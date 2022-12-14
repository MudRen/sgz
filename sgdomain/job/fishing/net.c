// net.c "渔网"
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
        
string * desc = ({      "一张崭新的渔网。",
                        "用过几回的渔网。",
                        "一张惯用的渔网。",
                        "渔网有些旧了。",
                        "一张旧渔网，有好些洞。",
                        "一张破旧的渔网，看起来是不能用了。",
                });
          
string * str1 = ({      "$N哗啦啦张开一张渔网，撒了开去。\n",
                        "$N将渔网张开，刷地一声抖了出去。\n",
                        "$N一边念叨着，一边将渔网撒了出去。\n",
                        "$N选定好一个地方，一把将渔网抖了出去。\n",
                        "$N把渔网撒了出去，静静地等着。\n",
                });
         
void setup() {
        set_id("net", "渔网");
        set_in_room_desc("一张渔网(net)");
        old = 0;
        thrown = 0;
        set_throwmsg("你哗啦啦张开一张渔网，撒了开去。\n");
        set_value(3);
        set_currency_type("silver");
        set_is_keeping(1);   
}

string long() { return desc[old]; }
 
mixed throw() {
        chance = 0;
        size = 0;
        if (thrown) return "渔网早就已经撒开了。\n";
        if (old > 4) return "渔网已经旧得不能用了。\n";
        if ( !present("pound", environment(this_body())) )
          return "这儿不是撒网的地方。\n";

        switch(DAY_D->query_season(1)) {
          case "spring" : size = 0 + random(3); chance = random(35); break;
                        // return "现在是养鱼季节，不能捕鱼。\n";
          case "winter" : size = 1 + random(3); chance = random(35); break;
                        // return "河上都结冰了，怎么撒网？\n";
          case "summer" : size = 2 + random(3); chance = random(45); break;
          case "autumn" : size = 3 + random(3); chance = random(55); break;
          default : size = 0; chance = -50; break;
        }
                        
        switch(DAY_D->query_string_hour(1)) {
          case "night" : return "深更半夜的，捕什么鱼？\n";  
          case "morning" : chance += 50; break;
          case "noon" : chance += 10; break;
          case "afternoon" : chance += 30; break;
        }
                        
        this_body()->simple_action(choice(str1));
	write("\n");
        this_body()->start_busy(30+random(60), "你正忙着捕鱼呢。");
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
          write("渔网还没撒出去呢。\n");
        else if ( this_body()->query_cur_hp() < 10 )
          write("你气力不足，捞不动渔网。\n");
        else if ( chance < 50 ) {
	  this_body()->set_cur_hp(this_body()->query_cur_hp() - 2);
          this_body()->simple_action("$N轻轻松松地捞起渔网。");
          write("结果失望地发现什么也没有。\n");
        }
        else if ( size < 3 ) {
          this_body()->set_cur_hp(this_body()->query_cur_hp() - 4);
          this_body()->simple_action("$N轻轻松松地捞起渔网。");
          write("只见到一条小鱼在网中跳来跳去。\n");
          ob = new(FISH);
          ob->modify(size);
          ob->move(this_body());
        }               
        else if ( size < 5 ) {
          this_body()->set_cur_hp(this_body()->query_cur_hp() - 6);
          this_body()->simple_action("$N大费精力地捞起渔网。");
          write("哇，一条大鱼！\n");
          ob = new(FISH);
          ob->modify(size);
          ob->move(this_body());
        }
        else {
          this_body()->set_cur_hp(this_body()->query_cur_hp() - 8);
          this_body()->simple_action("$N费了大半天工夫，好不容易捞起渔网。");
          write("好大一条鱼！难怪那么费劲。\n");
          ob = new(FISH);
          ob->modify(size);
          ob->move(this_body());
        }
        thrown = 0;
        return 1;
}
