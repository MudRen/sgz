// this room is created by buzzer.c
// driver is ��ɽҹ��
// created date is Sat May 28 20:00:26 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("wuling");
set_light(50);
set_brief("%^YELLOW%^"+"������"+"%^RESET%^");
set_long("
    ����������ľ�����,��Ҫ��Ӫ�ķ��ı�,һЩѧ����
����������ȥ��\n\n");
set_exits( ([
"west":"/a/wuling/wl_beijie3.c",
 ]));
}
