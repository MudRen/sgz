//  well.c
//  ��
//  created by tset 1/19/98
//  last updated by tset 1/19/98

#include <mudlib.h>
#include <ansi.h>

inherit OBJ;
inherit M_DRINK_CONTAINER;
inherit M_DRINKABLE;

int always_usable() { return 1; }       // drink without acquire

void setup() {
        set_id("well", "ˮ��", "jing");
        set_long("һ��ǳǳ��ˮ���������и�ˮư������ˮ��");
        set_in_room_desc("һ��ǳǳ��ˮ����\n");
        set_num_drinks(100);
        set_con("��ˮ");
   set_drink_action((: this_body()->simple_action("$N����Ҩ��һư"+
        query_con()+"����ཹ��һ�����ȵøɸɾ�����\n") :));
   set_last_drink_action( (: this_body()->simple_action(YEL+"$N����ˮư��"+
        "Ҩ�����һ��"+query_con()+"���ȵ�һ�ɶ�����\n"+NOR) :));
   set_finish_drink_action( (: write(RED+"ˮ���ݽ��ˡ�\n"+NOR) :));
}

