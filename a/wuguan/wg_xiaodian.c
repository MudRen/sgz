// this room is created by buzzer.c
// driver is �������
// created date is Fri May  6 22:01:45 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
inherit STORE;
void setup() {
set_area("wuguan");
set_light(50);
set_brief("%^YELLOW%^"+"С��"+"%^RESET%^");
set_long("
    ������ص�һ��·��С�꣬����߹�С�򿴵�һ��С���������
���ˡ�������ﲻ�࣬���Եúܸɾ����ࡣ��С������ɨ���ء���list
ָ����Կ������е���Ʒ��buyָ���\n\n");
set_exits( ([
"north":"/a/wuguan/wg_dadao.c",
 ]));
add_object("/sgdomain/obj/foodanddrink/mantou.c");
add_object("/sgdomain/obj/foodanddrink/ypjd.c");
}
