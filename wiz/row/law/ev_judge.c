#include <mudlib.h>
#include <security.h>
#include <daemons.h>

#define ANNUAL_TIME 		172800
#define TIME_WAIT_FOR_JURY 	10
#define TIME_WAIT_FOR_JUDGE     15
#define SAVE_FILE "/wiz/flee/law/ev_judge"

inherit M_ACCESS;
inherit __DIR__"ev_judge/elect.c";
inherit __DIR__"ev_judge/announce.c";
inherit __DIR__"ev_judge/jury.c";

private mapping info;
private mapping cases;
private mapping jury;

void initial_judge(int tt);

void save_data()
{
    set_privilege(1);
    unguarded(1, (: save_object, SAVE_FILE, 1 :));
    return;
}
void create()
{
    set_privilege(1);
    unguarded(1, (: restore_object, SAVE_FILE, 1 :));
    if ( !sizeof(info)||!mapp(info) ){
	info = (["last_time":time(), "times":0, "stage":"", "turns":0, ]);
    }
    call_out("check_time", 60);
}
void check_time()
{
    remove_call_out("check_time");

    if ( time() > info["last_time"]+ANNUAL_TIME ) {
	info["last_time"] = time();
	info["times"] = info["time"] + 1;
	save_data();
        initial_judge(info["times"]);
    } else 
	call_out("check_time", 60);
}
void initial_judge(int tt)
{
    if ( !sizeof(jury) ) {
        if ( !sizeof(jury=elect()) ) {
	} else {
	    announce_elect_result( keys(jury) );
	}
        call_out("check_time", 60);
	return;
    } else {
        call_for_meeting( keys(jury) );
        info["stage"] = "wait_ministers";
        info["turns"] = 1;
	call_out("do_process", 20);
    }
}
void do_process()
{
    string s, *ss;
    mapping mm;

    remove_call_out("do_process");

    info["turns"] = info["turns"] + 1;
    if ( info["stage"] == "wait_ministers" ){
 	ss = check_ministers(jury);
        if( !sizeof(ss) ) {
            info["turns"] = 1;
            info["stage"] = "start_meeting";
            announce_start();
        } else call_for_ministers( ss );
        if ( info["turns"] > TIME_WAIT_FOR_JURY ) {
            punish_min(ss);
            info["turns"] = 1;
            info["stage"] = "start_meeting";
            announce_start();
        }
    } else if ( info["stage"] == "start_meeting" ) {
        if ( !sizeof(cases) ){
	    announce_end();
            info["stage"] = "end_meeting";
        } else {
	    info["stage"] = "process_meeting";
            info["turns"] = 1;
	}
    } else if ( info["stage"] == "process_meeting" ){
	mm = filter_mapping(cases, (: !cases[$1]["comment"] :) );
        if ( !sizeof(mm) ) {
          announce_end();
          info["stage"] = "end_meeting";
	}
        foreach( s in jury ) jury[s] = 0;
	s = keys(mm)[0];
        info["stage"] = "case";
        info["turns"] = 0;
        info["case"]  = s;
    } else if ( info["stage"] == "case" ) {
        info["turns"] = info["turns"] + 1;
        if ( info["turns"] > TIME_WAIT_FOR_JUDGE ) {
            info["stage"] = "process_meeting";
            announce_nojudge(info["case"]);
            cases[info["case"]]["comment"] = "no decision made\n";
        }
        announce_process(info["times"]);
        call_for_judge();
        if ( check_judge(jury) == 1 ) {
            info["stage"] = "process_meeting";
	    announce_who_win( info["case"] );
            cases[info["case"]]["comment"] = "win\n";
        } else if ( check_judge(jury) == -1 ) {
            info["stage"] = "process_meeting";
            announce_who_lose( info["case"] );
            cases[info["case"]]["comment"] = "lose\n";
        }
    } else if ( info["stage"] == "end_meeting" ) {
	reward_all_min( jury );
        end_meeting();
	call_out("check_time", 60);	
	return;
    } else {
	call_out("check_time", 60);
	SGSYS("error in judge, see /data/event/ev_judage for details");
	return;
    }

    call_out("do_process", 20);
}
