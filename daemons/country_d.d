/* country_d.c by fire on 1/07/98
this is used to handle the common control of countries
country includes cities towns and obstalce
*/
#include <mudlib.h>
#include <security.h>
#include <ansi.h>
#include <country.h>
inherit M_ACCESS;
inherit __DIR__+"country_d/stat_me";
private mapping countries;
#define SAVE_FILE "/data/daemons/countries"
#define LOG_FILE "/data/log/countries.log"
static private int m_modified;
void save_data()
{
	if(m_modified)
	{
		unguarded(1, (: save_object, SAVE_FILE :));
		m_modified=0;
	}
}
void create()
{
    unguarded(1, (: restore_object, SAVE_FILE, 1 :));
	return;
}
int check_cc_condition(string char_id,string area_id)
{
	string *list;
	list=CHAR_D->check_char_area("ranknation",R_KING,area_id);
	if(sizeof(list)>0)
		return CC_OTHERCOUNTRYCAPITAL;
	return CC_ACCEPTED;
}
void trans_country(string old,string newid) {
	mixed tmp;
	string message;
	countries[newid]=([]);
	foreach(string k, mixed v in countries[old]) {
		tmp=v;
		countries[newid][k]=tmp;
	}
	NEWS_D->add_nation_group("nation."+newid);
	NEWS_D->remove_nation_post(old);
	map_delete(countries,old);

	message=sprintf("【大事记】%s于%s将王位禅让给%s。\n",
		CHAR_D->get_char(old,"name"),
		DAY_D->query_chinese_day(),CHAR_D->get_char(newid,"name"));
	HIS(message);
	tell(users(),HIR+message+NOR);
	unguarded(1, (: write_file, LOG_FILE, message :));
	m_modified=1;
}
// please don't call this function from other program
void add_country(string p_id,string p_area)
{
	string *list;
	string p_otherarea;
	string p_othercountry;
	string message;
	int area_level;
	int array leader_title;
	array p_date;
	int p_day,p_month,p_year;
	string s_year,s_month,s_day;
	p_date=DAY_D->query_date();
	p_day=p_date[1];
	p_month=p_date[2];
	p_year=p_date[3];
	s_year=CHINESE_DA->chinese_number(p_year);
	s_month=CHINESE_DA->chinese_number(p_month);
	s_day=CHINESE_DA->chinese_number(p_day);
	
	countries[p_id]=([]);
	list=CHAR_D->check_char("area",p_area);
	foreach(string c_id in list)
	{
	 //Added by suicide for do sth to those chat who fealty to king
	 if (CHAR_D->get_char(c_id,"fealty")==p_id)
	    {
	     CHAR_D->set_char(c_id,"loyalty",1); //与原国家的关系度
	     CHAR_D->set_char(c_id,"nation",p_id);
	     CHAR_D->set_char(c_id,"loyalty",60+random(40));
	     CHAR_D->set_char(c_id,"reputation",CHAR_D->get_char(c_id,"reputation")*12/10);
	     
	     continue;      //效忠的官员官职不做调动保持原位. 
	    }
	//End end;
		if(c_id!=p_id) 
		{
			CHAR_D->set_char(c_id,"ranklocal",0);
			if((CHAR_D->get_char(c_id,"ranknation"))>0)
			{
				CHAR_D->set_char(c_id,"ranklocal",0); 
				p_othercountry=CHAR_D->get_char(c_id,"nation");
				if(!stringp(p_othercountry))// this just in case
				{
					CHAR_D->set_char(c_id,"ranknation",0);
				}
				else
				{
					p_otherarea=CHAR_D->get_char(p_othercountry,"area");
					CHAR_D->set_char(c_id,p_otherarea); // make this char go home
				}
			}
			else
			{
				CHAR_D->set_char(c_id,"nation",0);
			}
		}
	}
	area_level=AREA_D->get_area(p_area,"level");
	leader_title=OFFICER_D->query_area_officer_title(area_level,0,0);
	CHAR_D->set_char(p_id,"ranknation",R_KING);
	CHAR_D->set_char(p_id,"ranklocal",leader_title[0]);
	CHAR_D->set_char(p_id,"nation",p_id);
	AREA_D->set_area(p_area,"nation",p_id);
	message=sprintf("【大事记】%s于三国志%s年%s月%s日在%s立国．\n",
		CHAR_D->get_char(p_id,"name"),
		s_year,s_month,s_day,
		AREA_D->get_area(p_area,"name"));
	HIS(message);
	tell(users(),HIR+message+NOR);
	NEWS_D->add_nation_group("nation."+p_id);
	unguarded(1, (: write_file, LOG_FILE, message :));
	m_modified=1;
}
int creat_country(string p_id)
{
	string p_area;
	int p_tmp;
	if(!countries)
		countries=([]);
	if(countries[p_id])
		return CC_ALREADYEXIST;
	if(!(CHAR_D->char_exist(p_id)))
		return CC_CHARNOTEXIST;
	p_area=CHAR_D->get_char(p_id,"area");
	if(!stringp(p_area))
		return CC_CHARNOAREA;
	if((p_tmp=(check_cc_condition(p_id,p_area)))!=CC_ACCEPTED)
		return p_tmp; // other conditions
	add_country(p_id,p_area);
	return CC_ACCEPTED;
}
// this function should be just used in the early develop 
// time. later to use it may cause other conflict
string remove_country(string p_id) 
{
	array p_date;
	int p_day,p_month,p_year;
	string s_year,s_month,s_day;
	string message;
	string* list;
	p_date=DAY_D->query_date();
	p_day=p_date[1];
	p_month=p_date[2];
	p_year=p_date[3];
	s_year=CHINESE_DA->chinese_number(p_year);
	s_month=CHINESE_DA->chinese_number(p_month);
	s_day=CHINESE_DA->chinese_number(p_day);
    if (!countries[p_id]) 
		return "该国家不存在．\n";
	list=CHAR_D->check_char("nation",p_id);
	if(sizeof(list)) {
	foreach(string c_id in list)
		{
			CHAR_D->set_char(c_id,"ranknation",0);
			CHAR_D->set_char(c_id,"ranklocal",0);
			CHAR_D->set_char(c_id,"nation",0);
		}
	}
	list=AREA_D->check_char("nation",p_id);
	if(sizeof(list)) {
		foreach(string c_id in list)
		{
			AREA_D->set_area(c_id,"nation",0);
		}
	}

	message=sprintf("【大事记】%s于三国志%s年%s月%s日亡国．\n",
		CHAR_D->get_char(p_id,"name"),
		s_year,s_month,s_day);
	HIS(message);
	tell(users(),HIR+message+NOR);
	unguarded(1, (: write_file, LOG_FILE, message :));
	map_delete(countries, p_id);
	m_modified=1;
	NEWS_D->remove_nation_post(p_id);
    return "国家删除成功．\n";
}
int create_friend_country(string c1,string c2)
{
	array p_date;
	int p_day,p_month,p_year;
	string s_year,s_month,s_day;
	string message;
	p_date=DAY_D->query_date();
	p_day=p_date[1];
	p_month=p_date[2];
	p_year=p_date[3];
	s_year=CHINESE_DA->chinese_number(p_year);
	s_month=CHINESE_DA->chinese_number(p_month);
	s_day=CHINESE_DA->chinese_number(p_day);
	if((!countries[c1])||(!countries[c2]))
		return CF_NOTEXIT;
	if(!countries[c1]["friend"])
		countries[c1]["friend"]=({});
	if(!countries[c2]["friend"])
		countries[c2]["friend"]=({});
	if ((member_array(c1,countries[c2]["friend"])!=-1)&&
		(member_array(c2,countries[c1]["friend"])!=-1))
		return CF_ALREADY;
	if((countries[c1]["master"]==c2)||
	   (countries[c2]["master"]==c1))
	   return CF_MASTERSLAVE;
	countries[c1]["friend"]-=({c2});
	countries[c1]["friend"]+=({c2});
	countries[c2]["friend"]-=({c1});
	countries[c2]["friend"]+=({c1});
	message=sprintf("【大事记】%s于三国志%s年%s月%s日与%s结为同盟国．\n",
		COUNTRY_D->get_country(c1,"name"),
		s_year,s_month,s_day,
		COUNTRY_D->get_country(c2,"name"));
	tell(users(),HIR+message+NOR);
	unguarded(1, (: write_file, LOG_FILE, message :));
	
	m_modified=1;
	return CF_ACCEPT;
}
int remove_friend_country(string c1,string c2)
{
	array p_date;
	int p_day,p_month,p_year;
	string s_year,s_month,s_day;
	string message;
	int ret;
	p_date=DAY_D->query_date();
	p_day=p_date[1];
	p_month=p_date[2];
	p_year=p_date[3];
	s_year=CHINESE_DA->chinese_number(p_year);
	s_month=CHINESE_DA->chinese_number(p_month);
	s_day=CHINESE_DA->chinese_number(p_day);
	if((!countries[c1])||(!countries[c2]))
	{
		if (countries[c1]["friend"])
			countries[c1]["friend"]-=({c2});
		if (countries[c2]["friend"])
			countries[c2]["friend"]-=({c1});
		ret= RF_NOTEXIT;
	}
	else
	{
		if(!countries[c1]["friend"])
			countries[c1]["friend"]=({});
		if(!countries[c2]["friend"])
			countries[c2]["friend"]=({});
		if ((member_array(c1,countries[c2]["friend"])==-1)||
			(member_array(c2,countries[c1]["friend"])==-1))
                ret=RF_NOFRIEND;
		else
		{
			countries[c1]["friend"]-=({c2});
			countries[c2]["friend"]-=({c1});
			message=sprintf("【大事记】%s于三国志%s年%s月%s日与%s解除同盟．\n",
				COUNTRY_D->get_country(c1,"name"),
				s_year,s_month,s_day,
				COUNTRY_D->get_country(c2,"name"));
			tell(users(),HIR+message+NOR);
			unguarded(1, (: write_file, LOG_FILE, message :));
			
                        ret=RF_ACCEPT;
		}
	}
	m_modified=1;
	return ret;
}
string set_country(string p_id,string para_name,mixed para_value)
{
	string p_ret;
	int i_ret;
	if(!countries[p_id])
		return "该国家不存在．\n";
	switch (para_name)
	{
		
	case "addfriend":
                i_ret=create_friend_country(p_id,para_value);
                if(i_ret==CF_ACCEPT)
			p_ret="国家同盟设置成功．\n";
		else
			p_ret="国家同盟设置失败．\n";
		break;
	case "rmfriend":
		i_ret=remove_friend_country(p_id,para_value);
		if(i_ret==1)
			p_ret="国家同盟解除成功．\n";
		else
			p_ret="国家同盟解除失败．\n";
		break;
	default:
		countries[p_id][para_name]=para_value;
		p_ret="国家参数设\n";
		break;
	}
	m_modified=1;
	return p_ret;
}
string get_country_name(string p_id)
{
	string p_name;
	if(!stringp(countries[p_id]["name"]))
	{
		p_name=CHAR_D->get_char(p_id,"r_name");
		return p_name+"国";
	}
	return (countries[p_id]["name"]);
}
int get_country_sum(string p_id,string para)
{
	string* list;
	int p_ret;
	list=AREA_D->check_area("nation",p_id);
	foreach(string s_id in list)
	{
		p_ret+=AREA_D->get_area(s_id,para);
	}
	return p_ret;
}
/* no use now, country pay now in ev_lincome
void country_pay(string p_id)
{
	string* list;
	int p_sal;
	int p_gold;
	int p_ogold;
	int p_nopay=0;
	string mess;
	p_gold=countries[p_id]["gold"];
	list=CHAR_D->check_char("nation",p_id);
	foreach(string s_id in list)
	{
		
		p_sal=CHAR_D->get_char(s_id,"salarynation");
		if(p_sal)
                {      
			if(p_gold>=p_sal)
                        {
				p_gold-=p_sal;
				p_ogold=CHAR_D->get_char(s_id,"gold");
				CHAR_D->set_char(s_id,"gold",p_ogold+p_sal);
			}
			else
			{
				CHAR_D->set_char_loyalty(s_id,p_id,
					CHAR_D->get_char_loyalty(s_id,p_id)-LD_NOPAY);
				p_nopay=1;
			}
		}
	}
	if(p_nopay)
	{
		mess=sprintf("【发饷】%s官员未能领够俸禄，忠诚下降．\n",
			COUNTRY_D->get_country(p_id,"name"));
		tell(users(),HIR+mess+NOR);
		CHAR_D->set_char(p_id,"reputation",
			(CHAR_D->get_char(p_id,"reputation")-RD_NOPAY));
	}
	countries[p_id]["gold"]=p_gold;
	m_modified=1;
}
void country_pay_whole()
{
	string *list;
	list=keys(countries);
	foreach(string p_id in list)
	{
		country_pay(p_id);
	}
}
*/
int get_salarynation(string p_id)
{
	string* list;
	int p_ret;
	list=CHAR_D->check_char("nation",p_id);
	foreach(string s_id in list)
	{
		p_ret+=CHAR_D->get_char(s_id,"salarynation");
	}
	return p_ret;
}
int *get_nation_product_level(string p_id)
{
	int p_zhi=0,p_mei=0,p_levelnum=0;
	int *list_title;
	string *list_char;
	string *a_tmp;
	int i,j;
	
	list_title=OFFICER_D->query_nation_officer_title_all(COUNTRY_D->get_country(p_id,"level"));
	list_char=CHAR_D->check_char("nation",p_id);
	for(i=0;i<sizeof(list_title);++i)
	{
		if((list_title[i]>99)||(list_title[i]==R_KING)) // this is wen guan
		{	int p_zhitmp=0,p_meitmp=0;
			int p_num;
			int v_left;
			mapping m;
			p_levelnum++;
			a_tmp=filter_array(list_char,
				(:CHAR_D->get_char($1,"ranknation")==$(list_title[i]):));
			for(j=0;j<sizeof(a_tmp);++j)
			{
				m=CHAR_D->get_char(a_tmp[j],"skills");
				p_zhitmp+=m["sk_zhimou"];
				p_meitmp+=m["sk_meili"];
			}
			p_num=OFFICER_D->query_max_officer_number(list_title[i]);
			v_left=p_num-sizeof(a_tmp);
			p_zhitmp+=(v_left*(25+random(10)));
			p_meitmp+=(v_left*(25+random(10)));
			p_zhitmp/=p_num;
			p_meitmp/=p_num;
			p_zhi+=p_zhitmp;
			p_mei+=p_meitmp;
		}
	}
	p_zhi/=p_levelnum;
	p_mei/=p_levelnum;
	return ({p_zhi+random(4)-2,p_mei+random(4)-2,(p_zhi+p_mei)/2+random(4)-2});
}
void adjust_product_level()
{
	mixed list;
	list=keys(countries);
	foreach(string p_id in list)
	{
		array a_tmp;
		int n_businesslevel,n_agriculturelevel,n_industrylevel;
		int l_businesslevel,l_agriculturelevel,l_industrylevel;
		int r_business,r_agriculture,r_industry;
		int p_step;
		mixed a_list;
		int p_importance;
		a_tmp=get_nation_product_level(p_id);
		n_businesslevel=a_tmp[0];
		n_agriculturelevel=a_tmp[1];
		n_industrylevel=a_tmp[2];
		a_list=AREA_D->check_area("nation",p_id);
		foreach(string a_id in a_list)
		{
			a_tmp=AREA_D->get_area_product_level(a_id);
			l_businesslevel=a_tmp[0];
			l_agriculturelevel=a_tmp[1];
			l_industrylevel=a_tmp[2];
			l_businesslevel=(l_businesslevel*70+n_businesslevel*30)/100;
			l_agriculturelevel=(l_agriculturelevel*70+n_agriculturelevel*30)/100;
			l_industrylevel=(l_industrylevel*70+n_industrylevel*30)/100;
			r_business=AREA_D->get_area(a_id,"business");
			r_agriculture=AREA_D->get_area(a_id,"agriculture");
			r_industry=AREA_D->get_area(a_id,"industry");
			p_importance=AREA_D->get_area(a_id,"importance");
			switch(p_importance)
			{
					case AI_INDUSTRY:
						l_industrylevel+=10;
						break;
					case AI_AGRICULTURE:
						l_agriculturelevel+=10;
						break;
					case AI_BUSINESS:
						l_businesslevel+=10;
						break;
					case 0: // no importance
						l_businesslevel+=2;
						l_agriculturelevel+=2;
						l_industrylevel+=2;
						break;
			}
//                        p_tell=sprintf("%s l_ag is %d r_ag is %d \n",
//                                AREA_D->get_area(a_id,"name"),
//                                l_agriculturelevel,
//                                r_agriculture);
			p_step=random(6)-1;
			if(l_businesslevel>r_business)
				r_business+=p_step;
			else
				r_business-=p_step;
			p_step=random(6)-1;
			if(l_agriculturelevel>r_agriculture)
				r_agriculture+=p_step;
			else
				r_agriculture-=p_step;
			p_step=random(6)-1;
			if(l_industrylevel>r_industry)
				r_industry+=p_step;
			else
				r_industry-=p_step;
			AREA_D->set_area(a_id,"business",r_business);
			AREA_D->set_area(a_id,"agriculture",r_agriculture);
			AREA_D->set_area(a_id,"industry",r_industry);
		}
	}
}
int *get_nation_safe_level(string p_id)
{
	int p_zhi=0,p_mei=0,p_levelnum=0;
	int p_wu=0;
	int *list_title;
	string *list_char;
	string *a_tmp;
	int i,j;
	int p_ret;
	
	list_title=OFFICER_D->query_nation_officer_title_all(COUNTRY_D->get_country(p_id,"level"));
	list_char=CHAR_D->check_char("nation",p_id);
	for(i=0;i<sizeof(list_title);++i)
	{
		int p_zhitmp=0,p_meitmp=0,p_wutmp=0;
		int p_num;
		int v_left;
		mapping m;
		p_levelnum++;
		a_tmp=filter_array(list_char,
			(:CHAR_D->get_char($1,"ranknation")==$(list_title[i]):));
		for(j=0;j<sizeof(a_tmp);++j)
		{
			m=CHAR_D->get_char(a_tmp[j],"skills");
			p_zhitmp+=m["sk_zhimou"];
			p_meitmp+=m["sk_meili"];
			p_wutmp+=m["sk_wuli"];
		}
		p_num=OFFICER_D->query_max_officer_number(list_title[i]);
		v_left=p_num-sizeof(a_tmp);
		p_zhitmp+=(v_left*(25+random(10)));
		p_meitmp+=(v_left*(25+random(10)));
		p_wutmp+=(v_left*(25+random(10)));
		p_zhitmp/=p_num;
		p_meitmp/=p_num;
		p_wutmp/=p_num;
		p_zhi+=p_zhitmp;
		p_mei+=p_meitmp;
		p_wu+=p_wutmp;
	}
	p_zhi/=p_levelnum;
	p_mei/=p_levelnum;
	p_wu/=p_levelnum;
	p_ret=(p_mei*70+p_wu*10+p_zhi*20)/100;
	return ({p_ret+random(4)-2});
}
void adjust_safe_level()
{
	mixed list;
	list=keys(countries);
	foreach(string p_id in list)
	{
		array a_tmp;
		int n_safelevel;
		int l_safelevel;

		int r_safe;
		int p_step;
		mixed a_list;
		int p_importance;
		a_tmp=get_nation_safe_level(p_id);
		n_safelevel=a_tmp[0];
		a_list=AREA_D->check_area("nation",p_id);
		foreach(string a_id in a_list)
		{
			a_tmp=AREA_D->get_area_safe_level(a_id);
			l_safelevel=a_tmp[0];
			l_safelevel=(l_safelevel*70+n_safelevel*30)/100;
			r_safe=AREA_D->get_area(a_id,"safe");
			p_importance=AREA_D->get_area(a_id,"importance");
			switch(p_importance)
			{
					case AI_SAFE:
						l_safelevel+=10;
						break;
					case 0: // no importance
						l_safelevel+=2;
						break;
			}
			p_step=random(6)-1;
			if(l_safelevel>r_safe)
				r_safe+=p_step;
			else
				r_safe-=p_step;
			AREA_D->set_area(a_id,"safe",r_safe);
		}
	}
}
int *get_nation_military_level(string p_id)
{
	int p_zhi=0,p_mei=0,p_wu=0,p_levelnum=0;
	int *list_title;
	string *list_char;
	string *a_tmp;
	int i,j;
	int p_train,p_morale;
	list_title=OFFICER_D->query_nation_officer_title_all(COUNTRY_D->get_country(p_id,"level"));
	list_char=CHAR_D->check_char("nation",p_id);
	
	for(i=0;i<sizeof(list_title);++i)
	{
		if(list_title[i]<100) // this is wu guan and the leader
		{	int p_zhitmp=0,p_meitmp=0,p_wutmp;
			int p_num;
			int v_left;
			mapping m;
			p_levelnum++;
			a_tmp=filter_array(list_char,
				(:CHAR_D->get_char($1,"ranknation")==$(list_title[i]):));
			for(j=0;j<sizeof(a_tmp);++j)
			{
				m=CHAR_D->get_char(a_tmp[j],"skills");
				p_zhitmp+=m["sk_zhimou"];
				p_meitmp+=m["sk_meili"];
				p_wutmp+=m["sk_wuli"];
			}
			p_num=OFFICER_D->query_max_officer_number(list_title[i]);
			v_left=p_num-sizeof(a_tmp);
			p_zhitmp+=(v_left*(25+random(10)));
			p_meitmp+=(v_left*(25+random(10)));
			p_wutmp+=(v_left*(25+random(10)));
			p_zhitmp/=p_num;
			p_meitmp/=p_num;
			p_wutmp/=p_num;
			p_zhi+=p_zhitmp;
			p_mei+=p_meitmp;
			p_wu+=p_wutmp;
		}
	}
	p_zhi/=p_levelnum;
	p_mei/=p_levelnum;
	p_wu/=p_levelnum;
	p_train=(p_wu+p_zhi)/2;
	p_morale=(p_wu+p_mei)/2;
	return ({p_train+random(4)-2,p_morale+random(4)-2,});
}
void adjust_military_level()
{
	mixed list;
	list=keys(countries);
	foreach(string p_id in list)
	{
		array a_tmp;
		int n_trainlevel,n_moralelevel;
		int l_trainlevel,l_moralelevel;

		int r_train,r_morale;
		int p_step;
		mixed a_list;
		int p_importance;
		a_tmp=get_nation_military_level(p_id);
		n_trainlevel=a_tmp[0];
		n_moralelevel=a_tmp[1];
		a_list=AREA_D->check_area("nation",p_id);
		foreach(string a_id in a_list)
		{
			a_tmp=AREA_D->get_area_military_level(a_id);
			l_trainlevel=a_tmp[0];
			l_moralelevel=a_tmp[1];
			l_trainlevel=(l_trainlevel*70+n_trainlevel*30)/100;
			l_moralelevel=(l_moralelevel*70+n_moralelevel*30)/100;
			r_train=AREA_D->get_area(a_id,"train");
			r_morale=AREA_D->get_area(a_id,"morale");
			p_importance=AREA_D->get_area(a_id,"importance");
			switch(p_importance)
			{
					case AI_MILITARY:
						l_trainlevel+=10;
						l_moralelevel+=10;
						break;
					case 0: // no importance
						l_trainlevel+=2;
						l_moralelevel+=2;
						break;
			}
/*			{

				string p_tell;
				p_tell=sprintf("%s l_t is %d r_t is %d\n",
					AREA_D->get_area(a_id,"name"),
					l_trainlevel,r_train);
			}*/
			p_step=random(4)-1;


			if(l_trainlevel>r_train)
				r_train+=p_step;
			else
				r_train-=p_step;
			p_step=random(4)-1;
			if(l_moralelevel>r_morale)
				r_morale+=p_step;
			else
				r_morale-=p_step;
			AREA_D->set_area(a_id,"train",r_train);
			AREA_D->set_area(a_id,"morale",r_morale);
		}
	}
}
mixed get_country(string p_id,string para_name)
{
    if (!countries[p_id]) 
		return 0;
	if(!para_name) para_name="";
	switch(para_name)
	{
	case "":
		return countries[p_id];
	case "militarylevel":
		return get_nation_military_level(p_id);
	case "safelevel":
		return get_nation_safe_level(p_id);
	case "productlevel":
		return get_nation_product_level(p_id);
	case "population":
	case "soldier":
		return get_country_sum(p_id,para_name);
	case "goldlocal":
		return get_country_sum(p_id,"gold");
	case "foodlocal":
		return get_country_sum(p_id,"food");
	case "stufflocal":
		return get_country_sum(p_id,"stuff");
	case "name":
		return get_country_name(p_id);
	case "salary":
		return get_salarynation(p_id);
	default:
		if (!countries[p_id][para_name])  // try to find the situation of zero
			return 0;
		return countries[p_id][para_name];
	}
}
string* check_country(string para_name,mixed para_value)
{
	string* ret;
	string* list;
	list=keys(countries);
	ret=filter_array(list, (:countries[$1][$(para_name)]==$(para_value):));
	return ret;
}
mixed list_countries()
{
    return keys( countries );
}
int nation_exist(string p_id)
{
	if(countries[p_id])
		return 1;
	return 0;
}
int clean_up() {
   return 0; // means never_again
}
void remove() {
	save_data();
}
