// answer.c
// by fire on July 20, 1998
// ok
#include <verb.h>
inherit VERB_OB;

mixed can_answer_wrd_to_liv(string str,object liv) 
{
        return 1;
}
mixed do_answer_wrd_to_liv(string item, object liv )
{
    string p_act;
    string p_use;
    p_use=this_body()->query_userid();
    p_act=item;
    switch(item)
    {
        case "yes":
		case "��":
			this_body()->targetted_action("$N��$T������ǡ�\n",liv);
            break;
        case "no":
		case "��":
			this_body()->targetted_action("$N��$T���������\n",liv);
            break;
        default :                                               
		this_body()->targetted_action("$N��$T�����"+p_act+"\n",liv);
     }
     liv->be_answered(this_body(), item);
     return 1;
}
mixed do_answer_str_to_str(string item, string str )
{
	object o;
	o=ENV_LIV(str);
	if(!objectp(o)) return;
	do_answer_wrd_to_liv(item, o);
}

array query_verb_info()
{       
     return ({ ({"STR to STR" }) });
}
