// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

/* Megaboz's attempt at a home cmd  4-23-94 */

#include <mudlib.h>
#include <playerflags.h>

inherit CMD;

mapping homes = ([]);

object find_home(string name) {
    if (homes[name]) return homes[name];

    homes[name] = new(TEMP_WORKROOM);
    homes[name]->set_owner(name);
    return homes[name];
}

private void main(string arg)
{
    object ob;
    string *msgs;
    string home;

    if (!arg)
    {
        object env = environment(this_body());
        if( env )
        {
            if( file_name(env) == this_body()->query_home())
            {
                this_body()->simple_action("$N�Ѿ��ڼ���Ү��");
                return;
            }
            msgs = this_body()->get_player_message("home");
            if (environment(this_body()))
                this_body()->my_action( "��ؼ�ඡ�\n");
            this_body()->other_action( msgs[1]);
        }
        home = this_body()->query_home();
        if (home == "CLONE") {
            ob = find_home(this_body()->query_name());
            this_body()->move(ob);
        }
        else
            this_body()->move(home);

        msgs = this_body()->get_player_message("menter");
        tell_environment(this_body(), msgs[1], 0, ({ this_body() }));

        if ( !(this_body()->test_flag(F_BRIEF)) )
            this_body()->do_game_command("look");

        return;
    }

    home = WIZ_DIR + "/" + arg + "/workroom";
    if ( file_size(home + ".c") <= 0 )
    {
        out(arg + "�����޼ҿɹ���ʿ��\n");
        return;
    }

    if( file_name( environment( this_body())) == home )
    {
        this_body()->simple_action("$N�Ѿ�������ˣ�������");
        return;
    }
    this_body()->simple_action("$Nǰ�� " + arg +
      " �ļ�����������ȥ�ˡ�");

    this_body()->move(home);

    tell_environment(this_body(), this_body()->query_name() +
      "���������� " + arg + " �һ췹�ˡ�\n",
      0, ({ this_body() }));

    if(!(this_body()->test_flag(F_BRIEF)))
        this_body()->do_game_command("look");

    return;
}

int help(){
    write("�÷�: home [player]\nû�в���������ص��Լ������䡣\n");
    write("�����������ʦ����Ϊ��������ᵽ���˵Ĺ�����ȥ�ݷá�\n");
    return 1;
}
