// candy.c ��������� by fire on Jan 7, 1998
#include <sanguo.h>
inherit M_VALUE;
inherit OBJ;
inherit M_GETTABLE;
inherit M_EDIBLE;
void eat_tan()
{
	string p_use;
	p_use=this_body()->query_userid();
        if(p_use=="ljty")
		this_body()->simple_action("$N�����������ǳ��˼��ڣ�����ѽ��\n");
	else
		this_body()->simple_action("$N�����������ǳ��˼��ڣ���ʹ�����ش����\n");
}
void eat_last_tan()
{
	string p_use;
	p_use=this_body()->query_userid();
        if(p_use=="ljty")
this_body()->simple_action("$N��ʣ�µĴ��������һ�ѷŵ��������ѽ��\n");
	else
this_body()->simple_action("$N��ʣ�µĴ��������һ�ѷŵ������ʹ�����ش����\n");
}
void setup()
{   set_id("candy", "���������", "tang");
    set_long("�������˵Ĵ�������ǡ�");
    set_size(VERY_SMALL);
    set_gettable(1);
    set_num_eats(3);
    set_unit("��");
    set_value(1);
    set_currency_type("gold");
    set_eat_action((: eat_tan :));
    set_last_eat_action( (: eat_last_tan :));
}
