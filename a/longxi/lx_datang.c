// this room is created by buzzer.c
// driver is 花儿朵朵
// created date is Sat May  7 14:27:51 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("longxi");
set_light(50);
set_brief("%^YELLOW%^"+"大堂"+"%^RESET%^");
set_long("
    这里是陇西的衙门大堂，正中一面明镜高悬的大匾，是各地
的衙门必备的家当。大堂的地上擦得逞亮却隐约能看到一点点的血痕，看
来是大堂用刑时留下的痕迹。两边各各一些肃静、回避的牌子，竟有些不
威自怒的感觉。\n\n");
set_exits( ([
"west":"/a/longxi/lx_laoyu.c",

"south":"/a/longxi/lx_yamen.c",
 ]));
}
