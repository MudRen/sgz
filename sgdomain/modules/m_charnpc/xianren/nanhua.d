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
        set_name("nanhua laoxian", HIY+"仙人"+NOR+"南华老仙");
        add_id("nanhua");
        set_gender(1);
        set_age(80);
        set_proper_name(HIY+"仙人"+NOR+"南华老仙(nanhua laoxian)");
        set_in_room_desc(HIY+"仙人"+NOR+"南华老仙(nanhua laoxian)");
        add_question("fate", "fate");
        add_ask_str("fate","$N向$T深深一鞠躬道：小可特向先生指教一事，不知小可所在城市今年吉凶如何。\n");
       
        call_out("my_heart",1);
}
mixed special_answer(object ob, string str)
{
        if( who&&stringp(who)&&who!="" ) 
                return this_object()->targetted_action("$N对$T道：请稍等！\n",ob);
        else if( str=="fate" ){
                who = ob->query_id()[0];
                return do_something(ob);
        } else return ::special_answer(ob, str);
}
void do_something(object ob)
{
        this_object()->reponda("nod");
        this_object()->targetted_action("$N慢理斯条地对$T说：你要问那个城市呀？\n
", ob);
 this_body()->modal_push((: get_name :),"那个城市啊？");
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
remove_call_out("no_answer");
        if( !AREA_D->area_exist(what) ){
                this_object()->targetted_action("$N疑惑的对$T道：你确定有这个城市吗？\n",
                                                 this_body());
                who = "";
                remove_call_out("no_answer");
                } 
        else {
                write("南华老仙听了「呵呵」一笑：这我当然知道，请稍候．．．\n");
                fate = FATE_D->query_fate_table();
                infos = fate["spring"]+fate["summer"]+fate["autumn"]+fate["winter"];
                foreach (array ss in infos)
                  if (member_array(what,ss)!=-1)
                      {found=1;
                       info = ss;}
                if (found&&(info[2]==-1)) 
                  {
                     if (FATE_D->get_fate_type(info[1])=="bad")
                          write("南华老仙说道：老夫昨日夜观星相，"+
                          AREA_D->get_area(info[0],"name")+"之地灾星闪耀，恐有%^RED%^"+
                          FATE_D->get_fate_name(info[1])+"%^RESET%^之灾，贵地尚需早日预防．\n");
                      else
                          write("南华老仙说道：老夫昨日夜观星相，"+
                          AREA_D->get_area(info[0],"name")+"之地福星高照，有%^YELLOW%^"+
                          FATE_D->get_fate_name(info[1])+"%^RESET%^之兆，但无民怨必会降临．\n");
                  }
                else
                  {
               		  write("南华老仙说道：贵境今年风调雨顺，小子如此忧国忧民，难得难得！\n");
                  }
                }  
who = "";
}
        
                
                      
                
                
 
