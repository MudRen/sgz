// Updated by stefan on 10 Jan 1997
// Updated by tset on 15 Apr 1998
/* Do not remove the headers from this file! see /USAGE for more info. */

// This command works only for admins.  -- Rust

#include <mudlib.h>
inherit CMD;

private void main()
{
    int flag;
    object user;

    flag = 0;

    if ( !check_privilege(1) )
    {
        out("�Բ�����������ֻ�ܸ�����ʹ�á�\n");
        return;
    }

    foreach ( user in users() )
    {
        object ob = query_snooping(user);

        if ( ob )
        {
	    outf("%s ���ڼ��� %s.\n",
                   user->query_userid(),
                   ob->query_userid());
	    flag++;
        }
    }

    if ( flag == 0 )
	out("Ŀǰû���κ��˱�������\n");
}
