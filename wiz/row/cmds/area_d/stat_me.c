// stat_me.c by fire on Dec 1998
// for area to inherit
string stat_me(string a_id,int priority)
{
   string p_ret="";
   mixed c,p_tmp;
   int *list_title;
   string *list_char,s_tmp,a_nation;
   array a_tmp;
   int i,j,v_left;
   mapping troop;

   if(!AREA_D->area_exist(a_id))
       return "û�����������\n";
   c=AREA_D->get_area(a_id,"");
   p_ret+=sprintf("�������ţ�%-14s���ƣ�%s\n",a_id, c["name"]);
   p_ret+="������������������������������������������������\n";
   p_ret+=sprintf("�ȼ���%d ������%4s  �˿ڣ�%d\n",
      c["level"], DAY_D->get_weather_short(c["weather"]),
      c["population"]);
   if(priority<1)
     p_ret+=sprintf("������%3d ��ҵ��%3d ũҵ��%3d ��ҵ��%3d �ص㣺%s\n",
        c["safe"],c["industry"],c["agriculture"],c["business"],
                AREA_D->get_area(a_id,"importancestr"));
   if(priority<2)
      p_ret+=sprintf("���ʣ�%d ���ݣ�%d ��%d\n",
           c["stuff"],c["food"],c["gold"]);
   p_ret+=sprintf("������%s ̫�أ�%s ��˰��%d ��˰��%d\n",
       CHAR_D->get_char(c["nation"],"name"),
       CHAR_D->get_char(AREA_D->get_area(a_id,"leader"),"name"),
       c["taxnation"],c["taxlocal"]);
   if(priority<2)
   {
     p_ret+=sprintf("Ԥ�ƽ������룺%d �������룺%d �������룺%d\n",
       AREA_D->get_area(a_id,"goldin"),AREA_D->get_area(a_id,"foodin"),
       AREA_D->get_area(a_id,"stuffin"));
     p_ret+=sprintf(
        "����֧����ʿ����%d ��Ա��%d ������֧����%d ����֧����%d\n",
         AREA_D->get_area(a_id,"goldout"),
         AREA_D->get_area(a_id,"salary"),
         AREA_D->get_area(a_id,"foodout"),
         AREA_D->get_area(a_id,"stuffout"));
     p_ret+=sprintf(
       "ʿ����%d ѵ����%d ʿ����%d ��ƥ��%d ������%d ���ˣ�%d\n",
       AREA_D->get_area(a_id,"soldier"),c["train"],c["morale"],c["horse"],
       c["bow"],c["bandit"]);
       if(sizeof(c["st"])) {
           foreach(string st_it in keys(c["st"])) {
           p_ret+=sprintf("%s��%d  ",(EV_MERCHANT)->query_goods(st_it,"name"),
		c["st"][st_it]);
           }
	   p_ret+="\n";
       }

	troop = c["troop"];
	if( mapp(troop) ){
		i = 0;
		foreach(string tt in keys(troop)){
			i++;
			if( i >= 3 ){
				i = 0;
				p_ret+="\n";
			}
			p_ret+=sprintf("%-20s:%-7d%3s", WARAI_D->query_type(tt, "name")+"("+tt+")", troop[tt], "");
		}
		p_ret+="\n";
	}
    }
    p_ret+="��Ա��\n";
    list_title=OFFICER_D->query_area_officer_title_all(c["level"]);
    list_char=CHAR_D->check_char("area",a_id);
    for(i=0;i<sizeof(list_title);++i)
    {  p_ret+=OFFICER_D->query_rank_name(list_title[i])+"��";
       a_tmp=filter_array(list_char,
            (:CHAR_D->get_char($1,"ranklocal")==$(list_title[i]):));
       for(j=0;j<sizeof(a_tmp);++j)
       {   p_ret+=CHAR_D->get_char(a_tmp[j],"name");
           p_ret+=" ";
       }
       v_left=OFFICER_D->query_max_officer_number(list_title[i]);
       v_left-=sizeof(a_tmp);
       for(j=0;j<v_left;++j)
           p_ret+="���� ";
       p_ret+="\n";
    }
    p_ret+="��ְ�͹��ҹ�Ա��";
    a_nation=AREA_D->get_area(a_id,"nation");
    for(j=0;j<sizeof(list_char);++j)
    {   p_tmp=CHAR_D->get_char(list_char[j],"nation");
        if(p_tmp==a_nation) {
		if(!CHAR_D->get_char(list_char[j],"ranklocal")) {
			CHAR_D->set_char(list_char[j],"ranklocal",R_SG);
		}
		if(CHAR_D->get_char(list_char[j],"ranklocal")==R_SG)
	            p_ret+=(CHAR_D->get_char(list_char[j],"name")+" ");
	}
    }
    p_ret+="\n";
    p_ret+="���ڵ�����";
    if(sizeof(c["neighbor"]))
    { foreach(string a in c["neighbor"])
      {   p_ret+=(AREA_D->get_area(a,"name")+" ");
      }
    }
    p_ret+="\n";
    p_ret+="�����������ˣ�";
    for(j=0;j<sizeof(list_char);++j)
    {   p_tmp=CHAR_D->get_char(list_char[j],"nation");
        if((!p_tmp)||(p_tmp==""))
            p_ret+=(CHAR_D->get_char(list_char[j],"name")+" ");
    }
    p_ret+="\n";
    return p_ret;
}
