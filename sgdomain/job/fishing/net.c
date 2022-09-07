// net.c "����"
#include <ansi.h>
#define FISH "/sgdomain/job/fishing/fish.c"

inherit OBJ;
inherit M_GETTABLE;
inherit M_THROWABLE; 
inherit M_VALUE;
 
private int old;
private int chance;
private int size;
private int thrown;
        
string * desc = ({      "һ��ո�µ�������",
                        "�ù����ص�������",
                        "һ�Ź��õ�������",
                        "������Щ���ˡ�",
                        "һ�ž��������к�Щ����",
                        "һ���ƾɵ��������������ǲ������ˡ�",
                });
          
string * str1 = ({      "$N�������ſ�һ�����������˿�ȥ��\n",
                        "$N�������ſ���ˢ��һ�����˳�ȥ��\n",
                        "$Nһ����߶�ţ�һ�߽��������˳�ȥ��\n",
                        "$Nѡ����һ���ط���һ�ѽ��������˳�ȥ��\n",
                        "$N���������˳�ȥ�������ص��š�\n",
                });
         
void setup() {
        set_id("net", "����");
        set_in_room_desc("һ������(net)");
        old = 0;
        thrown = 0;
        set_throwmsg("�㻩�����ſ�һ�����������˿�ȥ��\n");
        set_value(3);
        set_currency_type("silver");
        set_is_keeping(1);   
}

string long() { return desc[old]; }
 
mixed throw() {
        chance = 0;
        size = 0;
        if (thrown) return "��������Ѿ������ˡ�\n";
        if (old > 4) return "�����Ѿ��ɵò������ˡ�\n";
        if ( !present("pound", environment(this_body())) )
          return "������������ĵط���\n";

        switch(DAY_D->query_season(1)) {
          case "spring" : size = 0 + random(3); chance = random(35); break;
                        // return "���������㼾�ڣ����ܲ��㡣\n";
          case "winter" : size = 1 + random(3); chance = random(35); break;
                        // return "���϶�����ˣ���ô������\n";
          case "summer" : size = 2 + random(3); chance = random(45); break;
          case "autumn" : size = 3 + random(3); chance = random(55); break;
          default : size = 0; chance = -50; break;
        }
                        
        switch(DAY_D->query_string_hour(1)) {
          case "night" : return "�����ҹ�ģ���ʲô�㣿\n";  
          case "morning" : chance += 50; break;
          case "noon" : chance += 10; break;
          case "afternoon" : chance += 30; break;
        }
                        
        this_body()->simple_action(choice(str1));
	write("\n");
        this_body()->start_busy(30+random(60), "����æ�Ų����ء�");
        thrown = 1;
	old += random(2);

        switch (old) {
          case 0: set_value(1); set_currency_type("silver"); break;
          case 1: set_value(70); set_currency_type("coin"); break;
          case 2: set_value(50); set_currency_type("coin"); break;
          case 3: set_value(20); set_currency_type("coin"); break;
          case 4: set_value(5); set_currency_type("coin"); break;
          default: set_value(0); set_currency_type("coin"); break;
        }
	return 1;
}

int pull() {
        object ob;
        if ( !thrown )   
          write("������û����ȥ�ء�\n");
        else if ( this_body()->query_cur_hp() < 10 )
          write("���������㣬�̲���������\n");
        else if ( chance < 50 ) {
	  this_body()->set_cur_hp(this_body()->query_cur_hp() - 2);
          this_body()->simple_action("$N�������ɵ�����������");
          write("���ʧ���ط���ʲôҲû�С�\n");
        }
        else if ( size < 3 ) {
          this_body()->set_cur_hp(this_body()->query_cur_hp() - 4);
          this_body()->simple_action("$N�������ɵ�����������");
          write("ֻ����һ��С��������������ȥ��\n");
          ob = new(FISH);
          ob->modify(size);
          ob->move(this_body());
        }               
        else if ( size < 5 ) {
          this_body()->set_cur_hp(this_body()->query_cur_hp() - 6);
          this_body()->simple_action("$N��Ѿ���������������");
          write("�ۣ�һ�����㣡\n");
          ob = new(FISH);
          ob->modify(size);
          ob->move(this_body());
        }
        else {
          this_body()->set_cur_hp(this_body()->query_cur_hp() - 8);
          this_body()->simple_action("$N���˴���칤�򣬺ò���������������");
          write("�ô�һ���㣡�ѹ���ô�Ѿ���\n");
          ob = new(FISH);
          ob->modify(size);
          ob->move(this_body());
        }
        thrown = 0;
        return 1;
}
