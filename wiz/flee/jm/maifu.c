// ���
#include <mudlib.h>
#include <daemons.h>
#include <ansi.h>
void show_result(object ob);
int p_id;
int p_skill;
string p_name;
void main(object ob)
{
	int i;
	object env;
	string where;
	
	env = environment( ob );
	p_id=TROOP_D->get_char_troop(this_body()->query_id()[0]);
	p_name=this_body()->query_id()[0];
	if(!(CHAR_D->get_char(p_name,"skills")))
       	{       write("�㲻�����֮�ơ�\n");
                return;
       	}
	
        if(!p_skill=CHAR_D->get_char(p_name,"skills")["maifu"])
	{	write("�㲻�����֮�ơ�\n");
		return;
	}
	if( !p_id){
                write("ֻ�����ھ��в���ʹ�����֮�ơ�\n");
                return;
        };	
	// In the furture, We have to consider theplayer's ablility
	// add the exp of this jimou, reduce mp, etc.

	ob->simple_action(SG_SKILL_D->query_use("maifu"));
	ob->start_busy(10, "����æ��ʹ�����֮�ơ�");

	call_out("show_result", 5+random(5), ob);
}
void show_result(object ob)
{	
	int mora;
	int kill;
	int damage;

	kill = p_skill*2/3;
	kill = random(kill);
	ob->stop_busy();
	if( kill>50)
	{
		ob->simple_action(SG_SKILL_D->query_succ("maifu"));
		mora = random (20) +10;
	} 
	else
	{     if(kill>15)
		{
		ob->simple_action(SG_SKILL_D->query_succ("maifu"));
		mora = random (10) + 5;
		}
	      else 
		{
		ob->simple_action(SG_SKILL_D->query_fail("maifu"));		
		mora = random (-5) - 1;
		
		}
	}
	
	if (mora < 0)
	{  damage = (random(p_skill) + 12)/ 12;	
	   mora = mora * 9;
"/daemons/condition_d.c"->apply_condition(p_id,"confuse",mora,damage);
	  
	WARAI_D->war_inf(TROOP_D->get_troops(p_id,"task_id"),
TROOP_D->find_troop(p_id)->query_id()[1]+"ʹ�����֮��ʧ�ܣ��������֮�С�","b");	
	}
	else {
	damage = (random(p_skill) + 12)/ 12;	
	mora = mora * 3;
	"/daemons/condition_d.c"->apply_condition(p_id,"hide",mora,damage);
	TROOP_D->set_troops(p_id, "maifu", 1);
	}
	return;
}
