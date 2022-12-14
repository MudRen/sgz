// Cast.c for jimou
// By flee@sgz 04141999
#include <mudlib.h>
#include <daemons.h>

#define CAST_DIR "/wiz/group/cast/"

inherit CMD;
inherit M_GRAMMAR;

private void main(string arg)
{
	string jimou, who, what, *files;
	object player;

	player = this_body();
	if( !arg ){
		write("你要使用什么计谋？\n");
		return;
	};		
	if( player->query_cur_hp()*2 <= player->query_cur_max_hp() ){
		write("你的身体太虚弱了，不能使用任何计谋。\n");
		return;
	};

	files = get_dir( CAST_DIR );
	if( sscanf(arg, "%s on %s", jimou, who) != 2 ){
		if( sscanf(arg, "%s %s", jimou, what) != 2 )
			jimou = arg;
	};
	
	jimou = jimou + ".c";

	if( !sizeof(files) || member_array(jimou, files) == -1 ){
		write("没人会这种计谋。\n");
		return;
	};

	jimou = CAST_DIR + jimou;

	if( who )jimou->main(player, who);
	else if( what )jimou->main(player, what);
	else jimou->main(player);

	return;
}
