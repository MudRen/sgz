// this room is created by buzzer.c
// driver is �������
// created date is Fri May 27 15:25:21 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("jiangling");
set_light(50);
set_brief("%^YELLOW%^"+"�ϳ���"+"%^RESET%^");
set_long("
    �����ǽ�����ϳ���,�ߴ��ǽ��д��ŵ���
�����֡�"+"%^MAGENTA%^"+"����"+"%^RESET%^"+"����\n\n");
set_objects((["/sgdomain/modules/m_charnpc/guard.c":1]));
}
