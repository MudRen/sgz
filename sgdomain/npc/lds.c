// by fire
/* Do not remove the headers from this file! see /USAGE for more info. */
#include <ansi.h>
#define BOOK_FILE "/sgdomain/obj/other/bs"
inherit LIVING;
inherit M_BLOCKEXITS;

private mapping m_list=([
"qmdj" : (["name" : "�����Ŷݼס�", "skill" : "qmdj" , "lev" : 30,"vol" : 1]),
]);

private mapping d_list=([
"yyd" : (["name" : "���յ�", "day" : 49 , "gold" : 100,"strday": "������ʮ����"]),
"csd" : (["name" : "���ٵ�", "day" : 81 , "gold" : 500,"strday": "�žŰ�ʮһ��"]),

]);


private mixed handle_blocks( string dir )
{
	object o;
	o=present("bing shu",this_body());
	if(objectp(o)) {
		this_body()->targetted_action(
"$N��$O������$T��\n",this_object(),o);
		o->remove();
	}
	return 0;
}

void setup()
{
        set_name("zixu shangren", "��������");
        set_gender(1);
        set_in_room_desc("��������(zixu shangren)");
        set_age(60);
	add_id("daoshi");
        add_question("book","book");
        add_ask_str("book","$N��$T������˵�ɳ��в������飬�ɷ��$sһ�ۡ�\n");
        add_question("list","list");
        add_ask_str("list","$N��$T���������ɳ�����Щʲô������鵤ѽ��\n");
        add_question("dan","dan");
        add_ask_str("dan","$N��$T������˵�ɳ�ɽ�ж������������������鵤��$s��һ���󣬲�֪�ܲ���. . . .\n");

        add_question("good","good");
        add_ask_str("good","$N��$T��������Ҫ�ĵ���Ҳ��֪����������û�С�\n");

        add_block("south");

}
string long() {
        return "�����ڴ��н���ɽ���޵������ˣ�ȴ��֪��Ϊʲô��������Ϊ�ʵ�������\n";
}
void input_book(object who, string str) {
	object u,bk,shoyu;
	string *list;
	if(!objectp(who)) return;
	u=who->query_link();
	if(!objectp(u)) return;
	u->modal_pop();
	if(!str) str="";
	list=keys(m_list);
	if(member_array(str,list)==-1) {
		this_object()->targetted_action(
"$N��$T����$R������飬����ô��û��˵��ѽ��\n",who);
		return;
	}
	bk=new(BOOK_FILE);
	bk->add_id(m_list[str]["name"]+"��"+chinese_number(m_list[str]["vol"])+"��");
	bk->set_skill(m_list[str]["skill"]);
	bk->set_lev(m_list[str]["lev"]);
	who->targetted_action("$N��$T˵��Щʲô��\n",this_object());
	this_object()->targetted_action("$N����$T$O\n",who,bk);
	bk->move(who);

	shoyu=present("ysf pass",who);
	if(objectp(shoyu)) {
		shoyu->remove();
	}

}
void ask_book(object who) {
	object u;
	object shoyu;
	shoyu=present("ysf pass",who);
	if(!objectp(shoyu)) {
		this_object()->targetted_action(
"$N��$T����û��ʥ�ϵ����ͣ�������⼸������Ҳ�����Ҹ��˿���\n",who);
		return ;
	}
	this_object()->targetted_action(
"$N��$T������˵����˵����֪$RҪ���Ĳ��顣\n",who);
	u=who->query_link();
	if(!objectp(u)) return;
	u->modal_push((: input_book, who :),"����������š�\n");
}

