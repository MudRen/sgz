// ��ͤ˧��
// jt_dzh.c
#include <mudlib.h>
#include <sanguo.h>
#include <ansi.h>
inherit INDOOR_ROOM;
void setup(){
    set_area("jieting");
    set_light(50);
    set_brief(""+YEL+"˧��"+NOR+"");
    set_long("   �����ǽ�ͤ�ؾ���߽���İ칫֮�������ʵ���ڴ�������ʿ��
��ǹ�����������϶ѻ���Ҫ������麯������˻˻������ʱ�о�ʿ��
�ʱ�������ս�顣\n\n");
    set_exits( ([
        "southwest" :  __DIR__+"jt_jying.c",
    ]) );
}




