// this room is created by buzzer.c
// driver is ��ɽҹ��
// created date is Sat May 28 19:45:34 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("wuling");
set_light(50);
set_brief("%^YELLOW%^"+"������"+"%^RESET%^");
set_long("
    ����������Ĵ�����,����ͨ�����걱��,����ͨ��
У��,����ͨ������㽫̨,�����Ǵ����\n\n");
set_exits( ([
"east":"/a/wuling/wl_beijie1.c",

"north":"/a/wuling/wl_xiaochang.c",

"south":"/a/wuling/wl_dianjiangtai.c",

"west":"/a/wuling/wl_dadao2.c",
 ]));
}
