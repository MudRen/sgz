// this room is created by buzzer.c
// driver is ��ɽҹ��
// created date is Sat May 28 19:38:30 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("wuling");
set_light(50);
set_brief("%^YELLOW%^"+"�ӻ���"+"%^RESET%^");
set_long("
    ����һ���ӻ��̣�����С�������һ�أ�����һЩ�ճ�
��Ʒ�����ƹ������������һֻ�����ϣ��к��Ź������ˡ�
��˵˽������Ҳ��һЩ���صĶ�����\n\n");
set_exits( ([
"west":"/a/wuling/wl_suishilu3.c",
 ]));
}
