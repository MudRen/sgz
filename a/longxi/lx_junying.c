// this room is created by buzzer.c
// driver is 花儿朵朵
// created date is Sat May  7 13:52:43 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("longxi");
set_light(50);
set_brief("%^YELLOW%^"+"军营"+"%^RESET%^");
set_long("
    这里是陇西的驻军大营。这里几乎没有行人进进出出的多是官兵，不时也有
武林人物进出，门口有两个士兵在站岗，好象一般的人是不让进出的。\n\n");
set_exits( ([
"south":"/a/longxi/lx_xiaochang.c",

"north":"/a/longxi/lx_qianmendajie3.c",
 ]));
}
