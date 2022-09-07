// by fire
/* Do not remove the headers from this file! see /USAGE for more info. */
#include <ansi.h>
#define BOOK_FILE "/sgdomain/obj/other/bs"
inherit LIVING;
inherit M_BLOCKEXITS;

private mapping m_list=([
"cz1" : (["name" : "�����ԡ�����ƪ��", "skill" : "chenzhuo" , "lev" : 30,"vol" : 1]),
"cz2" : (["name" : "�����ԡ�����ƪ��", "skill" : "chenzhuo" , "lev" : 60,"vol" : 2]),
"cz3" : (["name" : "�����ԡ�����ƪ��", "skill" : "chenzhuo" , "lev" : 90,"vol" : 3]),
"fire1" : (["name" : "�����ӱ�������ƪ��", "skill" : "jbhj" , "lev" : 30,"vol" : 1]),
"fire2" : (["name" : "�����ӱ�������ƪ��", "skill" : "jbhj" , "lev" : 60,"vol" : 2]),
"fire3" : (["name" : "�����ӱ�������ƪ��", "skill" : "jbhj" , "lev" : 90,"vol" : 3]),
"water1" : (["name" : "�����ӱ�����ˮ��ƪ��", "skill" : "jbsj" , "lev" : 30,"vol" : 1]),
"water2" : (["name" : "�����ӱ�����ˮ��ƪ��", "skill" : "jbsj" , "lev" : 60,"vol" : 2]),
"water3" : (["name" : "�����ӱ�����ˮ��ƪ��", "skill" : "jbsj" , "lev" : 90,"vol" : 3]),
"hl1" : (["name" : "����躡�����ƪ��", "skill" : "hunluan" , "lev" : 30,"vol" : 1]),
"hl2" : (["name" : "����躡�����ƪ��", "skill" : "hunluan" , "lev" : 60,"vol" : 2]),
"hl3" : (["name" : "����躡�����ƪ��", "skill" : "hunluan" , "lev" : 90,"vol" : 3]),
"sq1" : (["name" : "���ϵ����顤ʿ��ƪ��", "skill" : "guwu" , "lev" : 30,"vol" : 1]),
"sq2" : (["name" : "���ϵ����顤ʿ��ƪ��", "skill" : "guwu" , "lev" : 60,"vol" : 2]),
"sq3" : (["name" : "���ϵ����顤ʿ��ƪ��", "skill" : "guwu" , "lev" : 90,"vol" : 3]),
"jm1" : (["name" : "��������ʮ�ıࡤ����ƪ��", "skill" : "jiaoma" , "lev" : 30,"vol" : 1]),
"jm2" : (["name" : "��������ʮ�ıࡤ����ƪ��", "skill" : "jiaoma" , "lev" : 60,"vol" : 2]),
"jm3" : (["name" : "��������ʮ�ıࡤ����ƪ��", "skill" : "jiaoma" , "lev" : 90,"vol" : 3]),
"qb1" : (["name" : "������ӡ����ƪ��", "skill" : "qibing" , "lev" : 30,"vol" : 1]),
"qb2" : (["name" : "������ӡ����ƪ��", "skill" : "qibing" , "lev" : 60,"vol" : 2]),
"qb3" : (["name" : "������ӡ����ƪ��", "skill" : "qibing" , "lev" : 90,"vol" : 3]),
"hb1" : (["name" : "������ӡ��ɱ�ƪ��", "skill" : "huangbao" , "lev" : 30,"vol" : 1]),
"hb2" : (["name" : "������ӡ��ɱ�ƪ��", "skill" : "huangbao" , "lev" : 60,"vol" : 2]),
"hb3" : (["name" : "������ӡ��ɱ�ƪ��", "skill" : "huangbao" , "lev" : 90,"vol" : 3]),
"jcml1" : (["name" : "�����ӱ��������ƪ��", "skill" : "fakeorder" , "lev" : 30,"vol" : 1]),
"jcml2" : (["name" : "�����ӱ��������ƪ��", "skill" : "fakeorder" , "lev" : 60,"vol" : 2]),
"jcml3" : (["name" : "�����ӱ��������ƪ��", "skill" : "fakeorder" , "lev" : 90,"vol" : 3]),
"nh1" : (["name" : "��������ʮ�ıࡤ�ü�ƪ��", "skill" : "neihong" , "lev" : 30,"vol" : 1]),
"nh2" : (["name" : "��������ʮ�ıࡤ�ü�ƪ��", "skill" : "neihong" , "lev" : 60,"vol" : 2]),
"nh3" : (["name" : "��������ʮ�ıࡤ�ü�ƪ��", "skill" : "neihong" , "lev" : 90,"vol" : 3]),
"ss1" : (["name" : "�����ԡ���ʰƪ��", "skill" : "shoushi" , "lev" : 30,"vol" : 1]),
"ss2" : (["name" : "�����ԡ���ʰƪ��", "skill" : "shoushi" , "lev" : 60,"vol" : 2]),
"ss3" : (["name" : "�����ԡ���ʰƪ��", "skill" : "shoushi" , "lev" : 90,"vol" : 3]),
"mf1" : (["name" : "������ӡ�����ƪ��", "skill" : "maifu" , "lev" : 30,"vol" : 1]),
"mf2" : (["name" : "������ӡ�����ƪ��", "skill" : "maifu" , "lev" : 60,"vol" : 2]),
"mf3" : (["name" : "������ӡ�����ƪ��", "skill" : "maifu" , "lev" : 90,"vol" : 3]),
"ff1" : (["name" : "���ϵ����顤�ܷ�ƪ��", "skill" : "fenfa" , "lev" : 30,"vol" : 1]),
"ff2" : (["name" : "���ϵ����顤�ܷ�ƪ��", "skill" : "fenfa" , "lev" : 60,"vol" : 2]),
"ff3" : (["name" : "���ϵ����顤�ܷ�ƪ��", "skill" : "fenfa" , "lev" : 90,"vol" : 3]),
"mh1" : (["name" : "�����ӱ��������ƪ��", "skill" : "miehuo" , "lev" : 30,"vol" : 1]),
"mh2" : (["name" : "�����ӱ��������ƪ��", "skill" : "miehuo" , "lev" : 60,"vol" : 2]),
"mh3" : (["name" : "�����ӱ��������ƪ��", "skill" : "miehuo" , "lev" : 90,"vol" : 3]),
"ls1" : (["name" : "����躡���ʯƪ��", "skill" : "luoshi" , "lev" : 30,"vol" : 1]),
"ls2" : (["name" : "����躡���ʯƪ��", "skill" : "luoshi" , "lev" : 60,"vol" : 2]),
"ls3" : (["name" : "����躡���ʯƪ��", "skill" : "luoshi" , "lev" : 90,"vol" : 3]),
"rs1" : (["name" : "�����ӱ���������ƪ��", "skill" : "luanshe" , "lev" : 30,"vol" : 1]),
"rs2" : (["name" : "�����ӱ���������ƪ��", "skill" : "luanshe" , "lev" : 60,"vol" : 2]),
"rs3" : (["name" : "�����ӱ���������ƪ��", "skill" : "luanshe" , "lev" : 90,"vol" : 3]),
"zc1" : (["name" : "������ӡ����ƪ��", "skill" : "scout" , "lev" : 30,"vol" : 1]),
"zc2" : (["name" : "������ӡ����ƪ��", "skill" : "scout" , "lev" : 60,"vol" : 2]),
"zc3" : (["name" : "������ӡ����ƪ��", "skill" : "scout" , "lev" : 90,"vol" : 3]),
"sg1" : (["name" : "������ӡ��ٹ�ƪ��", "skill" : "sugong" , "lev" : 30,"vol" : 1]),
"sg2" : (["name" : "������ӡ��ٹ�ƪ��", "skill" : "sugong" , "lev" : 60,"vol" : 2]),
"sg3" : (["name" : "������ӡ��ٹ�ƪ��", "skill" : "sugong" , "lev" : 90,"vol" : 3]),
]);

