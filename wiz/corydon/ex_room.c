/* ex_room
** Coded by ����@����־��վ
** Code generated with RoomMaker v0.9.1 coded by Onyx@RedDragon
** Do not remove this header.
*/
#include <ansi.h>


inherit ROOM;

void setup(){
    set_light(50);
        set_brief(""+YEL+"չ����"+NOR+"");
    set_long(
"\n    �����ǼҾ�չ�����������ڵĶ��ǼҾߡ�\n\n",
);
    set_exits( ([
"up" :  "/wiz/corydon/idleroom",
"hell":"/wiz/corydon/gate",
    ]) );
    set_objects( ([
"/wiz/ice/obj/furniture/hmbed.c":1,
"/wiz/ice/obj/furniture/szbed.c":1,
"/wiz/ice/obj/furniture/xmkbed.c":1,
"/wiz/ice/obj/furniture/xmbed.c":1,
"/wiz/ice/obj/furniture/ztbed.c":1,
"/wiz/ice/obj/furniture/bed.c":1,
"/wiz/ice/obj/furniture/sofa.c":1,
    ]) );
}
