// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */
/* Included for historical reasons - ie: practically every Infocom game
 * with the notable exception of Nord and Bert included support for it.

*/

#include <mudlib.h>
#include <setbit.h>

inherit VERB_OB;

string can_molest_obj(object ob) {
    if (ob && ob->is_living())
        return "���ڣ����ڣ��ú��档\n";
    else
        return "��ô���˻��ɵľٶ�����\n";
}

array query_verb_info()
{
    return ({ ({ "OBJ" }) });
}
