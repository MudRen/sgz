//  mianbing.c
//  ���
//  created by tset 1/17/98
//  last updated by tset 1/17/98

#include <sanguo.h>

inherit M_VALUE;
inherit OBJ;
inherit M_GETTABLE;
inherit M_EDIBLE;

void setup() {
        set_id("mianbing", "���", "bing");
        set_long("һ��������������");
        set_unit("��");
        set_gettable(1);
        set_value(50);
        set_currency_type("coin");
        set_num_eats(2); 
  set_eat_action((: this_body()->simple_action("$N������������˼��ڡ�"+
        "\n") :));
  set_last_eat_action((: this_body()->simple_action("$N��ʣ�µ����"+
        "�Եøɸɾ�����\n") :));
}

