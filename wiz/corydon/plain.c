/* plain.c
** Coded by ����@����
** Code generated with RoomMaker v0.9.1 coded by Onyx@RedDragon
** Do not remove this header.
*/
#include <ansi.h>


inherit OUTDOOR_ROOM;

static string *sounds = ({ 
"С�Ӵ��������ȡ�����ˮ����\n",
"�����ϲ�ʱ������������ʱ�˵ġ����ۡ�����ѻ������\n",
"�������Լ����һ������˻��\n",
"�Ӷ����Сľ���������Щ������\n",
});
int sound() {
write(sounds[random(sizeof(sounds))]);
return 1; }

void setup(){
set_light(50);
    set_area("eastside");
set_long("    

    ����������ѻ��
    С����ˮ�˼ҡ�
    �ŵ���������
    Ϧ�����£�
    �ϳ��������ġ�\n\n");
    add_item("house", "С��",
        ([ "look" : "һ����ӵ�Сľ�ݣ�����������˾�ס���ݶ���Ʈ������Ĵ��̡�\n"]));
    add_item("river", "С��",
        ([ "look" : "С�������¾��������ţ���Ŀ��ȥ���������ǲ�֪����Զ����",
        ]));
    add_item("sun", "Ϧ��",
        ([ "look" : "����%^H_RED%^����%^RESET%^������������Զɽ�����ȥ��",
        ]));
    add_item("people", "��",
        ([ "look" : "
��������ؿ�����һ�ۣ�һ������û�������л��л�����㻹�����㻹������û������ѽ�㡹�����ӡ�

ֻ�����ˣ�
�ֳ�%^B_ORANGE%^%^H_CYAN%^�������µ�%^RESET%^(dragon-blade)��
ͷ������(douli)��
����һ����ʦ������(workcloth)��
��̤ľ��(xmuji)��
������(suoyi)��

�����ﲻ��һ�����ǡ������ǡ����������ǡ�����
\n",
        ]));
        set_brief(""+YEL+"�쾻ɳ"+NOR+"");
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
