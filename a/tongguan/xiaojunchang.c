// this room is created by buzzer.c
// driver is �������
// created date is Sun May  1 23:07:48 2011
#include <mudlib.h>
#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("tongguan");
set_light(50);
set_brief("%^YELLOW%^"+"У����"+"%^RESET%^");
set_long("");
set_exits( ([
"south":"/a/tongguan/dalu_right.c",
 ]));
set_objects(([M_BOARD : ({ 1,"У������һԱ�佫��ѵ��ʿ�����ų����ֽ������͡�\n\n��ڴ�����һ��"+"%^MAGENTA%^"+"����������"+"%^RESET%^", "city.tongguan" }) ]) );
}
