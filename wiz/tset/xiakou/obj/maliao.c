//  maliao.c
//  ����
//  created by tset 1/17/98
//  last updated by tset 1/17/98

#include <sanguo.h>

inherit M_VALUE;
inherit OBJ;
inherit M_GETTABLE;

void setup() {
        set_id("maliao", "����");
        set_long("һ�����ʵ�����");
        set_unit("��");
        set_gettable(1);
        set_value(20);  
        set_currency_type("coin");
}
 
