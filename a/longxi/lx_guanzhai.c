// this room is created by buzzer.c
// driver is 花儿朵朵
// created date is Sat May  7 14:39:05 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("longxi");
set_light(50);
set_brief("%^YELLOW%^"+"官宅"+"%^RESET%^");
set_long("
    相传：春秋之时，郑国有一大夫，名叫颍考叔，在这里建造了一处宅院。
颍大夫一向勤政爱民。一到初春，颍大夫即开始陇西春耕，他看到天然的春耕圆，
愈耕心情俞高兴，情不自禁地唱起“耕耘乐”来。周围农夫们听到颍大夫唱歌，也
就跟着唱了起来。\n\n");
set_exits( ([
"east":"/a/longxi/lx_xiaoxiang3.c",
 ]));
}
