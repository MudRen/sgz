// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

#include <mudlib.h>

inherit OBJ;
inherit M_OPENABLE;
inherit M_READABLE;

mixed direct_read_obj(object ob) {
    if (!is_open())
    //return "Perhaps you should open the book first.\n";
    return "��Ҫ�Ȱ��鷭����\n";
    return m_readable::direct_read_obj(ob);
}

mixed direct_read_str_word_obj(string str, string p, object ob) {
    if (!is_open())
    //return "Perhaps you should open the book first.\n";
    return "��Ҫ�Ȱ��鷭����\n";
    return m_readable::direct_read_str_word_obj(str, p, ob);
}
