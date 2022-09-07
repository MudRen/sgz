//qb.c this is used to give qb command by fire on Jan 1999

#include <menu.h>
#include <mudlib.h>
#include <verb.h>
inherit MENUS;
inherit M_ACCESS;
inherit M_GRAMMAR;
inherit M_GLOB;
MENU toplevel;
MENU_ITEM quit_item;
MENU_ITEM seperator;

void do_getwine();
void do_cut(string str);
void do_getmeat();
void do_gethorse();
void do_getmoney(string str);
void do_nonsense();
void real_quit();

private object master,o;
private int poped;
private string p_id,n_id;

void do_getwine()
{
	poped=0;
    modal_pop();
	if(objectp(o))
	{
		this_body()->add_drink(500);
		this_body()->targetted_action(
			"$N��$T����$S�ڿʣ���Щ�þ�����\n",o);
        DELAY_D->delay_simple_action(o,"$N����������\n",1);
        DELAY_D->delay_targetted_action(o,this_body(),
			"$Nת�����һ��Ƹ�$T���ϡ�\n",2);
		DELAY_D->delay_simple_action(this_body(),
			"$N����ơ���ཡ�һ�����ȸ��ˡ�\n",3);

		DELAY_D->delay_targetted_action(this_body(),o,
			"$N�ѿվ��뻹��$T��\n",4);
	}
	call_out("quit_menu_application",5);
}

void do_getmeat()
{
    modal_pop();
	poped=0;
	if(objectp(o))
	{
		this_body()->add_food(500);
		this_body()->targetted_action(
			"$N��$T����$S���ˣ���Щ��������\n",o);
        DELAY_D->delay_simple_action(o,"$N����������\n",1);
        DELAY_D->delay_targetted_action(o,this_body(),
			"$Nת�����һ�������$T���ϡ�\n",2);
		DELAY_D->delay_simple_action(this_body(),
			"$Nץ����ֻ���ڱ�����ˡ�\n",3);

		DELAY_D->delay_targetted_action(this_body(),o,
			"$N�ѿ��뻹��$T��\n",4);
	}
	call_out("quit_menu_application",5);
}

void do_gethorse()
{
	object env=environment(this_body()),o_h;
	string p_id;
	mixed m_wear;
	p_id=this_body()->query_id()[0];
	m_wear=CHAR_D->get_char(p_id,"wear");
	if(!m_wear) m_wear=([]);
	
    modal_pop();
	poped=0;
	if(objectp(o))
	{
		this_body()->targetted_action(
			"$N��$T����$SҪԶ�У���Щǣ������\n",o);
		if(!m_wear["horse"]) {
	        DELAY_D->delay_targetted_action(o,this_body(),
				"$N��$TС������$R����Ǻ�Ϳ�ˣ�����û�������ء�\n",1);
			DELAY_D->delay_simple_action(this_body(),
				"$Nһ��ãȻ��\n",2);
			call_out("quit_menu_application",3);
			return;

		}
		if(env->is_indoors()){
	        DELAY_D->delay_targetted_action(o,this_body(),
				"$N��$TС������$R����Ǻ�Ϳ�ˣ��˴�ǣ����в��㡣\n",1);
			DELAY_D->delay_simple_action(this_body(),
				"$Nһ��ãȻ��\n",2);
			call_out("quit_menu_application",3);
			return;
		}
		if(env->is_horse()){
	        DELAY_D->delay_targetted_action(o,this_body(),
				"$N��$TС������$R����Ǻ�Ϳ�ˣ����Ѿ����������ˡ�\n",1);
			DELAY_D->delay_simple_action(this_body(),
				"$Nһ��ãȻ��\n",2);
			call_out("quit_menu_application",3);
			return;
		}
		o_h=OBJ_D->find_my_obj(p_id,m_wear["horse"]);
		if(!objectp(o_h))
		{	o_h=OBJ_D->clone_obj(m_wear["horse"]);
		}
		else {
			object *rs,h_env;
			h_env=environment(o_h);
			if(objectp(h_env)&&(h_env!=env)) {
				tell_environment(o_h,o_h->short()+"�������˵��ٻ���һ���̵����ˡ�\n");
				rs=o_h->get_riders();
			
				if(sizeof(rs)) {
					foreach(object r in rs) {
						r->move(h_env);
						r->simple_action("$N⧲�������ˤ��һ������ſ��\n");
					}
				}
			}
		}
		o_h->set_owner(p_id);
		o_h->move(env);
        DELAY_D->delay_simple_action(o,"$N����������\n",1);
        DELAY_D->delay_targetted_action(o,this_body(),
			"$Nת��ǣ��$n1p��"+o_h->short()+
			"����������$T���ϡ�\n",2);
		DELAY_D->delay_simple_action(this_body(),
			"$N����ص��˵�ͷ��\n",3);
	}
	call_out("quit_menu_application",5);
}


