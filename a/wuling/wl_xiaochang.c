// this room is created by buzzer.c
// driver is ��ɽҹ��
// created date is Sat May 28 19:48:06 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("wuling");
set_light(50);
set_brief("%^YELLOW%^"+"У��"+"%^RESET%^");
set_long("
    ����������У��,һ���Źٱ�����У���ϲ���,��ɱ���졣\n\n");
set_exits( ([
"north":"/a/wuling/wl_kezhan.c",

"south":"/a/wuling/wl_cunzhongxin.c",
 ]));
}
