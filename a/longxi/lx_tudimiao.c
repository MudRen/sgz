// this room is created by buzzer.c
// driver is �������
// created date is Sat May  7 14:39:27 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("longxi");
set_light(50);
set_brief("%^YELLOW%^"+"������"+"%^RESET%^");
set_long("
    ����һ��ʮ���ƾɵ�������Ҳ��֪�ķ��˶�ã����ϵ��²�����
�ҳ����������������ǽ���и����ڣ������������������ļ��ˡ�\n\n");
set_exits( ([
"south":"/a/longxi/lx_xiaoxiang3.c",
 ]));
}
