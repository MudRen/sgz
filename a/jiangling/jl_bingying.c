// this room is created by buzzer.c
// driver is �������
// created date is Mon May  9 09:19:58 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("jiangling");
set_light(50);
set_brief("%^YELLOW%^"+"��Ӫ"+"%^RESET%^");
set_long("
    ���ǽ����Ӫ,������������С���Ĳ�����,������
��ƽ·,������˧��.�кܶ���Χ�����а��ĵĵط���̸���ۡ�\n\n");
set_exits( ([
"west":"/a/jiangling/jl_shuaizhang.c",

"east":"/a/jiangling/jl_ruipinglu2.c",
 ]));
set_objects(([M_BOARD : ({ 1,"һ�����µ�"+"%^MAGENTA%^"+"�������԰�"+"%^RESET%^", "city.jiangling" }) ]) );
}
