// written by fire 
/* Do not remove the headers from this file! see /USAGE for more info. */
#define HOUSE_D "/daemons/house_d"
#define HOMEKEY "/sgdomain/home/homekey"
inherit M_CHAR;
inherit LIVING;
private
void setup()
{
    set_name("lu laoban", "³�ϰ�");
    set_gender(1);
    set_proper_name("³�ϰ�");
    set_in_room_desc("�Ƿ��ɽ�%^H_GREEN%^³�ϰ�%^RESET%^(lu laoban)");
    add_id("lu");
    add_id("laoban");
    set_age(50);

    add_ask_str("buy","$N��$T����$S����һ�䷿��. . . .\n");
    add_question("buy","buy" );

    add_ask_str("move","$N��$T����$S�����ˡ�\n");
    add_question("move","move" );

    add_ask_str("update","$N��$T����$S��ѷ��Ӹ������. . . .\n");
    add_question("update","update" );

    add_ask_str("get","$N��$T����$S�ķ����������\n");
    add_question("get","get" );
}
string long() {
	return
"%^H_GREEN%^³�ϰ�%^RESET%^���ഫ�Ǵ�������³��ĺ��ˣ��Ƴ�������\n";
}

mixed can_i_buy(string p_id,string h_id) {
	int p_price,p_level,my_level;

	if(!CHAR_D->get_char(p_id,"area")) 
		return "$N��$T����$R��û����ض��ӣ�����������㽨��ѽ��\n";
	if(mapp(CHAR_D->get_char(p_id,"h")))
		return "$N��$T����$R�Ѿ���һ�׷����ˣ��Ȱ��������������·��ɡ�\n";
	p_price=HOUSE_D->get_house(h_id,"price");
	if(!p_price) 
		return "$N��$T����$RҪ�ǵķ�������ôû��˵����\n";
	p_level=HOUSE_D->get_house(h_id,"level");
	my_level=CHAR_D->get_char(p_id,"ju");
	my_level++;
	my_level/=2;
	if(my_level<p_level)
		return "$N��$T����$R�ľ�λ̫�ͣ����ܸ������߼��ķ��ӡ�\n";
	if(MONEY_D->sub_all_money(find_body(p_id),p_price*10000)==-1) 
		return "$N��$T����$R��Ǯ���񲻹���������ȥ��취����Ǯ�ɡ�\n";

	return 1;

}
mixed can_i_update(string p_id,string h_id) {
	int p_price,p_level,my_level;
	int p_curprice;
	string cur_house;
	mixed hus;
	object me=find_body(p_id);
	hus=CHAR_D->get_char(p_id,"h");
	if(!mapp(hus)) return "$N��$T����$R��û�з��ӣ�����ʲô������졣\n";
	if(hus["st"]=="building") return "$N��$T����$R�ķ����������ء�\n";
	if(hus["st"]=="updating") return "$N��$T����$R�ķ������ڸ����ء�\n";
	if(hus["st"]=="moving") return "$N��$T����$R�ķ������ڰ��ء�\n";

	p_price=HOUSE_D->get_house(h_id,"price");
	if(!p_price) 
		return "$N��$T����$RҪ�ǵķ�������ôû��˵����\n";

	cur_house=hus["id"];
	p_curprice=HOUSE_D->get_house(cur_house,"price")/2;
	p_price-=p_curprice;
	p_price=bmax(10,p_price); // at least 10 gold

	p_level=HOUSE_D->get_house(h_id,"level");
	my_level=CHAR_D->get_char(p_id,"ju");
	my_level++;
	my_level/=2;

	if(my_level<p_level)
		return "$N��$T����$R�ľ�λ̫�ͣ����ܸ���������߼��ķ��ӡ�\n";
	if(MONEY_D->sub_all_money(me,p_price*10000)==-1) 
		return "$N��$T����$R��Ǯ���񲻹���������ȥ��취����Ǯ�ɡ�\n";

	return 1;

}

