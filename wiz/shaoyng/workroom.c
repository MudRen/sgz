#include <mudlib.h>
#include <ansi.h>
#include </wiz/fire/fire.h>

inherit ROOM;
void setup(){
    set_area("shaoyng_room");
    set_light(50);
    set_brief(""+HIR+"猪香亭"+NOR+"家的"+HIG+"桃园"+NOR+"");
    set_long(
"\n 滚滚长江东逝水，浪花淘尽英雄。
 是非成败转头空：青山依旧在，几度夕阳红。
 白发渔樵江渚上，惯看秋月春风。
 一壶浊酒喜相逢：古今多少事，都付笑谈中。\n
 建宁二年四月望日，帝御温德殿。方升座，殿角狂风骤起，
 只见一只老黑猪，从梁上飞将下来，蟠于椅上。。。。。。\n");
    set_exits( (["out" :  FROOMPATH+"vzhu_lin.c",
                 "dating" : __DIR__+"taoyuanting.c",
                 "houyuan" :  __DIR__+"houyuan.c",
                ]) );
}


