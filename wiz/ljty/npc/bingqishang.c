//by ljty. ������.
#include <mudlib.h>
#define CHINESE_DA "sgdomain/modules/chinese_da.c"

inherit LIVING;
inherit M_ACTIONS;
inherit M_TRIGGERS;

void setup() {
        object jia;

        set_name("bingqishang", "������");
        add_id("bingqi", "shang", "boss");
        set_gender(1);
        set_proper_name("������");
        set_in_room_desc("������(bingqishang)");
        set_age(45);
        set_long("һ����ʮ��ͷ�ı�������\n");

        jia = new("/sgdomain/obj/cloth/torso/buyi.c");
        jia->move(this_object());
        jia->move(this_object());
        jia->do_wear();

        add_question("rumors","rumors");
        add_question("buy","buy");
}
void special_answer(object who, string matter)
{
        switch(matter)
        {
            case "rumors":
                    this_object()->targetted_action("$N�Ͽ�չ���˵��"+
                    "�����������ҵģ����򼸼����ֵı��аɡ���\n", who);
                    return;
            case "buy":
                    this_object()->targetted_action("$N���̽�������"+
                    "���ð���������ȿ�����������������ˡ���\n",
                    who);
                    return;
            default:
                    this_object()->targetted_action("$N�ܱ�Ǹ�ض�$T"+
                    "˵�������͹ٵ����⣬$sʵ����һ�㶼��֪������\n",
                    who);

                    return;
        }
}
