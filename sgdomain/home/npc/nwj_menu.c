//qb.c this is used to give qb command by fire on Jan 1999

#include <menu.h>
#include <mudlib.h>
#include <verb.h>
#include <ppl.h>
#include <edit.h>
inherit __DIR__+"free_menu";

protected mapping r_typ=
([ 
  "path" : ([
		"name" : "%^YELLOW%^����%^RESET%^",
		"money" : 2, // 2 gold each
	   ]),
  "bedroom" : ([
		"name" : "%^YELLOW%^�Է�%^RESET%^",
		"money" : 10, // 2 gold each
		"num" : 1,
	   ]),

  "bingying" : ([
		"name" : "%^BLUE%^��Ӫ%^RESET%^",
		"money" : 50, // 2 gold each
		"num" : 4,
	   ]),

  "kitchen" : ([
		"name" : "%^GREEN%^����%^RESET%^",
		"money" : 10, // 2 gold each
		"num" : 1,
	   ]),

  "malang" : ([
		"name" : "%^GREEN%^����%^RESET%^",
		"money" : 10, // 2 gold each
		"num" : 1,
	   ]),
  "liangcang" : ([
		"name" : "%^GREEN%^����%^RESET%^",
		"money" : 30, // 2 gold each
		"num" : 4,
	   ]),

  "cangku" : ([
		"name" : "%^RED%^�ֿ�%^RESET%^",
		"money" : 20, // 2 gold each
		"num" : 1,
	   ]),

  "zhangfang" : ([
		"name" : "%^RED%^�ʷ�%^RESET%^",
		"money" : 10, // 2 gold each
		"num" : 1,
	   ]),

  "shufang" : ([
		"name" : "%^RED%^�鷿%^RESET%^",
		"money" : 20, // 2 gold each
		"num" : 1,
	   ]),

  "lianwuting" : ([
		"name" : "%^RED%^������%^RESET%^",
		"money" : 30, // 2 gold each
		"num" : 1,
	   ]),

  "keting" : ([
		"name" : "%^GREEN%^����%^RESET%^",
		"money" : 40, // 2 gold each
		"num" : 1,
	   ]),

]);

string show_typ() {
	string ret,*ps;
	ps=keys(r_typ);
	ret="Ŀǰ�ɽ���ķ��������У�\n";
	foreach(string p in ps) {
		ret+=r_typ[p]["name"]+"("+p+")   ";
	}
	ret+="\n������Ҫ����ķ������͵�ID��";
	return ret;
}		

void done_addroom(string dir,string typ) {
	string *ps;
	object o_h=SGHOME(p_id);
	int curs,path_num,max_num;
	string h_id,here_id,opdir;
	ps=keys(r_typ);
	if(member_array(typ,ps)==-1)
	{
		write("û��"+typ+"���෿�䡣\n");
		return;
	}
	curs=sizeof(o_h->check_room("t",typ));

	if(r_typ[typ]["num"]&&(curs>=r_typ[typ]["num"])) {
		write("Ŀǰ"+r_typ[typ]["name"]+"���ͷ����Ѿ��������ˡ�\n");
		return;
	}
	path_num=sizeof(o_h->check_room("t","path"));	
	h_id=CHAR_D->get_char(p_id,"h")["id"];
	max_num="/daemons/house_d"->get_house(h_id,"room");
	if(typ=="path") {
		if(path_num>max_num) {
			write("�����ٽ������������ˡ�\n");
			return;
		}
	}
	else {
		if((o_h->get_room("size")-path_num-2)>=max_num) {
			write("��ķ��Ӳ����ٽ������Ĺ��ܷ����ˡ�\n");
			return;
		}
	}
	if(MONEY_D->sub_all_money(master,r_typ[typ]["money"]*10000)==-1) {
		write("���Ǯ���������·����ˡ�\n");
		return;
	}
	here_id=master->query_room()->get_id();
	opdir=DIRECTION_D->oppdir(dir);
	o_h->add_room(here_id,dir,opdir,typ,r_typ[typ]["name"]);

	poped=0;
	modal_pop();
	call_out("quit_menu_application",7);

	master->targetted_action("$N��$T����$SҪ��������"+DIRECTION_D->cdir(dir)+
		"�ٽ���һ��"+r_typ[typ]["name"]+"��\n",slave);
	DELAY_D->delay_targetted_action(slave,master,"$N��$T˵��Ҫ��"+
		chinese_number(r_typ[typ]["money"])+"�����ӡ�\n",2);
	DELAY_D->delay_targetted_action(master,slave,"$N��$T����û���⡣\n",3);
	DELAY_D->delay_targetted_action(slave,master,"$N��$T�����·���Ӧ�úܿ�ͽ��á�\n",4);


}
void do_addroom(string dir) {
	string opdir;
	string t;
	string here_id;
	opdir=DIRECTION_D->oppdir(dir);
	if(!sizeof(opdir)) {
		write(dir+"���޷����ķ���\n");
		return;
	}
	t=master->query_room()->get_type();
	if((t!="path")&&(t!="hall")) {
		write("ֻ�д����������Ȳſ��Խ����·��䡣\n");
		return;
	}
	here_id=master->query_room()->get_id();
	if(stringp(SGHOME(p_id)->get_room(here_id,"e")[dir])) {
		write("��������Ծ��з����ˡ�\n");
		return;
	}

	get_input_then_call ((: done_addroom ,dir:) , show_typ());

}
void do_changeroomname(string nam) {
	object o_h=SGHOME(p_id);
	string here_id;
	here_id=master->query_room()->get_id();
	if(sizeof(nam)<1) {	
		write("����Ҫ�и����֡�\n");
		return;
	}
	o_h->set_room(here_id,"b",nam);
	o_h->update_room(here_id);

	poped=0;
	modal_pop();
	call_out("quit_menu_application",5);

	master->targetted_action("$N��$T����$SҪ�Ѵ˷�������Ƹ�Ϊ"+nam+"��\n",slave);
	DELAY_D->delay_targetted_action(slave,master,"$N��$T����û���⡣\n",2);
	DELAY_D->delay_targetted_action(master,slave,"$N��$T����ص��˵�ͷ��\n",3);

}


