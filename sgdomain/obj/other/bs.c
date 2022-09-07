// by fire on Jan 8 1998
// dunjia.c �ݼ�����
#include <ansi.h>
#include <sanguo.h>

inherit OBJ;
inherit M_GETTABLE;
inherit M_STUDYABLE;

string m_sk;
int m_lev;

int study_book()
{
  int p_res;
  string p_st;
  p_res=LEARNCHECK_D->check_can_learn_skills(m_sk,m_lev);
  this_body()->simple_action("$N����$o��ϸ�Ķ��˰��ʱ����\n",this_object());  
  switch(p_res)
  {
        case TOO_TIRED:
                this_body()->simple_action("$N���о����飬���˯�����۾�����������\n");
		break;
        case LESS_EXP:
                this_body()->simple_action("$N���鷭�˰��죬������᲻�����еİ��\n");
                break;
        case TOO_EASY:
                this_body()->simple_action("$N�����Ȿ��̫���ˡ�\n");
                break;
	case TOO_DIFFICULT:
		this_body()->simple_action("$N�����Ȿ��̫���ѡ�\n");
		break;
	case LESS_LITERATE:
		this_body()->simple_action("$N��ѧ�������㣬�޷���⣡\n");
		break;
	case 15:
		this_body()->simple_action("$N�ܻ����������ޣ�������ѧϰ���ּ����ˣ�\n");
		break;
        case CAN_LEARN:
                p_st=SG_SKILL_D->query_get(m_sk);
                this_body()->simple_action(p_st);
		DELAY_D->delay_simple_action(this_body(),"$N�����飬���ϰ���������������Żص�������ϡ�\n");
                break;
        default :
		SGSYS("return value from sk_learn_d is "+p_res);
                write("��֪Ϊʲô��ѧ���ᣬ������ʦ�ɡ�\n");
  }
  this_object()->remove();
  return 0;
}
void set_skill (string str) {
	m_sk=str;
}
void set_lev (int l) {
	m_lev=l;
}

void setup() {
    set_adj("װ����ϸ��");
    set_unit("��");
    set_size(VERY_SMALL);
    set_id("cang shu");
    set_long("һ��װ����ϸ�Ļ��Ҳ��飬��ҳ�Ѿ��е㷢�ơ�\n");
    set_study_action((: study_book :));
    set_gettable(1);
    set_can_drop(0);
    set_can_give(0);
}
