// this room is created by buzzer.c
// driver is �������
// created date is Fri May  6 22:02:27 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("wuguan");
set_light(50);
set_brief("%^YELLOW%^"+"��عؿ�"+"%^RESET%^");
set_long("");
set_exits( ([
"east":"/a/wuguan/wg_dalu.c",

"west":"/a/wuguan/wg_dadao.c",
 ]));
set_objects(([M_BOARD : ({ 1,"�ٱ���������صĳ��ſڡ�\n\n��ǽ�Ϲ���"+"%^MAGENTA%^"+"���������"+"%^RESET%^", "city.wuguan" }) ]) );
}
