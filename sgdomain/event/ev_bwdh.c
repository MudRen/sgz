#include <mudlib.h>
#include <security.h>
#define SAVE_FILE "/sgdomain/event/ev_bwdh/ev_bwdh"
#define JOIN_ROOM "/sgdomain/event/ev_bwdh/join_room.c"
inherit M_ACCESS;
private int times=0;
private int lev=0;
void save_data()
{
        unguarded(1, (: save_object, SAVE_FILE, 1 :));
        return;
}
void create()
{
        unguarded(1, (: restore_object, SAVE_FILE, 1 :));
	if( !times || !intp(times) ){
		times = 1;
		save_data();
	}
}
void check_bwdh(){
	string a;
	object room,master;
	a=AREA_D->pick_area();
	if(lev==0) 
		lev++;
	else {
		times++;
		lev=0;
	}
	save_data();
	room = load_object(JOIN_ROOM);
	master = present("matrial master", room);
	master->start(times,lev,a);
}