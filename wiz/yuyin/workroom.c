#include <mudlib.h>
inherit INDOOR_ROOM;
void setup(){
    set_brief ("聂风的家");
    set_long (
      "这是聂风温暖的家。如果你有何指教的话，你大可以
   E-MAIL给聂风。(yu-yuyin@263.net)
    ");
    set_exits (([
        "east":"/sgdomain/area/guan/huayin/vfield.c"
    ]));
}
