// this room is created by buzzer.c
// driver is �������
// created date is Sat May  7 14:27:51 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("longxi");
set_light(50);
set_brief("%^YELLOW%^"+"����"+"%^RESET%^");
set_long("
    ������¤�������Ŵ��ã�����һ�����������Ĵ��ң��Ǹ���
�����űر��ļҵ������õĵ��ϲ��ó���ȴ��Լ�ܿ���һ����Ѫ�ۣ���
���Ǵ�������ʱ���µĺۼ������߸���һЩ�ྲ���رܵ����ӣ�����Щ��
����ŭ�ĸо���\n\n");
set_exits( ([
"west":"/a/longxi/lx_laoyu.c",

"south":"/a/longxi/lx_yamen.c",
 ]));
}
