inherit TORCH;
inherit M_VALUABLE;
void setup() {
    set_adj("д��ר��");
    set_id("pen", "�ɿ˸ֱ�");
    set_long( (: "һ֧�ɿ˸ֱʣ�һ���͸�������С�\n" + (query_is_lit() ?
"�ƺ�����һֻ������\n" : "") :) );
    set_light_msgs("��$N��$O���ŵ�ʱ��һ����ɫ�Ļ�������������\n",
"��$n��$o��ȼ��ʱ�򣬷�����ɫ�Ļ�⡣\n");
    set_source( (: $1->can_light_the_magic_torch() ? (mixed)1 :
"�������ɫ�ƺ�����...\n" :) );
    set_fuel(-1); // never runs out
set_value(15);
}
