#include <mudlib.h>
#include <sanguo.h>
inherit ROOM;
void setup(){
    set_area("xbv_area");
    set_light(50);
    set_brief("--С�����ĳ���--");
    set_long(
"���������ĳ���
���䣬ú���......���ϸ��Ÿ�ϴ��Ĳˣ������������һЩ
��˿����һ���Ҫ������...... :)
");
    set_exits( ([
        "out" :  "/wiz/benben/workroom.c"
    ]) );
set_objects( ([ "/wiz/benben/NPC/benben.c" : 1 ]) );
}                             
