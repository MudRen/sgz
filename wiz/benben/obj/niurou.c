// niurou.c ����ţ��� by benben
#include <sanguo.h>
inherit M_VALUE;
inherit OBJ;
inherit M_GETTABLE;
inherit M_EDIBLE;
void eat_tan()
{
	string p_use;
	p_use=this_body()->query_userid();
        if((p_use=="benben")||(p_use=="fire"))
		this_body()->simple_action("$N��������ţ��ɳ��˼��ڣ�����ѽ����$n��֨��֨������ô�㣬��
�̲�ס���˿ڿ�ˮ��\n");
	else
		this_body()->simple_action("$N��������ţ��ɳ��˼��ڣ�ֻ���������ꡱһ����$n�������Ե�
�ˣ�ԭ��ҧ�˿�ţ�\n");
}
void eat_last_tan()
{
	string p_use;
	p_use=this_body()->query_userid();
        if((p_use=="benben")||(p_use=="fire"))
this_body()->simple_action("$N��ʣ�µ�����ţ���һ�ѷŵ�����ù��ѽ������һ����\n");
	else
this_body()->simple_action("$N��ʣ�µ�����ţ���һ�ѷŵ�������ҵ���ѽ������$N�ҽ�
һ�����³�����������\n");
}
void setup()
{   set_id("niurou","����ţ���");
    set_long("һ�������������ţ��ɡ�");
    set_adj("������");
    set_unit("��");
    set_gettable(1);
    set_num_eats(2);
    set_value(1);
    set_currency_type("gold");
    set_eat_action((: eat_tan :));
    set_last_eat_action( (: eat_last_tan :));
}
