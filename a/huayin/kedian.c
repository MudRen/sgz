// this room is created by buzzer.c
// driver is �������
// created date is Fri Apr 29 12:57:54 2011
#include <mudlib.h>
#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("huayin");
set_light(50);
set_brief("%^YELLOW%^"+"�͵�"+"%^RESET%^");
set_long("
    �����ǻ�����Ŀ͵꣬��Ϊ��·�������ṩ��Ϣ�ĵط���������
ʰ�Ļ���ɾ���û������ʲô���裬ֻ�ǰ�����������Ϣ������Ҫ��
����������������Է��ĵ�������˯��һ����Ȼ�������·��\n\n");
set_exits( ([
"east":"/a/huayin/nancunkou.c",
 ]));
set_objects( (["/sgdomain/obj/other/bed.c" : 1]) );
}
