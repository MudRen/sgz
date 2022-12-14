// ev_job.c
// by fire on January 1999
// this is used to handle give a char a job
#define CANT_OFFER 0
#define KING_OFFER 1  // king to other area officer
#define KINGLEADER_OFFER 2 // king offer area officer
#define LEADER_OFFER 3 // leader to officer
#define SIMPLE_OFFER 4 // leader to unofficer
#define MINRESIGNTIME 7200 // if you don't like this job need at least
                           // this time to resign it
static mapping king_offer=(["zhaoxiang" : "招降它国"]);
static mapping leader_offer=([ "letter" : "送信" , "spy" : "地区侦查",
	"searchwise" : "搜索贤人","visitwise" : "访问贤人",
	"patrol" : "巡逻","visitpeople" : "体察百姓",
	"fanpeople" : "煽动百姓","whisper":"策反敌将",
//	"landlord" : "开发新田",
	"visitofficer" : "安抚官员",
// Add by listen
	"setppl" : "设置间谍"]);
static mapping simple_offer=(["findbody" : "找人","askobj" : "催物",
                              "bugao" : "张贴布告",]);
private mapping jobs;
void confirm_job(object who, object officer);
void myjob(object officer,object who,string ans);
void finish_myjob(object officer, object who, string job);
void my_award(object usr ,mixed para);
void pre_myjob(object officer,object who,string job_name,string ans,string m_area,string file_name);
void pre_award(object usr ,mixed p);
int check_situation(string m_id,string y_id)
{
	string m_area,y_area;
	string m_nation,y_nation;
	int is_king=0;
	m_nation=CHAR_D->get_char(m_id,"nation");
	if(m_nation==m_id) is_king=1;
	m_area=CHAR_D->get_char(m_id,"area");
	y_area=CHAR_D->get_char(y_id,"area");
	y_nation=CHAR_D->get_char(y_id,"nation");
	if(m_area!=y_area)
	{
		if(!is_king) return CANT_OFFER;
		if(m_nation!=y_nation) return CANT_OFFER;
		return KING_OFFER;
	}
	if(m_nation==y_nation)
	{
		if(is_king) return KINGLEADER_OFFER;
		return LEADER_OFFER;
	}
	return SIMPLE_OFFER;
}
mixed suitable_job(string off_id,string work_id) 
{
	int p_check;
	p_check=check_situation(off_id,work_id);
    switch(p_check)
    {
	case CANT_OFFER:
		return 0;
	case KING_OFFER:
		return king_offer;
	case LEADER_OFFER:
		return leader_offer;
	case KINGLEADER_OFFER:
		return leader_offer+king_offer;
	default:
		return simple_offer;
	}
}
void ask_job(object who, object officer)
{
    string m_id,y_id;
    string m_area;
    int p_check;
    m_id=(officer->query_id())[0];
    y_id=(who->query_id())[0];
    m_area=CHAR_D->get_char(m_id,"area");
    if((AREA_D->get_area(m_area,"leader"))!=m_id)
    {
        string m_title;
        m_title=OFFICER_D->query_rank_name(
        (OFFICER_D->query_area_officer_title(
         AREA_D->get_area(m_area,"level"),0,0))[0]);
          officer->targetted_action
         ("$N对$T笑道：$R想找点事干？这个$s可做不了主，得去问本地"+m_title+"。\n",who);
         return;
    }
    //added by suicide in 2001.6.7 for avoiding dummy with low lit to work
    if (CHAR_D->char_exist(y_id)&&(CHAR_D->get_char(y_id,"literate")<30))
    {
    officer->targetted_action
         ("$N对$T笑道：$R大字认不了几个，还是回去进修进修再来，免得误了国家大事！\n",who);
    return;

    }
    //
	if(((file_name(environment(this_body())))!=
((AREA_D->get_area(m_area,"path"))+(AREA_D->get_area(m_area,"meeting"))))||(m_area!=
		environment(this_body())->get_area()))
	{
		officer->targetted_action("$N对$T摇摇头道：这个还是回到会议之所后再说吧。\n",who);
		return;
	}
	p_check=check_situation(m_id,y_id);
    switch(p_check)
    {
	case CANT_OFFER:
		officer->targetted_action
         ("$N对$T摇摇头，道：$R不是长居此地吧？本地事务外人不便插手，如此。。这个。。。\n",who);
		return;
	case KING_OFFER:
		jobs=king_offer;
		break;
	case LEADER_OFFER:
		jobs=leader_offer;
		break;
	case KINGLEADER_OFFER:
		jobs=leader_offer+king_offer;
		break;
	default:
		jobs=simple_offer;
		break;
	}
	if(sizeof(jobs))
	{
		officer->targetted_action
         ("$N对$T点点头，道：$R主动寻职邀功，精神可嘉，精神可嘉呀。\n"+
		 "现有以下工作：\n",who);
         confirm_job(who,officer);
         return;
	}
    officer->targetted_action
    ("$N直摇头：现在连$s都无事可做，唉，真无聊。\n",who);
                    return;
}
void confirm_job(object who, object officer)
{
    string y_id;
    string m_id;
	string p_dis;
	int *list;
	int i;
    m_id=(officer->query_id())[0];
    y_id=(who->query_id())[0];
	jobs=suitable_job(m_id,y_id);
    officer->set_answer(y_id,  (:myjob:) );
	list=keys(jobs);
	p_dis="〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n"+
		  "工作代号    工作名称    工作代号    工作名称\n"+
		  "〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n";
	for(i=0;i<sizeof(list);++i)
	{
		p_dis+=sprintf("%-12s%-12s",list[i],
			jobs[list[i]]);
		if(i%2)
			p_dis+="\n";
	}
	if(p_dis[<1]!=10) p_dis+="\n";
	p_dis+="〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n";
	tell_user(y_id,p_dis);
    officer->targetted_action
      ("$N对$T道：你考虑清楚了吗？\n"+
"想好了就请输入 answer <代号> to "+m_id+"\n",who);
}
void myjob(object officer,object who,string ans)
{
    string y_id,m_id,job_name,file_name,m_area;
	string p_status; // job status
	int p_begtime,p_curtime=time();
	mixed ret;
	officer->clear_answer();
    m_id=(officer->query_id())[0];
    y_id=(who->query_id())[0];
	jobs=suitable_job(m_id,y_id);
	
	if(!jobs || (member_array(ans,keys(jobs))==-1)
	    || (!JOB_D->query_job(ans)))
	{
	    officer->targetted_action
		  ("$N对$T摇摇头道：$R要求的工作我们这里没有呀。\n",who);
		return;
	}
	m_area=CHAR_D->get_char(m_id,"area");
	p_begtime=who->query_job(ans,"beg_time");
	if((p_begtime)&&(who->query_job(ans,"assignarea")!=m_area))
	{
		who->resign_job(ans);
		p_begtime=0;
	}
	job_name=jobs[ans];
	p_status=who->query_job(ans,"status");
	if((p_status=="done")&&(p_begtime)) // job finished
	{
		finish_myjob(officer,who,ans);
		return;
	}
	//setppl can not be canceled
	if(p_begtime&&((p_curtime-p_begtime)<MINRESIGNTIME)&&(ans!="setppl"))
	{
		officer->targetted_action
			("$N对$T道：$R当前的"+job_name+"工作尚未完成，即便是觉得太困难，\n至少也要花点时间去试试。\n",who);
		return;
	}
	//setppl do not limit how many for a day
	if(who->query_job(ans,"count_lasttimes") > 
           JOB_D->query_job(ans,"count_lasttimes") && ans!="setppl" ){
		officer->targetted_action
			("$N对$T道：$R今天的"+job_name+"工作已经做得够多了，该换换花样了。\n",who);
		return;
	}
//add By Joey to check positionn for setppl job


	file_name=PJOB+ans+"/"+ans+".c";
	if(file_size(file_name)<1)
	{
	    officer->targetted_action
		  ("$N对$T笑道："+job_name+"工作还没有完成，过会儿再来试试吧。\n",who);
		return;
	}
	if(p_begtime) // resign job first
		who->resign_job(ans);

	ret=file_name->job(who->query_id()[0],officer->query_id()[0]);
	if(!ret)
	{
	    officer->targetted_action
		  ("$N对$T笑道："+job_name+"工作还没有完成，过会儿再来试试吧。\n",who);
		return;
	}

/* emperor add. 加入所有ask job时就先进行robottest */

	officer->targetted_action(
		"$N对$T道：$R精神可嘉，不过得帮我解决个问题，完了才能领取"+jobs[ans]+"工作。\n",who);
	pre_myjob(officer,who,job_name,ans,m_area,ret);
/* emperor add it on 2003.5.12 */
/*emperor omit it on 2003.5.12 
	ret=file_name->job(who->query_id()[0],officer->query_id()[0]);
	if(!ret)
	{
	    officer->targetted_action
		  ("$N对$T笑道："+job_name+"工作还没有完成，过会儿再来试试吧。\n",who);
		return;
	}

	if(who->query_job(ans,"beg_time")) // assign succ
		who->set_job(ans,"assignarea",m_area); // assign area in case player
	                                           // change areas
	if(stringp(ret)) // may get the job, may not
	{  
		officer->targetted_action (ret,who);
		return; 
	}
	officer->targetted_action
		  ("$N对$T笑道：如此就给你安排个"+job_name+"工作，快去吧。\n",who);
*/
}


