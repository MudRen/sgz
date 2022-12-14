// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

/*
** sw_user.c -- switch the actual user
**
** 14-Jun-95.  Deathblade.  Created.
*/

#include <mudlib.h>
#include <security.h>
#include <commands.h>

string query_userid();
object query_body();

string query_userid();
void restore_me(string some_name, int preserve_vars);

varargs void switch_body(string new_body_fname, int permanent);

void register_failure(string addr);

void modal_simple(function input_func, int secure);

void set_privilege(mixed priv);     // from M_ACCESS
varargs mixed unguarded(mixed priv, function code);

void clear_input_stack();


private nomask int do_su(string old_userid, string new_userid, string new_body)
{
    object body;
    string old_name;
    string new_name;

    write("\n");
    if (query_body())
        old_name = query_body()->query_name();

    /*
    ** The input stack needs to be cleared before we switch bodies so that
    ** the shell the body creates becomes the bottom object on the input
    ** stack.  -- Rust
    */
    clear_input_stack();

    /*
    ** switch user, then switch body.  Note on switching user:  pass
    ** flag == 1 so that we do not blow away static variables (the
    ** old body).
    */
    restore_me(new_userid, 1);
    switch_body(new_body);

    /* alter privileges */
    if ( adminp(query_userid()) )
    set_privilege(1);
    else
    set_privilege(query_userid());

    body = query_body();
    new_name = body->query_name();
    if ( old_userid != new_userid )
    {
        if (old_name) 
            tell_environment(environment(body),
                      sprintf(//"%s has polymorphed into %s.\n",
                      "%s 摇身一变，变成了 %s。\n",
                       old_name, new_name), 0,
                       ({ body }) );
    }
    tell(this_object(), sprintf(//"Done. You are now %s.\n",
                                       "成功，你现在是 %s。\n",
                                           new_name));

}

private nomask void confirm_valid_su(string old_userid,
                     string new_userid,
                     string new_body,
                     string arg)
{
    string pwd;

    /* new_userid should exist and therefore the return value should be ok */
    pwd = unguarded(1, (: call_other, USER_D, "query_variable",
            new_userid, ({ "password" }) :))[0];

    if ( (crypt(arg, arg) != pwd) && (oldcrypt(arg, arg) != pwd) )
    {
    //write("\nWrong password.\n");
    write("\n密码错误。\n");
    register_failure(sprintf("(su to %s)", new_userid));
    return;
    }

    do_su(old_userid, new_userid, new_body);
}

nomask void switch_user(string str, string new_body)
{
    string old_userid = query_userid();
    string new_userid = lower_case(str);
    int is_Admin = adminp(old_userid);

    if ( previous_object() != find_object(CMD_OB_SU) )
    return;

    new_userid = lower_case(str);
    if ( !SECURE_D->valid_name(new_userid) )
    {
    //printf("'%s' is an invalid name.\n", str);
    printf("'%s' 不是一个合法的名字。\n", str);
    return;
    }

    if ( new_userid != old_userid )
    {
    string linkpath = LINK_PATH(new_userid) + __SAVE_EXTENSION__;

    if( unguarded(1, (: file_size($(linkpath)) :)) <= 0 )
    {
        //write("No such user.\n");
        write("没有这个玩家。\n");
        return;
    }
    }

    if ( is_Admin || new_userid == old_userid )
    {
    do_su(old_userid, new_userid, new_body);
    return;
    }

    //printf("switching to: '%s'\n", new_userid);
    printf("切换到：'%s'\n", new_userid);

    //write("Password: ");
    write("请输入密码：");
    modal_simple((: confirm_valid_su, old_userid, new_userid, new_body :), 1);
}
