// by fire on Dce 11, 1997 yangpi_jiudai.c ��Ƥ�ƴ�
#include <sanguo.h>
inherit M_VALUE;
inherit OBJ;
inherit M_GETTABLE;
inherit M_DRINK_CONTAINER;
inherit M_DRINKABLE;
void setup()
{   set_id("skin", "��Ƥ�ƴ�", "jiudai");
    set_long("һ������װ�ƺ�ˮ����Ƥ�ƴ���");
    set_gettable(1);
    set_num_drinks(5);
    set_value(1);
    set_currency_type("silver");
    set_con("�վ�");
    set_drink_action((: this_body()->simple_action("$N������Ƥ�ƴ����˼���"+query_con()+"��\n") :));
    set_last_drink_action( (: this_body()->simple_action("$Nҡ��ҡ��Ƥ�ƴ���һ�ﲱ�������"+query_con()+"�ȵ�һ�ɶ�����\n") :));
    set_finish_drink_action( (: write("��Ƥ�ƴ��Ѿ����ˡ�\n") :));
}
