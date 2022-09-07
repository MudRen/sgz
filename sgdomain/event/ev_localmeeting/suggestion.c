// suggestion.c
// by fire on Auguest 06 1998
// this is used for localmeeting to handle suggestions
// may be can be used by other meetings as well
#include <localmeeting.h>
void discuss_train(int task_id,int p_disnum);
void do_consider(string p_id);
void meet_over(int p_id);
void get_suggestion(int task_id,string p_who,string p_what,mixed p_para)
{
    int p_num;
	string* suggested;
   object o=CHAR_D->find_char(p_who);
   if(!objectp(o)) return;
	suggested=TASK_D->get_task(task_id,"suggested");
	if(!arrayp(suggested))
		suggested=({});
	if(member_array(p_what,suggested)!=-1)
	{
		object o_id;
		string p_id;
		p_id=AREA_D->get_area(TASK_D->get_task(task_id,"area"),"leader");
                o_id=CHAR_D->find_char(p_id);
		if(objectp(o_id))
                        o_id->simple_action("$N道：会议上不必反复提相似的建议。\n");
		return;
	}
   if(( o->query_job("suggest","count_lasttimes") > 
        JOB_D->query_job("suggest","count_lasttimes")) && 
        (p_what!="train")&&(p_what!="over")&&(p_what!="war")){
       object o_id;
       string p_id;
       p_id=AREA_D->get_area(TASK_D->get_task(task_id,"area"),"leader");
       o_id=CHAR_D->find_char(p_id);
       if(objectp(o_id))
          o_id->targetted_action
("$N道：$m今天提的建议已经够多了，该听听别人的意见了。\n",CHAR_D->find_char(p_who));
       return;
   }
   if(p_what!="train") 
   { o->resign_job("suggest");o->add_job("suggest");
   }
        TASK_D->set_task(task_id,"suggestion", p_what);
        TASK_D->set_task(task_id,"suggestionppl",p_who);
        p_num=TASK_D->get_task(task_id,"suggestionnum");
        TASK_D->set_task(task_id,"suggestiondetail",p_para);
        p_num=p_num+1;
        TASK_D->set_task(task_id,"suggestionnum",p_num);
        TASK_D->set_task(task_id,"suggestiondisnum",0);
        TASK_D->set_task(task_id,"supportgrp",({p_who}));
        TASK_D->set_task(task_id,"againstgrp",({}));
        TASK_D->set_task(task_id,"neutalgrp",({}));
        TASK_D->set_task(task_id,"stage",LMS_DISCUSS);
        TASK_D->set_task(task_id,"timer",0);
        TASK_D->set_task(task_id,"timaim",LML_DISCUSS);
}
string get_problem(int task_id)
{
	string p_subject;
	mixed p_para;
	p_subject=TASK_D->get_task(task_id,"suggestion");
	p_para=TASK_D->get_task(task_id,"suggestiondetail");
        switch(p_subject)
        {
        case "localtax":
             return sprintf("税率调到%d",p_para);
		case "war":
			return sprintf("出兵%s",AREA_D->get_area(p_para,"name"));
		case "recruit":
			if(!mapp(p_para))
				return sprintf("征兵%d",p_para);
			else
				return sprintf("裁%s%d",WARAI_D->query_type(p_para["type"],"name"),-(p_para["no"]));
		case "importance":
                        return sprintf("本地区发展策略转为"+(PCMD+"importance")->get_obj(p_para));
		case "localbuy":
			return "购进一批"+(EV_MERCHANT)->query_goods(p_para,"name");

		case "localbuy":
			return "购进一批"+(EV_MERCHANT)->query_goods(p_para,"name");
		case "sendfood":
			return "开仓赈粮"+chinese_number(p_para);
		case "build":
			return "建造"+BASE_D->get_base(p_para,"name");
		case "update":
			return "升级"+BASE_D->get_base(p_para,"name");
		case "market":
			return "开办集市";
        }
        return "";
}
void dis_over(int task_id)
{
        TASK_D->set_task(task_id,"suggestion", 0);
        TASK_D->set_task(task_id,"suggestionppl",0);
        TASK_D->set_task(task_id,"suggestiondetail",0);
        TASK_D->set_task(task_id,"supportgrp",0);
        TASK_D->set_task(task_id,"againstgrp",0);
        TASK_D->set_task(task_id,"neutalgrp",0);
        TASK_D->set_task(task_id,"stage",LMS_PROCESS);
        TASK_D->set_task(task_id,"timer",0);
        TASK_D->set_task(task_id,"timaim",LML_PROCESS);
        return;
}
void show_ask(string p_leader,string b_id)
{
        object o_leader,o_id;
        string p_string;
        int p_tmp;
        if(p_leader==b_id)
        {
                p_tmp=random(5);
                switch(p_tmp)
                {       case 0:
                        p_string="$N道：这个问题看来真是不好决定。\n";
                        break;
                        case 1:
                        p_string="$N开始认真考虑这个问题。\n";
                        break;
                        case 2:
                        p_string="$N边搓手边道：真是个棘手的问题。\n";
                        break;
                        case 3:
                        p_string="$N道：你们怎么都不开腔啦？\n";
                        break;
                        case 4:
                        p_string="$N道：我们得抓紧时间。\n";
                        break;
                }
                o_leader=CHAR_D->find_char(p_leader);
                if(objectp(o_leader))
                        o_leader->simple_action(p_string);
        }
        else
        {
                p_tmp=random(5);
                switch(p_tmp)
                {       case 0:
                        p_string="$N对$T道：$m$R意下如何？\n";
                        break;
                        case 1:
                        p_string="$N指了指$T道：$m$R好像有话要说。\n";
                        break;
                        case 2:
                        p_string="$N对$T道：说说你的看法吧。\n";
                        break;
                        case 3:
 p_string="$N对$T一抱拳，道：$m$R一向见解高明，这回也给我们参谋参谋。\n";
                        break;
                        case 4:
                        p_string="$N对$T道：该你发话啦。\n";
                        break;
                }
                o_leader=CHAR_D->find_char(p_leader);
                o_id=CHAR_D->find_char(b_id);
                if(objectp(o_leader)&&objectp(o_id))
                        o_leader->targetted_action(p_string,o_id);
        }
     do_consider(b_id);
}
void ask_discuss(int task_id)
{
        string p_leader;
        string p_area;
        string p_subject;
        string p_problem;
        object o_leader;
        int p_disnum;
        mixed p_para;
        
        string *p_char;
        mixed p_tmp;
        int p_num;
        
        p_area=TASK_D->get_task(task_id,"area");
        p_leader=AREA_D->get_area(p_area,"leader");
        p_subject=TASK_D->get_task(task_id,"suggestion");
	if(!p_subject) return;
        p_para=TASK_D->get_task(task_id,"suggestiondetail");
        p_problem=get_problem(task_id);
        p_tmp=TASK_D->get_task(task_id,"chars");
        p_char=keys(p_tmp);
        p_tmp=TASK_D->get_task(task_id,"againstgrp");
        p_char-=p_tmp;
        p_tmp=TASK_D->get_task(task_id,"supportgrp");
        p_char-=p_tmp;
        p_tmp=TASK_D->get_task(task_id,"neutalgrp");
        p_char-=p_tmp;
        p_num=sizeof(p_char);
        if(p_num)
        {
                string b_id;
                b_id=p_char[random(p_num)];
                show_ask(p_leader,b_id);
        }
}
void meet_discuss(int task_id)
{
        string p_leader;
        string p_area;
        string p_subject;
        string p_problem;
        object o_leader;
        int p_disnum;
        mixed p_para;
        p_area=TASK_D->get_task(task_id,"area");
        p_leader=AREA_D->get_area(p_area,"leader");
        p_subject=TASK_D->get_task(task_id,"suggestion");
        p_para=TASK_D->get_task(task_id,"suggestiondetail");
        p_problem=get_problem(task_id);
        p_disnum=TASK_D->get_task(task_id,"suggestiondisnum");
        p_disnum++;
        TASK_D->set_task(task_id,"suggestiondisnum",p_disnum);
        TASK_D->set_task(task_id,"timer",0);
        switch(p_subject)
        {
           case "train" : 
              discuss_train(task_id,p_disnum);
              return; 
		   case "over":
				meet_over(task_id);
				return;

        }
        if((p_disnum>MAX_DISCUSSTIME)&&
		(p_disnum>sizeof(TASK_D->get_task(task_id,"chars")))) // discuss too many time
        {
                o_leader=CHAR_D->find_char(p_leader);
                if(objectp(o_leader))
                        o_leader->simple_action
("$N道：关于"+p_problem+"的问题，今天看来是讨论不出结果，咱们改日再谈。\n"
);
                dis_over(task_id);
        }
        else
        {
                o_leader=CHAR_D->find_char(p_leader);
                if(objectp(o_leader))
                        o_leader->simple_action
("$N道：关于"+p_problem+"的问题，还请大家多多发表意见。\n");
                
                call_out("ask_discuss",2,task_id);
        }
}
