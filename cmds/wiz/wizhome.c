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
                this_body()->simple_action("$N已经在家了耶。");
                return;
            }
            msgs = this_body()->get_player_message("home");
            if (environment(this_body()))
                this_body()->my_action( "你回家喽。\n");
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
        out(arg + "属于无家可归人士。\n");
        return;
    }

    if( file_name( environment( this_body())) == home )
    {
        this_body()->simple_action("$N已经在这儿了，笨蛋！");
        return;
    }
    this_body()->simple_action("$N前往 " + arg +
      " 的家里找人聊天去了。");

    this_body()->move(home);

    tell_environment(this_body(), this_body()->query_name() +
      "看样子是来 " + arg + " 家混饭了。\n",
      0, ({ this_body() }));

    if(!(this_body()->test_flag(F_BRIEF)))
        this_body()->do_game_command("look");

    return;
}

int help(){
    write("用法: home [player]\n没有参数会让你回到自己工作间。\n");
    write("后面如果以巫师姓名为参数，则会到他人的工作间去拜访。\n");
    return 1;
}
