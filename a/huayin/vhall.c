//  ��®
// vhall.c  by fire on Dec.10.1997
// vhall.c modified by row 12.97
#include <mudlib.h>
#include <ansi.h>
#include <sanguo.h>
inherit ROOM;
void setup(){
    set_area("huayin");
    set_light(50);
    set_brief(""+YEL+"��®"+NOR+"");
    set_long(
"    ������һ���®���������������������������--ˮ����������
���ۿ�ȥ��ֻ�����������Ų�ϯ������һ�������氲��һ�����١�һ
����ɫ����¯�����ݽǣ��������䶼���������㡣Ҫȥ������
ask shuijing about luoyang, ��������: help starts��\n\n");

    set_exits( ([
        "west":"/a/huayin/cunzhongxin.c",
    ]) );
    set_objects( (["/sgdomain/obj/weapon/blade/dakandao.c" : 1]) );
    set_objects( (["/wiz/yuner/shuijing.c" : 1]) );
    set_objects(([M_BOARD : ({ 1,"��®���԰�", "city.huayin" }) ]) );
    /*add_item("note","һ�����",
        ([
"west":"/sgdomain/area/guan/huayin/cunzhongxin.c",
"read" : 
"\n\n---------------------------------------------------   
       
      ��ӭ���������������硣��������Ҳֻ�Ǹոտ�ʼ��
����Ϊ���ǵ�MudLib��ES2��Ҫ���Ͻ�ʮ�꣬������������
��Ҳ���������ı���ES2Ϊ������Muds���á������������
���༭����Ḷ���ܶ��ʱ�䡣��������֮���뷢Email��
���� s1414507@delta.ntu.edu.sg��
      
      ��������д�����ı�̾��飬��������Ϸ�ľ������
��������������Ϸ�Ŀ�������Ȼ��������E-mail address��
������������ǵ��������ǻ���һ�����������硣��һ����
���Ǻܻ�ӭ�д���ĵ��ӣ���ӭ�����������
    
      ����ҿ����롰news����������Ϥ���
--------------------------------------------------\n\n"
        ]));*/
}
string query_board()
{
	return "city.huayin";
}
