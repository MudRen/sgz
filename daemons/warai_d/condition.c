#define CONDITION(x) "/sgdomain/condition/"+x+".c"

mapping query_con(int troop, string what)
{
	mapping con, troops;

	troops = TROOP_D->query_troops();
	if( member_array(troop, keys(troops)) == -1 )return ([ ]);
	con = troops[troop]["con"];
	if( !what || !stringp(what) || what == "" )return con;
	else return con[what];
}
void set_con(int troop, string what, mixed val)
{
	mapping con;

	con = query_con( troop, "");
	if( !con || !mapp(con) || !sizeof(con) )con = ([ ]);
	con[what] = val;
	TROOP_D->set_troops(troop, "con", con);
}
void update_con(int troop)
{
	mapping con, tmp;
	object what;

	con = query_con(troop, "");
	tmp = ([ ]);
	if( !con || !mapp(con) || !sizeof(con) )return;
	foreach(string tt in keys(con)){
		what = load_object(CONDITION(tt));
		tmp[tt] = what->update_condition(troop, con[tt]);
		if( !mapp(tmp[tt]) || tmp[tt]["time"] == 0 ) map_delete(tmp, tt);
	};

	TROOP_D->set_troops(troop, "con", tmp);
}
