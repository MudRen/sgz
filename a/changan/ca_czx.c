// this room is created by buzzer.c
// driver is �������
// created date is Tue May  3 19:27:17 2011
#include <mudlib.h>
#include <ansi.h>
inherit OUTDOOR_ROOM;

void setup() {
set_area("changan");
set_light(50);
set_brief("%^YELLOW%^"+"������"+"%^RESET%^");
set_long("");
set_exits( ([
"south":"/a/changan/ca_nandajie.c",

"west":"/a/changan/ca_xdj1.c",

"east":"/a/changan/ca_dongdajie1",

 ]));
        set_objects( ([        "sgdomain/event/ev_king/kingguard.c" : 1,]));
set_objects(([M_BOARD : ({ 1,"�����ǳ��������Ĺ㳡���㳡��ͷ�������ƻֺ�Ļʹ���\n\nһ��ľ������"+"%^MAGENTA%^"+"�������԰�"+"%^RESET%^", "city.changan" }) ]) );
}
