// localcontributaion.c
// by fire on Dec 1998
// Modified by suicide for inc �ڷܶ� when inc localcontribution
// in 2000.08.08
mixed get_char(string id,string what);
string set_char(string id,string what,mixed val);
int increase_nation_contribution(string p_id,int inc) {
	mixed nc;
	string nat,area;
	nc=get_char(p_id,"nc");
	if(!mapp(nc)) nc=([]);
	area=get_char(p_id,"area");
	nat=AREA_D->get_area(area,"nation");
	if(!COUNTRY_D->nation_exist(nat)) return 0;
        nc[nat]+=inc;
	nat=get_char(p_id,"nation");
	if(COUNTRY_D->get_country(nat,"gs")==p_id) {
		int p_gsx;
		p_gsx=COUNTRY_D->get_country(nat,"gsx");
		p_gsx+=inc;
		if(p_gsx>500) p_gsx=500;
		if(p_gsx<0) p_gsx=0;
		COUNTRY_D->set_country(nat,"gsx",p_gsx);
	}
	set_char(p_id,"nc",nc);
	return 1;
}
int get_nation_contribution(string p_id) {
	mixed nc;
	string nat,area;
	nc=get_char(p_id,"nc");
	if(!mapp(nc)) nc=([]);
	area=get_char(p_id,"area");
	nat=AREA_D->get_area(area,"nation");
	if(!COUNTRY_D->nation_exist(nat)) return 0;
	return nc[nat];

}
int getchar_localcontribution(string p_id,string p_area)
{
   int nc,lc;
   mixed p_con;
   if(CHAR_D->get_char(p_id,"is_tmp")) return 0;
   if((!p_area)||(p_area==""))
   {
      p_area=CHAR_D->get_char(p_id,"area");
   }
   if(!AREA_D->area_exist(p_area))
        return 0;
   if(!CHAR_D->char_exist(p_id))
       return 0;
   p_con=CHAR_D->get_char(p_id,"lc"); // means localcontribution
   if(!p_con) p_con=([]);
   lc=p_con[p_area];
   nc=get_nation_contribution(p_id);
   return (lc*2+nc+1)/3;
}
int increase_localcontribution(string p_id,int inc,string p_area) {
   mixed p_con;
   if((!p_area)||(p_area==""))
   {
      p_area=CHAR_D->get_char(p_id,"area");
   }
   if(!AREA_D->area_exist(p_area))
        return -1;
   if(!CHAR_D->char_exist(p_id))
        return -1;
   p_con=CHAR_D->get_char(p_id,"lc");
   if(!p_con) p_con=([]);
   
   if (inc>=3)   //Added by  suicide in 2000.08.08
     CHAR_D->set_char(p_id,"tsx",CHAR_D->get_char(p_id,"tsx")+1);
   
   p_con[p_area]=p_con[p_area]+inc;
   CHAR_D->set_char(p_id,"lc",p_con);
   increase_nation_contribution(p_id,inc);
   return 1;

}
int setchar_localcontribution(string p_id,int para_value,string p_area)
{
   int oldval;
   if((!p_area)||(p_area==""))
   {
      p_area=CHAR_D->get_char(p_id,"area");
   }
   oldval=getchar_localcontribution(p_id,p_area);
   return increase_localcontribution(p_id,para_value-oldval,p_area);

}
// this is for char's honor
// when a char finish some task, he maybe reward some
// honor, then he can transfer the honor to other reward
// he want
int add_honor_point(string p_id,int n) {
	int old_n=CHAR_D->get_char(p_id,"hon");
	CHAR_D->set_char(p_id,"hon",old_n+n);
	increase_localcontribution(p_id,n/5,"");
	tell_user(p_id,"��ĵ�����������ˡ�\n");
	return CHAR_D->get_char(p_id,"hon");
}

string tran_honor_point(string p_id,string what, int n) {
	int hon;
	int val,tmp;
	string swhat,nat;
	nat=CHAR_D->get_char(p_id,"nation");
	hon=get_char(p_id,"hon");
	if((what=="")||!what) return "��Ŀǰӵ��"+hon+"���������㡣\n"+
		"�����취��cmd honour <ʲô> <����>\n"+
		"���磺cmd honour reputation 20  �൱�ڽ���20�����������\n"+
		"��Ч�Ľ����У� reputation(���� 1:1)  gold(�𣬴ӹ������ 10:1)\n"+
		"               loyalty(�ҳ϶� 10:1 ) zgxy(�ι����� 2:1)\n"+
		"               bfxy(�������� 2:1 )   wxxy(��ѧ���� 2:1)\n";

	if(n<=0) return "�������٣�\n";
	if(hon<n) return "����������㲻����\n";
	if(n>200) return "һ�ν���ô�࣬����Ϳ�ġ�\n";
	switch(what) {
	case "reputation":
		swhat="������";
		val=n;
		tmp=CHAR_D->get_char(p_id,"reputation");
		CHAR_D->set_char(p_id,"reputation",tmp+val);
		break;
	case "gold":
		swhat="���ƽ�";
		if(n<10) return "������Ҫ10���ƽ�\n";
		if(MONEY_D->get_all_money(find_body(p_id))>50000000)
			return "���Ǯ�����ˣ������ٽ����ƽ��ˡ�\n";
		val=n/10;
		tmp=COUNTRY_D->get_country(nat,"gold");
		if(val>tmp) return "���ǹ���û��ô��Ǯ�����㡣\n";
		COUNTRY_D->set_country(nat,"gold",tmp-val);
		MONEY_D->add_poket_money(find_body(p_id),val*10000);
		break;
	case "loyalty":
		swhat="���ҳ϶�";
		val=n/10;
		CHAR_D->set_char(p_id,"loyalty",
			CHAR_D->get_char(p_id,"loyalty")+val);
		break;
	case "wxxy": // wuli
		val=n/2;
		swhat="����ѧ����";
		find_body(p_id)->award_exp(val,"sk_wuli");
		break;
	case "zgxy": // meili
		val=n/2;
		swhat="���ι�����";
		find_body(p_id)->award_exp(val,"sk_meili");
		break;
	case "bfxy": // zhimou
		val=n/2;
		swhat="���������";
		find_body(p_id)->award_exp(val,"sk_zhimou");
		break;
	default :
		return "û��"+what+"���ֽ�����\n";
	}
	CHAR_D->set_char(p_id,"hon",CHAR_D->get_char(p_id,"hon")-n);
	return "��õ���"+val+swhat+"��\n";

}