void do_getmoney(string str)
{
    object o_money;
	int p_money=to_int(str);
	int p_gold=CHAR_D->get_char(p_id,"gold");
	if(p_money<1) p_money=1;
	if(p_gold<p_money)
	{
		write("����û����ô��Ǯ��\n");
		return;
	}
	poped=0;
    modal_pop();
	CHAR_D->set_char(p_id,"gold",(p_gold-p_money));
	o_money=new(M_GOLD);
    o_money->set_m_num(p_money);
    o_money->move(this_body());
	if(objectp(o))
	{
		this_body()->targetted_action(
			"$N��$T������Ǯ������\n",o);
        DELAY_D->delay_simple_action(o,"$N����������\n",1);
        DELAY_D->delay_targetted_action(o,this_body(),
			"$Nת������һֻ�Ͻ�Ǯ�С�\n",2);
		DELAY_D->delay_simple_action(this_body(),
			"$N��Ǯ�����ó�"+chinese_number(p_money)+"�����ӡ�\n",3);

		DELAY_D->delay_targetted_action(this_body(),o,
			"$N��Ǯ�л���$T����������С���պ��ˡ�\n",4);
	}
	call_out("quit_menu_application",5);
}

void do_praise(string str)
{
    object o_obj;

    mixed m_wear;
    o_obj=present(str,master) ;
    if(!objectp(o_obj)) {
	write("������û��"+str+"��\n");
	return;
    }
    call_out("quit_menu_application",5);

    this_body()->targetted_action("$N��$T�����ֵ��Ǻ������ˣ���$O���͸��ֵ��ǰɡ�\n",o,o_obj);
    this_body()->targetted_action("$N��$O�ݸ�$T��\n",o,o_obj);

    DELAY_D->delay_simple_action(o,"$N���˵�����������\n",1);

    destruct(o_obj);
    o_obj=present(str,master) ;
    if(!objectp(o_obj)) { 
       m_wear=CHAR_D->get_char(p_id,"wear");
       if(mapp(m_wear)) {
          string *ks,*vl,o_id;
          int ps;
          ks=keys(m_wear);
	  vl=values(m_wear);
	  ps=member_array(str,vl);
          if(ps==-1) return;
	  o_id=ks[ps];
	  map_delete(m_wear,o_id);
	  CHAR_D->set_char(p_id,"wear",m_wear);
       }
    }

}

void do_nonsense()
{
	poped=0;
    modal_pop();
	if(objectp(o))
	{
		this_body()->targetted_action(
			"$N��$T���ֹ�����֪˵��Щʲô��\n",o);
        DELAY_D->delay_simple_action(o,"$Nһ��ãȻ��֪���ơ�\n",1);
	}
	call_out("quit_menu_application",2);
}

