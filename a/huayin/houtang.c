// this room is created by buzzer.c
// driver is �������
// created date is Fri Apr 29 12:50:30 2011
#include <mudlib.h>
#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("huayin");
set_light(50);
set_brief("%^YELLOW%^"+"����"+"%^RESET%^");
set_long("
    ��������Ǻ����ˣ�����ܴ󣬵����õ÷ǳ��������־��£�Ҳ
������Ϊ��С��Ĺ뷿����¥�ϵ�Ե�ʡ�����ǽ����һ��ˮ��ľ�ķ�
�����������һ�ײ�ߣ����ӱ��������Ÿ߱�ľ�Ρ������԰���ֻС
�ɵ�ľ����������һֻϸ�ɻ�ƿ������Կ���һ����¥��ͨ���¥��\n\n");
set_exits( ([
"north":"/a/huayin/guifang.c",

"west":"/a/huayin/qianting.c",
 ]));
set_objects( (["/sgdomain/npc/zyuanwai.c" : 1]) );
}
