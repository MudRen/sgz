// this room is created by initarea.c
inherit OUTDOOR_ROOM;
void setup() {
set_area("wuling");
set_light(50);
set_brief("%^YELLOW%^"+"武陵驿站"+"%^RESET%^");
set_long("
    这里是武陵驿站,驿站是三国里最方便最快
捷的交通工具,驿站用的马就随便地放养在里面。一边站
着一个小伙子，看上去象是赶大车的，你如果想去什么地
方的话，可以问问他ask ma fu about 地方id(changan)。\n\n");
set_objects( (["/sgdomain/yizhan/mafu.c" : 1 ]) );
// connection added by buzzer 
      set_exits(([
 /* sizeof() == 1 */
  "north" : "/a/wuling/wl_dadao1.c",
]));

}
