// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

/*
** put.c
**
*/

#include <move.h>

inherit VERB_OB;

void do_put_obj_wrd_obj(object ob1, string p, object ob2) {
    mixed tmp;
    string prep;

    if (!try_to_acquire(ob1))
        return;

    tmp = ob1->move(ob2, p);
    if (tmp == MOVE_OK) {
        switch (p) {
        case "in":
            prep = "into";
            break;
        case "on":
            prep = "onto";
            break;
        }
        write("��ɡ�\n");
        this_body()->other_action("$N��$o����" + prep_calc(prep, "$o1") + "��\n", ob1, ob2);
		if(ob1->query_is_money()) {
			this_body()->simple_action("��֪˭һ�Ѱ�$o�����ˡ�\n",ob1);
			destruct(ob1);
		}

        return;
    }
    if (!tmp) tmp = "�ⲻ̫���ܡ�\n";
    write(tmp);
}

void do_put_obs_wrd_obj(array info, string p, object ob2) {
    handle_obs(info, (: do_put_obj_wrd_obj :), p, ob2);
}


array query_verb_info()
{
    return ({
        ({ "OBS WRD OBJ" }), ({ "insert", "place", "stuff", "hide" })
          });
    
    /*
    ** "hide OBS next to OBJ" -> "put OBS next to OBJ"
    ** "hide OBS beside OBJ" -> "put OBS beside OBJ"
    ** "hide OBS with OBJ" -> "put OBS with OBJ"
    */
}


