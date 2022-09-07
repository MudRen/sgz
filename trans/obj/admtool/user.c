// Updated by emperor on 10 Mar 2003
// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */
/*
** user.c -- user administration options
**
** 950630, Deathblade: created.
*/
#include <mudlib.h>
#include <security.h>

#define PLHOME_PATH(x) sprintf("/data/home/%c/%s",x[0],x)

void std_handler(string str);
void do_one_arg(string arg_prompt, function fp, string arg);
void do_two_args(string arg1_prompt, string arg2_prompt,
             function fp, string arg);
varargs void modal_simple(function input_func, int secure);
varargs void modal_func(function input_func, mixed prompt_func, int
secure);
#ifdef USE_WIZ_POSITION
# define PROMPT_USER        "(AdmTool:user) [nwdpPmq?] > "
#else
# define PROMPT_USER        "(AdmTool:user) [nwdPmq?] > "
#endif
#define SECS_PER_DAY        (24 * 60 * 60)
private nomask void write_user_menu()
{
     write("�������ߣ��û�����\n"
           "\n"
           "   n [����]            - ɾ���û�\n"
           "   w [����]            - �����û�Ϊ��ʦ\n"
           "   d [����]            - ����ʦ�����������\n"
#ifdef USE_WIZ_POSITION
           "   p [����] [����]     - �趨��ʦ�ļ���\n"
#endif
           "   P [����]            - ɾ�� N ��û�����ߵ����\n" 
           "\n"
          "    m        - ��ѡ��\n"
          "    q        - �˳�\n"
          "    ?        - ����\n"
          "\n"  
          );     
}
private nomask void nuke_user(string userid, int skip_save)
{
    object o;
    mixed err;
    if ( o = find_user(userid) )
    {
    o->receive_private_msg("�Բ����㱻ɾ���ˡ�\n");
    o->quit();
    }
    MAILBOX_D->get_mailbox(userid)->nuke_mailbox(1);
    MAILBOX_D->unload_mailbox(userid);
    /* remove a bunch of files. note: some might not exist. */
    err = rm(LINK_PATH(userid) + __SAVE_EXTENSION__);
    err = rm(USER_PATH(userid) + __SAVE_EXTENSION__);
    err = rm(PSHELL_PATH(userid) + __SAVE_EXTENSION__);
    err = rm(WSHELL_PATH(userid) + __SAVE_EXTENSION__);
    err = rm(PLHOME_PATH(userid) + __SAVE_EXTENSION__);
    LAST_LOGIN_D->remove_user(userid, skip_save);
    err = SECURE_D->delete_wizard(userid);
  //### deal with clearing privs and stuff
//### this should be enough, but may need more thought (this was a quicky)
//### need to set it to something like @disabled so that unguarded() code
//### in the wiz dir doesn't have priv 1 now.
    SECURE_D->set_protection(WIZ_DIR "/" + userid, 1, -1);
    
    printf("'%s' has been nuked.\n", userid);
}
#if 0
private nomask void confirm_nuking(string name, string str)
{
    str = lower_case(str);
    if ( str != "y" && str != "yes" )
    {
    write("����ɾ����\n");//"Nuke aborted!\n");
    return;
    }
    nuke_user(name, 0);
}
#endif

private nomask void confirm_nuking(string name, string str)
{
	int i, j, ppl_cnt, count;
	string *dir, *ppls, *all_players;

    str = lower_case(str);
    if ( str != "y" && str != "yes" )
    {
    	write("����ɾ����\n");//"Nuke aborted!\n");
    	return;
	}
	all_players = ({});
	if(name=="all_id"){
		dir = get_dir("/data/links/");
		for(i=0; i<sizeof(dir); i++) {
			reset_eval_cost();
			//write(dir[i]);
			ppls = get_dir( "/data/links/" + dir[i] + "/");
			ppl_cnt += sizeof(ppls);
			for(j=0; j<sizeof(ppls); j++) {
				reset_eval_cost();
				if( sscanf(ppls[j], "%s.o", name)==1 ){
					if( adminp(name)) continue;
					if(wizardp(name)) continue;
					if(name=="zrd")   continue;
				
					all_players +=({name});
					nuke_user(name, 0);
				}
#if 0
				else {
					printf("ɾ���ļ�%s\n",ppls[j]);
					rm (ppls[j]);
				}
#endif
			}
		}
	}
	else nuke_user(name, 0);
}

