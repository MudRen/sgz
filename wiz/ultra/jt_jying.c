// ��ͤ��Ӫ
// jt_jying.c
#include <mudlib.h>
#include <sanguo.h>
#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup(){
    set_area("jieting");
    set_light(50);
    set_brief(""+YEL+"��Ӫ"+NOR+"");
    set_long("  ��Ӫ������������������롣��ʿ�Ǿ����ӣ�ʱ�̱����ž��衣 
������˧�ʺ���������ʱ��ʱ�о�У���룬������顣
\n\n");
    set_exits( ([
        "south" :  __DIR__+"jt_area.c",
        "northwest" :  __DIR__+"jt_ysht.c",
        "northeast" :  __DIR__+"jt_shzhang.c",
    ]) );
}

