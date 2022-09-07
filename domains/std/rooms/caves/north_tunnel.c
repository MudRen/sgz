// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

#include <mudlib.h>

inherit ROOM;

void setup()
{
    set_area("pirate");
    set_brief("���ص�");
    set_long("��������ͨ�����Ҷ�һֱ�򱱣�ͨ��Զ����");

    set_objects( (["/domains/std/objects/gate.c":  ({ "south" }) ]) );

    set_exits( ([
        "south" : "/domains/std/rooms/caves/north_cave.c"
        ]) );

    set_state_description("gate_open_off", "������һ�������˵����ţ��������š�");
    set_state_description("gate_open_on", " \n������һ�������˵����ţ�����б���š�");
}
