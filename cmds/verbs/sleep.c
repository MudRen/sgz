// sleep.c by fire on Jan 1999
inherit VERB_OB;

void wake(string p_id)
{
	object o=find_body(p_id);
	if(!objectp(o))
		return;
	o->simple_action("$N˯���ˣ���һ�������ѽ��\n");
	return;
}
void do_sleep()
{
   object env;
   int hp;
   int sleeptime=10+random(20);
   int food,drink;

   string p_id=this_body()->query_id()[0];
   env=environment(this_body());
   if(!env->is_bed())
   {
	   write("�����Ŵ���˯��\n");
	   return;
   }
   food=this_body()->query_sg_food();
   drink=this_body()->query_sg_drink();
   if(!food)
   {
	   write("��̫���ˣ�˯����ѽ��\n");
	   return;
   }
   if(!drink)
   {
	   write("��ڿʵ�������ʵ��������˯��\n");
	   return;
   }

   hp=this_body()->query_cur_max_hp();
   this_body()->set_cur_hp(hp);
   hp=this_body()->query_cur_max_mp();
   this_body()->set_cur_mp(hp);

   this_body()->start_busy(sleeptime, "�����������С�\n");
   this_body()->simple_action("$Nһͷ�������ϣ�������˯������\n");
   call_out("wake",sleeptime+1,p_id);
}
array query_verb_info()
{
    return ({ ({ ""}) });
}


