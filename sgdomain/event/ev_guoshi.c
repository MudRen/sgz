// ev_guoshi.c
// by Suicide on July 29, 2000

#define   SHOW_VOTE_NAME   1 
private   mapping vote_type = ([]);            //����ͶƱ�����ͣ�<������>:<ͶƱ��>        

mixed can_be_guoshi(string p_id)
{
if(CHAR_D->get_char(p_id,"loyalty")<90) 
   return "�ҳ϶Ȳ�����$s��ô��������";
if(CHAR_D->get_char(p_id,"reputation")<10000) 
   return "���������������Է���";
if(CHAR_D->get_skill(p_id,"sk_meili")<50) 
   return "�ι���������$R���ܷ���";
if(CHAR_D->get_char(p_id,"nationcontribution")<4000) 
   return "���ҹ��ײ����������Է���";
return 1;
}

void vote(object officer,object who,string ans)
{int vote_id,i_ans;
 string y_id,m_id,na;
 m_id = (officer->query_id())[0];
 y_id=(who->query_id())[0];
 na = CHAR_D->get_char(m_id,"nation");
 vote_id = VOTE_D->get_special_vote(na,vote_type[na])[0];
 switch(ans)
  {
  case "1" :
  case "2" :
  case "3" :
    {
    sscanf(ans,"%d",i_ans);
    VOTE_D->set_vote(vote_id,i_ans,y_id);
    officer->targetted_action("$N��$T����$R���������֪���ˣ������°ɣ��ù����Լ��ú����롣\n",who);
    officer->clear_answer();
    break;
    }     	
  default:
    officer->targetted_action("$N��$T����$R����������е�����������Ȼ��ˣ������������ɡ�\n",who);
    officer->clear_answer();
  return;
  }
}


void new_guoshi_vote(object officer,object who,string ans)
{int vote_id,i_ans;
 string y_id,m_id,na,gs;
 mixed result;
 if (ans=="yes"||ans=="Yes")
 {
 m_id = (officer->query_id())[0];
 y_id=(who->query_id())[0];
 na = CHAR_D->get_char(m_id,"nation");
 gs=COUNTRY_D->get_country(na,"gs");
 if (vote_type[na]=="dismiss")
{
 who->targetted_action(
 "%^CYAN%^$N��$T�������£����۹�ʦ�ᵳӪ˽�����������������������Ϊ�أ�������ְ��%^RESET%^\n",officer);
 
 VOTE_D->add_special_vote(na,"dismiss","������˷�ӳ��ʦ"+CHAR_D->get_char(gs,"name")
 +"("+y_id+")�ᵳӪ˽���������񣬲�֪�����к��������\n",3,y_id);   
 }
 else
 {
 who->targetted_action(
"%^CYAN%^$N��$TЦ����$s����Ϊ���¶��������ҹ�������������̫�ظ���Ϊ������������ǣ�Ϊ��һ\n"+
 "        ͳ���٣�׳���ҹ���"+"��$R�������Թ�ʦְ֮��Լ����·̫�أ���֪$R������Σ�%^RESET%^\n",officer);
 
 if (stringp(result=can_be_guoshi(y_id)))
    {officer->targetted_action
     ("$N��$TЦ��������"+result+"�������Ȼ�ȥ�ɣ�\n",who);
     return;
    }
    
 officer->targetted_action(
"$N��$TЦ��������²ż汸���������Σ�����$s���ú͸�·̫���������飬��������������ʦְ֮��\n",who);
 VOTE_D->add_special_vote(na,"elect",CHAR_D->get_char(y_id,"name")+"("+y_id+
 ")ǰ�����Լ�Ϊ��ʦ�����˿��书��������ְ֮����֪��λ����������Σ�\n",3,y_id);   
}

 CHAR_D->set_char(y_id,"candidate",1);  //����������ԣ���ֹ�����ʦ�����϶���
                                        //����Լ���ʹ����������ԭNPC���Ĺ�ʦ
                                        //��pos�Ķ���codeǰ�жϴ�����
 vote_id = VOTE_D->get_special_vote(na,vote_type[na])[0];
 VOTE_D->add_selectitem(vote_id,({"(1) ͬ��","(2) ��ͬ��","(3) ��Ȩ"}),0,0);
 VOTE_D->set_vote(vote_id,1,y_id);
}
else
{
   officer->targetted_action("$N��$T����$Rԭ������Ϊ���¶������Ǿ����ɡ�\n",who);
   officer->clear_answer();
}
}


void confirm_guoshi_vote(object who, object officer )
{
	string y_id;
	string m_id;
	m_id=(officer->query_id())[0];
	y_id=(who->query_id())[0];
	officer->set_answer(y_id,  (:vote:) );
        officer->targetted_action
          ("$N��$TЦ������ȷ������\n",who);
write("ȷ���˾������� answer <ѡ��> to "+m_id+"\n");
}


