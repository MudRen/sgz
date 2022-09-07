// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

/*
   release_a_member( object )// Will remove a player from the guild,
                             // and may record the fact on a player's
                             // revoke list to stop reentry. This is
                             // dependant on set_guild_begone()

*/

varargs void targetted_action();

private string which_guild;

/* ---------------------------------------------------
**
** These functions can be overridden to modify the behavior of the
** messages/errors issued by the "guild master"
*/
void guildmsg_new_conflict(object who, string why)
{
    targetted_action(//"$N $vlook sternly at $t and $vsay, \"As a member of $o, I cannot allow you to use our facilities anymore.  When you leave them, I'm sure that you'll be more than welcome back.\"\n",
                     "$N����ؿ���$t��˵��������Ϊ$o��һԱ���Ҳ�����������ʹ�����ǵ�װ����������뿪�����ǣ��Ỷӭ������ġ���\n", 
                     who, why);
}
void guildmsg_welcome_back(object who)
{
    targetted_action(//"$N $vwelcome $t back to the $o.\n",
                     "$N��ӭ$t��������$o��\n",
                     who, GUILD_D->query_guild_title(which_guild));
}
void guildmsg_not_member(object who)
{
    targetted_action(//"$N $vpoint out to $t, \"You aren't a member of the $o.\"\n",
                     "$Nָ��$t�����㲻��$o�ĳ�Ա����\n",   
                     who, GUILD_D->query_guild_title(which_guild));
}
void guildmsg_already_member(object who)
{
    targetted_action(//"$N $vpeer quizzically at $t and $vsay, \"You already belong to our guild.\"\n",
                     "$N��ֵؿ���$t��˵�������㱾���������ǰ��ɵġ���\n",
                     who);
}
void guildmsg_refuse_entry(object who, string why)
{
    targetted_action(//"$N $vstare unpleasantly at $t and $vgrowl, \"Not while you belong to $o.\"\n",
                     "$N����������$t˵������ֻҪ����$o�ĳ�Ա�Ͳ��С���\n",
                     who, why);
}
void guildmsg_welcome(object who)
{
    targetted_action(//"$N $vwelcome $t to the $o.\n",
                     "$N��ӭ$t����$o��\n",
                     who, GUILD_D->query_guild_title(which_guild));
}
void guildmsg_leave_nicely(object who)
{
    targetted_action(//"$N $vbid $t farewell.\n",
                     "$N�Ը�$t�뿪���ɡ�\n",   
                      who);
}
void guildmsg_leave_badly(object who)
{
    targetted_action(//"$N $vsay, \"So be it, $tp. Leave this place.\"\n",
                     "$N˵���������������㱻����������ɣ���\n",   
                     who);
}
void guildmsg_leave_as_enemy(object who)
{
    targetted_action("$N $vsnarl, \"So be it, $tp. You have chosen your doom.\"\n",
                     "$Nŭ��������쵰����Ӵ˾��Ǳ��ŵĵ��ˣ�ȥ���ɣ���\n",   
                     who);
}

/* --------------------------------------------------- */


static nomask void set_which_guild(string new_guild)
{
    which_guild = new_guild;
}

mixed do_guild_check(object who)
{
    if ( !who )
        who = this_body();

    return GUILD_D->guild_is_ok(which_guild, who->guilds_belong());
}

string query_which_guild()
{
    return which_guild;
}
//### this seems unused since add_a_member() has its own check
#if 0
void check_a_member()
{
    mixed p = do_guild_check();

    if ( p )
    {
        this_body()->simple_action(//"The Guildmaster snarls at $N, "
                                   //"\"As a member of $O, I cannot allow "
                                   //"you membership.\"\n",
                                   "������$N���������Ϊ$O��һԱ���Ҳ�׼������\n",
                                   p);
    }
}
#endif /* 0 */


void recheck_a_member(object who)
{
    mixed p;

    if ( !who )
        who = this_body();

    p = do_guild_check(who);
    if( p )
    {
        guildmsg_new_conflict(who, p);
        who->suspend_guild(which_guild,
                           GUILD_D->query_guild_suspend_level(which_guild));
    }
    else
    {
        guildmsg_welcome_back(who);
        who->unsuspend_guild(which_guild);
    }
}


void add_a_member(object who)
{
    mixed p;

    if ( !who )
        who = this_body();

    if( who->query_member_guild(which_guild))
    {
        guildmsg_already_member(who);
    }
    else
    {
        p = do_guild_check(who);
        if( p )
        {
            guildmsg_refuse_entry(who, p);
        }
        else
        {
            guildmsg_welcome(who);
            who->add_guild(which_guild, 1);
        }
    }
}


void release_a_member(object who)
{
    if ( !who )
        who = this_body();

    if ( !who->query_member_guild(which_guild) )
    {
        guildmsg_not_member(who);
        return;
    }

    switch ( GUILD_D->query_guild_begone(which_guild) )
    {
    // ### --OH: 0 should do a revoke guild, 1 do a ban guild(1)
    // ###       that means that when try to rejoin get welcome back msg

    default:
    case 0:
    case 1:
        guildmsg_leave_nicely(who);
        who->revoke_guild(which_guild);
        return;

    case 2:
        guildmsg_leave_nicely(who);
        who->revoke_guild(which_guild);
        who->ban_guild(which_guild, 2);
        return;

    case 3:
        guildmsg_leave_as_enemy(who);
        who->revoke_guild(which_guild);
        who->ban_guild(which_guild, 3);
        return;
    }
}
