// string.c
// by fire on Dec 1998
#include <ansi.h>
string get_char_reputation(int sg_shengwang)
{
        if(sg_shengwang<10)
                return "ĬĬ����" ;
        if(sg_shengwang<100)
                return RED + "С������"+NOR ;
        if(sg_shengwang<1000)
                return YEL + "��¶��â" +NOR;
        if(sg_shengwang<10000)
                return GRN + "�ư�һ��"+NOR ;
        if(sg_shengwang<100000)
                return HIY + "��¹��ԭ"+NOR ;
        if(sg_shengwang<1000000)
                return HIR + "�ʶ�����"+NOR ;
        if(sg_shengwang<10000000)
                return HIG + "��������"+NOR ;
        return HIC+"һͳ����"+NOR ;
        
}
string query_status(int p_status)
{
        switch(p_status)
        {
        case STATUS_NOTFINISHED:
                return "δ��";
        case STATUS_SLEEPING:
                return"����";
        case STATUS_ACTIVE:
                return"�";
        case STATUS_ONLINE:
                return"����";
        default:
                return"δ֪";
        }
}
