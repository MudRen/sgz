// Updated by stefan on 10 Jan 1997
// modified by fire on Jan 2 1998
// modified by tset on Mar 7 1998
// modified by stefan on 30 Jan 2000
/* Do not remove the headers from this file! see /USAGE for more info. */

/*
** channel/cmd.c
**
** Part of the CHANNEL_D to handle channel command processing.
*/

#include <classes.h>
#include <channel.h>

#include <ansi.h>
inherit CLASS_CHANNEL_INFO;

void deliver_notice(string channel_name,string message);
void deliver_channel(string channel_name, string str);
void deliver_string(string channel_name, string str);
void create_channel(string channel_name);
class channel_info query_channel_info(string channel_name);
string user_channel_name(string channel_name);
void test_for_purge(string channel_name);

void set_permanent(string channel_name, int is_perm);
void set_flags(string channel_name, int flags);

void deliver_emote(string channel_name,
           string sender_name,
           string message);
void deliver_tell(string channel_name,
          string sender_name,
          string message);
void deliver_soul(string channel_name, mixed * soul);

string make_name_list(mixed * list);

int cmd_moderation(string channel_name, string arg);
void moderation_signoff(string channel_name);
void print_mod_info(string channel_name);

int re_repu;

/*
** cmd_channel()
**
** Standard channel processing command for player input.  Most channel-
** oriented systems will use this to get standardized channel manipulation.
**
** channel_type is:
**  0 normal
**  1 intermud
*/
mixed can_i_send(string msg) {
	string oldmsg;
	int oldtime,curtime=time();
	object tb=this_body();
	if(!objectp(tb)) return 0;
	oldtime=tb->query_lastchattime();
	oldmsg=tb->query_lastchatmsg();
	if((curtime-oldtime)>10) {
		tb->set_lastchat(msg);
		return 1;
	}
	if((curtime-oldtime)<2)
		return "��˵��̫���ˡ�\n";
	if(msg==oldmsg)
		return "ʮ���ڲ����ظ�ͬ���Ļ��\n";
	tb->set_lastchat(msg);
	return 1;
}
varargs nomask void cmd_channel(string channel_name, string arg,
                int channel_type)
{
    class channel_info ci = query_channel_info(channel_name);
    object tb;
    int listening;
    string user_channel_name;
    string sender_name, sender_id;
	mixed ret;
    tb = this_body();
    if (!tb) tb=previous_object(1);
    //printf("tb = %O\n",tb);
    ret=can_i_send(arg);
    if(tb->chan_disabled()) {
            printf("���Ƶ��������Ȩ��ȡ���ˣ�������WIZ����ָ���\n");
            return;

    }
    if (tb==previous_object(1)) listening =1;
    else listening = member_array(channel_name, tb->query_channel_list()) != -1;
    
    user_channel_name = user_channel_name(channel_name);

    if ( !arg || arg == "" )
    {
        if ( listening )
        {
        printf(//"You are presently listening to '%s'.\n",
               "�����ڽ��� '%s' ����Ϣ��\n",
                user_channel_name);
        print_mod_info(channel_name);
        }
        else
        {
        printf(//"You are not listening to '%s'.\n",
               "�����ڲ�δ���� '%s' ����Ϣ��\n",
                user_channel_name);
        }

        return;
    }

    if ( arg[0..3] == "/new" )
    {
        string * options = explode(arg[4..], " ");

        if ( ci )
        {
            if ( sizeof(options) )
              printf(//"'%s' already exists; modifying options...\n",
                "'%s' �Ѿ���ʹ���ˣ��뻻�������� Options��\n",
               user_channel_name);
            else
              printf(//"'%s' already exists.\n",
               "'%s' �Ѿ���ʹ���ˡ�\n",
                user_channel_name);
        }
        else
        {
            create_channel(channel_name);
            printf(//"'%s' has been created.\n",
               "'%s' �����ɹ���\n",
                user_channel_name);
        }

        ci = query_channel_info(channel_name);

        foreach ( string option in options )
        {
            switch ( option )
            {
                case "admin":
                    if ( !adminp(this_user()) )
                    {
                    //printf("Only admins can create admin channels.\n");
                    printf("ֻ��������ܽ��� admin Ƶ����\n");
                    return;
                    }
                    set_flags(channel_name, CHANNEL_ADMIN_ONLY);
                    // printf("  --> only admins may tune in\n");
                    printf("  --> ֻ���������������\n");
                    break;

                case "wiz":
                case "wizard":
                /* ### need better security? */
                    if ( (ci->flags & CHANNEL_ADMIN_ONLY) && !adminp(this_user()) )
                    {
                        //printf("Only admins can turn off admin-only.\n");
                        printf("ֻ��������ܹر� admin-only �����ԡ�\n");
                        return;
                    }
                    else if ( !wizardp(this_user()) )
                    {
                        //printf("Only wizards can create wizard channels.\n");
                        printf("ֻ����ʦ���ܽ��� wizard Ƶ����\n");
                        return;
                    }
                    set_flags(channel_name, CHANNEL_WIZ_ONLY);
                    //printf("  --> only wizards may tune in\n");
                    printf("  --> ֻ����ʦ����������\n");
                    break;

                case "permanent":
                   /* ### need better security? */
                   if ( !adminp(this_user()) )
                   {
                        //printf("Only admins can tweak permanent channels.\n");
                        printf("ֻ��������ܿ�������Ƶ����\n");
                        return;
                    }
                    set_permanent(channel_name, 1);
                    //printf("  --> the channel is permanent\n");
                    printf("  --> ���Ƶ����Ϊ����Ƶ����\n");
                    break;

                case "nopermanent":
                case "goaway":
                    /* ### need better security? */
                    if ( !adminp(this_user()) )
                    {
                        //printf("Only admins can tweak permanent channels.\n");
                        printf("ֻ��������ܿ�������Ƶ����\n");
                        return;
                    }
                    set_permanent(channel_name, 0);
                    //printf("  --> the channel may now go away\n");
                    printf("  --> ���Ƶ����Ϊ��ʱƵ����\n");
                    test_for_purge(channel_name);
                break;
            }
        }

        /* tune the channel in now */
        arg = "/on";
    }
    if ( arg == "/on" )
    {
        if ( listening )
        {
                printf(//"You are already listening to '%s'.\n",
                        "���Ѿ������� '%s' Ƶ���ˡ�\n",
                        user_channel_name);
        }
        else if ( !ci )
        {
                printf(//"'%s' does not exist. Use /new to create it.\n",
                        "'%s' �������ڣ��� /new ��������\n",
                        user_channel_name);
                return;
        }
        else
        {
                /* enforce the channel restrictions now */
                /* ### not super secure, but screw it :-) */
                if ( (ci->flags & CHANNEL_WIZ_ONLY) && !wizardp(this_user()) )
                {
                        printf(//"Sorry, but '%s' is for wizards only.\n",
                                "�Բ���'%s' ����ʦר��Ƶ����\n",
                                user_channel_name);
                        return;
                }
                if ( (ci->flags & CHANNEL_ADMIN_ONLY) && !adminp(this_user()) )
                {
                        printf(//"Sorry, but '%s' is for admins only.\n",
                                "�Բ���'%s' ������ר��Ƶ����\n",
                                user_channel_name);
                        return;
                }

                tb->channel_add(channel_name);
                printf(//"You are now listening to '%s'.\n",
                        "���������� '%s' Ƶ����\n",
                        user_channel_name);
        }

        print_mod_info(channel_name);

        return;
    }

    /*
    ** All the following "commands" need to have the player listening
    */
    if ( !listening )
    {
        printf(//"You are not listening to '%s'.\n",
                   "������û������ '%s' Ƶ����\n",
                        user_channel_name);

        return;
    }
    
    sender_name = tb->query_name();
    sender_id = tb->query_id()[0];

    if ( arg == "/off" )
    {
        tb->channel_remove(channel_name);
        printf(//"You are no longer listening to '%s'.\n",
           "������ֹͣ���� '%s' Ƶ����\n",
            user_channel_name);

        moderation_signoff(channel_name);
    }
    else if ( arg == "/list" || arg == "/who" )
    {
        write(iwrap(sprintf(//"Users listening to '%s': %s.\n",
                        "�û��������� '%s' ���� : %s.\n",
                user_channel_name,
                make_name_list(ci->listeners))));
    }
    else if( arg == "/last" || arg == "/history" )
    {
        string history = implode(ci->history, "");

        if ( history == "" )
                history = "<none>\n";

        more(sprintf(//"History of channel '%s':\n%s\n",
                 "'%s' Ƶ����ȥ�����ֵ���Ϣ�У�\n%s\n",
             user_channel_name, history));
    }
    else if( arg == "/clear" )
    {
	if( adminp( tb ) || tb == ci->moderator )
        {
            ci->history = ({});
            write( "Ƶ������ˡ�\n");
        }
        else
            error( this_body()->query_userid() + 
		"��ͼ�Ƿ���� " + user_channel_name + " Ƶ��");
    }
    else if ( cmd_moderation(channel_name, arg) )
    {
    /* it was handled */
    }
    else if ( arg[0] == ';' || arg[0] == '*' || arg[0] == ':')
    {
    	if(channel_name=="rumor"){
    		int reputation=CHAR_D->get_char(sender_id,"reputation");
    		if(!CHAR_D->get_char(sender_id)) {write("�㻹û�ж��ӣ�����ɢ��ҥ�ԡ�\n");return;}
    		if(reputation<100) {write("�����������������ɢ��ҥ�ԡ�\n");return;}
re_repu=50-random(50);
                CHAR_D->set_char(sender_id,"reputation",reputation-re_repu);
printf("����ɢ��ҥ�ԣ��������������%d�㡣\n",re_repu);
    	}

		if(stringp(ret)) {
			printf(ret);
			return;
		}
        if ( ci->moderator && ci->speaker &&
          tb != ci->moderator && tb != ci->speaker )
        {
            printf(//"You are not the speaker on '%s'.\n"
                   "�㲻�� %s Ƶ���ϵķ����ˡ�\n", user_channel_name);
        }
        else if ( channel_type == 1 ) {
            mixed * soul;
            string the_soul;
            
            if (sscanf(arg[1..],"%s %*s",the_soul)!=2)
                the_soul=arg[1..];
            if (SOUL_D->query_emote(the_soul)) 
                soul = SOUL_D->parse_imud_soul(arg[1..]);                
            if ( soul ) {
                deliver_soul(channel_name, soul);
            }
//            else 
//                deliver_emote(channel_name, sender_name, arg[1..]);
        }
        else if ( arg[0] == '*' )
        {
            mixed * soul;
            string the_soul;
	    string verb,targ;
	    string p_se;
	    if (sscanf(arg[1..],"%s %s",verb,targ)!=2) {
	        verb=arg[1..];
	        if (channel_name=="rumor")
	            soul=SOUL_D->get_soul(verb,"rumor",({ }));
	        else
	            soul=SOUL_D->get_soul(verb, "", ({ }));
	        if (soul) p_se=soul[1][1];
	    }
	    else {
	        mixed * p_use;
		object ob;

		ob=get_object(targ);
		if(!objectp(ob)) {
		    ob=CHAR_D->find_char(targ);
		    if(objectp(ob)&&(ob->is_guy()))
		    ob=0;
		}
		if(!objectp(ob)) {
		    object *obs;
		    obs=deep_inventory(this_body()->query_room());
		    obs = filter_array(obs, (: $1->id($(targ)) :));
		    if(sizeof(obs)) ob=obs[0];
		} 
		if(ob) {
		    if(channel_name=="rumor")
                        soul=SOUL_D->get_soul(verb,"LIVrumor",({ ob }));
                    else
                        soul=SOUL_D->get_soul(verb,"LIV",({ ob }));
                    if(soul)
                        p_se=soul[1][2];
                }
            }
	    if (p_se) {	
	    	deliver_channel(channel_name,p_se[0..(strlen(p_se)-2)]);
                if(channel_name=="rumor")
                   deliver_notice("announce", sprintf("ҥ�ԣ�%s", sender_name));
	    }
            else {
                printf("ʲô. . . ��\n");
	    }
	}
        else
        {
                   deliver_emote(channel_name, sender_name, arg[1..]);
        }
    }
    else {
    	if(channel_name=="rumor"){
    		int reputation=CHAR_D->get_char(sender_id,"reputation");
    		if(!CHAR_D->get_char(sender_id)) {write("�㻹û�ж��ӣ�����ɢ��ҥ�ԡ�\n");return;}
    		if(reputation<100) {write("�����������������ɢ��ҥ�ԡ�\n");return;}
re_repu=50-random(50);
                CHAR_D->set_char(sender_id,"reputation",reputation-re_repu);
printf("����ɢ��ҥ�ԣ��������������%d�㡣\n",re_repu);
    	}

	if(stringp(ret)) {
	    printf(ret);
	    return;
		}

        if ( ci->moderator && ci->speaker &&
         tb != ci->moderator && tb != ci->speaker )
        {
               printf(//"You are not the speaker on '%s'.\n",
               "�㲻�� '%s' �ķ�����֮һ��\n",
                user_channel_name);
        }
        else
        {       
	        deliver_tell(channel_name, sender_name + "(" + sender_id + ")", arg);
        }
    }
}
string query_channel_name(string channel_name)
{
	switch(channel_name)
	{
	    case "chat" :
		case "gossip":
			return "����";
		case "newbie" :
			return "����";
		case "wiz" :
            return "��ʦ";  
        case "rumor" :
            return "ҥ��";  
		case "announce" :
            return "ϵͳ";
        case "weather" :
            return "��ɫ";  
        case "imud_imud_sgz" :
			return "����־";  
		default :
			return channel_name;
	}
}
