// this room is created by buzzer.c
// driver is 花儿朵朵
// created date is Sat May  7 13:57:15 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("longxi");
set_light(50);
set_brief("%^YELLOW%^"+"角力场"+"%^RESET%^");
set_long("
    这里是陇西角力场,只见中间围着一圈陇西官兵,中间一个高大个的官兵正和
一个瘦少的官兵在比赛,一伙官兵在给瘦少的官兵加油助威。边上摆着一排木质兵
器，供官兵角力使用。\n\n");
set_exits( ([
"north":"/a/longxi/lx_qianmendajie5.c",
 ]));
}
