// this room is created by buzzer.c
// driver is �������
// created date is Fri Apr 29 10:51:55 2011
#include <mudlib.h>
#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("huayin");
set_light(50);
set_brief("%^YELLOW%^"+"ĥ��"+"%^RESET%^");
set_long("
    ����һ���൱�¾ɵ�ĥ����ĥ���м���һֻ���ص�ʯĥ��������
��ĥ��¿��Ҳ�Ҳ������ˣ�ֻ�п��Լ�����ĥ�ˣ��㲻���������Ǿ�
��Ǯ��ʹ���������׻���\n\n");
set_exits( ([
"east":"/a/huayin/lukou.c",
 ]));
set_objects( (["/sgdomain/job/choppork/zth.c" : 1]) );
}
