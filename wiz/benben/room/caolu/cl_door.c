//  ����
// cl_door.c by benben
#include <mudlib.h>
#include <sanguo.h>
#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup(){
    set_area("caolu_area");
    set_light(50);
    set_brief(""+YEL+"����"+NOR+"");
    set_long(
"                                   /\\   
                              /\\  /  \\    /\\
                       /\\    /  \\/ ^  \\  /  \\  /\\
                      /  \\  /   /    ^ \\/ ^  \\/  \\
         /\\          /  ^ \\/^ ^/^  ^  ^ \\^   /^   \\
        / ^\\    /\\  / ^   /  ^/ ^ ^ ^   ^\\ ^/  ^^  \\
       /^   \\  / ^\\/ ^ ^�� ^ / ^��^    ^$ \\/ ^   ^  \\       *
      /  ^ ^ \\/^  ^\\ ^ ^ ^ ��^  ^   ^   _$__  ^   ^  \\     /|\\
     / ^ ^  ^ \\ ^  _\\___________________|  |_____^ ^  \\   /||o\\
    / ^^  ^ ^ ^\\  /______________________________\\ ^ ^ \\ /|o|||\\
   /  ^  ^^ ^ ^  /________________________________\\  ^  /|||||o|\\
  /^ ^  ^ ^^  ^    ||___|___||||||||||||___|__|||      /||o||||||\\
 / ^   ^   ^    ^  ||___|___||||||||||||___|__|||          | |
/ ^ ^ ^  ^  ^  ^   ||||||||||||||||||||||||||||||oooooooooo| |ooooooo
ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
    ��ǰ��һ�����СԺ�����������ţ���Լ���Կ���һ��ͯ����ɨ
�ء�\n\n");
    set_exits( ([
        "north" :  __DIR__+"cl_mdoor.c",
        "south" :  __DIR__+"cl_road2.c",
    ]) );
}
