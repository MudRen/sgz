#include <mudlib.h>
#define CAO "/sgdomain/job/feedgoat/cao.c"

inherit OBJ;
inherit M_INPUT;

private int grass_grow;

void setup()
{
	set_id("grass", "青草");
	set_in_room_desc("一大片绿油油的青草地(grass)");	
	grass_grow = 20;
	call_out("grow", 10 );
	return;
}
string long()
{
	if( grass_grow == 0 )
		return "一大片绿油油的青草地。但是现在所有的草都被割光了。";
	else if( grass_grow < 7 )
		return "一大片绿油油的青草地。几簇小草正随风摇动。";
	else if( grass_grow < 14 )
		return "一大片绿油油的青草地。像是一方绿色的毯子铺在地上。";
	else return "一大片绿油油的青草地。足有半人多高。";
}
void grow()
{
	grass_grow = grass_grow + 2 + random(3);
	tell_environment( this_object(), "青草静悄悄的生长着。\n");
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
				player->simple_action("$N刷刷的割下几大捆草来。\n");
				return;
			} 
			printf("你身上已经有一捆草了。\n");
			return;	
		};
	};
	printf("你要拿什么来割草呢？\n");
	return;
}			