/*
** emperor add pre_myjob() on 2003.5.12
*/
void pre_myjob(object officer,object who,string job_name,string ans,string m_area,mixed ret)// emperor add this fuction on 2003.5.12
{
	object o;
	o=find_user(who->query_id()[0]);
    if(objectp(o))
        ROBOT->robot_test(o,(:pre_award:),({officer,job_name,ans,m_area,ret}));
//    write("111111\n");
	return;
}

/*
** emperor add pre_award() on 2003.5.12
*/
void pre_award(object usr ,mixed p)
{
    int isrobot;
    string job_name,m_area,ans;
    mixed ret;
    
    object officer = p[0];
    job_name = p[1];
    ans = p[2];
    m_area = p[3];
    ret = p[4];
    if(!objectp(usr)) return;
    usr=usr->query_body();
    if(!objectp(usr)) return;
    isrobot=usr->query_robot();
    if(isrobot)
    {  
		usr->add_job(ans);
		usr->finish_job(ans);
		if(objectp(officer)) {
			officer->targetted_action("$N对$T邹了邹眉：回答错误，没戏。\n",usr);
		}
		else {
			usr->simple_action("$N问题回答错误。\n");
		}
		DELAY_D->delay_simple_action(usr,"$N哼了一声，一副不满的样子。\n",1);
		return;
    }
	if(objectp(officer))
	    officer->targetted_action("$N对$T道：不错，不错，看赏！\n",usr);
	else
		usr->simple_action("$N问题回答正确。\n");
    usr->simple_action("$N高兴地跳了起来。\n");
    
	if(usr->query_job(ans,"beg_time")) // assign succ
		usr->set_job(ans,"assignarea",m_area); // assign area in case player
	                                           // change areas
	if(stringp(ret)) // may get the job, may not
	{  
		if(officer) officer->targetted_action (ret,usr);
		return; 
	}
	if(officer) officer->targetted_action
		  ("$N对$T笑道：如此就给你安排个"+job_name+"工作，快去吧。\n",usr);
}

