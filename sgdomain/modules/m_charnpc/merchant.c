// the body of merchant
inherit PMODULES+"m_charnpc";
private mixed p_custom;
private string p_stage,p_for,p_what,n_id;
private int p_discount,p_count;
private int arg_time;
void trade_process();
void answer_buy(object who);
int my_bargen(int sug);
void my_cancel();
void my_deal();
void award(object o);
void setup()
{
   move_setup();
   add_question("goods","goods");
   add_question("buy","buy");
   add_ask_str("goods","$N��$Tһ���ֵ��������ϰ壬���������Щʲô��ɫ����$S������\n");
   add_ask_str("buy","$N��$T�����ѻ����Ȱ����������$SҪ��������\n");
}
string long()
{
   string p_id;
   p_id=COUNTRY_D->get_country(n_id,"name");
   return p_id+"�̶ӣ�һЩ�������ڲ��ϵؽ����С�\n";
}
string query_title(string p_id,string c_id)
{
   string p_nationname;
   p_nationname=COUNTRY_D->get_country(CHAR_D->get_char(p_id,
	   "my_nation"),"name");
   return p_nationname+"�̶�("+p_id+")";
}
void answer_good(object who)
{
   string *lis;
   int i;
   string ans;
   lis=(EV_MERCHANT)->query_m_goods(n_id,"list","");
   if(!sizeof(lis))
   {
     this_object()->simple_action(
       "$N������˼��˵����������ȫ��������\n");
      return;
   }
   ans="$N�𵽣����������´����\n";
   this_object()->simple_action(ans);
ans="����      ��Ǯ              ����     \n"+
"������������������������������������������������������������������\n";
   for(i=0;i<sizeof(lis);++i)
   {
     ans+=sprintf("%-10s%-16s  %s\n",
       (EV_MERCHANT)->query_m_goods(n_id,lis[i],"name"),
       CHINESE_D->chinese_value(100*
         (EV_MERCHANT)->query_m_goods(n_id,lis[i],"price")),

		 chinese_number((EV_MERCHANT)->query_m_goods(n_id,lis[i],"quantity")));
   }
  write(ans);
}
void special_answer(object who, string matt)
{
  switch(matt)
  {
      case "goods" :
         answer_good(who);
		 return;
	  case "buy":
		 answer_buy(who);
		 return;
  }
}
void answer_buy(object who)
{
   string *lis;
   string p_id;
   p_id=who->query_id()[0];
   if(!COUNTRY_D->nation_exist(CHAR_D->get_char(p_id,"nation")))
   {
		this_object()->targetted_action
			("һ$N��$T����ص�������ֻ�͹ټ������⡣\n",who);
		return;
   }
   if(p_id==p_custom)
   {
		this_object()->targetted_action
			("��$N��$T����Ц������$m$R��ô��Ϳ�ˣ������ϱ����⻹û̸���ء�\n",who);
		return;
   }
   if(stringp(p_custom)&&find_user(p_custom)&&present(p_id,environment(this_object())))
   {
		this_object()->targetted_action
			("һ$N��$T��æ��Ц������$m$R��Ϣŭ��С���������һ�꣬���Ͼͺ�$R̸��\n",who);
		return;
   }
   lis=(EV_MERCHANT)->query_m_goods(n_id,"list","");
   if(!sizeof(lis))
   {
     this_object()->simple_action(
       "$N������˼��˵����������ȫ��������\n");
      return;
   }
   p_custom=p_id;
   p_stage="begbuy";
   trade_process();
   remove_call_out("trade_over");
   call_out("trade_over",90);
}
void trade_over()
{
	object custom;
	custom=find_body(p_custom);
	if((!objectp(custom))||(environment(this_object())!=environment(custom)))
	{
		p_custom=0; return;
	}
	this_object()->targetted_action(
		"һ$N��$T��������$R��û������ʲô������������ɡ�\n",find_body(p_custom));
	custom=find_user(p_custom);
	if(objectp(custom))
		custom->modal_pop();
	p_custom=0;
	return;
}
string get_action()
{
	switch(p_stage)
	{
	case "begbuy":
		return "$N��$T����$R��Ϊ���ɶ��򣬻���Ϊ�ԼҶ���ѽ��\n";
	case "buywhat":
		return "$N��$T����$RҪ��Щʲô��\n";
	case "howmany":
		return "$N��$T����$RҪ�����ٻ���\n";
	case "bargen":
		return "$N��$T��Ц����$m$RҪ�����ھͽ�Ǯ������\n";
	default:
		return "$N��Ȼ��֪������ô�졣\n";
	}
}
string get_prom()
{
	string *lis;
	int i,s;
	string ret="";
	lis=(EV_MERCHANT)->query_m_goods(n_id,"list","");
	s=sizeof(lis);
	switch(p_stage)
	{
	case "begbuy":
		return "1 Ϊ������2  Ϊ�Լ���\n";
	case "buywhat":
		if(!s) return "BUG �� BUG ������\n";
		for(i=1;i<=s;++i)
			ret+=sprintf("%d  %s��",i,
				(EV_MERCHANT)->query_m_goods(n_id,lis[i-1],"name"));
		return ret;
	case "howmany":
		ret=sprintf("�����ٻ���[ 1 -- %d ]\n",
			(EV_MERCHANT)->query_m_goods(n_id,p_what,"quantity"));
		return ret;
	case "bargen":
		return "��ѡ��1 - 9�����ۣ�10��������-1��������\n" ;
	default:
		return "������BUG�ˡ�\n";
	}
}

