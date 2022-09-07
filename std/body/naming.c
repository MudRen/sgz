// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

/*
** naming.c -- functions for naming and description of the player body
**
** 960603, Deathblade: created.
*/

#include <commands.h>           /* for CMD_OB_xxx */

#include <sanguo.h>
private string name = "���ع�·��";
private string describe;
private string invis_name;
private string nickname;
private string chinese_name;
string query_primary_id();

int is_visible();
int test_flag(int which);
int query_ghost();
object query_link();
string number_of(int num, string what);
void save_me();
string query_reflexive();
void remove_id(string array id...);
void add_id(string array id...);
void set_id(string array id...);

string in_room_desc();

#ifdef USE_TITLES
string query_title();
#endif

int query_prone();

string query_chinese_name()
{
    return (chinese_name) ? chinese_name : name;
}

string query_name()
{
    if ( invis_name == chinese_name || !invis_name ) invis_name = "ĳĳ";
    if ( !is_visible() ) return invis_name;
    return query_chinese_name();
}

string query_long_name()
{
    if (query_ghost())
        return query_chinese_name() + "�Ļ���";
#ifdef USE_TITLES
    return query_title();
#else
    return query_chinese_name() + "(" + name + ")";
#endif
}

nomask string query_userid()
{
    return name;
}

nomask string query_invis_name()
{
    return invis_name;
}

string query_idle_string()
{
    object link = query_link();
    int idle_time;
    string result = "";
    if(!objectp(link)) return "�����ˣ�";
    if ( interactive(link) )
       idle_time = query_idle(link)/60;
    if ( !idle_time )
      return "";

    if( idle_time > 24 * 60 )
        result += " [���� " + idle_time/(24 * 60) + " ��" + "]";
    else if( idle_time > 60 )
        result += " [���� " + idle_time/60 + " Сʱ" + "]";
    else
        result += " [���� " + idle_time + " ����" + "]";

    return result;
}

// This is used by in_room_desc and by who, one of which truncates,
// one of which doesnt.  Both want an idle time.
string base_in_room_desc()
{
    string result;
    object link = query_link();

    result = query_long_name();

    if (query_prone())
        return query_chinese_name() + "̱���ڵ���";

    /* if they are link-dead, then prepend something... */
    if ( !link || !interactive(link) )
        result = result + "������";

    return result;
}

string query_formatted_desc(int num_chars)
{
    string idle_string;
    int i;
  
    idle_string = query_idle_string();
    if ( i = strlen(idle_string) )
    {
        num_chars -= (i + 1);
        idle_string = " " + idle_string;
    }
    return M_ANSI->colour_truncate(base_in_room_desc(), num_chars) + idle_string;
}

void set_description(string str)
{
    if(base_name(previous_object()) == CMD_OB_DESCRIBE)
        describe = str;
    save_me();
}

string our_description()
{
    if (describe)
        return in_room_desc() + "\n" + describe ;

   return in_room_desc()+"\n";
}

void set_nickname(string arg)
{
    if (file_name(previous_object()) != CMD_OB_NICKNAME)
        error("Illegal call to set_nickname\n");

    if ( nickname )
        remove_id(nickname);

    nickname = arg;
}

string query_nickname()
{
    return nickname;
}

static void naming_create(string userid, string cname)
{
    name = userid;
    chinese_name = cname;
}

static void naming_init_ids()
{
    set_id(name, chinese_name); 
    if ( nickname )
        add_id(nickname);
}
string query_who_name() {
  return query_chinese_name()+"("+query_primary_id()+")";}
