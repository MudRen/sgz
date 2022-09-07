// ev_localmeeting.c 
// this is used to handle the local meeting
// this in fact is a task
// by fire on July 31, 1998
// this is to check if an area can hold a
// local meeting
#include <localmeeting.h>

#define MAXNUMBER 9

inherit __DIR__+"ev_localmeeting/pass";
inherit __DIR__+"ev_localmeeting/train";
inherit __DIR__+"ev_localmeeting/suggestion";
inherit __DIR__+"ev_localmeeting/agree";
inherit __DIR__+"ev_localmeeting/judge";
inherit __DIR__+"ev_localmeeting/consider";
inherit __DIR__+"ev_localmeeting/absent";

int can_lmeeting(string a_id)
{
        int* task;
        string p_leader;
        string* u_list;
        int i,a_num;
        p_leader=AREA_D->get_area(a_id,"leader");
        task=TASK_D->get_char_task(p_leader);
        if(task[0]!=-1)  // has some task
        {
                if(task[1]==TT_LOCALMEETING)
                        return LM_ALREADYLOCALMEETING;
                else
                        return LM_OTHERTASK;
        }
        u_list=CHAR_D->check_char_area("nation",
                AREA_D->get_area(a_id,"nation"),a_id);
        
        a_num=0;
        for(i=0;i<sizeof(u_list);++i)
        {
                task=TASK_D->get_char_task(u_list[i]);
                if(task[0]==-1)
                        a_num++;
        }
        if((sizeof(u_list)-a_num)>=LM_MINABSENT)
                return LM_TOOMANYABSENT;
        if(a_num<LM_MINCHAR)
        {
                return LM_NOENOUTHCHAR;
        }
        return LM_OK;
}
int can_auto_lmeeting(string a_id)
{
        string p_leader;
        p_leader=AREA_D->get_area(a_id,"leader");
        if((CHAR_D->get_char(p_leader,"status"))==STATUS_ONLINE)
                return 0; // a player is the leader can't auto meeting
        if(can_lmeeting( a_id)==LM_OK)
                return 1;
        return 0;
}
// this is used for the system to hold local meeting
// in a regular schedule 
void local_meeting(string a_id)
{
        int t_num;
        mapping m_us;
        string *u_list,*u_all;
        string s_room;
        string p_leader;
        string tmp;
        int *task,i;
        object ob_char;
        CHANNEL_D->deliver_tell("rumor","system",
            sprintf("%s���ھ��е������顣",AREA_D->get_area(a_id,"name")));
        t_num=TASK_D->add_task(TT_LOCALMEETING);
        TASK_D->set_task(t_num,"area",a_id);
        s_room=AREA_D->get_area(a_id,"path")+
                AREA_D->get_area(a_id,"meeting");
        TASK_D->set_task(t_num,"room",s_room);
        u_all=CHAR_D->check_char_area("nation",
                AREA_D->get_area(a_id,"nation"),a_id);
        p_leader=AREA_D->get_area(a_id,"leader");

        if(sizeof(u_all)<=MAXNUMBER){
                u_list=u_all;
        }
        else {
                u_list=filter_array(u_all,(:CHAR_D->get_char($1,"status")==STATUS_ONLINE:));
                u_list-=({p_leader});
                u_list+=({p_leader});
                u_all-=u_list;
                while(sizeof(u_list)<MAXNUMBER){
                        tmp=u_all[random(sizeof(u_all))];
                        u_list+=({tmp});
                        u_all-=({tmp});
                }
        }

        m_us=([]);
        for(i=0;i<sizeof(u_list);++i)
        {
                task=TASK_D->get_char_task(u_list[i]);
                if(task[0]==-1)
                {
                        m_us[u_list[i]]=LMP_ATTEND;
                        CHAR_D->set_char(u_list[i],"task",TASK_MEETING);
                        if(CHAR_D->get_char(u_list[i],"status")==STATUS_ONLINE) // a player
                        {
                                if(file_name(environment(CHAR_D->find_char(u_list[i])))!=s_room)
                                (EV_INFORMSB)->inform_sb(u_list[i],
                                AREA_D->get_area(a_id,"name")+"Ҫ�ٿ��ط����飬��$R��ȥ��");    
                        }
                        else
                        {
                                ob_char=CHAR_D->find_char(u_list[i]);
                                if(CHAR_D->get_char(u_list[i],"status")==STATUS_ACTIVE) // active
                                {
                                    if(CHAR_D->get_char(u_list[i],"room")!= s_room)
                                    {
                                        (EV_INFORMSB)->inform_sb(u_list[i],
                                                AREA_D->get_area(a_id,"name")+"Ҫ�ٿ��ط����飬��$R��ȥ��");    
                                        if(objectp(ob_char))
                                        {
                                                ob_char->simple_action("$N���ֵ���$s��Ҫ����������ǣ��������¡�\n");
                                                ob_char->simple_action("$N���Ҵҵ��뿪�ˡ�\n");
                                        }
                                        CHAR_D->put_char(u_list[i],s_room);
                                      if(objectp(ob_char))
                                        ob_char->simple_action("$N���Ҵҵ����˹�����\n");
                                    }
                                }
                                else
                                {
                                        if(!objectp(ob_char)||
                                        (file_name(environment(CHAR_D->find_char(u_list[i])))!=
                                                s_room))
                                        {
                                                CHAR_D->put_char(u_list[i],s_room);
                                                ob_char=CHAR_D->find_char(u_list[i]); if(objectp(ob_char))
                                                ob_char->simple_action("$N���Ҵҵ����˹�����\n");
                                        }
                                }
                        }
                }
        }
        AREA_D->set_area(a_id,"status",ST_MEETING);
        ob_char = CHAR_D->find_char(p_leader);
        if(objectp(ob_char))
              ob_char->simple_action("$N����������λ�԰�����������Ͽ�ʼ��\n");
        m_us[p_leader]=LMP_LEADER;
        TASK_D->set_task(t_num,"start_time",time());
        TASK_D->set_task(t_num,"chars",m_us);
        TASK_D->set_task(t_num,"timaim",LML_BEGIN);
        TASK_D->set_task(t_num,"stage",LMS_BEGIN);
}
void auto_local_meeting()
{
}
void meet_announce(int p_id)
{
        string p_area;
        string p_leader;
        object o_char;
        p_area=TASK_D->get_task(p_id,"area");
        p_leader=AREA_D->get_area(p_area,"leader");
        o_char=CHAR_D->find_char(p_leader);
        if(objectp(o_char))
        {
                o_char->simple_action
                ("$N������λ���������ˣ�$S����������������̸̸�������ľ�������������\n");
                o_char->simple_action
                ("$N���ŵ�����λ���ؾ����볩�����ԡ�\n");
        }
        call_out("begin_absent",20,p_id,0);
        TASK_D->set_task(p_id,"stage",LMS_PROCESS);
        TASK_D->set_task(p_id,"timaim",LML_PROCESS);
        return;
}
void meet_readytoend(int p_id)
{
        string p_area;
        string p_leader;
        object o_char;
        p_area=TASK_D->get_task(p_id,"area");
        p_leader=AREA_D->get_area(p_area,"leader");
       begin_absent(p_id,1);
        o_char=CHAR_D->find_char(p_leader);
        if(objectp(o_char))
        {
                o_char->simple_action
                ("$N������λ���������ˣ�ʱ�����磬���к���Ҫ�飿\n");
                o_char->simple_action
                ("$N���ŵ����������£���λ����Щ�ظ�ЪϢȥ�ɡ�\n");
        }
        TASK_D->set_task(p_id,"stage",LMS_END);
        TASK_D->set_task(p_id,"timaim",LML_END);
        return;
}
void meet_over(int p_id)
{
        string p_area;
        string p_leader;
        object o_char;
        mapping m_us;
        string *p_list;
        int i;
        p_area=TASK_D->get_task(p_id,"area");
        p_leader=AREA_D->get_area(p_area,"leader");  // ̫�� id
        o_char=CHAR_D->find_char(p_leader);
        if(objectp(o_char))
        {
                if(TASK_D->get_task(p_id,"war_leader")) // will have war 
                {
                        o_char->simple_action("�������٣������ȥ׼�������̷�����");

                }
                else {
                        o_char->simple_action
                                        ("$N����������ձ㵽�����λ���������ˣ�����ء�\n");
                        if(TASK_D->get_task(p_id,"trainleader"))
                                        o_char->simple_action(
                                          "$N���ŵ����μ������ľ�ȥ׼���ɡ�\n");
                }
        }
        m_us=TASK_D->get_task(p_id,"chars");
        p_list=keys(m_us);
        
        for(i=0;i<sizeof(p_list);++i)
        {
            // remove the task from each id that joined the meeting            
            CHAR_D->set_char(p_list[i],"task",TASK_NONE);

            // �����һ�� npc �ֲ���̫�أ���������ʧ
            if( ( p_leader != p_list[i] ) && ( CHAR_D->get_char_status(p_list[i])!= STATUS_ONLINE ) )
            {
                o_char=CHAR_D->find_char(p_list[i]);
                if(objectp(o_char))
                {
                        o_char->simple_action
                        ("$N���ֵ���$s��ǣ�\n$N����Ҵ��뿪�ˡ�\n");
                }

                CHAR_D->remove_npc_char(p_list[i]);
            }
            
        }
        
        AREA_D->set_area(p_area,"status",ST_NORMAL);

        if(TASK_D->get_task(p_id,"war_leader")) // will have war 
        {// to trigger a war
                string att_leader, def_area,att_area;
                att_leader=TASK_D->get_task(p_id,"war_leader");
                def_area=TASK_D->get_task(p_id,"def_area");
                att_area=TASK_D->get_task(p_id,"att_area");
        
                TASK_D->remove_task(p_id); // safe to cancel the old task first

                (EV_WAR)->area_war(att_leader,att_area,def_area);
                return;
        }
        else if(TASK_D->get_task(p_id,"trainleader"))
        {
            string leader;
            mixed group;
            leader=TASK_D->get_task(p_id,"trainleader");
            group=TASK_D->get_task(p_id,"traingrp");
            TASK_D->remove_task(p_id);
            (EV_WAR)->train(p_area,leader,group);
            return; 
       }
        TASK_D->remove_task(p_id);
        
}
void meet_process(int p_id)
{
        int p_stage;
        p_stage=TASK_D->get_task(p_id,"stage");
        switch(p_stage)
        {
        case LMS_BEGIN:
                meet_announce(p_id);
                break;
        case LMS_PROCESS:
                meet_readytoend(p_id);
                break;
        case LMS_DISCUSS:
                meet_discuss(p_id);
                break;
        case LMS_END :
        default:
                meet_over(p_id);
        }
}
void ask_localmeeting(object who, object officer)
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
         ("$N��$TЦ����Ҫ���������飿����$s����������������ʾ����"+m_title+"��\n",who);
         return;
    }
        if(((CHAR_D->get_char(m_id,"nation"))!=(CHAR_D->get_char(y_id,"nation")))
           ||((CHAR_D->get_char(m_id,"nation"))!=(CHAR_D->get_char(y_id,"nation"))))
        {
        officer->targetted_action
         ("$N��$TЦ����лл$m$R�Ĺ��ģ����ǻᰲ�ŵġ�\n",who);
         return;
        }
        if((file_name(environment(officer)))!=
                ((AREA_D->get_area(m_area,"path"))+(AREA_D->get_area(m_area,"meeting"))))
        {
        officer->targetted_action
         ("$N��$Tҡҡͷ��Ц�����˴��ǻ���֮����\n",who);
         return;
        }

        if(CHAR_D->get_char(y_id,"level")<2)
        {
                officer->targetted_action
                       ("$N��$Tҡҡͷ��$R����ְ��Ա�����������Ͳ���̫�����ˡ�\n",who);
                return;
        }

        if(CHAR_D->get_char(y_id,"area")!=m_area)
        {
                officer->targetted_action
                       ("$N��$Tҡҡͷ��$R�Ǳ��ع�Ա�����������Ͳ���̫�����ˡ�\n",who);
                return;
        }

        p_check=can_lmeeting(CHAR_D->get_char(m_id,"area"));

        switch(p_check)
        {
        case LM_OK:
        officer->targetted_action
         ("$N��$T����$m$R����$s����һ�¡�\n",who);
                if(CHAR_D->get_char(m_id,"status")==STATUS_ONLINE)
                {
                        tell_user(m_id,"ͬ�⿪�������� cmd localmeeting��\n");
                }
                else
                {
        officer->targetted_action("$N��$T��ͷ�����ðɡ�\n",who);
                local_meeting(CHAR_D->get_char(m_id,"area"));
                }
                return;
        case LM_OTHERTASK:
        officer->targetted_action
         ("$N��$Tҡ��ҡͷ������$s����̫æ���ֲ�����ѽ��\n",who);
         return;
        case LM_ALREADYLOCALMEETING:
        officer->targetted_action
         ("$N��$T����$m$R����������æ��Ϳ�ˣ��ҵ��ڴ˲��������鱾��������\n",who);
         return;
        case LM_NOENOUTHCHAR :
        officer->targetted_action
         ("$N��$TЦ����$m$R��������ң�����ʲô��ѽ��\n",who);
         return;
        case LM_TOOMANYABSENT:
        default:
        officer->targetted_action
         ("$N��$TЦ����$m$R�����˽�����ϵ����������ֻ�������վ��С�\n",who);
         return;
        }
}