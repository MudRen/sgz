/* workroom.c
** Coded by �ϴ�@����־
** Code generated with RoomMaker v0.9.1 coded by Onyx@RedDragon
** Do not remove this header.
*/


inherit ROOM;

void setup(){
    set_light(10000);
    set_brief("�ϴ�Ļ����");
    set_long(
"����ʲôҲû�С��տյ����ġ�"
);
    add_item("paper" , "һ��СֽƬ��");
    set_exits( ([
"enter" :  "/wiz/laoda/rooms/home",
"dgc"   :  "/wiz/fire/room/vdagu_chang",
"out" :  "/wiz/fire/room/vzhu_lin"
    ]) );
    set_objects( ([
    ]) );
}