void finish_myjob(object officer,object who,string job)
{
	object o;
	officer->targetted_action(
		"$N对$T道：任务完成的不错，不过还得帮我解决个问题，完了才能领赏。\n",who);
	o=find_user(who->query_id()[0]);
	who->finish_job(job);
   	who->set_job(job,"status","over");

    if(objectp(o))
        ROBOT->robot_test(o,(:my_award:),({officer , job}));
	return;
}
void my_award(object usr ,mixed para)
{
    string my_id;
    int isrobot;
	int job_level;
	int N=1,val=20; 
    string p_name,job;
	object officer,ob;
    if(!objectp(usr)) return;
    usr=usr->query_body();
    if(!objectp(usr)) return;
	officer=para[0];
	job=para[1];
//	if(!objectp(officer)) return;
    isrobot=usr->query_robot();
    my_id=usr->query_id()[0];
    p_name=CHAR_D->get_char(my_id,"name");
    if(isrobot)
    {  
		if(objectp(officer)) {
			officer->targetted_action("$N对$T邹了邹眉：回答错误，没戏。\n",usr);
		}
		else {
			usr->simple_action("$N问题回答错误。\n");
		}
	   DELAY_D->delay_simple_action(usr,"$N哼了一声，一副不满的样子。\n",1);
       return;
    }
	if(objectp(officer))
	    officer->targetted_action("$N对$T道：不错，不错，看赏！\n",usr);
	else
		usr->simple_action("$N问题回答正确。\n");

	job_level=JOB_D->query_job(job,"level");
	if(job_level==1)
	{
		switch(job)
		{
		case "spy":
			N=sizeof(usr->query_job("spy","spied"));
			if(N==(usr->query_job("spy","size")))
				val=6; // five room equal a common jobs
			else
				val=3; // not finish all
			break;
		case "landlord":
			N = 1+ to_int(usr->query_job("landlord", "reward")/1000);
			val = 1 + random(2);
			break;
		default:
			N=usr->query_job(job,"score");
			val=3;
		}
	}
	switch(job_level)
	{
	case 0:
		switch(job) {
			case "findbody" :
				CHAR_D->set_char(my_id,"reputation",
					CHAR_D->get_char(my_id,"reputation")+1);
				usr->simple_action("$N的声望上升了。\n");
                                ob=new(M_SILVER);
                                ob->set_m_num(random(8)+3);
                                ob->move(usr);
                                usr->simple_action("$N得到几两赏银。\n");
				break ;		
			case "askobj" :
			    CHAR_D->set_char(my_id,"localcontribution",
		              CHAR_D->get_char(my_id,"localcontribution")+1);
			    usr->simple_action("$N的地区贡献增加了。\n");
	        		ob=new(M_SILVER);
		        	ob->set_m_num(random(20)+5);
			        ob->move(usr);
			        usr->simple_action("$N得到几两赏银。\n");
			   break;
			case "bugao" :
			    CHAR_D->set_char(my_id,"loyalty",
		              CHAR_D->get_char(my_id,"loyalty")+1);
			    usr->simple_action("$N的忠诚度增加了。\n");
	        		ob=new(M_SILVER);
		        	ob->set_m_num(random(10)+5);
			        ob->move(usr);
			        usr->simple_action("$N得到几两赏银。\n");
			   break;

                        default:
                           break;
                 }
                 break;


	case 1:
/*		CHAR_D->set_char(my_id,"reputation",
		   CHAR_D->get_char(my_id,"reputation")+N*val);
		usr->award_exp(N*val,"");
		CHAR_D->set_char(my_id,"localcontribution",
		   CHAR_D->get_char(my_id,"localcontribution")+N*val/10+1);
		usr->simple_action("$N的声望上升了。\n");
		usr->simple_action("$N的经验增加了。\n");
		usr->simple_action("$N地区贡献增加了。\n");
*/
	        AWARD(usr,N*val);  // no change all the middle level job
  		    	         // reward credit
		switch(job) {
			case "whisper" :
			      CHAR_D->set_char(usr->query_job("whisper","target"),"loyalty",
			                   usr->query_job("whisper","loyalty"));
			      break ;		
			case "letter" :
			      CHAR_D->set_char_loyalty(usr->query_job("letter","target"),
			                   CHAR_D->get_char(my_id,"nation"),
			                   usr->query_job("letter","loyalty"));
			      break ;		
                        default:
                              break;
                            }
	
		break;
	default:
		usr->simple_action("not finish yet.\n");
	}
    usr->simple_action("$N高兴地跳了起来。\n");
}
