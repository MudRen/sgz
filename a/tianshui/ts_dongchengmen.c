// this room is created by buzzer.c
// driver is �������
// created date is Sun May  8 21:12:15 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("tianshui");
set_light(50);
set_brief("%^YELLOW%^"+"������"+"%^RESET%^");
set_long("
    ������ˮ�ǵĶ����ţ���������Ļ��������������ķ�ɳ��ʴ�Ե���Щ
�ưܡ��������Ϸ�����ǿǿ�����ϳ������š��������֡�������߽����������ﷸ
�������������ӻ���ԭ���ٱ��ǽ䱸ɭ�ϣ��������ͽ�ס���˽������ʡ�һ����
ֱ����ʯ��������������졣�����ǽ��⣬��������������˶���������ǣ�
�򶫵����ش��������ǳ��\n\n");
set_exits( ([
"west":"/a/tianshui/ts_dongdajie.c",
 ]));
}
