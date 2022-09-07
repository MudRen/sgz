// infor.c
// by fire on 7 July 1998
// this is used to 
// give detailed information for
// a cetain char, country, or area
#include <mudlib.h>
#include <daemons.h>
inherit CMD;
inherit M_GLOB;
string bar="����������������������������������������������������������������������\n";
void infoa(string a_id)
{
	string mess="";
	string mess_tmp;
	mixed p_tmp;
	int *list_title;
	string *list_char;
	string s_tmp;
	array a_tmp;
	int i,j,v_left;
	if(!(AREA_D->area_exist(a_id)))
	{
		mess="�õ��������ڣ���listarea�г������嵥��\n";
		write(mess);
		return;
	}
	mess_tmp=sprintf("�������ţ�%8s    ���ƣ�%s\n",a_id,AREA_D->get_area(a_id,"name"));
	mess+=mess_tmp;
        mess+="����������������������������������������������������������������\n";
	mess_tmp=sprintf("�ȼ���%d ������%4s  �˿ڣ�%d\n",
		AREA_D->get_area(a_id,"level"),
		DAY_D->get_weather_short(AREA_D->get_area(a_id,"weather")),
		AREA_D->get_area(a_id,"population"));
	mess+=mess_tmp;
	mess_tmp=sprintf("������%3d ��ҵ��%3d ũҵ��%3d ��ҵ��%3d �ص㣺%s\n",
		AREA_D->get_area(a_id,"safe"),
		AREA_D->get_area(a_id,"industry"),
		AREA_D->get_area(a_id,"agriculture"),
		AREA_D->get_area(a_id,"business"),
		AREA_D->get_area(a_id,"importancestr"));
	mess+=mess_tmp;
	mess_tmp=sprintf("���ʣ�%d ���ݣ�%d ��%d\n",
		AREA_D->get_area(a_id,"stuff"),
		AREA_D->get_area(a_id,"food"),
		AREA_D->get_area(a_id,"gold"));
	mess+=mess_tmp;
	mess_tmp=sprintf("������%s ̫�أ�%s ��˰��%d ��˰��%d\n",
		CHAR_D->get_char(AREA_D->get_area(a_id,"nation"),"name"),
		(stringp(CHAR_D->get_char(AREA_D->get_area(a_id,"leader"),"name")) ?
		CHAR_D->get_char(AREA_D->get_area(a_id,"leader"),"name") : "����"),
		AREA_D->get_area(a_id,"taxnation"),
		AREA_D->get_area(a_id,"taxlocal"));
	mess+=mess_tmp;
	mess_tmp=sprintf("Ԥ�ƽ������룺%d �������룺%d �������룺%d\n",
		AREA_D->get_area(a_id,"goldin"),
		AREA_D->get_area(a_id,"foodin"),
		AREA_D->get_area(a_id,"stuffin"));
	mess+=mess_tmp;
	mess_tmp=sprintf("����֧����ʿ����%d ��Ա��%d ������֧����%d ����֧����%d\n",
		AREA_D->get_area(a_id,"goldout"),
		AREA_D->get_area(a_id,"salary"),
		AREA_D->get_area(a_id,"foodout"),
		AREA_D->get_area(a_id,"stuffout"));
	mess+=mess_tmp;
    mess_tmp=sprintf("ʿ����%d ѵ����%d ʿ����%d ��ƥ��%d ������%d ���ˣ�%d\n",
                AREA_D->get_area(a_id,"soldier"),
                AREA_D->get_area(a_id,"train"),
                AREA_D->get_area(a_id,"morale"),
                AREA_D->get_area(a_id,"horse"),
                AREA_D->get_area(a_id,"bow"),
                AREA_D->get_area(a_id,"bandit"));
	mess+=mess_tmp;
	mess+="��Ա��\n";
	list_title=OFFICER_D->query_area_officer_title_all(AREA_D->get_area(a_id,"level"));
	list_char=CHAR_D->check_char("area",a_id);
	for(i=0;i<sizeof(list_title);++i)
	{
		mess_tmp=OFFICER_D->query_rank_name(list_title[i])+"��";
		a_tmp=filter_array(list_char,
			(:CHAR_D->get_char($1,"ranklocal")==$(list_title[i]):));
		for(j=0;j<sizeof(a_tmp);++j)
		{
			mess_tmp+=CHAR_D->get_char(a_tmp[j],"name");
			mess_tmp+=" ";
		}
		v_left=OFFICER_D->query_max_officer_number(list_title[i]);
		v_left-=sizeof(a_tmp);
		for(j=0;j<v_left;++j)
		{
			mess_tmp+="���� ";
		}
		mess_tmp+="\n";
		mess+=mess_tmp;
	}
	mess+="���ڵ�����";
	a_tmp=AREA_D->get_area(a_id,"neighbor");
	for(j=0;j<sizeof(a_tmp);++j)
		mess+=(AREA_D->get_area(a_tmp[j],"name")+" ");
	mess+="\n";
	mess+="�����������ˣ�";
	for(j=0;j<sizeof(list_char);++j)
	{
		p_tmp=CHAR_D->get_char(list_char[j],"nation");
		if((!p_tmp)||(p_tmp==""))
			mess+=(CHAR_D->get_char(list_char[j],"name")+" ");
	}
	mess+="\n";
	more(mess);
}
void infon(string n_id)
{
	string mess="";
	string mess_tmp;
	mixed p_tmp;
	string *list_area;
	string s_tmp;
	array a_tmp;
	int i,j,v_left;
	int *list_title;
	string *list_char;
	if(!(COUNTRY_D->nation_exist(n_id)))
	{
		mess="�ù��Ҳ����ڣ���listcountry�г������嵥��\n";
		write(mess);
		return;
	}
	mess_tmp=sprintf("���Ҵ��ţ�%s  ���ƣ�%s\n",n_id,COUNTRY_D->get_country(n_id,"name"));
	mess+=mess_tmp;
	mess+="��������������������������������������������������\n";
	mess_tmp=sprintf("���˿ڣ�%d �ܱ�����%d\n",
		COUNTRY_D->get_country(n_id,"population"),
		COUNTRY_D->get_country(n_id,"soldier"));
	mess+=mess_tmp;
	mess+=sprintf("����(��%d ����%d �%d)\n",
		COUNTRY_D->get_country(n_id,"gold"),
		COUNTRY_D->get_country(n_id,"food"),
		COUNTRY_D->get_country(n_id,"stuff"));
	mess+=sprintf("�ط�(��%d ����%d �%d)\n",
		COUNTRY_D->get_country(n_id,"goldlocal"),
		COUNTRY_D->get_country(n_id,"foodlocal"),
		COUNTRY_D->get_country(n_id,"stufflocal"));
	mess+=sprintf("��أ�");
	list_area=AREA_D->check_area("nation",n_id);
	for(i=0;i<sizeof(list_area);++i)
	{
		mess+=sprintf("%s ",AREA_D->get_area(list_area[i],"name"));
	}
	mess+="\n";
	mess+="��͢��Ա\n";
	list_title=OFFICER_D->query_nation_officer_title_all(COUNTRY_D->get_country(n_id,"level"));
	list_char=CHAR_D->check_char("nation",n_id);
	for(i=0;i<sizeof(list_title);++i)
	{
		mess_tmp=OFFICER_D->query_rank_name(list_title[i])+"��";
		a_tmp=filter_array(list_char,
			(:CHAR_D->get_char($1,"ranknation")==$(list_title[i]):));
		for(j=0;j<sizeof(a_tmp);++j)
		{
			mess_tmp+=CHAR_D->get_char(a_tmp[j],"name");
			mess_tmp+=" ";
		}
		v_left=OFFICER_D->query_max_officer_number(list_title[i]);
		v_left-=sizeof(a_tmp);
		for(j=0;j<v_left;++j)
		{
			mess_tmp+="���� ";
		}
		mess_tmp+="\n";
		mess+=mess_tmp;
	}
	mess+="�ط���Ա��\n";
	a_tmp=filter_array(list_char,
		(:CHAR_D->get_char($1,"ranknation")==0:));
// sort_array(a_tmp,(:OFFICER_D->query_level(CHAR_D->get_char($1,"ranklocal")):);
	for(i=0;i<sizeof(a_tmp);++i)
		mess+=sprintf("%s ",CHAR_D->get_char(a_tmp[i],"name"));
	mess+="\n";
	more(mess);
}
void infoc(string c_id)
{
	string mess="";
	string mess_tmp;
	mixed p_tmp;
	string *list;
	string s_tmp;
	array a_tmp;
	int s_wuli,s_zhimou,s_meili;
       if(c_id=="me")
          c_id=this_body()->query_id()[0];
	if(!(CHAR_D->char_exist(c_id)))
	{
		mess="�ý�ɫ�����ڣ���listchar�г���ɫ�嵥��\n";
		write(mess);
		return;
	}
	mess_tmp=sprintf("��ɫ���ţ�%12s    ���ƣ�%s\n",c_id,CHAR_D->get_char(c_id,"name"));
	mess+=mess_tmp;
	mess+="������������������������������������������\n";
	p_tmp=CHAR_D->get_char(c_id,"skills");
	s_wuli=p_tmp["sk_wuli"];
	s_zhimou=p_tmp["sk_zhimou"];
	s_meili=p_tmp["sk_meili"];
	p_tmp=CHAR_D->get_char(c_id,"gift");
	
	mess_tmp=sprintf("�֣�%4s  �Ա�%2s  ���䣺%3d ��ò��%d\n",
		CHAR_D->get_char(c_id,"zi"),
		(CHAR_D->get_char(c_id,"gender")==1 ? "��" :"Ů"),
		CHAR_D->get_char(c_id,"age"),p_tmp["rongmao"]);
	mess+=mess_tmp;
	mess_tmp=sprintf("������%3d ��ı��%3d ������%3d ���ͣ�%s \n",
		s_wuli,s_zhimou,s_meili,
		(CHAR_D->get_char(c_id,"type")==TYPE_NPC ? "NPC" :"PLY"));
	mess+=mess_tmp;
	mess_tmp=sprintf("��������%6s  ���ڵأ�%6s  �ҳϣ�%d\n",
		COUNTRY_D->get_country(CHAR_D->get_char(c_id,"nation"),"name"),
		AREA_D->get_area(CHAR_D->get_char(c_id,"area"),"name"),
		CHAR_D->get_char(c_id,"loyalty"));
	mess+=mess_tmp;
	mess_tmp=sprintf("��͢��ְ��%8s  �ط���ְ��%6s%s\n",
		OFFICER_D->query_rank_name(CHAR_D->get_char(c_id,"ranknation")),
		AREA_D->get_area(CHAR_D->get_char(c_id,"area"),"name"),
		OFFICER_D->query_rank_name(CHAR_D->get_char(c_id,"ranklocal")));
	mess+=mess_tmp;
	mess_tmp=sprintf("ٺ»��%6d    ������%8s(%d)\n",
		CHAR_D->get_char(c_id,"salary"),
		CHAR_D->get_char(c_id,"reputationstr"),
		CHAR_D->get_char(c_id,"reputation"));
	mess+=mess_tmp;
	mess_tmp=sprintf("״̬��%s\n",(CHAR_D->get_char(c_id,"statustr")));
	mess+=mess_tmp;
	mess_tmp=sprintf("��������ϵ��\n");
	mess+=mess_tmp;
	list=COUNTRY_D->list_countries();
	s_tmp=CHAR_D->get_char(c_id,"nation");
	list=filter_array(list,(:$1!=$(s_tmp):));
	a_tmp=({});
	foreach(string n_id in list)
	{
		s_tmp=sprintf("%6s��%3d ",
			COUNTRY_D->get_country(n_id,"name"),
			CHAR_D->get_char_loyalty(c_id,n_id));
		a_tmp+=({s_tmp});
	}
	mess_tmp=sprintf("%-#50s\n",implode(a_tmp,"\n"));
	mess+=mess_tmp;
	mess_tmp=sprintf("���⼼�ܣ�\n");
	mess+=mess_tmp;
	mess_tmp=sprintf("���\n");
	mess+=mess_tmp;
	mess_tmp=sprintf("������\n");
	mess+=mess_tmp;
	mess_tmp=sprintf("��װ��\n");
	mess+=mess_tmp;
	mess_tmp=sprintf("���\n");
	mess+=mess_tmp;
	more(mess);
}
private void main(string arg)
{
	string p_type,p_name;
	int p_c=1;
	if(!arg)
		arg="";
    if(sscanf(arg, "%s %s", p_type,p_name)!=2)
	{
		p_c=0; // doesn't use propoly
	}
	if ((p_type!="n")&&(p_type!="c")&&(p_type!="a"))
	{
		p_c=0;
	}
	if(!p_c)
	{
		write("�÷���	info n <country_id> ����ĳһ������Ϣ\n"+
			"	info c <char_id> ����ĳһ��ɫ��Ϣ\n"+
			"	info a <area_id> ����ĳһ������Ϣ\n"+
			"���ӣ�  info c lv bu \n"+
			"	���г��й�������һЩ��Ϣ��\n"+
			"�ο���	����listcountry, listchar �� listarea �г�\n"+
			"	���ң���ɫ�͵����嵥��\n");
		return;
	}
	switch(p_type)
	{
	case "a":
		infoa(p_name);
		return;
	case "c":
		infoc(p_name);
		return;
	case "n":
		infon(p_name);
		return;
	}
}
