// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

/*
** pshell.c -- player shell object
**
** Simple shell for the players.
**
** 950817, Deathblade: created.
*/

#include <mudlib.h>
#include <daemons.h>
#include <commands.h>

inherit SHELL;
inherit M_COMPLETE;

private static int last_time, accumulate;	//last_time�ϴ�ִ�������ʱ��, accumulateһ�����ۼ�ִ������ĸ���

string array query_path() {
    return ({ CMD_DIR_PLAYER "/" });
}
     
string query_shellname()
{
    return "Player Shell";
}

private mapping shell_vars = ([]);

void set_variable(string name, mixed value)
{
  if(!shell_vars)
    shell_vars = ([]);
  switch(name)
    {
    case "ansi":
    case "status":
      shell_vars[name] = value;
      return;
    default:
      error(//"Bad player shell variable."
            "�������� shell ����");
    }
}

void unset_variable(string name, mixed value)
{
  if(!shell_vars)
    shell_vars = ([]);
  switch(name)
    {
    case "ansi":
    case "status":
      map_delete(shell_vars,name);      
      return;
    default:
      error(//"Bad player shell variable."
            "�������� shell ����");

    }
}

mixed get_variable(string name)
{
  if(!shell_vars)
    shell_vars = ([]);
  return shell_vars[name];
}

private nomask string expand_one_argument(string arg)
{
    mixed expansion;

    if ( strlen(arg) <= 1 || arg[<1] != '*' )
        return arg;

    expansion = complete_user(arg[0..<2]);
    if ( stringp(expansion) )
        return expansion;

    return arg;
}

static void execute_command(string * argv, string original_input)
{
    mixed tmp;
    array winner;
    string argument;
    
    int t;

	//printf("jin le execute_command()\n");
    if (!this_body()) return;

	//printf("last_time = %d\n",last_time);
	//printf("time() = %d\n",time());
    if ((t =time()) == last_time) 
	{
		//printf("t = %d, last_time = %d, accumulate=%d\n",t,last_time,accumulate);
    	accumulate++;
    	if (accumulate == 8) 
		{
			//printf("jin le start_busy() qian mian\n");
    	    this_body()->start_busy(2, "��һ������̫��������..");
    	}
    	if (accumulate >= 8) return;
    }
    else 
	{
		//printf("jin le else\n");
    	last_time = t;
    	accumulate = 0;
    }

    /* BEGINNING OF EXPANSION */

    // In some shells, this is the hook for doing username completion,
    // globbing, flag pre-parsing, etc...  In others, it's used to execute
    // code encased in ` `'s.
    argv = map(argv, (: expand_one_argument :));
    if(!argv)
        return;
    argv -= ({ "" });

    // ### wtf is this?
    // Hmm, I might undo this one...  the only reason this is here is to 
    // allow \\$ to work right.  \$ can work right in other ways....
    argv = map(argv, (: stringp($1) ? replace_string($1, "\\$","$") : $1 :));

    // If there is a local shell command that matches our input, try to
    // execute it.
    evaluate(tmp=dispatch[argv[0]], argv);
    if(tmp)
        return;

	//printf("command expansion end\n");
    /* END OF EXPANSION */

    winner = CMD_D->find_cmd_in_path(argv[0], ({ CMD_DIR_PLAYER "/" }));
    if ( !arrayp(winner) )
    {
        string channel_name;

		//printf("find_cmd_in_path() over, winer ��ȡʧ��\n");
        if ( this_body()->do_game_command(original_input) )
            return;
		//printf("this_body()->do_game_command() ִ�й���\n");
        /* try a channel */
        channel_name = CHANNEL_D->is_valid_channel(argv[0], this_body()->query_channel_list());
        if ( channel_name )
        {
            /* ### strictly speaking, players can't use I3 channels */
            int chan_type = channel_name[0..4] == "imud_";
			//printf("��cmd_channel()ǰ��\n");
            CHANNEL_D->cmd_channel(channel_name,
                                    implode(argv[1..], " "),
                                    chan_type);
            return;
        }

//### This is a hack until the parser can tell me if a word is a verb.
		//printf("������˵���������д���\n");
        if(is_file(CMD_DIR_VERBS "/" + argv[0] + ".c"))
            write(this_body()->nonsense());
        else
            printf(//"I don't know the word: %s.\n"
                   "û�� %s �������򶯴ʡ�\n", argv[0]);

        return;
    }
	//printf("find_cmd_in_path() over, winer success to get\n")
    if ( sizeof(argv) > 1 )
        argument = implode(argv[1..], " ");

    winner[0]->call_main(argument,0,0,0,0,0,argument);
}

static nomask string query_save_path(string userid)
{
    return PSHELL_PATH(userid);
}

