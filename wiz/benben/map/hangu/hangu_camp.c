//  ���ȹ� by benben
// hangu_camp.c
#include <mudlib.h>
#include <sanguo.h>
#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup(){
    set_area("hangu");
    set_light(50);
    set_brief(""+YEL+"�عؽ�ʿ��կ��"+NOR+"");
    set_long("    �˴������ѹ����عؽ�ʿ��פ���ڴˡ�
\n\n");
    set_exits( ([
        "west" :  __DIR__+"hangu_meetingroom.c",
        "south" :  __DIR__+"hangu_guankou.c",
	"north" :  __DIR__+"hangu_exit.c",
    ]) );
}

