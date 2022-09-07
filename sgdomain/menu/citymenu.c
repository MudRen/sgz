//char menu for managering character database
//created by flee@lima on 3 Aug 1998

#include <menu.h>
#include <mudlib.h>
#include <daemons.h>
#include <edit.h>
#include <ansi.h>

#define AREA_SERVER load_object("/a/area_server")
#define BUILDCITY_D "/daemons/buildcity_d"


inherit MENUS;
inherit M_ACCESS;
inherit M_GRAMMAR;
inherit M_GLOB;

MENU toplevel;
MENU roomedit;

MENU_ITEM quit_item;
MENU_ITEM seperator;

array dirs=({"east","west","south","north","southeast","southwest","northeast",
"northwest","up","down","enter","out",});

mixed opdirs=(["east":"west", "south":"north", "north":"south",
"west":"east","southeast":"northwest","southwest":"northeast","up":"down",
"enter":"out","northeast":"southwest","northwest":"southeast","down":"up",
"out":"enter",]);

string p_id,p_name,p_zhou,p_sht; //����ID,������,��������,���м��(���г��еķ���ID���Լ��_��ͷ)
int level; //���м���
string m_id,c_id; //����ID

void do_create(string str);
void do_open(string str);
void do_return();
void do_move(string str);
void do_del(string str);
void do_edit();
void do_add(string str);


mixed can_i_do()
{
c_id=this_body()->query_primary_id();
p_id=CHAR_D->get_char(c_id,"buildcity");
//m_id=explode(file_name(me->query_room()),"/")[2];
if (!p_id&&!wizardp(this_body())) 
   return "%^RED%^��û�б��������޽��³��е�Ȩ����������ͨ��ͳһȫ����չʾ�Լ���ʵ����!%^RESET%^\n";
if (p_id)
{
p_name = BUILDCITY_D->get_city_build_info(p_id,"name");
p_zhou = BUILDCITY_D->get_city_build_info(p_id,"zhou");
p_sht  = BUILDCITY_D->get_city_build_info(p_id,"short"); 
p_sht  = BUILDCITY_D->get_city_build_info(p_id,"short"); 
level  = BUILDCITY_D->get_city_build_info(p_id,"level"); 
}
if (!wizardp(this_body()))
{if (!p_id)  return "%^CYAN%^���������޽�������е���Ϣ��������������ϵ!%^RESET%^\n";
if (!p_name) return "%^CYAN%^���������޽�������е���Ϣ��������������ϵ!%^RESET%^\n";
if (!p_zhou) return "%^CYAN%^���������޽�������е���Ϣ��������������ϵ!%^RESET%^\n";
if (!p_sht)  return "%^CYAN%^���������޽�������е���Ϣ��������������ϵ!%^RESET%^\n";
if (!level) return "%^CYAN%^���������޽�������е���Ϣ��������������ϵ!%^RESET%^\n";}
return 1;
 
}

int can_i_make_room()
{string p_area=this_body()->query_room()->get_area();
 if ((p_area!=p_id)&&(!wizardp(this_body())))
    {
    write("%^RED%^����Ȩ�ڴ˵ؽ��з������!%^RESET%^\n");
    return 0;
    } 
m_id=explode(file_name(this_body()->query_room()),"/")[2];
return 1;
}


void create_empty_room(string r_id) {
    AREA_SERVER->add_room(r_id);
    AREA_SERVER->set_room(r_id,"b","%^YELLOW%^�շ���("+r_id+")%^RESET%^");
    AREA_SERVER->set_room(r_id,"l","");
    AREA_SERVER->set_room(r_id,"e",([]));
    AREA_SERVER->set_room(r_id,"t",0);
    AREA_SERVER->set_room(r_id,"o",([]));
  }



void do_change_room_id(string id)
{mapping r_info;
 int index = sizeof(p_sht);
 if (id=="q") return;
 if (!can_i_make_room()) return;
 if (id[0..index]!=(p_sht+"_"))
    {
    write("%^RED%^����ID��ǰ׺����Ϊ "+p_sht+"_"+"��%^RESET%^\n");
    get_input_then_call((: do_change_room_id :),"��������Ҫ�޸ĵķ���ID :" );
    return;
    }
 if (BUILDCITY_D->is_room_exist(id))
    {
    write("%^RED%^�޸ĵķ���ID���Ѿ����ڡ�%^RESET%^\n");
    get_input_then_call((: do_change_room_id :),"��������Ҫ�޸ĵķ���ID :" );
    return;
    }
 BUILDCITY_D->add_room(p_id,id);
 BUILDCITY_D->trans_room(p_id,m_id,p_id,id);
 this_body()->move("/a/"+p_id+"/"+id);
 r_info=BUILDCITY_D->get_room(p_id,m_id,"e");
 BUILDCITY_D->del_room(p_id,m_id);
 foreach(string dir in keys(r_info))
  {mapping exits;
   exits=BUILDCITY_D->get_room(p_id,r_info[dir],"e");
   exits[opdirs[dir]]=id;
   BUILDCITY_D->set_room(p_id,r_info[dir],"e",exits);
   }
}

