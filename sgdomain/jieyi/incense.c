// edit by row on June 1999
/* Do not remove the headers from this file! see /USAGE for more info. */

inherit TORCH;
inherit M_VALUABLE;

void setup() {
    set_id("incense", "%^CYAN%^��%^RESET%^");
    set_unit("֦");
    set_long( (: "һ֦ϸϸ�����һ������ݷ𣬼�����ض�Ҫ�õ���\n" + (query_is_lit() ? "���Ѿ�����ȼ�ˣ����ð���������̡�\n" : "") :) );
    set_light_msgs("$N���������ؽ�$O�յ������ϣ�С������ص��š�\n", "$n�����ؽ�$o��ȼ����ʱ�����ж���һ�����ĵ���ζ��\n");
//    set_source( (: $1->can_light_the_magic_torch() ? (mixed)1 : "�������ɫ�ƺ�����...\n" :) );
    set_fuel(-1); // never runs out
	set_value(100);
        call_out("dest",900);
}
void dest()
{
	object ob;
//        ob=present("incense",this_body());
ob=this_object();
	if(objectp(ob))
	{
	write("���ڳ�ʱ��û��ʹ�ã�%^CYAN%^��%^RESET%^����һ����ɢ�ɻ��ˡ�\n");
	destruct(ob);
	}
}
