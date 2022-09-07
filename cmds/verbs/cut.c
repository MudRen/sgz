#include <mudlib.h>
#include <verb.h>
//ok
inherit VERB_OB;

void do_cut_str_with_str(string st1,string st2)
{
	object ob1,ob2;
	ob1=ENVMY_OB(st1);
	if(!ob1){ return;}
	ob2=MY_OB(st2);
	if(!ob2){ return;}
    if(!ob2->can_cut_with_obj())
	{
		write(ob2->short()+"����û�������ж�����\n");
		return;
	}
	if(!ob1->is_cutable())
	{
		write(ob1->short()+"�������С�\n");
		return;
	}
	ob2->do_cutting(ob1);
}
void do_cut_str(string str)
{
	object o;
	mixed ret;
	o=ENVMY_OB(str);
	if(!o) {return;}
	ret=o->direct_cut_obj();
	if(ret==1)
	{
		o->do_cutting();
		return;
	}
	if(!ret)
		ret=o->short()+"����û���С�\n";
	write(ret);
	return;

}
array query_verb_info()
{
	return ({ ({ "STR", "STR with STR", }) });
}
