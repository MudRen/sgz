// this room is created by buzzer.c
// driver is 花儿朵朵
// created date is Sat May  7 13:55:51 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("longxi");
set_light(50);
set_brief("%^YELLOW%^"+"粮仓"+"%^RESET%^");
set_long("
    这里是陇西的粮仓，堆放着堆积如山的军粮，逢到旱涝灾年也做济灾
之用。由于仓广人少，经常引起匪徒的窥视。\n\n");
set_exits( ([
"north":"/a/longxi/lx_qiandajie4.c",
 ]));
}
