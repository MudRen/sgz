#include <ansi.h>
inherit INDOOR_ROOM;
void setup(){
    set_area("westside");
    set_light(50);
        set_brief(""+YEL+"�����Сľ��"+NOR+"");
    write(sprintf("%O\n",file_name(previous_object(1))));
}
