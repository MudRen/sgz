// this room is created by buzzer.c
// driver is °ÍÉ½Ò¹Óê
// created date is Sun May 29 12:59:30 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("xuchang");
set_light(50);
set_brief("%^YELLOW%^"+"Ð¡Î÷ºþ"+"%^RESET%^");
set_long("");
set_exits( ([
"north":"/a/xuchang/xc_linjiejiujia.c",

"south":"/a/xuchang/xc_balingqiao.c",

"east":"/a/xuchang/xc_qingxujiebei.c",
 ]));
}
