// �ҵ�����ɽ��
// dd_xy.c
#include <mudlib.h>
#include <sanguo.h>
#include <ansi.h>
inherit OUTDOOR_ROOM;

void setup(){
    set_area("didao");
    set_light(50);
    set_brief(""+YEL+"ɽ��"+NOR+"");
    set_long(
@LONG 
  �����±���Ѫ�����

                   �ҵ�

	       ���������ڴ�
	        	
LONG
);
    set_exits( ([
	"west"      :  __DIR__+"dd_xy.c",
    ]) );
}


