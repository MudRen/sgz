// this room is created by buzzer.c
// driver is ��ɽҹ��
// created date is Mon May 30 21:04:13 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("chaisang");
set_light(50);
set_brief("%^YELLOW%^"+"��Ӫ"+"%^RESET%^");
set_long("");
set_exits( ([
"west":"/a/chaisang/cs_xiaochang.c",

"east":"/a/chaisang/cs_yishiting.c",

"south":"/a/chaisang/cs_beijiedong.c",
 ]));
set_objects(([M_BOARD : ({ 1,"����İ��ľ����������Ҵ��£�����ȥ��\n\nľ���Ϲ��� "+"%^MAGENTA%^"+"��ɣ���԰�"+"%^RESET%^", "city.chaisang" }) ]) );
}
