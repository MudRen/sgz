// m_ask.c  by fire on Dec 23 1997
private string *answer_list = ({}); // list for answers
static private int p_first;
private mapping ask_list=([]);
private mapping asklist=([]); // this is used for extra ask from job
mixed set_asklist(string q, string p,mixed v)
{
	if(!asklist) asklist=([]);
	if(!asklist[q]) asklist[q]=([]);
	asklist[q][p]=v;
	return asklist[q];
}
mixed query_asklist(string q,string p)
{
	if((!q)||(q=="")) return asklist;
	if(!asklist) asklist=([]);
	if(!asklist[q]) return 0;
	return 	asklist[q][p];
}
mixed clear_asklist(string q)
{
	map_delete(asklist,q);
	return asklist;
}
mixed query_ask_str(string item)
{
   return ask_list[item];
}
void add_ask_str(string item,string sen)
{
     ask_list[item]=sen;
}
nomask void add_question(string question, string ans) 
{
if(p_first==0)
{
   p_first=1;
  answer_list=({});
}
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
        m_name=this_object()->query_chinese_id();
	m_zi=this_object()->query_sg_zi();
	if(m_zi)
	{
		m_zi="��"+m_zi;
	}
	else
	{
		m_zi="";
	}
this_object()->simple_action("$NЦ��˵��������"+m_name+m_zi+"������ָ�̣�\n")
;
	return;
}
nomask void ans_def_here(object who)
{
	string m_name;
	m_name=environment(this_body())->short();
this_object()->simple_action("$NЦ��˵����������"+m_name+"ϲ�������\n");
	return;
}
nomask void ans_def_all(object who)
{
    int sum,i;
	mapping ext_ans;
    string ans,*ext_list;
    string p_id=this_object()->query_id()[0];
    sum=sizeof(answer_list);
    if(!sum ||(objectp(this_object()->query_link())&&!CHAR_D->char_exist(p_id) ))
    {   this_object()->targetted_action(
"$N��$T���ͷ���˵������ʲô����֪���������ҡ�\n",who);
         return;
    }
    ans="$N��$T˵������֪��������Щ��������Щ�������á�\n";
    for(i=0;i<sum;++i)
      ans=ans+answer_list[i][0]+"\n";
	ext_ans=who->query_asklist();
	ext_list=keys(ext_ans);
	if(sizeof(ext_list))
	{
		foreach(string q in ext_list)
		{
			if(ext_ans[q]["target"]==p_id)
				ans+=q+"\n";
		}
	}

    this_object()->targetted_action(ans,who);
    return;
}
nomask void ans_def_rumors(object who)
{
this_object()->simple_action("$NЦ��˵������ʱ��û�����ˣ�����Ҳû����ʲô���µ���Ϣ��\n");
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
this_object()->targetted_action("$N��$T˵������˵ʲô��������ѽ��\n",who);
			return;
		case 1:
this_object()->targetted_action("$N��$T˵�������ʵ�������ôһ����û��ѽ��\n",who);
			return;
		case 2:
this_object()->targetted_action("$N��$T˵�����������������ʱ��ˡ�\n",who);
			return;
		case 3:
this_object()->targetted_action("$N��$T�ɴ����۾����ţ�\n",who);
			return;
		case 4:
this_object()->targetted_action("$N��$T˵�����ܱ�Ǹ����Ҳ���������ʵ�����ѽ��\n",who);
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
			case "all":
				ans_def_all(who);
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
