#include <mudlib.h>
#include <ansi.h>

inherit OBJ;
inherit M_GETTABLE;
string *sname=({HIR"��",HIY"��",HIB"��",HIG"��",HIW"��",HIM"��",});
string *adjtive=({"�����","Ӻ�ݵ�","������","������","���׵�","���ߵ�",
"���ŵ�","�����","���ĵ�"});

void setup()
{	
	string name=sname[random(sizeof(sname))]+"ĵ��"NOR;
        string adjt=adjtive[random(sizeof(adjtive))];
	set_id("flower", name);
	set_unit("��");
	set_adj(adjt);
	return;
}

string long()
{
	return "����ĵ������������������ĵ������������\n";
}
