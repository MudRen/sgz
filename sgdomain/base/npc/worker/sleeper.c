// sleeper.c
inherit __DIR__+"worker";
string get_room_desc() {
	return "���ں�����˯��"+p_workername+c_name+"("+my_id+")";
}

mixed extra_init() {
	set_steps(2); // just two judge way

	create_scenario("noise1");
	add_act("noise1","n1","WTO",1,"$N���˸����ֺ�����˯�ˡ�\n");

	create_scenario("noise2");
	add_act("noise2","n1","WTO",1,"$N��֪���ε���ʲô���ٺٺٵ�Ц�ˡ�\n");

	create_scenario("noise3");
	add_act("noise3","n1","WTO",1,"$N�ĺ���������������"+p_workername+
		"��ע�⡣��ҷ׷�ת��ͷ������\n");
	add_act("noise3","n2","HTO",2,"$N��������һ�ۣ�����ŵøϿ�ת��������ɻ\n");
}

string get_prompt() {
	return "��ô�죿�����(a) ��(l) һ������(0) ��"+query_pronoun()+"˯(1)\n";
}

string get_desc(int lv) {
	if(random(lv)<20)
		return "$m������"+p_workername+"û��ʲô��ͬ��\n";
	if(status<4)
		return "$mƽʱ����һ����ɢ�ļһ\n";
	if(status<6)
		return "$m������"+p_workername+"û��ʲô��ͬ��\n";
	return "$mƽʱ��һ���ǳ��ڷܵ�"+p_workername+"��\n";
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
		add_act("bye","kick","MEW",0,"kick");
		add_act("bye","wake","WEO",1,"pain");
		if(score>0) 
			add_act("bye","run","WTM",2,
				"$Nһ����$T���ŵõ�ͷ����ȥ�ɻ�ȥ�ˡ�\n");
		else
			add_act("bye","run","WTM",2,
				"$N����������ţ����춼û�����ˣ��ߡ�$M�������ڵظɻ�ȥ�ˡ�\n");
		break;
	case 1:
		add_act("bye","kick","MTH",0,"$N��$TС������"+c_name+
			"�������࣬��"+query_pronoun()+"��˯�����\n");
		add_act("bye","wake","WEO",1,"wake");
		if(score>0) {
			add_act("bye","run","WTM",2,
				"$Nһ����$T����æ�Ϲ�����\n"+"$R����$s��$s��������Ŭ����\n");
			add_act("bye","leave","WTO",3,
				"$N�뿪�ɻ�ȥ�ˡ�\n");
		}
		else {
			add_act("bye","run","WEO",2,"hehe");
			add_act("bye","leave","WTO",3,"$Nĥĥ�����뿪�ɻ�ȥ�ˡ�\n");
		}
		break;
	}
	disappear();
}
void show_start() {
	create_scenario("start");
	add_act("start","1","MTH",1,"$N����$T��"+p_roomname+
		"��Ѳ�ӣ�ͻȻ�������ϴ���һ���������\n");
	add_act("start","2","MTO",2,"$N��һ������ͷһ��������������һ������˯�����\n");
	add_act("start","3","HTO",3,"$N���ε��˵�һ�ߡ�\n");
	do_scenario("start");
}