void confirm_if_new_guoshi_vote(object who, object officer ,string type)
{
        string y_id;
	string m_id;
	m_id=(officer->query_id())[0];
	y_id=(who->query_id())[0];
	officer->set_answer(y_id,  (:new_guoshi_vote:) );
	if (type == "dismiss")
        {officer->targetted_action
          ("%^CYAN%^$N��$TЦ���������ǲ��������������ڵĹ�ʦ��%^RESET%^\n",who);
         write("ȷ���˾������� answer yes  to "+m_id+"\n");
        }
        else
        {officer->targetted_action
          ("%^CYAN%^$N��$TЦ������֪�����Ƿ�����Ȥ����ʦ����˷��ǰ���%^RESET%^\n",who);
         write("ȷ���˾������� answer yes  to "+m_id+"\n");
        }
}

mixed can_ask(string m_id,string y_id,string y_area)
{
return "$N��$T��Ȼ����������ǰ���ż�թС�����Թ�ʦ���𣬽�����Ҷ�ι��Ƽ����������Ժ����ݵ�����!\n"; //2001.4.13
 if((CHAR_D->get_char(m_id,"nation"))!=m_id)
       return
"$N��$TЦ������ô��Ҫ�Ĺ��Ҵ���$s�Ҳ�̫�����$R�㻹��ȥ�������ɡ�\n";
 if((CHAR_D->get_char(m_id,"type"))==TYPE_PLAYER)
       return
"$N��$TЦ��������һ�о������¹��˻�Ӧ��������������Ҫ��ʦЭ����\n";
 if((CHAR_D->get_char(m_id,"nation"))!=(CHAR_D->get_char(y_id,"nation")))
       return
"$N��$TЦ�����������������������֣��ٲ����Ļ������˶�Ҫ����ץ����Ρ�\n";

 if ((AREA_D->get_area(y_area,"leader"))!=y_id)
       return
"$N��$Tŭ������ô��Ҫ�Ĺ��Ҵ��£�ƾ�����ݻ��岻���죬������̫���������ɡ�\n";
 if (CHAR_D->get_char(y_id,"grant"))
       return        
"$N��$TЦ��������ֻ����ʱ̫�أ�����������������̫���������ɡ�\n";
 return 1;
}


void ask_guoshi(object who, object officer)
{
        string m_id,y_id,na,vote_id;
        string y_area,gs;
	int i;
	mixed result;
	mapping vote;
	m_id=(officer->query_id())[0];
        y_id=(who->query_id())[0];
        y_area=CHAR_D->get_char(y_id,"area");
        na = CHAR_D->get_char(m_id,"nation");
        if (stringp(result=can_ask(m_id,y_id,y_area)))
           {
            officer->targetted_action(result,who);
            return;
           }
        
        if (gs=COUNTRY_D->get_country(na,"gs")) //����Ѿ��й�ʦ
           vote_type[na] = "dismiss";
        else
           vote_type[na] = "elect";
           
        if (!VOTE_D->get_special_vote(na,vote_type[na])) //���������ͶƱ  
           {
           if (vote_type[na]=="dismiss")
             officer->targetted_action(
"$N��$TЦ�����������ڵĹ�ʦ��"+CHAR_D->get_char(gs,"name")+"("+gs+")���ѵ���������������?\n",who);
           else
             officer->targetted_action(
"%^CYAN%^$N��$TЦ���������������ã�$s����Ϊ��ʦ���������Խ��ÿ����������顣%^RESET%^\n",who);
           confirm_if_new_guoshi_vote(who,officer,vote_type[na]);
           return;
           }
        else
          {
           vote_id = VOTE_D->get_special_vote(na,vote_type[na])[0];
     	   printf(VOTE_D->get_special_vote(na,vote_type[na])[1]);
           VOTE_D->show_vote_result(vote_id);
           vote = VOTE_D->get_vote_result(vote_id);
           if (SHOW_VOTE_NAME){
     	   printf("\n\n%%^CYAN%%^�޳��� : ");
     	   for (i=0;i<sizeof(vote[1]);i++)
         	printf("%%^CYAN%%^%s ",CHAR_D->get_char(vote[1][i],"name"));
           printf("%%^RESET%%^\n");
           printf("%%^CYAN%%^������ : ");
     	   for (i=0;i<sizeof(vote[2]);i++)
         	printf("%%^CYAN%%^%s ",CHAR_D->get_char(vote[2][i],"name"));
           printf("%%^RESET%%^\n");
           printf("%%^CYAN%%^��Ȩ�� : ");
           for (i=0;i<sizeof(vote[3]);i++)
         	printf("%%^CYAN%%^%s ",CHAR_D->get_char(vote[3][i],"name"));
           printf("%%^RESET%%^\n\n");}
           officer->targetted_action
          ("$N��$TЦ������֪����������Σ�����һ���Լ��������\n",who);
           confirm_guoshi_vote(who,officer);
          }
}
     	
      
           

