// Cast daemon
// Flee@sgz Dec 2, 1999
#include <mudlib.h>
#include <security.h>

#define BEAT_DURATION 5
//#define SAVE_FILE "/data/daemons/cast_d.o"
#define SAVE_FILE "/data/daemons/cast_d"

inherit M_ACCESS;

private mapping casts;
static  mapping players;

void save_data()
{
        unguarded(1, (: save_object, SAVE_FILE, 1 :));
}
void create()
{
	unguarded(1, (: restore_object, SAVE_FILE, 1 :));
	if( !players||!mapp(players) ) players = ([ ]);
	if( !casts||!mapp(casts) ) casts = ([ ]);
	call_out("condition_heart", BEAT_DURATION);
call_out("auto_cast",5);
}
void condition_heart()
{
	mapping tmp;

	remove_call_out("condition_heart");
	call_out("condition_heart", BEAT_DURATION);
	foreach(string who in keys(players)){
		tmp = players[who];
		foreach(string id in keys(tmp)){
			if( member_array(id, keys(casts))==-1 ) map_delete(tmp, id);
			if( tmp[id]+casts[id]["duration"]<time() ) map_delete(tmp, id);
		}
		if( !sizeof(tmp) ) map_delete(players, who);
		else players[who] = tmp;
	}
}
mixed can_cast(string who, string what)
{
	int lvl;
	mapping tmp;

	if( !CHAR_D->get_char(who,"") ) return "只有游戏的角色才可使用计谋！\n";
	tmp = CHAR_D->get_char(who, "skills");
	if( !mapp(tmp)||!sizeof(tmp) ) return "很可惜，你并不会任何计谋！\n";
	lvl = tmp[what];
	if( member_array(what, keys(casts))==-1 ) return "没有这种计谋！\n";
	if( !lvl||lvl<casts[what]["req"] ) return "你的级别不足，无法使用这种计谋！\n";
	if( !(tmp=players[who])||!mapp(tmp) ) return 1;
	if( member_array(what, keys(tmp))!=-1 ) return "不能如此频繁的使用这种计谋！\n";
	return 1;
}
void reg_player(string who, string what)
{
	mapping tmp;

	tmp = players[who];
	if( !tmp||!mapp(tmp) ) tmp = ([ ]);
	tmp[what] = time();
	players[who] = tmp;
}
mixed get_cast(string id, string what)
{
	if( !id||!stringp(id)||id=="" ) return casts;
	if( member_array(id, keys(casts))==-1 ) return casts;
	if( !what||!stringp(what)||what=="" ) return casts[id];
	if( member_array(what, keys(casts[id]))==-1) return casts[id];
	return casts[id][what];
}
void set_cast(string id, string what, mixed val)
{
	if( !id||!stringp(id)||id=="" )
		write("要修改哪种计谋？\n");
	else if( member_array(id, keys(casts))==-1 )
		write("没有这种计谋！\n");
	else if( !what||!stringp(what)||what=="") 
		write("要修改哪种属性\n");
	else {
		if( !mapp(casts[id]) ) casts[id] = ([ ]);
		casts[id][what] = val;
		write("修改了！\n");
		save_data();
	}
}
void add_cast(string id)
{
	if( !id||!stringp(id)||id=="" )
		write("要增加什么计谋？\n");
	else if( member_array(id, keys(casts))!=-1 )
		write("这种计谋已经存在了！\n");
	else {
		casts[id] = ([ ]);
		write("增加了！");
		save_data();
	}
}
void remove_cast(string id)
{
	if( !id||!stringp(id)||id=="" )
		write("要删除哪种计谋？\n");
	else if( member_array(id, keys(casts))==-1 )
		write("没有这种计谋！\n");
	else {
		map_delete(casts, id);
		write("删除！\n");
		save_data();
	}
}
void stat_me()
{
	string out;
	mapping tmp;

	if( !sizeof(casts) ) return;
	out = sprintf("%-8s%-12s  %-6s%-14s  %-10s  %s\n",
                "名称", "ＩＤ", "等级", "使用间隔", "使用要求", "基本修养");
	foreach(string id in keys(casts)){
		tmp = casts[id];
		out+=sprintf("%-8s%-12s  %-6s%-14s  %-10s  %s\n",
			tmp["name"], id, chinese_number(tmp["level"]),
			chinese_number(tmp["duration"])+"秒",
			chinese_number(tmp["req"])+"级",
			(tmp["base"]==1?"武学修养":(tmp["base"]==2?"兵法修养":"治国修养")));
	}
	out+="三国志中共有"+chinese_number(sizeof(casts))+"种计谋！\n";

	write(out);
}
void auto_cast()
{
remove_call_out("auto_cast");
"/sgdomain/event/ev_cast.c"->start();
}
