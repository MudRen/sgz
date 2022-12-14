// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

/*
** objfind.c
**
** Find the locations (environments) of instances of the given class
**
** 07-Nov-94. Created. Deathblade.
*/

#include <mudlib.h>

inherit CMD;

private object * get_obs(string arg)
{
    return filter_array(objects(), (: base_name($1) == $(arg) :) );
}

private void main(string arg)
{
    object * obs;

    if ( !check_privilege(1) )
        //error("Must be an admin to use objpurge.\n");
        error("只有大神才可以用 objpurge\n");
    obs = get_obs(arg);
    //outf("Removing %d objects of class %s\n",
    outf("删除 %d 个属于 %s 的物件。\n", sizeof(obs), arg);
    obs->remove();

    obs = filter_array(obs, (: $1 :));  /* remove zeros */
    //outf("Destructing %d objects of class %s\n"
    outf("摧毁 %d 个属于 %s 的物件。\n", sizeof(obs), arg);

    map_array(obs, (: destruct :));
}
