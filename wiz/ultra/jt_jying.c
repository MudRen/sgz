// 街亭军营
// jt_jying.c
#include <mudlib.h>
#include <sanguo.h>
#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup(){
    set_area("jieting");
    set_light(50);
    set_brief(""+YEL+"军营"+NOR+"");
    set_long("  军营里旌旗鲜明，排列整齐。将士们精神抖擞，时刻保持着警惕。 
北面是帅帐和议事厅，时不时有军校出入，报告军情。
\n\n");
    set_exits( ([
        "south" :  __DIR__+"jt_area.c",
        "northwest" :  __DIR__+"jt_ysht.c",
        "northeast" :  __DIR__+"jt_shzhang.c",
    ]) );
}

