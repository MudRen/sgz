// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */
#include <verb.h>
inherit VERB_OB;

void do_turn_str(string str)
{
	object o;
	mixed ret;
	o=MYENV_OB(str);
	if(!o) {return;}
	ret=o->direct_turn_obj();
	if(ret==1)
	{
		o->turn();
		return;
	}
	if(!ret)
		ret="��û����"+o->short()+"��\n";
	write(ret);
	return;
}

array query_verb_info()
{
   return ({ ({ "STR" }), ({ "water" }) });
}
