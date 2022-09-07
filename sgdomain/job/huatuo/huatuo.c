#include <mudlib.h>
#include <ansi.h>
#define HUA_TOOL __DIR__"hua_tool.c"

// this is used to make the char active
inherit "/sgdomain/modules/m_charnpc/xianren/xianren_act";
inherit LIVING;
inherit M_CHAR;
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

	set_name("hua tuo", "����");
	add_id("huatuo");
	set_gender(1);
	set_age(60);
	set_proper_name(HIY+"���˵�����"+NOR+"����(hua tuo)");
        set_in_room_desc(HIY+"���˵�����"+NOR+"����(hua tuo)");
	add_question("job", "job");
        add_ask_str("job", "$N��$T�����ʵ������������зԸ���\n");
	add_question("cancel", "cancel");
	add_ask_str("cancel","$N�������Ķ�$T������������ʵ����̫�ѡ�������\n");
	add_question("skills", "skills");
	add_ask_str("skills","$N��$T�����ʵ�����֪�����кϱ��죿\n");
   	clear_say(); // clear the default say
      	add_say("˭Ҫ���ܰ�����Щ��ҩ�ͺ��ˡ�\n"); // add say, can add more
      	clear_chat(); // clear default chat
        add_chat("�ܲ٣��鳼Ҳ���������£����ó��٣�");
      	add_chat("���߷�����δ�ȣ�����ͼ���ڽ�����");
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
	int i, j;
	mapping job;
        object tool;
	string area, *areas, *color, *taste;

	color = ({"��ɫ", "��ɫ", "��ɫ", "��ɫ", "��ɫ", "��ɫ", "��ɫ", });
	taste = ({"��ζ", "��ζ", "��ζ", "��ζ", "��ζ", "ɬζ", "��ζ", });
	job = who->query_job("hua tuo", "");
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

	who->resign_job("hua tuo");
        who->add_job("hua tuo");
	tool = new(HUA_TOOL);
	tool->move(who);
	this_object()->targetted_action("$N��$T���˵�ͷ���������ã�ȥ�����ҵ��ҩ�ɡ�\n", who);
	this_object()->targetted_action("$N�ݸ�$Tһ��Сҩ����\n", who);

	i = random(sizeof(color));
	j = random(sizeof(taste));
	who->set_job("hua tuo", "color", i);
	who->set_job("hua tuo", "taste", j);

	areas = AREA_D->list_areas();
	area = areas[random(sizeof(areas))];
	this_object()->simple_action("$N��������ҩ����"+color[i]+taste[j]+"�ģ���Ҫ����ϸ�ˡ�\n");
	this_object()->simple_action("$N����ȥ"+AREA_D->get_area(area, "name")+"һ�����Ұɡ�\n");
        who->set_job("hua tuo", "memo", color[i]+taste[j]+"��ҩ��("+AREA_D->get_area(area, "name")+")");
	who->set_job("hua tuo", "area", area);

	return 1;
}
mixed indirect_give_obj_to_liv(object ob, object liv)
{
	string name;
	object who;
	mapping job;

	who  = this_body();
	name = who->query_id()[0];
	job  = who->query_job("hua tuo", "");

	if( job["beg_time"] <= 0 ){
		destruct(ob);
		return this_object()->short()+"���ĵص�л��\n";
	};
	if( ob->query(who->query_id()[0]) == "ok" ){ 
		this_object()->responda("admire");
		who->finish_job("hua tuo");
		who->set_job("hua tuo", "place", ({ }));
                destruct(ob);
		ROBOT->robot_test(who, (: do_award :) );
		return this_object()->short()+"���ĵص�л��\n";
	} else {
		destruct(ob);
		responda("heng");
		return this_object()->short()+"��������ʲô������\n";
	}

}
int do_award(object who)
{
	int rep, gold, point;
	string name, *sks, skill;

	name = who->query_primary_id();
	rep  = 50+random(50);
	gold = 10000+random(15000);	
	sks  = keys(who->get_sg_skills());
	if( who->query_robot() ){
		write("��Ǹ������Ĵ𰸣�û���κν������´���Ŭ���ɣ�\n");
                return 2;
        } else {
		this_object()->tegetted_action("$N����$T�ļ����������ģ�\n", who);
                CHAR_D->set_char(name, "reputation",
                        CHAR_D->get_char(name,"reputation")+rep);
                who->set_all_con_money(who->query_all_con_money()+gold);
		write("�㱻������"+chinese_number(gold/100)+"��������\n");
        	write("������������"+chinese_number(rep)+"��\n");
		if( !sks||!arrayp(sks)||!sizeof(sks) ) return 1;
        	sks = filter_array(sks, (: SG_SKILL_D->query_type($1)==4 :));
        	if( !sks||!arrayp(sks)||!sizeof(sks) ) return 1;
        	skill = sks[random(sizeof(sks))];
        	point = who->query_job("hua tuo", "count");
        	if( point>200 ) point = 200;
        	point = point + 50 + random(50);

        	who->award_exp(point ,skill);
        	write("���%^H_CYAN%^"+SG_SKILL_D->query_name(skill)+"%^RESET%^�����"
                	+chinese_number(point)+"�㣡\n");
	}
	return 1;
}
int check_cancel(object who)
{
	mapping job;

        job = who->query_job("hua tuo", "");
        if( !job || !mapp(job) )
		this_object()->targetted_action("$N��$T���ȵ�˵�����´�δҪ������ʲô�ɣ�\n",who);
        else if(  job["beg_time"] <= 0 )
		this_object()->targetted_action("$N��$T���ȵ�˵�����������Ѿ�����ˣ�\n",who);
        else if( time() - job["beg_time"] < 1800 )
		this_object()->targetted_action("$N��$T������˵���Ⱥú÷�ʡһ���������Ұɡ�\n", who);
        else {
                this_object()->responda("sigh2");
		this_object()->targetted_action("$N��$T������˵�����С��Ҳ�첻�ã�\n",who);
                who->finish_job("hua tuo");
		who->set_job("hua tuo", "place", ({ }));
        }

        return 1;
}

void answer_skills(object ob)
{
	string msg  = "";
	string *sks = ({"jiaoma", "guwu", "shidu", "jiedu", "chenzhuo", });
	
	foreach(string s in sks) msg+=SG_SKILL_D->query_name(s)+"("+s+")��\n";
	this_object()->targetted_action("$N��$T��Ц�˼����������಻�ţ�����\n"+msg+"�������Щ�ĵã�\n", ob);
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