// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

// See echoall header. P-)

#include <mudlib.h>

inherit CMD;


private void main( string str) {

  if ( !str )
  {
    out("�÷���echo <msg>\n");
    return;
  }

  if(!end_of_pipeline())
  {
     out(str);
     return;
  }

    tell_environment(this_body(), str + "\n", 0, ({ this_body() }));
    write("�㷢����Ϣ��"+str+"\n");

    return;
}
