// this room is created by buzzer.c
// driver is �������
// created date is Sat May  7 12:16:59 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("longxi");
set_light(50);
set_brief("%^YELLOW%^"+"������"+"%^RESET%^");
set_long("
    ������¤��Զ�������ĵ�����,�ſ����ⳤ��,һ����С������һ������
���������ۿգ���ͣӪҵ�����������ϡ�\n\n");
set_exits( ([
"east":"/a/longxi/lx_dounanjie2.c",
 ]));
}
