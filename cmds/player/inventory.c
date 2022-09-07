// Updated by stefan on 10 Jan 1997 modified by fire on 20 Jan 1998
/* Do not remove the headers from this file! see /USAGE for more info. */
// Rust/Belboz@ZorkMUD wrote it
// Megaboz added header and help 5-5-94
// Beek decided to edit this one when he noticed we had two
// inventory commands.  *boggle*
#include <mudlib.h>
inherit CMD;
string my_disp(object me,array obs);

private void main(string arg)
{
    string ex;
    object user;
    if(!arg)
    {
		ex = my_disp(this_body(),all_inventory(this_body()));
    	if (sizeof(ex)) {
        	out("�����ϴ���������Ʒ(���أ�"+
				this_body()->query_capacity("in")*100/
				this_body()->query_max_capacity("in")+"%)��\n" + ex);
    	} else {
        	out("������ʲôҲû�С�\n");
    	}
    }
    else 
    {
	if (!wizardp(this_body()))
        {
		out("ֻ����ʦ�ſ���͸�����ˡ�\n");
		return;
        }
	else
	{
		user=find_body(arg);
		if(!objectp(user))
		{
			out("û������ˡ�\n");
			return;
		}
		else
		{
//		    	if (ex = inv_list(all_inventory(user)))
			ex = my_disp(user,all_inventory(user));
			if (sizeof(ex))
			{
        			out(user->short()+"���ϴ���������Ʒ(���أ�"+
				user->query_capacity("in")*100/
				user->query_max_capacity("in")+"%)��\n" + ex);
		    	} 
			else
			{
        			out(user->short()+"����ʲôҲû�С�\n");
    			}
		}
	}
    }
    return;
}


string my_disp(object me,array obs)
{
	string ret="";
	string stat;
	string id;
	int bef,aft;
	object o;
	array sg_ob,wear_ob;
	object obw=me->query_weapon();
	if(!sizeof(obs)) return "";
	if((objectp(obw))&&(obw!=me)){
		ret="%^BLUE%^��%^RESET%^"+obw->short()+"\n";
		obs-=({obw});
	}
	if(!sizeof(obs)) return ret;
	wear_ob=({});
    foreach (object ob2 in obs) 
    {
       	stat=ob2-> ob_state() ;
        if(stringp(stat))
		{
			ret+="%^BLUE%^��%^RESET%^"+ob2->short()+"\n";
			wear_ob+=({ob2});
		}
	}

	obs-=wear_ob;	
	sg_ob=filter_array(obs,(: $1->sg_obj() :));
//	sg_ob=obs;
	if(sizeof(sg_ob))
		obs-=sg_ob;
	while(sizeof(sg_ob))
	{
		bef=sizeof(sg_ob);
		id=sg_ob[0]->query_id()[0];
		o=sg_ob[0];
		sg_ob=filter_array(sg_ob, (: ($1->query_id()[0])!=$(id) :));
		aft=sizeof(sg_ob);
		ret+="  "+chinese_number(bef-aft)+o->query_unit()+
			o->short()+"\n";
	}
		
	if(sizeof(obs))
	{
		ret+=inv_list(obs);
	}
	return ret;
}
