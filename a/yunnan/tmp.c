// this room is created by initarea.c
inherit BASE_ROOM;
void setup() {
set_area("yunnan");
set_light(50);
set_brief("����");
set_long("");
set_objects( (["/sgdomain/yizhan/mafu.c" : 1 ]) );
// connection added by buzzer 
      set_exits(([ /* sizeof() == 1 */
  "west" : "/a/yunnan/yn_shibanlu1.c",
]));

}
