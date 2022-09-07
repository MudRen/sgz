#include <mudlib.h>
#include <ansi.h>

inherit OBJ;
inherit M_GETTABLE;
inherit M_LIGHTABLE;
inherit M_VALUE;
int fun;
int lighten;
string *sname=({HIR"��ͯ��ϲ"NOR,HIY"��������"NOR,HIB"ԧ��˫��"NOR,
HIG"��������"NOR,HIW"��������"NOR,HIM"��������"NOR,});
string *chaois=({
   HIY"һ�������׷���ų�����գ��ֻ���׷�����ڿ��������������һ�Ų��õ�Ц����\n"NOR,
  HIY"��ɫ�Ĺ���������̻���ȥ������һ����ɫ������Ԥ���ż��顣\n"NOR,
HIR"���������顱�������̻�����������ҹ�գ���ʱ���춼�ǻ��ĺ���\n"NOR,
HIW"һ��СС���������ʣ�ը��ʱȴ�۶���ɢ������һ����˸�����ӣ�������һֱ�̵����ϡ�\n"NOR,
HIR"������𽻲������ͬʱը������֯������������ɫ���䡣\n"NOR,
HIR"���顱��һ��������ڸ߿շ��˿�������ɢ�Ļ𻨴���������ġ��Ұ��㡱�������֡�\n"NOR,
HIY"һ����ɫ�Ļ��������ɫ��ҹ�գ��ٱ��ѿ�����ɢ��ǧǧ�����СС�Ľ𻨡�\n"NOR,
	});
void delay();

void setup()
{	
	string name=sname[random(sizeof(sname))];
	set_id("firework", name);
	set_unit("ֻ");
	set_gettable(0);
	set_size(1);
	fun = random(10);
	lighten =0;
return;
}

string long()
{
	return "���˾�����������𣬷ŷſ���֪���ˡ�(light firework)\n";
}

int light()
{
	string who;
	int i;
	if(lighten)
	{write("���ڵ��ء�\n");
	return 0;
	}
	lighten = 1;
	who = this_body()->query_name();
	DELAY_D->delay_simple_action(this_body(),"$NС������Ŀ����̻�̽����ȥ���ȼ����\n",2);

	while(random(5)<2)
	{  DELAY_D->delay_simple_action(this_body(),"$N�ֲ�������������ôҲ�㲻��������\n",5);
		
	}
	
	DELAY_D->delay_simple_action(this_body(),"$N���������������۾���ƴ��һ�㣡���ˣ�\n",5);
	DELAY_D->delay_simple_action(this_body(),"$Nһ����շ�������������֮�⡣\n",6);
	
	DELAY_D->delay_simple_action(this_body(),"$N���ŵĿ���ȼ���е��̻�\n",8);
	write("\n");

	call_out("delay",12);
	return 1;
}


void delay()
{	string msg;

	remove_call_out("delay");
	switch(fun)
	{
	case 0:
	case 1:
	write(HIB"�����յ���ͷ��һ������ð��ȴʲôҲû������ԭ���Ǹ����ڡ�\n");
	break;
	case 2:
	write(HIR"�����յ����������һ�������顱��һ�����죬ը�˸����ô���\n");
	break;
	default:

write(HIR"�����յ���������ಡ���һ�����������̻������˵ĺȲ��г������\n");
	msg = chaois[random(sizeof(chaois))];
	tell(users(),"%^H_RED%^����䡿"+msg);
	break;
	}
	destruct(this_object());
}

		
