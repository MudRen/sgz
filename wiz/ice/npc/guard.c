/* Do not remove the headers from this file! see /USAGE for more info. */

#include <mudlib.h>

inherit GUILD_GUARD;

void setup( string guild )
{
      object jia;
    jia=new("/wiz/nono/obj/changpao.c");
    jia->move(this_object());
    jia->do_wear();
    set_sg_rongmao(25);
    set_age(40);
    set_gender( 1 ); // female - overrides default
    set_in_room_desc( "һλ�������׵�������ס�����еĳ��ڡ�" );
    add_block( "north" );
    add_block( "south" );
    add_block( "east" );
    add_block( "west" );
    add_block( "up" );
    add_block( "down" );
    add_block( "out" );
    add_block( "enter" );
    add_block( "northwest" );
    add_block( "northeast" );
    add_block( "southwest" );
    add_block( "southeast" );
}
