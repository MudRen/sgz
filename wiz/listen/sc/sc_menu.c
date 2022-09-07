//qb.c this is used to give qb command by fire on Jan 1999

#include <menu.h>
#include <mudlib.h>
#include <verb.h>
#include <ppl.h>
inherit "/sgdomain/home/npc/free_menu";

void do_getmeat()
{
	object o_h,o;
	mixed ret;
	o=slave;
	o_h=SGHOME(p_id);
	ret=o_h->has_chufang();

	modal_pop();
	poped=0;

	master->targetted_action("$N��$T����$S���ˣ��ؼ�ȥ��Щ�Ե�����\n",o);

        DELAY_D->delay_simple_action(o,"$N����������\n",1);

	if(!stringp(ret)&&(MONEY_D->sub_all_money(master,500)==1)) {
		master->add_food(500);
	        DELAY_D->delay_targetted_action(o,master,
			"$Nת�����һ�������$T���ϡ�\n",2);
		DELAY_D->delay_simple_action(master,
			"$Nץ����ֻ���ڱ�����ˡ�\n",3);
		DELAY_D->delay_targetted_action(master,o,
			"$N�ѿ��뻹��$T��\n",4);
	}
	else {
		if(!stringp(ret))
			ret="ûǮ������";
	        DELAY_D->delay_targetted_action(o,master,
			"$N��$T��������$R������"+ret+"������û�гԵġ�\n",2);
		DELAY_D->delay_simple_action(master,
			"$N�����������������ֵ�Ҫ���ˡ�\n",3);
	        DELAY_D->delay_simple_action(o,"$N����һ��͵͵��Ц�š�\n",4);
		DELAY_D->delay_targetted_action(master,slave,
			"$Nһ���ߵ�$T��ƨ���ϣ����ʵ�$r�����ҹ���ȥ��\n",5);

	}
	call_out("quit_menu_application",6);
}

void do_gethorse()
{
	object env=environment(master),o_h;
	object o=slave;
	mixed m_wear;
	m_wear=CHAR_D->get_char(p_id,"wear");
	if(!m_wear) m_wear=([]);
	
	modal_pop();
	poped=0;
	master->targetted_action("$N��$T����$SҪԶ�У���Щ������\n",o);
	if(!m_wear["horse"]) {
        	DELAY_D->delay_targetted_action(o,master,
				"$N��$TС������$R����Ǻ�Ϳ�ˣ�����û�����ء�\n",1);
		DELAY_D->delay_simple_action(master,"$Nһ��ãȻ��\n",2);
		call_out("quit_menu_application",3);
		return;
	}
	if(env->is_troop()){
	        DELAY_D->delay_targetted_action(o,master,
			"$N��$TС�������ھ��У�$R�ĳ�С�Ŀɲ��ҿ�������\n",1);
		DELAY_D->delay_simple_action(master,"$Nһ��ãȻ��\n",2);
		call_out("quit_menu_application",3);
		return;
	}

	if(env->is_horse()){
	        DELAY_D->delay_targetted_action(o,master,
			"$N��$TС������$R����Ǻ�Ϳ�ˣ����Ѿ����ڳ����ˡ�\n",1);
		DELAY_D->delay_simple_action(this_body(),"$Nһ��ãȻ��\n",2);
		call_out("quit_menu_application",3);
		return;
	}
	o_h=OBJ_D->find_my_obj(p_id,m_wear["horse"]);
	if(!objectp(o_h))
		o_h=OBJ_D->clone_obj(m_wear["horse"]);
	else {
		object *rs,h_env;
		h_env=environment(o_h);
		if(objectp(h_env)&&(h_env!=env)) {
			tell_environment(o_h,o_h->short()+"�����Զ���ʻģʽ�������˿�ȥ��\n");
			rs=o_h->get_riders();
			if(sizeof(rs)) {
				foreach(object r in rs) {
					r->move(h_env);
					r->simple_action("$N⧲����������������⡣\n");
				}
			}
		}
	}
	o_h->set_owner(p_id);
	o_h->move(env);
        DELAY_D->delay_simple_action(o,"$N����������\n",1);
        DELAY_D->delay_targetted_action(o,master,"$Nת������$n1p��"+o_h->short()+
		"���ѳ��Ÿ�$T�򿪡�\n",2);
	DELAY_D->delay_simple_action(master,"$N����ص��˵�ͷ��\n",3);
	call_out("quit_menu_application",5);
}

