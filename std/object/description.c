// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

#include <mudlib.h>
#include <setbit.h>

/* Our descriptions:
 * long:   should be a complete sentence or a closure.
 * in_room_desc: A longer string for rooms.  Titles for players.
 */
/* if these are zero, sane defaults are used based on 'names'. */
private static mixed long;
private static mixed in_room_desc;
/* our description when we haven't been touched.  Really an
 * in_room_desc, not a long */
private string untouched_long;

/* these are somewhere else... */
int test_flag(int);
int is_visible();
int is_attached();
string short();
string a_short();
string query_unit();
varargs mixed call_hooks();


/* this one is here, but this is a forward declaration. */
string query_in_room_desc();

//:FUNCTION set_long
//Set the long description of an object
nomask void set_long(mixed str)
{
    long = str;
    if ( functionp(long) ) return;
    if ( long == "" || long[<1] != '\n' ) long += "\n";
}

//:FUNCTION get_base_long
// Get the variable long, not the full description...
string get_base_long()
{
    string res;

    if(!is_visible())
      return //"Funny, you don't see anything at all.";
             "你眼前一片漆黑，什么也看不到。\n";
    res = evaluate(long);
    if (!res)
        return //"You see nothing special about " + short() + "\n";
               short()+"看起来没什么特殊的。\n";
    return res; //    return wrap(res);
}

string get_extra_long()
{
//:HOOK extra_long
//The returned strings are added on to the end of the long description.
    return call_hooks("extra_long", (: $1 + $2 :), "") || "";
}

//:FUNCTION long
//Return the verbose description of an object that you see when you look
//at it.
string long()
{
  return get_base_long() + get_extra_long();
}

static string array discarded_message;

string untouched_long() {
    return untouched_long;
}

//:FUNCTION show_in_room
//Return a string appropriate for inclusing in a room long description.
//Note that duplicatep() objects return nothing.
string show_in_room()
{
    string str;
    int our_count;
    if(!is_visible()) return 0;
    /* If an object is attached, it is considered part of its
     * parent and it's the parent's responsibility to print an
     * appropriate description.  For example, wielded weapons are
     * attached and should be included in the monster's description.
     * c.f. Zork's:
     *    A nasty-looking troll, brandishing a bloody axe, blocks all
     *         passages out of the room.
     */
    if (is_attached()) return 0;
    our_count = count();
    if (our_count > 4) {
        str = short();
        if (!str) return 0;

        return "这儿有很多" + short() + "。\n";
    }
    if (our_count > 1 )
    {
        str = short();
        if( !str )
            return 0;

        //      if( query_ob_flag( AUTO_IN_ROOM_DESC ) )
        return sprintf("这儿有%s", chinese_number(our_count)+query_unit()+short());
    }

    if (!test_flag(TOUCHED) && (str = untouched_long()))
        return str;

    if( str = query_in_room_desc() )
        return str;

    str = a_short();

    if( !str )
        return 0;

    //    if( query_ob_flag( AUTO_IN_ROOM_DESC ) )

    if (!discarded_message)
        discarded_message = MESSAGES_D->get_messages("discarded");

    return sprintf( choice(discarded_message), str );
}

//:FUNCTION set_in_room_desc
//Set the description an object has when it is sitting in a room
static void set_in_room_desc( mixed arg )
{
  in_room_desc = evaluate(arg);
}

string query_posessive(){  return "它的"; }

//:FUNCTION
//set the untouched description of the object.  This is the way the object
//is described originally, but not after is has been taken or moved.
void set_untouched_desc(string arg){
    if(stringp(arg)) untouched_long = arg;
}

string query_in_room_desc()
{
    if(!is_visible())
      return "";
    return (string)evaluate(in_room_desc);
}
