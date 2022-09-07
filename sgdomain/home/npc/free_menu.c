//qb.c this is used to give qb command by fire on Jan 1999

#include <menu.h>
#include <mudlib.h>
#include <verb.h>
#include <ppl.h>
inherit MENUS;
inherit M_ACCESS;
inherit M_GRAMMAR;
inherit M_GLOB;
MENU toplevel;
MENU_ITEM quit_item;
MENU_ITEM seperator;
MENU_ITEM space;

void do_cut(string cf);
void real_quit();
void do_givepos(string str);
void quit_old_place();
protected object master,slave;
protected int poped;
protected string p_id,n_id,master_id;

protected mapping p_pos=
([ 
  "gj" : ([
		"name" : "�Ϲܼ�",
		"num" : 1, // maximum number for one family
		"type" : ({OLDWOMAN,OLDMAN}), // just old man and old woman can do it
	   ]),
  "nwj" : ([
		"name" : "���߽�",
		"num" : 1, // maximum number for one family
		"type" : ({MIDMAN}), // just old man and old woman can do it
	   ]),
  "zfxs" : ([
		"name" : "�ʷ�����",
		"num" : 1, // maximum number for one family
		"type" : ({OLDMAN}), // just old man and old woman can do it
		"room" : "zhangfang",
	   ]),

  "dcs" : ([
		"name" : "���ʦ",
		"num" : 1, // maximum number for one family
		"type" : ({OLDMAN,OLDWOMAN,MIDMAN,MIDWOMAN}), 
		"room" : "kitchen",
	   ]),

  "sc" : ([
		"name" : "���",
		"num" : 3, // maximum number for one family
		"type" : ({OLDMAN,OLDWOMAN,MIDMAN,MIDWOMAN,YOUNGMAN,YOUNGWOMAN}), 
	   ]),

]);
string show_pos() {
	string ret,*ps;
	ps=keys(p_pos);
	ret="Ŀǰ�е�ְλ�ǣ�\n";
	foreach(string p in ps) {
		ret+=p_pos[p]["name"]+"("+p+")   ";
	}
	ret+="\n������Ҫ���ŵ���ְ���ID��";
	return ret;
}		
void do_getinfo()
{
	object o_h;
	string p_info;
	int p_cometime,p_salary;
	o_h=SGHOME(p_id);

	poped=0;
    	modal_pop();
	p_cometime=o_h->get_npc(n_id,"cometime");
	p_salary=o_h->get_npc(n_id,"salary");
	p_info="$N��$T������$R��$s����������"+CHINESE_D->chinese_period((time()-p_cometime)*90)+
		"��Ŀǰ��ٺ���ǣ�"+chinese_number(p_salary)+"������һ���¡�\n";
	master->targetted_action(
		"$N��$T����$m����������������ô����\n",slave);

        DELAY_D->delay_targetted_action(slave,master,p_info,2);
	call_out("quit_menu_application",5);
}


