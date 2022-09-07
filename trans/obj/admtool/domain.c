// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

/*
** domain.c -- domain adminstration
**
** 950710, Deathblade: Created.
*/

#include <mudlib.h>
#include <security.h>

int write_error(string err);
void std_handler(string str);
void do_one_arg(string arg_prompt, function fp, string arg);
void do_two_args(string arg1_prompt, string arg2_prompt,
                 function fp, string arg);

varargs void modal_func(function input_func, mixed prompt_func, int secure);

#define PROMPT_DOMAIN   "(AdmTool:domain) [lscCduaArmq?] > "


private nomask void write_domain_menu()
{
/*
    write("Administration Tool: domain administration\n"
          "\n"
          "    l                 - list domains\n"
          "    s [domain]        - show domain information\n"
          "\n"
          "    c [domain]        - create a domain                  [admin]\n"
          "    C [domain]        - create abstract domain (no dir)  [admin]\n"
          "    d [domain]        - delete a domain                  [admin]\n"
          "\n"
          "    u [user]          - show user's domains\n"
          "    a [user] [domain] - add user to a domain             [lord]\n"
          "    A [user] [domain] - add user as a lord of the domain [lord]\n"
          "    r [user] [domain] - remove a user from a domain      [lord]\n"
          "\n"
          "    m                 - main menu\n"
          "    q                 - quit\n"
          "    ?                 - help\n"
          "\n"
          );
*/
    write("�����ߣ��������\n"
          "\n"
          "    l                 - �����б�\n"       
          "    s [����]          - ��ʾĳ������Ϣ\n"
          "\n"
          "    c [����]          - ����һ������                 [����]\n" 
          "    C [����]          - ����һ����������(��Ŀ¼)     [����]\n"
          "    d [����]          - ɾ��һ������                 [����]\n"              
          "\n"
          "    u [�û�]          - ��ʾ�û���Ϣ\n"
          "    a [�û�] [����]   - ���û�����һ������           [����]\n"
          "    A [�û�] [����]   - �����û�Ϊ����               [����]\n"      
          "    r [�û�] [����]   - ���û���������ɾ��           [����]\n"      
          "\n"                                          
          "    m        - ��ѡ��\n"
          "    q        - �˳�\n"
          "    ?        - ����\n"
          "\n"
          );      
          
}

private nomask void list_domains()
{
    string * domains;

    domains = SECURE_D->query_domains();
    if ( !sizeof(domains) )
    {
        //write("There are no domains.\n");
        write("û���κ�����\n");
    }
    else
    {
        printf(//"The following domains exist:\n%-#78s\n",
               "������������\n%-#78s\n",
               implode(sort_array(domains, 1), "\n") + "\n");
    }
}

private nomask void show_domain_info(string domain)
{
    string * members;
    string * lords;

    members = SECURE_D->query_domain_members(domain);
    if ( !members )
    {
        //printf("There is no domain named '%s'\n", domain);
        printf("û���� %s Ϊ��������\n", domain);
    }
    else
    {
        lords = SECURE_D->query_domain_lords(domain) || ({ });
        members -= lords;

        //printf("Domain %s:\n", domain);
        printf("���� %s��\n", domain);

        switch ( sizeof(lords) )
        {
        case 0:
            //write("Lords:   (none)\n");
            write("������       (��ȱ)\n");
            break;

        case 1:
            //printf("Lord:    %s\n", lords[0]);
            printf("������      %s\n", lords[0]);
            break;

        default:
            printf("������      %s\n", //"Lords:   %s\n", 
                   implode(lords, ", "));
            break;
        }

        switch ( sizeof(members) )
        {
        case 0:
            //write("Members: (none)\n");
            write("��Ա��       (��)\n");
            break;

        case 1:
            //printf("Member:  %s\n", members[0]);
            printf("��Ա��      %s\n", members[0]);
            break;

        default:
            printf("��Ա��      %s\n",//"Members: %s\n",
             implode(members, ", "));
            break;
        }
    }
}

