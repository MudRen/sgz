// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */
#include <sanguo.h>
inherit TORCH;
inherit M_VALUE; // modified by fire
void setup() {
    set_adj("ħ��");
    set_id("torch", "ľ��");
    set_long( (: "һ��ϸ����ľͷ���ƺ���ĳ�ֻ�����\n" + (query_is_lit() ?
"������ȼ�����������ɫ���档\n" : "") :) );
    set_light_msgs("��$N��$O���ŵ�ʱ��һ����ɫ�Ļ�������������\n",
"��$n��$o��ȼ��ʱ�򣬷�����ɫ�Ļ�⡣\n");
    set_source( (: $1->can_light_the_magic_torch() ? (mixed)1 :
"�������ɫ�ƺ�����...\n" :) );
    set_fuel(-1); // never runs out
set_value(2);
set_currency_type("gold");
}
