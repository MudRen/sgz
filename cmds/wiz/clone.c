// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

#include <mudlib.h>
#include <move.h>

inherit CMD;


private void main( mixed *arg ) {
    object o, ob;
    int size = sizeof( arg[0]);
    
    if( !size )
        arg[0] = this_body()->query_shell_ob()->get_variable( "cwf" );
    ob=this_body()->query_shell_ob();
    if (!sizeof(arg)) arg = ({ this_body()->get_variable("cwf") });
    o = new(arg[0]);
    if( !o )
    {
        out("�������ʧ�ܡ�\n");
        return;
    }
    if( !size && !inherits( "/std/object.c", o))
    {
        destruct(o);
        out( "clone [�ļ���]\n");
        return;
    }
    this_body()->do_player_message("clone", o);
    if (o->get() != MOVE_OK || o->move(this_body()) != MOVE_OK) {
        if (o->move(environment(this_body())) != MOVE_OK)
            out("��ɡ�(�޷��ƶ�)\n");
        else
            out("��ɡ�(��������)\n");
    } else
        out("��ɡ�(���������Ʒ��)\n");
    return;
}