void do_change_room_name(string name)
{
if (!can_i_make_room()) return;
BUILDCITY_D->set_room(p_id,m_id,"b","%^YELLOW%^"+name+"%^RESET%^");
this_body()->force_look();
}


private nomask void receive_room_long(string* text)
{int lines;
 string desc="\n";
 if ( !sizeof(text) )
    { write("����׫д������\n");
      return;
    }
 lines = sizeof(text);
 for (int i=0;i<lines;i++)
     desc+=text[i];
 desc = wrap(desc, 60);
 desc += "\n";
 BUILDCITY_D->set_room(p_id,m_id,"l",desc);
 write("׫д����������\n");
 this_body()->force_look();
 return;
}

void do_change_room_long()
{
 if (!can_i_make_room()) return;
 write("%^CYAN%^�����뷿�������:%^RESET%^\n");
 new(EDIT_OB, EDIT_TEXT, 0, (: receive_room_long:));
}

void do_del_connection(string dir,string str)
{string r_id;
 mapping r_exit,m_exit;
if (str!="y"&&str!="Y") return;
m_exit=BUILDCITY_D->get_room(p_id,m_id,"e");
r_id = m_exit[dir];
r_exit=BUILDCITY_D->get_room(p_id,r_id,"e");
map_delete(r_exit,opdirs[dir]);
map_delete(m_exit,dir);
//Ŀ�귿��ֻ��opdirs[dir]��һ������ʱ��Ϊ�˷�ֹ��Ϊ��©�Ĺµ����䣬����
//������ֱ��ɾ��������ڡ��ƹ�������Ƶİ취���Ȱѹµ��������ӵ��𴦣�Ȼ
//����ɾ��������ڡ�
/*if (!sizeof(r_exit)) 
{
write("%^RED%^ɾ������"+dir+"�󣬳��ڷ���"+r_id+"����Ϊû����ڵĹµ����䣬���Ը�ɾ�����ڲ�������ֹ!%^RESET%^\n");
return;
}
if (!sizeof(m_exit)) 
{
write("%^RED%^ɾ������"+dir+"�󣬵�ǰ����"+m_id+"����Ϊû����ڵĹµ����䣬���Ը�ɾ�����ڲ�������ֹ!%^RESET%^\n");
return;
}*/
BUILDCITY_D->set_room(p_id,m_id,"e",m_exit);
BUILDCITY_D->set_room(p_id,r_id,"e",r_exit);
}



void do_add_room_exit(string dir,string str)
{
 mapping r_exit,m_exit;
 if (str[0..sizeof(p_sht)]!=(p_sht+"_"))
    {
    write("%^RED%^���ӵķ���ID��ǰ׺����Ϊ "+p_sht+"_"+"��%^RESET%^\n");
    get_input_then_call((: do_add_room_exit :),"��������Ҫ���ӵķ���ID :" );
    return;
    }
 if (!BUILDCITY_D->is_room_exist(p_id,str))
    {
    write("%^RED%^���ӵķ���ID�Ĳ����ڡ�%^RESET%^\n");
    get_input_then_call((: do_add_room_exit :),"��������Ҫ���ӵķ���ID :" );
    return;
    }
if (member_array(opdirs[dir],keys(BUILDCITY_D->get_room(p_id,str,"e")))!=-1)
   {
     write("Ŀ�귿��Ķ�Ӧ�����Ѿ��������ӡ�\n");
     return;
   }
m_exit=BUILDCITY_D->get_room(p_id,m_id,"e");
if (!m_exit) m_exit=([]);
m_exit[dir] = str;
r_exit=BUILDCITY_D->get_room(p_id,str,"e");
if (!r_exit) r_exit=([]); 
r_exit[opdirs[dir]] = m_id;
BUILDCITY_D->set_room(p_id,m_id,"e",m_exit);
BUILDCITY_D->set_room(p_id,str,"e",r_exit);

}

