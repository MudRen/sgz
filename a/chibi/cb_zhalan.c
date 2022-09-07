// this room is created by buzzer.c
// driver is »¨¶ù¶ä¶ä
// created date is Mon Jul 25 23:31:37 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("chibi");
set_light(50);
set_brief("%^YELLOW%^"+"Õ¤À¸"+"%^RESET%^");
set_long("");
set_exits( ([
"north":"/a/chibi/cb_xiaolu.c",
 ]));
}