mixed can_i_move(string p_id,string w_id) {
	int p_curprice,p_dis;
	string cur_house,w_cur;
	mixed hus;
	object me=find_body(p_id);
	hus=CHAR_D->get_char(p_id,"h");

	if(!mapp(hus)) return "$N��$T����$R��û�з��ӣ��Ҹ����ʲô��ѽ��\n";
	if(hus["st"]=="building") return "$N��$T����$R�ķ����������ء�\n";
	if(hus["st"]=="updating") return "$N��$T����$R�ķ������ڸ����ء�\n";
	if(hus["st"]=="moving") return "$N��$T����$R�ķ������ڰ��ء�\n";

	w_cur=hus["a"];
	if(w_id==w_cur) return "$N��$T����$R�ķ���Ŀǰ����"+AREA_D->get_area(w_cur,"name")+"\n";
	if(!AREA_D->area_exist(w_id)) return "$N��$T����û��˵��"+w_id+"���������������ѽ��\n";

	p_dis=AREA_D->get_distance(w_cur,w_id);

	cur_house=hus["id"];
	p_curprice=HOUSE_D->get_house(cur_house,"price")*500;
	p_curprice*=p_dis;

	if(MONEY_D->sub_all_money(me,p_curprice)==-1) 
		return "$N��$T����$R��Ǯ���񲻹���������ȥ��취����Ǯ�ɡ�\n";
	return 1;
}

void answer_type(object me, object who,string ans) {
	mixed ret;
	string p_id;

	mapping hus=([]);
	object hs;
		
	p_id=who->query_primary_id();
	me->clear_answer();

	ret=can_i_buy(p_id,ans);
	if(stringp(ret)) {
		me->targetted_action(ret,who);
		return;
	}

	hus["id"]=ans;
	hus["st"]="building";
	hus["t"]=time();
	hus["a"]=CHAR_D->get_char(p_id,"area");

	hus["builder"]=this_object()->query_primary_id();

	hus["t_need"]=(HOUSE_D->get_house(ans,"level")*2+2)*16*60;

	CHAR_D->set_char(p_id,"h",hus);

	hs=SGHOME(p_id);
	if(objectp(hs)) hs->init_rooms();
	me->targetted_action("$N��$T����$R�Ȳ�Ҫ�ż������Ѿ������ˣ���"+
		chinese_number(HOUSE_D->get_house(ans,"level")*2+2)+"����������Ϣ�ɡ�\n",who);
	CHANNEL_D->deliver_tell("gossip",this_object()->short(),
		"����ǣ������������ӵ�"+
		"Ϊ"+CHAR_D->get_char(p_id,"name")+
		"��"+AREA_D->get_area(hus["a"],"name")+"��"+
		HOUSE_D->get_house(ans,"name")+"�Ļ��ˡ�"); 
}


void answer_move_where(object me, object who,string ans) {
	mixed ret;
	string p_id;
	int p_dis;
	mapping hus=([]);
	p_id=who->query_primary_id();
	me->clear_answer();

	ret=can_i_move(p_id,ans);

	if(stringp(ret)) {
		me->targetted_action(ret,who);
		return;
	}


	hus=CHAR_D->get_char(p_id,"h");
	hus["st"]="moving";
	hus["t"]=time();
	p_dis=AREA_D->get_distance(hus["a"],ans);
	hus["a"]=ans;
	hus["builder"]=this_object()->query_primary_id();

	hus["t_need"]=(HOUSE_D->get_house(hus["id"],"level")*p_dis/2+1)*16*60;

	CHAR_D->set_char(p_id,"h",hus);

	me->targetted_action("$N��$T����$R�Ȳ�Ҫ�ż������Ѿ������ˣ���"+
		chinese_number(HOUSE_D->get_house(hus["id"],"level")*p_dis/2+1)+"����������Ϣ�ɡ�\n",who);
	CHANNEL_D->deliver_tell("gossip",this_object()->short(),
		"����ǣ������������ӵ�"+
		"Ϊ"+CHAR_D->get_char(p_id,"name")+
		"��ҵĻ��ˡ�"); 
}

