// 奇兵
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
		write("你不会奇兵之计。\n");
        else if( !p_skill=CHAR_D->get_char(p_name,"skills")["qibing"] )
		write("你不会奇兵之计。\n");
	else if( !p_id)
                write("只有身在军中才能使用奇兵之计。\n");
	else if( ob->query_cur_mp()<60 ) 
		write("你精神不足，不能使用这种计谋！\n");
	else {
		load_object("/daemons/cast_d.c")->reg_player(p_name, "qibing");
		ob->set_cur_mp(ob->query_cur_mp()-60);
		ob->simple_action(SG_SKILL_D->query_use("qibing"));
		ob->start_busy(10, "你正忙于使用奇兵之计。");

		call_out("show_result", 5+random(5), ob, p_skill, p_id);
	}
}
void show_result(object ob, int p_skill, int p_id)
{	
	int mora;
	int kill;
	int damage;

	kill = p_skill*2/3;
	kill = random(kill/2)+kill/2;
	ob->stop_busy();

	if( kill>50 ){
		ob->simple_action(SG_SKILL_D->query_succ("qibing"));
		mora = random(10)+5;
	} else if( kill>15 ){
		ob->simple_action(SG_SKILL_D->query_succ("qibing"));
		mora = random(8)+3;
	} else {
		ob->simple_action(SG_SKILL_D->query_fail("qibing"));
		mora = -random(5) - 1;
	}
	
	if( mora < 0 ){
		damage = (random(p_skill) + 12)/6;
	   	mora = -(mora * 10);
		load_object("/daemons/condition_d.c")->apply_condition(p_id,"confuse",mora,damage);
		WARAI_D->war_inf(TROOP_D->get_troops(p_id,"task_id"),
			TROOP_D->find_troop(p_id)->query_id()[1]+"使用奇兵之计失败，陷入混乱之中。","b");
	} else {
		damage = (random(p_skill) + 12)/ 12;
		mora = mora * 10;
		load_object("/daemons/condition_d.c")->apply_condition(p_id,"hide",mora,damage);
		TROOP_D->set_troops(p_id, "qibing", 1);
	}

	return;
}