void do_change_room_exit(string dir)
{
 if (!can_i_make_room()) return;
 if (dir=="q") return;
 if (member_array(dir,dirs)==-1)
   {
     write("����ķ���\n");
     get_input_then_call((: do_change_room_exit :),"�������������޸ĵĳ��ڣ�" );
     return;
   }
 if (member_array(dir,keys(BUILDCITY_D->get_room(p_id,m_id,"e")))!=-1)//�����Ѿ�����
   {
     get_input_then_call((: do_del_connection,dir :),"��ȷ��Ҫɾ�����������<y/n>��" );
     return;
   }
 else
   {
     get_input_then_call((: do_add_room_exit,dir:),"�������ӵķ���ID��" );
     return;
   }
}

void do_change_room_object()
{
}

void done_change_room_type(string type)
{
if (type=="q") return;
switch(type)
{
case "1" :
     BUILDCITY_D->set_room(p_id,m_id,"t",1);break;
case "2" :
     if (level<5) {write(RED"ֻ���弶�ǲ��ܽ�����!\n"NOR);return;}
     BUILDCITY_D->trans_room("jianye","jy_dangpu",p_id,m_id);
     BUILDCITY_D->set_city_build_info(p_id,"dangpu",m_id);
     tell(bodies(),YEL+"��ϵͳ��"+this_body()->query_chinese_id()+"("+this_body()->query_primary_id()+")"+
                     "���³�"+p_name+"("+p_id+")"+"�ĵ����깤�ˡ�"+NOR+"\n");

     break;
case "3" :
     if (level<4) {write(RED"ֻ���ġ��弶�ǲ��ܽ�Ǯׯ!\n"NOR);return;}
     BUILDCITY_D->trans_room("jianye","jy_bank",p_id,m_id);
     BUILDCITY_D->set_city_build_info(p_id,"bank",m_id);
     tell(bodies(),YEL+"��ϵͳ��"+this_body()->query_chinese_id()+"("+this_body()->query_primary_id()+")"+
                     "���³�"+p_name+"("+p_id+")"+"��Ǯׯ�깤�ˡ�"+NOR+"\n");

     break;
case "4" :
     BUILDCITY_D->trans_room("jianye","jy_yst",p_id,m_id);
     BUILDCITY_D->set_city_build_info(p_id,"meeting",m_id);
     tell(bodies(),YEL+"��ϵͳ��"+this_body()->query_chinese_id()+"("+this_body()->query_primary_id()+")"+
                     "���³�"+p_name+"("+p_id+")"+"�������깤�ˡ�"+NOR+"\n");

     break;
case "5" :
     BUILDCITY_D->trans_room("jianye","jy_djt",p_id,m_id);
     BUILDCITY_D->set_city_build_info(p_id,"fly",m_id);
     tell(bodies(),YEL+"��ϵͳ��"+this_body()->query_chinese_id()+"("+this_body()->query_primary_id()+")"+
                    "���³�"+p_name+"("+p_id+")"+"��У���깤�ˡ�"+NOR+"\n");

     break;
case "6" :
     BUILDCITY_D->trans_room("jianye","jy_westgate",p_id,m_id);
     BUILDCITY_D->set_city_build_info(p_id,"go",m_id);
     tell(bodies(),YEL+"��ϵͳ��"+this_body()->query_chinese_id()+"("+this_body()->query_primary_id()+")"+
                     "���³�"+p_name+"("+p_id+")"+"�ĳ����깤�ˡ�"+NOR+"\n");

     break;
case "7" :
     BUILDCITY_D->trans_room("jianye","jy_jianyu",p_id,m_id);
     BUILDCITY_D->set_city_build_info(p_id,"prison",m_id);
     tell(bodies(),YEL+"��ϵͳ��"+this_body()->query_chinese_id()+"("+this_body()->query_primary_id()+")"+
                     "���³�"+p_name+"("+p_id+")"+"�ļ����깤�ˡ�"+NOR+"\n");

     break;
case "8" :
     BUILDCITY_D->trans_room("jianye","jy_yz",p_id,m_id);
     BUILDCITY_D->set_city_build_info(p_id,"yizhan",m_id);
     tell(bodies(),YEL+"��ϵͳ��"+this_body()->query_chinese_id()+"("+this_body()->query_primary_id()+")"+
                     "���³�"+p_name+"("+p_id+")"+"����վ�깤�ˡ�"+NOR+"\n");

default  :
     BUILDCITY_D->set_room(p_id,m_id,"t",0);break;
}
this_body()->force_look();
}

