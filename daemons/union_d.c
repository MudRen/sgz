#include <mudlib.h>
#include <security.h>
#include <daemons.h>

#define SAVE_FILE "/data/daemons/union_d"

inherit M_ACCESS;
inherit __DIR__"union_d/cases.c";
inherit __DIR__"union_d/elect.c";

private mapping info;

void save_data()
{
    unguarded(1, (: save_object, SAVE_FILE, 1 :));
    return;
}
void create()
{
    unguarded(1, (: restore_object, SAVE_FILE, 1 :));
    if ( !sizeof(info)||!mapp(info) ){
	info = (["last_time":time(), "times":0, "stage":"", "turns":0, "end":0,]);
    }
    call_out("check_time", 60);
}
void check_time()
{
}
