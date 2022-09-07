// this room is created by buzzer.c
// driver is ª®∂˘∂‰∂‰
// created date is Sun Jul 17 23:22:56 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("gongan");
set_light(50);
set_brief("%^YELLOW%^"+"Õ¡µÿ√Ì"+"%^RESET%^");
set_long("");
set_exits( ([
"south":"/a/gongan/ga_liangcang.c",

"north":"/a/gongan/ga_shaiguchang.c",
 ]));
}
