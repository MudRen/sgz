/* plain.c
** Coded by 玄冰@三国
** Code generated with RoomMaker v0.9.1 coded by Onyx@RedDragon
** Do not remove this header.
*/
#include <ansi.h>


inherit OUTDOOR_ROOM;

static string *sounds = ({ 
"小河传来「淙淙」的流水声。\n",
"树顶上不时传来几声不合时宜的「哇哇」的乌鸦叫声。\n",
"秋风中隐约传来一两声马嘶。\n",
"河对面的小木屋里好像有些人声。\n",
});
int sound() {
write(sounds[random(sizeof(sounds))]);
return 1; }

void setup(){
set_light(50);
    set_area("eastside");
set_long("    

    枯藤老树昏鸦，
    小桥流水人家。
    古道西风瘦马，
    夕阳西下，
    断肠人在天涯。\n\n");
    add_item("house", "小屋",
        ([ "look" : "一间古朴的小木屋，里面好像还有人居住，屋顶上飘出阵阵的炊烟。\n"]));
    add_item("river", "小河",
        ([ "look" : "小河在桥下静静地流着，极目望去，正流往那不知名的远方。",
        ]));
    add_item("sun", "夕阳",
        ([ "look" : "半轮%^H_RED%^红日%^RESET%^，正慢慢地向远山背后沉去。",
        ]));
    add_item("people", "人",
        ([ "look" : "
那人冷冷地看了你一眼，一副「我没惹你你该谢天谢地烧香还神了你还来惹我没事找事呀你」的样子。

只见那人：
手持%^B_ORANGE%^%^H_CYAN%^青龙偃月刀%^RESET%^(dragon-blade)。
头戴斗笠(douli)。
外套一身巫师工作服(workcloth)。
脚踏木屐(xmuji)。
身穿蓑衣(suoyi)。

你心里不禁一惊，那。。。那。。。不就是。。。
\n",
        ]));
        set_brief(""+YEL+"天净沙"+NOR+"");
    set_exits( ([
                 "caolu" : START,
        "bridge" : __DIR__+"bridge.c",
    ]) );
    set_objects( ([
        __DIR__"bridge" : 1,
    ]) );
}
string query_board()
{
    return "task.jimou";
}
