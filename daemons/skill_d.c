// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

#include <security.h>
#include <classes.h>

inherit M_DAEMON_DATA;

/*
** Keep the list of the available skills.
**
** NOTE: The values in this mapping are unused (set to 1)
*/
private mapping skills = ([]);

#define PRIV_REQUIRED   "Mudlib:daemons"

void register_skill(string skill)
{
    if ( !check_privilege(PRIV_REQUIRED) )
        error("security: illegal attempt to add a skill\n");

    if ( skills[skill] )
        return;

    skills[skill] = 1;
    save_me();
}

void remove_skill(string skill)
{
    if ( !check_privilege(PRIV_REQUIRED) )
        error("security: illegal attempt to remove a skill\n");

    if ( !skills[skill] )
        return;

    map_delete(skills, skill);
    save_me();
}

string * query_skills()
{
    return keys(skills);
}
