// this room is created by buzzer.c
// driver is ��ɽҹ��
// created date is Mon May 30 19:08:35 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("nanpi");
set_light(50);
set_brief("%^YELLOW%^"+"������"+"%^RESET%^");
set_long("");
set_exits( ([
"east":"/a/nanpi/np_wuku.c",

"west":"/a/nanpi/np_liangcang.c",
 ]));
set_objects(([M_BOARD : ({ 1,"ǽ�Ϲ���һ��"+"%^MAGENTA%^"+"��Ƥ���԰�"+"%^RESET%^", "city.nanpi" }) ]) );
}
