// this room is created by buzzer.c
// driver is 花儿朵朵
// created date is Sat May  7 14:36:47 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("longxi");
set_light(50);
set_brief("%^YELLOW%^"+"戏棚"+"%^RESET%^");
set_long("
    这里就是陇西戏棚，台上正唱着戏呢，你可以坐下来叫上一壶
茶，好好的做一次票友。台上那位演员虽不是名角，唱起戏来
倒也是有板有眼，让人心情一畅，偶然的不快顿时烟消云散。\n\n");
set_exits( ([
"south":"/a/longxi/lx_beichenjie3.c",
 ]));
}
