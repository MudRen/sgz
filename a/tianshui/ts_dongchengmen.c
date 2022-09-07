// this room is created by buzzer.c
// driver is 花儿朵朵
// created date is Sun May  8 21:12:15 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("tianshui");
set_light(50);
set_brief("%^YELLOW%^"+"东城门"+"%^RESET%^");
set_long("
    这是天水城的东城门，由于这里的环境干燥，经过几年的风沙侵蚀显得有些
破败。城门正上方勉勉强强可以认出“东门”两个大字。许多来边疆做苦力的罪犯
常常经过这里逃回中原，官兵们戒备森严，动不动就截住行人进行盘问。一条笔
直的青石大道向东西两边延伸。东边是郊外，许多西域来的商人都从这里出城，
向东到达秦川。西边是城里。\n\n");
set_exits( ([
"west":"/a/tianshui/ts_dongdajie.c",
 ]));
}
