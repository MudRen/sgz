#include <mudlib.h>
#include <ansi.h>
#include <sanguo.h>
inherit ROOM;
void setup()
{
    set_area("xbv_area");
    set_light(50);
    set_brief(""+HIR+"����ׯ"+HIY+"��Դ��"+NOR+"");
    set_long("
������  ��ĸ���ô�������Ƕ�Ū����С�ǡ�\n
���ǵĹ�â��̴٣������ϻ���ʲô���ܱ��������ã��Իͣ�
�����ǳ��ֵ�ʱ�򣬾��������㲻���������Ҳ�᲻ȥ���Ĺ�â��\n
�������µ�κ�����еĿ��գ��ֻ���˭֪���أ�\n\n");
    set_exits ((["out" :  "/wiz/shaoyng/workroom.c"]) );
    set_objects (([ "/wiz/shaoyng/npc/weiyan.c" : 1 ]));
}                             

