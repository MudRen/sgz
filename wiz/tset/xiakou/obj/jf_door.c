//  jf_door.c
//  ����С��
//  created by tset 1/23/98
//  last updated by tset 1/23/98
 
inherit SECRET_DOOR;

void update_sibling()
{
    object sibling = get_sibling();
    // Needed for initial load ...\
    if( !sibling )
        return;

    // Magic ...
    if( is_open())
        sibling->do_on_open();
    else sibling->do_on_close();
    ::update_sibling();
}

void do_on_open()
{
    environment( this_object())->set_room_state( "jf_door");
}

void do_on_close()
{
    environment( this_object())->clear_room_state( "jf_door");
}

void setup(string dir)
{
    set_id("door", "С��");
    set_unit("��");
    set_adj("����ͨͨ��"); 
    set_long("���������ۣ���ע�������������\n");
 
    add_hook( "open", (: do_on_open :));
    add_hook( "close", (: do_on_close :));
    set_closed(1);   
    setup_door("С��", dir);
}
