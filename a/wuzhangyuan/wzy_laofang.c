// this room is created by buzzer.c
// driver is �������
// created date is Fri May  6 15:09:47 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("wuzhangyuan");
set_light(50);
set_brief("%^YELLOW%^"+"�η�"+"%^RESET%^");
set_long("");
set_exits( ([
"north":"/a/wuzhangyuan/wzy_dalu2.c",
 ]));
set_objects( (["/sgdomain/prison/yuzu.c" : 1 ]) );
}
