// mantou.c ��ͷ��cheap food
// by fire on Jan 1999
inherit OBJ;
inherit M_GETTABLE;
inherit M_EDIBLE;
inherit M_VALUE;
void setup()
{   set_id("mantou", "��ͷ");
    set_long("������Ĵ������ͷ���������ͺóԡ�");
	set_eat_val(8);
    set_size(SMALL);
    set_gettable(1);
    set_num_eats(20);
    set_unit("ö");
	set_currency_type("silver");
    set_value(1);
	set_eat_action("$Nҧ��һ����ͷ����óԡ�\n");
    set_last_eat_action("$N��ʣ�µ���ͷһ�������������û�ҽ���������ȥ��\n");
	set_can_sell("�ԵĶ������ܵ�����\n");
}
