// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

#include <commands.h>
#include <mudlib.h>

inherit CMD;
inherit M_INPUT;

#define MAX_DESCRIP_SIZE 6

private string* descrip = ({});

private void end_describe()
{
    if(!sizeof(descrip))
    {
        write("����û�иı䡣\n");
    }
    else
    {
        this_body()->set_description(implode(descrip, "\n") + "\n");
        write("����������\n");
    }

    destruct();
}


private void receive_line(string input)
{
    if(input == ".")
    {
        modal_pop();
        end_describe();
        return;
    }
    if(input == "~q")
    {
        write("������\n");
        modal_pop();
        destruct();
        return;
    }
    descrip += ({input});
    if(sizeof(descrip) == MAX_DESCRIP_SIZE)
    {
        write("�ﵽ�����������������������\n");
        modal_pop();
        end_describe();
    }
}

nomask void begin_describing()
{
    if ( previous_object() != find_object(CMD_OB_DESCRIBE) )
        error("��ͼ�Ƿ�ʹ�� describe.c\n");

    modal_push((: receive_line :), "");
}


void create()
{
  ::create();
  no_redirection();
}

private void main(string s)
{
    if ( stringp(s) && strlen(s) )
    {
        descrip = explode(s, "\n");
        end_describe();
        return;
    }

    out("���� "+ MAX_DESCRIP_SIZE+" ��֮�ڶ����Լ�����һ��������\n"
          "�� '.' �����༭��\n"
          "�� '~q' �����༭�� \n"
          "-----------------------------------------\n");

    new(CMD_OB_DESCRIBE)->begin_describing();
}
