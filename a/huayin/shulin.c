// this room is created by buzzer.c
// driver is �������
// created date is Thu Apr 28 23:27:20 2011
#include <mudlib.h>
#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("huayin");
set_light(50);
set_brief("%^YELLOW%^"+"����"+"%^RESET%^");
set_long("
    ��ǰ��һƬ���֣�Ҳ��֪��˭�ڶ�����ǰ�ֵģ��������ڿ���Ұ
��Ұ�����൱ïʢ��ƽʱ����С����Ĵ���ᵽ��������Щ����ȥ
�ջ���������������ʱ�����ﶼ�Ǿ����ĵģ�ֻ��������Щ��֪����
С���ڡ��ౡ��س���\n\n");
set_exits( ([
"east":"/a/huayin/xiaolu.c",
 ]));
set_objects( (["/sgdomain/job/chopwoods/woods.c" : 1]) );
}
