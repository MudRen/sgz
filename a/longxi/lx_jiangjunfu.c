// this room is created by buzzer.c
// driver is 花儿朵朵
// created date is Sat May  7 12:20:17 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("longxi");
set_light(50);
set_brief("%^YELLOW%^"+"将军府"+"%^RESET%^");
set_long("
    这里是陇西的将军府，平时陇西军士议事也是在这里,
公案后端坐着一个威猛的将军，但一脸疲惫，看来征战刚归的模样。
大堂两边摆着兵器架，架上锋刃仍留血迹，映着架后的战旗，分外
耀眼。两班将佐，虽征尘未洗，但斗志昂扬，甚是雄壮。\n\n");
set_exits( ([
"east":"/a/longxi/lx_dounanjie3.c",
 ]));
}
