#include <mudlib.h>
#include <ansi.h>
#define BW_MASTER __DIR__"master.c"

inherit OUTDOOR_ROOM;

void setup(){
        set_light(50);
        set_brief(""+YEL+"�佫���Դ��"+NOR+"");
	set_long("    ��������佫���Եı����������ص��м�վ��һλ������ȵ���
��(master)����������������µ�Ӣ��һ�Ը��£���������Ҫ����
(ask master about join)��");
	set("no_fight", 1);
	set_objects(([
		BW_MASTER:1,
]));
}

