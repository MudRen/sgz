// accountant ������ʿ
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
   set_name("zhonglang jiang", "��ǰ���ɽ�");
   set_in_room_desc(""HIC"��������"NOR""HIR"��ǰ���ɽ�"NOR"(zhonglang jiang)");
   set_long(
       "�����׵۵�������ʿ�����������ѯ�ʽ����׵�֮�¡�\nask zhonglang jiang about jinjian\n");
    add_id("general");
   set_gender(1);
   set_age(30);
   set_sg_rongmao(20);
   add_question("jinjian", "jinjian");
   add_ask_str("jinjian","$N��$T�������¿ɷ�����׵ۣ�\n");
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
	        	"$N�������²�δ�ټ����㣬��ˡ���²��ܷ��С�\n");
	        return;
	}
   }
    this_object()->targetted_action("$N�������������ڣ����ñ��¾ú�\n\n$T�������������£������˻ʹ���ڡ�\n",usrk);
    usr->move(KROOM);
    this_body()->force_look();          
}