//**************************************************************
//  ����ķ���
// vfire.c write by fire on 12.10.1997
#include <mudlib.h>
#include <ansi.h>
#include <sanguo.h>
inherit ROOM;
void setup(){
    set_light(50);
    set_brief("--����ķ���--");
    set_long("    ������䲻������ո�ס������������û̫��ʰ�á������滨
����һ���ʻ���\n\nһ�Ŵ�����(table)\n\n");
        add_item("table", "һ�Ŵ�����",
	([
"look" : "һ�Ŵ����ӣ�����ܿ����滨ƿ��һ���ʻ�(flower)��"
	    ]) );
    set_exits( ([
        "out" :  FROOMPATH+"/wiz/fire/workroom.c",
        "up" :  "/domains/std/magic_torch",
     "lily" : "/wiz/fire/room/private/lily.c",
]));
    add_item("flower" , "һ���ʻ�",
        ([
"smell" : "��ս������������ʻ���һ������Ʈ��������ú���������ˡ�\n",
"read" : "\n\n����˶��ʻ��ϵ�ֽ��������д�ţ�\n
���׸�����������
        ף����Զ���ᡢ������
              ���fire��\n\n",
"look" : "һ���������ʺã������Ǵ�·�߲ɵģ����滹��һ��ֽ����\n",
"get" : "�������ʻ������ţ��ַ��˻�ȥ��\n",
        ]) );
}
