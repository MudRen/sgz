// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

// Belboz

#include <daemons.h>
#include <mudlib.h>

inherit CMD;

private void main()
{
    int         pts,total;
    string      rank;

    if( wizardp(this_user()) )
    {
        out("����һλ�����Ա��\n");
    }

    pts = this_body()->query_score();
    total = QUEST_D->total_points();
    if(total)
      switch( (100*pts)/total )
        {
        case 0:  rank = "��ȫ����";break;
        case 1..5: rank = "ҵ�మ����";break;
        case 6..10: rank = "����ѡ��";break;
        case 11..20: rank = "����ѡ��";break;
        case 21..30: rank = "����̽�ռ�";break;
        case 31..40: rank = "�м�̽�ռ�";break;
        case 41..50: rank = "�߼�̽�ռ�";break;
        case 51..60: rank = "ð�ռ�";break;
        case 61..70: rank = "רҵð�ռ�";break;
        case 71..80: rank = "���������";break;
        case 81..90: rank = "��ȫ�����";break;
        case 91..99: rank = "���������";break;
        default:
          if(pts < 0 ) rank = "�����С��";
          else rank = "���ɴ���";
    }
    if(total)
      outf("��%s�У���� %d �����õ��� %d �֣������ǣ�%s��\n", 
           mud_name(), total, pts, rank );
    else
      outf("��%s�и���û�з��������������㻹�ɵò���\n", mud_name());
}
