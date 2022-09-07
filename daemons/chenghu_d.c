// by fire on Dec 31 1997
// chenghu_d.c the �ƺ�ϵͳ
#include <ansi.h>
inherit M_ANSI;
string *lvs=({ "Ŀ��ʶ��","��ͨ����","����ʶ��","С���Ĳ�",
"�±�ǧ��","�������","����ï��","��������","����Т��","ǧ���ĺ�",});
string *cls=({RED,GRN ,ORG, BLU ,MAG ,CYN ,WHT ,HIR ,HIG ,HIY ,HIB ,HIM ,HIC ,HIW ,});
string *ju_name=({"����","���ں�","ͤ��","���","�غ�","�о�","�Ӿ�","��","��","��","��"});
string *ju_color=({WHT,ORG,RED,GRN,BLU,MAG,HIR,HIG,HIB,HIC,HIY,});
int *ju_rep=({10000,20000,50000,70000,100000,120000,140000,160000,180000,1000000});
int *ju_lit=({50,100,200,500,700,1000,1500,2000,2500,3000});

string stat_me_ju() {
	string ret;
	int i,sum;
	sum=sizeof(ju_name);
	ret="�ȼ�  ��λ    ����Ҫ��    ��ѧҪ��\n";
	for(i=1;i<sum;++i) 
		ret+=sprintf("%2d    %-6s   %7d    %d\n",
			i,ju_name[i],ju_rep[i-1],ju_lit[i-1]);
	return ret;

}
int query_ju_lit(int i) {	return ju_lit[i];
}
int query_ju_rep(int i) {	return ju_rep[i];
}
string query_ju_str (int i) {
	if(i>=sizeof(ju_name)) i=sizeof(ju_name)-1;
	return ju_color[i]+ju_name[i];
}
string query_char_jun (string p_id) {	int j, n;
	string ss, s="";
	j=CHAR_D->get_char(p_id,"ju");
	if(j) {		
		s=CHAR_D->get_char(p_id,"ju_n");
		if(!sizeof(s))
			s=AREA_D->get_area(
				CHAR_D->get_char(p_id,"area"),"name");
			}
	s = s+query_ju_str(j);
	ss = colour_truncate(s,8);
	if( (n=10-strlen(ss))<=0 ) return s;
	j = n>>1;
	if( n%2&&10%2) j++;
	return power_str(" ",j) + s + power_str(" ",n-j);
}
string query_char_jun_who(string p_id) {
	return ju_color[CHAR_D->get_char(p_id,"ju")]+"��"+query_char_jun(p_id)+"��"+NOR;
	}
