// this room is created by buzzer.c
// driver is �������
// created date is Tue May  3 19:52:01 2011
#include <mudlib.h>
#include <ansi.h>
inherit M_BANK;

void setup() {
set_area("changan");
set_light(50);
set_brief("%^YELLOW%^"+"Ǯׯ"+"%^RESET%^");
set_long("
    �����ǳ����ǵ�Ǯׯ���ſ�д��һ�����ơ�����¡����Ǯׯ�ϰ�
�������ʱ��������̡�������Զһ�������ǮȡǮ���ſ�����һ��
Ǯׯ�ĸ�ʾ(sign)\n\n");
set_exits( ([
"west":"/a/changan/ca_yongchangjie3.c",
 ]));
set_objects( (["/sgdomain/obj/other/sign.c" : 1]) );
}
