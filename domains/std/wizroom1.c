/* Do not remove the headers from this file! see /USAGE for more info. */
#include <mudlib.h>
inherit ROOM;
mixed can_go_up()
{
    if( environment( this_body())->is_vehicle()) return "你要走下来才行。\
n";
    return 1;
}
int do_go_up(){ 
    this_body()->do_game_command( "climb up stairs");
    return 1;
}
mixed can_go_down()
{
    if( environment( this_body())->is_vehicle()) return "你要走下来才行。\
n";
    return 1;
}
int do_go_down()
{
    this_body()->do_game_command( "climb down stairs" );
    return 1;
}
void setup(){
    object door;
    set_area("wiz_area");
    set_brief("巫师大厅");
    set_long("欢迎来到 LIMA，这里是巫师们讨论和发表与 LP MUD 和 MudOS 相"
"关问题的论坛。你也可以在这里询问一些有关中文 MUD 的技术性问题。"
"由于汉化还不够充分，LIMA 仍有许多的地方有待完善，欢迎大家多提意见。\n"
"        使用新闻系统，请用 news 命令。\n"
"        使用玩家选单，请用 menu 命令。\n"
"        使用邮件系统，请用 mail 命令。\n"
"北面墙上镶着一个闪光的轮回台，可以去往人间。西面是静室，它的门正");
    set_state_description( "oak_door_off", "关着。\n");
    set_state_description( "oak_door_on", "开着。\n");
    set_exits( ([
                 "east" : "example_room1.c",
                 "south" : "monster_room.c",
                 "west" : "quiet_room.c",
                 "north" : START,
                 "northwest" : "lava_room",
    ]) );
    set_objects( ([
        STAIRS : ({ "/domains/std/attic", "/domains/std/shop", 1}),
           "/domains/std/magic_torch" : 1,
    "/domains/std/large_oak_door" : ({ "west" }),
    ]) );
    set_default_exit( "穿墙而过会很疼耶，还是走正路的好。\n");
    door = present( "door");
    if( !door->query_closed())
    door->do_on_open();
}
int sound ()
{
  write ("南无阿弥陀佛... 谁在念经 ?!\n");
  return 1; // Let the parser know the listen was successfull
}
