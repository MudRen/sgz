// this room is created by buzzer.c
// driver is 花儿朵朵
// created date is Sun May  8 21:15:23 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("tianshui");
set_light(50);
set_brief("%^YELLOW%^"+"西城门"+"%^RESET%^");
set_long("
    这是天水城的西城门，由于这里的环境干燥，经过几年的风沙侵蚀显得有些
破败。城门正上方勉勉强强可以认出“西门”两个大字。许多来边疆做苦力的罪犯
常常经过这里逃回中原，官兵们戒备森严，动不动就截住行人进行盘问。一条笔直
的青石大道向东西两边延伸。西边是郊外，一直向西去就是陇西,许多本地人赶着
牲口从这里经过，到城里去卖掉自己种的瓜果，再买回生活必需品。东边是城里。\n\n");
set_exits( ([
"east":"/a/tianshui/ts_xidajie.c",
 ]));
}
