// this room is created by buzzer.c
// driver is ��ɽҹ��
// created date is Sat May 28 20:03:10 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit M_BANK;

void setup() {
set_area("wuling");
set_light(50);
set_brief("%^YELLOW%^"+"С��"+"%^RESET%^");
set_long("
    ����������־��ȫ��������"+"%^MAGENTA%^"+"��ͨ��"+"%^RESET%^"+"��Ǯׯ����ֵ꣬����
�Ƕ���¢�ϣ�����ܻ��ȣ��߸ߵĹ�̨���������һ����İ�����
�������æ�Ű�����̧����Ժ����������Ļ����ǰ���д����ˣ�
ǽ������һ�Ÿ�ʾ��ת�˺�ȡǮ��ȡ�����Ѱٷ�֮ʮ����\n\n");

set_exits( ([
"west":"/a/wuling/wl_xiaolu2.c",
 ]));
set_objects( (["/sgdomain/obj/other/sign.c" : 1]) );
}
