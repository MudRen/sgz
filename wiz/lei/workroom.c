//  ���ֵļ�
#include <mudlib.h>
#include <ansi.h>
#include <sanguo.h>
inherit ROOM;
void setup(){
    set_area("xbv_area");
    set_light(50);
    set_brief(""+YEL+"���ֵļ�"+NOR+"");
    set_long(
"���ڽ�һ�����ӣ�һ�����Ӻ�һ�Ŵ������˿�����ϲ������
�����Ϸ��ż����飬��Ҫ����Ǭ����˷���Ű������Ʒ��
ǽ����һ��֣�Ƶġ�����ͼ����������һ�����(photo)��\n\n");
    set_exits( ([
        "tset" :  "/wiz/tset/workroom.c", 
        "benben" : "/wiz/benben/workroom.c",
        "out" :  FROOMPATH+"vzhu_lin.c"
    ]) );
    add_item("photo" , "һ�����",
        (["look" : "\n\n��һ�ź�Ӱ��
 ���ִ����۾������������ûʲô�ÿ��ġ�
�Ǹ�Ů��Ƥ��ѩ�ף������۾���һ����Ц��Ц����Ī������ӡ�
��֪���ǳ��ֵĵڼ��������á�\n\n"
       ]) );
}
string query_board()
{
        return "lei";
}
