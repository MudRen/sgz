#include <mudlib.h>
#define GRASS __DIR__"grass.c"

inherit M_WEAPON;
inherit M_VALUE;

string *color = ({"��ɫ", "��ɫ", "��ɫ", "��ɫ", "��ɫ", "��ɫ", "��ɫ", });
string *taste = ({"��ζ", "��ζ", "��ζ", "��ζ", "��ζ", "ɬζ", "��ζ", });

void setup() {
        set_id("chu tou", "Сҩ��", "chu");
        set_unit("��");
        set_in_room_desc("һ�ѻ��Ӳ�ҩ�õ�Сҩ��(chu tou)");
        set_attack_ability(20);
        set_attack_power(10);
        set_defence_ability(1);
        set_combat_messages("combat-blade");
    	set_value(300);
    	set_currency_type("coin");
}
int direct_use_obj()
{
	return 1;
}
int do_use_it()
{
	int hp, i, j, k, m;
	string area, *place;
	object who, env, *other, grass;

	who   = environment(this_object());
	env   = environment(who);
	area  = env->get_area();
	i     = who->query_job("hua tuo", "color");
	j     = who->query_job("hua tuo", "taste");
	place = who->query_job("hua tuo", "place");
	hp    = who->query_cur_hp();

	if( !place || !arrayp(place) )place = ({ });
	if( area != who->query_job("hua tuo", "area") 
		&& member_array(area, AREA_D->get_area(who->query_job("hua tuo", "area"),"neighbor")) == -1 )
		write("����û��ʲôҩ��ֵ��ע��ġ�\n");
	else if( member_array(file_name(env)+".c", place) != -1 )
		write("�����类�����˸��׳����ˡ�\n");
        else if( hp < 15 )
		write("������Ϣһ���ٸɰɡ�\n");
	else if( env->is_indoors() )
		write("����������ô����ҩ�ݡ�\n");
	else {
                who->set_cur_hp(hp-10);
		who->simple_action("$N����ҩ���ڵ�����ϸ�������š�\n");
		who->start_busy(3, "����æ����ҩ�أ�\n");
		if( random(3) == 1 ) {
			place = place + ({ file_name(env)+".c" });
			grass = new(GRASS);
			grass->move(who);
			who->set_job("hua tuo", "place", place);
			who->simple_action("$NС��������ڳ�һ���ҩ��\n");
			if( random(sizeof(place)) > 3 ){
				grass->set(who->query_id()[0], "ok");
				grass->set_long("һ��"+color[i]+taste[j]+"��ҩ�ݡ�");
				write("���������ڵ��ˡ�\n");
				write("��һʱ�˷ܣ�ž��ҩ�����ˡ�\n");
				destruct( this_object() );
				return 2;
			} else {
				k = random(sizeof(color));
				while(k==i)k = random(sizeof(color));
				m = random(sizeof(taste));
				while(m==j)m = random(sizeof(taste));
				grass->set_long("һ��"+color[k]+taste[m]+"��ҩ�ݡ�");
			}
		} else {
			who->simple_action("����$NʲôҲû���֡�\n");
		}
	};

	return 1;
}

