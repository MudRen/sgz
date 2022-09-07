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
	set_name("master", HIY+"��ѧ��ʦ"+NOR);
        add_id("matrial master");
        set_in_room_desc("һλ�����ڵ���ѧ��ʦ(master)");
        set_long("һλ�����ڵ���ѧ��ʦ(master)");
	set_age(50);
        set_gender(1);
	add_question("join", "join");
        add_ask_str("join", "$N��$T�����ʵ���$R��$s�����μӡ�\n");
	stage = 0;
}
string long() {
        return "һλ�����ڵ���ѧ��ʦ(master)\n";
}
mixed special_answer(object ob, string str){
	string name, nation, *who;
	int my_level;

	my_level=ob->query_sk_level("sk_wuli");
        if( str != "join" ) return ::special_answer(ob, str);
	name = ob->query_id()[0];

	if( stage < 1 )	
		this_object()->targetted_action("$N��$T������Ǹ����ỹδ�ٿ��ء�\n", ob);
	else if( stage > 1 )
		this_object()->targetted_action("$N��$T������Ǹ������Ѿ���ʼ�ˡ�\n", ob);
	else if( !nation = CHAR_D->get_char(name, "nation") )	
		this_object()->targetted_action("$N��$T������Ǹ���޹�����ʿ���ܲμӡ�\n", ob);

	else if( (level ==1 ) && (my_level<50))
		this_object()->targetted_action("$N��$T������Ǹ������"+s_level+"�������������������\n", ob);

	else if( (level ==0 ) && (my_level>=50))
		this_object()->targetted_action("$N��$T������Ǹ������"+s_level+"�������������̫�ߡ�\n", ob);

	else if( fighter&&mapp(fighter) ){	
		who = fighter[nation];
		if( !who || !arrayp(who) ) who = ({ });
		if( member_array(name, who) != -1 )	
			this_object()->targetted_action("$N��$T�������Եȣ�������Ͽ�ʼ��\n", ob);
		else if( sizeof(who) == 2 )
			this_object()->targetted_action("$N��$T��������������˲��������½�������\n", ob);
		else {
			who = who - ({name});
			who = who + ({name});
			fighter[nation] = who;
			this_object()->responda("nod");
			do_chat(COUNTRY_D->get_country(nation, "name")+"��"+
				CHAR_D->get_char(name,"name")+"Ҫ������Ⱥ����ս��");
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

	s_level=(p_level==1 ? "������" : "���ż�");

	area=p_area;
	fighter = ([ ]);
	if( !tt || !intp(tt) ) tt = 1;
	call_out("auto_run", 10);
	do_chat("��"+chinese_number(tt)+"������־֮"+s_level+
		"�佫���Դ���Ҫ��ʼ�ˣ�����������Ӣ��һ�ȸߵ��ߣ�������"+
		AREA_D->get_area(area,"name")+"������");
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
		do_chat("����μ�"+s_level+"�佫���Դ���ߣ�������"+
			AREA_D->get_area(area,"name")+"������");
		do_chat("����ʱ�仹�У�"+chinese_number(9-time)+"���ӡ�");
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
		do_chat(COUNTRY_D->get_country(nn, "name")+"��Ȩ�����μӱ��δ�ᡣ");
	}	
	all = ({ });
	winner = ({ });
	foreach( nn in keys(fighter) ){
		if( arrayp(fighter[nn]) ) all = all + fighter[nn];
	}	
	if( sizeof(all) < 2 ){
		do_chat("�μ�����̫�٣��˴δ��ʹ˽�����");
		stage = 0;
		leave();
	};
	return;
}
void process_fight(){
	remove_call_out("process_fight");
	if( sizeof(all) == 1 ){
		winner = winner + ({ all[0] });
		do_chat(CHAR_D->get_char(all[0],"name")+"�ֿգ�ֱ�ӽ�����һ�֡�");
		all = ({ });
		process_fight();
	} else if( sizeof(all) == 0 ){
		if( sizeof(winner) == 1 ) annouce_winner();
		else {
			all = winner;
			winner = ({ });
			do_chat("��"+chinese_number(turn)+"�ֱ�����ϣ���һ�����Ͽ�ʼ��");
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
		do_chat("��"+chinese_number(turn)+"�ֵ�"+chinese_number(cang)+"��������"+CHAR_D->get_char(one,"name")+"����"+CHAR_D->get_char(two,"name")+"��");
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
		do_chat(CHAR_D->get_char(one,"name")+"ȱϯ���䣡");
		do_player_win(two);
		return;
	};
	o_two = CHAR_D->find_char(two);
	if( !o_two || !objectp(o_two) ){
                do_chat(CHAR_D->get_char(two,"name")+"ȱϯ���䣡");
                do_player_win(one);
                return;
        };
	o_one->move(env);
	o_two->move(env);
	o_one->set_cur_hp(o_one->query_cur_max_hp());
	o_two->set_cur_hp(o_two->query_cur_max_hp());
	o_one->simple_action("$N�첽�߽�"+env->short()+"��\n");
	o_two->simple_action("$N�첽�߽�"+env->short()+"��\n");
	do_chat("��"+chinese_number(turn)+"�ֵ�"+chinese_number(cang)+"��������ʼ��");
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
	do_chat("��"+chinese_number(turn)+"�ֵ�"+chinese_number(cang)+
		"����"+CHAR_D->get_char(who,"name")+"ʤ��");
	do_chat("ʤ�߽��������ƽ𣬸��߽��������ƽ�");

	call_out("process_fight", 10);
}
void annouce_winner(){
	string name, cname, king;
	int r_money;
	name  = winner[0];
	cname = CHAR_D->get_char(name, "name");
	king  = CHAR_D->get_char(name, "nation");
	do_chat("��"+chinese_number(which)+"������־"+s_level+"֮�佫���Դ�ᵽ�˽�����");
	do_chat(cname+"��ѹȺ�ۣ��¶᱾��İ�����");
	
	r_money=(level==1 ? 50 : 20 );
	CHAR_D->set_char(name,"gold",
		CHAR_D->get_char(name,"gold")+r_money);

	CHAR_D->set_char(name, "reputation", CHAR_D->get_char(name, "reputation")+1000);
	CHAR_D->set_char(king, "reputation", CHAR_D->get_char(king, "reputation")+1000);

	do_chat(cname+"���ͽ�"+chinese_number(r_money)+"����");
	do_chat(cname+"������һǧ�㡣");
	do_chat(COUNTRY_D->get_country(king, "name")+"�Ĺ���"+CHAR_D->get_char(king,"name")+"������һǧ�㡣");
	do_chat("��ɽ���ģ���ˮ��������λӢ�ۺ��ܣ����������ٻᡣ");
	HIS("��"+chinese_number(which)+"��"+s_level+"����־֮�佫���Դ����"+
		AREA_D->get_area(area,"name")+"����\n"+cname+"��ѹȺ�ۣ��¶᱾��İ�����");
	leave();
//	destruct(this_object());
}
