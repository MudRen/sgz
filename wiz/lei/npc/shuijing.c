umors;news;shouming;money)");
			return;
		case "help" :
			this_object()->simple_action("$N΢΢һЦ��\n");
			this_object()->simple_action("$N˵������������Ұɣ����ҿ��ʶ��ˡ���\n"+
"Ҫ���˽��������磬���ȶ�������(news)��\n");
			return;
		case "news" :
			this_object()->targetted_action("$N��$TЦ����"+  
"��������������С�ֵ��Ļ���־�����ɳ�һ����ҵ��\n",who);
			return;
		case "rumors" :
		    this_object()->targetted_action(
"$N��$TС��˵������˵����������Ϸ������������������ʦ������Ȥ�Ļ��Ͽ�ȥ�����ɡ�\n",who);
			return;
			
		case "money" :
			p_money=who->query_amt_money("bank");
			p_money=p_money+who->query_all_con_money();
			if (p_money>50000)
			{
				this_object()->targetted_action(
"$N��$t˵������С�ֵܼ����ķᣬֻ�¿������������Ǯ�ɡ���\n",who);
				return;
			}
			p_id=this_body()->query_userid();
			if(member_array(p_id, name_list) != -1)
			{
				this_object()->targetted_action(
"$N��$t�ź���˵�������������ҵ���ȫ��С�ֵ��ˣ��� . . .��\n",who);
				return;
			}
			name_list+=({ p_id });
			ob=new(M_GOLD);
			ob->set_m_num(3);
			ob->move(who);
			this_object()->targetted_action(
"$N��$t˵�����������ҵ����Ҳ��Ե�ݡ���㱡��������С�ֵ���Ͱ�ҵ��\n",who);
			this_object()->targetted_action("$N��$tһЩ�ƽ�\n",who);
			return;
		case "shouming" :
			p_money=who->query_shouming();
			s_tmp=chinese_number(p_money);
			this_object()->simple_action("$N��ָ�����㡣\n");
			this_object()->targetted_action(
"$N��$tС��˵������С�ֵ����и�֮�ˣ���������"+s_tmp+"�ء���\n",who);
			return;
			
	}
}
