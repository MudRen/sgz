// ev_learnskills.c
// by fire on Aug 16, 1998
// this is used to handle learn skills from other char
string subject_name(string matt)
{
	switch(matt)
	{
		case "bfxy":
			return "�ñ�֮��";
		case "zgxy":
			return "�ι�֮��";
		case "wxxy":
			return "��ѧ֮��";
		default:
			return "�Ա����";
	}
}
string subject_title(string matt)
{
	switch(matt)
	{
		case "bfxy":
			return "sk_zhimou";
		case "zgxy":
			return "sk_meili";
		case "wxxy":
			return "sk_wuli";
		default:
			return matt;
	}
}
void learn_skill(object student,string skill)
{
	int mas_level;
	string p_id;
	string p_st;
	int res;
	p_id=student->query_id()[0];
        mas_level=CHAR_D->get_skill(p_id,skill)+1;
	res=LEARNCHECK_D->check_can_learn_skills(skill,mas_level);
	switch(res)
	{
		case TOO_TIRED:
                        student->simple_action("$N���˰��죬�˯�����۾����������ˡ�\n");
			return;
		case CAN_LEARN:
	                p_st=SG_SKILL_D->query_get(skill);
	                student->simple_action(p_st);
			return;
                case LESS_EXP:
                        student->simple_action("$N���˰��죬ȴ������������һ�㣬ʲôҲû��������\n");
			return;
		case LESS_GIFT_MEILI:
		case LESS_GIFT_ZHIMOU:
		case LESS_GIFT_WULI:
		case LESS_GIFT:
                        student->simple_action("$N���˰��죬����������ȴ�ּǲ�ס��Ҳ�����츳���㡣\n");
			return;
		case LESS_LITERATE:
                        student->simple_action("$N���˰��죬����������ȴ�ּǲ�ס��Ҳ������ѧ����������\n");
			return;
	        default :
tell_user("fire",sprintf("the return is %O\n",res));
        	        write("��֪Ϊʲô��ѧ���ᣬ������ʦ�ɡ�\n");
			return;
	}
}
void ask_skills(object student,object master,string matt)
{
	string s_id,m_id;
	string p_nation;
	string sub,tit;
	sub=subject_name(matt);
	tit=subject_title(matt);
	s_id=(student->query_id())[0];
	m_id=(master->query_id())[0];
	p_nation=CHAR_D->get_char(s_id,"nation");
	
	if(!p_nation)
	{
		master->targetted_action
("$N��$Tҡͷ����$m$R�ƺ����������к��¶���֮������"+sub+
"�ҿ��Ͳ���ѧ�˰ɡ�\n",student);
		return;
	}
	if(p_nation!=CHAR_D->get_char(m_id,"nation"))
	{
		master->targetted_action
("$N��$Tҡͷ����$m$R��"+COUNTRY_D->get_country(p_nation,"name")+
"�߹٣������"+sub+"���ǲ����ഫ������\n",student);
		return;
	}
	if((CHAR_D->get_skill(s_id,tit))>=(CHAR_D->get_skill(m_id,tit)))
	{
		master->targetted_action
("$N��$TЦ����$m$c�αع�ǫ�����"+sub+"�Ѳ�����$C���ˡ�\n",student);
		return;
	}
	master->targetted_action
("$N��$TЦ����$m$c��������$C�Ҳ�ѧ��ǳ����һͬ̽��̽����"+sub+"�ɡ�\n",student);
        master->targetted_action("$N��$T�����һ��"+sub+"��\n",student);
	call_out("learn_skill",random(3)+1,student,tit);
}
