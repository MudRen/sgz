// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

#include <mudlib.h>
#include <daemons.h>

inherit CMD;

void create()
{
  ::create();
  no_redirection();
}

private void main(string str) {
    if (!str || str == "") {
         out("�÷���I <whatever you did>\n");
         return;
    }
   if( DID_D->someone_did(str))
    out("������ϡ� (Thank you!)\n");
}

