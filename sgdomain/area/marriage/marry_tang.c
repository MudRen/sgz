// 良缘堂,marry_tang.c
#include <mudlib.h>
#include <sanguo.h>
#include <ansi.h>
inherit ROOM;
void setup(){
    set_light(1);
    set_brief(""+HIR+"良缘堂"+NOR+"");
    set_long("
    步入良缘堂，你好像感受到满天地的祝福都集中在了这里。大红
的地毯从门口一直铺到中堂，等待着下一对新人踏着它走向幸福之路。
四下里是一桌一桌的酒席，铺着整齐的桌布，摆着红烛，中央处还插
着一束象征着百年好合的百合花。近梁处是许多大红灯笼。最显眼的
是中堂画上的月老，笑眯眯的牵着根红线，祝福着一对的新人们。
\n\n");
    set_exits( ([
        "out" : __DIR__+"marry_gate.c",
	"enter" : __DIR__+"marry_fang.c",
    ]) );
   set_objects( ([
	"/sgdomain/npc/marry_yahuan.c" : 2,
]) );

}