void done_changeroomdesc( string *lines)
{
	object o_h=SGHOME(p_id);
	string here_id;
	string nam;

	here_id=master->query_room()->get_id();
    if ( !lines )
    {
	    printf("�����жϡ�\n");
		return;
    }
	nam=implode(lines, "\n");
	nam+="\n";
	o_h->set_room(here_id,"l",nam);
	o_h->update_room(here_id);

	poped=0;
	modal_pop();
	call_out("quit_menu_application",5);

	master->targetted_action("$N��$T����$SҪ�Ѵ˷���Ĳ��ָ�һ�¡�\n",slave);
	DELAY_D->delay_targetted_action(slave,master,"$N��$T����û���⡣\n",2);
	DELAY_D->delay_targetted_action(master,slave,"$N��$T����ص��˵�ͷ��\n",3);
    
    
}

void do_changeroomdesc() {
	object o_h=SGHOME(p_id);
	string here_id;
	here_id=master->query_room()->get_id();
	if(here_id=="front") {
		write("������������ܸġ�\n");
		return;
	}
    printf("����������\n");

    new(EDIT_OB, EDIT_TEXT, 0, (: done_changeroomdesc:));

}
void do_repairroom() {
	int p_state,p_money;
	object o_here;
	o_here=master->query_room();
	p_state=o_here->get_status();
	if(p_state>80) {
		write("��������������ã�����Ҫ����\n");
		return;
	}
	if(p_state==1) {
		write("�����Ѿ�û�����ˡ�\n");
		return;
	}
	p_money=(100-p_state)/20;

	if(MONEY_D->sub_all_money(master,p_money*10000)==-1) {
		write("���Ǯ���������䡣\n");
		return;
	}
	poped=0;
	modal_pop();
	o_here->repair();
	call_out("quit_menu_application",7);
	master->targetted_action("$N��$T����������ӳ���ʧ�ޣ�������ú�����һ�¡�\n",slave);
	DELAY_D->delay_targetted_action(slave,master,"$N��$T˵��Ҫ��"+p_money+"�����ӡ�\n",2);
	DELAY_D->delay_targetted_action(master,slave,"$N��$T����û���⡣\n",3);
	DELAY_D->delay_targetted_action(slave,master,"$N��$T��������Ӧ�úܿ���޺á�\n",4);
}
void do_destoryroom(string con) {
	object o_h=SGHOME(p_id);
	string here_id,nb_id;
	string *nbs;

	if(con!="y") {
		write("���������Ҫ���������\n");
		return;
	}
	here_id=master->query_room()->get_id();
	nbs=o_h->get_room(here_id,"e");
	if(sizeof(nbs)>1) {
		write("����������������ϳ��ڣ����ܲ�\n");
		return;
	}
	nb_id=nbs[0];
	if((here_id=="front")||(here_id=="enter")) {
		write("�������������������ڣ����ܲ�\n");
		return;
	}

	if(MONEY_D->sub_all_money(master,20000)==-1) {
		write("���Ǯ�����𷿼䡣\n");
		return;
	}
	poped=0;
	modal_pop();
	call_out("quit_menu_application",7);

	o_h->remove_room(here_id);

	master->targetted_action("$N��$T����$SҪ����䷿�����\n",slave);
	DELAY_D->delay_targetted_action(slave,master,"$N��$T˵��Ҫ��"+
		chinese_number(2)+"�����ӡ�\n",2);
	DELAY_D->delay_targetted_action(master,slave,"$N��$T����û���⡣\n",3);
	DELAY_D->delay_targetted_action(slave,master,"$N��$T���������Ѿ����ˡ�\n",4);

}
void create( )
{
    set_privilege(1);
    toplevel = new_menu("\n������߽��´�ָ�");
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

    add_menu_item(toplevel, new_menu_item("�����·���",	(: get_input_then_call,
		(: do_addroom :) ,"�·���ķ���" :) ,"4"));

    add_menu_item(toplevel, new_menu_item("�ı䷿������",	(: get_input_then_call,
		(: do_changeroomname :) ,"�µķ������ƣ�" :) ,"5"));

    add_menu_item(toplevel, new_menu_item("�ı䷿������",	(: do_changeroomdesc :) ,"6"));

    add_menu_item(toplevel, new_menu_item("�������",	(: get_input_then_call,
		(: do_destoryroom :) ,"ȷ�ϲ����(y/n)��" :) ,"7"));

    add_menu_item(toplevel, new_menu_item("������",	(: do_repairroom :) ,"8"));

    add_menu_item(toplevel, new_menu_item("�ı�ID",	(: get_input_then_call,
		(: do_changeid :) ,"��Ϊ��ID��" :) ,"9"));

    add_menu_item(toplevel, new_menu_item("��ְ", 	(: get_input_then_call,
	(: do_demote :) ,"ȷ�ϳ�ְ��(y/n)��" :) ,"a"));

    add_menu_item(toplevel, quit_item);
    add_menu_item(toplevel, space);
    set_menu_prompt (toplevel, "����ָ��[12349q]: ");
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
