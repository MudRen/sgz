// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

/*
** chanlist.c -- print available channels
**
** Print out the available channels in the system/intermud.  Note that
** the system allows any number of channels, so this will only print
** out some "suggested" channels.  This command is most effective for
** printing out a list of available Intermud channels.
**
** 950629, Deathblade: Created.
*/

#include <mudlib.h>
inherit CMD;

private nomask string fmt_imud_channel(string channel_name,
                                       mixed * channel_data)
{
    string owner = channel_data[0];
    string type = ({ "������",
                     "����",
                     "����" })[channel_data[1]];

    if ( owner == "*" )
        owner = "����״̬";

    return sprintf("%-19s Intermud: %s, %s\n",
                   channel_name, owner, type);
}

private void main(string arg)
{
    string s;
    mapping chanlist = IMUD_D->query_chanlist();

    s = "����Ƶ���б�\n-----------------------------\n"
        "gossip              ����\n"
        "newbie              ����\n"
        "news                ����\n"
        ;

    if ( wizardp(this_user()) )
        s +=
            "wiz                 ��ʦר��\n"
            "announce            ��ʦר��\n"
            "errors              ��ʦר��\n"
            ;

    if ( adminp(this_user()) )
        s +=
            "admin               ����ר��\n"
            ;

    if (wizardp(this_user()) )
    s += implode(({ "" }) + keys(chanlist),
                 (: $1 + fmt_imud_channel($2, $(chanlist)[$2]) :));

    out(s);
}
