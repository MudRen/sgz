// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

//
// written by Rust Jan 12, 1994
// Underwent a mighty transformation at the hands of Deathblade on
//  Apr 30, 1995 to move to new user/body system.
//


#include <mudlib.h>
#include <daemons.h>
#include <config.h>
#include <commands.h>
#include <security.h>

string query_userid();
void rcv_encoding(string arg);
void set_b5(int e);
void set_userid(string new_name);
void set_chinese_id(string cname);
void save_me();
void restore_me(string some_name, int preserve_vars);

void register_failure(string addr);
static private string tmp_id;

varargs void modal_push(function input_func,
            mixed prompt,
            int secure,
            function return_to_func
    );
varargs void modal_func(function input_func,
            mixed prompt,
            int secure
    );
void modal_pop();
void modal_recapture();

void begin_info_collection();

void existing_user_enter_game();
void existing_user_ready();

mixed unguarded(mixed priv, function fp);

/*
** The user's password (duh!)
*/
private string password;

/* forward declarations */
void rcv_userid(string arg);
void rcv_chinese_id(string arg);
void rcv_new_password(string arg);
void rcv_new_userid(string arg);
void rcv_check_new_user(string the_userid, string str);

string get_tmp_id() {
	return tmp_id;
}
private nomask void get_lost_now()
{
    destruct();
}

/*
** This is used when we want to get rid of somebody... we have to wait a
** bit for MudOS to flush the buffer before disconnecting them (desting
** this_object()).
*/
//### if MudOS waits before closing the socket, this system may be obsolete
private nomask void get_lost()
{
    remove_call_out();
    modal_func((: 1 :), "");    /* ignore all input */
    call_out((: get_lost_now :), 2);
}

/*
** Name and password processing
*/

nomask int matches_password(string str)
{
    return ( crypt(str, str) == password || oldcrypt(str, str) == password);
}

nomask void set_password(string str)
{
    if ( base_name(previous_object()) != CMD_OB_PASSWD )
    //error("illegal attempt to set a password\n");
    error("��ͼ�Ƿ��趨����\n");
    password = oldcrypt(str, str);
    save_me();
}

private nomask void time_up()
{
    //write("\nSorry, you've taken too long.\n");
    write("\n�Բ����㻨�������ϵ�ʱ��̫���ˣ����´�������\n");
    get_lost();
}

private nomask int check_site()
{
    if ( BANISH_D->check_site() )
    {
    printf(//"Sorry, your site has been banished from " + mud_name() + ".  To ask for\n"
           //"a character, please mail %s.\n",
           "�Բ�����ĵ�ַ��" + mud_name() + "��ֹ���ߣ�"
           "�� mail �� %s ����������ʻ���\n",
           ADMIN_EMAIL);

    get_lost();

    return 0;
    }

    return 1;
}


private nomask int valid_chinese_id(string str)
{
    int len, i;
    string *chars;    
//    str = trim_spaces(str);
    len = strlen(str);
    if ( len > 8 ) // fire change the maximum name from 11 to 8
    {
    write("�Բ����������̫���ˣ��뻻һ����\n");
    return 0;
    }

    if ( (len / 2) * 2 != len ) {
        write("�Բ���������������������\n");
        return 0;
    }
    for (i=0; i<len; i++)
        if ((i / 2) * 2 == i) {
            if (str[i] < 176 || str[i] > 247) {
                write("�Բ���������������������\n");
                return 0;
            }
        } else if (str[i] < 161 || str[i] > 254) {
                write("�Բ���������������������\n");
                return 0;
        }
    if (str == "ĳ��" || BANISH_D->check_name(str)) {
        write("�Բ��������������ֹʹ�ã��뻻һ����\n");       
        return 0;                                               
    }
/*
    if (NAME_D->check_chinese_id(str)) {
        write("�Բ�����������Ѿ�����ʹ���ˣ��뻻һ����\n");
        return 0;
    }
*/
    chars=CHAR_D->check_char("name", str);
    if(sizeof(chars)) {
        foreach(string c in chars) {
           if(CHAR_D->get_char(c,"type")==TYPE_NPC) {
              write("�Բ��𣬲���ʹ�������е���������\n");
              return 0;

           }
        }   
    }
    return 1;
}
        
