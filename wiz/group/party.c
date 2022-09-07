// party.c 
// by group on 25 Nov, 1998
#include <mudlib.h>
#include <party.h>

void start(string arg)
{
	string p_id,p_leader;
	string p_area;
//	string p_room;
	mixed p_auth;
	int p_res;
	int m_auth=1;
	p_id=this_body()->query_id()[0];
	p_area=CHAR_D->get_char(p_id,"area");
	p_leader=AREA_D->get_area(p_area,"leader");
	if(p_id!=p_leader)  // not the leader
	{
		write("只有地方首领和被授权的地方官才能下达此命令。\n");
		return;
	}
		if(((file_name(environment(this_body())))!=
((AREA_D->get_area(p_area,"path"))+(AREA_D->get_area(p_area,"meeting"))))||(p_area!=
		environment(this_body())->get_area()))
	{
		write("此处非宴会之所。\n");
		return;
	}
	p_res=(EV_PARTY)->can_party(p_area);
	switch(p_res)
	{
        case PT_OK:
            (EV_PARTY)->party(p_area);
            return;
        case PT_OTHERTASK:
	    write("太守现在正忙着呢，分不开身。\n");
         return;
        case PT_ALREADYPARTY:
	    write("看来你是忙糊涂了，这不是正在开宴会吗？\n");
         return;
	case PT_NOMONEY:
	    write ("钱粮不够可开不成宴会。\n");
	 return;	
	case PT_TIME:
	    write ("只有每年一月或七月一日至三日才可以开宴会。\n");
	    return;
        case PT_NOENOUTHCHAR :
	    write("总共没俩人，开什么宴会呀？！\n");
         return;
        case PT_TOOMANYABSENT:
          write("大家都太忙，看来宴会只好改期了。\n");
         return;
        }
}
