// funs.c
// by fire on Oct/07/99
// this is used to handle event of house system
// it is called by m_age
int check_ky(string p_id);
int home_pay(string p_id);
int main(string p_id) {
	int p_day,p_month,p_year;
	object o;
	o=find_body(p_id);
	if(!objectp(o)) return -1;
	p_day=o->query_ag_day();
	if(p_day==3) {	return check_ky(p_id); }
	if(p_day==1) {  return home_pay(p_id); }
	
}
int check_ky(string p_id) {
	int p_gold;
	int p_lose;
	object o;
	string msg;
	p_gold=CHAR_D->get_char(p_id,"gold");
	if(p_gold<100) return -1; // not enough money
	o=SGHOME(p_id);

	if(objectp(o)) {
		return 1; // have home
	}

	p_lose=p_gold/100+1;
	CHAR_D->set_char(p_id,"gold",p_gold-p_lose);
	msg="�Ŀ��ٺ����Ϊû�з��ڼ���������ܹ�̰����"+
		chinese_number(p_lose)+"���ƽ�";
	CHANNEL_D->deliver_tell("rumor","system",
		CHAR_D->get_char(p_id,"name")+msg);
	tell_user(p_id,"��"+msg+"\n");
	return 0;
}

int home_pay(string p_id) {
	int p_money,p_sal;
	string *ls,msg,s;
	object o=find_body(p_id);
	object oh;
	mixed tmp;
	if(!objectp(o)) return -1;
	oh=SGHOME(p_id);
	if(!objectp(oh)) return -1;
	p_money=MONEY_D->get_all_money(o);
	ls=oh->get_npc("list");
	p_sal=0;
	if(sizeof(ls)) {
		foreach(string l in ls) 
			p_sal+=oh->get_npc(l,"salary");
	}
	p_sal*=100;
	if(p_money<p_sal) {
		MONEY_D->sub_all_money(o,p_money);
		s=ls[0];
		oh->remove_npc(s);
		msg="�ҵ�Ӷ��"+oh->get_npc(s,"name")+"��Ϊû���쵽��Ǯ��һ��֮�£����ˡ�";
		CHANNEL_D->deliver_tell("rumor","system",
			CHAR_D->get_char(p_id,"name")+msg);
		tell_user(p_id,"��"+msg+"\n");
		return -2;

	}
	MONEY_D->sub_all_money(o,p_sal);
	p_money-=p_sal;
	if(p_money>200000) {
		tmp=oh->has_zhangfang();
		if(stringp(tmp)) {
			p_sal=random(100000);
			MONEY_D->sub_all_money(o,p_sal);
			msg="����Ϊ"+tmp+"Ӷ����̰����Ǯ"+CHINESE_D->chinese_value(p_sal)+"��";
			CHANNEL_D->deliver_tell("rumor","system",
				CHAR_D->get_char(p_id,"name")+msg);
			tell_user(p_id,"��"+msg+"\n");
			return -3;
		}			
	}		
	return 1;
}