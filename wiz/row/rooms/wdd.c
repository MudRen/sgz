//  �µµ�
// ly_czx.c 
#include <mudlib.h>
#include <sanguo.h>
#include <ansi.h>
inherit INDOOR_ROOM;

void setup(){
	set_light(50);
      set_brief("%^B_WHITE%^%^H_YELLOW%^�µµ�%^RESET%^");
	set_long("
    �������Ƚ��ǵ�˿����ѷɫ���Ǻ��׵�����گ���Թ���˵ĵ�
�����޴�Ļ������εض��𣬺��ص������񷶥������������������
�µ����ա������ļ�����Ѭ�㣬��������ζ�������������е�����
��͢�����һ��һ�ȣ����׵۶�Ҫ�ڴ˾��ķ��������ش����
�񣬲���������һ������ֻ�������ܵĻʵ���˵����˵�Ļ�����˭��
���������أ�\n\n");
	set_exits( ([
	"south" :"/sgdomain/area/emp/dadi.c",
	]) );
}
