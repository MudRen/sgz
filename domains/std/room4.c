// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

 /*
*** Example weather room  by Yaynu @ Lima Bean 160895
*/
 
inherit OUTDOOR_ROOM;
 
void setup()
{
set_area("wiz_area");
    set_brief("����Ȼ");
    set_long("����ĵط���������������ط���");
    set_weather(1);
    
    set_exits( ([
    "west": "room2",
    ]) );
}   


