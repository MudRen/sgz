// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

#include <mudlib.h>

inherit CMD;


private void main( string message )
{
    string array exits = environment(this_body())->query_exit_directions( 0 );
    string str = "����Դӣ�";
    switch( sizeof(exits))
    {
    case 0:
	out("�㿴�����κγ��ڡ�\n");
        return;
    case 1:
        str += exits[0];
        break;
    default:
        str += implode( exits[0..<2], ", " );
        str += "�� ";
        str += exits[<1];
    }
    str += " �����뿪���\n";
    out( str );
    return;
}
