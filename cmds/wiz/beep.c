// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

#include <mudlib.h>
inherit CMD;
inherit M_MESSAGES;
 
private void main( string  arg )
{
  object who;
  if( !arg)
    {
      this_body()->simple_action("$N������һ����" + chr(7));
      return;
    }
  who = find_body(lower_case(arg));
  if( !who )
    {
      out("��ֻ�ܺ�����ҡ�\n");
      return;
    }
  this_body()->inform( ({ this_body(), who }), action( ({this_body(), who }), "$N0����$T��\n" + chr(7))
                      );
  return;
}
 

