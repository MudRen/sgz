// this room is created by buzzer.c
// driver is ��ɽҹ��
// created date is Sat May 28 19:46:46 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("wuling");
set_light(50);
set_brief("%^YELLOW%^"+"�㽫̨"+"%^RESET%^");
set_long("
    ����������ĵ㽫̨,�ഫ��̫��������������\n\n");
set_exits( ([
"north":"/a/wuling/wl_cunzhongxin.c",
 ]));
}
