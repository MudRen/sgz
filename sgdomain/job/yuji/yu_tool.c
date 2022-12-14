#include <mudlib.h>

inherit M_WEAPON;
inherit M_VALUE;

int check_place(object who, mixed arg);
int check_who(object who, mixed arg);
int get_newjob(object who);
int succ_job(object who);

void setup() {
        set_id("zhu bang", "青竹棒", "bamboo");
        set_unit("根");
        set_in_room_desc("一根青竹棒，看上去沉甸甸的");
        set_attack_ability(20);
        set_attack_power(10);
        set_defence_ability(1);
        set_combat_messages("combat-blade");
        set_value(500);
        set_currency_type("coin");
}
int direct_use_obj()
{
        return 1;
}
int do_use_it()
{
        int hp;
        string area;
        object who, env;
	mapping job;

        who  = environment(this_object());
        env  = environment(who);
        area = env->get_area();
	hp   = who->query_cur_hp();
	job  = who->query_job("yu ji", "");

	who->start_busy(2, "你正忙着挥舞青竹棒呢。");

	if( who->query_cur_hp() < 30 ){
		write("还是休息一会再干吧。\n");
		return 1;
	} else who->set_cur_hp(who->query_cur_hp()-25);

	if( !job || !mapp(job) || job["beg_time"] <= 0 || job["stage"] == "over" ){
		who->simple_action("$N用力的敲打着竹棒，大家都奇怪的盯着$N。\n");
		return 1;
	}

	if( job["job_type"] == "place" ) check_place(who, job["job_para"]);
	else if( job["job_type"] == "char" ) check_who(who, job["job_para"]);
	else get_newjob(who);

	return 1;
}
int check_place(object who, mixed arg)
{
	int num;
	string area, room, t_room, t_obj;
	object env, *all;

	num  = who->query_job("yu ji", "num");
//	env  = environment(who);
	env  = who->query_room();
	area = env->get_area();
//	room = explode(file_name(env), "/")[sizeof(explode(file_name(env), "/"))-1];
	room = file_name(env);
	if( !arrayp(arg) ) t_room = arg;
	else {
		t_room = arg[0];
		t_obj  = arg[1];
	};

	who->simple_action("$N偷偷的晃动了一下"+this_object()->short()+"发出清脆的梆梆声。\n");
//	if( room + ".c" != t_room )
	if( room != t_room )
		write("可是没人注意到你。\n");
	else if( !t_obj ){
		write("一个人不知从何处冒了出来，从你身边擦身而过，消失不见了。\n");
		if( random(num) >= 2 || num >= 4 ) succ_job(who);
		else get_newjob(who);
	} else {
		all = all_inventory(who);
		foreach(object oo in all){
			if( oo->query_id()[0] != t_obj || !oo->sg_obj() )continue;
			write("一个人手拿着一"+oo->query_unit()+oo->query_id()[1]+"从你身边走过，还向你点了点头。\n");
			if( random(num) >= 2 || num >= 4 )succ_job(who);
                	else get_newjob(who);
			return 1;
		}
		write("一个人健步走了过来，看了你一眼，离开了。\n");
	};

	return 2;
}
int check_who(object who, mixed arg)
{
	int num;
	string t_who, t_obj;
	object env, npc, *all, *obj;
	
	num = who->query_job("yu ji", "num");
	env = environment(who);
	all = all_inventory(env);

	if( !arrayp(arg) ) t_who = arg;
        else {
                t_who = arg[0];
                t_obj  = arg[1];
        };

	who->simple_action("$N装作不经意的样子晃动着"+this_object()->short()+"发出清脆的梆梆声。\n");

	foreach(npc in all){
		if( npc->query_id()[0] == t_who ){
			if( !t_obj ){
				npc->targetted_action("$N慢步走到了$T跟前，又慢慢的走了回去。\n",who);
				if( random(num) >= 2 || num >= 4 )succ_job(who);
                		else get_newjob(who);
				return 2;
			};
			obj = all_inventory(who);
			foreach(object oo in obj){
				if( oo->query_id()[0] != t_obj || !oo->sg_obj() )continue;
				who->targetted_action("$N面对$T着拿出一"+oo->query_unit()+oo->query_id()[1]+"。\n", npc);
				npc->targetted_action("$N对着$T悄悄的点了点头。\n", who);
				if( random(num) >= 2 || num >= 4 )succ_job(who);
                                else get_newjob(who);
                                return 3;
			};
			npc->targetted_action("$N向$T打量了两眼，沉默不语。\n", who);
		};
	};
	write("可是什么也没有发生。\n");
	return 1;
}
int succ_job(object who)
{
	write("你只觉的"+this_object()->short()+"变的沉甸甸的，好象装了什么东西。\n");
	write("你的任务完成了，赶紧回去见于吉吧。\n");
	this_object()->set(who->query_id()[0], "ok");
	who->set_job("yu ji", "stage", "over");
	return 1;
}
int get_newjob(object who)
{
	string memo;
	string area, *areas, room, *rooms;
	string char, *chars;
	string obj, *objs;
	int type, ob;

	areas = AREA_D->list_areas();
        area  = areas[random(sizeof(areas))];

	if( random(2) == 1 ){
		type  = 1;
        	rooms = AREA(area)->get_room("list");
        	room  = rooms[random(sizeof(rooms))];
		
        	memo  = AREA_D->get_area(area,"name")+"之"+AREA(area)->get_room(room,"b");
	} else {
		type  = 2;
		chars = CHAR_D->check_char("area", area);
		chars = chars - ({ who->query_id()[0] });
		char  = chars[random(sizeof(chars))];
		memo  = AREA_D->get_area(area,"name")+"之"+CHAR_D->get_char(char, "name")+"("+char+")";
	};
	if( random(3) == 1){
		ob   = 1;
		objs = keys(OBJ_D->get_obj());
		objs = filter_array(objs, (: OBJ_D->get_obj($1, "level")==1 && OBJ_D->get_obj($1, "type") != "horse" :));
		obj  = objs[random(sizeof(objs))];
	};

	if( type == 1 ){
		who->set_job("yu ji", "job_type", "place");
		if( ob == 1 ) who->set_job("yu ji", "job_para", ({"/a/"+area+"/"+room, obj }));
		else who->set_job("yu ji", "job_para", 	"/a/"+area+"/"+room);
	} else {
		who->set_job("yu ji", "job_type", "char");
		if(  ob == 1 ) who->set_job("yu ji", "job_para", ({char, obj}));
		else who->set_job("yu ji", "job_para", char);
	}

	if( ob == 1 ){
		write("你只听到有人低声对你说：现在你的任务是找到"+memo+"，暗号是："+OBJ_D->get_obj(obj, "name")+"。\n");
		memo = memo + "--(" + OBJ_D->get_obj(obj, "name")+ ")";
	} else write("你只听到有人低声对你说：现在你的任务是找到"+memo+"。\n");

	who->set_job("yu ji", "memo", memo);
	who->set_job("yu ji", "num", who->query_job("yu ji", "num")+1);

	return 1;
}
