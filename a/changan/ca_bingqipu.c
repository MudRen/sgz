// this room is created by buzzer.c
// driver is �������
// created date is Tue May  3 21:16:35 2011
#include <mudlib.h>
#include <ansi.h>
inherit INDOOR_ROOM;
inherit STORE;

void setup() {
set_area("changan");
set_light(50);
set_brief("%^YELLOW%^"+"������"+"%^RESET%^");
set_long("
    ���߽������̣����ɵ���ǰһ������������������Ÿ�ʽ
�����ľ��µı�����ľ���������ų����󵶣���ǹ�������ȡ�ÿ
һ�������㰮�����֡���listָ���г������ͼ۸���buyָ��
����\n\n");
set_exits( ([
"east":"/a/changan/ca_xiaolu.c",
 ]));
add_object("/sgdomain/obj/weapon/blade/qixing.c");
add_object("/sgdomain/obj/weapon/blade/sanjian.c");
add_object("/sgdomain/obj/weapon/hammer/tiechui.c");
add_object("/sgdomain/obj/weapon/ji/changji.c");
add_object("/sgdomain/obj/weapon/ji/ji.c");
add_object("/sgdomain/obj/weapon/sword/gangjian.c");
}
