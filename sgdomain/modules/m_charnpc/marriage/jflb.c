// written by yuner and fire 
/* Do not remove the headers from this file! see /USAGE for more info. */
inherit M_CHAR;
inherit LIVING;

void setup()
{
    set_name("jiaohang laoban", "�����ϰ�");
    set_gender(1);
    set_in_room_desc("ɫ���Ե�%^YELLOW%^�����ϰ�%^RESET%^(jiaohang laoban)");
    add_id("laoban");
    set_age(40);

    add_ask_str("jiaozi","$N��$T�����ϰ壬����Ҫһ�����Ρ�\n");
    add_question("jiaozi","jiaozi" );

}
string long() {
	return
"һ��ɫ���Ե�%^YELLOW%^�����ϰ�%^RESET%^��\n";
}

mixed ask_jiaozi(object who) {
	int p_gender;
	string p_boy,p_girl;

	p_boy=who->query_primary_id();

	p_gender=who->query_gender();
	if(p_gender==2) return "$N��$T����һ�ۣ�ɫ���Ե�˵����С����Ҫʲô���Σ�\n"+
		"�������ס���ˣ�������������Ρ�\n";
	p_girl=CHAR_D->get_char(p_boy,"pri_mar");
	if(!p_girl) 
		return "$N��$TЦ����Ҫ�뻨�α����ã���ȥ����ү����Ǽ�һ�°ɡ�\n";
	if(p_boy!=CHAR_D->get_char(p_girl,"pri_mar"))
		return "$N��$TЦ�������ǹ�ϵ�������ף�Ҫ�뻨�α����ã�ȥ����ү������µǼ�һ�°ɡ�\n";
		
	if(objectp(CHAR_D->find_char("jiaofu tou"))) 
		return "$N��$TЦ�������Ӷ����ȥ�ˣ���һ�������ɡ�\n";
	if(objectp(CHAR_D->find_char("li guan"))) 
		return "$N��$TЦ���������������ھ��л��������ٵȵȰɡ�\n";

	return 1;
}
void pay(string p_boy,int price) {
	object o_boy;
	int p_money;
	string p_girl;
	p_girl=CHAR_D->get_char(p_boy,"pri_mar");
	o_boy=find_body(p_boy);
	if(!objectp(o_boy)) return;
	o_boy->simple_action("$N������˵����˵����͸�Ǯ��\n");
	p_money=o_boy->query_all_con_money();
	price*=10000;
	if(p_money<price) {
		o_boy->simple_action("$NͻȻ��һ�������������Ǯû������\n");
		this_object()->responda("admit "+p_boy);
		return;
	}
	
	o_boy->set_all_con_money(p_money-price);
	price/=10000;
	o_boy->targetted_action("$N����$T"+chinese_number(price)+"�����ӡ�\n",this_object());
	DELAY_D->delay_simple_action(this_object(),"$N����ص��˵����е�Ǯ��\n",2);
	DELAY_D->delay_targetted_action(this_object(),o_boy,"$N��$T���������Ѿ�׼�����ˣ�����%^YELLOW%^����%^RESET%^����ȥ�ѡ�\n",2);
	CHAR_D->add_char("jiaofu tou");
	CHAR_D->set_char("jiaofu tou","body","marriage/cgs");
	CHAR_D->set_char("jiaofu tou","is_tmp",1);
	CHAR_D->appear("jiaofu tou","wujun","wj_hq","$N����һ�����׶��鿪�˹�����\n");
	CHAR_D->find_char("jiaofu tou")->set_boygirl(p_boy,p_girl);
	CHAR_D->remove_char_d("jiaofu tou");
	tell(users(),"%^H_RED%^�����񡿽����ϰ�ɫ���Ե�˼���ţ�����"+
	CHAR_D->get_char(p_boy,"name")+"��Ҫ��"+CHAR_D->get_char(p_girl,"name")+"�з����к�Ϸ���ˡ��ٺ�. . . \n");
}
void before_check(object who) {
	string p_boy,p_girl;
	object o_boy,o_girl;
	string msg;
	int price;
	int p_rongmao;
	p_boy=who->query_primary_id();
	o_boy=CHAR_D->find_char(p_boy);
	p_girl=CHAR_D->get_char(p_boy,"pri_mar");
	o_girl=CHAR_D->find_char(p_girl);
	if((!objectp(o_girl))||(o_girl->query_room()!=this_object()->query_room())) {
		this_object()->targetted_action("$N��$T����С����������ѽ��Ҫ���������źñ��Ρ�\n",o_boy);
		return;
	}
	p_rongmao=CHAR_D->get_char(p_girl,"gift")["rongmao"];
	this_object()->targetted_action("$N����ɫ�ۣ���$T���ϵ�������ϸϸ�ؿ���һ�ߡ�\n",o_girl);
	this_object()->respanda("look "+p_girl);
	if(p_rongmao>25) {
		msg="$N��$Tѽ��һ���������ˣ������ˣ�"+CHAR_D->get_char(p_boy,"name")+"�������ҵ����������ܲ����ˡ�\n"+
			"һ��Ҫ��ͷ�Ȼ��Σ�˵�ſ�ˮ�����˳�����\n";
		price=100;
	}
	else if(p_rongmao>20) {
		msg="$N��$T����С���ó��ò���ѽ��Ҫ�����ϵȻ��Σ�˵����$t������������һ�ѡ�\n";
		price=50;
	}
	else if(p_rongmao>15) {
		msg="$N��$o����������Ż����ԣ����ò���̫�ã��Ͱ��Ÿ���ͨ���Ӱɡ�\n";
		price=20;
	}
	else {
		msg="$N��$Tѽ��һ������ô���Ѿͷ����֪"+CHAR_D->get_char(p_boy,"name")+"�������ҵ��ģ����ܲ����ˡ�\n"+
			"���ҿ��������Ǹ����˽��Ӱɡ�\n";
		price=10;
	}
	this_object()->targetted_action(msg,o_girl,o_boy);

	DELAY_D->delay_targetted_action(this_object(),o_boy,"$N��$T��������"+chinese_number(price)+
		"�����ӣ�$R�����Ƚ�Ǯ�ɡ�\n",3);
	call_out("pay",6,p_boy,price);
}
void special_answer(object who, string matt)
{
	mixed ret;
	string p_id;
	p_id=who->query_primary_id();
        switch(matt)
        {
                case "jiaozi" :
			ret=ask_jiaozi(who);
			if(stringp(ret)) {
				this_object()->targetted_action(ret,who);
				return;
			}
			before_check(who);
        }
}
