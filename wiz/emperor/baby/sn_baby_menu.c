void create( )
{
    set_privilege(1);
    toplevel = new_menu("");
    quit_item = new_menu_item("����", (:quit_old_place:), "q");
    seperator = new_seperator
    ("----------------------------------------------------------------------");
    space = new_seperator
    ("                                                                      ");

    add_menu_item(toplevel, seperator);
    add_menu_item(toplevel, space);
    add_menu_item(toplevel, new_menu_item("��������",	(: do_play :) ,"1"));
    add_menu_item(toplevel, new_menu_item("������ι��",	(: do_weinai :) ,"2"));
    add_menu_item(toplevel, new_menu_item("�̺���˵��",	(: do_teach :) ,"3"));
    add_menu_item(toplevel, new_menu_item("����������",	(: get_input_then_call,
		(: do_changeid :) ,"��Ϊ������" :) ,"4"));
    add_menu_item(toplevel, quit_item);
    add_menu_item(toplevel, space);
    set_menu_prompt (toplevel, "����ָ��[1234q]: ");
}

void start_menu()
{

	poped=1;

	init_menu_application( toplevel );
	call_out("quit_menu_application",50);

}