string query_chenghu_C(object w1, object w2) //��ʾ�׽������ҳƺ���ͨ���ڶԻ���
{	int p_gender;
	int p_age1,p_age2;
	string p_id1,p_id2;
	if(!w2->is_living()) return "����";
	p_age1=w1->query_age();
	p_age2=w2->query_age();
	p_gender=w1->query_gender();
	p_id1=w1->query_primary_id();
	p_id2=w2->query_primary_id();
	if(p_gender==1)  // male
	{
		if(CHAR_D->get_char(p_id1,"mar")==p_id2)
			return "Ϊ��";
		if((p_age1-p_age2)>50)			return "үү";
		if((p_age1-p_age2)>15)			return "����";
		if((p_age1-p_age2)>=0)			return "�ֳ�";
		if((p_age2-p_age1)>50)			return "���";
		if((p_age2-p_age1)>15)			return "ֶ��";
		return "С��";
	}
	else  // female
	{
		if(CHAR_D->get_char(p_id1,"mar")==p_id2) return "���";
		if((p_age1-p_age2)>50)			return "����";
		if((p_age1-p_age2)>15)			return "����";
		if((p_age1-p_age2)>=0)			return "���";
		if((p_age2-p_age1)>50)			return "��Ů";
		if((p_age2-p_age1)>15)			return "ֶŮ";
		return "С��";
	}
}
string query_chenghu_c(object w1,object w2)  //��ʾ�׽��ĶԷ��ƺ���ͨ���ڶԻ���
{	int p_gender;
	int p_age1,p_age2;
	string p_id1,p_id2;
	if(!w2->is_living()) return "����";
	p_age2=w1->query_age();
	p_age1=w2->query_age();
	p_gender=w2->query_gender();
	p_id1=w1->query_primary_id();
	p_id2=w2->query_primary_id();
	if(p_gender==1)  // male	
	{	if(CHAR_D->get_char(p_id1,"mar")==p_id2) return "���";
		if((p_age1-p_age2)>=50)			return "����";
		if((p_age1-p_age2)>=15)			return "����";
		if((p_age1-p_age2)>0)			return "�ֳ�";
		if((p_age2-p_age1)>=50)			return "���";
		if((p_age2-p_age1)>=15)			return "��ֶ";
		return "�͵�";
	}	else  //	female
	{	if(CHAR_D->get_char(p_id1,"mar")==p_id2) return "����";
		if((p_age1-p_age2)>=50)			return "����";
		if((p_age1-p_age2)>=15)			return "����";
		if((p_age1-p_age2)>0)			return "���";
		if((p_age2-p_age1)>=50)			return "��Ů";
		if((p_age2-p_age1)>=15)			return "ֶŮ";
		return "����";
	}
}
string query_chenghu_S(object who) //���������ҳƺ���ͨ���ڶԻ���
{	if(who->query_is_junzhu())  // �Ƿ����
return "��";
	if(who->query_is_jiangjun()) // �Ƿ񽫾�
		return "������";
	if(who->query_is_guan())  // �Ƿ�Ϊ��
		return "����";
	if((who->query_gender())!=1)
		return "��Ů";
	return "����";
}
string query_chenghu_s(object who)  //ǫ�������ҳƺ���ͨ���ڶԻ���
{	if(who->query_is_junzhu())  // �Ƿ����
		return "����";
	if(who->query_is_jiangjun()) // �Ƿ񽫾�
		return "ĩ��";
	if(who->query_is_guan())  // �Ƿ�Ϊ��
                return "��ְ";
	if((who->query_gender())!=1)
		return "СŮ��";
	return "С��";
}
string query_chenghu_R(object me, object who)  //�����ĶԷ��ƺ�
{	int p_age;
	string p_id,t_id;
	if(!objectp(me)) me=who;
	if(!objectp(who)) who=me;
	p_id=me->query_primary_id();
	t_id=who->query_primary_id();
	if(!who->is_living()) return "����";
	p_age=who->query_age();
	if((who->query_gender())==1)	{
		if(CHAR_D->get_char(p_id,"mar")==t_id)	return "���";
		if(who->query_is_junzhu())  // �Ƿ����
			return "����";
		if(who->query_is_jiangjun()) // �Ƿ񽫾�
		{
			if(p_age>60)	return "�Ͻ���";
			if(p_age>20)
				return "����";
			return "С����";
		}		if(who->query_is_guan())  // �Ƿ�Ϊ��
			return "����";
		if(p_age>50)			return "������";
		if(p_age>20)			return "����";
		return "С�ֵ�";
	}
	else //female
	{	if(CHAR_D->get_char(p_id,"mar")==t_id)	return "����";
		if(who->query_is_junzhu())  // �Ƿ����	
		return "Ů������";
		if(who->query_is_jiangjun()) // �Ƿ񽫾�
		{	if(p_age>60)	return "�Ͻ���";
			if(p_age>20)	return "Ů����";
			return "С����";
		}
		if(who->query_is_guan())  // �Ƿ�Ϊ��
			return "����";
		if(p_age>50)	return "������";
		if(p_age>30)	return "����";
		if(p_age>20)	return "����";
		return "С����";
	}
}
string query_chenghu_r(object me, object who)  //����ĶԷ��ƺ���
{	int p_age;
	string p_id,t_id;

	if(!objectp(me)) me=who;
	if(!objectp(who)) who=me;

	if(!who->is_living()) return "����";
	p_id=me->query_primary_id();
	t_id=who->query_primary_id();
	p_age=who->query_age();
;
	if((who->query_gender())==1)	{
		if(CHAR_D->get_char(p_id,"mar")==t_id)	return "����";
		if(who->query_is_junzhu())  // �Ƿ����	
			return "���";
		if(who->query_is_jiangjun()) // �Ƿ񽫾�	
		{	if(p_age>60)	return "����";
			if(p_age>20)	return "����";
			return "С��";
		}
		if(who->query_is_guan())  // �Ƿ�Ϊ��
			return "���";
		if(p_age>50)	return "�ϲ�����";
		if(p_age>20)	return "����";
		return "С�쵰";
	}	else //female
	{
		if(CHAR_D->get_char(p_id,"mar")==t_id)	return "�˻�";
		if(who->query_is_junzhu())  // �Ƿ����
			return "����";
		if(who->query_is_jiangjun()) // �Ƿ񽫾�	
		{ if(p_age>60)	return "��Ů��";
			if(p_age>20) return "Ů��";
			return "С��";
		}
		if(who->query_is_guan())  // �Ƿ�Ϊ��
			return "���";
		if(p_age>50)
			return "������";
		if(p_age>30)
			return "�ϼ���";
		if(p_age>20)	return "����";
		return "С����";
	}	
}
string literate_str(int i) {
      if(i<10) return cls[0]+lvs[0]+NOR;
      if(i<50) return cls[1]+lvs[1]+NOR;
      if(i<100) return cls[2]+lvs[2]+NOR;
      if(i<200) return cls[3]+lvs[3]+NOR;
      if(i<500)  return cls[4]+lvs[4]+NOR;
      if(i<1000) return cls[5]+lvs[5]+NOR;
      if(i<1500) return cls[6]+lvs[6]+NOR;
      if(i<2000) return cls[7]+lvs[7]+NOR;
      if(i<3000) return cls[8]+lvs[8]+NOR;
      return cls[9]+lvs[9]+NOR;
 }
