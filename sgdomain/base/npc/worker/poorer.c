// sleeper.c
inherit __DIR__+"worker";
string get_room_desc() {
	return "�������ڵ�"+p_workername+c_name+"("+my_id+")";
}

mixed extra_init() {
	set_steps(2); // just two judge way

	create_scenario("noise1");
	add_act("noise1","n1","MTW",1,"$N��$T��ô����ظɻ����ȴ�������ã�����ܹ��ⲻȥ��\n");

	create_scenario("noise2");
	add_act("noise2","n1","WTO",1,"$Nһ��С�ģ����ϵĺ�����˺��һ�����ӡ�\n");

	create_scenario("noise3");
	add_act("noise3","n1","HEW",1,"scowl");
}

string get_prompt() {
	return "��ô�죿�����(a) ��(l) ����(0) �ʹ���������(1)\n";
}

string get_desc(int lv) {
	if(random(lv)<20)
		return "$m������"+p_workername+"û��ʲô��ͬ��\n";
	if(status<4)
		return "$mƽʱ����һ�����Ĺ�\n";
	if(status<6)
		return "$m������"+p_workername+"û��ʲô��ͬ��\n";
	return "$m������ĸ�������ಡ������ܼ�ࡣ\n";
}
string get_look_desc() {
	int sk;
	sk=CHAR_D->get_skill(p_id,"sk_zhimou");
	return get_desc(sk);
}
string get_ask_desc() {
	object bs;
	mixed hd;
	int sk;
	bs=SGBASE(p_area,f_id);
	hd=bs->get_room(r_id,"head");
	sk=hd["pw"];
	return get_desc(sk);
}

void final_act(int sel,int err) {
	int score;

	if(err<=1) 
		score=2;
	else if(err<=2)
		score=1;
	else if(err<=3)
		score=0;
	else 
		score=-1;
	if(objectp(p_menu))
		p_menu->add_score(score);
	announce_score(score);

	create_scenario("bye");
	switch(sel) {
	case 0:
		add_act("bye","kick","MTW",0,"$N��$T������˵������ǮҲ���ͣ�������ô�������õ���ʲô����\n");
		add_act("bye","wake","WEO",1,"inn");
		if(score>0) 
			add_act("bye","run","WTM",2,
				"$Næ��Ц����$s��������֪��$R���Ӳ죬Ӧ���������·��Ŷԡ�\n");
		else
			add_act("bye","run","WTM",2,
				"$N����������ţ������Ǳ��������$r�����ġ�\n");
		break;
	case 1:
		MONEY_D->sub_all_money(master,500);
		add_act("bye","kick","MTW",0,"$N��$T������˵���Ǹ�Т���Ķ��ӣ��е�Ǯ������ĸ�׿����ˡ�\n"+
			"�������������ӣ���ȥ����²��°ɡ�\n");
		add_act("bye","dd","MTW",1,"$N����$T�������ӡ�\n");
		if(score>0) {
			add_act("bye","run","WEM",2,"courage1");
			add_act("bye","leave","WTO",3,
				"$N�뿪�ɻ�ȥ�ˡ�\n");
		}
		else {
			add_act("bye","run","WEO",2,"grin");
			add_act("bye","leave","WTO",3,"$N��Ǯ����Ь�ף�ĥĥ�����뿪�ɻ�ȥ�ˡ�\n");
		}
		break;
	}
	disappear();
}
void show_start() {
	create_scenario("start");
	add_act("start","1","MTW",1,"$N��ͷ������$T���ף�������ô�и�Ҫ���ġ�\n");
	add_act("start","2","HTW",2,"$Næ���͵������ǲ��ǣ��������ǵ�"+p_workername+
		"����$m��\n");
	add_act("start","3","MEO",3,"oh");
	do_scenario("start");
}