//  ������
// ly_czx.c 
#include <mudlib.h>
#include <sanguo.h>
#include <ansi.h>
inherit OUTDOOR_ROOM;

void setup(){
	set_area("luoyang");
	set_light(50);
        set_brief(""+YEL+"�����"+NOR+"");
	set_long("
    ������������ǵ����ģ�������ֽ����ڴˡ�һ��Ρ��ߴ����
¥������ǰ��������Щ���ơ�ÿ���峿�����������������ŵ�����
�����������Ĵ��С�·�ڳ�ˮ�����������˳����ϡ���˵���궭
׿���������ǣ����������յ�Ŭ���ؽ������յķ����ƺ��ֻ����ˡ�\n\n");

	set_room_state("valid_start");
	set_exits( ([
	"east" :  __DIR__+"ly_ddj1.c",
	"west" :  __DIR__+"ly_xdj1.c",
	"south" : __DIR__+"ly_ndj1.c",
	"north" : __DIR__+"ly_bdj1.c"
	]) );
    set_objects(([ "/wiz/row/guard/guard1" : ({ "stock-mage" }) ]));
//        set_objects(([M_BOARD : ({ 1,"�������԰�", "luoyang" }) ]) );
}
