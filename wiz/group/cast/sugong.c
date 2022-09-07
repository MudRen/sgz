// �ٹ�
#include <mudlib.h>
#include <daemons.h>
#include <ansi.h>

void show_result(object ob, int p_skill, int p_id);

void main(object ob)
{
	int p_id,p_skill;
	object env;
	string p_name;
	
	env = environment( ob );
	p_id=TROOP_D->get_char_troop(this_body()->query_id()[0]);
	p_name=this_body()->query_id()[0];

	if( !(CHAR_D->get_char(p_name,"skills")) )
		write("�㲻���ٹ�֮�ơ�\n");
        else if( !p_skill=CHAR_D->get_char(p_name,"skills")["sugong"] )
		write("�㲻���ٹ�֮�ơ�\n");
	else if( !p_id)
                write("ֻ�����ھ��в���ʹ���ٹ�֮�ơ�\n");
	else {
		load_object("/daemons/cast_d.c")->reg_player(p_name, "sugong");
	ob->award_exp(ob->query_sk_level("sk_zhimou")/2+random(20),"sugong");
		ob->simple_action(SG_SKILL_D->query_use("sugong"));
		ob->start_busy(10, "����æ��ʹ���ٹ�֮�ơ�");

		call_out("show_result", 5+random(5), ob, p_skill, p_id);
	}
}
void show_result(object ob, int p_skill, int p_id)
{	
	int mora;
	int kill;
	int damage;
	int soldier;

	kill = p_skill*2/3;
	kill = random(kill/2)+kill/2;
	soldier = TROOP_D->get_soldier_total_number(p_id);
	ob->stop_busy();

	if( kill>50 ){
		ob->simple_action(SG_SKILL_D->query_succ("sugong"));
		mora = random(5)+10;
	} else if( kill>15 ){
		ob->simple_action(SG_SKILL_D->query_succ("sugong"));
		mora = random(3)+5;
	} else {
		ob->simple_action(SG_SKILL_D->query_fail("sugong"));
		mora = -random(5) - 1;
	}
	if ( soldier < 1000 ) soldier = 1000;
	mora = mora*1000/soldier;
	if( mora < 0 ){
		damage = (random(p_skill) + 12)/6;
	   	mora = -(mora * 10);
		load_object("/daemons/condition_d.c")->apply_condition(p_id,"confuse",mora,damage);
		WARAI_D->war_inf(TROOP_D->get_troops(p_id,"task_id"),
	TROOP_D->find_troop(p_id)->query_id()[1]+"ʹ���ٹ�֮��ʧ�ܣ��������֮�С�","b");
	} else {
		damage = (random(p_skill) + 12)/ 12;
		mora = mora * 10;
load_object("/daemons/condition_d.c")->apply_condition(p_id,"speedup",mora,damage);
		TROOP_D->set_troops(p_id, "sugong", 1);
	}

	return;
}