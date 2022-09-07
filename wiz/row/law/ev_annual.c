/* ev_annual.c
   this is used to let the emperor to hold annual meeting every 2 sanguo year.
   by row on Feb, 2000 */
mapping tmp=([]);
string p_id;
int tmp_time=0;
object* p_list;
int p_sum;
int wait_time;
private mapping ministers;

void remove_name();
int query_recall();
string query_name();
string set_name(string arg);
int query_time();
void auto_holdmeeting();
void auto_check();
void auto_run();
void set_count(int i);
void recall();
void select_member();

void select_member()
{
    int i, j, r1, r2, a1, a2;
    string s, s1, *ss, *ppl;
	array *rank=OFFICER_D->query_nation_officer_title_all(1)-({1,10,11});

    ppl = filter_array(CHAR_D->list_chars(), (: CHAR_D->get_char($1,"ranknation")
	&&CHAR_D->get_char($1, "type")==1 :));

    for(i=0; i<sizeof(ppl)-1; i++){
        s = ppl[i];
        ss= ppl[i+1..];
        for(j=0; j<sizeof(ss); j++ ){
            s1 = ss[j];
            r1 = OFFICER_D->query_level(CHAR_D->get_char(s,"ranknation"));
            r2 = OFFICER_D->query_level(CHAR_D->get_char(s1,"ranknation"));
            a1 = CHAR_D->get_char(s,"literate");
	    a2 = CHAR_D->get_char(s1,"literate");
            if( r1<r2 || (r1==r2&&a1<a2) ) {
		ppl[i] = s1;
                ppl[i+1+j] = s;
                s = s1;
	    }
	}
    }
    ppl = filter_array(ppl, (: !wizardp($1) :));
    if ( sizeof(ppl)<10 ) return 0;
    ppl = ppl[0..9];

//SGSYS(sprintf("list is %O\n", ppl));

	foreach (string o in ppl ) {
       int r;
       r=rank[random(sizeof(rank))];
       rank-=({r});
       CHAR_D->set_char(o,"royalrank",r);
       CHAR_D->set_char(o,"is_jury",1);                
}
//SGSYS(sprintf("rest rank is %O\n", rank));

	tell(users(),"%^H_YELLOW%^��������͢��%^H_RED%^����%^H_CYAN%^���У�������������꣬����һ����������¡�%^RESET%^\n");
	tell(users(),"%^H_YELLOW%^��������͢��%^H_CYAN%^���׵ۣ��%^RESET%^\n");
	tell(users(),"%^H_YELLOW%^��������͢��%^H_RED%^����%^H_CYAN%^���У��ǡ�%^RESET%^\n");
	tell(users(),"%^H_YELLOW%^��������͢��%^H_RED%^����%^H_CYAN%^���У�Т��ʵۣ��������񣬻ʵ۳��ã������������������٣�����\n"+
	             "                      ��㡣������ɥ���衣����������Ϊ����ң��������٣�Ӧ��\n"+
	             "                      ˳�ˣ���ο����֮����%^RESET%^\n");
	tell(users(),"%^H_YELLOW%^��������͢��%^H_CYAN%^���׵��ߵ�����ͨ�죬�޲����Ҹ��ط����ȥ��%^RESET%^\n");
	tell(users(),"%^H_YELLOW%^��������͢��%^H_CYAN%^���׵ۣ��ƣ���˹��˱㽵һگ�����˴�Ϊ�����ա�%^RESET%^\n");
	tell(users(),"\n%^H_YELLOW%^��������͢��%^H_CYAN%^Ƭ�̺󡣡���%^RESET%^\n\n");
	tell(users(),"%^H_YELLOW%^��������͢��%^H_RED%^����%^H_CYAN%^���У�������ˣ��ʵ�گԻ������˳Ӧ��������������Ϊ�Źɣ�����\n"+
	             "                      ���⣺%^RESET%^\n\n");
	foreach (string o in ppl ) {
	tell(users(),"                      %^H_CYAN%^��  %^H_GREEN%^"+CHAR_D->get_char(o,"name")+"%^H_CYAN%^��  %^H_YELLOW%^"+OFFICER_D->query_rank_name(CHAR_D->get_char(o,"royalrank"))+"%^H_CYAN%^һְ��%^RESET%^\n");
	}
	tell(users(),"\n                      %^H_CYAN%^�������������Һ�ҵ��Ϊ����ͳ��%^RESET%^\n");
	tell(users(),"                                                                  %^H_CYAN%^��ˡ�%^RESET%^\n");
	return;
}

