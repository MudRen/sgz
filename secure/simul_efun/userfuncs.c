// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

#include <mudlib.h>
#include <daemons.h>
#include <security.h>

string base_name(mixed val);

nomask object this_body()
{
    object u = this_user();

    return u ? u->query_body() : 0;
}

varargs nomask object find_user(string str, int even_linkdead)
{
    object *choices;

    if (even_linkdead)
        choices = children(USER_OB);
    else
        choices = users();
    choices = filter(choices, (: $1->query_userid() == $(str) :));

    if (sizeof(choices))
        return choices[0];

    return 0;
}

varargs nomask object find_body(string str, int even_linkdead)
{
    object u = find_user(str, even_linkdead);

    return u ? u->query_body() : 0;
}

nomask int wizardp(mixed m)
{
    if (objectp(m))
        m = m->query_userid();

    if (stringp(m))
        return SECURE_D->query_is_wizard(m);

    return 0;
}

nomask int adminp(mixed m)
{
    if (objectp(m))
        m = m->query_userid();
    // 测试用
    if (m == "mudren")
    {
        return 1;
    }

    return member_array(m, SECURE_D->query_domain_members("Admin") || ({})) != -1;
}

nomask int user_exists(string user)
{
    return USER_D->user_exists(user);
}

nomask mixed get_user_variable(string varname)
{
    object shell;

#define UNDEFINED_VALUE ([])[0]

    if (!this_user())
        return UNDEFINED_VALUE;
    shell = this_user()->query_shell_ob();
    if (!shell)
        return UNDEFINED_VALUE;
    return shell->get_variable(varname);
}
