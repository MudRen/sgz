// ���
#include <mudlib.h>
#include <daemons.h>
#include <ansi.h>

#define WEATHER_CHANNEL "weather"
#define CHANNEL_FORMAT "%%^WEATHER_CHANNEL%%^��%s��%s%%^RESET%%^\n"

void show_wind(string where, int wind);

void main(object ob, string wind)
{
	int i;
	string where;
	object env;
	string *winds = ({"�޷�", "����", "������", "����", "���Ϸ�", "�Ϸ�", "���Ϸ�", "����", "������",});
	env = environment( ob );
        while( env && !inherits(BASE_ROOM, env) )env = environment( env );
	if( !where = env->get_area() ){
		write("ֻ����ս���ϲ��ܸı����\n");
		return;
	};
	if( !wind || !stringp(wind) || member_array(wind, winds) == -1 ){
                write("���ڱ������ķ����ǣ�" + DAY_D->get_wind_short(AREA_D->get_area(where, "wind")) + "��\n");
		write("�޷磬���磬�����磬���磬���Ϸ磬�Ϸ磬���Ϸ磬���磬�������硣\n");
                return;
        };
	if( member_array(wind, winds) == AREA_D->get_area(where, "wind") ){
		write("���ڵķ�����ǣ�" + DAY_D->get_wind_short(AREA_D->get_area(where, "wind")) + "��\n");
		return;
	};

	// In the furture, We have to consider the player's ablility
	// add the exp of this jimou, reduce mp, etc.

	ob->simple_action("$N��ϥ���������������дʡ�\n");
	ob->simple_action("ת�ۼ䣬�����ܲ����������\n");
	ob->start_busy(10, "����æ�������ء�");
	load_object("/daemons/cast_d.c")->reg_player(ob->query_primary_id(), "fengbian");
        ob->award_exp(ob->query_sk_level("sk_zhimou")/2+random(20), "fengbian");
	call_out("show_result", 5+random(5), ob, where, member_array(wind, winds));
}
void show_result(object ob, string where, int wind)
{
	ob->stop_busy();
	if( random(2) == 1 ){
		ob->simple_action("һ������������������һ�����죬����ı��ˡ�\n");
		AREA_D->set_area(where, "wind", wind);
		show_wind(where, wind);
	} else {
		ob->simple_action("һ�����������������ô���$N���ϡ�\n");
		ob->set_cur_hp(0);
	}
	return;
}
void show_wind(string where, int wind)
{
	string w_info;
	object env, body, *players;
	
	players = users();
	foreach( object user in players ){
		if( !body = user->query_body() )continue;
		if( !env = environment(body) )continue;
		while (env && !inherits(BASE_ROOM, env))env = environment(env);
		if( !(env->get_area()) || env->get_area() != where )continue;
		if( wind ) w_info = "��ʼ��"+DAY_D->get_wind_short(wind)+"�ˡ�";
		else w_info = "��ͣ�ˡ�";
		tell(({user}), sprintf(CHANNEL_FORMAT, "����", w_info), MSG_INDENT);
	};
	return;
}
