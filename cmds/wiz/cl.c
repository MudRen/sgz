// similar to clone, but used to clone obj through obj_d
/* Do not remove the headers from this file! see /USAGE for more info. */
#include <mudlib.h>
#include <move.h>
#define space "                                         "
inherit CMD;
inherit M_ANSI;
void dis_all_obj();
void dis_objs(string *ids);
void dis_list();
private void main( string str ) {
    object o, ob;
	string *ids;
	if(str=="list") {
		dis_list();
		return;
	}
	if((!str)||(str==""))
	{	
		dis_all_obj();
		return;
	}
	ids=OBJ_D->check_obj("type",str);
	if(sizeof(ids))
	{
		dis_objs(ids);
		return;
	}
	ids=OBJ_D->check_obj("sub_type",str);
	if(sizeof(ids))
	{
		dis_objs(ids);
		return;
	}
	o=OBJ_D->clone_obj(str);
	if(objectp(o))
		this_body()->do_player_message("clone", o);
	else{ 
		if(stringp(o))
			printf("%O\n",o);
		return;
	}
    if (o->get() != MOVE_OK || o->move(this_body()) != MOVE_OK) {
        if (o->move(environment(this_body())) != MOVE_OK)
            out("��ɡ�(�޷��ƶ�)\n");
        else
            out("��ɡ�(��������)\n");
    } else
        out("��ɡ�(���������Ʒ��)\n");
    return;
}
void dis_objs(string *ids)
{
	mixed obs;
	int sum,count=0,p_len=0,i;
	int N=27,C=3;
	string tmp;
	obs=OBJ_D->get_obj();
	sum=sizeof(ids);
	for(i=0;i<sum;++i)
	{
		if(p_len>0) {
			tmp=space[0..p_len-1];
			printf("%s",tmp);
		}
		tmp=obs[ids[i]]["name"]+"("+ids[i]+") ";
		if(obs[ids[i]]["level"])
			tmp=obs[ids[i]]["level"]+"_"+tmp;
		p_len=colour_strlen(tmp);
		printf("%s",tmp);
		p_len=N-p_len;
		while(p_len<0){
			p_len+=N;
			count++;
		}
		count++;
		if(count>=C) {
			printf("\n");
			count=0;
			p_len=0;
		}
	}
	printf("\n");
	printf("�鵽��Ʒ��%d����\n",sum);

}
void dis_all_obj()
{
	mixed obs;
	string *ids;
	int sum,count=0,p_len=0,i;
	int N=27,C=3;
	string tmp;
	obs=OBJ_D->get_obj();
	ids=keys(obs);
	sum=sizeof(ids);
	for(i=0;i<sum;++i)
	{
		if(p_len>0) {
			tmp=space[0..p_len-1];
			printf("%s",tmp);
		}
		tmp=obs[ids[i]]["name"]+"("+ids[i]+") ";
		if(obs[ids[i]]["level"])
			tmp=obs[ids[i]]["level"]+"_"+tmp;
		p_len=colour_strlen(tmp);
		printf("%s",tmp);
		p_len=N-p_len;
		while(p_len<0){
			p_len+=N;
			count++;
		}
		count++;
		if(count>=C) {
			printf("\n");
			count=0;
			p_len=0;
		}
	}
	printf("\n");
	printf("�鵽��Ʒ��%d����\n",sum);
}

void dis_list()
{
	string dis="",*obs;
	string *makers,*ls,p_room,room_name,p_area;
	int i=1;
	object env;
        mapping ob_tmp=([]);
	mapping mk_dt=([]);
	makers=CHAR_D->check_char("is_maker",1);
	if(!sizeof(makers)) return; 
	obs=OBJ_D->get_obj("list");
        if(!sizeof(obs)) return;
        foreach(string o_id in obs) {
	    ob_tmp[o_id]=OBJ_D->get_obj(o_id,"type")+
              OBJ_D->get_obj(o_id,"sub_type")+
              OBJ_D->get_obj(o_id,"level");
	}
        obs=sort_array(obs, (:
                ($(ob_tmp)[$1]>$(ob_tmp)[$2] ? 1 : -1 ) :) );
        foreach(string mk in makers)
	{
		mk_dt[mk]=CHAR_D->get_char(mk);
	}
	foreach(string ob in obs) {
		dis+=sprintf("[%d] ID: %s  ���ƣ�%s�ȼ���%d\n",
			i,ob,OBJ_D->get_obj(ob,"name"),OBJ_D->get_obj(ob,"level"));
		i++;
//		dis+=sprintf("����������            ����ID  �ɶ�  ������  ���ڵ���  ���ڷ��� ��\n");
		foreach(string mk in makers){
			ls=mk_dt[mk]["goods"];
			if(!ls) ls=({});
			if(member_array(ob,ls)!=-1) {
				p_room=mk_dt[mk]["shd_room"];
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
				dis+=sprintf("%10s%18s  %4s  %6d%10s  %s\n",
					mk_dt[mk]["name"],mk,
					((mk_dt[mk]["just_sell"]==1) ? "����":"����"),
					sizeof(ls),p_area,room_name);
			}
		}
	}
	more(dis);

}
