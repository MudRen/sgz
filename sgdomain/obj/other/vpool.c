// vpool.c ������
inherit OBJ;
void setup()
{
  set_attached(1);
  set_unit("Ƭ");
  set_id("pool","����", "water","chitang");
  set_long("����һ����ͨ��С����������Ӿ���ǲ���");
}
int swim(string s)
{
	int p_hp,p_sjlev,p_sjexp;
	p_hp=this_body()-> query_cur_hp();
	p_sjlev=this_body()->query_sk_level("jbsj");
	p_sjexp=this_body()->query_sk_exp("jbsj");
	if (p_hp<15)
	{ write("��ô���˻����Σ���������ѽ��\n");
	this_body()->other_action("$N�����·�׼����������������ԥ�˰�����û����ȥ��\n");
	return 1;
	}
	write ( "��������������������һ�ᣬ���ϰ�ʱ���е������쳣�泩��\n");
	this_body()->other_action("$N�����˳��������������һ���������\n");
	this_body()->do_game_command("xixi");
	if((p_sjlev<30) && (p_sjexp<1000))
	{
	write("�����Ӿ��������ˡ�\n");
	this_body()->set_sg_skill("jbsj", p_sjlev, p_sjexp+10);
	}
	this_body()->set_cur_hp(p_hp-12);
	return 1;
}
         
