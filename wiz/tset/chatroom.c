/* RoomMaker.c
** Coded by 苑璧@LIMA
** Code generated with RoomMaker v0.9.1 coded by Onyx@RedDragon
** Do not remove this header.
*/

#include <mudlib.h>
#include <ansi.h>

inherit ROOM;

int do_go_ting() {
    if(!wizardp(this_body())) {
	write("你还留在原地。\n");
	return 1;
    }
    return 0;
}

void setup(){
    set_area("chatting");
    set_light(25);
    set_brief("%^CYAN%^小憩聊天%^RESET%^");
    set_long("
一个宽宽敞敞的房间，放了好些舒服松软的大沙发，一坐上去，令人
觉得浑身舒畅，真是个歇息讲话的好地方。
\n\n");

    set_exits( ([
        "out" :  __DIR__"workroom.c",
	"ting" : __DIR__"ting.c",
    ]) );
    set_hidden_exits("ting");
    set_exit_msg("ting", "一阵轻风吹过，$N忽地化作枫叶，随风而去。\n");


    add_item("sofa", "沙发", "seat", "chair", ([
	   "look" : "几张舒服松软的大沙发。",
           "sit"  : "你舒舒服服地坐上沙发，翘起了二郎腿。",
        ]));
}
 
string query_board()
{
	return "board.zatan";
}
 
