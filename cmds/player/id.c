// id.c  
// created by tset 1/16/98
// last updated by tset 11/30/98

#include <mudlib.h>
inherit CMD;

private void main(string arg)
{
    int i;
    object *inv;
     
    if (!arg)
    {
        inv =  all_inventory(this_body());
        if( !sizeof(inv) ) {
            write("�㣨"+implode(this_body()->query_id(), ", ")+"������û���κζ�����\n");
            return;
        }
         
        printf("�㣨"+implode(this_body()->query_id(), ", ")+"������Я����Ʒ�ı������ :\n");
        for( i=0; i < sizeof(inv); i++)
        {
            if( !this_body()->is_visible(inv[i]) ) continue;
            printf("%s\n", implode(inv[i]->query_id(), ", ") );
        }
    }
    else if(arg == "here")
    {
        inv =  all_inventory(environment(this_body()));
	/* does this case ever happen? */
        if( !sizeof(inv) ) {
	    write("���"+implode(environment(this_body())->query_id(),", ")+"��û���κζ�����\n");
            return;
        }
        write("����������У�"+implode(environment(this_body())->query_id(),", ")+"��, \n���Ｐ��Ʒ���������� :\n");
        for( i=0; i < sizeof(inv); i++)
        {
            if( !this_body()->is_visible(inv[i]) ) continue;
            printf("%s\n", implode(inv[i]->query_id(), ", ") );
        }
    }
    else
        printf("�÷�: id, id here\n");

    return;
}           
            
