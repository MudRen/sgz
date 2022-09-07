//qb.c this is used to give qb command by fire on Jan 1999

#include <menu.h>
#include <mudlib.h>
#include <verb.h>
#include <ppl.h>
inherit __DIR__+"free_menu";
void do_addcook(string str) {
	string f_name;
	object ob,o_h;
	array cook;
	int val;
	if(OBJ_D->get_obj(str,"type")!="food") {
		write("û��"+str+"����ʳ�\n");
		return; 
	}
	f_name=OBJ_D->get_obj(str,"name");
	ob=present(str,master);
	if(!objectp(ob)) {
		write("������û��"+f_name+"��\n");
		return;
	}
	o_h=SGHOME(p_id);
	cook=o_h->get_npc(n_id,"cook");
	if(!sizeof(cook)) cook=({"wotou"});
	if(member_array(str,cook)!=-1) {
		write("��ĳ�ʦ�Ѿ�����"+f_name+"�ˡ�\n");
		return;
	}
	if(sizeof(cook)>10) {
		write("��ĳ�ʦ���չ��ߣ�����Ҫ��ѧ�»����ˡ�\n");
		return;
	}
	modal_pop();
	poped=0;
	
	master->targetted_action(
		"$N��$T����$m������������ܲ���ѧ����ѽ��˵�ŵݸ�$t$O��\n",slave,ob);

	ob->move(slave);
		
        DELAY_D->delay_targetted_action(slave,master,
		"$N��ϸ�о���"+f_name+"��\n",2);
	val=OBJ_D->get_obj(str,"value");
	val=val*10+20000;
        DELAY_D->delay_targetted_action(slave,master,
		"$N��$T����û���⣬"+f_name+
		"Ӧ�ò�������$R�ܲ��ܸ���"+CHINESE_D->chinese_value(val)+
		"���ҳ�ȥ��Щԭ�������俴��\n",4);
	if(MONEY_D->sub_poket_money(master,val)==1) {
	        DELAY_D->delay_targetted_action(slave,master,
			"$T��$N�����ã��ã�����"+CHINESE_D->chinese_value(val)
			+"�������ȥ׼���ɡ�\n",5);
		cook+=({str});
		o_h->set_npc(n_id,"cook",cook);

	}
	else 
	        DELAY_D->delay_targetted_action(slave,master,
			"$T��$Nһ��üͷ����Ҫ����ô��Ǯ�����»�ͷ��˵�ɡ���\n",5);
	destruct(ob);
	call_out("quit_menu_application",6);
}

void do_reqfood(string str) {
	string f_name;
	object ob,o_h;
	array cook;
	int val;
	
	if(OBJ_D->get_obj(str,"type")!="food") {
		write("û��"+str+"����ʳ�\n");
		return; 
	}

	f_name=OBJ_D->get_obj(str,"name");

	o_h=SGHOME(p_id);
	cook=o_h->get_npc(n_id,"cook");
	if(!sizeof(cook)) cook=({"wotou"});
	if(member_array(str,cook)==-1) {
		write("��ĳ�ʦ��������"+f_name+"�ˡ�\n");
		return;
	}

	modal_pop();
	poped=0;
	
	master->targetted_action(
		"$N��$T����$m����˵���"+f_name+"���ò�����һ"+
		OBJ_D->get_obj(str,"unit")+"��$S������\n",slave);

	val=OBJ_D->get_obj(str,"value");
	val=val/4;

	if(MONEY_D->sub_all_money(master,val)==1) {
	        DELAY_D->delay_targetted_action(slave,master,
			"$N��$T�����ã��ã���΢��һ�ȣ���������á�\n",2);
		ob=OBJ_D->clone_obj(str);
		ob->move(master);

	        DELAY_D->delay_targetted_action(slave,master,
			"$N��$T�������ˣ�˵�Ű�һ"+OBJ_D->get_obj(str,"unit")+
			"�ո㶨��"+f_name+"�ݵ�$n1p���\n",5);

	}
	else 
	        DELAY_D->delay_targetted_action(slave,master,
			"$N��$Tһ��üͷ�������������׵�Ǯ��û���ˣ�������"+f_name+"��\n",2);
	call_out("quit_menu_application",6);

}



void do_askcook() {

	object o_h;
	array cook;
	string msg;
	o_h=SGHOME(p_id);

	cook=o_h->get_npc(n_id,"cook");
	if(!sizeof(cook)) cook=({"wotou"});

	modal_pop();
	poped=0;

	master->targetted_action(
		"$N��$T����$m�������Щʲô�óԵ�ѽ��\n",slave);

	msg="$N��$T�Ϲ�������$R��$s�������¶�����\n";
	foreach(string s in cook) {
		msg+=OBJ_D->get_obj(s,"name")+"("+s+")\n";
	}


        DELAY_D->delay_targetted_action(slave,master,
		msg,3);
	if(sizeof(cook)<3)
		msg="$Nһ���ߵ�$T��ƨ���ϣ����ģ��Ż�����ô�㶫�������ҹ���ȥ��\n";
	else if(sizeof(cook)<7)
		msg="$N��$T���ͷ����������ҪŬ����\n";
	else
		msg="$n���������ر���$t˵�������$n1r���г�Ϣ�ۣ�$n0a�������ε�����һ���ţ�\n";

        DELAY_D->delay_targetted_action(master,slave,
		msg,5);

	call_out("quit_menu_application",6);
}


void create( )
{
    set_privilege(1);
    toplevel = new_menu("\n��Դ��ʦ�´�ָ�");
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

    add_menu_item(toplevel, new_menu_item("�ı�ID",	(: get_input_then_call,
		(: do_changeid :) ,"��Ϊ��ID��" :) ,"9"));

    add_menu_item(toplevel, new_menu_item("��ְ", 	(: get_input_then_call,
	(: do_demote :) ,"ȷ�ϳ�ְ��(y/n)��" :) ,"a"));

    add_menu_item(toplevel, new_menu_item("ѯ������",	(: do_askcook :) ,"b"));
    add_menu_item(toplevel, new_menu_item("��������",	(: get_input_then_call,
		(: do_addcook :) ,"ѧ���Ķ�����" :) ,"c"));

    add_menu_item(toplevel, new_menu_item("��Ե�",	(: get_input_then_call,
		(: do_reqfood :) ,"��Щʲô��" :) ,"d"));

    add_menu_item(toplevel, quit_item);
    add_menu_item(toplevel, space);
    set_menu_prompt (toplevel, "����ָ��[12345679q]: ");
}