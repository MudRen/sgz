// this room is created by buzzer.c
// driver is 巴山夜雨
// created date is Sat May 28 19:35:20 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("wuling");
set_light(50);
set_brief("%^YELLOW%^"+"南门"+"%^RESET%^");
set_long("
    这里是武陵的南门, 有两个官兵正守在门口,盘查过往商客。\n\n");
set_objects((["/sgdomain/modules/m_charnpc/guard.c":1]));
}
