// 乱射
#include <mudlib.h>
#include <daemons.h>
#include <ansi.h>

int p_id,p_skill;
string p_name;

void main(object ob)
{
	int i, x, y, x2, y2, id, kill, *troops;
	string where, s_type;
	mapping solider,enemy;
	object env;

	env = environment(ob);
	p_id = TROOP_D->get_char_troop(this_body()->query_primary_id());
	p_name=this_body()->query_id()[0];
        if(!(CHAR_D->get_char(p_name,"skills")))
        {       write("你不会乱射之计。\n");
                return;
        }
        if(!p_skill=CHAR_D->get_char(p_name,"skills")["luanshe"])
        {       write("你不会乱射之计。\n");
                return;
        }
	if( !p_id){
		write("只有身在军中才能使用乱射。\n");
		return;
	};
	solider = TROOP_D->get_troops(p_id, "soldier");
	if( !sizeof(solider) || member_array("bowman", keys(solider)) == -1 ){ 
		write("你的手下没有弓兵，怎能使用乱射。\n");
		return;
	};
	if( solider["bowman"]["energy"] < 20 ){
		write("弓兵行动力不足，难以使用乱射。\n");
		return;
	};

	solider["bowman"]["energy"] = 0;
	TROOP_D->set_troops(p_id, "solider", solider);
	ob->simple_action(SG_SKILL_D->query_use("luanshe"));

	troops = TROOP_D->list_troops();
	troops = troops - ({ p_id });
	if( !sizeof(troops) )return;
	where = TROOP_D->get_troop_area(p_id);
	
	x = TROOP_D->get_troop_position(p_id)[0];
	y = TROOP_D->get_troop_position(p_id)[1];

	for( i = 0; i < sizeof(troops); i++ ){
		id = troops[i];
		x2 = TROOP_D->get_troop_position(id)[0];
		y2 = TROOP_D->get_troop_position(id)[1];

		if( TROOP_D->get_troop_area(id) != where )continue;
		if( (x-x2)*(x-x2)+(y-y2)*(y-y2) > 4 )continue;
		tell(deep_inventory(TROOP_D->find_troop(id)),
			"一阵箭雨从天而降，毫无防备的士兵连声惨叫。\n",
			MSG_INDENT);		
		tell(deep_inventory(TROOP_D->find_troop(p_id)),
                        "乱箭射一队人马之中！\n",
                        MSG_INDENT);
		kill = p_skill*100/11;
		enemy = TROOP_D->get_troops(id, "soldier");
		s_type= keys(enemy)[random(sizeof(keys(enemy)))];
		WARAI_D->kill_troop(id,kill);
		WARAI_D->clear_empty_troop(({id}));		
	};

	WARAI_D->war_inf(TROOP_D->get_troops(p_id,"task_id"),
TROOP_D->find_troop(p_id)->query_id()[1]+"使用乱射之计，杀敌"+
chinese_number(kill)+"人。","b");

}
