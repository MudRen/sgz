// this room is created by buzzer.c
// driver is �������
// created date is Mon May  9 09:40:16 2011
#include <mudlib.h>
#include <ansi.h>
inherit M_BANK;

void setup() {
set_area("jiangling");
set_light(50);
set_brief("%^YELLOW%^"+"Ǯׯ"+"%^RESET%^");
set_long("
    �����ǽ����Ǯׯ���ſ�д��һ�����ơ���ͨ���š���Ǯׯ�ϰ�
�������ʱ��������̡�������Զһ�������ǮȡǮ���ſ�����һ��
Ǯׯ�ĸ�ʾ(sign)\n\n");
set_exits( ([
"east":"/a/jiangling/jl_ruipinglu3.c",
 ]));
set_objects( (["/sgdomain/obj/other/sign.c" : 1]) );
}
