// this room is created by buzzer.c
// driver is �������
// created date is Sun May  8 21:16:59 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("tianshui");
set_light(50);
set_brief("%^YELLOW%^"+"��Ӫ"+"%^RESET%^");
set_long("
    ��������ˮ��פ����Ӫ�����Ｘ�����ǹٱ���һ�ӹٱ����������
����������һ������������������ָ�ֻ��ţ������ǹپ���ͷ�ӡ�\n\n");
set_exits( ([
"north":"/a/tianshui/ts_yishiting.c",

"south":"/a/tianshui/ts_xidajie.c",

"east":"/a/tianshui/ts_beidajie.c",
 ]));
}
