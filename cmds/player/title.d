// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

#include <mudlib.h>
inherit CMD;

void create()
{
  ::create();
  no_redirection();
}

private void main(string title)
{
    if(!sizeof(title))
    {
      outf("��ĳƺ��ǣ�%s\n", this_body()->query_title());
      return;
    }
  if(strsrch(title,"$N") == -1)
    title = "$N " + title;
  this_body()->set_title(title);
  
  out("�ƺŸı��ˡ�\n");
}
