// ��Ե��,marry_tang.c
#include <mudlib.h>
#include <sanguo.h>
#include <ansi.h>
inherit ROOM;
void setup(){
    set_light(1);
    set_brief(""+HIR+"��Ե��"+NOR+"");
    set_long("
    ������Ե�ã��������ܵ�����ص�ף������������������
�ĵ�̺���ſ�һֱ�̵����ã��ȴ�����һ������̤���������Ҹ�֮·��
��������һ��һ���ľ�ϯ��������������������ź������봦����
��һ�������Ű���úϵİٺϻ��������������������������۵�
�����û��ϵ����ϣ�Ц���е�ǣ�Ÿ����ߣ�ף����һ�Ե������ǡ�
\n\n");
    set_exits( ([
        "out" : __DIR__+"marry_gate.c",
	"enter" : __DIR__+"marry_fang.c",
    ]) );
   set_objects( ([
	"/sgdomain/npc/marry_yahuan.c" : 2,
]) );

}
