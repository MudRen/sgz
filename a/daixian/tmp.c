// this room is created by initarea.c
inherit OUTDOOR_ROOM;
void setup() {
set_area("daixian");
set_light(50);
set_brief("%^YELLOW%^"+"��վ"+"%^RESET%^");
set_long("");
set_objects( (["/sgdomain/yizhan/mafu.c" : 1 ]) );
// connection added by buzzer 
      set_exits(([
"north":"/a/daixian/dx_xijie.c",
 /* sizeof() == 1 */
]));

}