void answer_update_type(object me, object who,string ans) {
	mixed ret;
	string p_id;

	mapping hus=([]);
	p_id=who->query_primary_id();
	me->clear_answer();

	ret=can_i_update(p_id,ans);
	if(stringp(ret)) {
		me->targetted_action(ret,who);
		return;
	}


	hus=CHAR_D->get_char(p_id,"h");
	hus["id"]=ans;
	hus["st"]="updating";
	hus["t"]=time();
	hus["builder"]=this_object()->query_primary_id();
	
	hus["t_need"]=(HOUSE_D->get_house(ans,"level")*2+2)*16*60;

	CHAR_D->set_char(p_id,"h",hus);

	me->targetted_action("$N��$T����$R�Ȳ�Ҫ�ż������Ѿ������ˣ���"+
		chinese_number(HOUSE_D->get_house(ans,"level")*2+2)+"����������Ϣ�ɡ�\n",who);
	CHANNEL_D->deliver_tell("gossip",this_object()->short(),
		"����ǣ������������ӵ�"+
		"Ϊ"+CHAR_D->get_char(p_id,"name")+
		"��"+AREA_D->get_area(hus["a"],"name")+"�ѷ��Ӹ�װ��"+
		HOUSE_D->get_house(ans,"name")+"�Ļ��ˡ�"); 
}


mixed my_house_ready(string p_id) {
	mapping my_house;
	string h_id;
	int t_need;
	my_house=CHAR_D->get_char(p_id,"h");
	if((!mapp(my_house))||((my_house["st"]!="building")&&(my_house["st"]!="updating")
		&&(my_house["st"]!="moving"))||
		(my_house["builder"]!=this_object()->query_primary_id()))
		return "$N��$T����$R����˰ɣ�����û���յ��������Ļ�ѽ��\n";
	h_id=my_house["id"];
	t_need=(my_house["t_need"]);
	t_need=t_need-(time()-my_house["t"]);
	if(t_need>0) 
		return "$N��$T����$R̫�Լ��ˣ���Ҫ�ٵ�"+chinese_number(t_need/16/60+1)+
			"�죬��Ļ���ܸ㶨��\n";
	return 1;
	
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
		o->set_id(hus["id"]);
	}
	else if(hus["st"]=="building"){
		okey=new(HOMEKEY);
		okey->set_owner(p_id);
		this_object()->targetted_action
			("$N��$TЦ������˵��$R�ķ����Ѿ�����ˣ�����Կ�ף���ȥ�����ɡ�\n"+
			 "˵��ָ�$t$O\n",this_body(),okey);
		okey->move(this_body());
	}
	else {
	}

	hus["id"]=my_house["id"];
	hus["st"]="new";
	hus["t"]=time();
	hus["a"]=my_house["a"];
	map_delete(hus,"t_need");
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
                case "buy" :
		        this_object()->targetted_action(
				"$N��$TЦ����Ҫ�Ƿ���ѽ����ϲ����ϲ����֪$Rѡ����ʲô��ʽ��\n",who);
			this_object()->set_answer(p_id, (:answer_type:) );
			tell_user(p_id,"��%^RED%^answer <����ID> to lu%^RESET%^���ش�\n");
                        return;
                case "update" :
		        this_object()->targetted_action(
				"$N��$TЦ����Ҫ���췿��ѽ����ϲ����ϲ����֪$Rѡ����ʲô��ʽ��\n",who);
			this_object()->set_answer(p_id, (:answer_update_type:) );
			tell_user(p_id,"��%^RED%^answer <����ID> to lu%^RESET%^���ش�\n");
                        return;

                case "move" :
		        this_object()->targetted_action(
				"$N��$TЦ����$RҪ���ѽ����ϲ����ϲ����֪$RҪ�ᵽ�δ���\n",who);
			this_object()->set_answer(p_id, (:answer_move_where:) );
			tell_user(p_id,"��%^RED%^answer <����ID> to lu%^RESET%^���ش�\n");
                        return;
                case "get" :
			ret=my_house_ready( p_id);
			if(stringp(ret)) {
			        this_object()->targetted_action(ret,who);
				return;
			}
			get_my_house(p_id);
			return ;
        }
}
