// ev_settle.c
// by fire on July 21, 1998
#define S_ACCEPT 1
#define S_ALREADY -1
#define S_OTHERCOUNTRY -2
#define S_OFFICERALREADY -3
#define S_POOR -4
#define S_MUSEUM -5
void create()
{
}
int check_settle(object who,string a_id)
{
	string y_id;
	string oa_id;
	y_id=(who->query_id())[0];
//        if(!(CHAR_D->char_exist(y_id)))
//                return S_ACCEPT;
	oa_id=CHAR_D->get_char(y_id,"area");
	if(oa_id==a_id)
		return S_ALREADY;
	if((CHAR_D->get_char(y_id,"ranklocal"))||(CHAR_D->get_char(y_id,"ranknation")))
	{
		if((CHAR_D->get_char(y_id,"nation"))!=(AREA_D->get_area(a_id,"nation")))
			return S_OTHERCOUNTRY;
		else
			return S_OFFICERALREADY;
	}
        if((who->query_sk_level("sk_wuli")<30)||
           (who->query_sk_level("sk_meili")<30)||
           (who->query_sk_level("sk_zhimou")<30))
           return S_POOR;
	if(MUSEUM_D->char_exist(y_id))
		return S_MUSEUM;
	return S_ACCEPT;
}
void run_settle(object officer, object who)
{
	string m_id,y_id;
	string m_area;
	m_id=(officer->query_id())[0];
	y_id=(who->query_id())[0];
	m_area=CHAR_D->get_char(m_id,"area");
	if(CHAR_D->char_exist(y_id))
	{
		CHAR_D->set_char(y_id,"area",m_area);
	}
	else
	{
		mapping m_tmp=([]);
		string *a_tmp;
		int i;
		CHAR_D->new_player_char(y_id);
		CHAR_D->set_char(y_id,"name",who->short());
		CHAR_D->set_char(y_id,"gender",who->query_gender());
		CHAR_D->set_char(y_id,"age",who->query_age());
		CHAR_D->set_char(y_id,"area",m_area);
		CHAR_D->set_char(y_id,"zi",who->query_sg_zi());
		CHAR_D->set_char(y_id,"reputation",who->query_shengwang_int());
		CHAR_D->set_char(y_id,"status",STATUS_ONLINE);
		//CHAR_D->set_char(y_id,"loyalty",50);	//�տ�ʼ���������ˣ���ʱ���ļ��ҳϡ�
		m_tmp["wuli"]=who->query_wuli_pure();
                m_tmp["zhimou"]=who->query_zhimou_pure();
		m_tmp["meili"]=who->query_meili_pure();
		m_tmp["rongmao"]=who->query_sg_rongmao();
                
		CHAR_D->set_char(y_id,"gift",m_tmp);
		a_tmp=who->query_self_skills();
		m_tmp=([]);
		for(i=0;i<sizeof(a_tmp);++i)
		{
			m_tmp[a_tmp[i]]=who->query_sk_level(a_tmp[i]);
		}
                CHAR_D->set_char(y_id,"skills",m_tmp);
                CHAR_D->set_char(y_id,"literate",who->query_literate());
        }
       CHANNEL_D->deliver_tell("rumor","system",
                sprintf("%s����Ͷ��%sȥ�ˡ�",CHAR_D->get_char(y_id,"name"),
                        AREA_D->get_area(m_area,"name")));	
}
void settle(object officer,object who,string ans)

{
	switch(ans)
	{
		case "yes":
		case "y":
		case "��":
officer->targetted_action("$N��$T����$R���Ժ��������̰��ס�\n",who);
			run_settle(officer,who);
	officer->clear_answer();
			return;
		default:
                        officer->targetted_action("$N��$T������Ȼ��ˣ���$R����������ɡ�\n",who);
	officer->clear_answer();
	return;
	}
}
void confirm_settle(object who, object officer)
{
	string y_id;
	string m_id;
	m_id=(officer->query_id())[0];
	y_id=(who->query_id())[0];
	officer->set_answer(y_id,  (:settle:) );
        officer->targetted_action
          ("$N��$TЦ������ȷ������\n",who);
write("ȷ���˾������� answer yes to "+m_id+"\n");
}
void ask_settle(object who, object officer)
{
        string m_id,y_id;
        string m_area;
		int p_check;
        m_id=(officer->query_id())[0];
        y_id=(who->query_id())[0];
		//printf("m_id = %s, y_id = %s\n",m_id,y_id);
        m_area=CHAR_D->get_char(m_id,"area");
        if((AREA_D->get_area(m_area,"leader"))!=m_id)
        {
            string m_title;
            m_title=OFFICER_D->query_rank_name(
            (OFFICER_D->query_area_officer_title(
             AREA_D->get_area(m_area,"level"),0,0))[0]);
              officer->targetted_action
("$N��$TЦ����$R���ڴ˾þӣ����$s��������������Ҫȥ�ʱ���"+m_title+"����\n",who);
             return;
        }
	p_check=check_settle(who,m_area);
	switch(p_check)
	{
		case S_ACCEPT:
              officer->targetted_action
             ("$N��$TЦ����$R�Ļ���־�������ڴˣ�ʵ�˱��ذ���֮�鸣Ҳ��\n",who);
			confirm_settle(who,officer);
			return;
		case S_MUSEUM:
              officer->targetted_action
             ("$N��$TЦ����$R�˵�ع����м��ص�ǰ�����͡��˴���С���²���$R����֮�ء�\n",who);
			return;
		case S_ALREADY:
              officer->targetted_action
             ("$N��$TЦ����$R����Ǻ�Ϳ�ˣ��������Ǳ������ˡ�\n",who);
			return;
		case S_OTHERCOUNTRY:
              officer->targetted_action
("$N��$TЦ����$R��"+COUNTRY_D->get_country(CHAR_D->get_char(y_id,"nation"),"name")+
"�߹٣��ڴ˵ؾ������¶��в���ɡ�\n",who);
			return;
		case S_OFFICERALREADY:
              officer->targetted_action
             ("$N��$TЦ�������»����ӳ����顣\n",who);
			return;
                case S_POOR:
              officer->targetted_action
("$N��$Tһ���۵�������$r����Ҫ�ڴ�ɧ�Ź���\n",who);
                        return;
	}
}

