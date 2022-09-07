// m_ask.c  by fire on Dec 23 1997
private string *answer_list = ({}); // list for answers
nomask void add_question(string question, string ans) 
{
        answer_list += ({ ({ question }) + ({ ans }) });
}
nomask string query_question(string ques)
{
    int i;
    string *q_id;
    string *ans_id;
    i = sizeof(answer_list);
    if (!i)
	return "--" ; //means no answer for this question
    while (i--)
        {
            q_id = ({ answer_list[i][0] });
            if(ques==q_id[0])
            {
		ans_id=({ answer_list[i][1] });
		return ans_id[0];
	    }
         }
	return "--";
}
nomask void ans_def_name(object who)
{
	string m_name;
	string m_zi;
	m_name=this_object()->query_name();
	m_zi=this_object()->query_sg_zi();
	if(m_zi)
	{
		m_zi="��"+m_zi;
	}
	else
	{
		m_zi="";
	}
this_object()->simple_action("$NЦ��˵����������"+m_name+m_zi+"������ָ�̣�\n")
;
	return;
}
nomask void ans_def_here(object who)
{
	string m_name;
	m_name=environment(this_body())->short();
this_object()->simple_action("$NЦ��˵������������"+m_name+"ϲ������𣿡�\n");
	return;
}
nomask void ans_def_rumors(object who)
{
this_object()->simple_action("$NЦ��˵��������ʱ��û�����ˣ�����Ҳû����ʲô���
�����Ϣ����\n");
	return;
}
nomask void ans_def_dunno(object who)
{
	string m_name;
	int p_tmp;
	p_tmp=random(5);
	switch(p_tmp)
	{
		case 0:
this_object()->targetted_action("$N��$t˵��������˵ʲô��������ѽ����\n",who);
			return;
		case 1:
this_object()->targetted_action("$N��$t˵���������ʵ�������ôһ����û��ѽ��
��\n",who);
			return;
		case 2:
this_object()->targetted_action("$N��$t˵�������������������ʱ��ˡ���\n",who);
			return;
		case 3:
this_object()->targetted_action("$N��$t�ɴ����۾������ţ���\n",who);
			return;
		case 4:
this_object()->targetted_action("$N��$t˵�������ܱ�Ǹ����Ҳ���������ʵ�����ѽ��
��\n",who);
			return;
	}
	return;
}
nomask void be_asked(object who, string matt)
{
	string ans_id;
	ans_id=query_question(matt);
	if(ans_id=="--")
	{
		switch(matt)
		{
			case "name":
				ans_def_name( who);
				return;
			case "here":
				ans_def_here(who);
				return;
			case "rumors":
				ans_def_rumors(who);
				return;
			default :
				ans_def_dunno(who);
				return;
		}
	}
	this_object()->special_answer(who,matt);
}
mixed direct_ask_liv_about_wrd(object liv, string item)
{
    return 1;
}
