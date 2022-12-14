// accountant 帝王卫士
#include <ansi.h>
#include <mudlib.h>
#define EV_KING "/sgdomain/event/ev_king.c"
#define EV_KWAR "/sgdomain/event/ev_kwar.c"
#define KROOM "/sgdomain/area/emp/hugo.c"
inherit M_OUT;
inherit LIVING;

object usr;
int starttime;
int money,t_money,rep;
void input_way(string arg);
void ask_jinjian(object usrk);
void award();
void setup()
{
   object jia;
   jia=new(PTORSO+"zhanp");
   jia->move(this_object());
   jia->do_wear();
   set_name("zhonglang jiang", "御前中郎将");
   set_in_room_desc(""HIC"〖东汉〗"NOR""HIR"御前中郎将"NOR"(zhonglang jiang)");
   set_long(
       "他是献帝的贴身卫士，你可以向他询问晋见献帝之事。\nask zhonglang jiang about jinjian\n");
    add_id("general");
   set_gender(1);
   set_age(30);
   set_sg_rongmao(20);
   add_question("jinjian", "jinjian");
   add_ask_str("jinjian","$N向$T道：在下可否晋见献帝？\n");
}

mixed special_answer(object ob, string str)
{
   object player;
   player = this_body();
   switch(str)
   {
      case "jinjian":
          ask_jinjian(player);
          return;
      default:
         return ;
    }
}
void ask_jinjian(object usrk)
{
    string n_id, mess;  
        
    usr=usrk;   
    n_id=usr->query_id()[0];
    if (EV_KING->query_name()!=n_id && EV_KWAR->query_name()!=n_id)
   {
	object pass;
	pass=present("ysf pass",usrk);
	if(!objectp(pass)) {
        	this_object()->simple_action(
	        	"$N道：陛下并未召见于你，请恕在下不能放行。\n");
	        return;
	}
   }
    this_object()->targetted_action("$N道：请速速入内，勿让陛下久候。\n\n$T在侍卫的引领下，来到了皇宫入口。\n",usrk);
    usr->move(KROOM);
    this_body()->force_look();          
}