//  ���ô���
// marry_gate.c 
#include <mudlib.h>
#include <sanguo.h>
#include <ansi.h>
inherit OUTDOOR_ROOM;

void setup(){
	set_light(50);
	set_brief(""+HIR+"���ô���"+NOR+"");
	set_long("
    �����ǽ�����õĴ��ſڣ�����װ���Ĵ���͸��һ��ϲ���������ձ�
������һ�š�%^H_RED%^ϲϲ%^RESET%^���֣����ĺò�ҫ�ۡ������ϡ���Ե�á�����������
�Ź�â���ƺ���ף�������˵������ǡ���������������Ҳ�����������ĺ�
�⣬Ц�ø��⿪�ġ�����ϲ������������ǰ���к��ſ��ˡ��������룺��
ʲôʱ���Ҳ��ܳ�Ϊ����������أ��� \n\n");
		
	set_exits( ([
	"enter" : __DIR__"marry_tang.c",
	]) );
	set_objects(([
	"/sgdomain/npc/marry_servant.c" : 2,
]) );
}
