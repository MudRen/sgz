// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

#include <mudlib.h>

inherit CMD;
inherit M_GRAMMAR;

private void main(string which)
{
    mapping data;
    mixed * info;

    if ( !which )
    {
        out("��Ҫָ��һ����ж��ʡ�\n");
        return;
    }

    data = SOUL_D->query_emote(which);
    if ( !data )
    {
        out("û�������ж��ʡ�\n");
        return;
    }

    if ( data[""] )
    {
        info = SOUL_D->get_soul(which, "", ({ }));
        outf("%s :\n  ��ῴ����%s���˻ῴ����%s\n",
               which, info[1][0], info[1][1]);
    }

    if ( data["LIV"] )
    {
        info = SOUL_D->get_soul(which, "LIV", ({ this_object() }));
        outf("%s somebody:\n  ��ῴ����%sĿ��ῴ����%s���˻ῴ����%s\n",
               which, info[1][0], info[1][1], info[1][2]);
    }

    if ( data["STR"] )
    {
        info = SOUL_D->get_soul(which, "STR", ({ "slowly" }));
        outf("%s slowly :\n     ��ῴ����%s���˻ῴ����%s\n",
               which, info[1][0], info[1][1]);
    }

    if ( data["LIV STR"] )
    {
        info = SOUL_D->get_soul(which, "LIV STR", ({ this_object(), "slowly" }));
        outf("%s somebody slowly :\n  ��ῴ����%sĿ��ῴ����%s���˻ῴ����%s\n",
               which, info[1][0], info[1][1], info[1][2]);
    }
}

string query_pronoun()
{
    return "��";
}
string query_reflexive()
{
    return "���Լ�";
}
string query_subjective()
{
    return query_pronoun();
}
string query_objective()
{
    return "��";
}
string query_possessive()
{
    return "����";
}
string query_named_possessive()
{
    return "ĳ�˵�";
}

string short()
{
    return "ĳ��";
}

void player_menu_entry (string s)
{
  bare_init();
  main (s);
  done_outputing();
}
