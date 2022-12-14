// flee@sgz April 12 1999
//
// modified at: October 06, 2001
//      by xiaobai: bugfixed
//          原来的过了12个钟头后，zuoci 还是认为玩家当天的工作做够了。
//          原因：检查工作数目前，没有按时间更新

#include <ansi.h>

// #define _DEBUG_ID   "xiaobai"

#define ZUO_TOOL __DIR__"zuo_tool.c"

#define MAX_COUNT   20  // 当天工作次数的限制
#define JOB_ID      "zuo ci" // 本工作 id

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

        set_name("zuo ci", "左慈");
        add_id("zuoci");
        set_gender(1);
        set_age(65);
        set_proper_name(HIY+"流浪的仙人"+NOR+"左慈(zuo ci)");
        set_in_room_desc(HIY+"流浪的仙人"+NOR+"左慈(zuo ci)");

        add_question("job", "job");
        add_ask_str("job", "$N向$T躬身问道：先生，可有吩咐？\n");
        add_question("cancel", "cancel");
        add_ask_str("cancel","$N满脸赤红的对$T道：先生任务实在是太难。。。。\n");
	    add_question("skills", "skills");
        add_ask_str("skills","$N向$T躬身问道：不知先生有合本领？\n");
      	clear_chat(); // clear default chat
        add_chat("难得而易失者时也，时至而不旋踵者机也。");
        add_chat("上智不处危以侥幸，中智能因危以为功，下愚安于危以自亡。");
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
        int nDoneJobNum = 0;   // 本天已做的次数

        job = who->query_job("zuo ci", "");
        if( job || mapp(job) )
        {
            if( job["beg_time"] > 0 )
            {
                    this_object()->targetted_action("$N生气的对$T哼了一声：上次的活还没干完呢！\n", who);
                        return 0;
            }
// xiaobai
/* xiaobai: 06102001, 注意，原来这里直接读 job["lasttimes"]，其数值是没有更新的，时效已过    
          	if( sizeof(job["lasttimes"]) > 20 )
*/
            // 获取现在的已工作次数
          	nDoneJobNum = who->query_job( JOB_ID, "count_lasttimes" );
          	if( nDoneJobNum > MAX_COUNT )
            {
                 	this_object()->targetted_action("$N满脸堆笑的说：$R应该休息一会啦。\n",who);
                 	return 0;
           	}
           	
//// xiaobai

     	}

        who->resign_job("zuo ci");
        who->add_job("zuo ci");
        tool = new(ZUO_TOOL);
        tool->move(who);

        this_object()->responda("ah");
        this_object()->targetted_action("$N神神秘秘的对$T说：如今天下大乱，不知何地会出真命天子啊？\n", who);
        this_object()->targetted_action("$N悄悄的塞给$T一只左慈特制的阴阳铜镜。\n", who);
        this_object()->targetted_action("$N悄声对$T道：去找找哪里龙虎之气最盛。\n", who);

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
        this_object()->targetted_action("$N悄声对$T道：到"+AREA_D->get_area(area1,"name")+
		"附近，"+AREA_D->get_area(area,"zhou")+"一带去看看吧，也许会有发现。\n",who);
        who->set_job("zuo ci","memo", AREA_D->get_area(area1,"name")+
		"("+AREA_D->get_area(area,"zhou")+")");

        return 1;
}
int check_cancel(object who)
{
        mapping job;

        job = who->query_job("zuo ci", "");
        if( !job || !mapp(job) )
                this_object()->targetted_action("$N对$T惊讶的说：在下从未要您做过什么吧？\n",who);
        else if(  job["beg_time"] <= 0 )
                this_object()->targetted_action("$N对$T惊讶的说：您的任务已经完成了！\n",who);
        else if( time() - job["beg_time"] < 1800 )
                this_object()->targetted_action("$N对$T生气的说：先好好反省一会再来见我吧。\n", who);
        else {
                this_object()->responda("sigh2");
                this_object()->targetted_action("$N对$T生气的说：这点小事也办不好！\n",who);
                who->finish_job("zuo ci");
        }

        return 1;
}
void answer_skills(object ob)
{
	string msg  = "";
string *sks = ({"neihong", "scout", "huangbao","jbsj","luoshi","jbhj"});
	
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
