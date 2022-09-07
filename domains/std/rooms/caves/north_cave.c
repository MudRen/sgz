// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

#include <mudlib.h>

inherit ROOM;


void setup()
{
    set_area("pirate");
    set_brief( "���Ҷ�" );

    set_long ("�����Ƕ�Ѩ�ı��棬һ���������С�Ӵ��Ϸ���������������������ұڳ��м伷ѹ�������ƺ���ʲô�����Ԥ�ס�");

    set_objects( (["/domains/std/objects/gate": ({ "north" })]) );

    add_item("wall", "�������ʯ�Ǻ���ͨ��һ�֣�û��ʲô�ر�ġ�");
    set_exits( ([
        "north" : "/domains/std/rooms/caves/north_tunnel.c",
        "south" : "/domains/std/rooms/caves/inside_cave.c",
        ]) );

    set_state_description("gate_open_off", "�����һ��������������ƺ���ס�˵ص�����ڡ�\n");

    set_state_description("gate_open_on", "�����һ����������ţ��������ţ�¶����һ���ص�����ڡ�\n");
}
