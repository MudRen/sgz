// this room is created by buzzer.c
// driver is �������
// created date is Sat May  7 13:53:37 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("longxi");
set_light(50);
set_brief("%^YELLOW%^"+"У��"+"%^RESET%^");
set_long("
    ����¤��У����ƽʱ��ʿ�Ǿ���������������Ϻ�ƽ����
������ָ��̨���и��������ɵ���ˣ��˶�һ������һ����������������
Ӫ��ɫ����ӭ���������졣ƽʱ��ʿ��һ�����������ϳ��٣������
����������Ұս����������¤�������Ѳ�ߡ�\n\n");
set_exits( ([
"north":"/a/longxi/lx_junying.c",
 ]));
}
