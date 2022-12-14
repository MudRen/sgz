#include <mudlib.h>
#define GRASS __DIR__"grass.c"

inherit M_WEAPON;
inherit M_VALUE;

string *color = ({"白色", "兰色", "青色", "红色", "黑色", "无色", "彩色", });
string *taste = ({"无味", "苦味", "甜味", "酸味", "辣味", "涩味", "臭味", });

void setup() {
        set_id("chu tou", "小药锄", "chu");
        set_unit("把");
        set_in_room_desc("一把华陀采药用的小药锄(chu tou)");
        set_attack_ability(20);
        set_attack_power(10);
        set_defence_ability(1);
        set_combat_messages("combat-blade");
    	set_value(300);
    	set_currency_type("coin");
}
int direct_use_obj()
{
	return 1;
}
int do_use_it()
{
	int hp, i, j, k, m;
	string area, *place;
	object who, env, *other, grass;

	who   = environment(this_object());
	env   = environment(who);
	area  = env->get_area();
	i     = who->query_job("hua tuo", "color");
	j     = who->query_job("hua tuo", "taste");
	place = who->query_job("hua tuo", "place");
	hp    = who->query_cur_hp();

	if( !place || !arrayp(place) )place = ({ });
	if( area != who->query_job("hua tuo", "area") 
		&& member_array(area, AREA_D->get_area(who->query_job("hua tuo", "area"),"neighbor")) == -1 )
		write("这里没有什么药草值得注意的。\n");
	else if( member_array(file_name(env)+".c", place) != -1 )
		write("这里早被你挖了个底朝天了。\n");
        else if( hp < 15 )
		write("还是休息一会再干吧。\n");
	else if( env->is_indoors() )
		write("房子里面怎么会生药草。\n");
	else {
                who->set_cur_hp(hp-10);
		who->simple_action("$N拿着药锄在地上仔细的搜索着。\n");
		who->start_busy(3, "你正忙着挖药呢！\n");
		if( random(3) == 1 ) {
			place = place + ({ file_name(env)+".c" });
			grass = new(GRASS);
			grass->move(who);
			who->set_job("hua tuo", "place", place);
			who->simple_action("$N小心翼翼的挖出一株草药。\n");
			if( random(sizeof(place)) > 3 ){
				grass->set(who->query_id()[0], "ok");
				grass->set_long("一株"+color[i]+taste[j]+"的药草。");
				write("啊，终于挖到了。\n");
				write("你一时兴奋，啪，药锄断了。\n");
				destruct( this_object() );
				return 2;
			} else {
				k = random(sizeof(color));
				while(k==i)k = random(sizeof(color));
				m = random(sizeof(taste));
				while(m==j)m = random(sizeof(taste));
				grass->set_long("一株"+color[k]+taste[m]+"的药草。");
			}
		} else {
			who->simple_action("可是$N什么也没发现。\n");
		}
	};

	return 1;
}

