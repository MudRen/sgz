//  函谷关 by benben
// hangu_camp.c
#include <mudlib.h>
#include <sanguo.h>
#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup(){
    set_area("hangu");
    set_light(50);
    set_brief(""+YEL+"守关将士扎寨处"+NOR+"");
    set_long("    此处易守难攻，守关将士就驻扎在此。
\n\n");
    set_exits( ([
        "west" :  __DIR__+"hangu_meetingroom.c",
        "south" :  __DIR__+"hangu_guankou.c",
	"north" :  __DIR__+"hangu_exit.c",
    ]) );
}

