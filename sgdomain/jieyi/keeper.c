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
    set_name("old keeper", "老店主");
    set_gender(1);
    set_proper_name("老店主");
    set_in_room_desc("老店主(old keeper)");
    add_id("keeper");
    set_age(70);
    set_long("一个白发苍苍、年迈体弱的老人，惨淡经营着这家香烛店。\n不过由于他是虔诚的佛教徒，也就乐善好施，当然只是给一些店里有的东西了。\n(ask old keeper about incense)");
	add_question("name","name" );
	add_question("here","here");
	add_question("rumors","rumors");
	add_question("incense","incense");
	add_ask_str("incense","$N对$T躬身一拜，道：$s欲行祭祀大礼，敢问老丈求些好香，不知。。。\n");
}
void special_answer(object who, string matt)
{
	object incense;
	object ob;
	switch(matt)
	{
		case "name" :
			this_object()->simple_action("$N咳嗽了几声，用苍老的声音答道："+
"老夫归隐已久，这名字不提也罢。\n");
 			return;
 		case "here" :
			this_object()->simple_action(
"$N慢条斯理地道：老夫闲来无事，权且开这一家小店了度残生。\n");
			return;
		case "rumors" :
			this_object()->targetted_action("$N看了$T一眼，道："+
"你若有心，就该解救众黎民于乱世。。。\n",this_body());
			return;
		case "incense" :
	ob=present("incense",this_body());
	if(objectp(ob))
	{
	this_object()->targetted_action("$N对$T摇摇头道：你既已有了，何必再问老夫要呢？\n",this_body());
	return;
	}
	this_object()->targetted_action("$N看了$T一眼，微微颔首：嗯，记住，心诚则灵啊。\n$N递给$T一支%^CYAN%^香%^RESET%^。\n",this_body());
	incense=new("/sgdomain/jieyi/incense.c");
	incense->move(this_body());
	}
}