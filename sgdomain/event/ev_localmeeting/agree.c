// agree.c
// by fire on Auguest 06 1998
// this is used for localmeeting to handle agree of suggestion
#include <localmeeting.h>
void begin_judge(int task_id);
void dis_over(int task_id);
string get_problem(int task_id);
void do_agree_sb(int task_id,string my_id,string t_id)
{
        string p_subject;
        string p_problem;
        mixed p_para;
        object o_my,o_tar;
        int pos;
        string *ag,*dg,*ng;
        string p_act;
        int p_ran;
        ag=TASK_D->get_task(task_id,"supportgrp");
        dg=TASK_D->get_task(task_id,"againstgrp");
        ng=TASK_D->get_task(task_id,"neutalgrp");
        p_subject=TASK_D->get_task(task_id,"suggestion");
        p_para=TASK_D->get_task(task_id,"suggestiondetail");
        p_problem=get_problem(task_id);
        if(member_array(t_id,ag)!=-1)
                pos=1; // agree
        
        if(member_array(t_id,dg)!=-1)
                pos=2; // disagree
        if(member_array(t_id,ng)!=-1)
                pos=3; // no idea
        p_ran=random(5);
        o_my=CHAR_D->find_char(my_id);
        o_tar=CHAR_D->find_char(t_id);
        switch(p_ran)
        {
                case 0:
                        p_act="$N��$Tһ���֣�����$R��߼�Ҳ��\n";
                        break;
                case 1:
                        p_act="$Nһ��$T�ļ�򣬵����ߣ��ߣ�ʵ�ڸ�����\n";
                        break;
                case 2:
                        p_act="$N��$TЦ����$R֮����$s��ı����ѽ��\n";
                        break;
                case 3:
                        p_act="$N��ͷ������֧��$m$R�Ĺ۵㡣\n";
                        break;
                default:
                        p_act="$Nһ�Ĵ��ȣ�����$m$R���Լ��ǡ�\n";
                        break;
        }
        if(objectp(o_my)&&objectp(o_tar))
                o_my->targetted_action(p_act,o_tar);
        switch(pos)
        {
                case 1:
                        ag+=({my_id});
                        TASK_D->set_task(task_id,"supportgrp",ag);
                        p_act="$N���ŵ�����֧��"+p_problem+"��";
                        break;
                case 2:
                        dg+=({my_id});
                        TASK_D->set_task(task_id,"againstgrp",dg);
                        p_act="$N���ŵ����ҷ���"+p_problem+"��";
                        break;
                default:
                        ng+=({my_id});
                        TASK_D->set_task(task_id,"neutalgrp",ng);
                        p_act="$N����˵��������"+p_problem+"����û�п�����";
                        break;
        }
        if(objectp(o_my))
        o_my->simple_action(p_act);
      begin_judge(task_id);
}
mixed agree_sb(int task_id,string my_id,string t_id)
{
        
        int p_num;
        string p_name;
        string *chars;
        string *ag,*dg,*ng;
        string sub;
        sub=TASK_D->get_task(task_id,"suggestion");
        if(!sizeof(sub))
                return "����û��ʲô���⡣\n";
        if(sub=="train") 
             return "ѵ��ûʲô�����۵ģ���cmd me��ʾ�μӡ�\n";   
		if(sub=="over")
             return "��ǰɢ��ûʲô�����۵ģ���ͬ����cmd against��ʾ���ԡ�\n";   
        if(!sizeof(t_id))
                t_id=TASK_D->get_task(task_id,"suggestionppl");
        p_name=CHAR_D->get_char(t_id,"name");
        if(!p_name)
                return "��ͬ��˭�������\n";
        if(t_id==my_id)
                return "�㵱Ȼͬ���������ˡ�\n";
        chars=keys(TASK_D->get_task(task_id,"chars"));
        ag=TASK_D->get_task(task_id,"supportgrp");
        dg=TASK_D->get_task(task_id,"againstgrp");
        ng=TASK_D->get_task(task_id,"neutalgrp");
        if(member_array(t_id,chars)==-1)
                return sprintf("%s��û�вμӻ��顣\n",p_name);
        if((member_array(t_id,ag)==-1)&&
           (member_array(t_id,dg)==-1)&&
           (member_array(t_id,ng)==-1))
                return sprintf("%s��û�з��������\n",p_name);
        if((member_array(my_id,ag)!=-1)||
           (member_array(my_id,dg)!=-1)||
           (member_array(my_id,ng)!=-1))
                return "���Ѿ�������߼��ˡ�\n";
        do_agree_sb(task_id,my_id,t_id);
        return 0;
}
void do_disagree_sb(int task_id,string my_id,string t_id)
{
        string p_subject;
        string p_problem;
        mixed p_para;
        object o_my,o_tar;
        int pos;
        string *ag,*dg;
        string p_act;
        int p_ran;
        ag=TASK_D->get_task(task_id,"supportgrp");
        dg=TASK_D->get_task(task_id,"againstgrp");
        p_subject=TASK_D->get_task(task_id,"suggestion");
        p_para=TASK_D->get_task(task_id,"suggestiondetail");
        p_problem=get_problem(task_id);
        if(member_array(t_id,ag)!=-1)
                pos=1; // agree
        
        if(member_array(t_id,dg)!=-1)
                pos=2; // disagree
        p_ran=random(5);
        o_my=CHAR_D->find_char(my_id);
        o_tar=CHAR_D->find_char(t_id);
        switch(p_ran)
        {
                case 0:
                        p_act="$N��ü����$m$R֮���ƺ������ϡ�\n";
                        break;
                case 1:
                        p_act="$N��$Tҡͷ����$R֮����$s���ҹ�ͬ��\n";
                        break;
                case 2:
                        p_act="$Nҡҡͷ������$m$R���Է��������롣\n";
                        break;
                case 3:
                        p_act="$N�����ҷ���$m$R�Ĺ۵㡣\n";
                        break;
                default:
                     p_act="$N����Ƭ�̣�����$m$R�����ƺ�������ʵ��Ȼ��\n";
                        break;
        }
        if(objectp(o_my)&&objectp(o_tar))
                o_my->targetted_action(p_act,o_tar);
        switch(pos)
        {
                case 2:
                        ag+=({my_id});
                        TASK_D->set_task(task_id,"supportgrp",ag);
                        p_act="$N���ŵ�����֧��"+p_problem+"��";
                        break;
                default:
                        dg+=({my_id});
                        TASK_D->set_task(task_id,"againstgrp",dg);
                        p_act="$N����˵�����ҷ���"+p_problem+"��";
                        break;
        }
        if(objectp(o_my))
        o_my->simple_action(p_act);
      begin_judge(task_id);
}
mixed disagree_sb(int task_id,string my_id,string t_id)
{
        
        int p_num;
        string p_name;
        string *chars;
        string *ag,*dg,*ng;
        string sub;
        sub=TASK_D->get_task(task_id,"suggestion");
        if(!sizeof(sub))
                return "����û��ʲô����ɷ��ԡ�\n";
        if(sub=="train") 
             return "ѵ��ûʲô�����۵ģ���cmd me��ʾ�μӡ�\n";   
		if(sub=="over") {
			object o;
			o=CHAR_D->find_char(my_id);
			if(!objectp(o)) return; // impossible
			o->simple_action("$N������æ����æɢ�ᣬ�һ��л�����\n");
			dis_over(task_id);
			return 0;
		}

        if(!sizeof(t_id))
                t_id=TASK_D->get_task(task_id,"suggestionppl");
        p_name=CHAR_D->get_char(t_id,"name");
        if(!p_name)
                return "�㷴��˭�������\n";
        if(t_id==my_id)
                return "�㷴�����Լ���\n";
        chars=keys(TASK_D->get_task(task_id,"chars"));
        ag=TASK_D->get_task(task_id,"supportgrp");
        dg=TASK_D->get_task(task_id,"againstgrp");
        ng=TASK_D->get_task(task_id,"neutalgrp");
        if(member_array(t_id,chars)==-1)
                return sprintf("%s��û�вμӻ��顣\n",p_name);
        if((member_array(t_id,ag)==-1)&&
           (member_array(t_id,dg)==-1)&&
           (member_array(t_id,ng)==-1))
                return sprintf("%s��û�з��������\n",p_name);
        if(member_array(t_id,ng)!=-1)
                return sprintf("%s�����û�����ԡ�\n",p_name);
        if((member_array(my_id,ag)!=-1)||
           (member_array(my_id,dg)!=-1)||
           (member_array(my_id,ng)!=-1))
                return "���Ѿ�������߼��ˡ�\n";
        do_disagree_sb(task_id,my_id,t_id);
        return 0;
}
void do_neutral_sb(int task_id,string my_id,string t_id)
{
        string p_subject;
        string p_problem;
        mixed p_para;
        object o_my,o_tar;
        int pos;
        string *ng;
        string p_act;
        int p_ran;
        ng=TASK_D->get_task(task_id,"neutalgrp");
        p_subject=TASK_D->get_task(task_id,"suggestion");
        p_para=TASK_D->get_task(task_id,"suggestiondetail");
        p_problem=get_problem(task_id);
        pos=3; // neutral
        
        p_ran=random(2);
        o_my=CHAR_D->find_char(my_id);
        o_tar=CHAR_D->find_char(t_id);
        switch(p_ran)
        {
           case 0:
	      p_act="$N����$m$R֮������ԣ�Ҳ���񲻶ԣ���֮��������\n";
              break;
           default:
              p_act="$N��ü����$m$R���ԣ�֧�ֲ��ǣ���֧��Ҳ���ǣ�������\n";
                        break;
        }
        if(objectp(o_my)&&objectp(o_tar))
                o_my->targetted_action(p_act,o_tar);
        ng+=({my_id});
        TASK_D->set_task(task_id,"neutalgrp",ng);
        p_act="$N���ŵ�������"+p_problem+"����û�п�����\n";
        if(objectp(o_my))
        o_my->simple_action(p_act);
      begin_judge(task_id);
}
mixed neutral_sb(int task_id,string my_id,string t_id)
{
        
        int p_num;
        string p_name;
        string *chars;
        string *ag,*dg,*ng;
        string sub;
        sub=TASK_D->get_task(task_id,"suggestion");
        if(!sizeof(sub))
                return "����û��ʲô����ɱ�ʾ������\n";
        if(sub=="train") 
             return "ѵ��ûʲô�����۵ģ���cmd me��ʾ�μӡ�\n";   
		if(sub=="over")
             return "��ǰɢ��ûʲô�����۵ģ���ͬ����cmd against��ʾ���ԡ�\n";   
        if(!sizeof(t_id))
                t_id=TASK_D->get_task(task_id,"suggestionppl");
        p_name=CHAR_D->get_char(t_id,"name");
        if(!p_name)
                return "���˭�������ʾ������\n";
        if(t_id==my_id)
                return "������Լ���ʾ������\n";
        chars=keys(TASK_D->get_task(task_id,"chars"));
        ag=TASK_D->get_task(task_id,"supportgrp");
        dg=TASK_D->get_task(task_id,"againstgrp");
        ng=TASK_D->get_task(task_id,"neutalgrp");
        if(member_array(t_id,chars)==-1)
                return sprintf("%s��û�вμӻ��顣\n",p_name);
        if((member_array(t_id,ag)==-1)&&
           (member_array(t_id,dg)==-1)&&
           (member_array(t_id,ng)==-1))
                return sprintf("%s��û�з��������\n",p_name);
        if((member_array(my_id,ag)!=-1)||
           (member_array(my_id,dg)!=-1)||
           (member_array(my_id,ng)!=-1))
                return "���Ѿ�������߼��ˡ�\n";
        do_neutral_sb(task_id,my_id,t_id);
        return 0;
}
