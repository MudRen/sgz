// this room is created by buzzer.c
// driver is �������
// created date is Mon Jul 25 23:32:09 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("chibi");
set_light(50);
set_brief("%^YELLOW%^"+"У��"+"%^RESET%^");
set_long("");
set_exits( ([
"east":"/a/chibi/cb_daokou.c",

"west":"/a/chibi/cb_xiaolu.c",
 ]));
}
