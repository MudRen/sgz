// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

#include <mudlib.h>

inherit CMD;

private void main(string array argv)
{
  mixed result;


  result = CMD_D->find_cmd_in_path(argv[0], 
           this_body()->query_shell_ob()->query_path());

  if(result == -1)
    {
      out("�������·��������ôһ���ļ�������û�� main() ������\n");
      return;
    }

  if(!result)
    {
      out("�������·����û������ļ���\n");
      return;
    }
  outf("%s λ�ڣ�%s\n", argv[0], result[1]);
  return;
}

