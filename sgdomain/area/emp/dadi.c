//by ljty.
#include <mudlib.h>
#include <sanguo.h>
#include <ansi.h>
inherit INDOOR_ROOM;
void setup(){   
	set_light(50);
   set_brief(""+YEL+"���ǵ�"+NOR+"");
   set_long("
    ��������µƻ�Իͣ��������������Ƶ�վ����Χ�����ڸ���
��λ��ȼ����ʮ�ĸ���ڴֵĽ������Ƶĺ���ʮ����̫�ഹ�ֹ�
���ڽ�̽��Ե�����ǰ���㲻�Խ��ľ���һ����������Ҳ���Ҵ�
һ�£����ĵ�վ��һ�ԡ�
\n");
   set_exits( ([
             "goout" : __DIR__+"hugo.c",  
          "west" : __DIR__+"cl1",
            "east" : __DIR__+"cl4",
      "north" :"/wiz/row/rooms/wdd.c",

	]) );	
	set_objects( ([        "/sgdomain/event/ev_king/king.c" : 1,]));
set_enter_msg("dadian","$Nսս�������߽��˴�����һ������ͨ��һ�¹����˵��ϡ�\n\n");
    set_exit_msg("goout","\n$Nսս�����ص�ͷ���������Ų�����˳��˴��������һ������\n\n");
}
