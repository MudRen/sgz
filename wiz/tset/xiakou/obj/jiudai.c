//  jiudai.c
//  �ƴ�
//  created by tset 1/17/98
//  last updated by tset 1/19/98

#include <sanguo.h>

inherit M_VALUE;
inherit OBJ;
inherit M_GETTABLE;
inherit M_DRINK_CONTAINER;
inherit M_DRINKABLE;

void setup() {
        set_id("jiudai", "�ƴ�", "skin");
        set_long("һ������װ�ƺ�ˮ�ľƴ���");
        set_gettable(1);
        set_num_drinks(5);
        set_value(100);
        set_currency_type("coin");
        set_con("�׾�");
   set_drink_action((: this_body()->simple_action("$N����ƴ����˼���"+
        query_con()+"��\n") :));
   set_last_drink_action( (: this_body()->simple_action("$Nҡ��ҡ�ƴ���"+
        "һ�ﲱ�������"+query_con()+"�ȵ�һ�ɶ�����\n") :));
   set_finish_drink_action( (: write("�ƴ��Ѿ����ˡ�\n") :));
}

