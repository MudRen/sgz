// wizlist.c
// Updated by flee 31 July 1999
// Updated by tset 17 Sep 1998
// by fire on 17 June 1998
// this is used to list information of users

#include <mudlib.h>
#include <daemons.h>
#include <security.h>
#include <ansi.h>

inherit CMD;
inherit M_GLOB;

array id_list = ({});
int first = 0;
mixed us = ([]);

void create()
{
    mixed list;
    string p_level, p_name, p_ip;
    int p_time, c_time, p_isonline, i, count;

    set_privilege(1);

    list = LAST_LOGIN_D->query_times();
    c_time=time();
        
    for( i=0; i<sizeof(list); i++ ){
        p_level= adminp(list[i][1]) ? "a" : wizardp(list[i][1]) ? "w" : "p";
	if( p_level=="p" )continue;
	us[list[i][1]] = ([]);
        p_time = c_time - list[i][0];
        p_ip   = list[i][2];
	p_name = FINGER_D->get_chinese_id(list[i][1]);
	if( !p_name||!stringp(p_name) ) p_name="����";
        p_isonline = objectp( find_user(list[i][1]) );

        if( p_time>600 ) p_time=p_time-(p_time%60);
        if( p_time>36000 ) p_time=p_time-(p_time%3600);
	if( p_time>864000 ) p_time=p_time-(p_time%86400);
                
	if( p_level!="p" ){
	    us[list[i][1]] = ({p_name,p_level,p_isonline,p_time,p_ip});
	    id_list-=({list[i][1]}); 	
	    id_list+=({list[i][1]});
	}
    }
}
void do_upgrade_list()
{
    int p_time;
    array who;

    foreach(string ss in id_list){
	who = ({ });
	who = us[ss];
	who[2] = objectp( find_user(ss) );
	p_time = time()-LAST_LOGIN_D->query_last(ss)[0];
	if( p_time>600 ) p_time=p_time-(p_time%60);
        if( p_time>36000 ) p_time=p_time-(p_time%3600);
        if( p_time>864000 ) p_time=p_time-(p_time%86400);
	who[3] = p_time;
	us[ss] = who;
    }
}
private void main()
{
    int count, i, p_time, c_time, p_isonline;
    string p_level,p_name,p_ip;
    string disp="";
    string disp_tmp;
    

    if( first==0 ){
          create();
          first=1;
    } else do_upgrade_list();
                
        if(!wizardp(this_body()))
	disp = sprintf("�ɣġ�    ������    ��֡�  ״̬��ʱ�䡡\n");
    else
    disp = sprintf("�ɣġ�    ������    ��֡�  ״̬��ʱ�䡡		�ɣ�\n");
    disp+=sprintf(power_str("��",35))+"\n";
    count=sizeof(id_list);

    for(i=0;i<count;i++){
        disp+=sprintf("%s%-8s  %-8s  %4s  %8s%-16s %s\n",
			(us[id_list[i]][3]>2592000?RED:NOR),
                        id_list[i],
                        us[id_list[i]][0],
                        (us[id_list[i]][1]=="p" ? "���": 
                        us[id_list[i]][1]=="w" ? "��ʦ" : "����"),
                        (us[id_list[i]][2] ? "  "HIY"���ߣ�"NOR : "  ���ߣ�"),
                        CHINESE_D->chinese_period(us[id_list[i]][3]),
                        (wizardp(this_body())?us[id_list[i]][4]:"������������"));
    }
    disp+="����������������������������������������������������������������������\n";
    disp+=sprintf("���鵽%d���û���\n",count);
    more(disp);
}
