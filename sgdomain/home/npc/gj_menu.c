//qb.c this is used to give qb command by fire on Jan 1999

#include <menu.h>
#include <mudlib.h>
#include <verb.h>
#include <ppl.h>
inherit __DIR__+"free_menu";

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

void do_npclist() {
	string msg;
	object o_h;

	string *ls;
	int i,sum;
	string t_id,t_name,tt_id,t_pos;
	mapping inf;

	o_h=SGHOME(p_id);

	modal_pop();
	poped=0;

	master->targetted_action(
		"$N��$T����$m�����ڼ��ﶼ��Ӷ��Щʲô�ˡ�\n",slave);

	ls=o_h->get_npc("list");
	sum=sizeof(ls);
	msg="$N��$T���������$R�����ڸ���������ֹ���"+chinese_number(sum)+"��\n";
	for(i=0;i<sum;++i) {
		t_id=ls[i];
		inf=o_h->get_npc(t_id);
		tt_id=inf["pre_id"];
		t_name=inf["sname"]+inf["gname"];
		t_pos=inf["pos"];
		if(!stringp(t_pos)) t_pos="free";
		t_pos=load_object("/sgdomain/home/npc/"+t_pos)->get_type_name();
		msg+=t_name+"("+tt_id+")��ְλ��"+t_pos+"��������"+
			chinese_number(inf["salary"])+"����\n";
				
	}
        DELAY_D->delay_targetted_action(slave,master,msg,2);
	call_out("quit_menu_application",3);
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

    add_menu_item(toplevel, new_menu_item("������",	(: do_npclist :) ,"b"));

    add_menu_item(toplevel, new_menu_item("������",	(: get_input_then_call,
		(: do_call :) ,"�ٻ����ˣ�" :) ,"c"));

    add_menu_item(toplevel, quit_item);
    add_menu_item(toplevel, space);
    set_menu_prompt (toplevel, "����ָ��[12349q]: ");
}

