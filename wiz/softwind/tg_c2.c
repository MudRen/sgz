/* tg_c2.c
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
������ϡ�٣�����Ҳ������һ����������������פ�����µ��о��ʡ�
�ϱ��Ǿ�Ӫ���������������عؿڡ��Ӵ����������͵��������ˡ�\n"
);
    set_exits( ([
HIG+"west" :  "",
"east" :  "tg_c1.c",
"north" :  "tg_zjz.c",
"south" :  "tg_jy.c"+NOR
    ]) );
    set_objects( ([
    ]) );
}
