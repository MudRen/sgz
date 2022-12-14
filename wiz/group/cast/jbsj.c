// 水计
#include <mudlib.h>
#include <daemons.h>
#include <ansi.h>
void show_result(object ob, string who, int p_skill, int p_id, int e_id);
string e_name, p_name;
void main(object ob, string who)
{
	int p_skill, p_id, e_id;
	int x,y,x2,y2;
	object env;
	string where;
	
	env = environment( ob );
	p_id=TROOP_D->get_char_troop(this_body()->query_primary_id());
	e_id=TROOP_D->get_char_troop(who);
	e_name=CHAR_D->get_char(who,"name");
	p_name=CHAR_D->get_char(ob->query_primary_id(),"name");
	where = TROOP_D->get_troop_area(p_id);
	if(!(p_skill=CHAR_D->get_char(ob->query_primary_id(),"skills")["jbsj"]) )
	{	write("你不会水淹之计。\n");
		return;}
	if( !p_id){
                write("只有身在军中才能使用水淹之计。\n");
                return;
        }	
	// In the furture, We have to consider theplayer's ablility
	// add the exp of this jimou, reduce mp, etc.
	if ( !e_id || TROOP_D->get_troop_area(e_id)!=where)
		{ write("对方不在此战场上。\n");
			return;
		}
	if (TROOP_D->get_troop_side(e_id) ==TROOP_D->get_troop_side(p_id))
		{write ("不可向己方部队施用此计。\n");
			return;
		}
	
	x =TROOP_D->get_troop_position(p_id)[0];
	y = TROOP_D->get_troop_position(p_id)[1];

	x2 = TROOP_D->get_troop_position(e_id)[0];
                y2 = TROOP_D->get_troop_position(e_id)[1];
	if (MAP_D->get_map_cell(where,y2,x2,"m") != "～")
		{
		write("对方不在水中，无法施计。\n");
		return;}
                if( (x-x2)*(x-x2)+(y-y2)*(y-y2) > 4 ){
			write("你离敌人太远无法施计。\n");
			return;}
	tell(deep_inventory(TROOP_D->find_troop(e_id)),
"一阵怒涛般的响声传来，一条水龙向部队冲了下来。，原来是"+p_name+"对你的部队使用水淹之计。\n",
                        MSG_INDENT);
                // In future, we have to consider effects of the
                // ablility of general, zhenxing, dixing, etc.
                // Now the damage depends only on the No of bowman
	ob->simple_action(SG_SKILL_D->query_use("jbsj"));
	ob->start_busy(10, "你正忙于施计呢。\n");
	load_object("/daemons/cast_d.c")->reg_player(ob->query_primary_id(),"jbsj");
        ob->award_exp(ob->query_sk_level("sk_zhimou")/2+random(20), "jbsj");	
	call_out("show_result", 10+random(5), ob, who, p_skill, p_id, e_id);
}
void show_result(object ob, string who, int p_skill, int p_id, int e_id)
{	
	int kill,kill1,mora,mora1;
	int e_skill;
	int damage, p_num, e_num;
	float rate;
		
	if(!(CHAR_D->get_char(who,"skills")))
	e_skill=0;
	else {
	e_skill=CHAR_D->get_char(who,"skills")["jbsj"];}
	if (!objectp(who))
        e_skill= CHAR_D->get_char(who,"skills")["sk_zhimou"];
	kill =random(p_skill);
	kill1 =random(e_skill);
	kill = kill*2 - kill1 *1.8;
	ob->stop_busy();
	if( kill>50)
	{	tell(deep_inventory(TROOP_D->find_troop(e_id)),
                "水龙冲过，士兵惊慌失措，溺死无数。\n",
                        MSG_INDENT);
		mora = random (-20) -10;
		mora1 = random (6) +2;
		rate = 2;
		ob->simple_action(SG_SKILL_D->query_succ("jbsj"));
		} 
	else
	{     if(kill>20)
		{
	tell(deep_inventory(TROOP_D->find_troop(e_id)),
        	"水龙冲过，士兵多有溺死。\n",
                        MSG_INDENT);	
		mora = random (-10) - 5;
		mora1 = random (3) + 1;
		rate = 1.1;
		ob->simple_action(SG_SKILL_D->query_succ("jbsj"));
		}
	      else if( kill>5)
		{
		tell(deep_inventory(TROOP_D->find_troop(e_id)),
        	"水龙冲过，士兵有些不慎溺死。\n",
                        MSG_INDENT);
		mora = random(-5) - 1;
		mora1 = 1;
		rate = 0.4;
		ob->simple_action(SG_SKILL_D->query_succ("jbsj"));
		}	
	      else 
		{
		tell(deep_inventory(TROOP_D->find_troop(e_id)),
        	"水龙冲过，但士兵们在指挥下避开了浪头。\n",
                        MSG_INDENT);
		mora = random(8) + 3;
		mora1 = random(-8) - 3;
		rate = 0;
		ob->simple_action(SG_SKILL_D->query_fail("jbsj"));
		}
	}
	p_num=TROOP_D->get_soldier_total_number(p_id);
	e_num=TROOP_D->get_soldier_total_number(e_id);
	TROOP_D->add_morale(p_id,mora1);
	TROOP_D->add_morale(e_id,mora);
	if (p_num > (e_num*5))
	{damage = rate * kill * 2* p_num / (e_num*2.5);}
	else 
	{if (p_num < e_num)
	damage = rate *kill * p_num * 4/e_num;
	else 
	damage = rate * kill * 2 * p_num / e_num *1.2; 
	}
	if(damage){
	 WARAI_D->kill_troop(e_id,damage);
                WARAI_D->clear_empty_troop(({e_id}));
        WARAI_D->war_inf(TROOP_D->get_troops(p_id,"task_id"),
TROOP_D->find_troop(p_id)->query_id()[1]+"使用水淹之计，使"+
TROOP_D->find_troop(e_id)->query_id()[1]+"损失"+chinese_number(damage)+
"人”。","b"); 
	};	

return;
}
