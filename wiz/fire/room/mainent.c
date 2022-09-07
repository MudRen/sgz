#include <mudlib.h>
#include <sanguo.h>
inherit ROOM;
void setup(){
	string st1,st2,st3;
    set_area("my_home");
    set_light(50);
    set_brief("--烈火的小屋--");
st1=
"               这是烈火灾后重建的家
                                ~
                               ~~
                             _~_
                            |  |
            ________________|__|____
           /\\  \\  \\  \\  \\  \\  \\  \\  \\ 
         /    \\  \\  \\  \\  \\  \\  \\  \\  \\  
       /        \\  \\  \\  \\  \\  \\  \\  \\  \\
     /            \\  \\  \\  \\  \\  \\  \\  \\  \\
   /________________\\__\\__\\__\\__\\__\\__\\__\\__\\         
   |                 |       烈火的家       |\n";
st2=
"   |      _____      |   _   _______    _   |
   |     [__|__]     |  [_]  |      |  [_]  |  
   |     [__|__]     |  [_]  |      |  [_]  |                __
   |                 |  [_]  |      |  [_]  |               /  \\
   |                 |       |    @ |       |              /_  | <= Mail to 
   |                 |       |      |       |            ~/  \\ /    Fire\n";
st3=
"   |                 |       |      |       |       wW    |__|/
   |_________________|_______|______|_______|     WwW www  ||    wW
WW wwW                        \\_____\\_
                                \\_____\\\n";
    set_long(st1+st2+st3);
    set_exits( ([
        "enter" :  "/wiz/fire/workroom.c",
        "out" :  FROOMPATH+"vzhu_lin.c"
            ]) );
    add_item("postbox" , "一个邮筒",
        (["mail" : "\n\n想要写信给Fire吗？请用MUDMail。\n\n" 
        ]));
}                
