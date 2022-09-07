#include <mudlib.h>
#include <security.h>

#define SAVE_FILE "/sgdomain/event/ev_tribe/ev_tribe"
#define NOBLE     "/sgdomain/event/ev_tribe/noble.c"

inherit M_ACCESS;

private mapping tribes;

void save_data()
{
        unguarded(1, (: save_object, SAVE_FILE, 1 :));
        return;
}
void create()
{
        unguarded(1, (: restore_object, SAVE_FILE, 1 :));
        if( !tribes||!mapp(tribes) ){
                tribes = ([ ]);
                save_data();
        }
}
void set_tribe(string who, string what, mixed val)
{
	mapping tmp;

	if( !(tmp=tribes[who])||!mapp(tribes[who]) ) tribes[who]=(["nation":([]) ]);
	tmp = tribes[who];
	tmp[what]=val;
	tribes[who] = tmp;

	save_data();
}
mixed get_tribe(string who, string what)
{
	if( !tribes[who]||!mapp(tribes[who]) ) return;
	return tribes[who][what];
}
void add_relation(string who, string na, int num)
{
	mapping tmp;

	tmp = get_tribe(who, "nation");
	if( !tmp[na] ) tmp[na] = 0;
	tmp[na]+=num;
	if( tmp[na]>=1000 ) tmp[na] = 1000;
}
void sub_relation(string who, string na, int num)
{
        mapping tmp;

        tmp = get_tribe(who, "nation");
        if( !tmp[na] ) tmp[na] = 0;
        tmp[na]-=num;
        if( tmp[na]<=0 ) tmp[na] = 1;
}
void stat_me(string who)
{
	int i;
	string out;
	mapping tmp;

	if( !who||!stringp(who)||who==""||member_array(who,keys(tribes))==-1 ) {
		out="����      ����   �����   ������   ��߱���   ������Ʒ\n";
		foreach(string ss in keys(tribes)){
			tmp = tribes[ss];
			if( !tmp||!mapp(tmp) )continue;
			out+=sprintf("%-10s%-7s%-11s%-11s%-11s%-11s\n",ss,
				tmp["name"],
				AREA_D->get_area(tmp["area"],"name"),
				chinese_number(tmp["num"]*1000),
				(!tmp["type"]?"���":TROOP_TYPE_D->get_troop_type(tmp["type"],"name")),
				tmp["obj"]);
		}
	} else {
		tmp = tribes[who];
		if( !tmp||!mapp(tmp) ) out = "not such tribe in this mud\n";
		else if( !(tmp=tmp["nation"])||!mapp(tmp) ) out = "no kingdom information availeble\n";
		else {
			out = "";
			foreach(string ss in keys(tmp)){
				i++;
				if( i>3 ) { i=0; out+="\n";}
				out+=sprintf("��%-8s��    %-4d",COUNTRY_D->get_country(ss,"name"), tmp[ss]);
			}
		}
	}
	write(out);
}
