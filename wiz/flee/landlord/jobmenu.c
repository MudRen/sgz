#include <ansi.h>
#include <mudlib.h>

inherit M_INPUT;

private string refuse = "¶����м�ı��飬������Ĺ���Ч�ʽ����ˡ�\n";
private string accept = "��˼��Ƭ�̣��ӱ�Ŭ���ĸ��������\n";
private mapping workers = ([ ]);

void get_input_from_main(string arg);
void quit_jobmenu();
int check_busy();

void create_worker();
void do_list_worker(mapping ww);

void do_distribute(mixed str);
void do_award(mixed str);
void do_praise(mixed str);
void do_scold(mixed str);
void do_list();
void do_view();
void do_help();

void start_menu()
{
        modal_push( (: get_input_from_main :), "ad"HIY"h"NOR"lqpsv-->" );
        return;
}
void quit_jobmenu()
{
        modal_pop();
        destruct( this_object() );
        return;
}
void get_input_from_main(mixed arg)
{
	string *tmp;
		
	tmp = explode(arg, " ");
	if( !tmp||!sizeof(tmp)||!arrayp(tmp) ){
		write("�Ƿ����\n");
		return;
	} else if( tmp[0]=="a"&&sizeof(tmp)>1 ) do_award( tmp[1..] );
	else if( tmp[0]=="d"&&sizeof(tmp)>1 )   do_distribute( tmp[1..] ); 
	else if( tmp[0]=="p"&&sizeof(tmp)>1 ) 	do_praise( tmp[1..] );
	else if( tmp[0]=="s"&&sizeof(tmp)>1 ) 	do_scold( tmp[1..] );
	else if( tmp[0]=="l" ) do_list();
	else if( tmp[0]=="v" ) do_view();
	else if( tmp[0]=="q" ) quit_jobmenu();
	else do_help();

	return;
}
void do_help()
{
	printf("1) a ���������ʽ�����\n");
        printf("2) d ���乤�������¡�\n");
        printf("3) h ��ʾ�������ļ���\n");
	printf("4) l �г��ɹ�ѡ���ũ��\n");
        printf("5) p �������µĹ�����\n");
	printf("6) q �뿪���˵���\n");
        printf("7) s �������°��²�����\n");
        printf("8) v �鿴����״����\n");
        return;
}
void create_worker()
{
	int i;
	string c_name, id;

	string *first = ({ "��","Ǯ","��","��","��","��","֣","��","��","��","��","��" });
	string *words = ({ "˳","��","��","��","��","��","��","��","־","��",
        	"Т","��","��","��","��","��","��","ʢ","ʤ","��","��","��","ͬ","��",
        	"��","��","��","¡","��","��","��","��","��" });
	string *rnd_id = ({"ra","ma","ta","pu","gu","du","so","po","lo","phi","tri"});
	string *rnd_id_tail = ({"ng","gh","ss","h","le","d","ck","m","tte"});
	
	workers = ([ ]);
	for( i=0; i<4; i++){
		c_name = first[random(sizeof(first))]+words[random(sizeof(words))];
		if( random(6)>2 ) c_name+=words[random(sizeof(words))];
		id = rnd_id[random(sizeof(rnd_id))];
        	if( random(10) > 4 ) id+=rnd_id[random(sizeof(rnd_id))];
        	id+=rnd_id_tail[random(sizeof(rnd_id_tail))];
		workers[id] = (["name":c_name,"str":10+random(10),"tire":random(5),
			"int":10+random(10),"exp":10+random(10),"eff":5+random(5)]);
	}
}
void do_distribute(mixed str)
{
	string who, what, *jobs;
	mapping oldw, now;

	jobs = ({ "����", "����", "���", });
	oldw = this_body()->query_job("landlord","worker");

	if( !check_busy() )return;
	write("���ڵĹ����У����������أ���ȡ�\n");
	if( sizeof(oldw)>=3 ){
		write("���Ѿ�ָ�����㹻��ũ���ˡ�\n");
	} else if( !sizeof(workers) ){
		write("�����г��ɹ�ѡ���ũ��\n");
	} else if( !arrayp(str)||sizeof(str)!=2||!stringp(who=str[0])||!stringp(what=str[1]) ){
		write("�����ʽ���ԡ�\n");
		write("��ʽ��d ũ���Ӣ���� ������������\n");
	} else if( member_array(who, keys(workers))==-1 ){
		write("û�����ũ��\n");
	} else if( member_array(what, jobs)==-1 ){
		write("\nû�����ֹ�����");
	} else {
		if( !oldw||!mapp(oldw)||!sizeof(oldw) )oldw = ([ ]);
		foreach(string ss in keys(oldw)){
			if( oldw[ss]["job"]==what ){
				write(oldw[ss]["name"]+"���������๤����\n");
				return;
			}
		}
		now = workers[who];
		map_delete(workers, who);
		now["job"] = what;
		oldw[who] = now;
		this_body()->set_job("landlord", "worker", oldw);
		this_body()->simple_action("$N������ũ��"+now["name"]+"ȥ����"+now["job"]+"������\n");
	}
	return;
}
void do_award(mixed str)
{
	string who, what;
	mapping oldw, one;

	oldw = this_body()->query_job("landlord", "worker");

	if( !check_busy() )return;
	if( !mapp(oldw)||!sizeof(oldw) ){
		write("��������û��һ��ũ��\n");
	} else if( !arrayp(str)||sizeof(str)!=2 ){
		write("�����ʽ���ԡ�\n");
                write("��ʽ��a ũ���Ӣ���� ����������\n");
	} else if( !stringp(who=str[0])||member_array(who, keys(oldw))==-1 ){
		write("��û��һ���С�"+who+"����ũ��\n");
	} else if( !stringp(what=str[1])||to_int(what)<=0 ){
		write("��Ҫ�͸��������������ء�\n");
	} else if( to_int(what)>this_body()->query_all_con_money() ){
                write("�ڿ�������������ô��Ǯ��\n");
                return;
        } else {
		this_body()->set_all_con_money(this_body()->query_all_con_money()-to_int(what)*100);
		one = oldw[who];
		this_body()->simple_action("$N��"+one["name"]+"˵�����úøɣ�$S����"+chinese_number(to_int(what))+"�����ӡ�\n");
		if( random(this_body()->query_sk_level("sk_zhimou"))>=random((50-to_int(what)<=0?0:50-to_int(what))) ){
			write(one["name"]+accept);
			one["tire"] = 0;
			one["eff"]+=4+random(3);
			if( one["eff"]>10 ) one["eff"]=10;
		} else {
			write(one["name"]+refuse);
                        one["tire"]-=4+random(2);
			if( one["tire"]<0 ) one["tire"] = 1;
		}
		oldw[who] = one;
		this_body()->set_job("landlord", "worker", oldw);
	}
	return;
}
void do_praise(mixed str)
{
	string who;
        mapping oldw, one;

        oldw = this_body()->query_job("landlord", "worker");

	if( !check_busy() )return;
        if( !mapp(oldw)||!sizeof(oldw) ){
                write("��������û��һ��ũ��\n");
        } else if( !arrayp(str)||sizeof(str)!=1 ){
                write("�����ʽ���ԡ�\n");
                write("��ʽ��p ũ���Ӣ����\n");
        } else if( !stringp(who=str[0])||member_array(who, keys(oldw))==-1 ){
                write("��û��һ���С�"+who+"����ũ��\n");
	} else {
		one = oldw[who];
		this_body()->simple_action("$N�����ĳ���"+one["name"]+"���ɵĺá�\n");
		if( one["eff"]<7 ){
			write( one["name"]+"�����Ŀ�����һ�ۡ�\n");
			write( one["name"]+refuse );
			one["eff"]-=2+random(2);
			if( one["eff"]<=0 ) one["eff"]=0;
		} else if( random(this_body()->query_sk_level("sk_zhimou"))+one["eff"] > random(20) ){
                	write( one["name"]+accept );
			one["eff"]+=2+random(2);
			if( one["eff"]>10 ) one["eff"]=10;
		} else write(one["name"]+"����������\n");
		oldw[who] = one;
		this_body()->set_job("landlord", "worker", oldw);
	};

	return;
}
void do_scold(mixed str)
{
        string who;
        mapping oldw, one;

        oldw = this_body()->query_job("landlord", "worker");

	if( !check_busy() )return;
        if( !mapp(oldw)||!sizeof(oldw) ){
                write("��������û��һ��ũ��\n");
        } else if( !arrayp(str)||sizeof(str)!=1 ){
                write("�����ʽ���ԡ�\n");
                write("��ʽ��s ũ���Ӣ����\n");
        } else if( !stringp(who=str[0])||member_array(who, keys(oldw))==-1 ){
                write("��û��һ���С�"+who+"����ũ��\n");
        } else {
                one = oldw[who];
                this_body()->simple_action("$N����"+one["name"]+"�����ģ������㶼����ʲô��\n");
		if( one["eff"]>7 ){
                        write( one["name"]+"�����Ŀ�����һ�ۡ�\n");
                        write( one["name"]+refuse );
                        one["eff"]-=2+random(2);
                        if( one["eff"]<=0 ) one["eff"]=0;
                } else if( random(this_body()->query_sk_level("sk_zhimou"))-one["eff"]>random(10) ){
                        write( one["name"]+accept );
                        one["eff"]+=2+random(2);
                        if( one["eff"]>10 ) one["eff"]=10;
                } else write(one["name"]+"����������\n");
                oldw[who] = one;
                this_body()->set_job("landlord", "worker", oldw);
	};

	return;
}
void do_list()
{
	mapping oldw;

        oldw = this_body()->query_job("landlord", "worker");
	if( sizeof(oldw)>=3 ){
		write("���Ѿ����㹻��ũ���ˡ�\n");
		return;
	};
	create_worker();
	do_list_worker( workers );

	return;
}
void do_view()
{
	mapping oldw;

	oldw = this_body()->query_job("landlord", "worker");

        if( !mapp(oldw)||!sizeof(oldw) )
                write("��������û��һ��ũ��\n");
	else do_list_worker( oldw );

	return;
}
void do_list_worker(mapping ww)
{
	string out;
	mapping one;

	out = " ����      ����    ����  ����  ����  Ч��  ƣ��    ����\n";
	out+="��������������������������������������������������������\n";
	foreach(string ss in keys(ww) ){
		one = ww[ss];
		out+=sprintf("%-10s%-10s%-6d%-6d%-6d%-6d%-7d%-8s\n",
			one["name"],ss,one["int"],one["exp"],one["str"],one["eff"],one["tire"],(one["job"]?one["job"]:"----"));
	};
	out+="��������������������������������������������������������\n";
	out+="�ܹ�������"+chinese_number(this_body()->query_job("landlord","")["done"])+"��\n";
	write(out);

	return;
}
int check_busy()
{
	int hp;

	hp = this_body()->query_cur_hp();
	if( hp< 20 ){
		write("���Ѿ�̫���ˣ�������Ϣһ���ٸɰɡ�\n");
		return 0;
	}
	if( this_body()->query_busy(1)!="��æ��"){
		write("����æ���ء�\n"); 
		return 0;
	}
	this_body()->set_cur_hp(hp-10-random(10));
	this_body()->start_busy(3+random(2),"����æ���ء�");
	return 1;
}
