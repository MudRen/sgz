/* RoomMaker.c
**Coded by �����
** Do not remove this header.
*/

#include <mudlib.h>
#include <ansi.h>
#include <sanguo.h>

inherit ROOM;

void setup(){
    set_area("xbv_area");
    set_light(50);
    set_brief(YEL+"������Ĺ�����"+NOR);
    set_long("  
����տ���Ұ��ʲôҲû��!
�Ʋʵ���Ʈ����С�ı�Ūʪ������
�����Ϸ���Щ����,������������Щ��������֮��ġ�

����羰���ǲ�����ϧ�����ȥ�����߶���һ��������Ҫ�����˵Ļ���
Please mail to net.
\n\n");
    set_exits( ([
        "out" :  FROOMPATH+"vzhu_lin.c",
        "fire" :"/wiz/fire/workroom.c"
    ]) );
}