void ask_list(object who) {
	string msg;
	string *list;
	this_object()->targetted_action(
"$N��$T�����������ǲ��٣����ɳ�Ϊ�����ֻ�����¼�����\n",who);
        msg="id               ����\n";
	list=keys(m_list);
	foreach(string l in list) {
		msg+=sprintf("%-7s  %-24s %s\n",l,m_list[l]["name"],"��"+
			chinese_number(m_list[l]["vol"])+"��");
	}
	list=keys(d_list);
	foreach(string l in list) {
		msg+=sprintf("%-7s  %-24s %s\n",l,d_list[l]["name"],
			chinese_number(d_list[l]["gold"])+"��");
	}

	tell_user(who->query_primary_id(),msg);
	return ;
}
void input_dan(object who, string str) {
	object u;
	string *list;
	int p_gold,p_id;
	object shoyu;
	if(!objectp(who)) return;
	u=who->query_link();
	if(!objectp(u)) return;
	u->modal_pop();
	p_id=who->query_primary_id();
	if(!str) str="";
	list=keys(d_list);
	if(member_array(str,list)==-1) {
		this_object()->targetted_action(
"$N��$T����$R������ɵ�������ô��û��˵��ѽ��\n",who);
		return;
	}
	p_gold=CHAR_D->get_char(p_id,"gold");
	if(p_gold<d_list[str]["gold"]) {
		this_object()->targetted_action(
"$N��$T����$R���ϵ�Ǯ�����\n",who);
		return;
	}
	CHAR_D->set_char(p_id,"gold",p_gold-d_list[str]["gold"]);
	tell_user(p_id,"�����ϵ�"+chinese_number(d_list[str]["gold"])+"���ƽ𱻵�ʿ�����ˡ�\n");
	CHAR_D->set_char(p_id,"lian_dan",(["time" : time(),"dan" : str]));
	this_object()->targetted_action(
"$N��$T����$R��Ҫ��"+d_list[str]["name"]+"����"+d_list[str]["strday"]+
"����ʱ������ȡ�ɵ��ɡ�\n",who);
	shoyu=present("ysf pass",who);
	destruct(shoyu);

}
void ask_dan(object who) {
	object u;
	object shoyu;
	string p_id;

	shoyu=present("ysf pass",who);
	p_id=who->query_primary_id();
	if(p_id!=CHAR_D->get_char(p_id,"nation")) // this is not king
	{
		this_object()->targetted_action(
		  "$N��$T������ֻ��һ��֮��������\n",who);
		return ;
	}

	if(!objectp(shoyu)) {
		this_object()->targetted_action(
"$N��$T����û��ʥ�ϵ����ͣ�����Ҳ�����Ҹ���������\n",who);
		return ;
	}
	this_object()->targetted_action(
"$N��$T������˵����˵����֪$RҪ��ʲô����\n",who);
	u=who->query_link();
	if(!objectp(u)) return;
	u->modal_push((: input_dan, who :),"�������ɵ����š�\n");

}
void ask_good(object who) {
	string p_id;
	mixed my_dan;
	string d_id;
	int t_time;
	object o_dan;
	p_id=who->query_primary_id();
	my_dan=CHAR_D->get_char(p_id,"lian_dan");
	if(!mapp(my_dan)) {
		this_object()->targetted_action(
"$N��$T����$Rû����������ɡ�\n",who);
		return ;
	}
	d_id=my_dan["dan"];
	if(!mapp(d_list[d_id])) {
		this_object()->targetted_action(
"$N��$T�����ܱ�Ǹ��$R�����ĵ�����ʦȡ���ˡ�\n",who);
		return ;
	}
	t_time=time();
	t_time-=my_dan["time"];
	t_time/=60; t_time/=16;
	t_time=d_list[d_id]["day"]-t_time;
	if(t_time>0) {
		this_object()->targetted_action(
"$N��$T����$R�����ĵ�����Ҫ��"+chinese_number(t_time)+"�졣\n",who);
		return ;
	}
	o_dan=new(__DIR__+"dan/"+d_id);
	o_dan->move(this_body());
	CHAR_D->set_char(p_id,"lian_dan",0);
	this_object()->targetted_action(
"$N��$T����$R�����ĵ��Ѿ����ˣ�$m��$n1p$O��\n",who,o_dan);
	
}
void special_answer(object who, string matt)
{
	switch(matt) {
		case "book":
			ask_book(who);
			return ;
		case "list":
			ask_list(who);
			return ;
		case "dan":
			ask_dan(who);
			return ;
		case "good":
			ask_good(who);
			return ;

	}
}
