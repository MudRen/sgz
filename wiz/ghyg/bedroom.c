#include <ansi.h>

inherit INDOOR_ROOM;

void setup(){
    set_area("westside");
    set_light(50);
          set_brief(""+YEL+"Ʈѩ����Ϣ��"+NOR+"");
    set_long("
      ������Ʈѩ����Ϣ�ң�����Ƚϼ򵥣����������Գ�һ�ָ߹�����ʡ�
��������ʱ������ʹ����Ȼ����һ�ֳ羴�ĸо������ˣ����Ǹ������ˣ�
Ʈѩ��ϲ���˴�£���ģ������������ȥ��Ҫ���������ˣ����ܻ�ɱ��
��ġ�С�ĵ�á�
\n\n"
);
    set_exits( ([
              "east" : "/wiz/ghyg/workroom.c",
            "west" : "/a/huayin/venter.c",
    ]) );
    set_objects( ([
//   __DIR__"npc/piaox.c":1,
      ]) );
}
