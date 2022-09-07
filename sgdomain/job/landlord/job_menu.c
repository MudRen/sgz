#include <mudlib.h>

inherit M_INPUT;

string refuse = "$N¶����м�ı��飬������Ĺ���Ч�ʽ����ˡ�\n";
string accept = "$N��˼��Ƭ�̣��ӱ�Ŭ���ĸ��������\n";
object *workers;

void get_input_from_main(string arg);
void quit_jobmenu();

void do_distribute(string *str);
void do_view();
void do_award(string *str);
void do_praise(string str);
void do_scold(string str);
void do_help();

void set_workers(object *obs)
{
	workers = obs;
}

void start_menu()
{
	modal_push( (: get_input_from_main :), "acdhqsv-->" );
	return;
}
void quit_jobmenu()
{
        modal_pop();
        destruct( this_object() );
        return;
}
void get_input_from_main(string arg)
{
	string *tmp;

	tmp = explode( arg, " " );

	if( !arg || arg == "" || arg == "h" || tmp[0] == "h" )do_help();
	else if( tmp[0] == "d"&&sizeof(tmp)>1 )do_distribute( tmp[1..] );
	else if( tmp[0] == "p"&&sizeof(tmp)>1 )do_praise( tmp[1] );
	else if( tmp[0] == "s"&&sizeof(tmp)>1 )do_scold( tmp[1] );
	else if( tmp[0] == "a"&&sizeof(tmp)>1 )do_award( tmp[1..] );
	else if( tmp[0] == "v" )do_view();
	else if( tmp[0] == "q" )quit_jobmenu();
	else {
		write("�Ƿ����\n");
        	return;
	};
	return;
}
void do_distribute(string *str)
{
	int who, job;
	object ob;

	mapping jobs = (["kanshu":"����","zhengdi":"����","guangai":"���"]);

	if( !this_body()->query_job("landlord", "start") ){
                printf("�㻹û���ټ�һ�������ء�\n");
                return;
        };
	printf("�������������Ĺ����У�\n1) �����������\n2) ���أ�����\n3) ��ȣ������\n");
	if( sizeof(str) < 2 || sscanf(str[0], "%d", who) != 1|| sscanf(str[1], "%d", job) != 1
		|| job < 1 || job > 3 || who < 1 || who > 3 ){
		printf("�������������������˵ʲô��\n");
		printf("d [No of worker] [No of job] \n");
		return;
	};
	ob = workers[who-1];
	if( ob->query("job")&&ob->query("job")!="none" ){
		printf("����æ���ء�\n");
		return;
	};
	ob->set("job", values(jobs)[job-1]);
	this_body()->targetted_action("$N������$Tȥ"+values(jobs)[job-1]+"��\n", ob);
	return;
}
void do_view()
{
	int i;
	string out;
	mapping att;
	object ob;

	if( !this_body()->query_job("landlord", "start") ){
		printf("�㻹û���ټ�һ�������ء�\n");
		return;
	};
	out = " ����      ����    ����  ����  ����  Ч��   �ɼ�   ����\n";
	out = out + "��������������������������������������������������������\n";
	for( i = 0; i < sizeof(workers); i++){
		ob = workers[i];
		if ( !ob->query_link() ){
			out = out + sprintf("%-10s%-10s%-6d%-6d%-6d%-6d%-7d%-10s\n",
				ob->query_id()[1], ob->query_id()[0],
				ob->query("int"), ob->query("exp"), ob->query("str"), 
				ob->query("eff"),
				ob->query("wrk"), 
				ob->query("job") );
		} else {
			att = ob->query_job("land_dp", "att");
			out = out + sprintf("%-10s%-10s%-6d%-6d%-6d%-6d%-7d%-10s\n",
				ob->query_id()[1], ob->query_id()[0],
				att["int"], att["exp"], att["str"],
				att["eff"], att["wrk"], att["job"] );
		};
	};
	out = out + "\n";
	write( out );
	return;
}
void do_help()
{
	printf("1) a ���������ʽ�����\n");
	printf("2) d ���乤�������¡�\n");
	printf("3) h ��ʾ�������ļ���\n");
	printf("4) p �������µĹ�����\n");
	printf("5) s �������°��²�����\n");
	printf("6) v �鿴����״����\n");
	return;
}
void do_award(string *str)
{
	int who, amount, hp;
	mapping att2;
	object ob;

	if( !this_body()->query_job("landlord", "start") ){
                printf("�㻹û���ټ�һ�������ء�\n");
                return;
        };	
	if( sizeof(str) < 2 || sscanf(str[0], "%d", who) != 1|| sscanf(str[1], "%d", amount) != 1
                || amount < 1 || who < 1 || who > sizeof(workers) ){
                printf("�������������������˵ʲô��\n");
                printf("a [No of worker] [amount of silver] \n");
                return;
        };
	hp = this_body()->query_cur_hp();
	if( hp < 70 ){
		printf("���Ѿ�̫���ˣ���������Ϣһ���ٸɰɡ�\n");
                return;
        };
	this_body()->set_cur_hp( hp - 50 - random(10) );
	if( amount*100 > this_body()->query_all_con_money() ){
		write("�ڿ�������������ô��Ǯ��\n");
	        return;
	};

        ob = workers[who-1];
	this_body()->set_all_con_money(this_body()->query_all_con_money()-amount*100);
	if ( ob->query_link() ) ob->set_all_con_money(ob->query_all_con_money()+amount*100);

	this_body()->targetted_action("$N��$T˵�����úøɣ�$S����"+chinese_number(amount)+"�����ӡ�\n", ob);
	if( random(this_body()->query_sk_level("sk_zhimou")) >= 
		random((50-amount<=0?0:50-amount)) ){
		ob->simple_action( accept ); 
		if( ob->query_link() ){
			att2 = ob->query_job("land_dp", "att");
			att2["eff"] = att2["eff"]+1+random(2);
			ob->set_job("land_dp", "att", att2);
		}
		else ob->set("eff", ob->query("eff")+1+random(2));
	} else {
		ob->simple_action( refuse );
	};
	return;
}
void do_praise(string str)
{
	int who, hp;
	mapping att2;
	object ob;

        if( !this_body()->query_job("landlord", "start") ){
                printf("�㻹û���ټ�һ�������ء�\n");
                return;
        };
	if( sscanf(str, "%d", who) != 1 || who < 1 || who > sizeof(workers) ){
		printf("�������������������˵ʲô��\n");
		printf("p [No of worker] \n");
		return;
	};
	hp = this_body()->query_cur_hp();
        if( hp < 70 ){
                printf("���Ѿ�̫���ˣ���������Ϣһ���ٸɰɡ�\n");
                return;
        };
	ob = workers[who-1];
        this_body()->set_cur_hp( hp - 50 - random(10) );	
	this_body()->targetted_action("$N�����ĳ���$T���ɵĺá�\n", ob);

	if( ob->query("eff") < 7 ){
		ob->targetted_action("$N�����Ŀ���$Tһ�ۡ�\n", this_body());
		ob->simple_action( refuse );
		if ( ob->query_link() ){
			att2 = ob->query_job("land_dp", "att");
			att2["eff"] = att2["eff"]-1;
			ob->set_job("land_dp", "att", att2);
		} else ob->set("eff", ob->query("eff")-1);
	} else if( random(this_body()->query_sk_level("sk_zhimou"))
		+ob->query("eff") > random(20) ){
		ob->simple_action( accept );
		if ( ob->query_link() ){
                        att2 = ob->query_job("land_dp", "att");
			att2["eff"] = att2["eff"]+1;
			ob->set_job("land_dp", "att", att2);
		} else ob->set("eff", ob->query("eff")+1);
	} else {
		ob->targetted_action("$N��������$T��\n", this_body()); 
	};
	return;

}
void do_scold(string str)
{
	int who, hp;
	mapping att2;
        object ob;

        if( !this_body()->query_job("landlord", "start") ){
                printf("�㻹û���ټ�һ�������ء�\n");
                return;
        };
        if( sscanf(str, "%d", who) != 1 || who < 1 || who > 3 ){
                printf("�������������������˵ʲô��\n");
                printf("p [No of worker] \n");
	        return;
        };
        hp = this_body()->query_cur_hp();
        if( hp < 70 ){
                printf("���Ѿ�̫���ˣ���������Ϣһ���ٸɰɡ�\n");
                return;
        };
        ob = workers[who-1];
        this_body()->set_cur_hp( hp - 50 - random(10) );
	this_body()->targetted_action("$N����$T�����ģ������㶼����ʲô��\n", ob);
	if( ob->query("eff") > 7 ){
		ob->targetted_action("$N�����Ŀ���$Tһ�ۡ�\n", this_body());
                ob->simple_action( refuse );
                if ( ob->query_link() ){
                        att2 = ob->query_job("land_dp", "att");
                        att2["eff"] = att2["eff"]-1;
			ob->set_job("land_dp", "att", att2);
		} else ob->set("eff", ob->query("eff")-1);
        } else if( random(this_body()->query_sk_level("sk_zhimou"))
                -ob->query("eff") > random(10) ){
		ob->simple_action( accept );
		if ( ob->query_link() ){
                        att2 = ob->query_job("land_dp", "att");
                        att2["eff"] = att2["eff"]+1;
                        ob->set_job("land_dp", "att", att2);
                } else ob->set("eff", ob->query("eff")+1);
        } else {
                ob->targetted_action("$N��������$T��\n", this_body());
	};
        return;

}
