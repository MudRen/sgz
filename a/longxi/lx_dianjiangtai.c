// this room is created by buzzer.c
// driver is 花儿朵朵
// created date is Sat May  7 13:57:57 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("longxi");
set_light(50);
set_brief("%^YELLOW%^"+"点将台"+"%^RESET%^");
set_long("
    这里是陇西点将台,中间一座高台边上插满旌旗,在高台上摆着一个香案，
由于没有战事,这里显得极为空旷,只有几个陇西官兵站在东面路口。\n\n");
set_exits( ([
"east":"/a/longxi/lx_qianmendajie5.c",
 ]));
}
