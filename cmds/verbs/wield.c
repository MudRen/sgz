// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

//**********************************/
//*  move                          */
//**********************************/

#include <mudlib.h>
#include <verb.h>
inherit VERB_OB;

void do_wield_str(string str)
{
	object o;
	mixed ret;
	o=MY_OB(str);
	if(!o) {return;}
	ret=o->direct_wield_obj();
	if(ret==1)
	{
		this_body()->do_wield(o);
		return;
	}
	if(!ret)
		ret="��û��װ��"+o->short()+"��\n";
	write(ret);
	return;
    
    
}
 
array query_verb_info ()
{
    return ({ ({ "STR" }) });
}
