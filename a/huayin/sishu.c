// this room is created by buzzer.c
// driver is �������
// created date is Fri Apr 29 12:12:54 2011
#include <mudlib.h>
#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("huayin");
set_light(50);
set_brief("%^YELLOW%^"+"��˽��"+"%^RESET%^");
set_long("
    һ�䲻��С�Ĳݷ����������ƾɲ��������ڰ��ż��Ű�С��ľ
���Ͱ�ʣ�����С��ͯſ�����档�е��ڡ�߽߽ѽѽ�������飬�е�
������������һ������֡�һ�ߵ����������Ÿ����ݵ���ͷ������
��������������ӣ��ƺ���һ�ж�Į�����ģ�ֻ�Ƕ��������õ�һ��
���Ƶ����顣\n\n");
set_exits( ([
"east":"/a/huayin/xiaoxiang.c",
 ]));
set_objects( (["/sgdomain/npc/kongyiji.c" : 1]) );
}
