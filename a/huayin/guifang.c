// this room is created by buzzer.c
// driver is �������
// created date is Fri Apr 29 12:50:58 2011
#include <mudlib.h>
#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("huayin");
set_light(50);
set_brief("%^YELLOW%^"+"�뷿"+"%^RESET%^");
set_long("
    һ�����������ɱ������������ı��ӣ�������Щ���κ����ĸ�
����û������������˵�Ů��������С��Ĺ뷿���Ĵ��İ��趼��
��ô�ľ��£����Ϲҵ������˻������ӣ�һ����һ�������ο�ͼ����
��ױ̨����������ŵ�ͭ�����ƺ��ܿ����Լ�����Ӱ��������䷿��
��㲻�ɵ��������������\n\n");
set_exits( ([
"south":"/a/huayin/houtang.c",
 ]));
}
