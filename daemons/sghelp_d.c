/*
** File: sghelp_d.c by fire on Dec 1998
** Created 25-OCT-94 by Deathblade for the new help system.
** This daemons is used to handle the player help system for sg
*/
#include <mudlib.h>
#include <security.h>
#include <area.h>
#define SAVE_FILE "/data/daemons/sghelp"
#define ROOT "/help/player/sanguo/"
#define BAR "----------------------------------------------------------------\n"
#define MAXNEWTIME 1209600 // two weeks
inherit M_ACCESS;
private mapping topics;
private static mapping real_topics;
private static int  pending_count;
private static object   initiator;
private static int root_length;
nomask void rebuild_data();
int add_new_topic();
void save_data()
{  unguarded(1, (: save_object, SAVE_FILE :));
}
void create()
{  unguarded(1, (: restore_object, SAVE_FILE, 1 :));
   root_length=sizeof(ROOT);
   remove_call_out("rebuild_data");
   rebuild_data();
   return;
}
nomask void process_dir(string path);
private void process_file(string path, string file)
{   string pathname;
    if ( file == "." || file == ".." ) return;
    if(member_array('.',file)!=-1) return;
    pathname = path + file;
    if ( file_size(pathname) == 0 ) return;
    if ( file_size(pathname) == -2 )
    {   pathname += "/";
        call_out((: process_dir :), 0, pathname);
        ++pending_count;
    }
    else
    {  if(real_topics[file])
       {  write("Warning "+file+" has more than one location\n");
          return;
       }
       real_topics[file] =  pathname[root_length..<1];
    }
}
nomask void process_dir(string path)
{   map_array(get_dir(path + "*"), (: process_file, path :));
    if ( !--pending_count )
    { 
       add_new_topic();
    }
}
nomask void rebuild_data()
{   string * lines;
    string * dirs;
    if ( pending_count )
    {  write("SGHELP_D �����ؽ�����־����ϵͳ��\n");
       return;
    }
    write("SGHELP_D ��ʼ�ؽ�����־����ϵͳ ... \n");
    initiator = this_user();
    dirs = (get_dir(ROOT+"*"));
    real_topics=([]);
    pending_count = 0;
    map_array(dirs, (: process_file, ROOT :));
}
mapping query_topics()
{   return topics;
}
mapping query_real_topics()
{   return real_topics;
}
int add_new_topic()
{
   string *top,*rtop;
   int curtime=time();
   if(!topics) topics=([]);
   top=keys(topics);
   rtop=keys(real_topics);
   rtop-=top;
   if(sizeof(rtop))
   {  foreach(string r in rtop)
      {  if(!topics[r]) topics[r]=([]); 
         topics[r]["p"]=real_topics[r];
      } 
      if(initiator)
         tell(initiator,sprintf("����%d��������Ϣ��\n",sizeof(rtop)));
   } 
   rtop=keys(real_topics);
   top-=rtop;
   if(sizeof(top))
   {
     foreach(string r in top)
        map_delete(topics, r);
      if(initiator)
         tell(initiator,sprintf("ɾ��%d��������Ϣ��\n",sizeof(top)));
   }
   rtop=keys(topics);
   foreach(string r in rtop)
   {
     topics[r]["p"]=real_topics[r];
     if(!topics[r]["parent"])
        topics[r]["parent"]=({});
     topics[r]["parent"]-=({"topics"});
     topics[r]["parent"]+=({"topics"});
     topics[r]["parent"]-=({"classes"});
     if(topics[r]["is_parent"])
       topics[r]["parent"]+=({"classes"});
     topics[r]["parent"]-=({"new"});
     if((curtime-stat(ROOT+topics[r]["p"])[1])<MAXNEWTIME)
        topics[r]["parent"]+=({"new"});
   }
   if ( initiator )
   {
     tell(initiator,"����־����ϵͳ�ؽ���ɡ�\n");
     initiator = 0;
   }
   real_topics=0;
   save_data();
   remove_call_out("rebuild_data");
   call_out("rebuild_data",86400);
   return sizeof(rtop);
}
mixed set_topic(string topic,string para,mixed value)
{
   if(!topics[topic]) return 0;
   topics[topic][para]=value;
   save_data();
   return value;
}
mixed get_topic(string topic, string para)
{
   if(!topics[topic]) return 0;
   if((!para)||(para==""))
      return topics[topic];
   return topics[topic][para];
}
string get_count(string arg)
{
   string pathname;
   string ret="";
   string *tmp;
   if(!topics[arg]) return "û�д˰������⡣\n";
   if(!topics[arg]["p"]) return "�˰����������ݻ�û����ɡ�\n";
   pathname=ROOT+topics[arg]["p"];
   if(file_size(pathname)<=0)
      return "BUG BUG BUG��\n";
   if(topics[arg]["t"])
   {  ret=arg+" : " + topics[arg]["t"] +"\n";
      ret+=BAR;
   }
   ret+=read_file(pathname);
   if(topics[arg]["is_parent"])
   {
      string *list,*list1,*list2;
      list=filter_array(keys(topics),
         (: member_array($(arg),topics[$1]["parent"])!=-1 :));
      list=sort_array(list,1);
      list1=filter_array(list,(:SGHELP_D->get_topic($1,"is_parent") :));
      list2=list-list1;
      list=list1+list2;
      if(sizeof(list))
      {
        int kk=0;
        ret+="\n��������һ�������࣬���а����������⣺\n"+BAR;
        foreach( string b in list)
        {  ret+=sprintf("%-12s: %-20s",b,get_topic(b,"t"));
           if(kk==1) ret+="\n";         
           kk++;
           if(kk>1)kk=0;
        }
      }
   }   
   tmp=topics[arg]["parent"];
   if(!tmp) tmp=({});
   tmp-=({"topics","classes","new"});
   if(sizeof(tmp))
   {
      int kk=0;
      string* idx;
      ret+="\n�����������ࣺ\n"+BAR;
      idx=sort_array(tmp,1);
      foreach( string b in idx)
      {  ret+=sprintf("%-12s: %-20s",b,get_topic(b,"t"));
         if(kk==1) ret+="\n";         
         kk++;
         if(kk>1)kk=0;
      }
   }
   if(sizeof(topics[arg]["related"]))
   {
     int kk=0;
     string *idx;
     ret+="\n��ذ�����\n"+BAR;
     idx=sort_array(topics[arg]["related"],1);
     foreach( string b in idx)
     {  ret+=sprintf("%-12s: %-20s",b,get_topic(b,"t"));
        if(kk==1) ret+="\n";         
        kk++;
        if(kk>1)kk=0;
     }
   }
   return ret;  
}
mixed add_parent(string me,string par)
{
   if(!topics[me]) return "û��"+me+"�����������\n";
   if(!topics[par]) return "û��"+par+"���������\n";
   if(!topics[par]["is_parent"]) return par+"���ǰ�����\n";
   if(!topics[me]["parent"]) topics[me]["parent"]=({});
   topics[me]["parent"]-=({par});
   topics[me]["parent"]+=({par});
   save_data();
   return me +" ���� " + par + " �࣬�ɹ�!\n";      
}
mixed sub_parent(string me,string par)
{
   if(!topics[me]) return "û��"+me+"�����������\n";
   if(!topics[me]["parent"]) topics[me]["parent"]=({});
   topics[me]["parent"]-=({par});
   save_data();
   return me +" �� " + par + " ����ɾ�����ɹ�!\n";      
}

