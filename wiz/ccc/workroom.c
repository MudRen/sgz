/* workroom.c
** Coded by �ϴ�@����־
** Code generated with RoomMaker v0.9.1 coded by Onyx@RedDragon
** Do not remove this header.
*/

#include <>

inherit ROOM;

void setup(){
    set_light(1);
    set_brief("�ϴ�Ļ����");
    set_long(
" ������������
�ϴ�������֪���ĺڰ�ͷͷ��ר��ɱ�˷Ż𣬶�ƶ�ø���������...
��Ȼ�����������Ǯ�˵Ļ���...."
);
    add_item("" , "");
    add_item("test?" , "????????");
    set_exits( ([
"enter" :  "/wiz/laoda/rooms/home",
"" :  "",
"out" :  "zhulin"
    ]) );
    set_objects( ([
"" :  0
    ]) );
}