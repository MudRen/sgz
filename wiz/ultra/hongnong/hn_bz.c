/* hn_cc.c
** Coded by ����@LIMA
** Code generated with RoomMaker v0.9.1 coded by Onyx@RedDragon
** Do not remove this header.
*/

#include <ansi.h>

inherit OUTDOOR_ROOM;

void setup(){
   set_area("hn_area");
    set_light(50);
    set_brief(YEL+"��վ"+NOR);
    set_long(
"  �����ٱ���������,��������.һ�������ں�������.�Աߵ�����
��,վ��һ��װ����ȫ��Уξ,�ƺ���ѵ��ʲô��.Զ��һ��
С�����������ܹ���"
);
   set_room_state("valid_start");
    set_exits( ([
    "south" : __DIR__+"hn_dj2",
    ]) );
    set_objects( ([
    ]) );
}
