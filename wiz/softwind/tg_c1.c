/* tg_c1.c
** Coded by �ͷ�@����־
** Code generated with RoomMaker v0.9.1 coded by Onyx@RedDragon
** Do not remove this header.
*/

#include <ansi.h>
#include <mudlib.h>
#include </wiz/fire/fire.h>

inherit ROOM;

void setup(){
    set_light(1);
    set_brief(YEL+"���ؽ���"+NOR);
    set_long(
"    ������Ѿ����������ˡ��ӹؿڽ�������ֻ����ôһ��С�֡���
������ϡ�٣�����Ҳ������һ�������ϱ���һ����ջ����Ϊ���صش�
�վ�����·���У���·�˶��ڴ˹�ҹ���������������عؿڡ��Ӵ���
�������͵��������ˡ�\n"
);
    set_exits( ([
HIG+"west" :  "tg_c2.c",
"east" :  "tg_gk.c",
"south"+NOR :  "tg_jg.c"
    ]) );
    set_objects( ([
    ]) );
}
