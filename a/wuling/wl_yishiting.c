// this room is created by buzzer.c
// driver is ��ɽҹ��
// created date is Sat May 28 19:51:24 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("wuling");
set_light(50);
set_brief("%^YELLOW%^"+"������"+"%^RESET%^");
set_long("
    ����������������,�м����һ�ų���,���԰��ż��ŵ��ӡ�
������̫���ճ���������ĵط�����������Ķ������ŵ��Ĺٺ�
����Ľ��������Ǵ����ǹ�����ͳһ���µı����ۼ���һ��
�ſ�վ�������ٱ�����ֹ�����˵�ɧ�Ŵ峤��\n\n");
set_exits( ([
"east":"/a/wuling/wl_xiaolu1.c",

"south":"/a/wuling/wl_dadao2.c",
 ]));
}
