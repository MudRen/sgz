#include <mudlib.h>
#define CAO "/sgdomain/job/feedgoat/cao.c"

inherit OBJ;
inherit M_INPUT;

private int grass_grow;

void setup()
{
	set_id("grass", "���");
	set_in_room_desc("һ��Ƭ�����͵���ݵ�(grass)");	
	grass_grow = 20;
	call_out("grow", 10 );
	return;
}
string long()
{
	if( grass_grow == 0 )
		return "һ��Ƭ�����͵���ݵء������������еĲݶ�������ˡ�";
	else if( grass_grow < 7 )
		return "һ��Ƭ�����͵���ݵء�����С�������ҡ����";
	else if( grass_grow < 14 )
		return "һ��Ƭ�����͵���ݵء�����һ����ɫ��̺�����ڵ��ϡ�";
	else return "һ��Ƭ�����͵���ݵء����а��˶�ߡ�";
}
void grow()
{
	grass_grow = grass_grow + 2 + random(3);
	tell_environment( this_object(), "��ݾ����ĵ������š�\n");
	call_out("grow", 15 );
	if( grass_grow > 20 )grass_grow = 20;
	return;
}
int set_grass(int lost)
{	
	grass_grow = grass_grow - lost;
	if( grass_grow < 0 )grass_grow = 0;
	return grass_grow;
}		
mixed direct_cut_obj()
{
	return 1;
}
void do_cutting()
{
	int i;
	object player, cao;
	object *obs;
	
	player = this_body();
	obs = all_inventory( player );
	for( i = 0; i < sizeof( obs ); i++){
		if( obs[i]->query_defence_ability()&&obs[i]->can_cut() ){
			cao = present("grass", player);
			if( !cao || !objectp(cao) ){
				cao = new( CAO );
				cao->move( player );
				set_grass( 2 );
				player->simple_action("$Nˢˢ�ĸ��¼�����������\n");
				return;
			} 
			printf("�������Ѿ���һ�����ˡ�\n");
			return;	
		};
	};
	printf("��Ҫ��ʲô������أ�\n");
	return;
}			
