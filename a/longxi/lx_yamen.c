// this room is created by buzzer.c
// driver is �������
// created date is Sat May  7 14:27:17 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("longxi");
set_light(50);
set_brief("%^YELLOW%^"+"����"+"%^RESET%^");
set_long("
    ���������������¤�������ţ���ľ���������߰�ǽ���쳣��Ŀ��
ͭƤ�������߰ڶ�������ͷ������צ��ʯʨ�ӡ�ǰ����������һ����ģ�
��Ȼ�ǹ�С����ԩ�õġ�ֱ����ȥ�Ϳ��Կ���֪������Ĵ��á�\n\n");
set_exits( ([
"north":"/a/longxi/lx_datang.c",

"south":"/a/longxi/lx_qiandajie4.c",
 ]));
}
