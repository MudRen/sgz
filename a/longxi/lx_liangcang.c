// this room is created by buzzer.c
// driver is �������
// created date is Sat May  7 13:55:51 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("longxi");
set_light(50);
set_brief("%^YELLOW%^"+"����"+"%^RESET%^");
set_long("
    ������¤�������֣��ѷ��Ŷѻ���ɽ�ľ������굽��������Ҳ������
֮�á����ڲֹ����٣����������ͽ�Ŀ��ӡ�\n\n");
set_exits( ([
"north":"/a/longxi/lx_qiandajie4.c",
 ]));
}
