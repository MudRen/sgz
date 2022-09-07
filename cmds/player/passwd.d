// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

// Rust wrote this and was a bad boy and didn't attach a header - Beek

#include <mudlib.h>

inherit CMD;
inherit M_INPUT;

private nomask void done()
{
    modal_pop();
    destruct();
    return;
    /* no need to destruct... we didn't clone */
    /* We do now! -=Zakk */
}

private nomask void confirm_new_password(string s1, string s2)
{
    write("\n");

    if(s1 != s2)
    {
        write("密码必须符合。\n");
    }
    else
    {
        this_user()->set_password(s1);
        write("密码设定完成。\n");
    }

    done();
}

private nomask void get_new_password(string s)
{
    write("\n");

    if ( strlen(s) < 5 )
    {
        write("你的密码必须由五个或以上的字母组成。\n密码更改失败。\n");
        done();
    }
    else
    {
        modal_func((: confirm_new_password, s :), "请再输入一次：", 1);
    }
}

private nomask void confirm_current_password(string s)
{
    write("\n");

    if ( !this_user()->matches_password(s) )
    {
        write("密码不符合。\n密码更改失败。\n");
        done();
    }
    else
    {
        modal_func((: get_new_password :), "请输入新密码：", 1);
    }
}

void start_cmd()
{
    if(!clonep() || (base_name(previous_object()) != base_name()))  {
        write("试图非法使用 passwd 命令。\n"); 
        destruct();
        return;
    }

    modal_push((: confirm_current_password :),
               "请输入你当前的密码：", 1);
}


private void main()
{
    if(!clonep())  {
        new(base_name())->start_cmd();
        return;
    }
    destruct();
    return;
}