mixed add_related(string me,string rel)
{
   if(!topics[me]) return "û��"+me+"�����������\n";
   if(!topics[rel]) return "û��"+rel+"���������\n";
   if(!topics[me]["related"]) topics[me]["related"]=({});
   topics[me]["related"]-=({rel});
   topics[me]["related"]+=({rel});
   save_data();
   return rel +" ��Ϊ " + me + " ���������!\n";
}
void system_check()
{
   string *list;
   list=keys(topics);
   list-=({"main"});
   foreach(string top in list)
   {  if(!topics[top]["t"])
         write(top+" û����Ŀ��\n");
      if(sizeof(topics[top]["parent"]-({"topics","classes","new"}))<1 )
         write(top+" û�������ࡣ\n");
      if(file_size(ROOT+topics[top]["p"])<=0)
         write("�Ҳ��� "+top+" �İ����ļ���\n");
   }
}
mixed find_wrong()
{
   string *list;
   list=keys(topics);
   list-=({"main"});
   foreach(string top in list)
   {  if(!topics[top]["t"])
         return top+" û����Ŀ��\n";
      if(sizeof(topics[top]["parent"]-({"topics","classes","new"}))<1 )
         return top+" û�������ࡣ\n";
      if(file_size(ROOT+topics[top]["p"])<=0)
         return "�Ҳ��� "+top+" �İ����ļ���\n";
   }
   return "�Ҳ����������İ������⡣\n";
}
