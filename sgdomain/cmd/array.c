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
          write("用法错误，请用cmd help array查看详细帮助。\n");
          return;
        }
        if(!env->is_troop())
        {
           write("只有身在军中才能指挥放箭。\n");
           return ;
        }
        t_id=TROOP_D->get_char_troop(p_id);
        if (TROOP_D->get_troops(t_id, "conds"))
        { if (TROOP_D->get_troops(t_id, "conds")["confuse"])
          {
        write ("混乱中，无法攻击。\n");
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
        this_body()->simple_action("$N疾声高呼：弓箭手！放箭！！\n");
        WARAI_D->attack_target(t_id, arg, "array attack");
//        WARAI_D->do_array_attack(t_id,arg);
        return;
}
