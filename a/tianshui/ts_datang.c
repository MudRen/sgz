// this room is created by buzzer.c
// driver is 花儿朵朵
// created date is Sun May  8 21:42:03 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("tianshui");
set_light(50);
set_brief("%^YELLOW%^"+"大堂"+"%^RESET%^");
set_long("
    堂上东西有两根楹住，挂着一幅对联，但是你无心细看。正墙上悬挂
一个横匾，上书“正大光明”四个金光闪闪的大字。知府正坐在文案后批
阅文书，师爷随侍在后，一帮衙役正分立两旁，在此有什么冤情你可以直
接向知府大人诉说。\n\n");
set_exits( ([
"east":"/a/tianshui/ts_yamen.c",
 ]));
}
