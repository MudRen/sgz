/* tg_zjz.c
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
    set_brief(HIY+"�о�����"+NOR);
    set_long(
"    �����������ععٽ����µĵط���\n"
);
    set_exits( ([
HIG+"south"+NOR :  "tg_c2.c"
    ]) );
    set_objects( ([
    ]) );
}
