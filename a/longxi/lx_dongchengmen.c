// this room is created by buzzer.c
// driver is �������
// created date is Sat May  7 13:49:23 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("longxi");
set_light(50);
set_brief("%^YELLOW%^"+"������"+"%^RESET%^");
set_long("
    ������������¤���Ķ����ţ���ǽ�Ͽ���ŵ��ġ�"+"%^MAGENTA%^"+"¤��"+"%^RESET%^"+"��
�����������,��ǽ�����ż��Źٸ���ʾ���ٱ��Ǿ����ע���Ź������ˣ�
�����С��Ϊ�һ����ֱ����ʯ�����������죬������ǰ�Ŵ�֡�\n\n");
set_objects((["/sgdomain/modules/m_charnpc/guard.c":1]));
}
