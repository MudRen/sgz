// this room is created by buzzer.c
// driver is ��ɽҹ��
// created date is Sat May 28 19:52:18 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("wuling");
set_light(50);
set_brief("%^YELLOW%^"+"С��ͷ"+"%^RESET%^");
set_long("
    �����������С��ͷ,�м���С�㴬ͣ����ͷ����,��
�ڽ�������ղ���ˮ����\n\n");
set_exits( ([
"south":"/a/wuling/wl_xiaolu1.c",
 ]));
}
