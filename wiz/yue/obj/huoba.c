// by fire on Jan huoba.c
#include <sanguo.h>
inherit TORCH;
inherit M_VALUE; // modified by fire
void setup() {
    set_adj("�ƾɵ�");
    set_id("huoba", "���");
    set_unit("��");
    set_long( (: "һ���ƾɵĻ�ѣ�ͷ����Щ���͡�\n" + (query_is_lit() ?
"������ȼ���ŵ���Ļ��档\n" : "") :) );
    set_light_msgs("��$N��$O���ŵ�ʱ��һ�ɺ�ɫ�Ļ�������������\n",
"��$N��$O��ȼ��ʱ��ð��һ��Ǻ�˵��̡�\n");
    set_source( 1 );
    set_fuel(500); // never runs out
set_value(2);
set_currency_type("silver");
}
