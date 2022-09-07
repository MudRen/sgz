// flee@sgz April 12 1999
//
// modified at: October 06, 2001
//      by xiaobai: bugfixed
//          ԭ���Ĺ���12����ͷ��zuoci ������Ϊ��ҵ���Ĺ��������ˡ�
//          ԭ�򣺼�鹤����Ŀǰ��û�а�ʱ�����

#include <ansi.h>

// #define _DEBUG_ID   "xiaobai"

#define ZUO_TOOL __DIR__"zuo_tool.c"

#define MAX_COUNT   20  // ���칤������������
#define JOB_ID      "zuo ci" // ������ id

inherit LIVING;
inherit M_CHAR;

inherit "/sgdomain/modules/m_charnpc/xianren/xianren_act";
inherit M_SMARTMOVE; // so it can move

int check_job(object who);
int check_cancel(object who);

void do_learn(string sk, int lvl, string ans);
void answer_skills(object ob);
void check_skills(string *sks, string ans);

void setup()
{
        object cloth;
        cloth = new("/sgdomain/obj/cloth/torso/hechang.c");
        cloth->move(this_object());
        cloth->do_wear();

        set_name("zuo ci", "���");
        add_id("zuoci");
        set_gender(1);
        set_age(65);
        set_proper_name(HIY+"���˵�����"+NOR+"���(zuo ci)");
        set_in_room_desc(HIY+"���˵�����"+NOR+"���(zuo ci)");

        add_question("job", "job");
        add_ask_str("job", "$N��$T�����ʵ������������зԸ���\n");
        add_question("cancel", "cancel");
        add_ask_str("cancel","$N�������Ķ�$T������������ʵ����̫�ѡ�������\n");
	    add_question("skills", "skills");
        add_ask_str("skills","$N��$T�����ʵ�����֪�����кϱ��죿\n");
      	clear_chat(); // clear default chat
        add_chat("�ѵö���ʧ��ʱҲ��ʱ�����������߻�Ҳ��");
        add_chat("���ǲ���Σ�Խ��ң���������Σ��Ϊ�������ް���Σ��������");
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
        string area, room, *areas, *rooms, area1;
        int nDoneJobNum = 0;   // ���������Ĵ���

        job = who->query_job("zuo ci", "");
        if( job || mapp(job) )
        {
            if( job["beg_time"] > 0 )
            {
                    this_object()->targetted_action("$N�����Ķ�$T����һ�����ϴεĻû�����أ�\n", who);
                        return 0;
            }
// xiaobai
/* xiaobai: 06102001, ע�⣬ԭ������ֱ�Ӷ� job["lasttimes"]������ֵ��û�и��µģ�ʱЧ�ѹ�    
          	if( sizeof(job["lasttimes"]) > 20 )
*/
            // ��ȡ���ڵ��ѹ�������
          	nDoneJobNum = who->query_job( JOB_ID, "count_lasttimes" );
          	if( nDoneJobNum > MAX_COUNT )
            {
                 	this_object()->targetted_action("$N������Ц��˵��$RӦ����Ϣһ������\n",who);
                 	return 0;
           	}
           	
//// xiaobai

     	}

        who->resign_job("zuo ci");
        who->add_job("zuo ci");
        tool = new(ZUO_TOOL);
        tool->move(who);

        this_object()->responda("ah");
        this_object()->targetted_action("$N�������صĶ�$T˵��������´��ң���֪�εػ���������Ӱ���\n", who);
        this_object()->targetted_action("$N���ĵ�����$Tһֻ������Ƶ�����ͭ����\n", who);
        this_object()->targetted_action("$N������$T����ȥ������������֮����ʢ��\n", who);

        areas = AREA_D->list_areas();
        areas = areas - ({"huayin"});
        area = areas[random(sizeof(areas))];

        rooms = AREA(area)->get_room("list");
        room = rooms[random(sizeof(rooms))];

        who->set_job("zuo ci", "area", area);
        who->set_job("zuo ci", "room", room);
        
        areas = AREA_D->get_area(area, "neighbor");
        areas = areas + ({ area });
        area1 = areas[random(sizeof(areas))];
        this_object()->targetted_action("$N������$T������"+AREA_D->get_area(area1,"name")+
		"������"+AREA_D->get_area(area,"zhou")+"һ��ȥ�����ɣ�Ҳ����з��֡�\n",who);
        who->set_job("zuo ci","memo", AREA_D->get_area(area1,"name")+
		"("+AREA_D->get_area(area,"zhou")+")");

        return 1;
}
int check_cancel(object who)
{
        mapping job;

        job = who->query_job("zuo ci", "");
        if( !job || !mapp(job) )
                this_object()->targetted_action("$N��$T���ȵ�˵�����´�δҪ������ʲô�ɣ�\n",who);
        else if(  job["beg_time"] <= 0 )
                this_object()->targetted_action("$N��$T���ȵ�˵�����������Ѿ�����ˣ�\n",who);
        else if( time() - job["beg_time"] < 1800 )
                this_object()->targetted_action("$N��$T������˵���Ⱥú÷�ʡһ���������Ұɡ�\n", who);
        else {
                this_object()->responda("sigh2");
                this_object()->targetted_action("$N��$T������˵�����С��Ҳ�첻�ã�\n",who);
                who->finish_job("zuo ci");
        }

        return 1;
}
void answer_skills(object ob)
{
	string msg  = "";
string *sks = ({"neihong", "scout", "huangbao","jbsj","luoshi","jbhj"});
	
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
