#include <ansi.h>

inherit LIVING;
inherit M_CHAR;
inherit "/sgdomain/modules/m_charnpc/xianren/xianren_act";
inherit M_SMARTMOVE;

private string who;
private string name;

void do_something(object ob);
void no_answer();
void get_name(string what);
void get_respond(string what);
void answer_skills(object ob);
void check_skills(string *sks, string ans);
void do_learn(string sk, int lvl, string ans);
string get_english_name(string what);

void setup()
{
        object cloth;
        cloth = new("/sgdomain/obj/cloth/torso/hechang.c");
        cloth->move(this_object());
        cloth->do_wear();

        set_name("bao dating", HIY+"流浪的仙人"+NOR+"包打听");
	add_id("bao");
        set_gender(1);
        set_age(50);
        set_proper_name(HIY+"流浪的仙人"+NOR+"包打听(bao dating)");
        set_in_room_desc(HIY+"流浪的仙人"+NOR+"包打听(bao dating)");

        add_question("something", "something");
        add_ask_str("something","$N向$T深深一鞠躬道：小可欲购一物件，但苦不知何处可得，盼先生指教。\n");
	add_question("skills", "skills");
        add_ask_str("skills","$N向$T躬身问道：不知先生有合本领？\n");

	call_out("my_heart",1);
}
mixed special_answer(object ob, string str)
{
	if( who&&stringp(who)&&who!="" ) 
		return this_object()->targetted_action("$N对$T道：请稍等！\n",ob);
	else if( str=="skills" )
		return answer_skills( ob );
	else if( str=="something" ){
		who = ob->query_id()[0];
		return do_something(ob);
	} else return ::special_answer(ob, str);
}
void do_something(object ob)
{
	this_object()->reponda("nod");
	this_object()->targetted_action("$N慢理斯条地对$T说：你要找什么东西呀？\n", ob);
        ob->modal_push((: get_name :),"要找什么啊？");
        call_out("no_answer", 60);
}
void no_answer()
{
	object ob;
	ob = CHAR_D->find_char(who);
	if( objectp(ob) ) ob->modal_pop();
	this_object()->reponda("heng");
	who = "";
}
string get_english_name(string what)
{
	string *list;

	list = keys(OBJ_D->get_obj());
	foreach(string ss in list){
		if( strsrch(OBJ_D->get_obj(ss,"name"), what)!=-1 ) return ss;
	}
	
	return "No such obj exits";
}
void get_name(string what)
{
	this_body()->modal_pop();
	if( what[0]<0||what[0]>125 ) name = get_english_name(what);
	else name = what;
	if( !OBJ_D->obj_exist(name) ){
		this_object()->targetted_action("$N疑惑的对$T道：你确定有这种物品？\n", this_body());
		who = "";
		remove_call_out("no_answer");
	} else {
		write("包打听听了「嘿嘿」一笑：这我当然知道，只是这个。。。这个。。。\n");
		write("包打听望了你一眼，没有说下去。\n");
		this_body()->modal_push((: get_respond :),"请输入对策：1、给钱，0、放弃。" );
	}	
}
void get_respond(string what)
{
	int i;
	mixed ret;
	string maker, area, *rooms;

	this_body()->modal_pop();
	who = "";
	i = 10 + random(40);
	remove_call_out("no_answer");
	if( what == "0" ){
		this_body()->targetted_action("$N犹豫了一下，对$T说：实在不好意思，小可最近手头比较紧。\n", this_object());
		this_object()->targetted_action("$N「哼」了一声，一脸不满的样子：那你自己慢慢找吧，别烦我。\n", this_body());
	} else if( this_body()->query_all_con_money()<(i*100) ) {
		this_object()->responda("heng");
		this_object()->targetted_action("$N对恶狠狠的道：穷光蛋，一边去。\n", this_body());
	} else {
		this_body()->targetted_action("$N满脸堆笑，连忙把一个早已准备好的红包放进包打听的怀里。\n", this_object());
		this_body()->set_all_con_money(this_body()->query_all_con_money()-i*100);
		this_body()->targetted_action("$N给了$T"+chinese_number(i)+"两银子。\n", this_object());
		ret = OBJ_D->get_obj_maker(name);
		if( !arrayp(ret)||!sizeof(ret) )
			this_object()->targetted_action("$N对$T叹道：此物只应天上有，人间那得几会闻！\n", this_body());
		else {
			maker = ret[random(sizeof(ret))];
			area = CHAR_D->get_char(maker, "room");
			rooms = explode(area,"/");
			area = rooms[sizeof(rooms)-2];
/*			if( wizardp(this_body()) ){
				write("make found is "+maker+"\n");
				write("room is "+CHAR_D->get_char(maker, "room")+"\n");
				write("area is "+area+"\n");
			}
*/	
			write("包打听两眼马上放光了：好！就告诉你吧，"+OBJ_D->get_obj(name,"name")+"在"+AREA_D->get_area(area,"zhou")+"一带可以买到。\n");
		}
	}
}
void answer_skills(object ob)
{
	string msg  = "";
	string *sks = ({"qibing", "scout", "shidu", "jiedu", "fakeorder","sugong" });
	
	foreach(string s in sks) msg+=SG_SKILL_D->query_name(s)+"("+s+")，\n";
	this_object()->targetted_action("$N对$T大笑了几声道：老朽不才，但对\n"+msg+"诸计颇有些心得！\n",ob);
	ob->modal_push((: check_skills, sks:), "你对那一种计谋感兴趣呢？");
}
void check_skills(string *sks, string ans)
{
	int level;

	this_body()->modal_pop();
	if( !ans||ans==""||!stringp(ans)||member_array(ans,SG_SKILL_D->query_skills())==-1 )
		write("没有这种计谋！\n");
	else if( member_array(ans, sks)==-1 )
		write(this_object()->short()+"不会这种计谋！\n");
	else if( !(level=this_body()->query_sk_level(ans)) )
		write("你并不会这种计谋！\n");
	else if( level>=100 )
		write("已经没有人可以教你了！\n");
	else {
		this_body()->modal_push((: do_learn, ans, level:),
			"\n花费"+chinese_number((level+1)*2+1)+"两金学习吗？\n决定了的话请输入yes。");
	}
}
void do_learn(string sk, int lvl, string ans)
{
	int money;
	mixed tmp;
	object who;
	
	this_body()->modal_pop();
	this_body()->start_busy(5, "你正忙着学习呢！\n");
	who=this_body();
	money=((lvl+1)*2+1)*10000;

	if( !ans||!stringp(ans)||ans!="yes" )
		write("不想学，算了！\n");
	else if( (this_body()->query_all_con_money())<money )
		write("你那有哪么多钱！\n");
	else if( (tmp=LEARNCHECK_D->check_can_learn_skills(sk, lvl+10))==TOO_TIRED )
		this_object()->targetted_action("$N对$T笑道：“你太累了！\n",who);
	else if( tmp==LESS_LITERATE )
		this_object()->targetted_action("$N对$T道：你的文学修养不够，有些道理听不明白的。\n",who);
	else if( tmp==LESS_EXP )
		this_object()->targetted_action("$N对$T笑到：“经验不够，只怕神仙也教不会你呀。”\n",who);
	else if( tmp==15 )
		this_object()->targetted_action("$N对$T笑到：你学了太多种计谋了！\n", who);
	else {
		who->set_all_con_money(who->query_all_con_money()-money);
		who->responda("ok");
	}
}

