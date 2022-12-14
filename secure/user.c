// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

/*
** user.c -- a user object
**
** This object represents a particular user and that user's connection.
**
** 95-Apr-30.  Deathblade.  Created.
*/

#include <mudlib.h>
#include <config.h>
#include <security.h>

inherit M_ACCESS;

inherit __DIR__ "user/login";
inherit __DIR__ "user/sw_body";
inherit __DIR__ "user/sw_user";
inherit __DIR__ "user/failures";
inherit __DIR__ "user/inputsys";
inherit __DIR__ "user/userinfo";
inherit __DIR__ "user/messages";
inherit __DIR__ "user/shell";

/*
** This users's userid (login id).
*/
string          userid, chinese_id;


/*
//### hack variable :-)... used for upgrading existing data
//###
//### 0: original format
//### 1: fixed body_fname; was unknown whether "proper"
//### 2: renamed "name" variable to "userid"
//### 3: fixed crypt() to use a real salt (FORTHCOMING)
*/

//### temp: upgrading file
private int             data_version = 2;
//### old variable
private string          name;
private string          owner;
private int isnetdead = 0;

static nomask void save_me()
{
    unguarded(1, (: save_object, LINK_PATH(userid) :));
}

nomask string set_owner(string id)
{
if (wizardp(this_object()))
   error("巫师ID不能设定拥有者。\n");
owner=id;
save_me();
return owner;
}

nomask string query_owner()
{
if (!owner) return "";
return owner;
}

nomask string query_userid()
{
    /*
    ** NOTE: allow this to return 0 so that callers can know that we
    ** are still in the login sequence.
    */
    return userid;
}

nomask string query_chinese_id()
{
    return chinese_id;
}

static nomask void set_userid(string new_userid)
{
    userid = new_userid;
}

static nomask void set_chinese_id(string new_cname)
{
    chinese_id = new_cname;
}

void remove()
{
    object body = query_body();

    if ( body )
        destruct(body);

    remove_call_out();
    stop_shell();
    destruct();
}

void quit()
{
    object body = query_body();

    if ( body )
        body->quit();

    remove();
}

mixed force_change_passwd(string owner_userid,string some_userid,string new_passwd)
{
if (find_user(some_userid))
   return "该玩家此时在线，你无法强行更改其密码!\n";
if (!unguarded(1, (: restore_object, LINK_PATH(some_userid), 0:)))
    return "该用户不存在，无法修改其密码。\n";
printf("%s\n",query_userid());
if (query_owner()!=owner_userid)
    return "你不是拥有者，无法修改其密码。\n";
set_password(new_passwd);
return 1;
}
static nomask void restore_me(string some_userid, int preserve_vars)
{
//### always "read" this variable
    data_version = 0;

    unguarded(1, (: restore_object, LINK_PATH(some_userid), preserve_vars :));

//### upgrade old files
    if(query_body_fname() == "/std/player")
        set_body_fname(BODY);
    if ( data_version == 0 )
    {
        if ( !query_body_fname() )
            set_body_fname(BODY);
        data_version = 1;
    }
    if ( data_version == 1 )
    {
        if ( !userid )
        {
            userid = name;
            name = 0;
        }
        data_version = 2;
    }
}

private nomask void net_dead()
{
    object body = query_body();
    isnetdead = 1;
    /*
    ** Tell the body about the net death.  The user object should stick
    ** around, though, so we can find it again if the user reconnects.
    ** If there is no body yet, then just torch self.
    */
    if ( body )
    {
        body->net_dead();
        call_out((: remove :), 300);
    }
    else
    {
        remove();
    }
}

public nomask int is_net_dead() {
    return isnetdead;
}
