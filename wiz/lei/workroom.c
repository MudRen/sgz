//  长街的家
#include <mudlib.h>
#include <ansi.h>
#include <sanguo.h>
inherit ROOM;
void setup(){
    set_area("xbv_area");
    set_light(50);
    set_brief(""+YEL+"长街的家"+NOR+"");
    set_long(
"屋内仅一把椅子，一个桌子和一张床。主人看来不喜繁琐。
桌子上放着几本书，主要是萧乾，王朔和张爱玲的作品。
墙上有一幅郑燮的“竹兰图”，还挂着一个相框(photo)。\n\n");
    set_exits( ([
        "tset" :  "/wiz/tset/workroom.c", 
        "benben" : "/wiz/benben/workroom.c",
        "out" :  FROOMPATH+"vzhu_lin.c"
    ]) );
    add_item("photo" , "一个相框",
        (["look" : "\n\n『一张合影』
 长街戴副眼镜，方脸大耳，没什么好看的。
那个女生皮肤雪白，大大的眼睛，一脸似笑非笑神秘莫测的样子。
不知道是长街的第几个干妹妹。\n\n"
       ]) );
}
string query_board()
{
        return "lei";
}
