// this room is created by buzzer.c
// driver is 花儿朵朵
// created date is Sat May  7 13:50:03 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("longxi");
set_light(50);
set_brief("%^YELLOW%^"+"玉真楼"+"%^RESET%^");
set_long("
    你坐在陇西最豪华的玉真楼上，看着楼下的凡人忙忙碌碌，心情很是
愉快，所谓“对酒当歌，人生几何”，还犹豫什么，尽情享受生活吧！\n\n");
set_exits( ([
"south":"/a/longxi/lx_qianmendajie2.c",
 ]));
}
