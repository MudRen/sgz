/* tg_jg.c
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
    set_brief(HIY+"�ƹ�"+NOR);
    set_long(
"    ����һ��С�ƹݡ�����Ļ�����д��һ�����ġ��ơ��֡��ſ�
����һ������(pai zi)���������ֱ�ǽ�Ϲ���һ������������С����
��  �Ͼ����˶ࡱ������������д�ģ���Ҳ�м��ֲ�����\n"
);
    add_item("pai zi" , "���տ��ţ���ʱ������٣�\n");
    set_exits( ([
HIG+"north"+NOR :  "tg_c1.c"
    ]) );
    set_objects( ([
    ]) );
}
