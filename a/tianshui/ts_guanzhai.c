// this room is created by buzzer.c
// driver is 花儿朵朵
// created date is Sun May  8 21:33:01 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("tianshui");
set_light(50);
set_brief("%^YELLOW%^"+"官宅"+"%^RESET%^");
set_long("
    一座富丽堂皇的大宅院出现在你的眼前，两头高大的石狮子镇住了大门
两侧。门外有官兵把守，戒备森严。门上挂着两个灯笼，赫然写着“韩”字。\n\n");
set_exits( ([
"west":"/a/tianshui/ts_beidajie.c",

"south":"/a/tianshui/ts_dongdajie.c",
 ]));
}
