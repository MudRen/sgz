#include <mudlib.h>
#include <sanguo.h>
inherit ROOM;
void setup(){
    set_area("xbv_area");
    set_light(50);
    set_brief("--Ğ¡¶«Î÷µÄ¼Ò--");
    set_long(
"Ğ¡¶«Î÷ÊÇ×âÁËÈË¼ÒµÄ·¿×Ó×¡µÄ£¬×Ô¼ºÂò²»Æğ·¿£¬Ö»ºÃ×âÒ»¸ö¡££
·¿¼ä²»´ó£¿¿´ÆğÀ´ºÜ¼òµ¥£¬»¹ºÃ²»Ëã¼òÂª¡£Ò»ÕÅ´²£¬Ò»¸öÊá×±±
Ì¨£¬Ò»¸öĞ´×Ö×À£¬»¹ÓĞÒ»¸ö²è¼¸¡£Îİ×ÓÀïÓĞĞ©ÁèÂÒ£¿¿´À´Ğ¡¶«
Î÷²»Ì«»áÊÕÊ°¡£\n\n´°»§(window)\n\n");
    set_exits( ([
  "kitchen" : __DIR__+"room/kitchen.c",
        "bedroom" :  __DIR__+"room/bedroom.c",
        "out" :  FROOMPATH+"vzhu_lin.c"
    ]) );
    add_item("window" , "Ò»ÉÈÏòÄÏµÄ´°»§",
        (["look" : "\n\nÄÏÃæ±¾À´ÊÇ´óº££¿¿ÉÊÇÕâÃ´¶à¸ßÂ¥
°ÑÊ²Ã´¶¼ÕÚ×¡ÁË¡£ :( \n\n"
        ]));
}                             
