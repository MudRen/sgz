// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

#include <mudlib.h>
#include <log.h>

inherit CMD;
inherit M_GRAMMAR;


#define SYNTAX  "�÷�: wall <��Ϣ>\n"

void create()
{
    ::create();
    no_redirection();
}

private void main( string arg )
{
    string              broadcast;

    if ( !check_privilege(1) )			//ԭ����"Admin:system"
        error("ֻ�д���ſ����� wall\n"); //"Must be an admin to use wall.\n");

    if( !sizeof( arg ))
    {
        write( SYNTAX );
        return;
    }

    broadcast = sprintf("%s �� %s ����ϵͳ��Ϣ��\n    %s\n",
      this_body()->query_name(), ctime(time()),
      punctuate(arg) );

    LOG_D->log(LOG_WALL, broadcast);

    tell(users(), broadcast, MSG_INDENT);
}
