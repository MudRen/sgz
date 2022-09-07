// wizlist.c
// Updated by tset 17 Sep 1998
// by fire on 17 June 1998
// this is used to list information of users
#include <mudlib.h>
#include <daemons.h>
#include <security.h>
inherit CMD;
inherit M_GLOB;

private void main()
{
    mixed list;
    int count;
    int i;
    string p_level,p_name,p_ip;
    int p_time,c_time,p_isonline;
    string disp="";
    string disp_tmp;
    array id_list=({});
    mixed us=([]);
    set_privilege(1);

    list = LAST_LOGIN_D->query_times();
    count = sizeof(list);

    c_time=time();
	
	for(i=0;i<count;++i)
	{
		us[list[i][1]]=([]);
		p_time=c_time-list[i][0];
		p_ip=list[i][2];
		p_name=FINGER_D->get_chinese_id(list[i][1]);
		p_level=adminp(list[i][1]) ? "a" : wizardp(list[i][1]) ? "w" : "p";
		p_isonline=objectp(find_user(list[i][1]));
		if(p_time>600)
			p_time=p_time-(p_time%60);
		if(p_time>36000)
			p_time=p_time-(p_time%3600);
		if(p_time>864000)
                        p_time=p_time-(p_time%86400);
		if(!wizardp(this_body()))
			p_ip="";
		us[list[i][1]]=({p_name,p_level,p_isonline,p_time,p_ip});
		id_list+=({list[i][1]});
	}

	id_list=filter_array(id_list,(:$(us)[$1][1]!="p":));
	id_list=sort_array(id_list,1);
		
    if(!wizardp(this_body()))
    	disp=sprintf("�ɣġ�    ������    ��֡������ߡ�ʱ�䡡\n");
    else
    	disp=sprintf("�ɣġ�    ������    ��֡������ߡ�ʱ�䡡�ɣ�\n");
    disp+=sprintf(power_str("��",35))+"\n";
    count=sizeof(id_list);
	for(i=0;i<count;i++)
	{
        disp+=sprintf("%-8s  %-8s  %4s  %8s%-16s %s\n",
			id_list[i],
			us[id_list[i]][0],
			(us[id_list[i]][1]=="p" ? "���": 
			us[id_list[i]][1]=="w" ? "��ʦ" : "����"),
			(us[id_list[i]][2] ? "�����ߣ�" : "�����ߣ�"),
			CHINESE_D->chinese_period(us[id_list[i]][3]),
			us[id_list[i]][4]);
	}
	disp+=sprintf("���鵽%d���û���\n",count);
	more(disp);
}