void do_stayhere()
{
	object env=master->query_room();
	string r_id;
	object o_h;
	o_h=SGHOME(p_id);
	r_id=env->get_id();
	o_h->set_npc(n_id,"room",r_id);

	modal_pop();
	poped=0;

	master->targetted_action(
		"$N��$T����$m�������û�µ�ʱ����ڴ������ǲ��\n",slave);

        DELAY_D->delay_targetted_action(slave,master,
		"$N��$T�������������\n",2);
	call_out("quit_menu_application",3);
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

	poped=0;
    	modal_pop();

    call_out("quit_menu_application",5);

    master->targetted_action("$N��$T����$R�����ˣ���$O���͸���ɡ�\n",slave,o_obj);
    master->targetted_action("$N�ָ�$T$O��\n",slave,o_obj);

    DELAY_D->delay_simple_action(slave,"$N���˵�����������\n",2);

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

void do_changeid(string str)
{
    object o_h;
    o_h=SGHOME(p_id);
	if(strsrch(str," ")>=0) {
		write("ID �в����пո�\n");
		return;
	}

    if((sizeof(str)>8)||(sizeof(str)<3)) {
	write("ID������3��8����ĸ��\n");
	return;
    }
	poped=0;
    	modal_pop();

    o_h->set_npc(n_id,"pre_id",str);
    slave=o_h->update_npc(n_id);

    call_out("quit_menu_application",5);

    master->targetted_action("$N��$T����$R�����ˣ�$S�������µ�ID��"+str+"����ס����\n",slave);

    DELAY_D->delay_simple_action(slave,"$N��ͷ������ס�ˡ�\n",2);
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
    add_menu_item(toplevel, new_menu_item("����ְ��",	(: get_input_then_call,
		(: do_givepos :) ,show_pos() :), "2"));

    add_menu_item(toplevel, new_menu_item("ѯ�����",	(: do_getinfo :) ,"3"));
    add_menu_item(toplevel, new_menu_item("�ʹ���Ʒ",	(: get_input_then_call,
		(: do_praise :) ,"�ʹͺ��" :) ,"4"));

    add_menu_item(toplevel, new_menu_item("�ı�ID",	(: get_input_then_call,
		(: do_changeid :) ,"��Ϊ��ID��" :) ,"9"));

    add_menu_item(toplevel, new_menu_item("����", (: get_input_then_call,
	(: do_cut :) ,"ȷ�Ͽ�����(y/n)��" :) ,"0"));

    add_menu_item(toplevel, quit_item);
    add_menu_item(toplevel, space);
    set_menu_prompt (toplevel, "����ָ��[123490q]: ");
}

void start_menu(object m,object s)
{
//	string id;
	master=m;
	slave=s;	
//	p_id=master->query_primary_id();
	p_id=slave->get_master();
	n_id=slave->get_id();
	poped=1;
//	sscanf(file_name(s), "/sgdomain/home/npc_server/%s/%s", master_id, id);
	init_menu_application( toplevel );
	call_out("quit_menu_application",50);

}
void do_givepos(string str) 
{
	string *ps;
	object o_h=SGHOME(p_id);
	int curs,my_typ;
	ps=keys(p_pos);
	if(member_array(str,ps)==-1)
	{
		write("û��"+str+"���ְ��\n");
		return;
	}
	curs=sizeof(o_h->check_npc("pos",str));
	if(p_pos[str]["num"]&&(curs>=p_pos[str]["num"])) {
		write("Ŀǰ"+p_pos[str]["name"]+"��ְλ�Ѿ����ˡ�\n");
		return;
	}
	my_typ=o_h->get_npc(n_id,"typ");
	if(sizeof(p_pos[str]["type"])&&(member_array(my_typ,p_pos[str]["type"])==-1)) {
		write(slave->short()+"���ʺ�"+p_pos[str]["name"]+"���ְλ��\n");
		return;
	}

	if(sizeof(p_pos[str]["type"])&&(member_array(my_typ,p_pos[str]["type"])==-1)) {
		write(slave->short()+"���ʺ�"+p_pos[str]["name"]+"���ְλ��\n");
		return;
	}

	poped=0;
	modal_pop();
	call_out("quit_menu_application",7);
	o_h->set_npc(n_id,"pos",str);
	slave=o_h->update_npc(n_id);
	master->targetted_action("$N��$T����$R�Ϳ๦�ߣ�$S����Ϊ"+
		p_pos[str]["name"]+"��\n",slave);
	DELAY_D->delay_simple_action(slave,"$N���˵�����������\n",2);
	DELAY_D->delay_targetted_action(slave,master,"$N��$T����������\n",3);

	
}
void kill_me() {
	if(objectp(slave))
		destruct(slave);
	
}
void do_cut(string cf)
{	
	object o_h;
	o_h=SGHOME(p_id);
	if(cf!="y") return;
	poped=0;
	modal_pop();

	master->targetted_action(
		"$N��$T�����Ҿ����ȵ��꣬����������������ˣ���ؼ�ȥ�ɣ�\n",slave);
        DELAY_D->delay_simple_action(slave,"$N����������\n",2);

        DELAY_D->delay_targetted_action(slave,master,
			"$Nһ������$T��ƨƨ�ϣ�ӡ��һ�������Ьӡ��\n",3);
	DELAY_D->delay_simple_action(master,
			"$N�۵���ֱ�С�\n",4);
	MONEY_D->sub_all_money(master,10000);

	DELAY_D->delay_targetted_action(master,slave,
			"$N�Ͻ���$T����һ�����ӡ�\n",5);

	DELAY_D->delay_simple_action(slave,
			"$N�߷��뿪�ˡ�\n",6);
	o_h->remove_npc(n_id);
	call_out("kill_me",7);
	call_out("real_quit",8);
}

void do_demote(string cf)
{	
	object o_h;
	o_h=SGHOME(p_id);
	if(cf!="y") return;
	poped=0;
	modal_pop();

	o_h->set_npc(n_id,"pos","free");
	slave=o_h->update_npc(n_id);

	master->targetted_action(
		"$N��$T������˵�����Ļ̫�����\n",slave);
        DELAY_D->delay_simple_action(slave,"$N�������ҡ�\n",2);

        DELAY_D->delay_targetted_action(master,slave,
			"$N��$T����������Ϣ��ϢҲ�á���ʱ�������˰ɡ�\n",3);
	DELAY_D->delay_simple_action(slave,
			"$N�����ǡ�\n",4);

	DELAY_D->delay_simple_action(slave,
			"$N���Ʋ��ֵ��˵�һ�ߡ�\n",6);

	call_out("real_quit",8);
}


void quit_old_place() {
	object o_h,o_r;
	string p_rm;

	o_h=SGHOME(p_id);
	
	modal_pop();
	poped=0;
	p_rm=o_h->get_npc(n_id,"room");
	o_r=o_h->load_room(p_rm);
	slave->move(o_r);
	master->targetted_action(
		"$N��$T��������û���ˣ������°ɡ�\n",slave);

	DELAY_D->delay_targetted_action(slave,master,
		"$N��$Tһ�Ϲ������ǣ�Ȼ�������ˣ�\n",2);
	call_out("real_quit",4);
}
void quit_menu_application()
{
	if(poped)
		modal_pop();
	poped=0;
	if (!slave) {real_quit(); return;}
	if(objectp(master)) 
	master->targetted_action(
		"$N��$T��������û���ˣ������°ɡ�\n",slave);
	DELAY_D->delay_simple_action(slave,
		"$Nһ�Ϲ������ǣ�Ȼ���˵�һ�ߣ�\n",2);
	call_out("real_quit",4);

}
void real_quit()
{
	if(poped)
		modal_pop();
	remove_call_out("quit_menu_application");

	if(objectp(slave))
		slave->set_busy(0);
    destruct(this_object());
}
