// this room is created by initarea.c
inherit INDOOR_ROOM;
void setup() {
set_area("huayin");
set_light(50);
set_brief("%^YELLOW%^"+"华阴驿站"+"%^RESET%^");
set_long("
    驿站是一间简陋的用茅草和木条搭起来的棚棚，棚下用粗粗的竹
子围起，权且作为马栏，驿站用的马就随便地放养在里面。一边站着
一个小伙子，看上去象是赶大车的，你如果想去什么地方的话，可以
问问他。\n\n");
set_exits( ([
"west":"/a/huayin/nancunkou.c",
 ]));
set_objects( (["/sgdomain/yizhan/mafu.c" : 1]) );
set_objects( (["/wiz/ljty/npc/mafu.c" : 1]) );
}
