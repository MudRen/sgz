// this room is created by buzzer.c
// driver is �������
// created date is Sat May  7 13:57:15 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("longxi");
set_light(50);
set_brief("%^YELLOW%^"+"������"+"%^RESET%^");
set_long("
    ������¤��������,ֻ���м�Χ��һȦ¤���ٱ�,�м�һ���ߴ���Ĺٱ�����
һ�����ٵĹٱ��ڱ���,һ��ٱ��ڸ����ٵĹٱ��������������ϰ���һ��ľ�ʱ�
�������ٱ�����ʹ�á�\n\n");
set_exits( ([
"north":"/a/longxi/lx_qianmendajie5.c",
 ]));
}
