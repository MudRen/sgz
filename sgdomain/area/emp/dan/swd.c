inherit OBJ;
inherit M_GETTABLE;
inherit M_EDIBLE;
void eat_dan()
{
	int sw;
	string p_id;
	p_id=this_body()->query_primary_id();
	sw=CHAR_D->get_char(p_id,"reputation");		//��ȡ����ֵ
	sw+=10000;
	CHAR_D->set_char(p_id,"reputation",sw);
	
	this_body()->simple_action(
"$N������һö%^H_MAGENTA%^������%^RESET%^��Ч�����ͼ�Ӱ���������ϱ����һ��㡣\n");
}
void setup()
{   set_id("shengwang dan", "%^H_MAGENTA%^������%^RESET%^");
    set_long("һ����ɫ��%^H_MAGENTA%^������%^RESET%^����˵���˿��Լ�һ���������");
    set_size(VERY_SMALL);
    set_gettable(1);
    set_num_eats(1);
    set_unit("��");
    set_eat_action((: eat_dan :));
    set_last_eat_action( (: eat_dan :));
}
