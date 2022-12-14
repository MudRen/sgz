// Ma fu for transport
// By flee@sgz, created at 23 NOV 1998
// Modified by flee on 26 NOV, take distance into consideration
#include <mudlib.h>

#define MACHE __DIR__"mache.c"
#define VOID "/obj/void.c"
#define __TIME__ 15
#define K 0.3
#define __COST__ 100

inherit LIVING;

void setup()
{
//	object jia;
//	object jia1;
	int i;
	string *dest;

	set_name("ma fu", "马夫");
	set_in_room_desc("一位懒洋洋的马夫(ma fu)");
	set_long("马夫抬头看了你一眼：要到哪儿去，问我好了。\nask ma fu about destination\n");
	set_gender(1);
	set_age(25);
	set_sg_rongmao(15);
//	jia=new("/sgdomain/obj/cloth/torso/buyi.c");
//	jia->move(this_object());
//	jia->do_wear();
//	jia1=new("sgdomain/area/cities/luoyang/obj/maxie.c");
//	jia1->move(this_object());
//	jia1->do_wear();
	
	dest = AREA_D->list_areas();
	for( i = 0; i < sizeof(dest); i++){
		add_question(dest[i], "dest");
		add_ask_str(dest[i], "$N向$T打听：您可以送我到" + 
			AREA_D->get_area(dest[i], "name") + "吗？\n");
	};		
	add_question("destination", "destination");
	add_ask_str("destination", "$N向$T打听：您可以送我到哪儿啊？\n");
}
string long() {
	return "一个愁闷苦脸的马夫。\n";
}
mixed special_answer(object ob, string dest)
{
	int i, count, tmp;
	int time, cost;
	string out;
	string *dests;
	string *path;
	string from;
	object env, mache;

	dests = AREA_D->list_areas();
        env = environment( ob );
        while( env && !inherits(BASE_ROOM, env) )env = environment( env );
        from = base_name( env );
        from = replace_string( from, "/", " ");
        path = explode( from, " ");
        from = path[sizeof(path)-2];
	if( dest == "destination" ){
		this_object()->responda("ah");
		this_object()->simple_action("$N道：您可以去这些地方：\n");		
		count = 0;
		tmp = 1;
		out = "\n";
		for( i = 0; i < sizeof(dests); i++){
			if( dests[i] == from )continue;
			out = out + sprintf("%-2d)%-6s - %-10s - %-14s", tmp,
				AREA_D->get_area(dests[i], "name"), dests[i],
				chinese_number(AREA_D->get_distance(from,dests[i])) + "两银子");
			count++;
			tmp++;
			if( count == 2 ){
				count = 0;
				out = out + "\n";
			};
		};
		printf("%s\n\n", out);
	} else {
		if( from == dest ){
			printf("马夫疑惑的问%s：您现在就在%s呀。\n",
				ob->query_name(), AREA_D->get_area(from,"name"));
			return;
		};
		cost = AREA_D->get_distance( from, dest ) * __COST__;
		time = AREA_D->get_distance( from, dest ) * __TIME__ * K +5;
		if( ob->query_all_con_money() < cost ){
			this_object()->simple_action("$N哼了一声：穷光蛋，一边去。\n");
			return;
		};
		ob->set_all_con_money( ob->query_all_con_money() - cost );
		mache = new( MACHE );
		printf("你付给车夫%s两银子。\n", chinese_number(cost/100));
		this_object()->simple_action("$N挥了挥手，一辆大车缓缓的开了过来。");
		ob->simple_action("$N一拱身，钻进了车里。");
		ob->move( mache );
		this_object()->simple_action("$N用力挥了一下皮鞭，大车慢慢的离开了。");
		mache->move( VOID );
		mache->destruct_itself(ob, time, dest);	
	};
	return;
}
		
