/* tg_gk.c
** Coded by �ͷ�@����־
** Code generated with RoomMaker v0.9.1 coded by Onyx@RedDragon
** Do not remove this header.
*/

#include <mudlib.h>
#include </wiz/fire/fire.h>
#include <ansi.h>

inherit ROOM;

void setup(){
   set_area("tongguan");
    set_light(1);
    set_brief(YEL+"���عؿ�"+NOR);
    set_long(
"   ����������صĹؿڡ������������Ĺذ��صأ������������룬
��ʮ�����ǽ������֮�գ�����μ���壬��ƺӱ��ض���֮Ҫ������
��ɽ�����ӣ������¾�����ͨ��С��������һ��һ�������䣬
�������£�����������ն������"

);
    set_exits( ([
HIG+"home" :  "wiz/softwind/workroom.c",
"west"+NOR : "/wiz/softwind/tg_c1.c"
    ]) );
    set_objects( ([
    ]) );
}
