#include <mudlib.h>

inherit M_INPUT;

void do_fire();
void do_water();
void do_rats();
void do_help();
void do_bugs();
void get_input_from_main(string arg);

void start_menu()
{
        modal_push( (: get_input_from_main :), "bfrwhq-->" );
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
	if( arg=="f" ) do_fire();
	else if( arg=="r" ) do_rats();
	else if( arg=="h" ) do_help();
	else if( arg=="q" ) quit_jobmenu();
	else if( arg=="w" ) do_water();
	else if( arg=="b" ) do_bugs();
	else write("�Ƿ����\n");
	return;
}
void do_fire()
{
	int hp;
	object ob;
	mapping job;

	ob = this_body();
	job= ob->query_job("do_farm", "");
	hp = ob->query_cur_hp();
	if( hp < 30 ){
		write("���Ѿ�̫���ˣ�������Ϣһ���ٸɰɡ�\n");
		return;
	}
	ob->set_cur_hp(hp-20-random(10));
	ob->start_busy(1+random(4), "����æ��ָ��ũ�����Ͷ��ء�");
	ob->award_exp(50+random(21), "sk_meili");
	if( job["job"]!="fire" ){
		ob->simple_action("��Ҷ�����ֵ��۹⿴��$N��\n");
		return;
	}
	ob->simple_action("$N��һ������Ҹ�������˵�žͷܲ���������Գ�ȥ��\n");
	ob->simple_action("��������$Nһӿ���ϣ���ѻ�����\n");
	if( !random(5) ){
		ob->set_job("do_farm", "job_d", job["job_d"]+1);
		write("��𷴶�Խ��Խ���ˡ�\n");
	} else if( !random(4) ){
		write("��ϧ�������ɲ��ɿ��ơ�\n");
	} else {
		ob->set_job("do_farm", "job_d", job["job_d"]-1);
		write("���ƽ������ܵ��˿��ơ�\n");
		if( (job["job_d"]-1)<= 0 ){
			ob->set_job("do_farm", "succ", job["succ"]+1);
			ob->set_job("do_farm", "job_d", 0);
			ob->set_job("do_farm", "job", "");
			write("���������������˼��£�Ϩ���ˡ�\n");
		}
	}
}
void do_water()
{
	int hp;
	object ob;
	mapping job;

	ob = this_body();
	job= ob->query_job("do_farm", "");
	hp = ob->query_cur_hp();
	if( hp < 30 ){
		write("���Ѿ�̫���ˣ�������Ϣһ���ٸɰɡ�\n");
		return;
	}
	ob->set_cur_hp(hp-20-random(10));
	ob->start_busy(1+random(4), "����æ��ָ��ũ�����Ͷ��ء�");
	ob->award_exp(10+random(51), "sk_meili");
	if( job["job"]!="water" ){
		ob->simple_action("��Ҷ�����ֵ��۹⿴��$N��\n");
		return;
	}
	ob->simple_action("$N��һ������Ҹ�������˵�žͷܲ���������ˮ��ȥ��\n");
	ob->simple_action("��������$Nһӿ���ϣ���Ѻ������ڶ�ס��\n");
	if( !random(5) ){
		ob->set_job("do_farm", "job_d", job["job_d"]+1);
		write("��ˮ����Խ��Խ���ˡ���\n");
	} else if( !random(4) ){
		write("ׯ�ڵ�������ȫ�ǻ�ˮ����\n");
	} else {
		ob->set_job("do_farm", "job_d", job["job_d"]-1);
		write("��ˮ�������ܵ��˿��ơ�\n");
		if( !(job["job_d"]-1) ){
			ob->set_job("do_farm", "succ", job["succ"]+1);
			ob->set_job("do_farm", "job_d", 0);
			ob->set_job("do_farm", "job", "");
			write("���ڣ����еĻ�ˮ���ž��ˡ�\n");
		}
	}
}
void do_rats()
{
	int hp;
	object ob;
	mapping job;

	ob = this_body();
	job= ob->query_job("do_farm", "");
	hp = ob->query_cur_hp();
	if( hp < 30 ){
		write("���Ѿ�̫���ˣ�������Ϣһ���ٸɰɡ�\n");
		return;
	}
	ob->set_cur_hp(hp-20-random(10));
	ob->start_busy(1+random(4), "����æ��ָ��ũ�����Ͷ��ء�");
	ob->award_exp(30+random(51), "sk_meili");
	if( job["job"]!="rats" ){
		ob->simple_action("��Ҷ�����ֵ��۹⿴��$N��\n");
		return;
	}
	ob->simple_action("$N��һ������Ҹ�������˵�žͷܲ����������Ⱥ��ȥ��\n");
	ob->simple_action("��������$Nһӿ���ϣ������������\n");
	if( !random(5) ){
		ob->set_job("do_farm", "job_d", job["job_d"]+1);
		write("����������ҧ�ı������ˡ���\n");
	} else if( !random(4) ){
		write("��ϧ�������ɵ�����Ű����\n");
	} else {
		ob->set_job("do_farm", "job_d", job["job_d"]-1);
		write("��Ⱥ�������ܵ��˿��ơ���\n");
		if( !(job["job_d"]-1) ){
			ob->set_job("do_farm", "succ", job["succ"]+1);
			ob->set_job("do_farm", "job_d", 0);
			ob->set_job("do_farm", "job", "");
			write("���ڣ�������Ⱥ���������ˡ�\n");
		}
	}

}
void do_bugs()
{
	int hp;
	object ob;
	mapping job;

	ob = this_body();
	job= ob->query_job("do_farm", "");
	hp = ob->query_cur_hp();
	if( hp < 30 ){
		write("���Ѿ�̫���ˣ�������Ϣһ���ٸɰɡ�\n");
		return;
	}
	ob->set_cur_hp(hp-20-random(10));
	ob->start_busy(1+random(4), "����æ��ָ��ũ�����Ͷ��ء�");
	ob->award_exp(10+random(51), "sk_meili");
	if( job["job"]!="bugs" ){
		ob->simple_action("��Ҷ�����ֵ��۹⿴��$N��\n");
		return;
	}
	ob->simple_action("$N��һ������Ҹ�������˵�žͷܲ���������Ⱥ�Ļȳ��ȥ��\n");
	ob->simple_action("��������$Nһӿ���ϣ���ѻȳ��������\n");
	if( !random(5) ){
		ob->set_job("do_farm", "job_d", job["job_d"]+1);
		write("�ȳ淴��Խ��Խ�ܼ��ˡ�\n");
	} else if( !random(4) ){
		write("��ϧ�ȳ����ɲ��ɿ��ơ�\n");
	} else {
		ob->set_job("do_farm", "job_d", job["job_d"]-1);
		write("�ȳ潥�����ܵ��˿��ơ�\n");
		if( !(job["job_d"]-1) ){
			ob->set_job("do_farm", "succ", job["succ"]+1);
			ob->set_job("do_farm", "job_d", 0);
			ob->set_job("do_farm", "job", "");
			write("���ڣ������ȳ�Ⱥ���������ˡ�\n");
		}
	}

}
void do_help()
{
	write("b-> bugs    ���\n");
	write("f-> fire    ���\n");
	write("w-> water   ��ˮ\n");
	write("r-> rats    ����\n");
	write("h-> help    ��ʾ������\n");
	write("q-> quit    �뿪������\n");
}

