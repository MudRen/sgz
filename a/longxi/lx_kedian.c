// this room is created by buzzer.c
// driver is 花儿朵朵
// created date is Sat May  7 14:36:19 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("longxi");
set_light(50);
set_brief("%^YELLOW%^"+"客店"+"%^RESET%^");
set_long("
    这是一家陇西的客栈，门口挂着块匾，上书“客似云来”。据说是
米芾的墨宝。店小二里里一边招呼客人，一边大声介绍米芾和客栈的渊
源，神色甚为得意。墙上挂着一个牌子,想来不是什么墨宝，写的歪歪扭扭。\n\n");
set_exits( ([
"west":"/a/longxi/lx_beichenjie3.c",
 ]));
set_objects( (["/sgdomain/obj/other/bed.c" : 1]) );
}