private nomask void create_domain(int no_domain_dir, string domain)
{
    string err;

    domain = lower_case(domain);

    /* this checks for admins... */
    if ( write_error(SECURE_D->create_domain(domain)) )
        return;

    //write("Domain created.\n");
    write("���򽨳ɡ�\n");

    if ( !no_domain_dir )
    {
        string dirname = "/domains/" + domain;

        mkdir(dirname);
        //printf("Created %s\n", dirname);
        printf("���� %s\n", dirname);
        printf(//"Setting protection level of %s\n",
               "�趨 %s �ı�������\n", dirname);
        
        write_error(SECURE_D->set_protection(dirname,
                                             1,
                                             domain + ":"));
    }
}

private nomask void delete_domain(string domain)
{
    SECURE_D->set_protection("/domains/" + domain, 1, -1);

    /* this checks for admins... */
    if ( write_error(SECURE_D->delete_domain(domain)) )
        return;

    //write("Domain deleted.\n");
    write("����ɾ���ˡ�\n");
}

private nomask void show_users_domains(string user)
{
    string * domains;

    domains = SECURE_D->query_domains(user) || ({ });
    if ( !sizeof(domains) )
        //printf("Wizard %s doesn't belong to any domain.\n", user);
        printf("��ʦ %s �������κ�һ������\n", user);
    else
        printf(//"Wizard %s belongs to %s.\n", 
               "��ʦ %s ���� %s��\n", user,
               implode(sort_array(domains, 1), ", "));
}

private nomask void add_user_to_domain(int lord, string user, string domain)
{
    /* this checks for lord privs... */
    if ( write_error(SECURE_D->add_domain_member(domain, user, lord)) )
        return;

    printf(//"Added %s %s %s.\n",
           "�� %s %s��\n", user, lord ? "��Ϊ "+domain+" ������" : "���� "+domain);
}

private nomask void remove_user_from_domain(string user, string domain)
{
    /* this checks for lord privs... */
    if ( write_error(SECURE_D->remove_domain_member(domain, user)) )
        return;

    //printf("Removed %s from %s.\n", user, domain);
    printf("�� %s �� %s ������ɾ����\n", user, domain);
}

private nomask void receive_domain_input(string str)
{
    string arg;

    if ( sizeof(str) > 1 )
    {
        if ( sscanf(str, "%s %s", str, arg) != 2 )
        {
            //write("** Format is: <option> <argument>\n");
            write("** ��ʽ��<option> <argument>\n");
            write_domain_menu();
            return;
        }
    }

    switch ( str )
    {
    case "l":
        if ( arg )
            //write("** No argument is required.\n");
            write("** ���������\n");
        list_domains();
        break;

    case "s":
        do_one_arg(//"Show information on which domain? ",
                   "��ʾ��һ���������Ϣ��",
                   (: show_domain_info :),
                   arg);
        break;

    case "c":
        do_one_arg(//"Name for the new domain? ",
                   "����������ƣ�",
                   (: create_domain, 0 :),
                   arg);
        break;

    case "C":
        do_one_arg(//"Name for the new domain? ",
                   "����������ƣ�",
                   (: create_domain, 1 :),      /* 1 == no_domain_dir */
                   arg);
        break;

    case "d":
        do_one_arg(//"Delete which domain? ",
                   "ɾ����һ������",     
                   (: delete_domain :),
                   arg);
        break;

    case "u":
        do_one_arg(//"Show information for which user? ",
                   "��ʾ��һ���û�����Ϣ��",     
                   (: show_users_domains :),
                   arg);
        break;

    case "a":
        do_two_args(//"Add which user? ",
                    "�����ĸ��û���",    
                    //"Add '%s' to which domain? ",
                    "���� %s ���ĸ�����",
                    (: add_user_to_domain, 0 :),
                    arg);
        break;

    case "A":
        do_two_args(//"Add which user as a lord? ",
                    //"Add '%s' to which domain? ",
                    "���ĸ��û�����Ϊ������",
                    "���� %s ���ĸ�����", 
                    (: add_user_to_domain, 1 :), /* 1 == lord */
                    arg);
        break;

    case "r":
        do_two_args(//"Remove which user? ",
                    //"Remove '%s' from which domain? ",
                    "ɾ���ĸ��û���",
                    "�� %s ���ĸ�������ɾ����",
                    (: remove_user_from_domain :),
                    arg);
        break;

    case "?":
        write_domain_menu();
        break;

    default:
        std_handler(str);
        break;
    }
}

static nomask void begin_domain_menu()
{
    modal_func((: receive_domain_input :), PROMPT_DOMAIN);
    write_domain_menu();
}
