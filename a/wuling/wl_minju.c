// this room is created by buzzer.c
// driver is ��ɽҹ��
// created date is Sat May 28 19:40:58 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("wuling");
set_light(50);
set_brief("%^YELLOW%^"+"���"+"%^RESET%^");
set_long("
    �����������õģ������˸������\n\n");
set_exits( ([
"east":"/a/wuling/wl_nanjie1.c",
 ]));
}
