// this room is created by buzzer.c
// driver is �������
// created date is Tue May  3 19:50:03 2011
#include <mudlib.h>
#include <ansi.h>
inherit M_DANGPU;

void setup() {
set_area("changan");
set_light(50);
set_brief("%^YELLOW%^"+"����"+"%^RESET%^");
set_long("
    �����ǳ����ǵĵ��̣��ſڵ�������д��һ���ܴ�ĵ��֡�
һ���žͿ��Կ����ܶ�����һ�˸ߵĹ�̨����������һλ����
�Ĵ����۾�����������������ڵ���һ�ߵ�ǽ�Ͽ���һ����Ŀ
�ĸ�ʾ(gaoshi)\n\n");
set_exits( ([
"east":"/a/changan/ca_ycj2.c",
 ]));
set_objects( (["/sgdomain/obj/other/gaoshi.c" : 1]) );
}