void trade_input(string str)

{

	string *lis;


	object o;

	int i,s;

	lis=(EV_MERCHANT)->query_m_goods(n_id,"list","");

	s=sizeof(lis);

	switch (p_stage)

	{

	case "begbuy":

		if(str=="2")

		{	this_body()->simple_action("$N����Ϊ�ԼҰ�㡣����\n");

			p_for="self";

		}

		else{

			this_body()->targetted_action("$N��$T����������ǹ��ɣ����㡣\n",this_object());

			p_for="area";

		}

		p_stage="buywhat";

		break;
	case "buywhat":
		i=to_int(str);
		if((i<1)||(i>s))
		{
			write("��ʲô��\n");
			return;
		}
		p_what=lis[i-1];
		this_body()->targetted_action("$N��$T�����Ƚ���"+
			(EV_MERCHANT)->query_m_goods(n_id,p_what,"name")+"��\n",this_object());
		p_stage="howmany";
		break;
	case "howmany":
		{
			int price,total_price;
			i=to_int(str);
			s=(EV_MERCHANT)->query_m_goods(n_id,p_what,"quantity");
			if((i<1)||(i>s))
			{	write("����٣�\n");
				return;
			}
			this_body()->simple_action(
				"$N�����Ƚ�"+chinese_number(i)+"��\n");
			price=(EV_MERCHANT)->query_m_goods(n_id,p_what,"price");
		total_price=price*i;
			if(total_price<1000) // less than 10 gold
			{
				this_object()->simple_action(
					"��$N�׷׵�����Ҳ̫С���˵�ɣ�����һ�γ���������Ҫʮ�����ӡ�\n");
				return;
			}
			p_count=i;
		p_stage="bargen";
			p_discount=0;
			arg_time=0;
		}
		break;
	case "bargen":
		i=to_int(str);
		if(i==-1)
	{	this_body()->simple_action(
				"$N�������ˣ��Ҳ������ˡ�\n");
			my_cancel();return;
		}
		if(i==10)
		{	
			this_body()->targetted_action(
			"$N��$T̾�������ˣ����ˣ�������Ҳ����ĥ��Ƥ���Ͱ���۰ɡ�\n",this_object());
			p_discount=10; 
			o=find_user(p_custom);
			if(objectp(o))
				o->modal_pop();
			my_deal(); return;
	}
		if((i>0)&&(i<10))
		{
			i=my_bargen(i);
			if(i==1) {
				o=find_user(p_custom);
				if(objectp(o))
					o->modal_pop();
				my_deal(); return;
		}
		}
		break;
	default:
	break;
	}
	o=find_user(p_custom);
	if(objectp(o))
		o->modal_pop();
	call_out("trade_process",1);
}
void my_deal()
{
        int p_goldneed,n_bank,p_goldhave;
	p_goldneed=
		(EV_MERCHANT)->query_m_goods(n_id,p_what,"price")*p_count*p_discount*10;

	this_object()->targetted_action(
	"$N��$T������Ц����"+chinese_number(p_count)+
		(EV_MERCHANT)->query_m_goods(n_id,p_what,"name")+
		"�Ѿ�׼�����ˣ���ֵ��"+
	CHINESE_D->chinese_value(p_goldneed)+
		"������$m$R���˰ɡ�\n",this_body());
	p_goldneed/=10000;  // now is real use gold
	switch(p_for)
	{
	case "self":
    n_bank=this_body()->query_amt_money("bank");
                if(n_bank < p_goldneed*10000)
		{
			this_body()->targetted_action(
                                "$Nһ���ʣ�ѽ�����á�Ǯׯ���Ǯ������\n"+
                                "$N���϶�$T��Ц����������˼������ͷ��Щ������ͷ����ɡ�\n",this_object());
			call_out("my_cancel",2);
			break;
		}
		this_body()->simple_action(
			"$N�����Ǻðɣ�����ô���ˡ�\n");
		this_body()->targetted_action(
			"$N��$T��������"+chinese_number(p_count)+
		(EV_MERCHANT)->query_m_goods(n_id,p_what,"name")+"��\n",this_object());
		{
			mixed my_army;
			my_army=CHAR_D->get_char(p_custom,"myarmy");
			if(!my_army) my_army=([]);
			if(!my_army[p_what]) my_army[p_what]=0;
			my_army[p_what]+=p_count;
			CHAR_D->set_char(p_custom,"myarmy",my_army);
    n_bank=n_bank-p_goldneed*10000;
    this_body()->set_money("bank", n_bank);
			(EV_MERCHANT)->decrease_count(n_id,p_what,p_count);
		}
		break;
	case "area":
		{
			string p_area;
			p_area=CHAR_D->get_char(p_custom,"area");
			p_goldhave=AREA_D->get_area(p_area,"gold");
			if(p_goldhave < p_goldneed)
			{
				this_body()->targetted_action(
					"$Nһ���ʣ�ѽ�����á�����Ǯ������\n"+
					"$N���϶�$T��Ц����������˼������Ǯ��Щ������ͷ����ɡ�\n",this_object());
				call_out("my_cancel",2);
				break;
		}
	if((PJOB+"localbuy/localbuy")->get_localbuy(p_custom)!=p_what)
		{
				this_body()->targetted_action(
					"$Nһ���ʣ�ѽ�����á�û�õ��ɹ�"+
					(EV_MERCHANT)->query_goods(p_what,"name")+
					"�Ĺ�����\n"+"$N���϶�$T��Ц����������˼����"+
					(EV_MERCHANT)->query_goods(p_what,"name")+
					"֮�²����ҹܡ�������ͷ��̸�ɡ�\n",this_object());
					call_out("my_cancel",2);
					break;
			}
			this_body()->simple_action(
				"$N�����Ǻðɣ�����ô���ˡ�\n");
			this_body()->targetted_action(
				"$N��$T����Ϊ��������"+chinese_number(p_count)+
			(EV_MERCHANT)->query_m_goods(n_id,p_what,"name")+"��\n",this_object());

			this_body()->finish_job("localbuy");
			AREA_D->set_area(p_area,p_what,
				AREA_D->get_area(p_area,p_what)+p_count);
			AREA_D->set_area(p_area,"gold",p_goldhave-p_goldneed);
			(EV_MERCHANT)->decrease_count(n_id,p_what,p_count);
			{
				object o;
				o=find_user(p_custom);
				if(objectp(o))
					ROBOT->robot_test(o,(:award:));
			} 
		}
		break;
	default: 
	}
    {	
		string p_area;
		p_area=AREA_D->check_area
			("area",environment(this_object())->get_area())[0];
		p_goldneed/=5;
		if(p_goldneed)
		{
			AREA_D->set_area(p_area,"gold",
				AREA_D->get_area(p_area,"gold")+p_goldneed);
			COUNTRY_D->set_country(n_id,"gold",
				COUNTRY_D->get_country(n_id,"gold")+p_goldneed);
		}
	}

	remove_call_out("trade_over");
	p_custom=0;
	return;
}
void award(object o)
{
    int isrobot;
	string p_id;
	o=o->query_body();
	if(!objectp(o)) return;
    isrobot=o->query_robot();
    if(isrobot)
	{
		this_object()->targetted_action(
			"һ��$N����$T��ͷ��ɵ�ϣ��ؼ�˯��ȥ�ɡ�\n",o);
		this_object()->simple_action(
			"��$N����һ����ô�Ц��\n");
		return;
	}
	p_id=o->query_id()[0];
    o->award_exp(50);
    CHAR_D->set_char(p_id,"reputation",
		CHAR_D->get_char(p_id,"reputation")+50);
    CHAR_D->set_char(p_id,"localcontribution",
      CHAR_D->get_char(p_id,"localcontribution")+2);
	CHAR_D->set_char_loyalty(p_id,n_id,
		CHAR_D->get_char_loyalty(p_id,n_id)+2);
    o->simple_action("$NΪ��������ɹ���$N�ľ��飬��������"+
		COUNTRY_D->get_country(n_id,"name")+"�Ĺ�ϵ����ˡ�\n");
	if(random(2))
	{
		object ob;
		this_object()->targetted_action(
			"һ��$N������$T˵����л$m$R���գ�����һ��С��˼��\n",o);
		this_object()->targetted_action(
			"%^GREEN%^һ��$N͵͵����$Tһ�����ӡ�\n%^RESET%^",o);
		ob=new(M_GOLD);
        ob->set_m_num(1);
        ob->move(o);
	}
}


