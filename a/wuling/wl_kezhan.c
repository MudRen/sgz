// this room is created by buzzer.c
// driver is ��ɽҹ��
// created date is Sat May 28 19:49:06 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("wuling");
set_light(50);
set_brief("%^YELLOW%^"+"��ջ"+"%^RESET%^");
set_long("
    ����һ�Ҽ�Ǯ�����Ŀ�ջ����Ϊ�ط�ƫƧ�����ͺ��١�\n\n");
set_exits( ([
"north":"/a/wuling/wl_xiaolu1.c",

"south":"/a/wuling/wl_xiaochang.c",
 ]));
set_objects( (["/sgdomain/obj/other/bed.c" : 1]) );

}
