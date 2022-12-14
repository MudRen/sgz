//  礼堂大门
// marry_gate.c 
#include <mudlib.h>
#include <sanguo.h>
#include <ansi.h>
inherit OUTDOOR_ROOM;

void setup(){
	set_light(50);
	set_brief(""+HIR+"礼堂大门"+NOR+"");
	set_long("
    这里是结婚礼堂的大门口，红漆装裹的大门透出一阵喜气。对面照壁
上贴着一张“%^H_RED%^喜喜%^RESET%^”字，红红的好不耀眼。门匾上“良缘堂”三个金字闪
着光芒，似乎在祝福着来此的情侣们。来来往往的人们也洋溢着满脸的红
光，笑得格外开心。两个喜仆左右立在门前，招呼着客人。你心里想：“
什么时候我才能成为这里的主角呢？” \n\n");
		
	set_exits( ([
	"enter" : __DIR__"marry_tang.c",
	]) );
	set_objects(([
	"/sgdomain/npc/marry_servant.c" : 2,
]) );
}
