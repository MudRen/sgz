// this room is created by buzzer.c
// driver is ��ɽҹ��
// created date is Thu Jun  2 20:52:38 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("poyang");
set_light(50);
set_brief("%^YELLOW%^"+"�Ͻ�"+"%^RESET%^");
set_long("");
set_exits( ([
"north":"/a/poyang/py_naoshi.c",

"east":"/a/poyang/py_xiaoxiang.c",

"south":"/a/poyang/py_nanmenkou.c",

"west":"/a/poyang/tmp.c",
 ]));
}