private nomask int valid_name(string str)
{
    int len;
    string *nousename=({"quit", "exit", "leave", "here", "me", "who", "new"});
    if(member_array(str,nousename) != -1) {
       write("�Բ���������������������ϵͳ���ң��뻻һ����\n");
       return 0;
    }
    if ( BANISH_D->check_name(str) )
    {
    //write("Sorry, that name is forbidden by the implementors.  Please choose another.\n");
        write("�Բ��������������ֹʹ�ã��뻻һ����\n");
        return 0;
    }

    if ( !check_site() )
    return 0;

    len = strlen(str);
    if ( len < 3 || len > 8 ) // fire change the maximum name from 11 to 8
    {
      //write("Sorry, that name's too long.  Try again.\n> ");
       write("�Բ����������̫���ˣ��뻻һ����\n> ");
       return 0;
    }

    /*
    ** We used to rely on the banish code to do this, but that is a
    ** Bad Thing as it is too easy to see those entries deleted.  In
    ** particular, we've been distributing the lib for a while now
    ** without a banish.o that contains this rule.  To use the banish
    ** code to implement a feature here is too convoluted and unintuitive.
    **
    ** So... we'll put a regex here to check the name.
    **
    ** Note that this regex matches the restriction imposed by the
    ** SECURE_D.  Also note the name is in lower case right now.
    */
    if ( !regexp(str, "^[a-z]+$") )
    {
    //write("Sorry, that name is forbidden by the implementors.  Please\n"
    //      "choose a name containing only letters.\n");
    write("�Բ������������׼ʹ�ã��뻻һ��ֻ����ĸ�ġ�\n");
    return 0;
    }

    return 1;
}


private nomask int check_special_commands(string arg)
{
    string array b;

    switch(arg)
    {
    	case "who":
        	b = bodies()->query_name();
		b -= ({ "ĳ��" });
		if(!sizeof(b)) {
		        write("����û��������Ӵ��\n");
		        return 0;
		}	
		printf(//"The following people are logged on:\n%s\n",
	           "���µ������������������У�\n%s\n",
        	   wrap(implode(b,", ")));
	        return 0;

    	case "":
    	case "quit":
    	case "exit":
    	case "leave":
    		//write("Bye.\n");
    		write("��ӭ�´�������\n");
    		get_lost();
    		return 0;
	case "new":
		modal_push((: rcv_new_userid :), "����������ȡһ��Ӣ�����֣�");
		return 0;		
    default:
    return 1;
    }
}

private nomask void rcv_new_userid(string arg) {

    if ( !check_special_commands(arg)) return;
    if ( unguarded(1, (: file_size,
               LINK_PATH(arg) + __SAVE_EXTENSION__ :)) <= 0 )
    {
        if ( !valid_name(arg) ) return; /* return for another user id */
        modal_func((: rcv_check_new_user, arg :),
           "'" + arg + "'  ��ȷ��");
        return;
    }
    else {
        write("���Ӣ�������Ѿ������ù��ˣ�\n");
        return;
    }
}

private nomask void rcv_confirm_new_pass(string first_entry,
                     string second_entry)
{
    if ( oldcrypt(second_entry, second_entry) != first_entry )
    {
    write("\n���Ӵ����˲�Ҫ�����������벻һ�¾��ǲ��У�\n");

//    modal_func((: rcv_new_password :), "Password: ", 1);
    modal_func((: rcv_new_password :), "���������룺", 1);
    return;
    }

    password = oldcrypt(second_entry, second_entry);

    write("\n");    /* needed after a no-echo input */

#ifdef CONF_IN_PROGRESS
    CONF_D->add_visitor(name);
#endif

    /*
    ** Done with the login sequence.  Pop our input handler now.
    */
    modal_pop();

    /*
    ** Time  go get some "user" information.
    */
    begin_info_collection();
}

private nomask void rcv_new_password(string arg)
{
    if ( strlen(arg) < 5 )
    {
    //write("Your password must have at least 5 characters in it.\n");
    write("�����������Ҫ����ַ���\n");
    return;
    }

    write("\n");    /* needed after a no-echo input */

    modal_func((: rcv_confirm_new_pass, oldcrypt(arg, arg) :),
           //"Again to confirm: ", 1);
           "�ٴκ˶ԣ�", 1);
}

