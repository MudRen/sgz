// this room is created by buzzer.c
// driver is ª®∂˘∂‰∂‰
// created date is Fri Jul 29 10:35:20 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("xiangyang");
set_light(50);
set_brief("%^YELLOW%^"+"œ„÷ÚµÍ"+"%^RESET%^");
set_long("");
set_exits( ([
"west":"/a/xiangyang/xy_tuzhaichang.c",

"east":"/a/xiangyang/xy_tianchijie3.c",
 ]));
}
