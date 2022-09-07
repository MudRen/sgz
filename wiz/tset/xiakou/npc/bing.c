//  bing.c              
//  ʿ��
//  created by tset 1/16/98
//  last updated by tset 2/2/98
 
#include <mudlib.h>
 
inherit LIVING;
inherit M_ACTIONS;

inherit M_WANDER;
                        
private *name_list=({ });
string *query_channel_list() {
    return ({ "plyr_gossip" });
}
                        
void setup()
{
        int age = random(30); 
        object jia;
                        
        if(age < 16) { age += 15; }

        set_id("shi bing", "ʿ��", "shibing", "bing", "soldier");
        set_gender(1);
        set_proper_name("ʿ��");
        set_in_room_desc("ʿ��(shi bing)");
        set_age(age);
        set_long("һ��Ѳ�ߵ�ʿ�����������ز쿴���ķ���\n");
                        
        jia = clone_object("/sgdomain/obj/cloth/torso/buyi.c");
        jia->move(this_object());
        jia->do_wear();

        add_question("here","here" );
        add_question("name","name");
        add_question("rumors","rumors");
}

void special_answer(object who, string matter)
{
        switch(matter)
        {
                case "name":
                        this_object()->targetted_action("$N����$T"+
                        "һ�ۣ���û���������æ���ء���������\n", who);
                        return;
                case "here":  
                        this_object()->targetted_action("$N��ϸ�ش�����$T"+
                        "һ�������������ʲô�ط�����֪�����Ҹ����㣺"+
                        "������"+environment(this_body())->get_brief()+
                        "����\n", who);
                        return;
                case "rumors":
                        this_object()->targetted_action("$N���ͷ���˵��"+
                        "��$Tû�¸ɹ������Щ���£�һ��ȥ����\n", who);
                        return;
        }
}
