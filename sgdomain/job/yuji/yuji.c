#include <ansi.h>
#define YU_TOOL __DIR__"yu_tool.c"

inherit LIVING;
inherit M_CHAR;
inherit "/sgdomain/modules/m_charnpc/xianren/xianren_act";
inherit M_SMARTMOVE; // so it can move

int check_job(object who);
int check_cancel(object who);
int do_award(object who);
void do_learn(string sk, int lvl, string ans);
void answer_skills(object ob);
void check_skills(string *sks, string ans);

void setup()
{
        object cloth;
        cloth = new("/sgdomain/obj/cloth/torso/hechang.c");
        cloth->move(this_object());
        cloth->do_wear();

        set_name("yu ji", HIY+"���˵�����"+NOR+"�ڼ�");
        add_id("yuji");
        set_gender(1);
        set_age(72);
	set_proper_name(HIY+"���˵�����"+NOR+"�ڼ�(yu ji)");
        set_in_room_desc(HIY+"���˵�����"+NOR+"�ڼ�(yu ji)");

        add_question("job", "job");
        add_ask_str("job", "$N��$T�����ʵ������������зԸ���\n");
        add_question("cancel", "cancel");
	add_ask_str("cancel","$N�������Ķ�$T������������ʵ����̫�ѡ�������\n");
	add_question("skills", "skills");
        add_ask_str("skills","$N��$T�����ʵ�����֪�����кϱ��죿\n");
      	clear_chat(); // clear default chat
        add_chat("���������£�����������Ҳ��");
        add_chat("����֮���㣬��һľ��֧Ҳ��");
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
	object tool;
	string area, *areas, room, *rooms, memo;

	job = who->query_job("yu ji", "");
        if( job || mapp(job) ){
                if( job["beg_time"] > 0 ){
			this_object()->targetted_action("$N�����Ķ�$T����һ�����ϴεĻû�����أ�\n", who);
                        return 0;
                }
                if( sizeof(job["lasttimes"]) > 20 ){
			this_object()->targetted_action("$N������Ц��˵��$RӦ����Ϣһ������\n",who);
                        return 0;
                }
        }
	
        who->resign_job("yu ji");
        who->add_job("yu ji");
        tool = new(YU_TOOL);
        tool->move(who);
	tool->set_in_room_desc("һ��ϸ�̵��������������ż���С�֣��ڼ���"+CHAR_D->get_char(who->query_id()[1], "name"));

	areas = AREA_D->list_areas();
	area  = areas[random(sizeof(areas))];
	rooms = AREA(area)->get_room("list");
	room  = rooms[random(sizeof(rooms))];
	memo  = AREA_D->get_area(area, "name")+"֮"+AREA(area)->get_room(room,"b");

	who->set_job("yu ji", "job_type", "place");
	who->set_job("yu ji", "job_para", "/a/"+area+"/"+room);
	who->set_job("yu ji", "memo", memo);
	who->set_job("yu ji", "num", 1);
	who->set_job("yu ji", "stage", "start");

	this_object()->targetted_action("$N����$T�����һЦ���ðɣ��������е�С��Ҫ���°�æ��\n", who);
	this_object()->targetted_action("$N�ݸ�$Tһ��"+tool->short()+"��\n", who);
	this_object()->targetted_action("$N��$T���������㵽"+memo+"��һ�˰ɣ�\n", who);

	return 1;
}
int check_cancel(object who)
{
        mapping job;

        job = who->query_job("yu ji", "");
        if( !job || !mapp(job) )
		this_object()->targetted_action("$N��$T���ȵ�˵�����´�δҪ������ʲô�ɣ�\n",who);
        else if(  job["beg_time"] <= 0 )
		this_object()->targetted_action("$N��$T���ȵ�˵�����������Ѿ�����ˣ�\n",who);
        else if( time() - job["beg_time"] < 1800 )
		this_object()->targetted_action("$N��$T������˵���Ⱥú÷�ʡһ���������Ұɡ�\n", who);
        else {
                this_object()->responda("sigh2");
		this_object()->targetted_action("$N��$T������˵�����С��Ҳ�첻�ã�\n",who);
                who->finish_job("yu ji");
        }

        return 1;
}
mixed indirect_give_obj_to_liv(object ob, object liv)
{
        string name;
        object who;
	mapping job;

	who  = this_body();
        name = who->query_id()[0];
	job  = who->query_job("yu ji", "");
	
	if( job["beg_time"] <= 0 ){
		destruct(ob);
                return this_object()->short()+"���˵�ͷ��\n";
	};
        if( ob->query(who->query_id()[0]) == "ok" ){
                this_object()->responda("admire");
                this_object()->responda("handshake");
                who->finish_job("yu ji");
                who->set_job("yu ji", "place", ({ }));
		who->tegetted_action("$N���ĵİ�һ��������ݸ�$T�������������������������ˡ�\n", this_object());
                this_object()->tegetted_action("$N����$T�ļ����������ģ�\n",who);
		ROBOT->robot_test(who, (: do_award :) );
		destruct(ob);
		return this_object()->short()+"��������Ц��������\n";
        } else {
		destruct(ob);
                return this_object()->short()+"��������ʲô������\n";
        }
}
int do_award(object who)
{
	int gold, rep, point;
	string name, *sks, skill;

	name = who->query_id()[0];
	if( who->query_robot() ){
		write("��Ǹ������Ĵ𰸣�û���κν������´���Ŭ���ɣ�\n");
                return 2;
        } else {
		sks  = keys(who->get_sg_skills());
                gold = 40000+random(30000);
		rep  = 100+random(50);
               	CHAR_D->set_char(name, "reputation",
                        CHAR_D->get_char(name, "reputation")+rep);
                who->set_all_con_money(who->query_all_con_money()+gold);
		write("�㱻������"+chinese_number(gold/100)+"��������\n");
        	write("������������"+chinese_number(rep)+"��\n");
		if( !sks||!arrayp(sks)||!sizeof(sks) ) return 1;
        	sks = filter_array(sks, (: SG_SKILL_D->query_type($1)==4 :));
        	if( !sks||!arrayp(sks)||!sizeof(sks) ) return 1;
        	skill = sks[random(sizeof(sks))];
        	point = who->query_job("yu ji", "count");
		if( point>200 ) point = 200;
        	point = point + 50 + random(50);
		who->award_exp(point ,skill);
        	write("���%^H_CYAN%^"+SG_SKILL_D->query_name(skill)+"%^RESET%^�����"
                	+chinese_number(point)+"�㣡\n");
	}
	return 1;
}
void answer_skills(object ob)
{
	string msg  = "";
	string *sks = ({"maifu", "fenfa", "luanshe", "qibing" });
	
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
