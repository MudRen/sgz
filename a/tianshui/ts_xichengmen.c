// this room is created by buzzer.c
// driver is �������
// created date is Sun May  8 21:15:23 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("tianshui");
set_light(50);
set_brief("%^YELLOW%^"+"������"+"%^RESET%^");
set_long("
    ������ˮ�ǵ������ţ���������Ļ��������������ķ�ɳ��ʴ�Ե���Щ
�ưܡ��������Ϸ�����ǿǿ�����ϳ������š��������֡�������߽����������ﷸ
�������������ӻ���ԭ���ٱ��ǽ䱸ɭ�ϣ��������ͽ�ס���˽������ʡ�һ����ֱ
����ʯ��������������졣�����ǽ��⣬һֱ����ȥ����¤��,��౾���˸���
���ڴ����ﾭ����������ȥ�����Լ��ֵĹϹ���������������Ʒ�������ǳ��\n\n");
set_exits( ([
"east":"/a/tianshui/ts_xidajie.c",
 ]));
}
