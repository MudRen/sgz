// this room is created by buzzer.c
// driver is 花儿朵朵
// created date is Sat May  7 13:49:23 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("longxi");
set_light(50);
set_brief("%^YELLOW%^"+"东城门"+"%^RESET%^");
set_long("
    这是凉州重镇陇西的东城门，城墙上刻着诺大的「"+"%^MAGENTA%^"+"陇西"+"%^RESET%^"+"」
两个楷书大字,城墙上贴着几张官府告示。官兵们警惕地注视着过往行人，
你最好小心为妙。一条笔直的青石板大道向西延伸，西边是前门大街。\n\n");
set_objects((["/sgdomain/modules/m_charnpc/guard.c":1]));
}
