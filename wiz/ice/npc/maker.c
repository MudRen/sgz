// maker.c the maker could be able to make weapon, cloth or armor
#define FIXVAL 2
#include <move.h>
inherit PMODULES+"m_charnpc";
inherit M_ANSI;
private string m_id;
void my_select(string str);
void input_name(string str);
void answer_somebody(object who);
void prepare_answer();
void my_select(string str);
void no_answer();
void fail_answer();
void succ_answer();

void setup()
{  call_out("my_heart",5);
   add_question("list","list");
   add_question("buy","buy");

}
void extra_init()
{
	string ask_list,ask_order,ask_fix,ask_buy,ask_good;
	m_id=this_object()->query_id()[0];
	CHAR_D->set_char(m_id,"is_maker",1);
	CHAR_D->set_char(m_id,"is_tmp",1);
	if(!CHAR_D->get_char(m_id,"just_sell")) {
		add_question("order","order");
		add_question("fix","fix");
		add_question("good","good");

		ask_order=CHAR_D->get_char(m_id,"ask_order");
		if(!ask_order) 
			ask_order="$N��$T�������֣�$m��$S�붨���������\n";
		add_ask_str("order",ask_order);

		ask_fix=CHAR_D->get_char(m_id,"ask_fix");
		if(!ask_fix) 
			ask_fix="$N��$T�������֣�$m��$S�е�����������ܲ��ܰ�æ��һ�ģ�\n";
		add_ask_str("fix",ask_fix);

		ask_good=CHAR_D->get_char(m_id,"ask_good");
		if(!ask_good) 
			ask_good="$N��$T�������֣�$m��$S�Ķ���׼��������\n";
		add_ask_str("good",ask_good);

	
	}

	ask_list=CHAR_D->get_char(m_id,"ask_list");
	if(!ask_list) 
		ask_list="$N��$T�������֣�$m����$S�������������Щʲô����\n";
	add_ask_str("list",ask_list);

	ask_buy=CHAR_D->get_char(m_id,"ask_buy");
	if(!ask_buy) 
		ask_buy="$N��$T�������֣�$m��$S����㶫����\n";
	add_ask_str("buy",ask_buy);

	add_id("maker");
}
string long(){  
	string p_long;
	p_long=CHAR_D->get_char(m_id,"long");
	if(!p_long) p_long="һ����æ������ת�Ĺ�����\n";
	return p_long;
}
void check_order() {
	mixed orders;
	string *ids,name;
	orders=CHAR_D->get_char(m_id,"orders");
	if(!sizeof(orders)) return;
	ids=keys(orders);
	foreach(string id in ids) {
		if(orders[id]["time"]<time())
		{
			if(find_user(id))
			{
				name=OBJ_D->get_obj(orders[id]["item"],"name");
				responda("hi "+id);
				responda("tell "+id+" �㶨��"+name+"�Ѿ�׼�����ˣ���������ȡ��\n");
			}
		}
	}
}
void do_my_speak(){  
	string act;
	mixed m_act;
	m_act=CHAR_D->get_char(m_id,"m_act");
	if(sizeof(m_act)){
		act=m_act[random(sizeof(m_act))];
	}
	else act="$N�Ǻǵ�Ц�˼�����������ӭ���١�\n";
	if(act[<1]!=10) act+="\n";
	this_object()->simple_action(act);
	return;
}
void check_myroom()
{
	string m_room,m_shd_room;
	m_room=CHAR_D->get_char(m_id,"room");
	m_shd_room=CHAR_D->get_char(m_id,"shd_room");
	if((m_shd_room)&&(m_room!=m_shd_room))
		CHAR_D->put_char(m_id,m_shd_room); // in case it run
}
void my_charaction(){
	check_myroom();
	check_order();
    do_my_speak();
}

