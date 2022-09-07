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

        set_name("bao dating", HIY+"���˵�����"+NOR+"������");
	add_id("bao");
        set_gender(1);
        set_age(50);
        set_proper_name(HIY+"���˵�����"+NOR+"������(bao dating)");
        set_in_room_desc(HIY+"���˵�����"+NOR+"������(bao dating)");

        add_question("something", "something");
        add_ask_str("something","$N��$T����һ�Ϲ�����С������һ��������಻֪�δ��ɵã�������ָ�̡�\n");
	add_question("skills", "skills");
        add_ask_str("skills","$N��$T�����ʵ�����֪�����кϱ��죿\n");

	call_out("my_heart",1);
}
mixed special_answer(object ob, string str)
{
	if( who&&stringp(who)&&who!="" ) 
		return this_object()->targetted_action("$N��$T�������Եȣ�\n",ob);
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
	this_object()->targetted_action("$N����˹���ض�$T˵����Ҫ��ʲô����ѽ��\n", ob);
        ob->modal_push((: get_name :),"Ҫ��ʲô����");
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
		this_object()->targetted_action("$N�ɻ�Ķ�$T������ȷ����������Ʒ��\n", this_body());
		who = "";
		remove_call_out("no_answer");
	} else {
		write("���������ˡ��ٺ١�һЦ�����ҵ�Ȼ֪����ֻ��������������������\n");
		write("������������һ�ۣ�û��˵��ȥ��\n");
		this_body()->modal_push((: get_respond :),"������Բߣ�1����Ǯ��0��������" );
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
		this_body()->targetted_action("$N��ԥ��һ�£���$T˵��ʵ�ڲ�����˼��С�������ͷ�ȽϽ���\n", this_object());
		this_object()->targetted_action("$N���ߡ���һ����һ�����������ӣ������Լ������Ұɣ����ҡ�\n", this_body());
	} else if( this_body()->query_all_con_money()<(i*100) ) {
		this_object()->responda("heng");
		this_object()->targetted_action("$N�Զ�ݺݵĵ�����⵰��һ��ȥ��\n", this_body());
	} else {
		this_body()->targetted_action("$N������Ц����æ��һ������׼���õĺ���Ž��������Ļ��\n", this_object());
		this_body()->set_all_con_money(this_body()->query_all_con_money()-i*100);
		this_body()->targetted_action("$N����$T"+chinese_number(i)+"�����ӡ�\n", this_object());
		ret = OBJ_D->get_obj_maker(name);
		if( !arrayp(ret)||!sizeof(ret) )
			this_object()->targetted_action("$N��$T̾��������ֻӦ�����У��˼��ǵü����ţ�\n", this_body());
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
			write("�������������ϷŹ��ˣ��ã��͸�����ɣ�"+OBJ_D->get_obj(name,"name")+"��"+AREA_D->get_area(area,"zhou")+"һ�������򵽡�\n");
		}
	}
}
void answer_skills(object ob)
{
	string msg  = "";
	string *sks = ({"qibing", "scout", "shidu", "jiedu", "fakeorder","sugong" });
	
	foreach(string s in sks) msg+=SG_SKILL_D->query_name(s)+"("+s+")��\n";
	this_object()->targetted_action("$N��$T��Ц�˼����������಻�ţ�����\n"+msg+"�������Щ�ĵã�\n",ob);
	ob->modal_push((: check_skills, sks:), "�����һ�ּ�ı����Ȥ�أ�");
}
void check_skills(string *sks, string ans)
{
	int level;

	this_body()->modal_pop();
	if( !ans||ans==""||!stringp(ans)||member_array(ans,SG_SKILL_D->query_skills())==-1 )
		write("û�����ּ�ı��\n");
	else if( member_array(ans, sks)==-1 )
		write(this_object()->short()+"�������ּ�ı��\n");
	else if( !(level=this_body()->query_sk_level(ans)) )
		write("�㲢�������ּ�ı��\n");
	else if( level>=100 )
		write("�Ѿ�û���˿��Խ����ˣ�\n");
	else {
		this_body()->modal_push((: do_learn, ans, level:),
			"\n����"+chinese_number((level+1)*2+1)+"����ѧϰ��\n�����˵Ļ�������yes��");
	}
}
void do_learn(string sk, int lvl, string ans)
{
	int money;
	mixed tmp;
	object who;
	
	this_body()->modal_pop();
	this_body()->start_busy(5, "����æ��ѧϰ�أ�\n");
	who=this_body();
	money=((lvl+1)*2+1)*10000;

	if( !ans||!stringp(ans)||ans!="yes" )
		write("����ѧ�����ˣ�\n");
	else if( (this_body()->query_all_con_money())<money )
		write("��������ô��Ǯ��\n");
	else if( (tmp=LEARNCHECK_D->check_can_learn_skills(sk, lvl+10))==TOO_TIRED )
		this_object()->targetted_action("$N��$TЦ��������̫���ˣ�\n",who);
	else if( tmp==LESS_LITERATE )
		this_object()->targetted_action("$N��$T���������ѧ������������Щ�����������׵ġ�\n",who);
	else if( tmp==LESS_EXP )
		this_object()->targetted_action("$N��$TЦ���������鲻����ֻ������Ҳ�̲�����ѽ����\n",who);
	else if( tmp==15 )
		this_object()->targetted_action("$N��$TЦ������ѧ��̫���ּ�ı�ˣ�\n", who);
	else {
		who->set_all_con_money(who->query_all_con_money()-money);
		who->responda("ok");
	}
}

