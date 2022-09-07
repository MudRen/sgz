// this room is created by initarea.c
inherit OUTDOOR_ROOM;
void setup() {
set_area("wuguan");
set_light(50);
set_brief("%^YELLOW%^"+"Œ‰πÿÊ‰’æ"+"%^RESET%^");
set_long("");
set_objects( (["/sgdomain/yizhan/mafu.c" : 1 ]) );
// connection added by buzzer 
      set_exits(([ /* sizeof() == 1 */
  "east" : "/a/wuguan/wg_huangtulu.c",
]));

}
