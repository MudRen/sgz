// this room is created by buzzer.c
// driver is �������
// created date is Mon May  9 09:26:42 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("jiangling");
set_light(50);
set_brief("%^YELLOW%^"+"���Ĺ㳡"+"%^RESET%^");
set_long("
    �����ǽ���ǵ����Ĺ㳡,��ˮ����������,�㳡�м���
һƬ����Ĳݵأ������С������ȥ�������ֳԵ���ġ���
����һ��С·��\n\n");
set_exits( ([
"west":"/a/jiangling/jl_xiaolu.c",

"south":"/a/jiangling/jl_ruipinglu.c",

"north":"/a/jiangling/jl_ruipinglu3.c",
 ]));
}
