/* Do not remove the headers from this file! see /USAGE for more info. */
#include <mudlib.h>
inherit ROOM;
mixed can_go_up()
{
    if( environment( this_body())->is_vehicle()) return "��Ҫ���������С�\
n";
    return 1;
}
int do_go_up(){ 
    this_body()->do_game_command( "climb up stairs");
    return 1;
}
mixed can_go_down()
{
    if( environment( this_body())->is_vehicle()) return "��Ҫ���������С�\
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
    set_brief("��ʦ����");
    set_long("��ӭ���� LIMA����������ʦ�����ۺͷ����� LP MUD �� MudOS ��"
"���������̳����Ҳ����������ѯ��һЩ�й����� MUD �ļ��������⡣"
"���ں�����������֣�LIMA �������ĵط��д����ƣ���ӭ��Ҷ��������\n"
"        ʹ������ϵͳ������ news ���\n"
"        ʹ�����ѡ�������� menu ���\n"
"        ʹ���ʼ�ϵͳ������ mail ���\n"
"����ǽ������һ��������ֻ�̨������ȥ���˼䡣�����Ǿ��ң���������");
    set_state_description( "oak_door_off", "���š�\n");
    set_state_description( "oak_door_on", "���š�\n");
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
    set_default_exit( "��ǽ���������Ү����������·�ĺá�\n");
    door = present( "door");
    if( !door->query_closed())
    door->do_on_open();
}
int sound ()
{
  write ("���ް����ӷ�... ˭��� ?!\n");
  return 1; // Let the parser know the listen was successfull
}
