// this room is created by buzzer.c
// driver is �������
// created date is Fri Apr 29 10:44:55 2011
#include <mudlib.h>
#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("huayin");
set_light(50);
set_brief("%^YELLOW%^"+"�峤��"+"%^RESET%^");
set_long("
    ����һ����ӵ�ľ�ݣ����ڷǳ������򵥵ذ�����һ�Ŵ���
ľ���ͼ�����ʣ������ǽ�Ϲ��ż��������䲻�ǳ��������ֱʣ���
Ҳ�Ƚ��Ϳ���������ǻ�����峤ƽʱ���ĵط�������Ĺ�Ա������
Ҫ������Ҳ���ǵ�������������\n\n");
set_exits( ([
"west":"/a/huayin/laofang.c",

"east":"/a/huayin/laohuaishu.c",
 ]));
//set_objects( (["/sgdomain/modules/m_board.c" : 1]) );
set_objects(([M_BOARD : ({ 1,"ǽ����һ�Ż�����Աר�õ� "+"%^MAGENTA%^"+"�������԰�"+"%^RESET%^", "city.didao" }) ]) );
}
