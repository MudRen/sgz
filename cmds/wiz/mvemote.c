// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

#include <daemons.h>

inherit CMD;

private void main(string str) {
  string dest;
  if ( !adminp(this_user()) )
    {
      out("�Բ���ֻ�Դ��񿪷š�\n");
      return;
    }
  
  if (!str) {
    out("�÷�: mvemote <target> <destination>\n");
    return;
  }
  sscanf(str, "%s %s", str, dest);
  if (SOUL_D->move_emote(str, dest))
    out("�ƶ��ˡ�\n");
  else out("ʧ���ˡ�\n");
}