void create()
{
    set_privilege(1);
    toplevel = new_menu("\n����ױ��´�ָ�");
    quit_item = new_menu_item("����", (:quit_menu_application:), "q");
    seperator = new_seperator
    ("������������������������������������������������������������������");
    add_menu_item(toplevel, seperator);
    add_menu_item(toplevel, new_menu_item("���þ���",	(: do_getwine :) ,"1"));
    add_menu_item(toplevel, new_menu_item("��������",	(: do_getmeat :) ,"2"));
    add_menu_item(toplevel, new_menu_item("��ǣ����",	(: do_gethorse :) ,"3"));
    add_menu_item(toplevel, new_menu_item("����Ǯ��",	(: get_input_then_call,
		(: do_getmoney :) ,"�ö���Ǯ[1]��" :) ,"4"));
    add_menu_item(toplevel, new_menu_item("�ʹ���Ʒ",	(: get_input_then_call,
		(: do_praise :) ,"�ʹͺ��" :) ,"5"));
    add_menu_item(toplevel, new_menu_item("ȥ����",	(: do_nonsense :) ,"6"));
    add_menu_item(toplevel, new_menu_item("׼������",	(: get_input_then_call, 
		(: do_cut :), "�ü�������" :), "0"));

        add_menu_item(toplevel, quit_item);
        add_menu_item(toplevel, seperator);
        set_menu_prompt (toplevel, "����ָ��[12340q]: ");
}

void start_menu()
{
	p_id=this_body()->query_id()[0];
	n_id=p_id+" qb";
	poped=1;
	master=this_body();
	o=CHAR_D->find_char(n_id);

	init_menu_application( toplevel );
	call_out("quit_menu_application",50);
}
void do_cut(string str)
{
    int p_realqb,p_qb=to_int(str);
	mixed myarmy;
	if(!p_qb)
	{
		write("�ܺã���Ҫ�����ˡ�\n");
		return;
	}
	myarmy=CHAR_D->get_char(p_id,"myarmy");
	p_realqb=myarmy["qbnum"];
	if(p_realqb<p_qb)
	{
		write("��û����ô���ױ���\n");
		return;
	}

    modal_pop();
	poped=0;
	myarmy["qbnum"]-=p_qb;
	if(objectp(o))
	{
		this_body()->targetted_action(
			"$N��$T�����ֵ��Ǹ������Ѿã�Ҳ�ûؼҿ��������ˣ�\n"+
			"���һ�����"+chinese_number(p_qb)+"���ֵܻؼҰɡ�\n",o);
        DELAY_D->delay_simple_action(o,"$N����������\n",1);
        DELAY_D->delay_targetted_action(o,this_body(),
			"$Nһ������$T��ƨƨ�ϣ�ӡ��һ�������Ьӡ��\n",2);
		DELAY_D->delay_simple_action(this_body(),
			"$N�۵���ֱ�С�\n",3);
	}
	call_out("quit_menu_application",4);

}

void quit_menu_application()
{
	if(poped)
		modal_pop();
	remove_call_out("quit_menu_application");
	if(objectp(o))
	{
		int p_gold=CHAR_D->get_char(p_id,"gold");
		if(p_gold&&(random(20)==9))
		{
			CHAR_D->set_char(p_id,"gold",p_gold-1);
			this_body()->targetted_action(
				"$N��$T�����ӿ�����һ�����ӣ������������ȥ�ɡ�\n",o);
	        DELAY_D->delay_targetted_action(o,this_body(),
				"$N���˵�����������������л$T���ʹ͡�\n",1);
	        DELAY_D->delay_simple_action(this_body(),
				"$N���ŵ�������û���ˣ������°ɡ�\n",2);
			DELAY_D->delay_simple_action(o,
				"$N����������\n",3);
			call_out("real_quit",4);
		}
		else
		{
			this_body()->targetted_action(
				"$N��$T��������û���ˣ������°ɡ�\n",o);
			DELAY_D->delay_simple_action(o,
				"$N����������\n",1);
			call_out("real_quit",2);
		}
	}
	else 
		real_quit();
}
void real_quit()
{
	string p_id=this_body()->query_id()[0];
	string n_id=p_id+" qb";
	CHAR_D->remove_char(n_id);
    destruct(this_object());
}
