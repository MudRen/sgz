// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

// Rust wrote this, it's a lot like room.c, except it's
// for things like furniture and vehichles, which aren't rooms,
// but are locations.


#include <setbit.h>
#include <move.h>

inherit COMPLEX_CONTAINER;
inherit M_ITEMS;
inherit __DIR__ "room/exits";

int this_look_is_forced;

int stat_me() {
    printf(//"Location: %s [ %s ]\n\n",
           "位置：%s [ %s ]\n\n",
      short(), implode(query_exit_directions(1), ", "));
    complex_container::stat_me();
    return 1;
}


//:FUNCTION can_hold_water
//Return 1 if the object can hold water
/* by default, locations can hold water */
int can_hold_water()
{
    return 1;
}

void create()
{
    complex_container::create();
    exits::create();
}

void mudlib_setup()
{
    ::mudlib_setup();
    set_light(DEFAULT_LIGHT_LEVEL);
    set_max_capacity(VERY_LARGE+LARGE);
    add_id("here", "这里");
    set_preposition("on");
    if(!sizeof(get_relations()))
    {
    set_relations("on");
    }
    set_default_exit((: //"You're not going anywhere until you get out of the "
                        "你哪里也不能去，要先出去"
              + short() + "才行。\n" :));
}


string get_location_description()
{
  return (environment(this_object())->long_without_object(this_object()));
}

//:FUNCTION as_location_short
// Since locations double as objects and places to be, this is the short
// That goes at the top of a room description.  Usually it's the same as
// the room plus a modifier, like:  Grand Hall, in the camero

string get_brief()
{
  return sprintf("%s, %s", environment(this_object())->short(),
         prep_calc(query_prep(), short()));
}

//:FUNCTION do_looking
//print out the description of the current room
void do_looking(int forced_look)
{
    // This probably shouldn't be done in a global variable,
    // instead it should be passed to long(), but long does
    // not take args anywhere else...
    this_look_is_forced = forced_look;

    if ( wizardp(this_body()) &&
      this_body()->query_shell_ob()->get_variable("show_loc") )
    {
    printf("[%s]\n", file_name(this_object()));
    }

    if ( environment(this_object())->query_light() < 1 )
    {
    write("这里很黑，什么也看不清楚。\n");
    }
    else
    {
#ifdef OBVIOUS_EXITS
    printf("%s [exits: %s]\n", get_brief(), show_exits());
#else
    printf("%s\n", get_brief());
#endif

//    write(wrap(get_location_description()));
    write(get_location_description()); // wrap doesn't work well with color
    }
}



