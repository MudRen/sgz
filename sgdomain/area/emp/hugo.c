//by ljty.
#include <mudlib.h>
#include <sanguo.h>
#include <ansi.h>

inherit ROOM;

void setup()
{
   set_light(50);
   set_brief(""+YEL+"�ʹ����"+NOR+"");
   set_long("
    �����ǽ��ǵ�ǰ��һƬ�յأ���ǰ��һ��ͨ�����ŵİ���̨�ף�
���澫��ϸ�̵�����������֮�˵�������һ���ߴ����͵����־���
�岽һ�������������ܣ��ŵ������Ҳ���Ҵ�������ͷ�첽���˹�
ȥ���������ȥͨ��������վ�ͳ��������ġ�
\n\n");
   set_exits( ([
             "dadian" : __DIR__+"dadi.c",
             "goout" : "/a/changan/ca_czx.c",
	]) );
    set_exit_msg("goout","\n$N����ǰ�����Ļ���֮�£��ص��˳��������ġ�\n\n");
}
