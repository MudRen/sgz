// ��ͤС�� modified by row
// jt_xd1.c

#include <mudlib.h>
#include <sanguo.h>
#include <ansi.h>
inherit OUTDOOR_ROOM;

void setup(){
	set_area("jieting");
	set_light(50);
	set_brief(""+YEL+"С��"+NOR+"");
	set_long("
    һ��������С�����������ˡ������Ϸ�����ȥ����Լ���Կ���һ
����·������ͨ����ˮ�ıؾ�֮·����������ˮ��������봨�ˡ���
���濿������һ��Сɽ��ɽ��פ����һ��Ӫկ�����Ʈ��������
����Ҫ�ء���ͤ����\n\n");
	set_exits( ([
	"east" :  __DIR__+"jt_yz.c",
"southwest" : __DIR__+"jt_yizhan.c",
	"north" : __DIR__+"jt_sl.c",
	]) );
}
