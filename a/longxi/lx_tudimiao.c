// this room is created by buzzer.c
// driver is 花儿朵朵
// created date is Sat May  7 14:39:27 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("longxi");
set_light(50);
set_brief("%^YELLOW%^"+"土地庙"+"%^RESET%^");
set_long("
    这是一间十分破旧的土地庙，也不知荒废了多久，梁上地下布满了
灰尘。土地神像後面的墙上有个洞口，老鼠爬进爬出，恶心极了。\n\n");
set_exits( ([
"south":"/a/longxi/lx_xiaoxiang3.c",
 ]));
}
