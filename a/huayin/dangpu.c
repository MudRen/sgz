// this room is created by buzzer.c
// driver is �������
// created date is Fri Apr 29 10:58:05 2011
#include <mudlib.h>
#include <ansi.h>
inherit M_DANGPU;
void setup() {
set_area("huayin");
set_light(50);
set_brief("%^YELLOW%^"+"����"+"%^RESET%^");
set_long("
    ���ǻ�����ĵ��̣��������ط��ĵ���һ����һ���žͿ��Կ���
�Ƕ��ص�һ�˸ߵĹ�̨����������Ų��ܽ���������ȥ����������
ս�ң��ϰ��յ�����Խ��Խ�࣬���Խ������̵���Ҳ��������������
���ż�����̤���ˡ�����Կ�����һ�Ե�ǽ����һ�Ÿ�ʾ(gaoshi)��\n\n");
set_exits( ([
"south":"/a/huayin/daguchang.c",
 ]));
set_objects( (["/sgdomain/obj/other/gaoshi.c" : 1]) );
}
