// this room is created by initarea.c
inherit OUTDOOR_ROOM;
void setup() {
set_area("longxi");
set_light(50);
set_brief("%^YELLOW%^"+"Â¤Î÷æäÕ¾"+"%^RESET%^");
set_long("");
set_objects( (["/sgdomain/yizhan/mafu.c" : 1 ]) );
// connection added by buzzer 
      set_exits(([ /* sizeof() == 1 */
  "west" : "/a/longxi/lx_dounanjie1.c",
]));

}
