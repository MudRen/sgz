// this room is created by buzzer.c
// driver is �������
// created date is Wed Jun 15 20:15:08 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("hongnong");
set_light(50);
set_brief("%^YELLOW%^"+"������"+"%^RESET%^");
set_long("");
set_exits( ([
"north":"/a/hongnong/hn_datang.c",
"west":"/a/hongnong/hn_nandajie2.c",
 ]));
set_objects(([M_BOARD : ({ 1,"ǽ�Ϲ���"+"%^MAGENTA%^"+"��ũ���԰�"+"%^RESET%^", "city.hongnong" }) ]) );
}
