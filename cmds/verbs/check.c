// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

#include <mudlib.h>
#include <setbit.h>
#include <verb.h>
//ok
inherit VERB_OB;

void do_check_str(string str)
{
	object o;
	mixed ret;
	o=MYENV_OB(str);
	if(!o) return;
	this_body()->simple_action(
		"$N����"+o->short()+"��ϸ������һ��\n");

	if(ret=o->direct_check_obj());
	if(ret==1)
	{
		string disp;
		write("�㷢��"+o->short()+"���ԣ�\n");
		disp=o->check_obj();
		write(disp);
		if(wizardp(this_body())) {
			string *makers,*ls,p_room,room_name,p_area;
			object env;
			makers=CHAR_D->check_char("is_maker",1);
			if(sizeof(makers)) {
				write("����������            ����ID  �ɶ�  ������  ���ڵ���  ���ڷ��� ��\n");
				foreach(string mk in makers){
					ls=CHAR_D->get_char(mk,"goods");
					if(!ls) ls=({});
					if(member_array(str,ls)!=-1) {
						p_room=CHAR_D->get_char(mk,"shd_room");
						if(!stringp(p_room)) p_room="/noroom"; // illegial room
						env=load_object(p_room);
						if(!objectp(env)) {
							room_name="no room";
							p_area="no area";
						}
						else {
							room_name=env->short();
							p_area=AREA_D->get_area(env->get_area(),"name");
							if(!p_area) p_area="no area";
						}
						if(p_area=="no area")
							SGSYS("����"+mk+"û�кϷ�������");
						printf("%10s%18s  %4s  %6d%10s  %s\n",
							CHAR_D->get_char(mk,"name"),
							mk,( (CHAR_D->get_char(mk,"just_sell")==1) ?
							"����":"����"),	sizeof(ls),p_area,room_name);
					}
				}
			}
		}
		return;
	}
	if(stringp(ret))
	{
		write(ret);
		return;
	}
	write("���"+o->short()+"�ϲ鲻��ʲô��������\n");
	return;
		
}

array query_verb_info()
{
    return ({ ({ "STR" }) });
}
