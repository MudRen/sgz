//qb.c this is used to give qb command by fire on Jan 1999

#include <menu.h>
#include <mudlib.h>
#include <verb.h>
#include <ppl.h>
inherit __DIR__+"free_menu";


void saltobody(string val) {
	int num,v;
	num=to_int(val);
	if(num<=0) return;
	if(num>1000) return;
	v=num*10000;
	if(MONEY_D->sub_salary_money(master,v)==-1) {
		write("���û����ô��Ǯ��\n");
		return;
	}
	MONEY_D->add_poket_money(master,v);

	poped=0;
	modal_pop();
	call_out("quit_menu_application",5);

	master->targetted_action("$N��$T������$S�ӿ�����"+chinese_number(num)+
		"���ƽ�\n",slave);
	DELAY_D->delay_targetted_action(slave,master,"$N��$T����û���⡣\n",2);
	DELAY_D->delay_targetted_action(master,slave,"$N����ص��ͷ��\n",4);
	
}


void bodytosal(string val) {
	int num,v;
	num=to_int(val);
	if(num<=0) return;
	if(num>1000) return;
	v=num*10000;
	if(MONEY_D->sub_poket_money(master,v)==-1) {
		write("������û����ô��Ǯ��\n");
		return;
	}
	MONEY_D->add_salary_money(master,v);

	poped=0;
	modal_pop();
	call_out("quit_menu_application",5);

	master->targetted_action("$N�ͳ�"+chinese_number(num)+
		"�����ӵָ�$T��������ЩǮ�浽���\n",slave);
	DELAY_D->delay_targetted_action(slave,master,"$N��$T����û���⡣\n",2);
	DELAY_D->delay_targetted_action(master,slave,"$N����ص��ͷ��\n",4);
	
}


void banktosal(string val) {
	int num,v;
	num=to_int(val);
	if(num<=0) return;
	if(num>1000) return;
	v=num*10000;
	if(MONEY_D->sub_bank_money(master,v)==-1) {
		write("Ǯׯ��û����ô��Ǯ��\n");
		return;
	}
	MONEY_D->add_salary_money(master,v);

	poped=0;
	modal_pop();
	call_out("quit_menu_application",5);

	master->targetted_action("$N��$T����ȥ��Ǯׯ���"+chinese_number(num)+
		"������ת�����\n",slave);
	DELAY_D->delay_targetted_action(slave,master,"$N��$T����û���⡣\n",2);
	DELAY_D->delay_targetted_action(master,slave,"$N����ص��ͷ��\n",4);
	
}


void saltobank(string val) {
	int num,v;
	num=to_int(val);
	if(num<=0) return;
	if(num>1000) return;
	v=num*10000;

        if(MONEY_D->get_bank_money(master)>50000000) {
                write("Ǯׯ���ܴ����Ǯ�ˡ�\n");
                return;
        }
	if(MONEY_D->sub_salary_money(master,v)==-1) {
		write("����û����ô��Ǯ��\n");
		return;
	}


	MONEY_D->add_bank_money(master,v);

	poped=0;
	modal_pop();
	call_out("quit_menu_application",5);

	master->targetted_action("$N��$T����ȥ�ѿ����"+chinese_number(num)+
		"������ת��Ǯׯ�����ϡ�\n",slave);
	DELAY_D->delay_targetted_action(slave,master,"$N��$T����û���⡣\n",2);
	DELAY_D->delay_targetted_action(master,slave,"$N����ص��ͷ��\n",4);
	
}
void create( )
{
    set_privilege(1);
    toplevel = new_menu("\n����ʷ������´�ָ�");
    quit_item = new_menu_item("����", (:quit_old_place:), "q");
    seperator = new_seperator
    ("----------------------------------------------------------------------");
    space = new_seperator
    ("                                                                      ");

    add_menu_item(toplevel, seperator);
    add_menu_item(toplevel, space);
    add_menu_item(toplevel, new_menu_item("�ڴ˹���",	(: do_stayhere :) ,"1"));

    add_menu_item(toplevel, new_menu_item("�ʹ���Ʒ",	(: get_input_then_call,
		(: do_praise :) ,"�ʹͺ��" :) ,"2"));

    add_menu_item(toplevel, new_menu_item("ѯ�����",	(: do_getinfo :) ,"3"));

    add_menu_item(toplevel, new_menu_item("���->Ǯׯ",	(: get_input_then_call,
		(: saltobank :) ,"Ǯ��(��1-1000)��" :) ,"4"));

    add_menu_item(toplevel, new_menu_item("Ǯׯ->���",	(: get_input_then_call,
		(: banktosal :) ,"Ǯ��(��1-1000)��" :) ,"5"));

    add_menu_item(toplevel, new_menu_item("����->���",	(: get_input_then_call,
		(: bodytosal :) ,"Ǯ��(��1-1000)��" :) ,"6"));
    add_menu_item(toplevel, new_menu_item("���->����",	(: get_input_then_call,
		(: saltobody :) ,"Ǯ��(��1-1000)��" :) ,"7"));


    add_menu_item(toplevel, new_menu_item("�ı�ID",	(: get_input_then_call,
		(: do_changeid :) ,"��Ϊ��ID��" :) ,"9"));

    add_menu_item(toplevel, new_menu_item("��ְ", 	(: get_input_then_call,
	(: do_demote :) ,"ȷ�ϳ�ְ��(y/n)��" :) ,"a"));

    add_menu_item(toplevel, quit_item);
    add_menu_item(toplevel, space);
    set_menu_prompt (toplevel, "����ָ��[12345679q]: ");
}

void start_menu(object m,object s)
{
	master=m;
	slave=s;	
	p_id=master->query_primary_id();
	n_id=slave->get_id();

	poped=1;

	init_menu_application( toplevel );
	call_out("quit_menu_application",50);

}