private mixed handle_blocks( string dir )
{
	object o;
        o=present("cang shu",this_body());
	if(objectp(o)) {
		this_body()->targetted_action(
"$N��$O������$T��\n",this_object(),o);
		o->remove();
	}
	return 0;
}

void setup()
{
        set_name("lao taijian", "��̫��");
        set_gender(0);
        set_in_room_desc("��̫��(lao taijian)");
        set_age(60);
    add_id("taijian");
        add_question("book","book");
        add_ask_str("book","$N��$T������ʥ�϶�׼���������鷿�����һ�������͹����ˡ�\n");
        add_question("list1","list1");
        add_ask_str("list1","$N��$T�������ʹ�������Щʲô����ѽ��\n");
        add_question("list2","list2");
        add_ask_str("list2","$N��$T�������ʹ�������Щʲô����ѽ��\n");
        add_question("list3","list3");
        add_ask_str("list3","$N��$T�������ʹ�������Щʲô����ѽ��\n");
        add_block("south");

}
string long() {
        return "һ����ü��Ŀ����̫�࣬��ִ������������΢΢һЦ��\n";
}
void input_book(object who, string str) {
	object u,bk,shoyu;
	string *list;
	string p_id;
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
	 shoyu=present("ysf pass",who);
        if(objectp(shoyu)) {
                shoyu->remove();
        }
        shoyu=present("shouyu",who);
        if(objectp(shoyu)) {
                shoyu->remove();
		}
	bk=new(BOOK_FILE);
	bk->add_id(m_list[str]["name"]+"��"+chinese_number(m_list[str]["vol"])+"��");
	bk->set_skill(m_list[str]["skill"]);
	bk->set_lev(m_list[str]["lev"]);
	who->targetted_action("$N��$T˵��Щʲô��\n",this_object());
	this_object()->targetted_action("$N����$T$O��\n",who,bk);
	bk->move(who);
}
void ask_book(object who) {
	object u;
	object shoyu;
	string p_id;
	shoyu=present("ysf pass",who);
	if(!objectp(shoyu)) {
		this_object()->targetted_action(
"$N��$T����û��ʥ�ϵ����ͣ���ū��������Խ��顣\n",who);
		return ;
	}
	shoyu->remove();
	this_object()->targetted_action(
"$N��$T������˵����˵����֪$RҪ���Ĳ����顣\n",who);
	u=who->query_link();
	if(!objectp(u)) return;
	u->modal_push((: input_book, who :),"����������š�\n");
}

void ask_list1(object who, int v) {
	string msg;
	string *list;

	this_object()->targetted_action(
"$N��$T�����������ǲ��٣�����ȴ���࣬���������¼�����\n",who);
        msg="id               ����\n";
	list=keys(m_list);
	foreach(string l in list) {
		if(m_list[l]["vol"]!=v) continue;
		msg+=sprintf("%-7s  %-24s %s\n",l,m_list[l]["name"],"��"+
			chinese_number(m_list[l]["vol"])+"��");
	}
	tell_user(who->query_primary_id(),msg);
	return ;
}


void special_answer(object who, string matt)
{
	switch(matt) {
		case "book":
			ask_book(who);
			return ;
		case "list1":
			ask_list1(who,1);
			return ;

		case "list2":
			ask_list1(who,2);
			return ;
                case "list3":
                        ask_list1(who,3);
                        return ;

	}
}
