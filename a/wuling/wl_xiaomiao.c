// this room is created by buzzer.c
// driver is ��ɽҹ��
// created date is Sat May 28 19:57:10 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("wuling");
set_light(50);
set_brief("%^YELLOW%^"+"С��"+"%^RESET%^");
set_long("
    ����������С��,Ժ����һ����ˮ��������ʯ��ʯ�ߣ���Ȼ�̾ᡣ\n\n");
set_exits( ([
"west":"/a/wuling/wl_beijie2.c",
 ]));
}
