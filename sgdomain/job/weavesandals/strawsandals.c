//strawsandals.c ��Ь�� by row
#include <sanguo.h>
#include <ansi.h>
#include <mudlib.h>
inherit OBJ;
inherit M_MERGEABLE;
inherit M_GETTABLE;
void setup()
{
merge_setup();
set_unit("ֻ");
set_id("caoxie di", YEL+"��Ь��"+NOR,);
add_id("di");
set_in_room_desc(YEL+"��Ь��"+NOR+"(caoxie di)");
set_long("�����÷��Ƶ�é�ݱ�֯���ɵ�Ь�ף�����ټ��������ۻ��Ϳ��Դ��ˡ�");
set_gettable(1);
set_is_keeping(1);
set_size(SMALL);
set_ori_size(SMALL);
}