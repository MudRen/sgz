// candy.c ��������� by fire on Jan 7, 1998
#include <sanguo.h>
inherit OBJ;
inherit M_GETTABLE;
inherit M_EDIBLE;
void eat_dan()
{
	int rm;
	mixed gift;
	string p_id;
	rm=this_body()->query_sg_rongmao();
	rm+=random(3)+1;
	rm=bmin(30,rm);
	this_body()->set_sg_rongmao(rm);
	p_id=this_body()->query_primary_id();
	gift=CHAR_D->get_char(p_id,"gift");
	if(mapp(gift)) {
		gift["rongmao"]=rm;
		CHAR_D->set_char(p_id,"gift",gift);
	}
	if(this_body()->query_gender()==1) {
		this_body()->simple_action(
"$N�Ȳ������ء����ࡹһ�·���һö%^H_MAGENTA%^���յ�%^RESET%^��һ�߲������ŵ�����ģ�Լ�����ס�\n");
	}
	else {
		this_body()->simple_action(
"$N����һö%^H_MAGENTA%^���յ�%^RESET%^������ط�����У�������ȥ��\n$N��æ�ҵ�һ��ͭ�����������գ������Լ���ø������������ˡ�\n");
	}
}
void setup()
{   set_id("yangyan dan", "%^H_MAGENTA%^���յ�%^RESET%^");
    set_long("һ�����˵�%^H_MAGENTA%^���յ�%^RESET%^����˵���˿���ʹ�˱�ø�Ư����");
    set_size(VERY_SMALL);
    set_gettable(1);
    set_num_eats(1);
    set_unit("��");
    set_eat_action((: eat_dan :));
    set_last_eat_action( (: eat_dan :));
}
