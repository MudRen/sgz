// this room is created by buzzer.c
// driver is �������
// created date is Sun May  8 21:40:53 2011
//#include <mudlib.h>
//#include <ansi.h>
//inherit INDOOR_ROOM;
inherit M_BANK;
void setup() {
set_area("tianshui");
set_light(50);
set_brief("%^YELLOW%^"+"Ǯׯ"+"%^RESET%^");
set_long("
    ����������־��ȫ��������"+"%^MAGENTA%^"+"��ͨ��"+"%^RESET%^"+"��Ǯׯ��ˮ�ֵ꣬����
�Ƕ���¢�ϣ�����ܻ��ȣ��߸ߵĹ�̨���������һ����İ�����
�������æ�Ű�����̧����Ժ����������Ļ����ǰ���д����ˣ�
ǽ������һ�Ÿ�ʾ��ת�˺�ȡǮ��ȡ�����Ѱٷ�֮ʮ����\n\n");
set_exits( ([
"west":"/a/tianshui/ts_nandajie.c",
 ]));
set_objects( (["/sgdomain/obj/other/sign.c" : 1]) );
}
