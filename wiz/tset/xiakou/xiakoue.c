//  xiakoue.c
//  ÏÄ¿Ú³Ç¶«
//  created by tset 1/20/98
//  last updated by tset 1/20/98

#include <mudlib.h>

inherit OUTDOOR_ROOM;

void setup(){
        set_area("xiakou");
        set_light(20);
        set_brief("³Ç¶«");
        set_long("
ÕâÊÇÒ»ÌõÆÄÎªÈÈÄÖµÄ´ó½Ö£¬ºÃĞ©Ğ¡µê¶¼ÔÚÕâ¶ù¡£±±±ßÓĞ¸ö²Ö¿â£¬ÃÅ   é 
ÍâÓĞÎÀ±ø¿´ÊØ£¬¿´À´ÊÇ¸öÒª½ôµÄµØ·½¡£ÄÏ±ßÊ±Ê±´«À´Ğ©ºôºÈÉù¡£ 
\n\n");

  set_exits( ([
        "north" : __DIR__"liangcang",
        "south" : __DIR__"bingying",
        "east"  : __DIR__"eastgate",
        "west"  : __DIR__"xiakouc",
                ]) );
 
}
