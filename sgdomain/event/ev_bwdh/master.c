#include <mudlib.h>
#include <ansi.h>

#define do_chat(x) CHANNEL_D->deliver_tell("gossip",this_object()->short(),x)
#define BW_ROOM __DIR__"bw_room.c"
#define COMBAT_FIGHT 1

inherit M_CHAR;
inherit LIVING;

private int stage;
private int time;
private int turn;
private int cang;
private int which;
private int level;

private string s_level;
private string area;


private int checks;
private mapping fighter;
private string *all;
private string *winner;
private string one;
private string two;

void do_init_fight();
void process_fight();
void annouce_winner();
void do_check();
void put_players();
void do_player_win(string who);

void leave() {
	object o_rm,o_env;
	object *obs;
	o_env=this_object()->query_room();
	o_rm=load_object("/a/"+area+"/"+AREA_D->get_area(area,"fly"));
	obs=deep_inventory(o_env);
	if(sizeof(obs)) {
		foreach(object o in obs) {
			if(objectp(o->query_link()))
				o->move(o_rm);

		}
	}
	o_rm->delete_exit("bwdh");
	destruct(o_env);
}
void setup(){        
	set_name("master", HIY+"武学宗师"+NOR);
        add_id("matrial master");
        set_in_room_desc("一位威镇海内的武学宗师(master)");
        set_long("一位威镇海内的武学宗师(master)");
	set_age(50);
        set_gender(1);
	add_question("join", "join");
        add_ask_str("join", "$N向$T躬身问道：$R，$s报名参加。\n");
	stage = 0;
}
string long() {
        return "一位威镇海内的武学宗师(master)\n";
}
mixed special_answer(object ob, string str){
	string name, nation, *who;
	int my_level;

	my_level=ob->query_sk_level("sk_wuli");
        if( str != "join" ) return ::special_answer(ob, str);
	name = ob->query_id()[0];

	if( stage < 1 )	
		this_object()->targetted_action("$N对$T道：抱歉，大会还未召开呢。\n", ob);
	else if( stage > 1 )
		this_object()->targetted_action("$N对$T道：抱歉，大会已经开始了。\n", ob);
	else if( !nation = CHAR_D->get_char(name, "nation") )	
		this_object()->targetted_action("$N对$T道：抱歉，无国籍人士不能参加。\n", ob);

	else if( (level ==1 ) && (my_level<50))
		this_object()->targetted_action("$N对$T道：抱歉，这是"+s_level+"比赛，你的武力不够。\n", ob);

	else if( (level ==0 ) && (my_level>=50))
		this_object()->targetted_action("$N对$T道：抱歉，这是"+s_level+"比赛，你的武力太高。\n", ob);

	else if( fighter&&mapp(fighter) ){	
		who = fighter[nation];
		if( !who || !arrayp(who) ) who = ({ });
		if( member_array(name, who) != -1 )	
			this_object()->targetted_action("$N对$T道：请稍等，大会马上开始。\n", ob);
		else if( sizeof(who) == 2 )
			this_object()->targetted_action("$N对$T道：贵国已有两人参赛，请下届再来。\n", ob);
		else {
			who = who - ({name});
			who = who + ({name});
			fighter[nation] = who;
			this_object()->responda("nod");
			do_chat(COUNTRY_D->get_country(nation, "name")+"的"+
				CHAR_D->get_char(name,"name")+"要向天下群雄挑战。");
		}	
	}	
	return;
}
void add_connect() {
	object o_rm,o_env;
	o_env=this_object()->query_room();
	o_rm=load_object("/a/"+area+"/"+AREA_D->get_area(area,"fly"));
	o_rm->add_exit("bwdh",file_name(o_env));
	o_env->add_exit("out",file_name(o_rm));
}
void start(int tt,int p_level,string p_area){
	stage 	= 1;
 	time  	= 0;
	turn    = 1;
	cang 	= 0;
	which	= tt;
	level = p_level;

	s_level=(p_level==1 ? "霸王级" : "入门级");

	area=p_area;
	fighter = ([ ]);
	if( !tt || !intp(tt) ) tt = 1;
	call_out("auto_run", 10);
	do_chat("第"+chinese_number(tt)+"届三国志之"+s_level+
		"武将争霸大会就要开始了，有意于天下英雄一比高低者，请速来"+
		AREA_D->get_area(area,"name")+"报名。");
	add_connect();	
}
void start_now(){
	remove_call_out("auto_run");
	time = 10;
	stage = 3;
	do_init_fight();
	call_out("auto_run", 10);
}
void auto_run(){
	remove_call_out("auto_run");
	if( stage == 1 ){  // Waiting for players
		time++;
		if( time >= 9 ) stage = 2;
		do_chat("有意参加"+s_level+"武将争霸大会者，请速来"+
			AREA_D->get_area(area,"name")+"报名。");
		do_chat("报名时间还有："+chinese_number(9-time)+"分钟。");
		call_out("auto_run", 60);
	} else if( stage == 2 ){ // Initial fight
		stage = 3;
		do_init_fight();
		call_out("auto_run", 10);
	} else if( stage == 3 )	{ // Start fight
		process_fight();
	}
//	else if( stage == 0 ){ // Stop fight
//	}
	add_connect();

}
void do_init_fight(){
	string nn, *nations;
	nations = COUNTRY_D->list_countries();
	foreach( nn in nations ){
		if( member_array(nn, keys(fighter)) != -1 )continue;
		do_chat(COUNTRY_D->get_country(nn, "name")+"弃权，不参加本次大会。");
	}	
	all = ({ });
	winner = ({ });
	foreach( nn in keys(fighter) ){
		if( arrayp(fighter[nn]) ) all = all + fighter[nn];
	}	
	if( sizeof(all) < 2 ){
		do_chat("参加人数太少，此次大会就此结束。");
		stage = 0;
		leave();
	};
	return;
}
void process_fight(){
	remove_call_out("process_fight");
	if( sizeof(all) == 1 ){
		winner = winner + ({ all[0] });
		do_chat(CHAR_D->get_char(all[0],"name")+"轮空，直接进入下一局。");
		all = ({ });
		process_fight();
	} else if( sizeof(all) == 0 ){
		if( sizeof(winner) == 1 ) annouce_winner();
		else {
			all = winner;
			winner = ({ });
			do_chat("第"+chinese_number(turn)+"局比赛完毕，下一局马上开始。");
			turn++;
			cang = 0;
			call_out("process_fight", 5);
		};
	} else {
		one = all[random(sizeof(all))];
		all = all - ({ one });
		two = all[random(sizeof(all))];
		all = all - ({ two });
		cang++;
		do_chat("第"+chinese_number(turn)+"局第"+chinese_number(cang)+"场比赛："+CHAR_D->get_char(one,"name")+"ｖｓ"+CHAR_D->get_char(two,"name")+"。");
		call_out("put_players", 5);
	}
	return;
}
void put_players(){
	object env, o_one, o_two;
	string a_id,b_id;
	env = load_object(BW_ROOM);
	o_one = CHAR_D->find_char(one);
	if( !o_one || !objectp(o_one) ){
		do_chat(CHAR_D->get_char(one,"name")+"缺席算输！");
		do_player_win(two);
		return;
	};
	o_two = CHAR_D->find_char(two);
	if( !o_two || !objectp(o_two) ){
                do_chat(CHAR_D->get_char(two,"name")+"缺席算输！");
                do_player_win(one);
                return;
        };
	o_one->move(env);
	o_two->move(env);
	o_one->set_cur_hp(o_one->query_cur_max_hp());
	o_two->set_cur_hp(o_two->query_cur_max_hp());
	o_one->simple_action("$N快步走进"+env->short()+"。\n");
	o_two->simple_action("$N快步走进"+env->short()+"。\n");
	do_chat("第"+chinese_number(turn)+"局第"+chinese_number(cang)+"场比赛开始。");
	a_id=o_one->query_primary_id();
	b_id=o_two->query_primary_id();
	FIGHT_D->add_fight(a_id,({b_id}),COMBAT_FIGHT); // 1 is common fight
        FIGHT_D->add_fight(b_id,({a_id}),COMBAT_FIGHT);
        o_one->start_fight(o_two);
	checks = 0;
	do_check();
	return;
}
void do_check(){
	object o_one, o_two;
	remove_call_out("do_check");
	o_one = CHAR_D->find_char(one);
	o_two = CHAR_D->find_char(two);
	if( !o_one->is_fighting() || !o_two->is_fighting() )
	o_one->start_fight(o_two);
	checks++;
	if( checks>=60 ){
		if( (o_one->query_cur_hp()/o_one->query_cur_max_hp())
		  > (o_two->query_cur_hp()/o_two->query_cur_max_hp()) )
			do_player_win(one);
		else 	do_player_win(two);
		checks = 0;
	} else {
		if( o_one->query_cur_hp() <= 60 ) do_player_win(two);
		else if( o_two->query_cur_hp() <= 60 ) do_player_win(one);
		else call_out("do_check", 3);
	};
}
void do_player_win(string who){
	object o_one, o_two;
	winner = winner - ({ who });
	winner = winner + ({ who });
	o_one = CHAR_D->find_char(one);
        o_two = CHAR_D->find_char(two);

	CHAR_D->set_char(one,"gold",CHAR_D->get_char(one,"gold")+2);
	CHAR_D->set_char(two,"gold",CHAR_D->get_char(two,"gold")+2);

	CHAR_D->set_char(who,"gold",CHAR_D->get_char(who,"gold")+2);
	if (o_one)
	{o_one->move(environment(this_object()));
	o_one->stop_fight(0);}
        if (o_two)
	{o_two->move(environment(this_object()));
	o_two->stop_fight(0);}
	do_chat("第"+chinese_number(turn)+"局第"+chinese_number(cang)+
		"场："+CHAR_D->get_char(who,"name")+"胜！");
	do_chat("胜者奖励五两黄金，负者奖励二两黄金。");

	call_out("process_fight", 10);
}
void annouce_winner(){
	string name, cname, king;
	int r_money;
	name  = winner[0];
	cname = CHAR_D->get_char(name, "name");
	king  = CHAR_D->get_char(name, "nation");
	do_chat("第"+chinese_number(which)+"届三国志"+s_level+"之武将争霸大会到此结束！");
	do_chat(cname+"技压群雄，勇夺本届的霸主！");
	
	r_money=(level==1 ? 50 : 20 );
	CHAR_D->set_char(name,"gold",
		CHAR_D->get_char(name,"gold")+r_money);

	CHAR_D->set_char(name, "reputation", CHAR_D->get_char(name, "reputation")+1000);
	CHAR_D->set_char(king, "reputation", CHAR_D->get_char(king, "reputation")+1000);

	do_chat(cname+"获赏金"+chinese_number(r_money)+"两。");
	do_chat(cname+"获声望一千点。");
	do_chat(COUNTRY_D->get_country(king, "name")+"的国王"+CHAR_D->get_char(king,"name")+"获声望一千点。");
	do_chat("青山不改，绿水长流，各位英雄豪杰，我们来年再会。");
	HIS("第"+chinese_number(which)+"届"+s_level+"三国志之武将争霸大会在"+
		AREA_D->get_area(area,"name")+"举行\n"+cname+"技压群雄，勇夺本届的霸主！");
	leave();
//	destruct(this_object());
}
