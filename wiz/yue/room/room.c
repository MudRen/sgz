//  �ӻ���
// ly_zahp.c 
#include <mudlib.h>
#include <sanguo.h>
#include <ansi.h>
inherit ROOM;
inherit STORE;
void setup(){
    set_area("ly_area");
    set_light(50);
    set_brief(""+YEL+"�ӻ���"+NOR+"");
    set_long(
"    �˴����������ϴ���ϵ�һ��С�ӻ��̡����Ӳ��󣬿�ǽ֧�Ÿ�
ľ�ܣ����ż������������£�ǽ�Ƕѷ��ż���Ƥ�䣬��������Ų���
���һ��С������Ÿ�С���㵧�Ź�̨�ϵĻҳ��������ӵ��ϰ���
������Ц�ؿ����㣬�����õĻ���������������Щ��������⡣��
С�ų�ȥ�����ϴ�֡�\n\n");
    set_exits( ([
        "west" :  __DIR__+"ly_ndj1.c",
    ]) );
}
