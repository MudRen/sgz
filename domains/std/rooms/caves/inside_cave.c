// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

#include <mudlib.h>

inherit ROOM;

void setup() 
{
    string river = "��ᱻ��ˮ�����ġ�\n";

    set_area ("pirate");

    set_brief("��Ѩ");
    set_long("������������ݵ���һ��С���С�һ��С�������򶫻���������Ѩ���в���"
             "�������Ǿ޴������ʯ��ʯ���еĻ��ۼ���һ���γɰ���߸ߵ����ӡ�"
             "������һ��Сͨ�����Ҷ��������Ϸ����졣");
    set_light(0);
    set_exits( ([
        "south" : "low_crawl",
        "east"  : river,
        "west"  : river,
        "southeast" : "small_dock", 
        "north" : "north_cave",
        ]) );
    set_hidden_exits("east","west");
    set_default_exit ("�������û�����Եĳ��ڡ�\n");
    add_item("����ʯ", "ʯ��", "ʯ��",
              "����ʯ��ʯ��û��ʲô����ĵط���" );

    add_item("cavern", "cave", "��Ѩ", "������..." );

    add_item("river", 
             ([
                 "swim" : "�ں�ˮ����Ӿû��ʲô��",
                 "wade" : "��ˮ����Ҳû��ʲô��",
                 ]));


    set_objects( ([]) );
}
