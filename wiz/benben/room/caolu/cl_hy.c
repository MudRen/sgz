//  ��Ժ
// cl_hy.c by benben
#include <mudlib.h>
#include <sanguo.h>
#include <ansi.h>
inherit ROOM;
void setup(){
    set_area("caolu_area");
    set_light(50);
    set_brief(""+YEL+"��Ժ"+NOR+"");
    set_long("           ____
         _/    `--_ 
        /__/ _-- \\ \\ 
       //   /     \\ )     W     Ww   WW  wWWWWw       WwWW w
 wwW wW\\_/_________/ wwWW   WW WW www  wwwWWWw WWW       W
   WwW    (stone)    WwWww wwwWWWWw wWWWWww WWWWwWWWwWWWw WWWWwWw

    ��Ժ��һ��յ�,�ݵ����п�ʯͷ��\n\n");
    set_exits( ([
        "south" :  __DIR__+"cl_ht.c",
    ]) );
}
