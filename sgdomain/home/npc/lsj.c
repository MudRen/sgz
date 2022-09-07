// written by fire 
/* Do not remove the headers from this file! see /USAGE for more info. */
#define HOUSE_D "/daemons/house_d"
#define HOMEKEY "/sgdomain/home/homekey"
inherit M_CHAR;
inherit LIVING;
void setup()
{
    set_name("lao suojiang", "������");
    set_gender(1);
    set_proper_name("������");
    set_in_room_desc("%^YELLOW%^������%^RESET%^(lao suojiang)");
    add_id("lao");
    add_id("suojiang");
    set_age(50);

    add_ask_str("cut","$N��$T����$R�ܲ��ܰ���ﱰѼ����Կ�ף�\n");
    add_question("cut","cut" );

}
string long() {
	return
"%^YELLOW%^������%^RESET%^��û�����򲻿��Ķ�����\n";
}

mixed can_i_have_key(string p_id) {
	mixed hus;
	object me=find_body(p_id);
	hus=CHAR_D->get_char(p_id,"h");
	if(!mapp(hus)) return "$N��$T����$R��û�з��ӣ�����ô������Կ�ס�\n";

	if(MONEY_D->sub_poket_money(me,10000)==-1) 
		return "$N��$T������Կ��Ҫһ�����ӡ������ϵ�Ǯ������\n";
	return 1;

}
private void give_key(string p_id) {
	object me,okey;
	me=find_body(p_id);
	okey=new(HOMEKEY);
	okey->set_owner(p_id);
	this_object()->targetted_action("$N��$T������Կ��Ҫһ�����ӡ�\n",me);
	DELAY_D->delay_simple_action(me,"$N����û���⡣\n",1);
	DELAY_D->delay_targetted_action(me,this_object(),"$N��$Tһ���ƽ�\n",2);
	DELAY_D->delay_targetted_action(me,this_object(),"$T�ӹ�Ǯ����ʼ�Կ�ס�\n",3);

	DELAY_D->delay_targetted_action(me,this_object(),"$Ţ��ͷ��Կ��ﱺ��ˡ�\n",6);
	DELAY_D->delay_targetted_action(me,this_object(),"$N�ӹ�$T�ֹ�����Կ�ף�����ص��˵�ͷ��\n",7);

	okey->move(me);	
}
private void get_my_house(string p_id) {
	mapping my_house,hus;
	object okey;
	my_house=CHAR_D->get_char(p_id,"h");
	hus=CHAR_D->get_char(p_id,"h");
	if(hus["st"]=="updating") {
		object o;
		o=SGHOME(p_id);
		o->set_room("front","l",
			read_file("/sgdomain/home/pic/"+hus["id"]+".pic"));
	}
	else {
		okey=new(HOMEKEY);
		okey->set_owner(p_id);
		this_object()->targetted_action
			("$N��$TЦ������˵��$R�ķ����Ѿ�����ˣ�����Կ�ף���ȥ�����ɡ�\n"+
			 "˵��ָ�$t$O\n",this_body(),okey);
		okey->move(this_body());
	}

	hus["id"]=my_house["id"];
	hus["st"]="new";
	hus["t"]=time();
	hus["a"]=my_house["a"];
	CHAR_D->set_char(p_id,"h",hus);


	CHANNEL_D->deliver_tell("gossip",this_object()->short(),
		"��ϲ��ϲ��"+CHAR_D->get_char(p_id,"name")+
		"��"+AREA_D->get_area(hus["a"],"name")+"��"+
		HOUSE_D->get_house(hus["id"],"name")+"�Ѿ�����ˣ����ȥ����һ�ٰɡ�"); 
}
void special_answer(object who, string matt)
{
	string p_id;
	mixed ret;
	p_id=who->query_primary_id();
        switch(matt)
        {
                case "cut" :
			ret=can_i_have_key(p_id);
			if(stringp(ret)) {
			        this_object()->targetted_action( ret,who);
				return;
			}
			give_key(p_id);
                        return;
        }
}
