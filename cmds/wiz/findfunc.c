// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

#include <mudlib.h>

inherit CMD;

private void main( mixed *arg )
{
    object      target;
    string func;
    string ret;

    target = arg[1];
    func = arg[0];
   ret = function_exists(func, target);
   if (ret) {
      outf("�˺��������� %s �С�\n", ret);
   } else {
      out("�˺�������������û�ж��塣\n");
   }
}