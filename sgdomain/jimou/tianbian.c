// ���
#include <mudlib.h>
#include <daemons.h>
#include <ansi.h>

#define WEATHER_CHANNEL "weather"
#define CHANNEL_FORMAT "%%^WEATHER_CHANNEL%%^��%s��%s%%^RESET%%^\n"

void show_weather(string where, int weather);

void main(object ob, string weather)
{
	int i;
	string where;
	object env;
	string *weathers = ({"����", "����", "����", "��ѩ", "���", "����", "����"});

	env = environment( ob );
        while( env && !inherits(BASE_ROOM, env) )env = environment( env );
	if( !where = env->get_area() ){
		write("ֻ����ս���ϲ��ܸı�������\n");
		return;
	};
	if( !weather || !stringp(weather) || member_array(weather, weathers) == -1 ){
                write("���ڱ������������ǣ�" + DAY_D->get_weather_short(AREA_D->get_area(where, "weather")) + "��\n");
		write("�����������ת��Ϊ�����죬���꣬������ѩ����磬���꣬�������\n");
                return;
        };
	if( member_array(weather, weathers) == AREA_D->get_area(where, "weather") ){
		write("���ڵ��������ǣ�" + DAY_D->get_weather_short(AREA_D->get_area(where, "weather")) + "��\n");
		return;
	};

	// In the furture, We have to consider the player's ablility
	// add the exp of this jimou, reduce mp, etc.

	ob->simple_action("$N��ϥ���������������дʡ�\n");
	ob->simple_action("ת�ۼ䣬�����ܲ����������\n");
	ob->start_busy(10, "����æ�������ء�");
	load_object("/daemons/cast_d.c")->reg_player(ob->query_primary_id(), "tianbian");
        ob->award_exp(ob->query_sk_level("sk_zhimou")/2+random(20), "tianbian");
	call_out("show_result", 5+random(5), ob, where, member_array(weather, weathers));
}
void show_result(object ob, string where, int weather)
{
	ob->stop_busy();
	if( random(2) == 1 ){
		ob->simple_action("һ������������������һ�����죬�����ı��ˡ�\n");
		AREA_D->set_area(where, "weather", weather);
		show_weather(where, weather);
	} else {
		ob->simple_action("һ�����������������ô���$N���ϡ�\n");
		ob->set_cur_hp(0);
	}
	return;
}
void show_weather(string where, int weather)
{
        string w_info;
        object env, body, *players;

        players = users();
        foreach( object user in players ){
                if( !body = user->query_body() )continue;
                if( !env = environment(body) )continue;
                while (env && !inherits(BASE_ROOM, env))env = environment(env);
                if( !(env->get_area()) || env->get_area() != where )continue;
		w_info = "����תΪ" + DAY_D->get_weather_short(weather)  + "��";
                tell(({user}), sprintf(CHANNEL_FORMAT, "����", w_info), MSG_INDENT);
        };
        return;
}
