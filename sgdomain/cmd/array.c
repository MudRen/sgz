// array.c 
// by fire on Nov 1998
// used for player to attack by array in the war
void start(string arg)
{
        object env;
        string p_id;
        int t_id;
        mixed ret;
        p_id=this_body()->query_id()[0];
        env=environment(this_body());
        if(!arg||arg=="")
        {
          write("�÷���������cmd help array�鿴��ϸ������\n");
          return;
        }
        if(!env->is_troop())
        {
           write("ֻ�����ھ��в���ָ�ӷż���\n");
           return ;
        }
        t_id=TROOP_D->get_char_troop(p_id);
        if (TROOP_D->get_troops(t_id, "conds"))
        { if (TROOP_D->get_troops(t_id, "conds")["confuse"])
          {
        write ("�����У��޷�������\n");
        return;
        }
        }
	t_id=env->get_id();
        ret=WARAI_D->can_array_attack(t_id,arg);
        if(ret!=1)
        {
           write(ret);
           return;
        }
        this_body()->simple_action("$N�����ߺ��������֣��ż�����\n");
        WARAI_D->attack_target(t_id, arg, "array attack");
//        WARAI_D->do_array_attack(t_id,arg);
        return;
}
