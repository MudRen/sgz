// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

/*
** money.c -- Currency administration
**
** 25-Jul-96   Valentino.    Created.
**  6-Aug-96   Valentino.    Generalized and ported to Da Bean.
*/

#include <daemons.h>
#define ADMINS "����"
void std_handler(string str);
varargs void modal_simple(function input_func, int secure);
varargs void modal_func(function input_func, mixed prompt_func, int secure);
void do_one_arg(string arg_prompt, function fp, string arg);
void do_two_args(string arg1_prompt, string arg2_prompt,
                 function fp, string arg);
void do_three_args(string arg1_prompt, string arg2_prompt,string arg3_prompt,
                 function fp, string arg);

#define PROMPT_MONEY     "(AdmTool:currency)   [alrxmq?] > "

private nomask void write_money_menu()
{
    write("������: Ǯ�ҹ���\n"
          "\n"
          "    a [ar] [mat] [nic] - ������Ǯ�� ["+ADMINS+"]\n"
          "    l [area]           - Ǯ���б�\n"
          "    r [area] [materi]  - ɾ��Ǯ�� ["+ADMINS+"]\n"
          "    x [area] [amount]  - �����һ��� ["+ADMINS+"]\n"
          "\n"
          "    m                  - ��ѡ��\n"
          "    q                  - �˳�\n"
          "    ?                  - ����\n"
          "\n"
          );
}

varargs private nomask void
list_cur(string area)
{
  if (area=="") area=0;
  if (area && member_array(area,MONEY_D->query_currency_areas())==-1)
    {
      write("*** û�ж����������\n");
      return;
    }
  MONEY_D->stat_me(area,10000);
}

varargs private nomask void
add_cur(string area,string material,string nickname)
{
  if (!stringp(nickname) || !stringp(material) || !stringp(nickname))
    {
      write("*** ������������\n");
      return;
    }
  MONEY_D->add_currency(area,material,nickname);
  write("����Ǯ�ҳɹ���\n");
}

varargs private nomask void
adj_ex(string area,int amount)
{
  if (!stringp(area) || !intp(amount))
    {
      write("*** ������������\n");
      return;
    }
  if (MONEY_D->adjust_exchange_rate(area,amount))
    write("����Ǯ�ҳɹ���\n");
  else
    write("û�иĶ���\n");
}

varargs private nomask void
rem_cur(string area,string material)
{
  if (!stringp(area) || !stringp(material))
    {
      write("*** ������������\n");
      return;
    }
  write("׼��ɾ��...\n");
  MONEY_D->remove_currency(area,material);
}

private nomask void receive_money_input(string str)
{
  int i;
  string arg,arg2;
  
  sscanf(str,"%s %s",str,arg);
  switch(str)
    {
    case "?":
      write_money_menu();
      break;
    case "a":
      if (!adminp(this_body()))
        {
          write("�Բ���ֻ��"+ADMINS+"���š�\n");
          return;
        }
      do_three_args("�������ƣ�","�������ƣ�","ʲô���֣�",
                    (:add_cur:),arg);
      break;
    case "r":
      if (!adminp(this_body()))
        {
          write("�Բ���ֻ��"+ADMINS+"���š�\n");
          return;
        }
      do_two_args("�������ƣ�","�������ƣ�",(:rem_cur:),arg);
      break;
    case "x":
      if (!adminp(this_body()))
        {
          write("�Բ���ֻ��"+ADMINS+"���š�\n");
          return;
        }
      sscanf(arg,"%s %d",arg,i);
      adj_ex(arg,i);
      break;
    case "l":
      do_one_arg("�������ƣ�[Ԥ��Ϊ��������] ",(:list_cur:),arg);
      break;
    default:
      std_handler(str);
      break;
    }
}

static nomask void begin_money_menu()
{
  modal_func((: receive_money_input :), PROMPT_MONEY);
  write_money_menu();
}



