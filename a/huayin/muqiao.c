// this room is created by buzzer.c
// driver is �������
// created date is Fri Apr 29 12:58:52 2011
#include <mudlib.h>
#include <ansi.h>
#include <sanguo.h>
inherit INDOOR_ROOM;
inherit M_BLOCKEXITS;
void setup() {
set_area("huayin");
set_light(50);
set_brief("%^YELLOW%^"+"ľ��"+"%^RESET%^");
set_long("
    ����һ��խխ��ľ�ţ�����ȥ�ƺ����첻�ã�Ҫ��Ȼ����ȥ����
�е��ľ���ս�ء����������¿�����һ�������С�ӣ�ˮ����������
�ţ��峺�ޱȣ��㻹���Կ�������������ˮ����Ϸ��\n\n");
set_objects((["/sgdomain/modules/m_charnpc/guard.c":1]));
}
