// this room is created by buzzer.c
// driver is �������
// created date is Sat May  7 12:20:17 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("longxi");
set_light(50);
set_brief("%^YELLOW%^"+"������"+"%^RESET%^");
set_long("
    ������¤���Ľ�������ƽʱ¤����ʿ����Ҳ��������,
�����������һ�����͵Ľ�������һ��ƣ����������ս�չ��ģ����
�������߰��ű����ܣ����Ϸ�������Ѫ����ӳ�żܺ��ս�죬����
ҫ�ۡ����ཫ����������δϴ������־���������׳��\n\n");
set_exits( ([
"east":"/a/longxi/lx_dounanjie3.c",
 ]));
}
