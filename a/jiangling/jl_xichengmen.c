// this room is created by buzzer.c
// driver is �������
// created date is Mon May  9 09:28:02 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("jiangling");
set_light(50);
set_brief("%^YELLOW%^"+"������"+"%^RESET%^");
set_long("
    �����ǽ����������,�ߴ��ǽ��д��ŵ�������
�֡�"+"%^MAGENTA%^"+"����"+"%^RESET%^"+"����\n\n");
set_exits( ([
"east":"/a/jiangling/jl_xiaolu.c",
 ]));
}
