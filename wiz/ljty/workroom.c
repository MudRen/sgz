// workroom.c wrote by ljty on 1.8.1998
#include <mudlib.h>
#include <sanguo.h>
#include <ansi.h>

inherit INDOOR_ROOM;
int do_go_up(){
    string p_id;
    p_id=this_body()->query_userid();
    if(p_id=="ljty")
    {
    this_body()->simple_action("$N登上了楼梯，向上走去。\n");
        this_body()->move("/wiz/ljty/room/bedroom");
        this_body()->force_look();
        return 1;
    }
    this_body()->simple_action("$N不小心从楼梯上摔了下来，头上撞了个大胞。\n");
    write("周围传来一阵回声，．．．那里是浪迹天涯的卧室，请留步。．．．\n");

   return 1;
}
int do_go_xibian(){
    string tar_msg;
    string p_id;
    p_id=this_body()->query_userid();
    if(p_id=="ljty")
    {
        this_body()->simple_action(
"$N一挥手，只前左边的墙上现出了一个通道。$N前往析汴村视察去了。\n");
        this_body()->move("/wiz/fire/room/vcenter.c");
        this_body()->force_look();
        return 1;
    }
        this_body()->simple_action("$N一头撞在墙上，头上撞了个大胞。\n");
    write("周围传来一阵回声，．．．你的穿墙术还不行．．．还不行．．\n");

   return 1;
}
int do_go_luoyang(){
    string tar_msg;
    string p_id;
    p_id=this_body()->query_userid();
    if(p_id=="ljty")
    {
        this_body()->simple_action(
"$N一挥手，只前左边的墙上现出了一个通道。$N前往洛阳城视察去了。\n");


        this_body()->move("/sgdomain/area/cities/luoyang/ly_center.c");
        this_body()->force_look();
        return 1;
    }
        this_body()->simple_action("$N一头撞在墙上，头上撞了个大胞。\n");
    write("周围传来一阵回声，．．．你的穿墙术还不行．．．还不行．．\n");

   return 1;
}
int do_go_left(){
    string p_id;
    p_id=this_body()->query_userid();
    if(p_id=="ljty")
    {
    this_body()->simple_action("$N挽起袖子到厨房做饭去了。\n");
        this_body()->move("/wiz/ljty/room/kitchen.c");
        this_body()->force_look();
        return 1;
    }
        this_body()->move("/wiz/ljty/room/kitchen.c");
        this_body()->force_look();
        this_body()->simple_action("\n一阵回声对$N说：欢迎，欢迎，请随便找些东西吃吧。
\n");
   return 1;
}

int do_go_right(){
    string p_id;
    p_id=this_body()->query_userid();
    if(p_id=="ljty")
    {
    this_body()->simple_action("$N拿了块白毛巾，向卫生间走去。\n");
        this_body()->move("/wiz/ljty/room/bathroom");
        this_body()->force_look();
        return 1;
    }
    this_body()->simple_action("$N不小心滑了一跤，半天起不来。\n");
    write("周围传来一阵回声，．．．那里是浪迹天涯的卫生间，请留步。．．．\n"
);
   return 1;
}
void setup(){
    set_area("ljty_area");
    set_light(50);
    set_brief(""+HIR+"--浪迹天涯的客厅--"+NOR+"");
    set_long(
"    浪迹天涯的家经过整修，己经与以前大不一样了，以前的那个
小屋子也就可以腾出来专做客厅了，装修的富丽堂皇，真有点暴发
户的味道。对了，桌子上有个相架，可以看看。\n\n相架(photo)\n");
    set_exits( ([
             "out"  :  FROOMPATH+"vzhu_lin.c",
             "luoyang" : "/sgdomain/area/cities/luoyang/ly_center.c",
             "xibian" : FROOMPATH+"vcenter.c",
             "changan" : "/sgdomain/area/cities/changan/ca_center.c",
             "up" : "/wiz/ljty/room/bedroom.c",
             "left" : "/wiz/ljty/room/kitchen.c",
             "right" : "/wiz/ljty/room/bathroom.c",
   ]) );
    set_hidden_exits("luoyang","changan","xibian");
    add_item("photo" , "一个相架",
        (["look" :  "
浪迹天涯的女朋友，长的不是很漂亮，还成，挺温柔的一个南国女孩子。\n\n"
       ]) );
}
