// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

#include <mudlib.h>
#include <config.h>
#include <daemons.h>
#include <security.h>
#include <log.h>
#define MAX_DUMMY   30
string query_userid();
string query_chinese_id();
void save_me();
void remove();
void get_lost_now();
void report_login_failures();

varargs void modal_simple(function input_func, int secure);

void set_privilege(mixed priv);     // from M_ACCESS
mixed unguarded(mixed priv, function fp);

void start_shell();
void run_login_script();

int query_n_gen();
/*
** The file name for set the dummies limit for indivdual
** Everybody can set a diff num from MAX_DUMMY to allow more char
** logining from the same IP which is a PROXY IP.
*/
private  int  dummy_limit;

/*
** The file name for the body object
*/
private string      body_fname;

/*
** The body object once it has been instantiated
*/
static private object   body;

nomask int query_dummy_limit()
{
    return dummy_limit;
}
nomask void set_dummy_limit(int limit)
{
    dummy_limit = limit;
    save_me();
}

nomask string query_body_fname()
{
    return body_fname;
}

nomask object query_body()
{
    return body;
}

//### temp hack for upgrading link files. see restore_me()
static nomask void set_body_fname(string new_body_fname)
{
    body_fname = new_body_fname;
}


varargs nomask void switch_body(string new_body_fname, int permanent)
{
    object where;
    object old_body;

    if ( previous_object() != body && this_body() != body )
    //error("security violation: bad body switch attempt\n");
    error("��ȫΥ���������л�����\n");

    where = body ? environment(body) : (mixed)VOID_ROOM;

    if ( permanent && new_body_fname )
    {
    body_fname = new_body_fname;
    save_me();
    }

    if ( !new_body_fname )
    new_body_fname = body_fname;

    old_body = body;
//LOG_D->log(LOG_BUG, "sw_body.c: fname("+new_body_fname+") userid("+query_userid()+")\n");    
    body = new(new_body_fname, query_userid());

    if (old_body) {
        old_body->move(VOID_ROOM);
        old_body->quit();
        if ( old_body )
            catch(old_body->remove());
    }

    report_login_failures();

    /* NOTE: we are keeping the same shell for now... */

    body->su_enter_game();
    body->move(where);
}


/*
** Functions to get the body set up and the user into the game.
*/

private nomask void incarnate(int is_new, string bfn)
{
    if (bfn) body_fname = bfn;
    write("is_new��ֵ��:" + is_new + "\n");
	write("bfn��ֵ��:" + bfn + "\n");
//LOG_D->log(LOG_BUG, "sw_body.c: body_fname("+body_fname+") userid("+query_userid()+")\n");
    
    body = new(body_fname, query_userid(), query_chinese_id());
    //write("body��ֵ��:" + body + "\n");	//����
    LAST_LOGIN_D->register_last(query_userid(), query_ip_name(this_object()));
    if ( query_n_gen() != -1 )
    body->set_gender(query_n_gen());
    save_me();

    start_shell();
    body->enter_game(is_new);
    run_login_script();
    if ( is_new ) 
       body->save_me();
}

static nomask void existing_user_enter_game()
{
    remove_call_out();  /* all call outs */

    write("\n"+read_file(MOTD_FILE));

    report_login_failures();

    incarnate(0, 0);
}

private nomask void rcv_try_to_boot(object who, string answer)
{
    if ( answer == "y" )
    {
	if(!objectp(who)) {

		write("It seems that you want to use bug, hehe!!!!\n");
		destruct(this_object());
           return;

	}

    who->receive_private_msg(//"You are taken over by yourself, or something.\n");
                             "�㱻���Լ�������滻���ˡ�\n");
    who->quit();

    existing_user_enter_game();
    return;
    }
    if (answer == "n" )
    {
    if ( wizardp(query_userid()) )
    {
        existing_user_enter_game();
        return;
    }

    //write("Try another time then.\n");
    write("�Ǿ�����һ�Ρ�\n");
    destruct(this_object());
    }

    //write("please type 'y' or 'n'  >");
    write("������ 'y' �� 'n' >");
    modal_simple((: rcv_try_to_boot, who :));
}

