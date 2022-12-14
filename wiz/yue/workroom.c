//**************************************************************
//  月神的房间
// vfire.c write by fire on 12.10.1997
#include <mudlib.h>
#include <ansi.h>
#include <sanguo.h>
inherit ROOM;
void setup(){
    set_light(50);
    set_brief("--月神的房间--");
    set_long("    这个房间不大，月神刚刚住近来。看来还没太收拾好。桌上面花
中有一束鲜花。\n\n一张大桌子(table)\n\n");
        add_item("table", "一张大桌子",
	([
"look" : "一张大桌子，下面很宽。上面花瓶中一束鲜花(flower)。"
	    ]) );
    set_exits( ([
        "out" :  FROOMPATH+"/wiz/fire/workroom.c",
        "up" :  "/domains/std/magic_torch",
     "lily" : "/wiz/fire/room/private/lily.c",
]));
    add_item("flower" , "一束鲜花",
        ([
"smell" : "你凑近闻了闻这束鲜花。一阵轻香飘来，你觉得好象变年轻了。\n",
"read" : "\n\n你读了读鲜花上的纸条。上面写着：\n
“献给美丽的月神。
        祝你永远年轻、美丽。
              你的fire。\n\n",
"look" : "一束美丽的鲜好，不象是从路边采的，上面还有一张纸条。\n",
"get" : "你拿起鲜花闻了闻，又放了回去。\n",
        ]) );
}
