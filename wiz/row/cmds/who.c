// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */
// Rust 2-6-94
#include <mudlib.h>
#include <daemons.h>
#include <playerflags.h>
#include <ansi.h>
inherit CMD;
#define DIVIDER "%%^H_CYAN%%^��������������������������������������������������������������������������%%^RESET%%^"
#define USER_DESC               "%%^H_WHITE%%^����%%^H_YELLOW%%^����б�%%^H_WHITE%%^����%%^RESET%%^  "
#define WHO_FORMAT      "%%^H_MAGENTA%%^��%%^H_GREEN%%^%s%%^H_MAGENTRA%%^��%%^RESET%%^  %%^H_WHITE%%^������ʱ�䣺%s��\n%sĿǰ����%d���������ܶ���%%^RESET%%^\n%s\n"
string get_who_string(string arg)
{
    object *u;
    int    bits, i;
    string name, extra, retval;
    mixed  info;
    if((sizeof(users())>25)&&(!arg))
      arg="-i";
    extra = retval = "\n";
    if (this_user())
    {               
        switch (arg)
        {
            case "-p":
                u = filter_array(users(), (: !wizardp($1) :));
                extra = USER_DESC + "\n";
                break;
            case "-w":
                u = filter_array(users(), (: wizardp :));
                                extra = "%%^H_WHITE%%^����%%^H_YELLOW%%^��ʦ�б�%%^H_WHITE%%^����%%^RESET%%^  ";
                break;
            case "-a":
                if ( wizardp(this_user()) )
                {
                    u = users();
                                extra = "%%^H_WHITE%%^����%%^H_YELLOW%%^������������%%^H_WHITE%%^����%%^RESET%%^  ";
                    break;
                }
                case "-i": 
                      extra="%%^H_WHITE%%^����%%^H_YELLOW%%^ID�б�%%^H_WHITE%%^����%%^RESET%%^  ";
                    retval += sprintf(WHO_FORMAT, mud_name(),
CHINESE_D->chinese_time(time()), extra, 
                      sizeof(users()), DIVIDER);
                      return retval+ sprintf("%-#79s\n", 
                       implode(users()->query_body()->query_who_name()-
               ({0}), "\n"));

            case "-m":
                if ( wizardp(this_user()) )
                {
                    u = filter_array(children(USER_OB),
                                     (: !interactive($1) :));
                                extra = "%%^H_WHITE%%^����%%^H_YELLOW%%^�������б�%%^H_WHITE%%^����%%^RESET%%^  ";
                    break;
                }
            case "-n": // sort according to country
                {
                      string *ids;
                      ids=users()->query_body()->query_primary_id();
                      ids=sort_array(ids,
                         (: (( CHAR_D->get_char($1,"nation")+"0" > 
                           CHAR_D->get_char($2,"nation")+"0" ) ? 1 : -1)
:));
                      u=({});
                      foreach(string id in ids) {
                          u+=({find_user(id)});
                      }
                                extra = "%%^H_WHITE%%^����%%^H_YELLOW%%^����������%%^H_WHITE%%^����%%^RESET%%^  ";
                      break;
                }
            case "-r": // sort according to reputation
                {
                      string *ids;
                      ids=users()->query_body()->query_primary_id();
                      ids=sort_array(ids,
                         (: (( CHAR_D->get_char($1,"reputation") > 
                           CHAR_D->get_char($2,"reputation") ) ? 1 : -1):));
                      u=({});
                      foreach(string id in ids) {
                          u+=({find_user(id)});
                      }
                                extra = "%%^H_WHITE%%^����%%^H_YELLOW%%^����������%%^H_WHITE%%^����%%^RESET%%^  ";
                      break;
                }
            case "-l": // sort according to level
                {
                      string *ids;
                      ids=users()->query_body()->query_primary_id();
                      ids=sort_array(ids,
                         (: (( CHAR_D->get_char($1,"level") > 
                           CHAR_D->get_char($2,"level") ) ? 1 : -1) :));
                      u=({});
                      foreach(string id in ids) {
                          u+=({find_user(id)});
                      }
                                extra = "%%^H_WHITE%%^����%%^H_YELLOW%%^����ְ����%%^H_WHITE%%^����%%^RESET%%^  ";
                      break;
                }
            default:
                if(arg) return "�÷������� help who �鿴������\n";
//                    retval += "Who: ����� flag��\n";
                u = users();
        }
    }
    else
          u = filter_array(users(), (: $1->query_body()->is_visible() :));
    retval += sprintf(WHO_FORMAT, mud_name(), CHINESE_D->chinese_time(time
()), extra, 
                      sizeof(u), DIVIDER);
    i = sizeof(u);
    if(!i)
        retval += sprintf("%|70s\n","�Բ���û��������");
    while(i--)
    {
        if(!objectp(u[i])) continue;
        if (!u[i]->query_body())
            continue;
        name = u[i]->query_body()->in_room_desc();
        bits = u[i]->query_body()->get_flags(PLAYER_FLAGS);
        if(!name)
            name = u[i]->query_userid();
        if(!(u[i]->query_body()->is_visible()))
            name = "("+name+")";
        if(u[i]->query_body()->test_flag(F_IN_EDIT))
             name += HIM + " -�༭��-" + NOR;
        if(u[i]->query_body()->test_flag(F_INACTIVE))
          name += HIM + " -������-" + NOR;
        retval += sprintf("��%s��%-68s\n",
           u[i]->query_body()->query_literate_str(),name);
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
