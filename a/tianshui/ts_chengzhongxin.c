// this room is created by buzzer.c
// driver is 花儿朵朵
// created date is Sun May  8 21:12:49 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("tianshui");
set_light(50);
set_brief("%^YELLOW%^"+"城中心"+"%^RESET%^");
set_long("
    这里是天水城的正中心，有一个很宽阔的广场，由于这里风沙很大，所以
铺着青石的地面经常铺着一层黄沙。一些游手好闲的人在这里溜溜达达，经常有
一些西域艺人在这里表演。这里人声鼎沸，许多小贩争着向行人兜售着自己的商
品，一派热闹景象。\n\n");
set_exits( ([
"north":"/a/tianshui/ts_beidajie.c",

"south":"/a/tianshui/ts_nandajie.c",

"west":"/a/tianshui/ts_xidajie.c",

"east":"/a/tianshui/ts_dongdajie.c",
 ]));
set_objects(([M_BOARD : ({ 1,"这里是天水的中心广场。\n\n路边竖立着一个"+"%^MAGENTA%^"+"天水布告栏"+"%^RESET%^", "city.tianshui" }) ]) );
}
