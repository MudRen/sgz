// this room is created by buzzer.c
// driver is �������
// created date is Sun May  8 21:32:23 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("tianshui");
set_light(50);
set_brief("%^YELLOW%^"+"������"+"%^RESET%^");
set_long("
    ���Ǳ����ţ����ڱ����Ļ����񻯣���������ķ�ɳ��ʴ�Ե���Щ�ưܡ�
�������Ϸ�����ǿǿ�����ϳ������š��������֣��ٱ��ǽ䱸ɭ�ϣ��������ͽ�ס����
���ʡ�һ����ֱ����ʯ�������ϱ��������졣�����ǽ��⣬����ġ�����
�ġ���·�ģ����˴Ҵҡ��ϱ��ǳ��\n\n");
set_exits( ([
"south":"/a/tianshui/ts_beidajie.c",
 ]));
}