void answer_list(object who){
	array goods;
	string tmp,name;
	string bar="                                 ";
	int val,len;
	goods=CHAR_D->get_char(m_id,"goods");
	if(!goods) goods=({});
	CHAR_D->set_char(m_id,"goods",goods);
	if(!sizeof(goods)){
		this_object()->simple_action(
			"$NЦ����������˼��С�̻�û�����ء�\n");
		return; 
	}
	this_object()->targetted_action(
		"$N������֪$R��ҪЩʲô��\n",who);
	write(
"��Ʒ����             �����               ������               �ȼ�\n");
	write(
"--------------------------------------------------------------------\n");

	foreach(string g in goods)	{
		int reusetype=1;
		string type;
		name=OBJ_D->get_obj(g,"name");
		if(!name) // no such things
		{
			goods-=({g});
			CHAR_D->set_char(m_id,"goods",goods);
			continue;
		}
		name=name+"("+g+")";
		len=colour_strlen(name);
		val=OBJ_D->get_obj(g,"value");
        tmp=" ";
        if( len <20)
            tmp=bar[0..(20-len)];
		type=OBJ_D->get_obj(g,"type");
		if((type=="food") || ( type=="drink")) reusetype=0;
        printf("%s%s%-18s   %-18s   %s\n",name,tmp,
           CHINESE_D->chinese_value(val),
		   (reusetype ? CHINESE_D->chinese_value(to_int(val*(1+FIXVAL))):"--------"),
//   		   (reusetype ? CHINESE_D->chinese_value(to_int(val*(FIXVAL))):"--------")
		chinese_number(OBJ_D->get_obj(g,"level"))
);
	}

}
mixed check_order_posible(object maker,object me,string ans) {
	array goods;
    int p_buyersmoney;
    int p_itemvalue;
	int p_level,l_n,l_l,m_l;
	mixed orders;
	string p_id,name;
	goods=CHAR_D->get_char(m_id,"goods");
	if(member_array(ans,goods)==-1)
		return "$N��$Tҡҡͷ������$RҪ�Ķ��������û��������\n";
	if(OBJ_D->get_obj(ans,"type")=="food")
		return "$N��$Tҡҡͷ������$RҪ�Ķ����Ҳ��ܶ�����\n";
	if(OBJ_D->get_obj(ans,"type")=="drink")
		return "$N��$Tҡҡͷ������$RҪ�Ķ����Ҳ��ܶ�����\n";

    maker->clear_answer();
    p_buyersmoney=me->query_all_con_money();
	p_itemvalue=OBJ_D->get_obj(ans,"value")*(1+FIXVAL);
	if(p_itemvalue>p_buyersmoney) 
                return "$N��ֵؿ���$Tһ�ۣ�����$R��Ǯ����û������\n";

	p_id=me->query_id()[0];
	if(!CHAR_D->char_exist(p_id))
		return "$N��$Tҡҡͷ������$R������֮�ˣ���Щ�����ҿ��Ͳ�Ҫ�˰ɡ�\n"
		+"���Ҫ���ɣ������Ҹ��ط���������(help settle)��\n";
	l_n=OFFICER_D->query_level(CHAR_D->get_char(p_id,"ranknation"));
    l_l=OFFICER_D->query_level(CHAR_D->get_char(p_id,"ranklocal"));
    m_l=bmax(l_n,l_l);
    m_l=(m_l+1)/2;	p_level=OBJ_D->get_obj(ans,"level");
    name=OBJ_D->get_obj(ans,"name");
	if(m_l>p_level){
		if(p_level==0)
			return "$N��$Tҡҡͷ������"+name+"��ƽ���������֮����ʺ�$R��\n";
		else
			return "$N��$Tҡҡͷ������"+name+"���¼���Ա����֮����ʺ�$R��\n";
	}
	if(m_l<p_level) {
		if(p_level==5)
			return "$N��$Tҡҡͷ����������Ц��"+name+"����������֮�$R���ܡ���������\n";
		else
			return "$N��$Tҡҡͷ���������У�"+name+"�˸߼���Ա����֮�$R�������ٺ������ɡ�\n";
	}
   	me->set_all_con_money(p_buyersmoney - p_itemvalue);
	orders=CHAR_D->get_char(m_id,"orders");
	if(!orders) orders=([]);
	orders[p_id]=([]);
	orders[p_id]["item"]=ans;
	orders[p_id]["time"]=time()+(60+random(60))*(p_level+1);
	CHAR_D->set_char(m_id,"orders",orders);
	return "$N��$T���ͷ������������Ѿ����£���"+name+"��ɺ󼴿�֪ͨ$R��ȡ��\n";
}
void to_order(object maker,object me,string ans){
	mixed ret;
	ret=check_order_posible(maker,me,ans);
	if(stringp(ret)){
		maker->targetted_action(ret,me);
		return;
	}

}
void to_fix(object maker,object me,string ans){
	write("���컹û��ɣ�ֱ�Ӷ����ɡ�\n");
}

