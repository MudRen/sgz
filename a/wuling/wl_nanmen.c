// this room is created by buzzer.c
// driver is ��ɽҹ��
// created date is Sat May 28 19:35:20 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("wuling");
set_light(50);
set_brief("%^YELLOW%^"+"����"+"%^RESET%^");
set_long("
    ���������������, �������ٱ��������ſ�,�̲�����̿͡�\n\n");
set_objects((["/sgdomain/modules/m_charnpc/guard.c":1]));
}
