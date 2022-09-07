// wotou.c ��ͷ��cheap food
// by fire on Jan 1999
inherit OBJ;
inherit M_GETTABLE;
inherit M_EDIBLE;
inherit M_VALUE;
void setup()
{
    if(file_name(previous_object())!=OBJ_D)
    {
            write("�Ƿ�����.\n");
            this_object()->remove();
            return;
    }
	/*set_id("wotou", "��ͷ");
    set_long("�ƻƵ���ͷ���������˵�һ��ʳ����");
	set_eat_val(10);
    set_size(SMALL);
    set_gettable(1);
    set_num_eats(10);
    set_unit("ö");
	set_can_drop("��ͷ��Ȼ�ѳԣ�Ҳ��������ѽ��\n");
	set_can_give("��������ͷҲ����˼���ˡ�\n");
    set_eat_action("$Nҧ��һ����ͷ�����ѳԣ����û�³�����\n");
    set_last_eat_action("$N��ʣ�µ���ͷһ�������������û�ҽ���������ȥ��\n");*/
}
int init_obj(string p_id)
{
	mixed par;
	par=OBJ_D->get_obj(p_id);

	set_id(p_id,par["name"]);
	add_id(p_id+" obj");
	set_unit(par["unit"]);

	set_in_room_desc("һ"+par["unit"]+par["name"]+"("+p_id+")\n");

	set_size(par["size"]);
	set_gettable(1); // food always can get
	set_long(par["long"]);

    set_currency_type(par["currency_type"]);
    set_value(par["value"]);

	set_eat_val(par["eat_val"]);
	set_drink_val(par["drink_val"]);
	set_num_eats(par["num_eats"]);		//�ܳԶ��ٴ�
	set_eat_action(par["eat_action"]);	//�ԵĶ�����ʾ������һ����������
	set_last_eat_action(par["last_eat_action"]);//���һ�γԵ���ʾ

	set_can_drop(par["can_drop"]);
	set_can_give(par["can_give"]);
	set_can_sell(par["can_sell"]);
	set_is_keeping(par["is_keeping"]);
}
int sg_obj() // so it is not a common obj
{
	return 1;
}

string check_obj()
{
	string ret;
	object p_id=this_object()->query_id()[0];
	mixed inf;
	inf=OBJ_D->get_obj(p_id);

	ret="��Ʒ���"+sprintf("%-8s  ",OBJ_D->type_name(inf["type"]))+"\n";
	ret+="ʳ��ָ���"+sprintf("%+d\n",inf["eat_val"])+
		"��ˮ�ָ���"+sprintf("%+d\n",inf["drink_val"])+
		"��Ǯ��"+
		((inf["value"] < 0) ? ("�޼�֮��"):(CHINESE_D->chinese_value(inf["value"])))+"\n";
	ret+="�ܳԼ��ڣ�"+sprintf("%d",inf["num_eats"])+
		"\n���˼��ڣ�"+this_object()->query_num_eats()+"\n";
	return ret;

}

mixed direct_check_obj()
{
	return 1;
}