void auto_check()
{       
        string mess, c_id;
        string m_id;
        int rep, repred;
        object usrs;    

        tmp_time++;
        if (tmp["name"]&&objectp(find_user(tmp["name"]))){
		if(tmp_time == 6 ||tmp_time== 12 ||tmp_time== 18 ||tmp_time==24)
		{       mess="��ǰ���ɽ�����������"
			+CHAR_D->get_char(tmp["name"],"name")+"���ñ��¾ú����������� \n";
		        CHANNEL_D->deliver_tell("rumor","system",mess);    
		        return;
		}
	        else 
		{
		       if ( tmp_time > 36 )
		        {	if( sizeof(tmp) )
			        {       m_id=tmp["name"];
			                rep=CHAR_D->get_char(m_id,"reputation");
			                repred=rep/20;
			                if (repred>15000)repred=15000;
			                CHAR_D->set_char(m_id,"reputation",rep-repred);
			                remove_name();
			                mess=CHAR_D->get_char(m_id,"name")+"���ٲ�������������"
					+chinese_number(repred)+"�㡣";
			                CHANNEL_D->deliver_tell("rumor","system",mess);                         
			        }
			}
		}
	}
        else 
	{       if( tmp_time > wait_time ){
        	        tmp_time = 0;
		        p_list=users();
		        p_sum=sizeof(p_list);
// we need to test if tmp["name"]= 0 or not
// if a ppl just at the login status, the
// find_user(0) will return an object commented by fire
	               if (tmp["name"]&&objectp(find_user(tmp["name"])))

		        c_id=tmp["name"];
        
        		else {
		                if(!p_sum)
			                return;
			        usrs=p_list[random(sizeof(p_list))];
// need to check if this user has a body, if just in connect
// situation, then it will not have a body. so need check
// and if it doesn't have a body, need change tmp_time back
// so can have next selection. same as when call the wizard
		                if(!objectp(usrs->query_body()) || wizardp(usrs)) 
                		{     
		                      tmp=([]);         
                		      tmp_time=1500;
		                      return ;
                		}
			        c_id=usrs->query_body()->query_primary_id();
			        if (!CHAR_D->char_exist(c_id))
			        {             tmp=([]);
		                      tmp_time=1500;
                		      return ;
			        }
			        if (CHAR_D->get_char(c_id,"task"))
			        {             tmp=([]);
                			      tmp_time=1500;
		        	              return ;
	                	}

		         }
        
// if have task 

	        tmp["name"]=c_id;
                
//        	auto_invite(c_id);
        
		}       
	}
	return;

}
void auto_holdmeeting()
{
	tell(users(),"%^H_YELLOW%^��������͢��%^H_RED%^����%^H_CYAN%^���У����£�ʱ���ѵ�������һ�ȵĹ�͢�����Ҫ��ʼ�ˡ�%^RESET%^\n");
	tell(users(),"%^H_YELLOW%^��������͢��%^H_CYAN%^���׵ۣ��ţ����������µµ�Ⱥ��ɹ���ү��Ϊ���ְա�%^RESET%^\n");
	tell(users(),"%^H_YELLOW%^��������͢��%^H_RED%^����%^H_CYAN%^���У��ǣ����¡�%^RESET%^\n\n");
	tell(users(),"%^H_YELLOW%^��������͢����ǰ���ɽ�%^RESET%^%^H_CYAN%^�����������ܷ������빬�������ϣ�%^RESET%^\n");
	tmp["time"] = time();                   
	wait_time=30+random(20);
}

string query_name()
{
        return tmp["name"];
}

void remove_name()
{
        tmp=([]);
}

int query_time()
{
        return tmp["time"];
}

string set_name(string arg)
{
        if(!objectp(find_user(arg))) return "";
        tmp["name"]=arg;
        return tmp["name"];
}

int query_recall()
{
        return tmp_time;
}
void set_count(int k)
{
        tmp_time = k;
}
void recall()
{
//        remove_call_out("recall");
        auto_run();
//        call_out("recall",5);
}