void to_buy(object maker,object me,string ans)
{
	array goods;
    int p_buyersmoney;
    int p_itemvalue;
    object ob;
	goods=CHAR_D->get_char(m_id,"goods");
	if(member_array(ans,goods)==-1){
		maker->targetted_action("$N��$Tҡҡͷ������$RҪ�Ķ��������û������\n",me);
		return;
	}
    maker->clear_answer();

    p_buyersmoney=me->query_all_con_money();
	p_itemvalue=OBJ_D->get_obj(ans,"value");

	if(p_itemvalue>p_buyersmoney) {
		maker->targetted_action("$N��ֵؿ���$Tһ�ۣ�����$R��Ǯ����û������\n",me);
		return;
	}
	ob=OBJ_D->clone_obj(ans);
	if(!objectp(ob)) {
		maker->targetted_action("$N��$T������˼��˵�������ò�����������BUG��������ʦ�ɡ�\n",me);
		return;
	}

    if((ob->move(me)) == MOVE_OK) {		
   		me->simple_action("$N�ڴ�������һ"+
            ob->query_unit()+ob->short()+"��\n"); 
    	me->set_all_con_money(p_buyersmoney - p_itemvalue);
        return;
     }
    else
    {
		maker->targetted_action("$N��$Tҡҡͷ������$R���϶���̫�࣬�ӵ�Щ������ɡ�\n",me);
	        destruct(ob);
		return;
    }
}
void answers(object who,string what) {
	array goods;
	string p_id,name;
	p_id=who->query_id()[0];
	goods=CHAR_D->get_char(m_id,"goods");
	if(!goods) goods=({});
	CHAR_D->set_char(m_id,"goods",goods);
	if(!sizeof(goods)){
		this_object()->simple_action(
			"$NЦ����������˼��С�̻�û�����ء�\n");
		return; 
	}
	if((what=="order")||(what=="fix"))
	{
		goods=filter(goods,(:(OBJ_D->get_obj($1,"type")
			!="food") && (OBJ_D->get_obj($1,"type")
			!="drink") :));
	}
	switch(what)
	{
	case "buy":
		this_object()->set_answer(p_id, (: to_buy :) );
		this_object()->targetted_action(
			"$N��$TЦ����$R����Щʲô��\n",who);
		break;
	case "order":
		if(!sizeof(goods)) {
			this_object()->simple_action(
				"$NЦ����������˼��С��û�����ɶ���\n");
			return; 
		}
		this_object()->set_answer(p_id, (: to_order :) );
		this_object()->targetted_action(
			"$N��$T����$R�붨��Щʲô��\n",who);
		break;
	case "fix":
		if(!sizeof(goods)) {
			this_object()->simple_action(
				"$NЦ����������˼��С��û�����ɸġ�\n");
			return; 
		}
		this_object()->set_answer(p_id, (: to_fix :) );
		this_object()->targetted_action(
			"$N��$T����$R���ʲô��\n",who);
		break;
	}

	foreach(string g in goods)	{
		name=OBJ_D->get_obj(g,"name");
		if(!name) // no such things
		{
			goods-=({g});
			CHAR_D->set_char(m_id,"goods",goods);
			continue;
		}
		name=name+"("+g+")";
		write(name+"\n");
	}
	write("����˾�����\n%^H_WHITE%^answer <��Ʒ����> to "+m_id+"%^RESET%^\n");

}
void answer_good(object who){
	mixed orders;
	string name;
	string p_id;
	string item;
	object ob,maker,me;
	maker=this_object();
	me=who;
	orders=CHAR_D->get_char(m_id,"orders");
	p_id=me->query_id()[0];
	if(!orders) orders=([]);
	if(!orders[p_id]){
      maker->targetted_action(
		"$N��$Tҡҡͷ������$Rû��������������ɣ�\n",me);
			return;
	}
	item=orders[p_id]["item"];
	name=OBJ_D->get_obj(item,"name");
	if(orders[p_id]["time"]>time())
	{	maker->targetted_action(
			"$N��$T����$R��"+name+"��û׼���ã������Ե�Ƭ�̡�\n",me);
			return;
	}
	maker->targetted_action(
			"$N��$T����$R��"+name+"�Ѿ�׼�����ˣ������ȡ����\n",me);

	ob=OBJ_D->clone_obj(item);
	if(!objectp(ob)) {
		maker->targetted_action("$N��$T������˼��˵�������ò�����������BUG��������ʦ�ɡ�\n",me);
		return;
	}
	if(ob->is_horse())
	{
		ob->move(environment(me)); // should no problem
		me->simple_action("$N�쵽ר��Ϊ$nר��׼����"+ob->short()+"\n");
		map_delete(orders,p_id);
		CHAR_D->add_char_wear(p_id,item);
		ob->set_owner(p_id);
	}
	else
	{
		if((ob->move(me)) == MOVE_OK) {	
   			me->simple_action("$N�ڴ��ᵽ��������"+
				ob->query_unit()+ob->short()+"��\n"); 
			CHAR_D->add_char_wear(p_id,item);
	//		CHAR_D->put_on_cloth(p_id);
			map_delete(orders,p_id);
			ob->set_owner(p_id);
			return;
		 }
		else
		{
			maker->targetted_action("$N��$Tҡҡͷ������$R���϶���̫�࣬�ӵ�Щ����ȡ���ɡ�\n",me);
				destruct(ob);
			return;
		}
	}

}

void special_answer(object who, string matt)
{
  switch(matt)
  {
      case "list" :
         answer_list(who);
		return;
      case "buy" :
         answers(who,"buy");
		return;
      case "order" :
         answers(who,"order");
		return;
      case "fix" :
         answers(who,"fix");
		return;
      case "good" :
         answer_good(who);
       return;
  }
}

int is_maker() {
	return 1;
}
