// this room is created by initarea.c
inherit OUTDOOR_ROOM;
void setup() {
set_area("chibi");
set_light(50);
set_brief("��վ");
set_long("");
set_objects( (["/sgdomain/yizhan/mafu.c" : 1 ]) );
// connection added by buzzer 
      set_exits(([ /* sizeof() == 1 */
  "north" : "/a/chibi/cb_xiaodao.c",
]));

}
