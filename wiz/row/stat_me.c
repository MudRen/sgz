// stat_me.c by fire on Dec 1998 
// for area to inherit
string get_zhoumu_name(string a_id) {
	string ret;
	string p_id;
	string zhou,zhouhd;

	zhou=AREA_D->get_area(a_id,"zhou");
	zhouhd=AREA_D->get_zhou_head(zhou);
	p_id=AREA_D->get_area(zhouhd,"zm");
	if(!p_id) return "";
	if(CHAR_D->get_char(p_id,"nation")!=AREA_D->get_area(zhouhd,"nation")) {
		AREA_D->set_area(zhouhd,"zm",0);
		return "";
	}
	if(AREA_D->get_area(a_id,"nation")!=AREA_D->get_area(zhouhd,"nation"))
		return "";
	return "%^H_MAGENTA%^����    ����"+CHAR_D->get_char(p_id,"name");
}
string product_estimate(string a_id) {
	string *bs;
	object ob;
	string ret="";
//	string ret="%^H_CYAN%^�������������������²�����%^RESET%^\n";
	mapping pd=([]);
	mapping tmp;
	bs=AREA_D->get_area(a_id,"base");
	if(!sizeof(bs)) return "";
	foreach(string b in bs) {
		ob=SGBASE(a_id,b);
		if(!objectp(ob)) continue;
		tmp=ob->get_base_product_estimate();
		if(!sizeof(tmp)) continue;
		foreach(string st,int val in tmp)
			pd[st]+=val;
	}
	if(!sizeof(pd)) return "";
	foreach(string stf, int v in pd) {
		if(!BASE_D->stuff_exist(stf)) continue;
		ret+=BASE_D->get_stuff(stf,"name")+"��"+chinese_number(v)+
			BASE_D->get_stuff(stf,"unit")+"  ";
	}
	ret+="\n";
	return ret;

}
string stat_me(string a_id,string para,int priority)
{
	string p_ret="";
	mixed c,p_tmp;
	int *list_title;
	string *list_char,s_tmp,a_nation;
	array a_tmp;
	int i,j,v_left;
	string p_id;
	mapping troop;
	p_id=this_body()->query_id()[0];
if(!AREA_D->area_exist(a_id))
	return "û�����������\n";
	c=AREA_D->get_area(a_id,"");
if(para=="")
{
	p_ret+="%^H_CYAN%^info aa %^H_YELLOW%^<area_id>%^RESET%^����ʾĿ�����������Ϣ��\n";
	p_ret+="%^H_CYAN%^info ag %^H_YELLOW%^<area_id>%^RESET%^����ʾĿ�����������Ϣ��\n";
	p_ret+="%^H_CYAN%^info am %^H_YELLOW%^<area_id>%^RESET%^����ʾĿ��������¼�������Ϣ��\n";
	p_ret+="%^H_CYAN%^info af %^H_YELLOW%^<area_id>%^RESET%^����ʾĿ�����������Ϣ��\n";
	p_ret+="%^H_CYAN%^info ao %^H_YELLOW%^<area_id>%^RESET%^����ʾĿ�����������Ϣ��\n";
	p_ret+="%^H_CYAN%^info a %^H_YELLOW%^<area_id>%^RESET%^�� ��ʾ����Ϣ��\n";
	p_ret+="ע����%^H_YELLOW%^<area_id>%^RESET%^Ϊ%^H_YELLOW%^here%^RESET%^������ʾ���ڵ������Ϣ��\n";
	return p_ret;
}
	p_ret+="%^MAGENTA%^������������%^H_GREEN%^��%^RESET%^%^MAGENTA%^����������%^H_GREEN%^��%^RESET%^%^MAGENTA%^����������%^H_GREEN%^��%^RESET%^%^MAGENTA%^����������%^H_GREEN%^Ѷ%^RESET%^%^MAGENTA%^������������%^RESET%^\n";
if(para=="g")
	p_ret+="\n%^B_WHITE%^%^BLACK%^��������ʾ��%^RESET%^%^H_YELLOW%^֮%^H_RED%^������Ϣ%^H_YELLOW%^��%^RESET%^\n\n";
if(para=="m")
	p_ret+="\n%^B_WHITE%^%^BLACK%^��������ʾ��%^RESET%^%^H_YELLOW%^֮%^H_RED%^���¼�������Ϣ%^H_YELLOW%^��%^RESET%^\n\n";
if(para=="f")
	p_ret+="\n%^B_WHITE%^%^BLACK%^��������ʾ��%^RESET%^%^H_YELLOW%^֮%^H_RED%^������Ϣ%^H_YELLOW%^��%^RESET%^\n\n";
if(para=="o")
	p_ret+="\n%^B_WHITE%^%^BLACK%^��������ʾ��%^RESET%^%^H_YELLOW%^֮%^H_RED%^������Ϣ%^H_YELLOW%^��%^RESET%^\n\n";
if(para=="a"||para=="g")
	p_ret+="%^H_CYAN%^��"+AREA_D->get_area(a_id,"zhou")+"�� %^RESET%^\n";
if(para=="g"||para=="a")
	p_ret+="%^H_GREEN%^��һ����Ѷ��%^RESET%^\n";
	p_ret+=sprintf("%%^H_YELLOW%%^���������š�%-8s����    �ơ�%-8s�� ������ ��%s%%^RESET%%^\n",a_id, c["name"],COUNTRY_D->get_country(AREA_D->get_area(a_id,"nation"),"name"));
if(para=="g"||para=="a")
	p_ret+=sprintf("%%^H_YELLOW%%^����    ����%-8d����    ����%-8s����    �ڡ�%-8d%%^RESET%%^\n",
      c["level"], DAY_D->get_weather_short(c["weather"]),c["population"]);
if(para=="g"||para=="a")
{
	if(priority<2)
	p_ret+=sprintf("%%^H_YELLOW%%^����    ����%-8d����չ�ص㡿%s%%^RESET%%^\n",
	c["safe"],AREA_D->get_area(a_id,"importancestr"));
}
if(para=="f"||para=="a")
{
	if(priority<1)
	p_ret+=sprintf("%%^H_YELLOW%%^����    ҵ��%-8d��ũ    ҵ��%-8d����    ҵ��%d%%^RESET%%^\n",
	c["industry"],c["agriculture"],c["business"]);
}
if(para=="g"||para=="a")
{
	if(priority<2)
	p_ret+=sprintf("%%^H_RED%%^����    ����%-8s%%^H_RED%%^��̫    �ء�%-8s%%^RESET%%^%s\n",
	CHAR_D->get_char(c["nation"],"name"), CHAR_D->get_char(AREA_D->get_area(a_id,"leader"),"name"),get_zhoumu_name(a_id));
}
if(para=="f"||para=="a")
{
	if(priority<1)
	p_ret+=sprintf("%%^H_YELLOW%%^��   ��   ��%-8d%%^H_RED%%^����    ˰��%-8d����    ˰��%d%%^RESET%%^\n", c["gold"],c["taxnation"],c["taxlocal"]);
}
if(para=="f"||para=="a")
{
	if(priority<1)
	{
	p_ret+="%^H_BLUE%^��������������֧״����%^RESET%^\n";
	p_ret+="%^H_CYAN%^�������������������²�����%^RESET%^\n";
	p_ret+="%^H_GREEN%^��������������������������������������������������������������\n";
	p_ret+=product_estimate(a_id);
	p_ret+="%^H_GREEN%^��������������������������������������������������������������\n";
	p_ret+=sprintf("%%^H_CYAN%%^���������롿%-8d%%^RESET%%^\n",
	AREA_D->get_area(a_id,"goldin"));
	p_ret+=sprintf("%%^H_CYAN%%^������֧������ʿ����%d ��Ա��%d��%%^RESET%%^\n",
	AREA_D->get_area(a_id,"goldout"),
	AREA_D->get_area(a_id,"salary"));
	p_ret+=sprintf("%%^H_CYAN%%^������֧����%-8d������֧����%d%%^RESET%%^\n",
	AREA_D->get_area(a_id,"foodout"),AREA_D->get_area(a_id,"stuffout"));
	}
}
if(para=="m"||para=="a")
{
	if(priority<1)
	{
	p_ret+="%^H_WHITE%^���������������ʴ�����%^RESET%^\n";
      p_ret+=sprintf("%%^H_YELLOW%%^��ʿ    ����%-8d��ѵ    ����%-8d��ʿ    ����%-8d%%^RESET%%^\n",
	AREA_D->get_area(a_id,"soldier"),c["train"],c["morale"]);
	if(sizeof(c["st"]))
		{
		p_ret+="%^H_CYAN%^��������������������������������������������������������������\n";
		foreach(string st_it in keys(c["st"]))
			{
			p_ret+=sprintf("%s��%d  ",(EV_MERCHANT)->query_goods(st_it,"name"),
			c["st"][st_it]);
			} 
		p_ret+="\n";
		}
	troop = c["troop"];
	if( mapp(troop) )
	{
	i = 0;
	foreach(string tt in keys(troop))
		{
		i++;
		if( i >= 3 )
			{
			i = 0;
 			p_ret+="\n";
			}
		p_ret+=sprintf("%-20s:%-7d%3s", WARAI_D->query_type(tt,"name")+"("+tt+")", troop[tt], "");
		}
	p_ret+="\n%^H_CYAN%^��������������������������������������������������������������%^RESET%^\n";
	}
	}
}
if(para=="o"||para=="a")
{
	p_ret+="%^H_MAGENTA%^��������Ա��%^RESET%^\n";
	list_title=OFFICER_D->query_area_officer_title_all(c["level"]);
	list_char=CHAR_D->check_char("area",a_id);
	for(i=0;i<sizeof(list_title);++i)
	{
	p_ret+="%^H_WHITE%^��"+OFFICER_D->query_rank_name(list_title[i])+"��%^RESET%^";
	a_tmp=filter_array(list_char,
		(:CHAR_D->get_char($1,"ranklocal")==$(list_title[i]):));
		for(j=0;j<sizeof(a_tmp);++j)
		{
		p_ret+=CHAR_D->get_char(a_tmp[j],"name");
		p_ret+=" ";
		}
	v_left=OFFICER_D->query_max_officer_number(list_title[i]);
	v_left-=sizeof(a_tmp);
	for(j=0;j<v_left;++j)
	p_ret+="���� ";
	p_ret+="\n";
	}
	p_ret+="%^H_RED%^����ְ�����ҹ�Ա��%^RESET%^\n";
	a_nation=AREA_D->get_area(a_id,"nation");
	for(j=0;j<sizeof(list_char);++j)
	{
	p_tmp=CHAR_D->get_char(list_char[j],"nation");
		if(p_tmp==a_nation)
		{
			if(!CHAR_D->get_char(list_char[j],"ranklocal"))
			{
			CHAR_D->set_char(list_char[j],"ranklocal",R_SG);
			}
			if(CHAR_D->get_char(list_char[j],"ranklocal")==R_SG)
			p_ret+=(CHAR_D->get_char(list_char[j],"name")+" ");
		}
	}
	p_ret+="\n";
}
if(para=="g"||para=="a")
{	p_ret+="%^H_YELLOW%^�����ڵ�����%^RESET%^\n";
	p_ret+="%^H_RED%^��������������������������������������������������������������\n";
	if(sizeof(c["neighbor"]))
	{
	foreach(string a in c["neighbor"])
		{
		p_ret+=(AREA_D->get_area(a,"name")+" ");
		}
	}
	p_ret+="\n";
	p_ret+="%^H_RED%^��������������������������������������������������������������\n";
}
if (para=="o"||para=="a")
{
	p_ret+="%^H_WHITE%^�������������ˣ�%^RESET%^\n";
	p_ret+="%^H_YELLOW%^��������������������������������������������������������������\n";
	for(j=0;j<sizeof(list_char);++j)
	{
	p_tmp=CHAR_D->get_char(list_char[j],"nation");
		if((!p_tmp)||(p_tmp==""))
		p_ret+=(CHAR_D->get_char(list_char[j],"name")+" ");
	}
	p_ret+="\n";
	p_ret+="%^H_YELLOW%^��������������������������������������������������������������\n";
}
	p_ret+="\n%^MAGENTA%^��������������������������������������������������%^B_WHITE%^%^BLACK%^����־%^RESET%^%^MAGENTA%^������%^RESET%^\n";
	return p_ret;
}