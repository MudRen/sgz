// this room is created by buzzer.c
// driver is 巴山夜雨
// created date is Sat May 28 19:42:38 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("wuling");
set_light(50);
set_brief("%^YELLOW%^"+"小屋"+"%^RESET%^");
set_long("
    这里是不知名的小屋,好像没有人住。屋子里家具，锅碗
都还在，只是蒙上了灰尘，大概主人参军打仗去了，为了抵御
日益强大的董卓国，官府开始拉壮丁募集士兵，造成很多村落
人丁稀少。\n\n");
set_exits( ([
"west":"/a/wuling/wl_nanjie2.c",
 ]));
}
