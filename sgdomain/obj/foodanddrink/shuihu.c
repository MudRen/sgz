// shuihu.c by fire on 1999, Jan
inherit OBJ;
inherit M_GETTABLE;
inherit M_DRINKABLE;
void setup()
{   set_id("shuihu", "ˮ��");
    set_long("һ������װˮ��ľˮ����");
    set_gettable(1);
    set_max_drinks(20);
    set_con("��ˮ");
    set_drink_action((: this_body()->simple_action("$N����ˮ�����˼���"
		+query_con()+"��\n") :));
    set_last_drink_action( (: this_body()->simple_action("$Nҡ��ҡˮ����һ�ﲱ�������"+query_con()+"�ȵ�һ�ɶ�����\n") :));
    set_finish_drink_action( (: write("ˮ���Ѿ����ˡ�\n") :));
}
