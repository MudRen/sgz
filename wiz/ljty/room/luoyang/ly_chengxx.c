//  ������
// ly_chengxx.c decribed by ljty on 1.8.1998
#include <mudlib.h>
#include <sanguo.h>
#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup(){
    set_area("ly_area");
    set_light(50);
    set_brief(""+YEL+"������"+NOR+"");
    set_long("    ��������������һ��С���ӣ����߻��ӡ�������һ�Ҷĳ�������
���ⶼ��첽�뿪��Ω��������۵Ķ�ͽ����Ǯ�ơ�
\n\n");
    set_exits( ([
        "north" :  __DIR__+"ly_xdj3.c",
        "south" :  __DIR__+"ly_chengxx2.c",
        "west" :  __DIR__+"ly_duc.c",
    ]) );
}
