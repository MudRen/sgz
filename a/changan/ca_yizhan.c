// this room is created by initarea.c
//inherit OUTDOOR_ROOM;
inherit BASE_ROOM;

void setup() {
set_area("changan");
set_light(50);
set_brief("%^YELLOW%^"+"≥§∞≤Ê‰’æ"+"%^RESET%^");
set_long("");
set_objects( (["/sgdomain/yizhan/mafu.c" : 1 ]) );
// connection added by buzzer 
      set_exits(([ /* sizeof() == 1 */
  "southeast" : "/a/changan/ca_dongdajie1.c",
]));

}
