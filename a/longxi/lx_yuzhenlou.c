// this room is created by buzzer.c
// driver is �������
// created date is Sat May  7 13:50:03 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("longxi");
set_light(50);
set_brief("%^YELLOW%^"+"����¥"+"%^RESET%^");
set_long("
    ������¤�������������¥�ϣ�����¥�µķ���ææµµ���������
��죬��ν���ԾƵ��裬�������Ρ�������ԥʲô��������������ɣ�\n\n");
set_exits( ([
"south":"/a/longxi/lx_qianmendajie2.c",
 ]));
}
