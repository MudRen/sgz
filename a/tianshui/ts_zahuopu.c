// this room is created by buzzer.c
// driver is �������
// created date is Sun May  8 21:16:19 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("tianshui");
set_light(50);
set_brief("%^YELLOW%^"+"�ӻ���"+"%^RESET%^");
set_long("
    ��������ˮ�ӻ���,ÿ������������Ҳͦ���֡��������������ν��ף�
���Ǵ��װ��棬�����ճ���ƷҲ��������ȫ���м�һ�Ź�̨��������������
��̨�������ʡ���˵˽������Ҳ��һЩ���صĶ�����\n\n");
set_exits( ([
"north":"/a/tianshui/ts_xidajie.c",
 ]));
}