private nomask void receive_name_for_nuking(string name)
{
    name = lower_case(name);
    printf(//"Are you sure you want to nuke '%s' ? "
           "��ȷ��Ҫɾ���û� %s ��", name);
    modal_simple((: confirm_nuking, name :));
}
private nomask void receive_name_for_wiz(string name)
{
    object ob;
    string err;
    if (!stringp(name) || name == "") {
        printf("��׼������˭��\n:");
        return;
    }
    name = lower_case(name);
    if ( SECURE_D->query_is_wizard(name) )
    {
        printf(//"** '%s' is already a wizard.\n"
               "** %s �Ѿ�����ʦ�ˡ�\n" , name);
        if (!is_directory (WIZ_DIR + name))
    {
            printf (//"However, /wiz/%s doesn't exist.  Creating...\n"
                    "���ǣ�"+WIZ_DIR+"/%s ��δ������������...\n", name);
            mkdir (WIZ_DIR + "/" + name);
            SECURE_D->set_protection (WIZ_DIR + "/"+ name, 1, name + ":");
    }
    return;
    }
    err = SECURE_D->create_wizard(name);
    if ( err )
    {
    printf("** Error: %s\n", err);
    return;
    }
    mkdir(WIZ_DIR "/" + name);
    SECURE_D->set_protection(WIZ_DIR "/" + name, 1, name + ":");
    printf(//"'%s' is now a wizard.\n"
           "%s �������ǳ�Ϊ��ʦ�ˡ�\n", name);
 //### switch to an action?
    ob = find_user(name);
    if ( ob )
    {
        tell(ob, //"You are now a wizard.  Changing bodies...\n"
                        "�����ڽ���Ϊ��ʦ����̥������...\n");
    ob->force_me("su");
    }
}
private nomask void receive_name_for_dewiz(string name)
{
    object ob;
    string err;
    name = lower_case(name);
    if ( adminp(name) )
    {
        printf(//"** '%s' is an admin and cannot be dewizzed.\n",
               "** %s �Ǵ��񣬲��ܱ���ְ��\n", 
               name);
    return;
    }
    if ( !SECURE_D->query_is_wizard(name) )
    {
        printf(//"** '%s' is not a wizard.\n"
               "** %s ���ڲ�������ʦ��\n", name);
    return;
    }
    err = SECURE_D->delete_wizard(name);
    if ( err )
    {
    printf("** Error: %s\n", err);
    return;
    }
    SECURE_D->set_protection(WIZ_DIR "/" + name, 1, -1);
    printf(//"'%s' is no longer a wizard.\n"
           "%s ���ڲ�������ʦ�ˡ�\n", name);
//### switch to an action?
    ob = find_user(name);
    if ( ob )
    {
        tell(ob, //"You have lost your wizard status.\n"
                        "�㱻����Ϊ��ͨ������ݡ�\n");
    ob->force_me("su");
    }
}
#ifdef USE_WIZ_POSITION
private nomask void receive_position_for_wiz(string name, string position)
{
    USER_D->set_variable(lower_case(name), "wiz_position", position);
    printf(//"%s's position has been set to: %s\n",
           "%s ��ְλ��������%s��\n",
       lower_case(name), position);
}
#endif
private nomask void confirm_purge(mixed * times, string str)
{
    str = lower_case(str);
    if ( str != "y" && str != "yes" )
    {
    write("ɾ��������\n");//"Purge aborted!\n");
    return;
    }
    foreach ( mixed * info in times )
    nuke_user(info[1], 1);
    LAST_LOGIN_D->save_me();
}
private nomask void receive_days_for_purge(string days)
{
    int limit = time() - (to_int(days) * SECS_PER_DAY);
    mixed * times = filter(LAST_LOGIN_D->query_times(),
                       (: $1[0] <= $(limit) :));
    printf(//"You will nuke %d users that have not logged on after %s.\n"
       //"Are you sure? ",
       "�㽫Ҫɾ�� %d λ�Դ� %s ��û�����ߵ���ҡ�\n��ȷ����",
       sizeof(times), ctime(limit));
    modal_simple((: confirm_purge, times :));
}
private nomask void receive_user_input(string str)
{
    string arg;
    sscanf(str, "%s %s", str, arg);
    switch ( str )
    {
    case "n":
        do_one_arg(//"Who should be nuked? ",
                   "׼��ɾ��˭��",
               (: receive_name_for_nuking :),
               arg);
    break;
    case "w":
        do_one_arg(//"Who should be wizzed? ",
                   "׼������˭��",     
               (: receive_name_for_wiz :),
               arg);
    break;
    case "d":
        do_one_arg(//"Who should be de-wizzed? ",
                   "׼����˭��ְ��",     
               (: receive_name_for_dewiz :),
               arg);
    break;
#ifdef USE_WIZ_POSITION
    case "p":
        do_two_args(//"Set position for who? ",
                    //"Set %s's to what? ",
                    "Ҫ�趨˭��ְλ��",
                    "�� %s ���ʲôְλ��",
                (: receive_position_for_wiz :),
                arg);
    break;
#endif
    case "P":
    do_one_arg("�����죿",
               (: receive_days_for_purge :),
               arg);
    break;
    case "?":
    write_user_menu();
    break;
    default:
    std_handler(str);
    break;
    }
}
static nomask void begin_user_menu()
{
    if ( !check_privilege(1) )
    {
        //write("Sorry... admin only.\n");
        write("�Բ���ֻ�Դ��񿪷š�\n");
    return;
    }
    modal_func((: receive_user_input :), PROMPT_USER);
    write_user_menu();
}