// this room is created by buzzer.c
// driver is ��ɽҹ��
// created date is Sat May 28 19:42:38 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("wuling");
set_light(50);
set_brief("%^YELLOW%^"+"С��"+"%^RESET%^");
set_long("
    �����ǲ�֪����С��,����û����ס��������Ҿߣ�����
�����ڣ�ֻ�������˻ҳ���������˲ξ�����ȥ�ˣ�Ϊ�˵���
����ǿ��Ķ�׿�����ٸ���ʼ��׳��ļ��ʿ������ɺܶ����
�˶�ϡ�١�\n\n");
set_exits( ([
"west":"/a/wuling/wl_nanjie2.c",
 ]));
}
