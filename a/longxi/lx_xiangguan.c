// this room is created by buzzer.c
// driver is �������
// created date is Sat May  7 14:35:49 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("longxi");
set_light(50);
set_brief("%^YELLOW%^"+"���"+"%^RESET%^");
set_long("
    ������¤����ʿ��,һ������ʿ��Ŀ���������ľ����,�Ա�ǽ����
������д�Ŵ��ġ��ࡱ�֡�·�������Թ��Լ�������ȥ������û���˿�
������ʿ�Ƶġ�\n\n");
set_exits( ([
"west":"/a/longxi/lx_beichenjie2.c",
 ]));
}
