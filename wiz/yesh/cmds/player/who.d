// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

// Rust 2-6-94

#include <mudlib.h>
#include <daemons.h>
#include <playerflags.h>

inherit CMD;

#define DIVIDER \
"��������������������������������������������������������������������������"

#define USER_DESC		"��������б�"
#define WHO_FORMAT	"%s��������ʱ�䣺%s��%s%d���û���\n%s\n"


string get_who_string(string arg)
{
    object *u;
    int    bits, i;
    string name, extra, retval;
    mixed  info;

    extra = retval = "\n";
    if (this_user())
    {               
        switch (arg)
        {
            case "-p":
            case "-z":
                u = filter_array(users(), (: !wizardp($1) :));
                extra = USER_DESC + "\n";
                break;
            case "-w":
            case "-i":
                u = filter_array(users(), (: wizardp :));
				extra = "������ʦ�б�\n";
                break;
            case "-l":
                if ( wizardp(this_user()) )
                {
                    u = users();
				extra = "����������������\n";
                    break;
                }
            case "-m":
                if ( wizardp(this_user()) )
                {
                    u = filter_array(children(USER_OB),
                                     (: !interactive($1) :));
				extra = "�����������б�\n";
                    break;
                }
            default:
                if(arg)
                    retval += "Who: ����� flag��\n";
                u = users();
        }
        if(!wizardp(this_user()))
          u = filter_array(users(), (: $1->query_body()->is_visible() :));
    }
    else
          u = filter_array(users(), (: $1->query_body()->is_visible() :));

    retval += sprintf(WHO_FORMAT, mud_name(), CHINESE_D->chinese_time(time()), extra, 
                      sizeof(u), DIVIDER);
    i = sizeof(u);
    if(!i)
        retval += sprintf("%|70s\n","�Բ���û��������");
    while(i--)
    {
        if (!u[i]->query_body())
            continue;
        name = u[i]->query_body()->query_formatted_desc(78);

        bits = u[i]->query_body()->get_flags(PLAYER_FLAGS);
        if(!name)
            name = u[i]->query_userid();

        if(!(u[i]->query_body()->is_visible()))
            name = "("+name+")";
        if(u[i]->query_body()->test_flag(F_IN_EDIT))
            name = "*"+ name;
        retval += sprintf("%-68s\n",name);
    }
    return retval + DIVIDER;
}

private void main(string arg)
{
    if( arg == "" )
        arg = 0;

    out(get_who_string(arg));
}

void player_menu_entry()
{
  bare_init();
  main(0);
  done_outputing();
}
