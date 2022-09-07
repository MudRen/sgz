// created by row Aug. 1999
/* Do not remove the headers from this file! see /USAGE for more info. */
#include <mudlib.h>
#include <sanguo.h>
inherit LIVING;
inherit M_ACTIONS;
inherit M_TRIGGERS;
inherit CHINESE_DA;
string *query_channel_list() {
    return ({ "plyr_gossip" });
}
void setup()
{
    set_name("old keeper", "�ϵ���");
    set_gender(1);
    set_proper_name("�ϵ���");
    set_in_room_desc("�ϵ���(old keeper)");
    add_id("keeper");
    set_age(70);
    set_long("һ���׷��Բԡ��������������ˣ��ҵ���Ӫ���������ꡣ\n�������������ϵķ��ͽ��Ҳ�����ƺ�ʩ����Ȼֻ�Ǹ�һЩ�����еĶ����ˡ�\n(ask old keeper about incense)");
	add_question("name","name" );
	add_question("here","here");
	add_question("rumors","rumors");
	add_question("incense","incense");
	add_ask_str("incense","$N��$T����һ�ݣ�����$s���м�����񣬸���������Щ���㣬��֪������\n");
}
void special_answer(object who, string matt)
{
	object incense;
	object ob;
	switch(matt)
	{
		case "name" :
			this_object()->simple_action("$N�����˼������ò��ϵ����������"+
"�Ϸ�����Ѿã������ֲ���Ҳ�ա�\n");
 			return;
 		case "here" :
			this_object()->simple_action(
"$N����˹��ص����Ϸ��������£�Ȩ�ҿ���һ��С���˶Ȳ�����\n");
			return;
		case "rumors" :
			this_object()->targetted_action("$N����$Tһ�ۣ�����"+
"�������ģ��͸ý��������������������\n",this_body());
			return;
		case "incense" :
	ob=present("incense",this_body());
	if(objectp(ob))
	{
	this_object()->targetted_action("$N��$Tҡҡͷ������������ˣ��α������Ϸ�Ҫ�أ�\n",this_body());
	return;
	}
	this_object()->targetted_action("$N����$Tһ�ۣ�΢΢��ף��ţ���ס���ĳ����鰡��\n$N�ݸ�$Tһ֧%^CYAN%^��%^RESET%^��\n",this_body());
	incense=new("/sgdomain/jieyi/incense.c");
	incense->move(this_body());
	}
}