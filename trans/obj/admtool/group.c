// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

/*
** group.c -- group adminstration
**
** 960115, Deathblade: created.
*/

#include <mudlib.h>
#include <security.h>

void std_handler(string str);
void do_one_arg(string arg_prompt, function fp, string arg);
void do_two_args(string arg1_prompt, string arg2_prompt,
                 function fp, string arg);

varargs void modal_func(function input_func, mixed prompt_func, int secure);

#define PROMPT_GROUP    "(AdmTool:group) [lscduarmq?] > "


private nomask void write_group_menu()
{
/*
    write("Administration Tool: group administration\n"
          "\n"
          "    l                - list groups\n"
          "    s [group]        - show a group's members\n"
          "\n"
          "    c [group]        - create a group              [Mudlib:]\n"
          "    d [group]        - delete a group              [Mudlib:]\n"
          "\n"
          "    u [user]         - show user's groups\n"
          "    a [user] [group] - add user to a group         [Mudlib:]\n"
          "    r [user] [group] - remove a user from a group  [Mudlib:]\n"
          "\n"
          "    m                - main menu\n"
          "    q                - quit\n"
          "    ?                - help\n"
          "\n"
          );
*/
    write("�����ߣ���Ⱥ����\n"
          "\n"
          "    l                - ��Ⱥ�б�\n"  
          "    s [��Ⱥ]         - ��Ⱥ��Ա�б�\n"
          "\n"
          "    c [��Ⱥ]         - ������Ⱥ\n"
          "    d [��Ⱥ]         - ɾ����Ⱥ\n"
          "\n"
          "    u [�û�]         - ��ʾ�û���������Ⱥ\n"
          "    a [�û�] [��Ⱥ]  - ���û�������Ⱥ\n"
          "    r [�û�] [��Ⱥ]  - ����Ⱥ��ɾ���û�\n"
          "\n"
          "    m        - ��ѡ��\n"
          "    q        - �˳�\n"
          "    ?        - ����\n"
          "\n"            
          ); 
}

private nomask void list_groups()
{
    string * groups;

    groups = keys(GROUP_D->get_group_data());
    if ( !sizeof(groups) )
    {
        //write("There are no groups.\n");
        write("û����Ⱥ���ڡ�\n");
    }
    else
    {
        printf(//"The following groups exist:\n%-#78s\n",
               "����������Ⱥ��\n%-#78s\n",
               implode(sort_array(groups, 1), "\n") + "\n");
    }
}

private nomask void show_group_members(string group)
{
    string * members;
int i;
    group = lower_case(group);
    members = GROUP_D->get_group_data()[group];
    if ( !members )
    {
        printf(//"There is no group named '%s'.\n",
               "û���� %s Ϊ������Ⱥ��\n", group);
    }
    else
    {
        printf(//"Group %s:\n"
               "��Ⱥ %s ��\n", group);
        

        switch ( sizeof(members) )
        {
        case 0:
            //write("Members: (none)\n");
            write("��Ա��       (��)\n");
            break;

        case 1:
            printf(//"Member:  %s\n"
                   "��Ա��      %s\n", members[0]);
            break;

        default:
            printf(//"Members: %s\n"
                   "��Ա��      %s\n", implode(members, ", "));
            break;
        }
    }
}

private nomask void create_group(string group)
{
    group = lower_case(group);

    GROUP_D->add_group(group);

    printf(//"Group %s created.\n"
           "��Ⱥ %s ���ɡ�\n", group);
}

private nomask void delete_group(string group)
{
    group = lower_case(group);

    GROUP_D->remove_group(group);

    printf(//"Group %s deleted.\n"
           "��Ⱥ %s ɾ����\n", group);
}

private nomask void show_users_groups(string user)
{
    mapping groups;

    user = lower_case(user);
    groups = filter(GROUP_D->get_group_data(),
                    (: member_array($(user), $2) != -1 :));

    if ( !sizeof(groups) )
        printf(//"%s doesn't belong to any groups.\n"
               "�û� %s �������κ���Ⱥ��\n", user);
    else
        printf(//"%s belongs to: %s.\n",
               "�û� %s ������Ⱥ��%s��\n", user,
               implode(sort_array(keys(groups), 1), ", "));
}

private nomask void add_user_to_group(string user, string group)
{
    user = lower_case(user);
    group = lower_case(group);

    if ( !GROUP_D->get_group_data()[group] )
    {
        printf(//"There is no group named '%s'.\n"
               "û���� %s Ϊ������Ⱥ��\n", group);
    }
    else
    {
        GROUP_D->add_group_member(group, user);

        printf(//"Added %s to group %s.\n"
               "�� %s ������Ⱥ %s��\n", user, group);
    }
}

private nomask void remove_user_from_group(string user, string group)
{
    user = lower_case(user);
    group = lower_case(group);

    GROUP_D->remove_group_member(group, user);

    printf(//"Removed %s from group %s.\n"
           "�� %s ����Ⱥ %s ��ɾ����\n", user, group);
}

private nomask void receive_group_input(string str)
{
    string arg;

    if ( sizeof(str) > 1 )
    {
        if ( sscanf(str, "%s %s", str, arg) != 2 )
        {
            //write("** Format is: <option> <argument>\n");
            write("** ��ʽ��<option> <argument>\n");
            write_group_menu();
            return;
        }
    }

    switch ( str )
    {
    case "l":
        if ( arg )
            //write("** No argument is required.\n");
            write("** ���������\n");
        list_groups();
        break;

    case "s":
        do_one_arg(//"Show members of which group? ",
                   "��ʾ��һ����Ⱥ�ĳ�Ա��",     
                   (: show_group_members :),
                   arg);
        break;

    case "c":
        do_one_arg(//"Name for the new group? ",
                   "����Ⱥ�����ƣ�",    
                   (: create_group :),
                   arg);
        break;

    case "d":
        do_one_arg(//"Delete which group? ",
                   "ɾ����һ����Ⱥ��",     
                   (: delete_group :),
                   arg);
        break;

    case "u":
        do_one_arg(//"Show groups for which user? ",
                   "��ʾ��һ���û�����Ⱥ��",     
                   (: show_users_groups :),
                   arg);
        break;

    case "a":
        do_two_args(//"Add which user? ",
                    //"Add '%s' to which group? ",
                    "�����ĸ��û���",    
                    "���� %s ���ĸ���Ⱥ��",        
                    (: add_user_to_group :),
                    arg);
        break;

    case "r":
        do_two_args(//"Remove which user? ",
                    //"Remove '%s' from which group? ",
                    "ɾ���ĸ��û���",
                    "�� %s ���ĸ���Ⱥ��ɾ����",
                    (: remove_user_from_group :),
                    arg);
        break;

    case "?":
        write_group_menu();
        break;

    default:
        std_handler(str);
        break;
    }
}

static nomask void begin_group_menu()
{
    modal_func((: receive_group_input :), PROMPT_GROUP);
    write_group_menu();
}
