// this room is created by buzzer.c
// driver is 花儿朵朵
// created date is Sat May  7 14:27:17 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("longxi");
set_light(50);
set_brief("%^YELLOW%^"+"衙门"+"%^RESET%^");
set_long("
    这里便是凉州重镇陇西的衙门，朱木大柱，青瓦白墙，异常醒目。
铜皮大门两边摆动放着两头张牙舞爪的石狮子。前面照例都有一个大鼓，
显然是供小民鸣冤用的。直看到去就可以看到知府做镇的大堂。\n\n");
set_exits( ([
"north":"/a/longxi/lx_datang.c",

"south":"/a/longxi/lx_qiandajie4.c",
 ]));
}
