// this room is created by buzzer.c
// driver is ��ɽҹ��
// created date is Mon May 30 19:22:53 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit M_BANK;
void setup() {
set_area("nanpi");
set_light(50);
set_brief("%^YELLOW%^"+"Ǯׯ"+"%^RESET%^");
set_long("
    ��������Ƥ��Ǯׯ���ſ�д��һ�����ơ��������š���Ǯׯ�ϰ�
�������ʱ��������̡�������Զһ�������ǮȡǮ���ſ�����һ��
Ǯׯ�ĸ�ʾ(sign)\n\n");
set_exits( ([
"west":"/a/nanpi/np_huashi.c",
 ]));
set_objects( (["/sgdomain/obj/other/sign.c" : 1]) );
}
