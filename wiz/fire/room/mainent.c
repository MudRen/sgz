#include <mudlib.h>
#include <sanguo.h>
inherit ROOM;
void setup(){
	string st1,st2,st3;
    set_area("my_home");
    set_light(50);
    set_brief("--�һ��С��--");
st1=
"               �����һ��ֺ��ؽ��ļ�
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
   |                 |       �һ�ļ�       |\n";
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
    add_item("postbox" , "һ����Ͳ",
        (["mail" : "\n\n��Ҫд�Ÿ�Fire������MUDMail��\n\n" 
        ]));
}                
