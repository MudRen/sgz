//wiz/chun/room/dream.c
#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup(){
  set_area("westside");
  set_light(80);
  set_brief(""+HIC+"������"+NOR+"");
  set_long("
  ����һ���������滨���������СС��԰��ɢ����������������㣮
��ô�����ĵط���Ӧ�ã�ֻ�����ξ��в��аɣ�����\n\n");
  set_objects( ([
  "/wiz/chun/roses.c":1,
  ]) );
  set_exits( ([
        "enter" : "/wiz/chun/workroom.c",
  ]));
};