void do_change_room_type()
{
if (!can_i_make_room()) return;
write("%^CYAN%^1--���ⷿ��  2--����  3--Ǯׯ  4--������  5--�㽫̨  6--���š�7--������8--��վ  ����--���ڷ���%^RESET%^\n");
get_input_then_call((: done_change_room_type :),"��������ĵķ�������:" );
}

void create()
{       
	set_privilege(1);
	toplevel = new_menu("\n" + mud_name() + "���н������˵�");
        roomedit = new_menu("\n�����޸�ѡ��");

	quit_item = new_menu_item("�˳�", (:quit_menu_application:), "q");
	seperator = new_seperator("\n������������������������������������������������������������������\n");

	add_menu_item(toplevel, seperator);
	add_menu_item(toplevel, new_menu_item("�����³���(Create)",
                        (: get_input_then_call, (: do_create :),
                        "������Ҫ�����ĳ���ID: ":), "c"));
        add_menu_item(toplevel, new_menu_item("�����³���(Open)",
                        (: get_input_then_call, (: do_open :),
                        "����Ҫ���ŵĳ����� :" :), "o"));
	add_menu_item(toplevel, new_menu_item("�ƶ����³���(Move)",
                        (: get_input_then_call, (: do_move :),
                        "������Ҫȥ���½�����ID: ":), "m"));
        add_menu_item(toplevel, new_menu_item("���³��з���(Return)",
                        (: do_return :), "r"));
	add_menu_item(toplevel, new_menu_item("�����µķ���(Add)",
			(: get_input_then_call, (: do_add :),
                        "����Ҫ���ӵķ���ID :" :), "a"));
        add_menu_item(toplevel, new_menu_item("ɾ����ǰ����(Delete)",
                        (: get_input_then_call, (: do_del :),
                        "��ȷ��Ҫɾ����ǰ������?<y/n> :" :), "d"));
        add_menu_item(toplevel, new_menu_item("�޸ĵ�ǰ����(Edit)",roomedit, "e"));
        add_menu_item(toplevel, quit_item);
        add_menu_item(toplevel, seperator);
        set_menu_prompt (toplevel, "����ָ��[comradeq]: ");

        add_menu_item(roomedit, seperator);
        add_menu_item(roomedit,new_menu_item("�޸ķ���ID(Id)",
                        (: get_input_then_call, (: do_change_room_id :),
                        "�����µĵķ���ID :" :), "i"));
        add_menu_item(roomedit,new_menu_item("�޸ķ�������(Name)",
                        (: get_input_then_call, (: do_change_room_name :),
                        "�����µĵķ������� :" :), "n"));
        add_menu_item(roomedit,new_menu_item("�޸ķ�������(Long)",
                        (: do_change_room_long :),"l"));
        add_menu_item(roomedit,new_menu_item("�޸ķ������(Exit)",
                        (: get_input_then_call,(:do_change_room_exit :),
                         "���������޸ĵĳ��ڣ�" :),"e"));
        add_menu_item(roomedit,new_menu_item("�޸ķ������(Object)",
                        (: do_change_room_object :),"o"));
        add_menu_item(roomedit,new_menu_item("�޸ķ�������(Type)",
                        (: do_change_room_type :),"t"));
        add_menu_item(roomedit, quit_item);
        add_menu_item(roomedit, new_menu_item("�ص���ѡ��",toplevel, "m"));
        add_menu_item(roomedit, seperator);
        set_menu_prompt (roomedit, "����ָ��[inleotqm]: ");

}

void start_menu()
{
 mixed tmp;
 if (stringp(tmp=can_i_do()))
   {
   write(tmp);
   this_object()->remove();
   return;
   }
 init_menu_application( toplevel );
}

void do_create(string str)
{
string creator = BUILDCITY_D->get_city_build_info(str,"creator");
if (!creator) 
    {write("%^RED%^û�иó��еĹ�����Ϣ���޷�����!%^RESET%^\n");return;}
if (!wizardp(this_body())&&(creator!=c_id))
    {write("%^RED%^�㲻�Ǹó��еĴ����ߣ��޷�����!%^RESET%^\n");return;}
p_id = str;
p_name = BUILDCITY_D->get_city_build_info(str,"name");
p_zhou = BUILDCITY_D->get_city_build_info(str,"zhou");
p_sht  = BUILDCITY_D->get_city_build_info(str,"short"); 
p_sht  = BUILDCITY_D->get_city_build_info(str,"short"); 
level  = BUILDCITY_D->get_city_build_info(str,"level"); 
BUILDCITY_D->create_first_room_of_city(p_id,p_sht);
}

