// this room is created by buzzer.c
// driver is �������
// created date is Sat May  7 13:57:57 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("longxi");
set_light(50);
set_brief("%^YELLOW%^"+"�㽫̨"+"%^RESET%^");
set_long("
    ������¤���㽫̨,�м�һ����̨���ϲ������,�ڸ�̨�ϰ���һ���㰸��
����û��ս��,�����Եü�Ϊ�տ�,ֻ�м���¤���ٱ�վ�ڶ���·�ڡ�\n\n");
set_exits( ([
"east":"/a/longxi/lx_qianmendajie5.c",
 ]));
}
