// this room is created by buzzer.c
// driver is 花儿朵朵
// created date is Sun May  8 21:32:23 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("tianshui");
set_light(50);
set_brief("%^YELLOW%^"+"北城门"+"%^RESET%^");
set_long("
    这是北城门，由于北方的环境恶化，经过几年的风沙侵蚀显得有些破败。
城门正上方勉勉强强可以认出“北门”两个大字，官兵们戒备森严，动不动就截住行人
盘问。一条笔直的青石板大道向南北两边延伸。北边是郊外，骑马的、坐轿
的、走路的，行人匆匆。南边是城里。\n\n");
set_exits( ([
"south":"/a/tianshui/ts_beidajie.c",
 ]));
}