private nomask void rcv_check_chinese_id(string chinese_id, string str)
{

    if ( !check_special_commands(str)) return;

    switch ( str )
    {
    case "n":  case "no":  case "nay":
    modal_func((: rcv_chinese_id :),
           //"Please enter your name (preferably correctly this time): ");
           "���������������������֣�");
    break;

    case "y":  case "yes":  case "aye":
        set_chinese_id(chinese_id);
        modal_func((: rcv_new_password :), "���������룺", 1);
    break;
    
    default:
    //write("Please answer Yes or No.\n");
    write("��ش� Yes �� No .\n");
    break;
    }
}

private nomask void rcv_chinese_id(string arg)
{
    if ( !arg || arg == "" )
    {
    //write("Sorry, everybody needs a name here.  Please try again.\n");
        write("�Բ���������������������\n");
        return;
    }

    if ( !check_special_commands(arg)) return;

    if ( !valid_chinese_id(arg) ) return;
    
    modal_func((: rcv_check_chinese_id, arg :),
           "'" + arg + "'  ��ȷ��");
    return;
}


private nomask void rcv_check_new_user(string the_userid, string str)
{
    str = lower_case(str);
    switch ( str )
    {
    case "n":  case "no":  case "nay":
    modal_func((: rcv_new_userid :),
           //"Please enter your name (preferably correctly this time): ");
           "�����¸���������ȡһ��Ӣ�����֣�");
    break;

    case "y":  case "yes":  case "aye":
#ifdef NO_NEW_PLAYERS
//    write(wrap("Unfortunately, "+mud_name()+" is still in the "
//           "developmental stage, and is not accepting new users. "
//           "If it is urgent, please use the guest character.")+"\n");
    write("�Բ���"+mud_name()+"���ڹ����У�Ŀǰ����������ң�"
               "���м��£������� guest ���롣"+"\n");
    get_lost();
    return;
#endif /* NO_NEW_PLAYERS */

    if ( !check_special_commands(str)) return;

    /*
    ** Begin the character creatin sequence. Store their name.
    */
    set_userid(the_userid);

    //write("\nAh, a New Player.\n");
    write("ร��������Ӵ...\n");
    modal_func((: rcv_chinese_id :), "����������������֣�");
    break;

    default:
    //write("Please answer Yes or No.\n");
    write("��ش� Yes �� No .\n");
    break;
    }
}
      
private nomask void rcv_password(int fails, string arg)
{
	restore_me(tmp_id,0); /* here to set the user_id */
    if ( matches_password(arg) )
    {
    /*
    ** Done with the login sequence.  Pop our input handler now.
    */
    modal_pop();

    existing_user_ready();
    return;
    }

    register_failure(query_ip_name(this_object()));
//    if ( fails == 2 ) /* if fail the first then kickout */
    {
    //write("\nYou're just too much for me.\nSorry.\n");
    write("\n�����ܲ����㣬�Բ�סඡ�\n");
    get_lost();
    return;
    }

    //write("\nHmmm.....\nI'll give you another chance.\n");
    write("\nHmmm......\n���ٸ���һ�λ��ᡣ\n");
    //modal_func((: rcv_password, fails + 1 :), "Password: ", 1);
    modal_func((: rcv_password, fails + 1 :), "���������룺", 1);
}

private nomask void modify_guest_userid()
{
    string * userids = users()->query_userid();

    for ( int i = 1; ; ++i )
    if ( member_array("guest" + i, userids) == -1 )
    {
        set_userid("guest" + i);
        save_me();
        return;
    }
}

