// this room is created by buzzer.c
// driver is �������
// created date is Sun May  8 21:42:03 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("tianshui");
set_light(50);
set_brief("%^YELLOW%^"+"����"+"%^RESET%^");
set_long("
    ���϶����������ס������һ������������������ϸ������ǽ������
һ�����ң����顰����������ĸ���������Ĵ��֡�֪���������İ�����
�����飬ʦү�����ں�һ���������������ԣ��ڴ���ʲôԩ�������ֱ
����֪��������˵��\n\n");
set_exits( ([
"east":"/a/tianshui/ts_yamen.c",
 ]));
}
