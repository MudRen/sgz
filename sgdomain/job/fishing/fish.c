// fish.c (����)
#include <mudlib.h>

inherit OBJ;
inherit M_GETTABLE;
inherit M_EDIBLE;

void setup()
{
        set_id("fish", "����");
        set_unit("��");
        set_gettable(1);
        set_num_eats(1);
set_last_eat_action((: this_body()->simple_action("$N����һ�����������ȥ��"+
        "\n") :));
        return;
}

void modify(int size) {
	if ( size < 3 )
                set_long("һ�����������С��");
	else
                set_long("һ�����ʴ���");
}
