// this room is created by buzzer.c
// driver is ��ɽҹ��
// created date is Mon May 30 20:55:19 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
inherit STORE;

void setup() {
set_area("chaisang");
set_light(50);
set_brief("%^YELLOW%^"+"С�ƹ�"+"%^RESET%^");
set_long("");
set_exits( ([
"east":"/a/chaisang/cs_nanjiexi.c",
 ]));
set_objects((["/sgdomain/obj/other/board.c" : ({ 1,"��ɣ�ľƹݣ��ſڹ���һ�ײ����ơ������ơ�list�г���Ʒ��buy����\nԺ����һ�ھ��������ľ�ˮ���Թൽˮ���\n\n"}) ]) );

add_object("/sgdomain/obj/foodanddrink/mantou.c");
add_object("/sgdomain/obj/foodanddrink/ypjd.c");

set_objects( (["/sgdomain/obj/other/well.c" : 1]) );
}
