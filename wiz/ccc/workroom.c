/* workroom.c
** Coded by ÀÏ´ó@Èı¹úÖ¾
** Code generated with RoomMaker v0.9.1 coded by Onyx@RedDragon
** Do not remove this header.
*/

#include <>

inherit ROOM;

void setup(){
    set_light(1);
    set_brief("ÀÏ´óµÄ»á¿ÍÌü");
    set_long(
" ±ğ¼±Âï£¡£¡£¡£¡£¡£
ÀÏ´óÊÇÌìÏÂÖªÃûµÄºÚ°ïÍ·Í·£¬×¨ÃÅÉ±ÈË·Å»ğ£¬¶¯Æ¶¼Ã¸»¡£ËùÒÔÂï...
µ±È»£¬Èç¹ûÄãÊÇÓĞÇ®ÈËµÄ»°£¬...."
);
    add_item("" , "");
    add_item("test?" , "????????");
    set_exits( ([
"enter" :  "/wiz/laoda/rooms/home",
"" :  "",
"out" :  "zhulin"
    ]) );
    set_objects( ([
"" :  0
    ]) );
}