void do_getwine()
{
	poped=0;
	modal_pop();

	if(MONEY_D->sub_poket_money(master,300)==1) {
		master->add_drink(500);
		master->targetted_action(
			"$N��$T�������㼸�����ӣ�$S�ڿʣ���ȥ��Щ������\n",slave);
	
	        DELAY_D->delay_simple_action(slave,"$N����������\n",1);
	        DELAY_D->delay_targetted_action(slave,master,
			"$Nת�����һ��Ƹ�$T���ϡ�\n",2);
		DELAY_D->delay_simple_action(master,
			"$N����ơ���ཡ�һ�����ȸ��ˡ�\n",3);
		DELAY_D->delay_targetted_action(master,slave,
			"$N�ѿվ��뻹��$T��\n",4);
	}
	else {
		master->targetted_action(
			"$N��$T����$R�ܲ��ܵ��������Ҫ��ˮ�ȡ�\n",slave);
	
	        DELAY_D->delay_targetted_action(slave,master,
			"$N��$T��������Ҫ��ȥ���ҿɲ��ɣ�ҪҪ���Լ�ȥ��\n",1);

		DELAY_D->delay_targetted_action(master,slave,
			"$Nһ���ߵ�$T��ƨ���ϣ�û�õ�$r�����ҹ���ȥ��\n",2);
		
	        DELAY_D->delay_simple_action(slave,"$N����������\n",3);

	}
    	call_out("quit_menu_application",5);

}


void do_call(string str)
{
    object o_h,o_k;
    string *ids,id;
    o_h=SGHOME(p_id);
	ids=o_h->check_npc("pre_id",str);
    if(!sizeof(ids))  {
	write("���û��"+str+"��\n");
	return;
    }
	poped=0;
    	modal_pop();
	
	id=ids[0];
	o_k=o_h->load_npc(id);

	o_k->move(master->query_room());
    call_out("quit_menu_application",5);

    master->targetted_action("$N��$T����$R����һ�£���$o�й�����\n",slave,o_k);

    DELAY_D->delay_simple_action(slave,"$N��ͷ�����ǣ�ת���뿪�ˡ�\n",2);
    DELAY_D->delay_targetted_action(slave,o_k,"$N��$T�����ˡ�\n",3);
    DELAY_D->delay_targetted_action(o_k,master,"$N��$T�Ϲ�����վ��һ�ԡ�\n",3);

}


void create( )
{
    set_privilege(1);
    toplevel = new_menu("\n��������´�ָ�");
    quit_item = new_menu_item("����", (:quit_old_place:), "q");
    seperator = new_seperator
    ("----------------------------------------------------------------------");
    space = new_seperator
    ("                                                                      ");

    add_menu_item(toplevel, seperator);
    add_menu_item(toplevel, space);
    add_menu_item(toplevel, new_menu_item("�ڴ˹���",	(: do_stayhere :) ,"1"));


    add_menu_item(toplevel, new_menu_item("ѯ�����",	(: do_getinfo :) ,"3"));
    add_menu_item(toplevel, new_menu_item("�ʹ���Ʒ",	(: get_input_then_call,
		(: do_praise :) ,"�ʹͺ��" :) ,"4"));


    add_menu_item(toplevel, new_menu_item("�ı�ID",	(: get_input_then_call,
		(: do_changeid :) ,"��Ϊ��ID��" :) ,"9"));


    add_menu_item(toplevel, new_menu_item("��ְ", 	(: get_input_then_call,
	(: do_demote :) ,"ȷ�ϳ�ְ��(y/n)��" :) ,"a"));

    add_menu_item(toplevel, new_menu_item("�þ���",	(: do_getwine :) ,"b"));
    add_menu_item(toplevel, new_menu_item("������",	(: do_getmeat :) ,"c"));
    add_menu_item(toplevel, new_menu_item("ǣ����",	(: do_gethorse :) ,"d"));


    add_menu_item(toplevel, quit_item);
    add_menu_item(toplevel, space);
    set_menu_prompt (toplevel, "����ָ��[12349q]: ");
}
