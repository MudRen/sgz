// this room is created by buzzer.c
// driver is 花儿朵朵
// created date is Thu May 26 21:57:30 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("jiangling");
set_light(50);
set_brief("%^YELLOW%^"+"大堂"+"%^RESET%^");
set_long("
    这里是江陵大堂,专门审犯人的地方,两旁站着威武
的衙役。\n\n");
set_exits( ([
"east":"/a/jiangling/jl_jianyu.c",

"north":"/a/jiangling/jl_yamen.c",
 ]));
}