/*
** Okay... an existing user is ready for their body.  Look for other
** users currently connected with this userid.  Those other users may
** be interactive or link-dead.  Do the right thing...
*/
static nomask void existing_user_ready()
{
    object * users;
    string * ids;
    int idx;
    object the_user;

    remove_call_out();  /* all call outs */

#ifdef NO_PLAYERS
    if( !wizardp(query_userid())) {
        write("Ŀǰֻ����ʦ�ſ��Խ��룬���в��㣬����ԭ�¡�\n");
        get_lost_now();
        return;
    }
#endif
    /*added by suicide to logins limit from per IP*/
    if( !wizardp(query_userid()))
    {
    users = filter(users(),(: find_body(($1)->query_userid()) :));
    users = filter(users, (: query_ip_number($1) == $2 :), query_ip_number(this_object()));
    users = filter(users, (: ($1)->query_userid() != $2 :) ,query_userid());
    if (sizeof(users)>=bmax(MAX_DUMMY,dummy_limit))
       {write("�Բ������ڴ�����IP��¼�Ľ�ɫ���࣬ʹ����ʱ�޷����룬����ԭ�¡�\n");
        write("����ͬ��IP��ID��:  ");
        //SUBUG(users);
        for (idx=0;idx<sizeof(users);idx++)
            write(users[idx]->query_userid()+",");
        write("\n");
        get_lost_now();
        return;
       }
    }   
   /* added end */ 
    /* adjust the privilege of the user ob */
    if ( adminp(query_userid()) )
    set_privilege(1);
    else
    set_privilege(query_userid());

    /* check for link-deadedness */
    users = children(USER_OB) - ({ this_object() });
//    ids = users->query_userid();
	ids=users->query_body()->query_primary_id();

    if ( (idx = member_array(query_userid(), ids)) == -1 )
    {
    existing_user_enter_game();
    return;
    }
    if ( !interactive(the_user = users[idx]) )
    {
    if ( body = the_user->query_body() )
    {
        the_user->steal_body();
        start_shell();
        body->reconnect(this_object());
    }
    else
    {
        existing_user_enter_game();
    }
    return;
    }

    //write("\nYou are already logged in!\nThrow yourself off?  ");
    write("\n���Ѿ���������!\n��ȷ��Ҫ�滻��");
    modal_simple((: rcv_try_to_boot, the_user :));
}

/* when a user reconnects, this is used to steal the body back */
nomask void steal_body()
{
    /* only USER_OB can steal the body, and we should be non-interactive */
    if ( base_name(previous_object()) != USER_OB || interactive() )
    //error("illegal attempt to steal a body\n");
    error ("�Ƿ���ͼ͵������\n");
    body = 0;
    remove();
}

/*
** A new character has been created and all inputs have been entered.
** Do a bit of additional work and go for a body.
*/
static nomask void new_user_ready()
{
    remove_call_out();  /* all call outs */
#ifdef AUTO_WIZ
    /* auto-wiz everybody as they are created */
    //write(">>>>> You've been granted automatic guest wizard status. <<<<<\n");
    write("\n>>>>> �㱻�����Զ���Ϊ��ʦ <<<<<\n");
    unguarded(1, (: SECURE_D->create_wizard($(query_userid())) :));
#endif 
    /* auto-Admin the first wizard if there are no Admins */
    {
        string * members = SECURE_D->query_domain_members("Admin");

        if ( !sizeof(members) )
        {
            if( !wizardp(query_userid()))
			{
				write("���ڽ���ʦ.\n");
				unguarded( 1, (: SECURE_D->create_wizard($(query_userid())) :));
			}
            write( ">>>>> ���Զ���Ϊ Admin���ǵ��� admtool. <<<<<\n");
            unguarded(1, (: SECURE_D->add_domain_member("Admin",
                            $(query_userid()),
                            1) :));
        }
    }

    /* adjust the privilege of the user ob */
	write("׼������set_privilege����\n");
	write("query_userid()������:" + query_userid() + "\n");
    if ( adminp(query_userid()) )
	{
		write("��֧1\n");
		set_privilege(1);
	}
    else
	{
		write("��֧2\n");
		set_privilege(query_userid());
	}

    // pass a lfun pointer so that we don't have to worry about validating��֤
    // the call.
	write("׼������incarnate����\n");
    NEW_USER_D->create_user( (: incarnate, 1 :) );
}
