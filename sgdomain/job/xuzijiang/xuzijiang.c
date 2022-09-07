#include <mudlib.h>
#include <ansi.h>

#define XIANREN __DIR__"xianren.c"

inherit LIVING;
inherit M_CHAR;
inherit "/sgdomain/modules/m_charnpc/xianren/xianren_act";
inherit M_SMARTMOVE; // so it can move

int check_job(object who);
int check_cancel(object who);
void check_ob();
void do_learn(string sk, int lvl, string ans);
void answer_skills(object ob);
void check_skills(string *sks, string ans);

void setup()
{
	object cloth;
	cloth = new("/sgdomain/obj/cloth/torso/hechang.c");
        cloth->move(this_object());
	cloth->do_wear();
	set_name("xu zijiang", "����");
	add_id("xu");
	set_gender(1);
	set_age(80);
	set_proper_name(HIY+"���˵�����"+NOR+"����(xu zijiang)");
	set_in_room_desc(HIY+"���˵�����"+NOR+"����(xu zijiang)");
	add_question("job", "job");
	add_ask_str("job", "$N��$T�����ʵ������������зԸ���\n");
	add_question("cancel", "cancel");
	add_ask_str("cancel","$N�������Ķ�$T������������ʵ����̫�ѡ�������\n");
	add_question("skills", "skills");
        add_ask_str("skills","$N��$T�����ʵ�����֪�����кϱ��죿\n");
      	clear_chat(); // clear default chat
        add_chat("��Ԩ���㣬�����˶�����Ҳ��");
        add_chat("�������ۣ������Ѵݡ�¾��һ�ģ������ɹ�Ҳ��");
	call_out("check_ob", 60);
	call_out("my_heart",1); // begin my heart
}
mixed special_answer(object ob, string str)
{	
	if( str == "job" ) check_job( ob );
	else if( str == "cancel" ) check_cancel( ob );
	else if( str == "skills" ) answer_skills( ob );
	else return ::special_answer(ob, str);
}
int check_job(object who)
{
	mapping job;
	object xianren;

	job = who->query_job("xu zijiang", "");
	if( job || mapp(job) ){
		if( job["beg_time"] > 0 ){
			this_object()->targetted_action("$N�����Ķ�$T����һ�����ϴεĻû�����أ�\n", who); 
			return 0;
		}
		if( sizeof(job["lasttimes"])>20 ){
			this_object()->targetted_action("$N������Ц��˵��$RӦ����Ϣһ������\n",who);
			return 0;
		}
	}

	who->resign_job("xu zijiang");
	who->add_job("xu zijiang");

	xianren = new(XIANREN);
	xianren->move(environment(this_object()));
	xianren->set_leader(who->query_id()[0]);
	xianren->set_in_room_desc(who->query_id()[1]+"����������λ���˵���������");

	this_object()->responda("nod");
	this_object()->simple_action("$N�������������λ���˵������߰ɡ�\n");
	xianren->simple_action("$N�����ڵ����˳�����\n");
	xianren->do_consider();
	return 1;
}
void check_ob()
{
	object *obs;

	obs = children("/sgdomain/job/xuzijiang/xianren.c");
	remove_call_out("check_ob");
	foreach(object oo in obs){
		if( oo->query_leader() ) oo->do_consider();
	}
	call_out("check_ob", 60);
}
int check_cancel(object who)
{
	mapping job;

	job = who->query_job("xu zijiang", "");

	if( !job || !mapp(job) )
		this_object()->targetted_action("$N��$T���ȵ�˵�����´�δҪ������ʲô�ɣ�",who);
	else if(  job["beg_time"] <= 0 )
		this_object()->targetted_action("$N��$T���ȵ�˵�����������Ѿ�����ˣ�\n",who);
	else if( time() - job["beg_time"] < 1800 )
		this_object()->targetted_action("$N��$T������˵���Ⱥú÷�ʡһ���������Ұɡ�\n", who);
	else {
		this_object()->responda("sigh2");
		this_object()->targetted_action("$N��$T������˵�����С��Ҳ�첻�ã�\n", who);
		who->finish_job("xu zijiang");
	}

	return 1;
}
void answer_skills(object ob)
{
	string msg  = "";
	string *sks = ({"hunluan", "shoushi", "tianbian", "fengbian","zhanbu" });
	
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
