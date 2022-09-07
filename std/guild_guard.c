/* Do not remove the headers from this file! see /USAGE for more info. */
//
// By Ohara.

#include <mudlib.h>

inherit MONSTER;
inherit M_BLOCKEXITS;
inherit "/std/body/guilds.c";


private mixed handle_blocks( string dir )
{
// if( this_body()->query_member_guild( implode( this_object()->guilds_belong(), "")) || (this_body()->query_guilds () && GUILD_D->query_guild_allies( implode(this_object()->guilds_belong(), ""))))
//        return 0;
//    else
        return ::handle_blocks( dir );
}


void mudlib_setup( string guild )
{
    ::mudlib_setup();
    set_id( "guard" , "卫兵" );
    set_in_room_desc( "这里有一个卫兵。" );
    set_gender( 1 );     // default male.
//    add_guild( guild, 1 );
    set_block_action( "$n伸手把$t推开：\"你不是本帮派的人。\"\n");
}
