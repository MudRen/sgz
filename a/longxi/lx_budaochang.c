// this room is created by buzzer.c
// driver is 花儿朵朵
// created date is Sat May  7 12:17:31 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("longxi");
set_light(50);
set_brief("%^YELLOW%^"+"布道场"+"%^RESET%^");
set_long("
    这里是太平道的布道场，大贤良师张角正站在道场中央
对着陇西民众说："+"%^MAGENTA%^"+"苍天已死，黄天当立，岁在甲子，天下大吉"+"%^RESET%^"+"。
几队头扎黄巾的勇士正神色紧张的守着西面的路口。\n\n");
set_exits( ([
"west":"/a/longxi/lx_dounanjie2.c",
 ]));
}
