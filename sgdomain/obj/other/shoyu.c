// shouyu.c ���׵�����
inherit OBJ;
inherit M_GETTABLE;
void setup()
{   
    set_id("shouyu", "%^GREEN%^���׵�����%^RESET%^");
    add_id("ysf pass");
    set_size(VERY_SMALL);
   set_long("����һ�ź��׵����԰䷢��������������\n�Ϳ���ȥһЩ�ʹ���ƽ������ȥ�ĵط���\n");
    set_gettable(1);
    set_can_drop(0);
   set_unit("��");
    set_can_give(0);
}
