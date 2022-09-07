// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

#include <daemons.h>
inherit CMD;

#define MIN_LEN 3

//:COMMAND
//Returns information on which mudlib functions contain the
//keyword passed, including a short description.
mixed
apropos(string s)
{
  mapping filer=([]);
  mapping topics;
  string output="";
  string *st;
  string pwd;

  topics=HELP_D->query_topics();
  if(!topics)
    {
      error("help_d û�и��������κ���Ŀ�İ���\n");
      return;
    }
  foreach (string key,string *files in topics)
    {
      if (strsrch(key,s)!=-1)
        foreach(string f in files)
          {         
            st=explode(f[6..],"/");
            pwd=implode(st[0..sizeof(st)-2],"/");
            if (!arrayp(filer[pwd])) filer[pwd]=({});
            filer[pwd]+=({key});
          }
    }
  foreach (string key in sort_array(keys(filer),1))
    {
      output+="["+key+"]: ";
      if (sizeof(filer[key])>1) output+="\n";
      output+=implode(filer[key],", ")+"\n";
    }
  output+="\n";
  return output;
}


private void
main(string s)
{
  string yt;
  if (!s) 
    {
      write("�÷���apropos <string>\n"
            "�����������Ĺؼ��ֵ� mudlib ��������Ϣ������һ��С˵����\n");
      return;
    }
  if (strlen(s)<MIN_LEN)
    {
      write("���ø���һЩ��������ѯ (���� "+MIN_LEN+
            " ��Ӣ����ĸ).\n");
      return;
    }
  yt=apropos(s);
  if (yt=="\n")
    write("û���ҵ���Ӧ�İ����ļ���\n");
  out(yt);
}
