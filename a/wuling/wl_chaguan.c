// this room is created by buzzer.c
// driver is ��ɽҹ��
// created date is Sat May 28 19:30:30 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("wuling");
set_light(50);
set_brief("%^YELLOW%^"+"���"+"%^RESET%^");
set_long("
    ������������,��һ�߽��������ŵ�һ�ɲ���������Ƣ����
��Ϊ֮һˬ�� ���Ű�����һ���ſ��������˿��ˣ������̸Ц��
��ͷ�Ӷ�����С�����Ŵ����Ĵ��߶��к����ˡ�\n\n");
set_exits( ([ 
"east":"/a/wuling/wl_xiaoxiang.c",
 ]));
}
