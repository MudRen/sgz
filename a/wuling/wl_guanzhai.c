// this room is created by buzzer.c
// driver is ��ɽҹ��
// created date is Sat May 28 19:33:34 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("wuling");
set_light(50);
set_brief("%^YELLOW%^"+"��լ"+"%^RESET%^");
set_long("
    ��������Ĺ�լ���ڲ����輫������������һ�ź�ɫ̴ľ
����������·��ž����Ļ�ƿ��һЩ���Ĵ������ıڹ�����
�ҵ��ֻ���\n\n");
set_exits( ([
"east":"/a/wuling/wl_suishilu1.c",
 ]));
}