void my_cancel()
{
	object custom;
	remove_call_out("trade_over");
	this_object()->targetted_action(
		"һ��$N����ԭ��$T����ˣ���ǡ�\n",this_body());
	this_object()->targetted_action(
		"��$N�׷׵����ɶ񣬿ɶ�\n��$Nһӵ���ϣ���$tʹ����һ�١�\n",this_body());
	CHAR_D->set_char_loyalty(p_custom,n_id,
		CHAR_D->get_char_loyalty(p_custom,n_id)-2);
	this_body()->simple_action(
		"$N�󺰾�����\n$N��"+COUNTRY_D->get_country(n_id,"name")+
		"�Ĺ�ϵ�����ˡ�\n");

	custom=find_user(p_custom);
	if(objectp(custom))
		custom->modal_pop();
	p_custom=0;
	return;

}
int my_bargen(int sug)
{
	string p_act;
	int rel,res=0;
	this_body()->simple_action(
		"$N������Ǯ̫����Ҫ��"+chinese_number(sug)+"�ۡ�\n");
	if(sug<p_discount)
	{
		p_act=sprintf("$N��$Tŭ�����㵱������ɵ�ӣ���%s�۶����У������%s�ۡ�\n",
			chinese_number(p_discount),chinese_number(sug));
	}
	if(sug==p_discount)
	{
		p_act=sprintf("$N�������Ƕ�˵�������𣬻�Ҫ�ᡣ\n");
	}
	if(sug>p_discount)
	{
		rel=CHAR_D->get_char_loyalty(p_custom,n_id);
		rel/=10;
		rel+=sug;
		rel-=arg_time;
		p_discount=sug;
		if((random(21)+5)<rel)
		{
			res=1;
			p_act=sprintf("$N�޿��κεص�����Ȼ$m$R���˵���Ǿ���ô���˰ɡ�\n");
		}
		else
		{	if(random(2))
				p_act="��$N�������в��У�Ҫ������ۣ�����ȫ�����ƺӡ�\n";
			else
				p_act="��$N�������в��У������Ѿ�������ͼۡ�\n";
		}
	}
	this_object()->targetted_action(p_act,this_body());
	arg_time++;
	return res;

}
void trade_process()
{
	string p_prom,p_act;
	object custom;
	custom=find_body(p_custom);
	if((!objectp(custom))||(environment(this_object())!=environment(custom)))
	{
		p_custom=0;
		return;
	}
	p_act=get_action();
	this_object()->targetted_action(p_act,custom);
	p_prom=get_prom();
	tell_user(p_custom,p_prom);
	custom=find_user(p_custom);
	if(objectp(custom))
		custom->modal_push((: trade_input :),">");
}
void remove()
{
	remove_call_out("trade_over");
	::remove();
}
// this is used after all other initiate
void extra_init()
{
	string p_id;
	p_id=this_object()->query_id()[0];
	n_id=CHAR_D->get_char(p_id,"my_nation");
}
void my_charaction(){
}
int query_clean_up()
{
   return 1;
}