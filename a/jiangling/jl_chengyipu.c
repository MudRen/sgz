// this room is created by buzzer.c
// driver is �������
// created date is Mon May  9 09:28:46 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
inherit STORE;

void setup() {
set_area("jiangling");
set_light(50);
set_brief("%^YELLOW%^"+"������"+"%^RESET%^");
set_long("
    ���ǽ�����ϵ�һ����ñ�꣬�����Ʒ������Ӳ��������¡��
�������·���Ь�ӣ�ñ�ӳ��ۡ�listָ���г���Ʒ��buyָ���\n\n");
set_exits( ([
"north":"/a/jiangling/jl_xiaoxiang.c",

"south":"/a/jiangling/jl_xiaolu.c",
 ]));
add_object("/sgdomain/obj/cloth/torso/buyi.c");
add_object("/sgdomain/obj/cloth/shoes/buxie.c");
add_object("/sgdomain/obj/cloth/shoes/pixue.c");
add_object("/sgdomain/obj/cloth/hats/guanjin.c");
}