private nomask void rcv_userid(string arg)
{
    string *wizs=({"fire","ice","row","stefan","group","flee","tset"});
    if ( !arg || arg == "" )
    {
    //write("Sorry, everybody needs a name here.  Please try again.\n");
    write("�Բ���ÿ���˶�Ҫ�и����֣�������������\n");
    return;
    }
/*
    if ( member_array( arg, wizs)==-1)
    {
    write("�Բ�������ֻ����ʦ�ſ��� login��\n");
    return;
    }
*/
    arg = lower_case(arg);

    if (!check_site()) return 0;

    if ( !check_special_commands(arg) ) return;

    if ( unguarded(1, (: file_size,
               LINK_PATH(arg) + __SAVE_EXTENSION__ :)) <= 0 )
    {
        write("���������Ӣ�����ֲ���ȷ��������������\n");
	return;
    }

    /* always check the site */
    if ( arg == "guest" && !check_site() )
    return;

    /*
    ** Restore the object, without worrying about preserving variables.
    ** Note that this sets the userid value.
    */

//    restore_me(arg, 0); /* should not set it before login may cause find_body error */
	tmp_id=arg; /* use this hold the use id */
    if ( arg == "guest" )
    {
	    restore_me(arg, 0);
		modify_guest_userid();
	    modal_pop();
	    existing_user_enter_game();
	    return;
    }

    //modal_func((: rcv_password, 0 :), "Password: ", 1);
    modal_func((: rcv_password, 0 :), "���������룺", 1);
   /*
    ** Adjust the time we'll wait for the user
    */
    remove_call_out();  /* all call outs */
    call_out((: time_up :), LOGIN_PASSWORD_WAIT);
}



private nomask void real_logon() {
    mixed mudlist = IMUD_D->query_mudlist();
    string match;
#ifdef _ALLOW_B5_
    write(M_ANSI->ansi(read_file(WELCOME_TEXT)));
#else
    write(M_ANSI->ansi(read_file(WELCOME_FILE)));
#endif
    foreach (match in keys(mudlist)) {
        mixed mud = mudlist[match];
        if ((strsrch(match, "����־") >= 0) && strsrch(match, "����") < 0) {
            printf("%14s%-14s%16s %4s   %s\n", " ", match, mud[1], 
            	mud[2] + "", (mud[0] == -1) ? "����" : "�ر�");
        }
    }
    write("\n");
/*
 * Warning: We have put literally thousands of hours of work into this
 * mudlib, and given it to you for free, and all we ask is that you give
 * us credit by leaving the lib version alone and visible on the login
 * screen.  Is that really so much to ask?
 *
 * If you think you have changed the lib to the point where you should
 * be allowed to change this, ask us first.  Please make sure you have
 * extensively modified/rewritten more than half of the base mudlib first
 * (intend to modify ... doesn't cut it)
 */
    printf(//"%s is running Lima 0.9r12 (pre-alpha) on %s\n\n",
           "%s�������� Lima 1.0a2 (Chinese)��%s��\n��������ʱ��%s��\n%s\n\n",
       mud_name(), driver_version(), 
       CHINESE_D->chinese_period(uptime() / 60 * 60), 
       FINGER_D->show_brief_finger());
    if (time() < 962394000) {
    	printf("����ʱ�������⣬�� %d ����ٽ��롣\n", 962394000 - time());
    	get_lost();
    	return;
    }    
    write("��ң����ã�\n");
#ifdef _ALLOW_B5_
    modal_func((: rcv_userid :), LOGIN_PROMPT);
#else
    modal_push((:  rcv_userid :), LOGIN_PROMPT);
    modal_recapture();
#endif
}

/*
** logon()
**
** Invoked by the driver to set up the object for logging in
*/
private nomask void logon()
{
    call_out((: time_up :), LOGIN_NAME_WAIT);

    write("");

#ifdef _ALLOW_B5_
    write(M_ANSI->ansi(read_file(WELCOME_LOGO)));
    modal_push((: rcv_encoding :), "Please select GB or BIG5 (gb/big5):");
    modal_recapture();
#else
#ifdef _ONLY_B5_
    set_b5(1);
#endif
    real_logon();
#endif
}

private nomask void rcv_encoding(string arg)
{
    arg = lower_case(arg);
    if (arg == "gb") {
        set_b5(0);
    }
    else if (arg == "big5") {
        set_b5(1);
    }
    else {
        write("ʹ�ù�������������룺gb\n");
        write("�ϥΤj���X�����a����J�Gbig5\n");
        return;
    }

    real_logon();
}    
