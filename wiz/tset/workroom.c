/* RoomMaker.c
** Coded by Է�@LIMA
** Code generated with RoomMaker v0.9.1 coded by Onyx@RedDragon
** Do not remove this header.
*/

#include <mudlib.h>
#include <ansi.h>

inherit ROOM;

void setup(){
    set_area("huayin");
    set_light(50);
    set_brief("%^H_MAGENTA%^Է赵Ļ����%^RESET%^");
    set_long("  
���ڶ���һ��ѣ�����̯��һ���������·�����鷳��
�����Ϸ���Щ���飬��Ȼ������û�¸����¸ɡ����ǰ������������ɡ�
����羰���ǲ�����ϧ�����ȥ�����߶���һ��������Ҫ�����˵Ļ���
�� mail tset ��
\n\n");
    set_exits( ([
        "out" :  FROOMPATH+"vzhu_lin.c",
        "zatan" : __DIR__+"chatroom.c", 
    ]) );
}
