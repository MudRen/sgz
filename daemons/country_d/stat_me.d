// stat_me.c for country_d
// by fire on Dec 1998
string stat_me(string n_id,int pri)
{
   string mess="";
   mixed p_tmp;
   mapping tbs;
   array bs;
   string *list_area;
   string s_tmp;
   array a_tmp;
   int i,j,v_left;
   int *list_title;
   string *list_char;
   if(!(COUNTRY_D->nation_exist(n_id)))
   {    return "�ù��Ҳ����ڡ�\n";
   }
   mess+="%^MAGENTA%^����������%^H_GREEN%^��%^RESET%^%^MAGENTA%^����������%^H_GREEN%^��%^RESET%^%^MAGENTA%^����������%^H_GREEN%^��%^RESET%^%^MAGENTA%^����������%^H_GREEN%^Ѷ%^RESET%^%^MAGENTA%^����������%^RESET%^\n\n";
   mess+="%^H_GREEN%^��һ����Ѷ��%^RESET%^\n";
mess+=sprintf("%%^H_YELLOW%%^�����Ҵ��š�%-8s����    �ơ�%-8s���������㡿%d%%^RESET%%^\n",n_id,
COUNTRY_D->get_country(n_id,"name"),COUNTRY_D->get_country(n_id,"hon"));

   if(pri<1)
   {
      mess+=sprintf("%%^H_YELLOW%%^�� ���˿� ��%-8d�� �ܱ��� ��%-8d%%^RESET%%^\n",
        COUNTRY_D->get_country(n_id,"population"),
        COUNTRY_D->get_country(n_id,"soldier"));
	mess+="%^H_WHITE%^�����ⴢ����%^RESET%^\n";
      mess+=sprintf("%%^H_RED%%^��   ��   ��%-8d��   ��   ��%-8d��   ��   ��%-8d%%^RESET%%^\n",
        COUNTRY_D->get_country(n_id,"gold"),
        COUNTRY_D->get_country(n_id,"food"),
        COUNTRY_D->get_country(n_id,"stuff"));
	mess+="%^H_WHITE%^������������%^RESET%^\n";
      mess+=sprintf("%%^H_RED%%^��   ��   ��%-8d��   ��   ��%-8d��   ��   ��%-8d%%^RESET%%^\n",
        COUNTRY_D->get_country(n_id,"goldlocal"),
        COUNTRY_D->get_country(n_id,"foodlocal"),
        COUNTRY_D->get_country(n_id,"stufflocal"));
   }
   mess+=sprintf("%%^H_CYAN%%^����أ�%%^RESET%%^\n");
   list_area=AREA_D->check_area("nation",n_id);
	mess+="%^H_GREEN%^����������������������������������������������������������%^RESET%^\n";
   for(i=0;i<sizeof(list_area);++i)
   {    mess+=sprintf("%s ",AREA_D->get_area(list_area[i],"name"));
   }
	mess+="\n%^H_GREEN%^����������������������������������������������������������%^RESET%^\n";
   mess+=sprintf("%%^H_BLUE%%^�����أ�����(����)%%^RESET%%^\n");
	mess+="%^H_YELLOW%^����������������������������������������������������������%^RESET%^\n";
	tbs=([]);
	for(i=0;i<sizeof(list_area);++i)
   {    
		bs=AREA_D->get_area(list_area[i],"base");
		if(sizeof(bs)) {
			foreach(string b in bs)
				tbs[b]++;
		}
   }
	if(sizeof(tbs)) {
		foreach(string b,int n in tbs) {
			mess+=BASE_D->get_base(b,"name")+"("+n+") ";
		}
	}

   mess+="\n%^H_YELLOW%^����������������������������������������������������������%^RESET%^\n";
   mess+="%^H_MAGENTA%^����͢��Ա��%^RESET%^\n";
   list_title=OFFICER_D->query_nation_officer_title_all
      (COUNTRY_D->get_country(n_id,"level"));
   list_char=CHAR_D->check_char("nation",n_id);
   for(i=0;i<sizeof(list_title);++i)
   {     mess+="%^H_WHITE%^��"+OFFICER_D->query_rank_name(list_title[i])+"��%^RESET%^";
         a_tmp=filter_array(list_char,
            (:CHAR_D->get_char($1,"ranknation")==$(list_title[i]):));
         for(j=0;j<sizeof(a_tmp);++j)
         {
            mess+=CHAR_D->get_char(a_tmp[j],"name");
            mess+=" ";
         }
         v_left=OFFICER_D->query_max_officer_number(list_title[i]);
         v_left-=sizeof(a_tmp);
         for(j=0;j<v_left;++j)
         {   mess+="���� ";
         }
	if(i==0) {
		string p_gs;
			p_gs=COUNTRY_D->get_country(n_id,"gs");
			if(CHAR_D->char_exist(p_gs)) {
				mess+= "  %^H_WHITE%^����ʦ��%^RESET%^"+CHAR_D->get_char(p_gs,"name");
				if(pri<2)
					mess+="  %^H_MAGENTA%^��%^H_WHITE%^���ζȣ�"+COUNTRY_D->get_country(n_id,"gsx");
			}
	}
         mess+="\n";
    }
    mess+="%^H_RED%^���ط���Ա��%^RESET%^\n";
    a_tmp=filter_array(list_char,
        (:CHAR_D->get_char($1,"ranknation")==0:));
	mess+="%^H_CYAN%^����������������������������������������������������������%^RESET%^\n";
    for(i=0;i<sizeof(a_tmp);++i)
        mess+=sprintf("%s ",CHAR_D->get_char(a_tmp[i],"name"));
	mess+="\n%^H_CYAN%^����������������������������������������������������������%^RESET%^\n";
   mess+="\n%^MAGENTA%^������������������������������������������������%^B_WHITE%^%^BLACK%^����־%^RESET%^%^MAGENTA%^����%^RESET%^\n";
   return mess;
}
