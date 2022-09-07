// Updated by stefan on 10 Jan 1997
// modified by tset on 7 Mar 1998
/* Do not remove the headers from this file! see /USAGE for more info. */

/*
** moderation.c -- channel moderation facilities
**
** 960115, Deathblade: created
*/

#include <classes.h>

//### this file is currently included into the channel daemon (rather than
//### inherited cuz we can't do this inherit (driver)
//inherit CLASS_CHANNEL_INFO;
inherit __DIR__ "cmd";
//class channel_info query_channel_info(string channel_name);
string user_channel_name(string channel_name);
void deliver_notice(string channel_name, string message);
nomask string make_name_list(mixed * list);


/*
** print_mod_info()
**
** Print moderator/speak infor for a moderated channel.
*/
static nomask void print_mod_info(string channel_name)
{
    class channel_info ci = query_channel_info(channel_name);

    if ( !ci->moderator )
    return;

    printf(//"It is being moderated by %s.\n",
           "������ %s �������Ƶ����\n",
            ci->moderator->query_name());

    if ( ci->speaker )
    printf(//"The current speaker is %s.\n",
           "���ڷ������ǣ�%s��\n",
             ci->speaker->query_name());
    else
    //printf("There is no current speaker.\n");
    printf("����û�з����ˡ�\n");

    if ( ci->moderator == this_body() )
    {
    if ( !ci->requestors ||
        !sizeof(ci->requestors) )
        //printf("There are no requestors.\n");
        printf("����û���������ԡ�\n");
    else
        write(iwrap(sprintf(//"Requestors are: %s.\n",
                            "���������Ե����У� %s��\n",
                make_name_list(ci->requestors))));
    }
    else if ( member_array(this_body(), ci->requestors) != -1 )
    {
    //printf("Your hand is raised to speak.\n");
    printf("�����Ҫ���ԡ�\n");
    }
}


/* this is used when signing off from a channel... */
static nomask void moderation_signoff(string channel_name)
{
    class channel_info ci = query_channel_info(channel_name);

    if ( !ci )
    return;

    if ( this_body() == ci->moderator )
    {
    ci->moderator = ci->speaker = ci->requestors = 0;

    deliver_notice(channel_name, //"This channel is now unmoderated");
				"���Ƶ���������ɷ��ԡ�");
    }
    else if ( this_body() == ci->speaker )
    {
    ci->speaker = 0;
    deliver_notice(channel_name,
               sprintf(//"%s is no longer speaking",
                       "%s ֹͣ���ԡ�",
                   this_body()->query_name()));
    }
}

static nomask int cmd_moderation(string channel_name, string arg)
{
    class channel_info ci = query_channel_info(channel_name);
    string user_channel_name = user_channel_name(channel_name);
    object tb = this_body();
    string sender_name = tb->query_name();

    if ( arg == "/raise" )
    {
    if ( !ci->moderator )
    {
        printf(//"'%s' is not moderated.\n",
                "'%s' Ƶ�������������֡�\n",
        user_channel_name);
    }
    else if ( tb == ci->speaker )
    {
        printf(//"You are already speaking on '%s'.\n",
               "������ '%s' Ƶ���Ϸ��ԡ�\n",
                 user_channel_name);
    }
    else if ( member_array(tb, ci->requestors) == -1 )
    {
        printf(//"Your raise your hand to speak on '%s'.\n",
               "�����Ҫ���� '%s' Ƶ���Ϸ��ԡ�\n",
           user_channel_name);
        ci->requestors += ({ tb });
        ci->moderator->channel_rcv_string(channel_name,
                      sprintf(//"[%s] (%s raises a hand to speak)\n",
                              "[%s] (%s����Ҫ����)\n",
                          user_channel_name,
                          sender_name));
    }
    else
    {
        printf(//"You already have your hand raised to speak on '%s'.\n",
               "���Ѿ�����Ҫ���� '%s' Ƶ���Ϸ����ˡ�\n",
           user_channel_name);
    }
    }
    else if ( arg == "/lower" )
    {
    if ( !ci->moderator )
    {
        printf(//"'%s' is not moderated.\n",
                "'%s' Ƶ�������������֡�\n",
                user_channel_name);
    }
    else if ( member_array(tb, ci->requestors) != -1 )
    {
        printf(//"Your lower your hand to avoid speaking on '%s'.\n",
               "����ַ�������׼���� '%s' Ƶ���Ϸ����ˡ�\n",
           user_channel_name);
        ci->requestors -= ({ tb });
        ci->moderator->channel_rcv_string(channel_name,
                      sprintf(//"[%s] (%s lowers a hand)\n",
                              "[%s] (%s�����˾������)\n",
                          user_channel_name,
                          sender_name));
    }
    else
    {
        printf(//"Your hand is not raised to speak on '%s'.\n",
               "�㲢û�о���Ҫ���� '%s' Ƶ���Ϸ��ԡ�\n",
           user_channel_name);
    }
    }
    else if ( arg[0..4] == "/call" )
    {
    arg = lower_case(trim_spaces(arg[5..]));
    if ( !ci->moderator )
    {
        printf(//"'%s' is not moderated.\n",
               "'%s' Ƶ�������������֡�\n",
                user_channel_name);
    }
    else if ( ci->moderator != tb )
    {
        printf(//"You are not the moderator of '%s'.\n",
               "�㲻�� '%s' Ƶ���������ˡ�\n",
                user_channel_name);
    }
    else if ( arg == "" )
    {
        if ( sizeof(ci->requestors) == 0 )
        {
        //printf("Nobody has their hand raised.\n");
        printf("û���˾��֡�\n");

        }
        else
        {
        ci->speaker = ci->requestors[0];
        ci->requestors = ci->requestors[1..];
        deliver_notice(channel_name,
                   //sprintf("%s will now speak",
		sprintf("%s���ڿ�ʼ���ԡ�",
                       ci->speaker->query_name()));
        }
    }
    else
    {
        object * spkr;

        spkr = filter_array(ci->requestors,
                (: $(arg) == lower_case($1->query_name()) :));
        if ( sizeof(spkr) == 0 )
        {
        printf(//"'%s' was not found (or did not have their hand raised.\n",
               "'%s' �����������û�о��֡�\n",
               arg);
        }
        else
        {
        ci->speaker = spkr[0];
        ci->requestors -= ({ spkr[0] });
        deliver_notice(channel_name,
                   //sprintf("%s will now speak",
                   sprintf("%s���ڿ�ʼ���ԡ�\n",
                       ci->speaker->query_name()));
        }
    }
    }
    else if ( arg == "/moderate" )
    {
    if ( adminp(this_user()) ||
        GROUP_D->member_group(this_user()->query_userid(), "moderators") )
    {
        ci->moderator = tb;
        if ( !ci->requestors )
        ci->requestors = ({ });
        deliver_notice(channel_name,
		sprintf(//"%s",
			"%s �������������Ƶ����",
                        sender_name));
    }
    else
    {
       // printf("You are not allowed to moderate this channel.\n");
       printf("��û��Ȩ�����������Ƶ����\n");
    }
    }
	else if (arg == "/unmoderate") {
	  if( this_body() == ci->moderator ) {
		ci->moderator = ci->speaker = ci->requestors = 0;
		deliver_notice(channel_name, "���Ƶ���������ɷ��ԡ�");
	  }
	  else
		printf("�㲻�� '%s' Ƶ���������ˡ�\n",channel_name);
	}
    else
    {
    /* not handled */
    return 0;
    }

    /* handled */
    return 1;
}