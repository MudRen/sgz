// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

#include <mudlib.h>
inherit ROOM;

void setup() {
    set_brief("��¥");
    set_long("��������ʦ�����ĸ�¥���յ�����...");
    set_exits( ([
                 "down" : "/domains/std/wizroom.c"
    ]) );
    set_objects( ([
           STAIRS : ({ 1, 0, "/domains/std/wizroom" }),
           "/domains/std/magic_flame" : 1
    ]) );
}
