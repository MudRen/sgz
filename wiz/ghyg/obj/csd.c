inherit OBJ;
inherit M_GETTABLE;
inherit M_EDIBLE;
void eat_dan()
{
	int rm;
	rm=this_body()->query_shouming();
	rm+=random(5)+2;
	rm=bmin(100,rm);
	this_body()->set_shouming(rm);
	if(this_body()->query_gender()==1) {
		this_body()->simple_action(
"$N����������һö%^H_YELLOW%^�������ϵ�%^RESET%^��˫Ŀ΢�գ�����������һ������ֻ���û����泩��\n");
	}
	else {
		this_body()->simple_action(
"$N����һö%^H_YELLOW%^�������ϵ�%^RESET%^�������Ĳ��ѣ���Ȼ�뵽���ս��ϣ����ɵá���������̾��һ����\n");
	}
}
void setup()
{   set_id("changsheng dan", "%^H_YELLOW%^�������ϵ�%^RESET%^");
    set_long("һ�����ɫ��%^H_YELLOW%^�������ϵ�%^RESET%^����˵���˿����������١�");
    set_size(VERY_SMALL);
    set_gettable(1);
    set_num_eats(1);
    set_unit("��");
    set_eat_action((: eat_dan :));
    set_last_eat_action( (: eat_dan :));
}
