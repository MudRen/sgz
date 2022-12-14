// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

inherit DOOR;


void do_on_open()
{
   object env = environment( this_body() );

load_object("/domains/std/rooms/caves/north_tunnel.c")->set_room_state("gate_open");
   env->set_room_state("gate_open");
}

void do_on_close()
{
   object env = environment( this_body() );

load_object("/domains/std/rooms/caves/north_tunnel.c")->clear_room_state("gate_open");
   env->clear_room_state( "gate_open");
}
void setup(string dir) {
   add_hook("open", (:do_on_open:) );
   add_hook("close", (:do_on_close :) );
    set_id("gate", "大门");
    set_adj("生锈的" );
  set_long("这道门已经锈的不成样子了，再也不能挡住什么东西了。");
    set_closed(1);
    setup_door("生锈的大门", dir);
    set_flag(ATTACHED);
}
