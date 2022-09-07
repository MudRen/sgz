mapping elect()
{
	int i, j, r1, r2, a1, a2;
	string s, s1, *ss, *ppl,str;
	mapping jury;
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
	if ( sizeof(ppl)<10 ) return ([ ]);
	ppl = ppl[0..9];
//	jury = ([ ]);

	foreach (string o in ppl ) {
	int r;
	r=rank[random(sizeof(rank))];
	rank-=({r});
	CHAR_D->set_char(o,"royalrank",r);
	CHAR_D->set_char(o,"is_jury",1);                
}

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
//	tell(users(),"                      %^H_CYAN%^��  %^H_GREEN%^"+CHAR_D->get_char(o,"name")+"%^H_CYAN%^��  %^H_YELLOW%^"+OFFICER_D->query_rank_name(CHAR_D->get_char(o,"royalrank"))+"%^H_CYAN%^һְ��%^RESET%^\n");
	str=sprintf("                      %%^H_CYAN%%^��  %%^H_GREEN%%^%-8s%%^H_CYAN%%^��  %%^H_YELLOW%%^%-8s%%^H_CYAN%%^һְ��%%^RESET%%^\n",CHAR_D->get_char(o,"name"),OFFICER_D->query_rank_name(CHAR_D->get_char(o,"royalrank")));
	tell(users(),str);
	}
	tell(users(),"\n                      %^H_CYAN%^�������������Һ�ҵ��Ϊ����ͳ��%^RESET%^\n");
	tell(users(),"                                                              %^H_CYAN%^��ˡ�%^RESET%^\n");

//	for(i=0; i<sizeof(ppl); i++){
//	CHAR_D->set_char(ppl[i], "rankroyal", i);
//	jury[ppl[i]] = 0;
//	}
       
//	return jury;
}