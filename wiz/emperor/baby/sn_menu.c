//emperor write it

#include <menu.h>
#include <mudlib.h>
#include <verb.h>
#include <ppl.h>
inherit __DIR__+"free_menu";

void do_query(string str)
{
	object o_h;
	int i,j,k;
	string *baby_list,msg;
	mapping inf;

	o_h=SGHOME(p_id);
	baby_list=CHAR_D->get_char(master,"baby_id");
	poped=0;
    	modal_pop();

	if (!j) {slave->targetted_action("$N��$T����һ������$m�������ڻ�û���ӡ�\n",master);return;}

	k=0;
	for(i=0;i<j;i++){
		inf=o_h->get_npc(baby_list[i]);
		if(inf["id"]==str) k=k+1;
	}
	if(!k){slave->targetted_action("$N��$T����һ������$m����û������ӻ���С�㡣\n",master);return;}
	inf=o_h->get_npc(str);
	if(inf["gender"]==1) msg="����";else msg="С��";
	slave->targetted_action("$N��$T����һ������$m������Զ���λ"+msg+"���������飺\n",master);
	new(__DIR__+"sn_baby_menu")->start_menu();
}

void do_babylist() {
	string msg;
	object o_h;

	string *baby_list;
	int i,j;
	mapping inf;

	
	o_h=SGHOME(p_id);
	baby_list=CHAR_D->get_char(master,"baby_id");
	j=sizeof(baby_list);
	modal_pop();
	poped=0;
	if (!j) {slave->targetted_action("$N��$T���������㻹û���ӡ�\n",master);return;}
	msg="$N��$T���������$R�����ڸ��ﹲ��"+chinese_number(j)+"���Ӻ�С�㡣\n";

	for(i=0;i<j;i++){
		inf=o_h->get_npc(baby_list[i]);
		msg+=inf["pre_name"]+"  "+inf["id"]+"\n";
	}

	DELAY_D->delay_targetted_action(slave,master,msg,2);
	call_out("quit_menu_application",3);
}

void create( )
{
    set_privilege(1);
    toplevel = new_menu("\n�����Ů�´�ָ�");
    quit_item = new_menu_item("����", (:quit_old_place:), "q");
    seperator = new_seperator
    ("----------------------------------------------------------------------");
    space = new_seperator
    ("                                                                      ");

    add_menu_item(toplevel, seperator);
    add_menu_item(toplevel, space);
    add_menu_item(toplevel, new_menu_item("�ڴ˹���",	(: do_stayhere :) ,"1"));


    add_menu_item(toplevel, new_menu_item("ѯ�����",	(: do_getinfo :) ,"2"));
    add_menu_item(toplevel, new_menu_item("�ʹ���Ʒ",	(: get_input_then_call,
		(: do_praise :) ,"�ʹͺ��" :) ,"3"));


    add_menu_item(toplevel, new_menu_item("�ı�ID",	(: get_input_then_call,
		(: do_changeid :) ,"��Ϊ��ID��" :) ,"4"));


    add_menu_item(toplevel, new_menu_item("ѯ��BABY",	(: get_input_then_call,
		(: do_query :) ,"ѯ���ĸ�BABY��" :) ,"5"));

    add_menu_item(toplevel, new_menu_item("BABY������",	(: do_babylist :) ,"6"));


    add_menu_item(toplevel, quit_item);
    add_menu_item(toplevel, space);
    set_menu_prompt (toplevel, "����ָ��[123456q]: ");
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

