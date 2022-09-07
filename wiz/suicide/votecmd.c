// updated by tset on 12 Jan, 2000
#include <mudlib.h>
#include <daemons.h>
#include <log.h>
#define DO_CHAT(x) 	tell(users(),"%^H_WHITE%^��ͶƱ��"+x+"%^RESET%^\n")
#define MAX_CHAN_NUM 	4
inherit CMD;
private mapping votes;
void show_help();
void do_check(string str);
void do_close(string str);
void do_open(string str);
void do_time();
void create()
{
	::create();
    	no_redirection();
	set_privilege(1);
	votes = (["close":([ ]), "open":([ ]), ]);
	call_out("do_time", 20);
	return;
}
void main(string str)
{
	string id, what, who;
	id = this_body()->query_primary_id();
	if( !str||!stringp(str)||str=="" ){
		show_help();
		return;
	}
	if (str=="board")
	{
 new("/sgdomain/menu/votetool")->begin_reading();
	 return;
	}
	sscanf(str, "%s %s", what,who);
	if( !mapp(votes) ) votes = (["close":([ ]), "open":([ ]), ]);
	if (!what||!stringp(what)||what==""||what=="help") show_help();
	else if( !CHAR_D->char_exist(id) && !wizardp(id) )
		write("ֻ����Ϸ��ɫ����ȨͶƱ��\n");
	else if( what=="check" ) do_check(who);
	else if( what=="close" ) do_close(who);
	else if( what=="open"  ) do_open(who);
	else 
		write("�������ѡ��\n");
	return;
}
void do_check(string str)
{
	mapping tmp;
	object ob;
	string tt, ss;
	if( str=="open"){
		tmp = votes["open"];
		ss = "���ھ��ж�������ҿ�����̸Ƶ���ı����\n";
	} else if( str=="close" ){ 
		tmp = votes["close"];
		ss = "���ھ��ж�������ҹرս�̸Ƶ���ı����\n";
	} else {
		write("�������ѡ��\n");
		return;
	}
	foreach(string s in keys(tmp)){
		ob = find_body(s);
		if( !objectp(ob) ) tt = "ĳĳ("+s+")";
		else tt = ob->query_name()+"("+s+")";
		ss+=sprintf("%-20s����%s���飬%s��֧�֣�����%sƱͨ����\n",
			tt, tmp[s]["player"], chinese_number(sizeof(tmp[s]["who"])),
			chinese_number(tmp[s]["no"]+1-sizeof(tmp[s]["who"])),
			);
	}
	write(ss+"\n");
}
void do_time()
{
	mapping tmp, tmp1;
	remove_call_out("do_time");
	call_out("do_time", 20);
	if( !sizeof(votes) )return;
	tmp = votes["close"];
	if( sizeof(tmp) ){
		foreach(string ss in keys(tmp) ){
			tmp1 = tmp[ss];
			if( !mapp(tmp1)||tmp1["time"]+600<time() ){
				map_delete(tmp, ss);
				DO_CHAT("����̫�ò��ܴ��ͳһ���������"+(objectp(find_body(ss))?find_body(ss)->query_name():ss)+"("+ss+")ͶƱȡ���ˣ�");
			}
		}
		votes["close"] = tmp;
	}
	tmp = votes["open"];
        if( sizeof(tmp) ){
                foreach(string ss in keys(tmp) ){
                        tmp1 = tmp[ss];
                        if( !mapp(tmp1)||tmp1["time"]+600<time() ){
                                map_delete(tmp, ss);
                                DO_CHAT("����̫�ò��ܴ��ͳһ���������"+(objectp(find_body(ss))?find_body(ss)->query_name():ss)+"("+ss+")ͶƱȡ���ˣ�");
                        }
                }
                votes["open"] = tmp;
        }
}
void do_close(string str)
{
	object ob;
	mapping tmp;
	string *ids;
	if( !objectp(ob=find_body(str)) )
		write("û��\""+str+"\"�����ң�\n");
	else if( ob->chan_disabled() )
		write("���Ľ�̸Ƶ���Ѿ����ر��ˣ�\n");
	else if (wizardp(str))
		write("�޷��ر���ʦ�Ľ�̸Ƶ����\n");
	else {
		tmp = votes["close"];
		tmp = tmp[str];
		ids = users()->query_body()->query_primary_id();
                ids = filter_array(ids, (: CHAR_D->char_exist($1) :));
		if( !tmp||!mapp(tmp) ){
			if( sizeof(votes["close"])>MAX_CHAN_NUM ){
				write("�Ѿ���̫���ͶƱ���ڽ��У����Եȣ�\n");
				return;
			}
			tmp = (["time":time(), "who":({ }), "no": sizeof(ids)/2,"player":this_body()->query_primary_id() ]);
			tmp["who"]-=({ this_body()->query_primary_id() });
                        tmp["who"]+=({ this_body()->query_primary_id() });
			votes["close"][str] = tmp;
			DO_CHAT(this_body()->query_name()+"����ر�"+ob->query_name()+"�Ľ�̸Ƶ����\n");
			LOG_D->log(LOG_VOTE, 
				sprintf("%s attemp to close %s's channel at %s\n",
				this_body()->query_primary_id(), str, ctime(time())));
		} else if( member_array(this_body()->query_primary_id(), tmp["who"])!=-1 ) {
			write("���Ѿ�Ͷ��һƱ�ˣ�\n");
		} else {
			tmp["who"]-=({ this_body()->query_primary_id() });
			tmp["who"]+=({ this_body()->query_primary_id() });
			votes["close"][str] = tmp;
			if( sizeof(tmp["who"])>tmp["no"] ){
				DO_CHAT(this_body()->query_name()+"ͶƱ֧�ֹر�"+ob->query_name()+"�Ľ�̸Ƶ��������ͨ���ˣ�");
				ob->disable_chan();
				tmp = votes["close"];
				map_delete(tmp, str);
				votes["close"] = tmp;
			} else {
				DO_CHAT(this_body()->query_name()+"ͶƱ֧�ֹر�"+ob->query_name()+"�Ľ�̸Ƶ��������"+chinese_number(tmp["no"]+1-sizeof(tmp["who"]))+"Ʊͨ����");
			}
		}
	}
}
void do_open(string str)
{
	object ob;
        mapping tmp;
        string *ids;
        if( !objectp(ob=find_body(str)) )
                write("û��\""+str+"\"�����ң�\n");
        else if( !ob->chan_disabled() )
                write("���Ľ�̸Ƶ����û�б��رգ�\n");
        else {
                tmp = votes["open"];
                tmp = tmp[str];
		ids = users()->query_body()->query_primary_id();
                ids = filter_array(ids, (: CHAR_D->char_exist($1) :));
                if( !tmp||!mapp(tmp) ){
			if( sizeof(votes["open"])>MAX_CHAN_NUM ){
                                write("�Ѿ���̫���ͶƱ���ڽ��У����Եȣ�\n");
                                return;
                        }
			tmp = (["time":time(), "who":({ }), "no": sizeof(ids)/2,"player":this_body()->query_primary_id() ]);
                        tmp["who"]-=({ this_body()->query_primary_id() });
                        tmp["who"]+=({ this_body()->query_primary_id() });
                        votes["open"][str] = tmp;
                        DO_CHAT(this_body()->query_name()+"�����"+ob->query_name()+"�Ľ�̸Ƶ����\n");
                } else if( member_array(this_body()->query_primary_id(), tmp["who"])!=-1 ) {
                        write("���Ѿ�Ͷ��һƱ�ˣ�\n");
                } else {
                        tmp["who"]-=({ this_body()->query_primary_id() });
                        tmp["who"]+=({ this_body()->query_primary_id() });
                        votes["open"][str] = tmp;
                        if( sizeof(tmp["who"])>tmp["no"] ){
                                DO_CHAT(this_body()->query_name()+"ͶƱ֧�ִ�"+ob->query_name()+"�Ľ�̸Ƶ��������ͨ���ˣ�");
                                ob->enable_chan();
				tmp = votes["open"];
                                map_delete(tmp, str);
                                votes["open"] = tmp;
                        } else {
                                DO_CHAT(this_body()->query_name()+"ͶƱ֧�ִ�"+ob->query_name()+"�Ľ�̸Ƶ��������"+chinese_number(tmp["no"]+1-sizeof(tmp["who"]))+"Ʊͨ����");
                        }
                }
        }
}
void show_help()
{
        string help = @HELP
vote close xxx          --> ͶƱͬ��ر�ĳ����ҵĽ�̸Ƶ����
vote open  xxx          --> ͶƱͬ�⿪��ĳ����ҵĽ�̸Ƶ����
vote check close|open   --> �鿴��ǰ����(�ر�)����Ľ��̡�
vote board              --> �μ�ͶƱ��ı��
HELP;
        write(help);
}
