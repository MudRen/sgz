/* RoomMaker.c
** Coded by 白梨云@三国
** Code generated with RoomMaker v0.9.1 coded by Onyx@RedDragon
** Do not remove this header.
*/

#include <mudlib.h>
#include <ansi.h>
#include <sanguo.h>

inherit ROOM;

void setup(){
    set_light(50);
    set_brief("白云居");
    set_long(
"      a@'           zzzzzzzzzz     ]@~~~~-@[    
  )@@~~~~-@                    @zzzzzzzd@[    
  ]@       @ezzzzzzzzzzzze@____@@_____  
  ]@@zzzzzzzd@[       .a@'         ]@~~@@~~~ 
  ]@       @[      .a@' )@@_    .@@]@~~~-@[ 
  ]@@zzzzzzzd@.z@C____@@L   d@']@_____]@[ 
  `@[~~~]@[    `~~~~~' `' `~~~~' 
真是人间仙境，一团团的白云随风飘荡，似梦似欢
置身其中，有一种说不出的意味，令你神魂颠倒
透过云彩，可以见到下面的芸芸众生，三国纷争"
);
    set_exits( ([
"out" :  "/sgdomain/area/guan/huayin/vzhu_lin.c"
    ]) );
    set_objects( ([
    ]) );
}