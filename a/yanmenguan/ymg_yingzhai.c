// this room is created by buzzer.c
// driver is ��ɽҹ��
// created date is Wed Jun 15 22:16:44 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("yanmenguan");
set_light(50);
set_brief("%^YELLOW%^"+"Ӫկ"+"%^RESET%^");
set_long("");
set_exits( ([
"south":"/a/yanmenguan/ymg_yingfang.c",

"north":"/a/yanmenguan/ymg_shuaizhang.c",

"west":"/a/yanmenguan/ymg_xiguankou.c",

"east":"/a/yanmenguan/ymg_qianshanlu.c",
 ]));
}
