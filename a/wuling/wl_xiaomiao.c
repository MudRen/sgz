// this room is created by buzzer.c
// driver is 巴山夜雨
// created date is Sat May 28 19:57:10 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("wuling");
set_light(50);
set_brief("%^YELLOW%^"+"小庙"+"%^RESET%^");
set_long("
    这里是武陵小庙,院子中一个大水塘，塘中石龟石蛇，昂然盘踞。\n\n");
set_exits( ([
"west":"/a/wuling/wl_beijie2.c",
 ]));
}
