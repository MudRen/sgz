/* RoomMaker.c
** Coded by ������@����
** Code generated with RoomMaker v0.9.1 coded by Onyx@RedDragon
** Do not remove this header.
*/

#include <mudlib.h>
#include <ansi.h>
#include <sanguo.h>

inherit ROOM;

void setup(){
    set_light(50);
    set_brief("���ƾ�");
    set_long(
"      a@'           zzzzzzzzzz     ]@~~~~-@[    
  )@@~~~~-@                    @zzzzzzzd@[    
  ]@       @ezzzzzzzzzzzze@____@@_____  
  ]@@zzzzzzzd@[       .a@'         ]@~~@@~~~ 
  ]@       @[      .a@' )@@_    .@@]@~~~-@[ 
  ]@@zzzzzzzd@.z@C____@@L   d@']@_____]@[ 
  `@[~~~]@[    `~~~~~' `' `~~~~' 
�����˼��ɾ���һ���ŵİ������Ʈ���������ƻ�
�������У���һ��˵��������ζ���������ߵ�
͸���Ʋʣ����Լ��������ܿܿ��������������"
);
    set_exits( ([
"out" :  "/sgdomain/area/guan/huayin/vzhu_lin.c"
    ]) );
    set_objects( ([
    ]) );
}