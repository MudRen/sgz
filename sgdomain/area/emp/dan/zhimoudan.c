#include <sanguo.h>
inherit OBJ;
inherit M_GETTABLE;
inherit M_EDIBLE;
void eat_dan()
{
	this_body()->set_zhimou_pure(30);
	
	this_body()->simple_action(
"$N�Ȳ������ء����ࡹһ�·���һö%^H_MAGENTA%^��ı��%^RESET%^����ʱ�е��Լ����Խ��ø���������ˡ�\n");
}
void setup()
{   set_id("zhimou dan", "%^H_MAGENTA%^��ı��%^RESET%^");
    set_long("һ�����˵�%^H_MAGENTA%^��ı��%^RESET%^����˵���˿���ʹ�˵���ı�츳��Ϊ���ֵ30��");
    set_size(VERY_SMALL);
    set_gettable(1);
    set_num_eats(1);
    set_unit("��");
    set_eat_action((: eat_dan :));
    set_last_eat_action( (: eat_dan :));
}
