// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

inherit OBJ;
inherit M_GETTABLE;
inherit M_DRINK_CONTAINER;
inherit M_DRINKABLE;

void setup()
{   set_id("bottle", "ƿ��", "flask");
    set_long("���������Ǹ���ͨ��ƿ�ӡ�");
    set_gettable(1);
    set_num_drinks(5);
    set_drink_action( (: this_body()->simple_action("$N����ƿ�Ӻ��˼��ڡ�\n$N") :));
    set_last_drink_action( (: this_body()->simple_action("$N����ƿ�Ӻ��˼��ڣ������һ��Ҳ�ȹ��ˡ�\n") :));
}
