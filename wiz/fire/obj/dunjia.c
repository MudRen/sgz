// by fire on Jan 8 1998
// dunjia.c �ݼ�����
#include <ansi.h>
#include <sanguo.h>
inherit OBJ;
inherit M_GETTABLE;
inherit M_STUDYABLE;
int study_book()
{
  int p_res;
  string p_st;
  p_res=LEARNCHECK_D->check_can_learn_skills("qmdj",30);
  switch(p_res)
  {
        case TOO_TIRED:
		this_body()->simple_action("$N���о����Ŷݼף����˯�����۾�����������\n");
                return 0;
	case LESS_EXP:
                this_body()->simple_action("$N���鷭�˰��죬������᲻�����еİ��\n");
                return 0;
        case TOO_EASY:
                this_body()->simple_action("$N�����Ȿ��̫���ˡ�\n");
                return 0;
        case CAN_LEARN:
                p_st=SG_SKILL_D->query_get("qmdj");
                this_body()->simple_action(p_st);
                return 1;
        default :
                write("��֪Ϊʲô��ѧ���ᣬ������ʦ�ɡ�\n");
  }
  return 0;
}
void setup() {
    set_adj("���ò�����");
    set_unit("��");
    set_id("book", "���ݼ����顷��һ��");
    set_long("һ�����ò������飬����ȥ������ͷ�ˡ�\n");
    set_getmsg("$N �������飬������˫�ַ���"); 
    set_study_action((: study_book :));
    set_gettable(1);
}
