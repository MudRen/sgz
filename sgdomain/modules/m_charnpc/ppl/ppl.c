// the body of ppl
#include <ppl.h>
#define NAME __DIR__+"name"
inherit PMODULES+"m_charnpc";
private int typ;
private string p_surname,p_id,p_givenname;
private int p_age,p_rongmao,p_gender,p_salary;
private string m_id;
mapping get_info () {
	mapping ret=([]);
	ret["typ"]=typ;
	ret["sname"]=p_surname;
	ret["gname"]=p_givenname;
	ret["age"]=p_age;
	ret["rongmao"]=p_rongmao;
	ret["gender"]=p_gender;
	ret["salary"]=p_salary;
	ret["cometime"]=time();
	return ret;
}
string get_p_id() {
	return p_id;
}
int set_salary(int s) {
	p_salary=s;
	return s;
}
void setup()
{
	object jia;
	typ=random(6)+1;
	p_surname=(NAME)->get_surname(typ);
	p_givenname=(NAME)->get_given_name(typ);
	p_age=(NAME)->get_age(typ);
	p_gender=(NAME)->get_gender(typ);
	p_rongmao=(NAME)->get_rongmao(typ);
	p_id=(NAME)->get_id(typ);
	m_id="r"+time()+random(50);	
	p_salary=(NAME)->get_salary(typ);
	p_salary+=p_rongmao;

	set_name(m_id,p_surname+p_givenname);
	add_id("ppl");
	add_id(p_id);
	set_gender(p_gender);
	set_age(p_age);
	set_sg_rongmao(p_rongmao);
	set_in_room_desc((NAME)->get_desc(typ)+p_surname+p_givenname+"("+p_id+")");
	//printf("NAME = %s, typ = %d\n",NAME,typ);
	jia=OBJ_D->clone_obj((NAME)->get_dress(typ));
	jia->move(this_object());
	jia->do_wear();

   	add_question("followme","followme");
	
	add_ask_str("followme","$N��$Tһ���ֵ���$R�ڼ����߶�û��˼��\n"+
"���Ҽ�ȥ���°ɣ��г��к���Ǯ�����������ġ�\n");
	
}


int is_ppl() {
	return 1;
}
mixed can_ask_followme(object who) {
	int r_num,n_num;
	string m_id=who->query_primary_id();
	object o_h;
	o_h=SGHOME(m_id);
	if(!objectp(o_h)) 
		return "$N��$T�������Լ���û�ҿɻأ�������ȥ��ң���ţ��\n";
	r_num=o_h->get_room("size");
	n_num=o_h->get_npc("size");
	if(n_num>r_num)
		return "$N��$T������ҵط�̫С����̫�࣬�Ҳ���ȥ��\n";
	return 1;
}

void answer_yes(object me, object who,string ans) {
	object o_h;
	if(ans!="yes") {
		me->targetted_action(
		"$N�����ض�$T˵����һ�����Ӷ����ϸ���$rҲ̫С���ˡ�\n",who);
		me->simple_action("$Nת���뿪�ˡ�\n");
		destruct(me);
		return;
	}
	if(MONEY_D->sub_poket_money(who,10000)!=1) {
		who->targetted_action(
			"$Nһģ�ڴ�����һ�죬��$T������˼��˵���Բ�������û�д�Ǯ��\n",me);
		me->targetted_action(
		"$N�����ض�$T˵����������һ�����Ӷ�û�У�$rҲ̫С���ˡ�\n",who);
		me->simple_action("$Nת���뿪�ˡ�\n");
		destruct(me);
		return;
	}
	who->targetted_action(
		"$N��$Tһ�����ӡ�\n",me);
	me->responda("rich");
	me->targetted_action(
		"$N��$T˵������׼��һ�£����͵�$R����ȥ��\n",who);
	o_h=SGHOME(who->query_primary_id());
	o_h->add_npc(me);
	me->simple_action("$Nת���뿪�ˡ�\n");
	destruct(me);
}

void answer_salary(object me, object who,string ans) {
	
	int m_salary=to_int(ans);
	me->clear_answer();
	if(m_salary<=p_salary) {
		me->targetted_action(
		"$N�����ض�$T˵����һ�²�"+CHINESE_D->chinese_value(m_salary*100)+
		"��$rҲ̫С���ˡ�\n",who);
		me->simple_action("$Nת���뿪�ˡ�\n");
		destruct(me);
		return;
	}
	p_salary=m_salary;
	me->responda("jump");
	me->targetted_action(
		"$N��$T����$R����̫���ˣ������һ���Ҫһ�����ӵĶ��𣬿��Ը�����\n",who);
	tell(who,"�� answer yes to "+p_id+" ��ʾͬ�⡣\n");

	me->set_answer(who->query_primary_id(), (:answer_yes:) ); 

}


void special_answer(object who, string matt)
{
	mixed ret;
  	switch(matt)
	{
	      case "followme" :
		ret=can_ask_followme(who);
		if(stringp(ret)) {
			this_object()->targetted_action(ret,who);
			return;
		}
		this_object()->responda("consider");
		this_object()->targetted_action(
			"$N��$T��������Ҷ�����Ǯѽ��\n",who);
		tell(who,"�� answer <����> to "+p_id+" ���ش� <����> ����ÿ�¶��������ӡ�\n");
		this_object()->set_answer(who->query_primary_id(), (:answer_salary:) );
       	        return;
  	}
}
string query_name() {
	return p_surname+p_givenname;
}