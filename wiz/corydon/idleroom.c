/* idleroom.c
** Coded by ����@����
** Code generated with RoomMaker v0.9.1 coded by Onyx@RedDragon
** Do not remove this header.
*/

#include <ansi.h>

inherit INDOOR_ROOM;



void setup(){
        object door;
    set_light(50);
    set_area("westside");
        set_brief(""+YEL+"������"+NOR+"");
    set_long("
    �����ƺ������˵��鷿�����ң�������������һ�㶼����Ϊ����
���Ҹ�λ����ͷ�ۼ����ӣ���Ϊ���˵���ǰ�������֮�⣬�����ط�
������ط���Щ������������һ������ܣ���������Ѿ������˺��
�Ļҳ����ɼ��˼������Ѿ�δ�����ˡ�����Ա���һ�Ŵ�����������
���ŵ��ԡ���ӡ��֮��Ķ�����
\n\n");
    set_exits( ([
        "down" : __DIR__+"ex_room.c",
        "goup" : __DIR__+"workroom.c",
    ]) );
    set_enter_msg("idleroom","\n$Nһ��С�����˽������ŷ����Լ�������һ�����ҡ�\n\n");
    set_objects( ([
//         __DIR__"obj/idle_door" : ({ "goup" }), // has bugs fix it please :)
    ]) );
  set_default_exit( "\n�ź���û�п����ʲô�ɻ���\n\n");
  door = present( "door");
  if(!objectp(door)) return ;
  if( !door->query_closed())
  door->do_on_open();
}
