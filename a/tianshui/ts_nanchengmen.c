// this room is created by buzzer.c
// driver is 花儿朵朵
// created date is Sun May  8 21:44:17 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("tianshui");
set_light(50);
set_brief("%^YELLOW%^"+"南城门"+"%^RESET%^");
set_long("
    这是天水城的南城门，由于这里的环境干燥，经过几年的风沙侵蚀显得有些
破败。城门正上方勉勉强强可以认出“南门”两个大字。官兵们戒备森严，动不动
就截住行人进行盘问。一条笔直的青石大道向南北两边延伸。南边是郊外，一些
西域来的商人都从这里出城，向南到达下弁。北边是城里。\n\n");
set_objects((["/sgdomain/modules/m_charnpc/guard.c":1]));
}
