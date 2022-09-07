// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */
/*                                                             */
/*   This is an example room for the lima mudlib          */
/*                                                             */
/*   Created by zifnab@lima bean 7/24/95                         */
/*                                                             */
/****************************************************************/

#include <mudlib.h>
inherit ROOM;

mixed can_go_east()
{
    object env = environment( this_body());
    if( env->is_vehicle() && member_array( "car", env->query_id()) != -1)
    {
        return 1;
    }
    return "����ܳ���һ����������һЩ��\n";
}


void setup(){
    set_area("wiz_area");
    set_brief("��Ʒ����");
 
    set_long("����һ�� lima mudlib ����Ʒ���䡣���Ͻ���һ�������Ŀ��ף�������һ������ͨ����ʦ��������֪�Ǻιʣ�������һ��ϴ������\n"); 
 
    set_exits( ([
        "west" : "wizroom",
        "south" : "room2",
        "north" : "/domains/std/rooms/v_plains/4/7",
        "east" : "/domains/std/car_wash.c",
    ]) );
    set_exit_msg("east", "�������ϴ����ʱ��ˮ��ͷ��ʼ��ϴ���ĵ��̡�\n");
 
    add_item( "suit" , "armor" , "suit of armor" , "������������־ɣ�������������ʱ����Ķ����ƺ�������ս����ɱ��������");

    set_objects ( ([
                    "/domains/std/safe.c" : 1 
                    ]));
}

