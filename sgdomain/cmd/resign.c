// resign.c 
// by row on May 29, 1999
// used for player char to risign a job
#include <ansi.h>
string job_id;
string job_memo1;
  string *forbiden = ({"xu zijiang", "hua tuo", "landlord","train"});
void confirm_resign(string p_idd,mixed p_input)
{
        string p_id;
        int rep,cut_rep;
        this_body()->modal_pop();
        p_id = this_body()->query_id()[0];
//        cut_rep=random(50);
        if(p_input=="yes"){
                write("���������"HIY""+job_memo1+""NOR"�Ĺ�����\n");
                this_body()->resign_job(p_idd);
                rep=CHAR_D->get_char(p_id,"reputation");
                if( (rep-cut_rep)<10 ){
                        return;
                }
		cut_rep=random(rep/20);
		if (cut_rep>250) cut_rep=250;
                rep=rep-cut_rep;
                write("��������½���"+chinese_number(cut_rep)+"�㡣\n");
                CHAR_D->set_char(p_id,"reputation",rep);
                return;
        }
        else
        write("�����ǲ�����������ѽ��\n");
        return; 
}
void start(string arg)
{
        string job_id,job_memo;
        int beg_time,time;
        time=time();
        if( (!arg)||(arg=="") ){
                write("�÷�: cmd resign <job_id>\n");
                write("���ӣ�cmd resign whisper (�����߷��н��Ĺ���)\n");
                return;
        }
        if( member_array(arg, forbiden) != -1 ){
                write("�㲻�ܷ����������\n");
                return;
        }
        beg_time = this_body()->query_job(arg,"beg_time");
        if (beg_time==0){
                write("�㲢û������������\n");
                return;
        }
        job_memo=JOB_D->query_job(arg,"name");
        job_memo1=job_memo;
        job_id=arg;
        if ((time-beg_time)/60<8){
                write("��ողŽ��ܹ����������������ٿ��Ƿ����ɡ�\n");
                return;
        } else {
                write("�������Ҫ����"HIY""+job_memo+
""NOR"������𣿣�������һ����ʧ��\nȷ��������yes��������س����˳���\n");
                this_body()->modal_push((: confirm_resign,arg:),"",0,0);
        }
}
