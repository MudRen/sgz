// this room is created by buzzer.c
// driver is �������
// created date is Fri Apr 29 12:50:06 2011
#include <mudlib.h>
#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("huayin");
set_light(50);
set_brief("%^YELLOW%^"+"����"+"%^RESET%^");
set_long("
    һ���������ӣ�����ŵ���һ������ζ����ֱ����ӣ�������
�����Ǽ��������ǽ����ͺ�����һֻ�����ͷ�����ҵط���Щ��
��ʲô�ġ������ѷ���Щ�������������ġ��㿴��һλ������
æǰæ���շ����ˡ�\n\n");
set_exits( ([
"north":"/a/huayin/qianting.c",
 ]));
set_objects( (["/sgdomain/job/chopwoods/chuniang.c" : 1]) );
}
