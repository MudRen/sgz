// this room is created by buzzer.c
// driver is 花儿朵朵
// created date is Sun May  8 21:17:33 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("tianshui");
set_light(50);
set_brief("%^YELLOW%^"+"议事厅"+"%^RESET%^");
set_long("
    这里是天水议事厅,见居中一张太师椅，上铺虎皮，一人正悠闲地倚於椅上，两旁
各有小妾正为他槌胸揉背。虎皮椅旁有两座大理石屏风，都有五六丈高，石上山水木碑，
便如画出来的一般。这本是太守审理军政民政及监察事务所在，但没人之时，便成了
暂且神游物外的安乐窝。\n\n");
set_exits( ([
"south":"/a/tianshui/ts_junying.c",
 ]));
}
