#include <mudlib.h>

#define __WORK__ 20

inherit MONSTER;
inherit M_CHAR;
inherit M_SMARTMOVE;

private int food=10;
private int water=10;
private int count=0;
private object owner;
string *emotes = ({"$N����¶�����õ�Ц�ݡ�",
		"$N���ֵ�������ȥ��",
		"$N�������Ʋ��֡�",
		"$Nʹ����������죬�������ʹ��������",
});

void setup()
{
	set_name("goat", "Сɽ��");
	set_gender(0);
	set_proper_name("һֻ�ɰ���Сɽ��");
	set_in_room_desc("Сɽ��(goat)");
	set_long("һֻ�ɰ���Сɽ������Ľ��´�����ȥ��");	
	call_out("heart_beat", 10);
}
void set_owner(object player)
{
	owner = player;
	return;
}
mixed indirect_give_obj_to_liv(object ob, object liv)
{
	object obj;
/*
	if( objectp(obj = present("grass", environment(this_object())))&& 
		obj->direct_cut_obj() ){
		return "С����˵��ڲݵ���������ȥ��\n";
	};
*/
	if( !ob || !objectp(ob) )return "С����ֵĴ������㡣\n";
	if( ob->is_food() ){
		this_body()->simple_action("$Nι��һЩ��ݸ�С��\n");
		if( food >= 8 )this_object()->simple_action("$Nһ�Ű�����ߵ���һ�ߡ�");
		else this_object()->simple_action("$N���ھͰ���ݳԹ��ˡ�\n");
		food ++;
		destruct(ob);
		return "С����˵Ľ��˼�����\n";
	} else if( ob->direct_fill_obj() ){
		this_body()->simple_action("$N���С���ˮ�ȡ�\n");
                if( water >= 8 )this_object()->simple_action("$Nһ����Ƶ��ܿ��ˡ�\n");
                else this_object()->simple_action("$NС���ͷ���˼���ˮ��\n");
                water ++;
		ob->move(environment(this_object()));
                return "С����˵Ľ��˼�����\n";
	};
	return "С����ֵĴ������㡣\n";
}	
void heart_beat()
{
	remove_call_out("heat_beat");
	if( random(3) == 1 )food--;		 
	if( random(3) == 1 )water--;
	count++;

	if( food < 0 || water < 0  ){
		this_object()->simple_action("$N���ڵ��������˼��£������ˡ�\n");
		tell_user(owner->query_id()[0], "���ϧ����û�������������\n");
		owner->finish_job("feedgoat");
		destruct( this_object() );
		return;
	};
	if( count >= __WORK__ ){
		tell_user(owner->query_id()[0], "���������Ѿ�����ˣ��Ͻ���ȥ����ɡ� \n");
		owner->set_job("feedgoat", "end", 1);
		destruct( this_object() );
		return;
	};
	if( !present(owner->query_id()[0], environment(this_object())) ){
		tell_environment(this_object(), "С��û��ע�⣬��֪�ܵ��Ķ�ȥ�ˡ�\n");
		tell_user(owner->query_id()[0], "����С���߶��ˣ�\n���ϧ����û�������������\n");
		owner->finish_job("feedgoat");
                destruct( this_object() );
                return;
        };
	if( water <= 5 )this_object()->targetted_action(
		"$N��$T�Ľ���������ȥ������ǿ��ˡ�\n", owner);
	else if( food <= 5 )this_object()->targetted_action(
		"$N��$T�Ľ���������ȥ�����ֵ㶫���ԡ�\n", owner);
	else this_object()->simple_action(emotes[random(sizeof(emotes))]);
									
	call_out("heart_beat", 15);
	return;
}