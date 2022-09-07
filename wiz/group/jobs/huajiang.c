// accountant 花匠
#include <ansi.h>
#include <mudlib.h>
#define JOBID "waterflower"
#define BOTTLE "/sgdomain/job/waterflower/bottle.c"
#define S_ROOM "/sgdomain/area/cities/luoyang/ly_mdhp.c"
#define BOWL "/sgdomain/job/waterflower/bowl.c"
inherit LIVING;
object room;
string employee;
int starttime;
void ask_job(object usr);
void setup()
{
   object jia;
   jia=new(PTORSO+"choup");
   jia->move(this_object());
   jia->do_wear();
   set_name("hua jiang", "花匠");
   set_in_room_desc("花匠(hua jiang)");
   set_long(
       "ask hua jiang about job。\n");
   set_gender(1);
   set_age(50);
   set_sg_rongmao(-1);
   employee="";
   starttime=0;
   add_question("job", "job");
   add_ask_str("job","$N向$T道：有什么花可种吗？\n");
}
mixed special_answer(object ob, string str)
{
   object player;
   player = this_body();
   switch(str)
   {
      case "job":
          ask_job(player);
          return;
      default:
         return ;
    }
}
void award(object usr)
{
    int isrobot, i;
    string n_id;	
    object ob, bowl, room;
    object *obs;
    object player;

    player = this_body();	
    n_id=usr->query_id()[0];	
    isrobot=usr->query_robot();
    if(isrobot)
    {   this_object()->simple_action(
         "$N道：对不起，傻瓜不可以种花。\n");
    }
    else
    {
        this_object()->simple_action("$N说到：不错，不错．\n");
        this_object()->simple_action("$N说道：你去做吧。\n",usr);
	obs = all_inventory( player );
        for( i = 0; i < sizeof( obs ); i++){
        if( obs[i]->can_turn()){
        employee = n_id;
        room=load_object(S_ROOM);
	bowl = new(BOWL);
        bowl->move(room);
        usr->resign_job(JOBID);
        usr->add_job(JOBID);
        return;}
	}

	this_object()->targetted_action("$N给$T一只水壶。\n",usr);
	ob=new(BOTTLE);
        ob->move(usr);
    	employee = n_id;
	room=load_object(S_ROOM);
        bowl = new(BOWL);
        bowl->move(room);
        usr->resign_job(JOBID);
        usr->add_job(JOBID);
	}
}

void ask_job(object usr)
{
    object bowl, bowl1, room;
    string n_id;
    int n_lasttimes,m_lasttimes;
    int p_s;
    n_id=usr->query_id()[0];
    if (employee==n_id)
    {
        this_object()->targetted_action(
         "$N对$T道：活儿已经安排给你了，还不去做？\n",usr);
        return;
    }
    if(employee!="") // some body working
    {
        object e;
        e=find_body(employee);
        if(objectp(e)) // this guy still on line
        {
                this_object()->targetted_action(
                 "$N对$T道：活儿现在有人做，待会儿再来吧。\n",usr);
                return;
         }
    }	
    n_lasttimes=usr->query_job(JOBID,"count_lasttimes");
    m_lasttimes=JOB_D->get_job(JOBID,"count_lasttimes");
    m_lasttimes=15; // because job_d not finished
    if(n_lasttimes>m_lasttimes)
    {
      this_object()->targetted_action(
          "$N对$T道：你今天干的活够多的了，该休息休息了。\n",usr);
        return;
    }
	room=load_object(S_ROOM);
	if (bowl1=present("bowl", room ))
	destruct(bowl1);
	this_object()->targetted_action(
"$N对$T道：我要给你一道题,看你聪明不聪明。\n",usr);
	ROBOT->robot_test(usr,(:award:));
}

void employ()
{
	employee="";
}

