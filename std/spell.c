// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

#include <assert.h>

private static string spell_name;

static void cast_spell(object target, object reagent);

static void set_spell_name(string s)
{
    spell_name = s;
}
string get_spell_name()
{
    return spell_name;
}


// You could check for things in these f()'s such as: does the person have
// the necessary components?  Does the person have the spell in memory, or
// is a scroll present?
// Return a string error message or 1 if it is cool.

static mixed valid_reagent(object reagent)
{
    /* DEFAULT: if there is a reagent, then it can't be used */
    if ( reagent )
    {
        return 0;
    }
    return 1;
}

static mixed valid_target(object target)
{
    /* DEFAULT: if there is a target, then it is invalid */
    if ( target )
    {
        return 0;
    }
    return 1;
}

static mixed valid_circumstances(mixed target, mixed reagent)
{
    /* DEFAULT: spells can be cast at any time */
    return 1;
}

static mixed check_valid_spell(int has_target, int has_reagent)
{
    return valid_circumstances(has_target, has_reagent);
}

static mixed check_valid_target(object target, mixed has_reagent)
{
    mixed res;

    res = valid_circumstances(target, has_reagent);
    if ( res != 1 )
        return res;

    return valid_target(target);
}

static mixed check_valid_reagent(object reagent, mixed has_target)
{
    mixed res;

    res = valid_circumstances(has_target, reagent);
    if ( res != 1 )
        return res;

    return valid_reagent(reagent);

#if 0
    if ( !res )
    {
        return reagent ?
            sprintf(//"You can't cast that with %s.\n"
                    "你无法用%s来施展法术。\n", reagent->short()) :
            "你要借助某个东西来施展法术。\n";
    }
    if ( stringp(res) )
    {
        return res;
    }
    ENSURE(res == 1);

    res = valid_target(target);
    if ( !res ) 
    {
        return target ?
            sprintf(//"You can't cast that on %s.\n",
                    "你不能对%s施展法术。\n",
                    target->short()) :
            "你要把这法术施展在某个东西上。\n";
    }
    if ( stringp(res) )
    {
        return res;
    }
    ENSURE(res == 1);

    return 1;
#endif
}

nomask mixed _check_valid_spell(int has_target, int has_reagent)
{
    ENSURE(previous_object() == find_object(SPELL_D));
    return check_valid_spell(has_target, has_reagent);
}

nomask mixed _check_valid_target(object target, mixed has_reagent)
{
    ENSURE(previous_object() == find_object(SPELL_D));
    return check_valid_target(target, has_reagent);
}

nomask mixed _check_valid_reagent(object reagent, mixed has_target)
{
    ENSURE(previous_object() == find_object(SPELL_D));
    return check_valid_reagent(reagent, has_target);
}

// The daemon calls this, we check if it came from the daemon, and then call
// the local (static) cast_spell
nomask void _cast_spell(object target, object reagent)
{
    ENSURE(previous_object() == find_object(SPELL_D));
    cast_spell(target, reagent);
}

void setup()
{
}

nomask void create()
{
    if ( base_name() == SPELL )
        return;

    /* let the subclass set up the spell info/characteristics */
    setup();

    /* now register with the spell daemon */
    SPELL_D->register_spell();
}
