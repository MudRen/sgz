/*
** Code generated with RoomMaker v0.9.1 coded by Onyx@RedDragon
** Do not remove this header.
*/

#include <mudlib.h>
#include <ansi.h>
#include <sanguo.h>

inherit ROOM;

void setup(){
    set_area("vinegar_bottle");
    set_light(50);
    set_brief(GRN"��̳��"NOR);

    set_long("  
һ���տյĴ�̳�ӣ�����һ��������
");
    set_exits( ([
        "out" :  FROOMPATH+"vzhu_lin.c",
        "zatan" : __DIR__+"chatroom.c", 
    ]) );
}
