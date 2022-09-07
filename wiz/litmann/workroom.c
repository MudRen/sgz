
#include <mudlib.h>
#include <ansi.h>

inherit ROOM;

void setup(){
    set_area("huayin");
    set_light(50);
    set_brief("%^H_MAGENTA%^乌江亭%^RESET%^");
    set_long("  

      胜败兵家不可期，包羞忍辱是男儿。
      江东子弟多才俊，卷土重来未可知。 
");
    set_exits( ([
        "out" :  FROOMPATH+"vzhu_lin.c",
        "wiz" :  "/domains/std/wizroom",
    ]) );
}
