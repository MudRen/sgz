//  草庐
// vhall.c  by fire on Dec.10.1997
// vhall.c modified by row 12.97
#include <mudlib.h>
#include <ansi.h>
#include <sanguo.h>
inherit ROOM;
void setup(){
    set_area("huayin");
    set_light(50);
    set_brief(""+YEL+"草庐"+NOR+"");
    set_long(
"    这里是一间草庐，主人是这个村子里有名的智者--水镜先生。你
放眼看去，只见地上铺着张草席，摆有一几，上面安着一把瑶琴。一
个黑色的香炉放在屋角，整个房间都弥漫着清香。要去洛阳：
ask shuijing about luoyang, 新手输入: help starts。\n\n");

    set_exits( ([
        "west":"/a/huayin/cunzhongxin.c",
    ]) );
    set_objects( (["/sgdomain/obj/weapon/blade/dakandao.c" : 1]) );
    set_objects( (["/wiz/yuner/shuijing.c" : 1]) );
    set_objects(([M_BOARD : ({ 1,"草庐留言板", "city.huayin" }) ]) );
    /*add_item("note","一则书简",
        ([
"west":"/sgdomain/area/guan/huayin/cunzhongxin.c",
"read" : 
"\n\n---------------------------------------------------   
       
      欢迎你来到三国的世界。我们现在也只是刚刚开始。
但因为我们的MudLib比ES2的要新上近十年，所以我们有信
心也有条件做的比用ES2为基础的Muds更好。如果你想申请
当编辑，你会付出很多的时间。当您决定之后请发Email给
长街 s1414507@delta.ntu.edu.sg。
      
      请在信中写明您的编程经验，玩网络游戏的经验和您
关于三国网络游戏的看法。当然还有您的E-mail address。
如果您符合我们的条件我们会在一周内与您联络。另一方面
我们很欢迎有创意的点子，欢迎您多提意见。
    
      新玩家可输入“news”来尽快熟悉这里。
--------------------------------------------------\n\n"
        ]));*/
}
string query_board()
{
	return "city.huayin";
}
