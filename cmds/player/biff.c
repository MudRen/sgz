// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

/*
** biff.c
**
** Adjust the "biff" setting (mail announcements)
**
** Created 31-OCT-94, Deathblade.
*/

#include <flags.h>
#include <mudlib.h>

inherit CMD;

#define USAGE "用法: biff [on | off]\n"

private string query_setting()
{
    return this_body()->test_flag(F_BIFF) ? "开启" : "关闭";
}

nomask private void main(string arg)
{
    if ( !arg || arg == "" )
    {
	out("你的邮件提示信号现在是：" + query_setting() +
	      "。\n" + USAGE);
	return;
    }

    switch ( arg )
    {
    case "on":
	this_body()->set_flag(F_BIFF);
	break;

    case "off":
	this_body()->clear_flag(F_BIFF);
	break;

    default:
	out(USAGE);
	return;
    }

    out("你的邮件提示信号现在改为：" + query_setting() + "\n");
}
