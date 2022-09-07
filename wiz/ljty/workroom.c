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
    this_body()->simple_action("$N������¥�ݣ�������ȥ��\n");
        this_body()->move("/wiz/ljty/room/bedroom");
        this_body()->force_look();
        return 1;
    }
    this_body()->simple_action("$N��С�Ĵ�¥����ˤ��������ͷ��ײ�˸������\n");
    write("��Χ����һ��������������������˼����ĵ����ң���������������\n");

   return 1;
}
int do_go_xibian(){
    string tar_msg;
    string p_id;
    p_id=this_body()->query_userid();
    if(p_id=="ljty")
    {
        this_body()->simple_action(
"$Nһ���֣�ֻǰ��ߵ�ǽ���ֳ���һ��ͨ����$Nǰ��������Ӳ�ȥ�ˡ�\n");
        this_body()->move("/wiz/fire/room/vcenter.c");
        this_body()->force_look();
        return 1;
    }
        this_body()->simple_action("$Nһͷײ��ǽ�ϣ�ͷ��ײ�˸������\n");
    write("��Χ����һ���������������Ĵ�ǽ�������У����������У���\n");

   return 1;
}
int do_go_luoyang(){
    string tar_msg;
    string p_id;
    p_id=this_body()->query_userid();
    if(p_id=="ljty")
    {
        this_body()->simple_action(
"$Nһ���֣�ֻǰ��ߵ�ǽ���ֳ���һ��ͨ����$Nǰ���������Ӳ�ȥ�ˡ�\n");


        this_body()->move("/sgdomain/area/cities/luoyang/ly_center.c");
        this_body()->force_look();
        return 1;
    }
        this_body()->simple_action("$Nһͷײ��ǽ�ϣ�ͷ��ײ�˸������\n");
    write("��Χ����һ���������������Ĵ�ǽ�������У����������У���\n");

   return 1;
}
int do_go_left(){
    string p_id;
    p_id=this_body()->query_userid();
    if(p_id=="ljty")
    {
    this_body()->simple_action("$N�������ӵ���������ȥ�ˡ�\n");
        this_body()->move("/wiz/ljty/room/kitchen.c");
        this_body()->force_look();
        return 1;
    }
        this_body()->move("/wiz/ljty/room/kitchen.c");
        this_body()->force_look();
        this_body()->simple_action("\nһ�������$N˵����ӭ����ӭ���������Щ�����԰ɡ�
\n");
   return 1;
}

int do_go_right(){
    string p_id;
    p_id=this_body()->query_userid();
    if(p_id=="ljty")
    {
    this_body()->simple_action("$N���˿��ë������������ȥ��\n");
        this_body()->move("/wiz/ljty/room/bathroom");
        this_body()->force_look();
        return 1;
    }
    this_body()->simple_action("$N��С�Ļ���һ�ӣ�����������\n");
    write("��Χ����һ��������������������˼����ĵ������䣬��������������\n"
);
   return 1;
}
void setup(){
    set_area("ljty_area");
    set_light(50);
    set_brief(""+HIR+"--�˼����ĵĿ���--"+NOR+"");
    set_long(
"    �˼����ĵļҾ������ޣ���������ǰ��һ���ˣ���ǰ���Ǹ�
С����Ҳ�Ϳ����ڳ���ר�������ˣ�װ�޵ĸ����ûʣ����е㱩��
����ζ�������ˣ��������и���ܣ����Կ�����\n\n���(photo)\n");
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
    add_item("photo" , "һ�����",
        (["look" :  "
�˼����ĵ�Ů���ѣ����Ĳ��Ǻ�Ư�������ɣ�ͦ�����һ���Ϲ�Ů���ӡ�\n\n"
       ]) );
}
