#include <ansi.h>
#define FARMER __DIR__"farmer.c"
#define SOIL   __DIR__"soil.c"

inherit OUTDOOR_ROOM;

void setup(){
        set_light(50);
	set_area("changan");
        set_brief("һƬ"+HIG+"������"+NOR+"��ũ��");
        set_long(@LONG
    һƬ�����͵�ũ�������ȥ�ǿ������߼ʵ�ׯ�ڡ�ũ��
�������ڵ������ţ����������и����ճɡ�
LONG);
	set_objects(([
		FARMER:1,
		SOIL  :1,
]));
        set("no_fight", 1);
}
