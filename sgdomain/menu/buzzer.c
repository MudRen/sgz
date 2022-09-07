// buzzer.c by fire ����������
// modified by row
// this cmd is used create quick room
inherit CMD;
array dirs=({"east","west","south","north","southeast","southwest","northe
ast","northwest","up","down","enter","out",});
   
string p_area,p_dir,p_id,p_name;
string m_id;
string p_path;
int is_indoor;
object p_usr;

mixed opdirs=(["east":"west", "south":"north", "north":"south",
"west":"east","southeast":"northwest","southwest":"northeast","up":"down",
"enter":"out","northeast":"southwest","northwest":"southeast","down":"up",
"out":"enter",]);

void over() {
   this_object()->remove();
   return;
}
int insert_connection(string m_file,string dir,string t_f) {
   string f_c,f_b,f_e;
   string f_exit;
   int f_p;
   mixed dirs;

   f_c=read_file(m_file);
   f_p=strsrch(f_c,"set_exits",1);
   if(f_p==-1) // no set_exist
   {
      f_p=strsrch(f_c,";",-1); // the last ;
      f_b=f_c[0..f_p];
      f_e=f_c[(f_p+1)..<1];
      dirs=([]);
      dirs[dir]=t_f;
      rm(m_file);
      write_file(m_file,f_b+sprintf("\n// connection added by buzzer 
      set_exits(%O);\n",dirs)+f_e);

   }
   else
   {
      f_b=f_c[0..(f_p-1)];

      f_c=f_c[f_p..<1];
      f_p=strsrch(f_c,"[",1);
      f_b=f_b+f_c[0..f_p];
      f_e=f_c[(f_p+1)..<1];
      rm(m_file);
      write_file(m_file,f_b+"\n\""+dir+"\":\""+t_f+"\",\n"+f_e);

   }
}

string get_cnt() {
    string ret;
    string driver,tim;
    driver=p_usr->query_body()->short();
    tim=ctime(time());
    ret= "// this room is created by buzzer.c\n";
    ret+="// driver is "+driver+"\n";
    ret+="// created date is "+tim+"\n";
    ret+="//#include <mudlib.h>\n";
    ret+="//#include <ansi.h>\n";
    if(is_indoor) 
      ret+="inherit INDOOR_ROOM;\n";
    else
      ret+="inherit OUTDOOR_ROOM;\n";
    ret+="void setup() {\n";
    ret+="set_area(\""+p_area+"\");\n";
    ret+="set_light(50);\n";

    ret+="set_brief(\"%^YELLOW%^\"+\""+p_name+"\"+\"%^RESET%^\");\n";
    ret+="set_long(\"\");\n";
    ret+="set_exits( ([ ]));\n}\n";

    return ret;
}
void create_t_room() {
   string ret;
   int res;
   ret=get_cnt();
   res=unguarded(1, (: write_file, p_path+p_id+".c",ret,1 :)); 
   if(res) write("room "+p_name+" ����ɹ�.\n");
   else write ("room "+p_name+" ����ʧ��.\n");
   
}
void room_update(string p_room)
{
    object o,*obs;
    object *myobs;
    int n;
    o=load_object(p_room);
    if(!objectp(o)) return ;

    myobs=({});
    obs = all_inventory(o);
    for (n = 0; n < sizeof(obs); n++)
    {
        object *obb;
        if(obs[n]->query_link()) {
		myobs+=({obs[n]});
        	obs[n]->move(VOID_ROOM);
		continue;
        }
        obb=deep_inventory( obs[n] );
        if(!sizeof(obb)) continue;
        obb=filter_array(obb,(:$1->query_link():));
        if(!sizeof(obb)) continue;
	myobs+=({obs[n]});
        obs[n]->move(VOID_ROOM);
    }
    destruct(o);
    o=load_object(p_room);
    if(!objectp(o)) return;
    if(sizeof(myobs)) {
        foreach(object oo in myobs) {
	   oo->move(o);
        }
    }
}
void input_indoor(string s) {
   p_usr->modal_pop();
   if(s=="q") {over(); return;} //
    is_indoor=0;
   if(s=="y") is_indoor=1;
   write("�����ǣ�"+p_area+"\n");
   write("�����ǣ�"+p_dir+"\n");
   write("�����ļ��ǣ�"+p_id+"\n");
   write("���������ǣ�"+p_name+"\n");
   write("����·���ǣ�"+ p_path+"\n");
   write("��"+(is_indoor? "����": "����")+"\n");
   write("�����ڵķ����ǣ�"+m_id+"\n");
   create_t_room();  
   insert_connection(p_path+m_id+".c",p_dir,p_path+p_id+".c");
   insert_connection(p_path+p_id+".c",opdirs[p_dir],p_path+m_id+".c");

   room_update(p_path+m_id+".c");

   over();

}

void input_name(string s) {
   p_usr->modal_pop();
   if(s=="q") {over(); return;} //
   if(!sizeof(s)) {
     write("û�з������ơ�\n");
     over();
     return;
   }
   p_name=s;
   write("�����ڷ�����<y|n>\n");
   p_usr->modal_push((:input_indoor:),"",0,0);
}

void input_id(string s) {
   p_usr->modal_pop();
   if(s=="q") {over(); return;} //
   if(!sizeof(s)) {
     write("û���ļ����ơ�\n");
	over();
     return;
   }
   p_id=s;
   write("�����뷿�����ƣ�\n");
   p_usr->modal_push((:input_name:),"",0,0);
}

void input_dir(string s) {
   p_usr->modal_pop();
   if(s=="q") {over(); return;} //
   if(member_array(s,dirs)==-1) {
     write("����ķ���\n");
     over();
     return;
   }
   p_dir=s;
   write("�������ļ����ƣ�\n");
   p_usr->modal_push((:input_id:),"",0,0);

}

void main(object usr)
{
   object o;
   p_usr=usr;
   o=usr->query_body()->query_room();
   p_area=o->get_area();
   printf("p_area = %s\n", p_area);
   if(!AREA_D->area_exist(p_area)) {
      write("���ﲻ������������\n");
      over();
      return;
   }
   /*CHANNEL_D->deliver_tell("rumor","system",
   usr->query_body()->short()+"����������ʽ��LIMA��������������"+
     AREA_D->get_area(p_area,"name")+"������ľ��");*/
   p_path=AREA_D->get_area(p_area,"path");
   m_id=file_name(o);
   printf("m_id = %s\n", m_id);
   m_id=m_id[sizeof(p_path)..<1];
   write("��������������������\n");
   p_usr->modal_push((:input_dir:),"",0,0);
}

