// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

// Rust wrote this and was a bad boy and didn't attach a header - Beek

#include <mudlib.h>

inherit CMD;
inherit M_INPUT;

private nomask void done()
{
    modal_pop();
    destruct();
    return;
    /* no need to destruct... we didn't clone */
    /* We do now! -=Zakk */
}

private nomask void confirm_new_password(string s1, string s2)
{
    write("\n");

    if(s1 != s2)
    {
        write("���������ϡ�\n");
    }
    else
    {
        this_user()->set_password(s1);
        write("�����趨��ɡ�\n");
    }

    done();
}

private nomask void get_new_password(string s)
{
    write("\n");

    if ( strlen(s) < 5 )
    {
        write("��������������������ϵ���ĸ��ɡ�\n�������ʧ�ܡ�\n");
        done();
    }
    else
    {
        modal_func((: confirm_new_password, s :), "��������һ�Σ�", 1);
    }
}

private nomask void confirm_current_password(string s)
{
    write("\n");

    if ( !this_user()->matches_password(s) )
    {
        write("���벻���ϡ�\n�������ʧ�ܡ�\n");
        done();
    }
    else
    {
        modal_func((: get_new_password :), "�����������룺", 1);
    }
}

void start_cmd()
{
    if(!clonep() || (base_name(previous_object()) != base_name()))  {
        write("��ͼ�Ƿ�ʹ�� passwd ���\n"); 
        destruct();
        return;
    }

    modal_push((: confirm_current_password :),
               "�������㵱ǰ�����룺", 1);
}


private void main()
{
    if(!clonep())  {
        new(base_name())->start_cmd();
        return;
    }
    destruct();
    return;
}

