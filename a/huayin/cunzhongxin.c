// this room is created by buzzer.c
// driver is �������
// created date is Thu Apr 28 23:17:04 2011
#include <mudlib.h>
#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("huayin");
set_light(50);
set_brief("%^YELLOW%^"+"С������"+"%^RESET%^");
set_long("
    ����С������ģ�����һֱ����һƬũ������Ͽ��Է���һ��
С�ӡ�������һ��С·������������һλ���ߵľ�����ƽʱ��������
ʲô��Ҫ���¶����������顣\n\n");
set_exits( ([
"south":"/a/huayin/xiaoxiang.c",

"north":"/a/huayin/lukou.c",

"west":"/a/huayin/xiaolu.c",

"east":"/a/huayin/vhall.c",
 ]));
}
