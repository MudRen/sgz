// this room is created by initarea.c
inherit OUTDOOR_ROOM;
void setup() {
set_area("shangdang");
set_light(50);
set_brief("��վ");
set_long("");
set_objects( (["/sgdomain/yizhan/mafu.c" : 1 ]) );
// connection added by buzzer 
      set_exits(([ /* sizeof() == 1 */
  "south" : "/a/shangdang/sd_xiaochang.c",
  "north" : "/a/shangdang/sd_dongdajie.c",
]));

}
