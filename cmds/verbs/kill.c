//filename: /cmds/verbs/kill.c
// modified by fire on 21, march, 1998 
// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */
// this need to add some limit
#include <mudlib.h>
#include <verb.h>
inherit VERB_OB;
mixed direct_kill_str(string str) {
	return 1;
}
mixed do_kill_str(string str)
{
	object o;
    mixed ret;
	write("ɱ���з�������Ҫ�������fight�ɡ�\n");
	return;
 
	o=ENV_LIV(str);
	if(!objectp(o)) return;
	if(o==this_body()) {
		write("�Լ����Լ���Ц����\n");
		return;
	}
	ret=FIGHT_D->can_fight(this_body(),o);
}
array query_verb_info()
{
     return ({ ({"STR" }) });
}

/*
void beg_kill(object ob)
{
	this_body()->start_fight(ob);
}
void answer_kill(object ob)
{
	ob->targetted_action("$N��$T�𵽣���$r$m,��������ա�\n\n",this_body());
	call_out((:beg_kill:),1,ob);
}
void do_kill_liv(object ob)
{
    if (ob == this_body())     
	printf("Ҫ��ɱ�������İ취��\n");
    else
	{
	this_body()->targetted_action("$N��$T���һ������$r$m,�Һ�$S��ս���ٻغ���\n\n",ob);
	call_out((:answer_kill:),1,ob);
	}
}
void do_kill() 
{
	printf("��Ҫɱ˭ѽ��\n");
}
void do_kill_str(string str)
{
   mixed ob;
	write("ɱ���з�������Ҫ�������fight�ɡ�\n");
	return;
   ob=NORMAL_D->get_monster(this_body(),str);
   if(objectp(ob))
	do_kill_liv(ob);
   else
	   write("��Ҫɱ˭��\n");
}
array query_verb_info()
{
   return ({ ({ "STR","", "LIV" }) });
}
 */