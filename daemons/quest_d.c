// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

#include <mudlib.h>
#include <log.h>

inherit M_DAEMON_DATA;


mapping quests = ([]);
static int total_points;

private
void
calculate_total_points()
{
    int     i;
    string*     keys;

    total_points = 0;

    keys = keys( quests );
    i = sizeof( keys );
    while( i-- )
    total_points += quests[keys[i]][1];
}

int
add_quest( string quest, int value, string base, string major_milestone )
{


    if(!check_previous_privilege(1)) return 0;
    if(quests[quest])
    {
    //write("D'oh, that quest already exists.\n");
    write("OOPS! 这个 QUEST 早有了。\n");
    return 0;
    }
    LOG_D->log(LOG_QUEST,
      sprintf(//"%-30s worth %d pts, added by %s.\n",
              "%-30s 值 %d 个点数，是 %s 增加的。\n",
                base, value,
    this_body()->query_name()));

    if(base[<2..] == ".c")
    {
    base = base[0..<3];
    }
    quests[quest] = ({ base , value , 0, major_milestone });
    calculate_total_points();
    save_me();
    return 1;
}

int
delete_quest( string quest )
{
    if(!check_previous_privilege(1) || !quests[quest])
    return 0;

    map_delete( quests, quest );
    save_me();
    calculate_total_points();
    return 1;
}

int quest_exists(string q)
{
    return quests[q];
}

int
grant_points( object solver, string quest )
{
    if( base_name( previous_object() ) != quests[quest][0] )
    return 0;

    if( !solver->add_quest( quest, quests[quest][1] ) )
    return 0;
    quests[quest][2]++;
    tell( solver, sprintf(//"Your score has gone up by %d points.\n",
                                 "你的分数增加了 %d 个点数。\n",
    quests[quest][1]) );
    save_me();

#ifdef USE_STATUS_LINE
    if( this_body()->has_status_line()) this_body()->update_status_line();
#endif
    return 1;
}


string array get_goals_for_quests_cmd()
{
    return map(filter(keys(quests), (: quests[$1][3] :)),
      (: sprintf("%s (%s)", $1, quests[$1][3]) :));
}

string dump_final_goals()
{
    string* keys;
    int     i;
    string  output;
    int     total1;
    int     total2;

    keys = keys( quests );
    keys = sort_array( keys, -1);

    i = sizeof( keys );
    output = "";
    while( i-- )
    {
    if(quests[keys[i]][3])
    {
        output += sprintf(//"%-17s-> %-2d pts, %d solves (%s)\n",
                          "%-17s-> %-2d 个点数，%d 解决了 (%s)\n",
          keys[i], quests[keys[i]][1], quests[keys[i]][2], quests[keys[i]][0]);
        total1 += quests[keys[i]][1];
    }
    total2 += quests[keys[i]][1];
    }

    output += sprintf(//"\nTotal points: %d in main goals, %d total\n",
                      "\n主要目的点数：%d，总共有 %d 点。\n",
                        total1, total2);

    return output;
}


// Dumps all the quest items, and not just the final goals
string quest_dump(string fname)
{
    string* keys;
    int     i;
    string  output;
    int     total;

    keys = keys( quests );
    keys = sort_array( keys, -1);

    i = sizeof( keys );
    output = "";
    while( i-- )
    {
    output += sprintf(//"%-17s-> %-2d pts, %d solves (%s)\n",
                      "%-17s-> %-2d 个点数，%d 解决了 (%s)\n",
      keys[i], quests[keys[i]][1], quests[keys[i]][2], quests[keys[i]][0]);
    total += quests[keys[i]][1];
    }

    output += //sprintf("\nTotal points: %d\n",total);
              sprintf("\n总点数：%d\n", total);

    if ( fname )
    write_file(fname, output, 1);

    return output;
}

string
show_quest( string quest )
{
    if( !quests[quest] )
    return sprintf(//"%s: no such quest milestone.\n",
                   "%s: 没有这种 QUEST 里程碑。\n",
                     quest);

    return sprintf("%-20s-> %-2d points, %d solves, home: %O",
                   "%-20s-> %-2d 个点数，%d 解决了，ｈｏｍｅ：%O",
                    quest, quests[quest][1],
      quests[quest][2], quests[quest][0]);
}

create()
{
    ::create();
    if (!quests)
    quests = ([]);
    calculate_total_points();
}

int
total_points()
{
    return total_points;
}
