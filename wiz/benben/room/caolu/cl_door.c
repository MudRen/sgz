//  柴门
// cl_door.c by benben
#include <mudlib.h>
#include <sanguo.h>
#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup(){
    set_area("caolu_area");
    set_light(50);
    set_brief(""+YEL+"柴门"+NOR+"");
    set_long(
"                                   /\\   
                              /\\  /  \\    /\\
                       /\\    /  \\/ ^  \\  /  \\  /\\
                      /  \\  /   /    ^ \\/ ^  \\/  \\
         /\\          /  ^ \\/^ ^/^  ^  ^ \\^   /^   \\
        / ^\\    /\\  / ^   /  ^/ ^ ^ ^   ^\\ ^/  ^^  \\
       /^   \\  / ^\\/ ^ ^卧 ^ / ^龙^    ^$ \\/ ^   ^  \\       *
      /  ^ ^ \\/^  ^\\ ^ ^ ^ 岗^  ^   ^   _$__  ^   ^  \\     /|\\
     / ^ ^  ^ \\ ^  _\\___________________|  |_____^ ^  \\   /||o\\
    / ^^  ^ ^ ^\\  /______________________________\\ ^ ^ \\ /|o|||\\
   /  ^  ^^ ^ ^  /________________________________\\  ^  /|||||o|\\
  /^ ^  ^ ^^  ^    ||___|___||||||||||||___|__|||      /||o||||||\\
 / ^   ^   ^    ^  ||___|___||||||||||||___|__|||          | |
/ ^ ^ ^  ^  ^  ^   ||||||||||||||||||||||||||||||oooooooooo| |ooooooo
ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
    眼前是一个篱笆小院，柴门虚掩着，隐约可以看见一个童子在扫
地。\n\n");
    set_exits( ([
        "north" :  __DIR__+"cl_mdoor.c",
        "south" :  __DIR__+"cl_road2.c",
    ]) );
}
