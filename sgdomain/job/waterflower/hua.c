#include <mudlib.h>
#include <ansi.h>
#include <bodyslots.h>

inherit M_GETTABLE;
inherit M_WEARABLE;
inherit M_VALUE;
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
	set_gettable(1);
        set_slot(HEAD);
        set_wearmsg("$N���Ὣ$o�������ԣ���ȻһЦ��\n");
        set_removemsg("$Nȡ�����Ե�$o����������Ʈɢ��һ縳�������\n");
	set_size(1);
	set_attack_ability(0);
 	set_defence_power(0);
        set_defence_ability(0);
        set_rongmao(5);
	return;
}

string long()
{
	return "����ĵ������������������ĵ������������\n";
}
