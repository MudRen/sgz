// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

#include <mudlib.h>

inherit VERB_OB;

int need_to_be_alive() {
    return 0;
}

int need_to_think() {
    return 0;
}

int need_to_see() {
    return 0;
}

mixed do_curse()
{
    write("�����Ļ�Ӧ���ø���ò����ʽ�ķ�ʽ��˵��\n");
}

array query_verb_info()
{
    return ({ ({ "" }), ({ "fuck","damn","shit","bitch"}) });
}
