// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

// Rust rewrote tell because it didn't do: tell rust@lima bean foo correctly.
// last update, by xiaobai, on 5 Sep. 2001

#include <mudlib.h>
#include <commands.h>

// #define _DEBUG_ID   "xiaobai"

inherit CMD;
inherit M_GRAMMAR;
inherit M_COMPLETE;
inherit M_ANSI;

void create()
{
    ::create();
    no_redirection();
}

private void main(string arg)
{
    string user;
    string host;
    string tmp;
    string * words;
    string muds;
    string * previous_matches;
    string * matches;
    int i, j;
    string mystring;
    string deststring;
    object who;
    int p_res=0;
    string* strNotellIds;  // xiaobai: for notell   
    string strMyId;  // xiaobai: for notell
    
    if(!arg)
    {
        out("�÷�: tell <user> <message>\n");
        return;
    }

    if(sscanf(arg,"%s@%s", user, tmp) == 2){
        if (user[0]=='~')
	{
		p_res=1;
		user=user[1..<1];
	}
        muds = IMUD_D->query_up_muds();
        words = explode(tmp, " ");
        j = sizeof(words);
        tmp = "";
        for(i=0;i<j;i++)
        {
            tmp += " " + words[i];
            if(tmp[0] == ' ')
                tmp = tmp[1..];
            matches = find_best_match_or_complete(tmp, muds);
            if(!sizeof(matches))
            {
                break;
            }
            previous_matches = matches;
        }
        if(previous_matches)
        {
            if(sizeof(previous_matches) > 1)
            {
                out("MUD ���Ʋ��壬������: " 
                  + implode(previous_matches, ", ") + "\n");
                return;
            }                


            host = previous_matches[0];
            arg  = implode(words[i..], " ");
            if(host == mud_name())
            {
                main(user+" "+arg);
                return;
            }

            if( arg[0] == ';' || arg[0] == ':' )
            {
                mixed *soul_ret;
                arg = arg[1..];
                soul_ret = SOUL_D->parse_imud_soul(arg);
                if(!soul_ret)  {
                    IMUD_D->do_emoteto(host, user, arg);
                    outf("��� %s@%s ������: %s%s\n", user, host, this_body()->query_name(), arg);
                    return;
                }
                IMUD_D->do_emoteto(host,user,soul_ret[1][<1]);
                outf("*%s", soul_ret[1][0]);
                return;
            }
            IMUD_D->do_tell(host, user, arg);
            outf("����� %s@%s: %s\n", user, host, arg);
            return;
        }
    }
    if(sscanf(arg, "%s %s", user, arg) != 2)
    {
        out("�÷�: tell <user> <message>\n");
        return;
    }
	if (user[0]=='~')
	{
		p_res=1;
		user=user[1..<1];
	}
	
	strMyId = this_user()->query_userid();  // xiaobai: for notell

    who = find_body(lower_case(user));

    if(!who)
    {
        outf("û�� %s.\n", user);
        return;
    }

    if (who->query_invis() && !adminp(this_user()) )
    {
        outf("�Ҳ��� %s.\n", user);
        return;
    }
    if (!who->query_link() || !interactive(who->query_link()))
    {
        outf("%s ���ڶ����С�\n", who->query_name());
        return;
    }
//// modified by xiaobai, on 5 Sep. 2001
    if ( who->query( "notell_ids" )&&(!p_res) )
    // �ٺ٣���� id �ڶԷ��ĺ�������
    {
        strNotellIds = who->query( "notell_ids" );

#ifdef _DEBUG_ID       
        TELL_BUG( _DEBUG_ID, this_user() );
#endif  //_DEBUG_ID

        if ( member_array( strMyId, strNotellIds ) != -1 )
        {
            outf("%s\n", who->query_notell());
            return;
        }
////
    }


/* commented by stefan, because he does not like it. */
/*
    if( arg[0] == ':' || arg[0] == ';' )
    {
        mixed *soul_ret;
        int tindex;
        arg = arg[1..];
        soul_ret = SOUL_D->parse_soul(arg);
        if(!soul_ret)  {
            mystring = sprintf("���%s������: %s%s\n", who == this_body() ? "���Լ�" : who->query_name(), this_body()->query_name(),arg);
            deststring = sprintf("*%s %s\n", this_body()->query_name(), arg);
        }
        else
        {
            mystring = sprintf("(tell) %s", soul_ret[1][0]);

            if((tindex = member_array(who, soul_ret[0])) == -1)  {
                deststring = sprintf("(tell) %s", soul_ret[1][<1]);
            }
            else
            {
                deststring = sprintf("(tell) %s", soul_ret[1][tindex]);
            }
        }
    }
    else
*/

    if(!p_res)
    {
        mystring = sprintf("�����%s��%s\n", who == this_body() ? "���Լ�" :
                    who->query_name(), arg);
        deststring = this_body()->query_who_name() + "�����㣺" + arg;
    }
    else
    {
        mystring = sprintf("��ش�%s��%s\n", who == this_body() ? "���Լ�" : who->query_name(), arg);
        deststring = this_body()->query_who_name() + "�ش��㣺" + arg;
	
    }
    out(mystring);
    if(who != this_body())
    {
    	deststring = "%^TELL%^"+deststring+"%^RESET%^\n";
        who->receive_private_msg(deststring, MSG_INDENT);
        who->set_reply( strMyId );
    }
}

nomask int valid_resend(string ob) {
    return ob == "/cmds/player/reply";
}
