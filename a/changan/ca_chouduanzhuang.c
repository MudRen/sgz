// this room is created by buzzer.c
// driver is �������
// created date is Tue May  3 21:36:45 2011
#include <mudlib.h>
#include <ansi.h>
inherit INDOOR_ROOM;
inherit STORE;

void setup() {
set_area("changan");
set_light(50);
set_brief("%^YELLOW%^"+"���ׯ"+"%^RESET%^");
set_long("
    ���Ƿ����ĳ������ϵ�һ���ܴ�ĳ��ׯ�������Ʒ����
��Ŀ��������¡���������·���Ь�ӣ�ñ�ӳ��ۡ�listָ����
����Ʒ��buyָ��򡣼ǵ�ǮҪ����Ŷ��\n\n");
set_exits( ([
"south":"/a/changan/ca_xdj1.c",
 ]));
add_object("/sgdomain/obj/cloth/torso/buyi.c");
add_object("/sgdomain/obj/cloth/torso/changpao.c");
add_object("/sgdomain/obj/cloth/torso/choup.c");
add_object("/sgdomain/obj/cloth/torso/hechang.c");
add_object("/sgdomain/obj/cloth/torso/jinp.c");
add_object("/sgdomain/obj/cloth/torso/longpao.c");
add_object("/sgdomain/obj/cloth/shoes/buxie.c");
add_object("/sgdomain/obj/cloth/shoes/pixue.c");
add_object("/sgdomain/obj/cloth/hats/guanjin.c");
add_object("/sgdomain/obj/cloth/hats/jinkui.c");
add_object("/sgdomain/obj/cloth/hats/yinkui.c");
}
