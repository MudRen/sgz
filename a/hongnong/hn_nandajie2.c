// this room is created by buzzer.c
// driver is �������
// created date is Wed Jun 15 20:06:26 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("hongnong");
set_light(50);
set_brief("%^YELLOW%^"+"�ϴ��"+"%^RESET%^");
set_long("");
set_exits( ([
"north":"/a/hongnong/hn_chengzhongxin.c",

"east":"/a/hongnong/hn_yishiting.c",

"west":"/a/hongnong/hn_kezhan.c",

"south":"/a/hongnong/hn_nandajie1.c",
 ]));
}