void do_open(string str)
{
 if (!wizardp(this_body())) {write(RED"ֻ����ʦ���ܿ����³���!\n"NOR);return;}
 if (p_id==str)
 {  
    BUILDCITY_D->init_city_info(p_id,p_name,p_zhou,p_sht,level);
    //CHAR_D->set_char(this_body()->query_primary_id(),"buildcity",0);
 }
 else
 {
    write(RED"���в�ƥ�䣬���ų���ʧ��!\n"NOR);
 }

//added city neighbor below. 

 return;
}

void do_move(string str)
{
string creator = BUILDCITY_D->get_city_build_info(str,"creator");
if (!creator) 
    {write("%^RED%^û�иó��еĹ�����Ϣ���޷�����!%^RESET%^\n");return;}
if (!wizardp(this_body())&&(creator!=c_id))
    {write("%^RED%^�㲻�Ǹó��еĴ����ߣ��޷�����!%^RESET%^\n");return;}
p_id = str;
p_name = BUILDCITY_D->get_city_build_info(str,"name");
p_zhou = BUILDCITY_D->get_city_build_info(str,"zhou");
p_sht  = BUILDCITY_D->get_city_build_info(str,"short"); 
p_sht  = BUILDCITY_D->get_city_build_info(str,"short"); 
level  = BUILDCITY_D->get_city_build_info(str,"level"); 
this_body()->move("/a/"+str+"/"+p_sht+"_lsjlg");
this_body()->force_look();
tell(bodies(),YEL+"��ϵͳ��"+this_body()->query_chinese_id()+"("+this_body()->query_primary_id()+")"+
                     "�ټ�������򣬿�ʼ��"+p_zhou+"һ�������³�"+p_name+"("+p_id+")"+NOR+"\n");
return;
}


void do_return()
{
   if(this_body()->query_room()->get_area()!=p_id)
      {
      write("%^RED%^�㲻���޽��еĳ�����,�޷�ִ�иù��ܡ�%^RESET%^\n");
      return;
      }
   this_body()->move("/a/huayin/vroad1");
   this_body()->force_look();
}

void do_add_connection(string str,string dir)
{  if (dir=="q") return;
   if (member_array(dir,dirs)==-1)
   {
     write("����ķ���\n");
     get_input_then_call((: do_add_connection,str :),"��������Ŀ���·�������췽��:" );
     return;
   }
   if (member_array(dir,keys(BUILDCITY_D->get_room(p_id,m_id,"e")))!=-1)
   {
     write("�÷����Ѿ��з������ӡ�\n");
     get_input_then_call((: do_add_connection,str :),"��������Ŀ���·�������췽��:" );
     return;
   }
   BUILDCITY_D->add_room(p_id,str);
   BUILDCITY_D->insert_connection(p_id,m_id,dir,str);
   BUILDCITY_D->insert_connection(p_id,str,opdirs[dir],m_id);
   BUILDCITY_D->update_room(p_id,str);
   this_body()->move(load_object("/a/"+p_id+"/"+str));//�ƶ����·���
   this_body()->force_look();
   BUILDCITY_D->update_room(p_id,m_id);
   tell(bodies(),YEL+"��ϵͳ��"+this_body()->query_chinese_id()+"("+this_body()->query_primary_id()+")"+
                     "������������ľ�����µĽ�����"+NOR+"\n");

}

void do_add(string str)
{int index = sizeof(p_sht);
 if (!can_i_make_room()) return;
 if (str=="q") return;
 if (str[0..index]!=(p_sht+"_"))
    {
    write("%^RED%^�޽��ķ���ID��ǰ׺����Ϊ "+p_sht+"_"+"��%^RESET%^\n");
    get_input_then_call((: do_add :),"��������Ҫ�½��ķ���ID :" );
    return;
    }
 if (BUILDCITY_D->is_room_exist(p_id,str))
    {
    write("%^RED%^�޽��ķ���ID���Ѿ����ڡ�%^RESET%^\n");
    get_input_then_call((: do_add :),"��������Ҫ�½��ķ���ID :" );
    return;
    }
 get_input_then_call((: do_add_connection,str :),"����Ŀ���·�������췽��:" );

}
void do_del(string str)
{mapping r_info;
 if ((str=="n")||(str=="N")) return;
 if (!can_i_make_room()) return;
 if (str!="y"&&str!="Y") m_id= str;
 BUILDCITY_D->del_room(p_id,m_id);
}

void do_edit()
{
if (!can_i_make_room()) return;
write("%^CYAN%^���ڷ����IDΪ"+m_id+"%^RESET%^\n");
init_menu_application(roomedit);
}

