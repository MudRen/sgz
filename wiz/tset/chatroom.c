/* RoomMaker.c
** Coded by Է�@LIMA
** Code generated with RoomMaker v0.9.1 coded by Onyx@RedDragon
** Do not remove this header.
*/

#include <mudlib.h>
#include <ansi.h>

inherit ROOM;

int do_go_ting() {
    if(!wizardp(this_body())) {
	write("�㻹����ԭ�ء�\n");
	return 1;
    }
    return 0;
}

void setup(){
    set_area("chatting");
    set_light(25);
    set_brief("%^CYAN%^С�����%^RESET%^");
    set_long("
һ��������ķ��䣬���˺�Щ�������Ĵ�ɳ����һ����ȥ������
���û����泩�����Ǹ�ЪϢ�����ĺõط���
\n\n");

    set_exits( ([
        "out" :  __DIR__"workroom.c",
	"ting" : __DIR__"ting.c",
    ]) );
    set_hidden_exits("ting");
    set_exit_msg("ting", "һ����紵����$N���ػ�����Ҷ������ȥ��\n");


    add_item("sofa", "ɳ��", "seat", "chair", ([
	   "look" : "�����������Ĵ�ɳ����",
           "sit"  : "���������������ɳ���������˶����ȡ�",
        ]));
}
 
string query_board()
{
	return "board.zatan";
}
 
