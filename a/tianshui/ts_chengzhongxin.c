// this room is created by buzzer.c
// driver is �������
// created date is Sun May  8 21:12:49 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("tianshui");
set_light(50);
set_brief("%^YELLOW%^"+"������"+"%^RESET%^");
set_long("
    ��������ˮ�ǵ������ģ���һ���ܿ����Ĺ㳡�����������ɳ�ܴ�����
������ʯ�ĵ��澭������һ���ɳ��һЩ���ֺ��е��������������������
һЩ����������������ݡ������������У����С�����������˶������Լ�����
Ʒ��һ�����־���\n\n");
set_exits( ([
"north":"/a/tianshui/ts_beidajie.c",

"south":"/a/tianshui/ts_nandajie.c",

"west":"/a/tianshui/ts_xidajie.c",

"east":"/a/tianshui/ts_dongdajie.c",
 ]));
set_objects(([M_BOARD : ({ 1,"��������ˮ�����Ĺ㳡��\n\n·��������һ��"+"%^MAGENTA%^"+"��ˮ������"+"%^RESET%^", "city.tianshui" }) ]) );
}
