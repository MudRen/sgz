// this room is created by buzzer.c
// driver is �������
// created date is Sun May  8 21:44:17 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("tianshui");
set_light(50);
set_brief("%^YELLOW%^"+"�ϳ���"+"%^RESET%^");
set_long("
    ������ˮ�ǵ��ϳ��ţ���������Ļ��������������ķ�ɳ��ʴ�Ե���Щ
�ưܡ��������Ϸ�����ǿǿ�����ϳ������š��������֡��ٱ��ǽ䱸ɭ�ϣ�������
�ͽ�ס���˽������ʡ�һ����ֱ����ʯ������ϱ��������졣�ϱ��ǽ��⣬һЩ
�����������˶���������ǣ����ϵ������͡������ǳ��\n\n");
set_objects((["/sgdomain/modules/m_charnpc/guard.c":1]));
}
