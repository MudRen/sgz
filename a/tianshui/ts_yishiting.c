// this room is created by buzzer.c
// driver is �������
// created date is Sun May  8 21:17:33 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("tianshui");
set_light(50);
set_brief("%^YELLOW%^"+"������"+"%^RESET%^");
set_long("
    ��������ˮ������,������һ��̫ʦ�Σ����̻�Ƥ��һ�������е�������ϣ�����
����С���Ϊ������౳����Ƥ��������������ʯ���磬���������ɸߣ�ʯ��ɽˮľ����
���续������һ�㡣���α���̫�������������������������ڣ���û��֮ʱ�������
������������İ����ѡ�\n\n");
set_exits( ([
"south":"/a/tianshui/ts_junying.c",
 ]));
}
