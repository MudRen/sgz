/* ground.c
** Coded by ����@����
** Code generated with RoomMaker v0.9.1 coded by Onyx@RedDragon
** Do not remove this header.
*/
#include <ansi.h>

inherit OUTDOOR_ROOM;

void setup(){
    set_light(50);
    set_area("westside");
        set_brief(""+YEL+"�յ�"+NOR+"");
    set_long("
    Сľ����ǰ��һСƬ�յأ���ΧһƬ���ף����ߴ��������ȡ���
С����ˮ�����Լ�ż����������ʱ�˵���ѻ��������ǰ��һ������
���ɵ�С�ӣ�һ��Сľ�ź�ب���ϡ�ľ�ݵ���Χ����Щ������������
Ҳ�ѽ�����ˡ���ǰ����һ�������Ѿ��߲������ӣ��Լ��������ӣ�
�������µ���ɹ���ܣ�ԭ����õ����ζ��Ѿ�������һ˿˿�����ơ�

%^H_BLUE%^��ɫ�ƺ��ѽ��ƻ裬��ߵ���ϼһƬ��졣%^RESET%^
\n\n"
);
    add_item("duilian", "����",
        ([ "look" : "

          ��        ��
          ϼ        ˮ
          ��        ��
          ��        ��
          ��        ��
          ��        һ
          ��        ɫ

\n\n",
        ]));
    set_exits( ([
        "house" : __DIR__+"workroom.c",
        "bridge" : __DIR__+"bridge.c",
    ]));
    set_enter_msg("goout","\nֻ����ľ�š�֨ѽ��һ����$N���˳�����\n\n");
    set_objects( ([
        __DIR__"bridge" : 1,
    ]) );
}
