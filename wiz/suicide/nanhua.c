#include <ansi.h>
inherit LIVING;
inherit M_CHAR;
inherit "/sgdomain/modules/m_charnpc/xianren/xianren_act";
inherit M_SMARTMOVE;
private string who;
private string name;
void do_something(object ob);
void no_answer();
void get_name(string what);
void get_respond(string what);
void answer_skills(object ob);
void check_skills(string *sks, string ans);
void do_learn(string sk, int lvl, string ans);
string get_english_name(string what);
void setup()
{
        object cloth;
        cloth = new("/sgdomain/obj/cloth/torso/hechang.c");
        cloth->move(this_object());
        cloth->do_wear();
        set_name("nanhuan laoxian", HIY+"����"+NOR+"�ϻ�����");
        add_id("nanhua");
        set_gender(1);
        set_age(80);
        set_proper_name(HIY+"����"+NOR+"�ϻ�����(nanhua laoxian)");
        set_in_room_desc(HIY+"����"+NOR+"�ϻ�����(nanhua laoxian)");
        add_question("fate", "fate");
        add_ask_str("fate","$N��$T����һ�Ϲ�����С����������ָ��һ�£���֪С�����ڳ��н��꼪����Ρ�\n");
       
        call_out("my_heart",1);
}
mixed special_answer(object ob, string str)
{
        if( who&&stringp(who)&&who!="" ) 
                return this_object()->targetted_action("$N��$T�������Եȣ�\n",ob);
        else if( str=="fate" ){
                who = ob->query_id()[0];
                return do_something(ob);
        } else return ::special_answer(ob, str);
}
void do_something(object ob)
{
        this_object()->reponda("nod");
        this_object()->targetted_action("$N����˹���ض�$T˵����Ҫ���Ǹ�����ѽ��\n
", ob);
        ob->modal_push((: get_name :),"�Ǹ����а���");
        call_out("no_answer", 60);
}
void no_answer()
{
        object ob;
        ob = CHAR_D->find_char(who);
        if( objectp(ob) ) ob->modal_pop();
        this_object()->reponda("heng");
        who = "";
}
void get_name(string what)
{       mapping fate;
        array infos = ({});
        array info = ({});
        int found=0;
        this_body()->modal_pop();
        if( !AREA_D->area_exist(what) ){
                this_object()->targetted_action("$N�ɻ�Ķ�$T������ȷ�������������\n",
                                                 this_body());
                who = "";
                remove_call_out("no_answer");
                } 
        else {
                write("�ϻ��������ˡ��Ǻǡ�һЦ�����ҵ�Ȼ֪�������Ժ򣮣���\n");
                fate = FATE_D->query_fate_table();
                infos = fate["spring"]+fate["summer"]+fate["autumn"]+fate["winter"];
                foreach (array ss in infos)
                  if (member_array(what,ss)!=-1)
                      {found=1;
                       info = ss;}
                if (found&&(info[2]==-1)) 
                  {
                     if (FATE_D->get_fate_type(info[1])=="bad")
                          write("�ϻ�����˵�����Ϸ�����ҹ�����࣬"+
                          AREA_D->get_area(info[0],"name")+"֮��������ҫ������%^RED%^"+
                          FATE_D->get_fate_name(info[1])+"%^RESET%^֮�֣������������Ԥ����\n");
                      else
                          write("�ϻ�����˵�����Ϸ�����ҹ�����࣬"+
                          AREA_D->get_area(info[0],"name")+"֮�ظ��Ǹ��գ���%^YELLOW%^"+
                          FATE_D->get_fate_name(info[1])+"%^RESET%^֮�ף�������Թ�ػή�٣�\n");
                  }
                else
                  {
               		  write("�ϻ�����˵�����󾳽�������˳��С������ǹ������ѵ��ѵã�\n");
                  }
                }  
}
        
                
                      
                
                
 
