// Cast.c for jimou
// By flee@sgz April 14 1999
#include <mudlib.h>
#include <log.h>
#include <daemons.h>

#define CAST_D "/daemons/cast_d.c"
#define JM_DIR "/sgdomain/jimou/"

inherit CMD;
inherit M_GRAMMAR;

private void main(string arg)
{
	int mp;
	string jm, whoid, who, what, whot;
	object player, jmob;
	mixed tmp;

	player 	= this_body();
	whoid  	= player->query_primary_id();

	if( !arg||!stringp(arg)||arg=="" )
                write("你要使用什么计谋？\n");
	else if( player->query_cur_hp()*4 <= player->query_cur_max_hp() )
                write("你的身体太虚弱了，不能使用任何计谋。\n");
	else {
		if( sscanf(arg, "%s on %s", jm, who) != 2 ){
                	if( sscanf(arg, "%s %s", jm, what) != 2 ){
				if( sscanf(arg, "%s on %s %s", jm, who, whot) != 3)
                        		jm = arg;
			}
        	};
		if( stringp(tmp=CAST_D->can_cast(whoid, jm)) )
			write(tmp);
		else {
			jmob = load_object(JM_DIR+jm+".c");
			if( !jmob||!objectp(jmob) ){
				SGSYS("Jimou object \""+jm+"\" does not exist !\n");
				return;
			}
        		if( stringp(tmp=player->check_condition(0)) ){
                		write(tmp);
                		return;
			}

			mp = 10 + 5*CAST_D->get_cast(jm, "level");
                	if( player->query_cur_mp() < mp ) {
                        	write("你精神不足，不能使用这种计谋！\n");
                        	return;
                	} else
                        	player->set_cur_mp(player->query_cur_mp()-mp);

			if( whot )who = who +" "+whot;
        		if( who )jmob->main(player, who);
        		else if( what )jmob->main(player, what);
        		else jmob->main(player);
        	tmp = DAY_D->query_date();
        	if(arrayp(tmp))
        	LOG_D->log(LOG_CAST, sprintf("ＭＵＤ时间：三国志%s年%s月%s:%s cast[%s] 当地时间:%s\n", 
        	CHINESE_DA->chinese_number(tmp[3]), 
        	CHINESE_DA->chinese_number(tmp[2]), 
        	DAY_D->query_string_day(),
        	whoid, arg, CHINESE_D->chinese_time(time())));
		}
	}
}
