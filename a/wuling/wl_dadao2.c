// this room is created by buzzer.c
// driver is ��ɽҹ��
// created date is Sat May 28 19:27:46 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("wuling");
set_light(50);
set_brief("%^YELLOW%^"+"���"+"%^RESET%^");
set_long("
    �����Ǵ��,����ͨ�������,��������С��,����
�������������,��λ��Ա����������ȥ��\n\n");
set_exits( ([
"east":"/a/wuling/wl_cunzhongxin.c",

"south":"/a/wuling/wl_xiaoxiang.c",

"west":"/a/wuling/wl_dadao1.c",

"north":"/a/wuling/wl_yishiting.c",
 ]));
}
