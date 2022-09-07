// by fire on aug 1999
inherit M_CHAR;
inherit LIVING;
inherit M_BLOCKEXITS;
#define MARRY_GATE "/sgdomain/area/marriage/marry_gate"
string p_boy,p_girl;
string p_boyname,p_girlname;
string p_area;
string p_step;
private mapping p_gift=([]);
int p_life;
static string *chaois=({
    "һȺС���ڷ��������ţ����ţ�Ҫ��ϲ�ǡ�\n",
    "һ����ʦ�����š��ε����ա��Ĵ��úò����֡�\n",
    "һ�˸ߺ�������Ц�ˣ����˺��ô�Ц��\n",
    "�ܶ��˼����ſڣ��뿴��������\n",
    "������һ������ģ�����ϲ���ô��ֽ���š�\n",
    "һ���ʷ����������������̣�����ž���ؼ������������������˵��춼�ϲ�£��\n",
    "����ƹƹ���ҡ��������ͣ������ȹ��껹���֡�\n",
    "$N��ͷ�������Խ���������������¾���\n",
    "$N�������ı��͵�����ʲô����ͽ����Ұɡ�\n",

});
mixed get_gift() {
	return p_gift;
}
int get_gift_amount() {
	int ret=1;
	int *val;
	int sum,i;
	val=values(p_gift);
	sum=sizeof(val);
	for(i=0;i<sum;++i)
		ret+=val[i];
	return ret;
}

private mixed handle_blocks( string dir )
{
        string p_id;
	if(dir!="litang") return 0;
	p_id=this_body()->query_primary_id();
	if(p_id==p_boy) {
		this_object()->targetted_action(
		"$N��$T�Ϲ��������ɹٻ������ȥ��\n",this_body());
		return 0;
	}
	if(p_id==p_girl) {
		this_object()->targetted_action(
		"$N��$T�Ϲ����������ӣ������롣\n",this_body());
		return 0;
	}
	if(p_id=="jiaofu tou") {
		this_object()->targetted_action(
		"$N�����������ˣ����ÿ������ÿ���\n",this_body());
		return 0;
	}
	if(p_gift[p_id]) {
		this_object()->targetted_action(
		"$N��$T�Ϲ�����$m$R�������롣\n",this_body());
		return 0;
	}
/*	if((!CHAR_D->char_exist(p_id))&&(objectp(find_body(p_id)))) { 
		this_object()->targetted_action(
		"$N��$T�Ϲ�����$m$R�������롣\n",this_body());
		return 0;
	} */
        return ::handle_blocks(dir);    
}

void setup()
{
    set_name("li guan", "���");
    set_gender(1);
    set_in_room_desc("\nһ�����ų��۵�ӭ��%^H_RED%^���%^RESET%^(li guan)\n");

    add_ask_str("xinren","$N��$TС������˭���ѽ����ô�ų���\n");
    add_question("xinren","xinren" );

    add_ask_str("guanli","$N��$Tһ���ֵ���$s���������ֱ���΢�������Ц�ɡ�\n");
    add_question("guanli","guanli" );

    call_out("check",10);
    add_block("litang");

    set_block_action( "$N��$Tһ�Ϲ�������$R�ȵǼ�����������ڹ���ɡ�\n");
}

string long() {
	return
"һ�����ų��۵�ӭ��%^H_RED%^���%^RESET%^������æ������ӿ͡�\n";
}

void set_step(string s) {
	p_step=s;
	return;
}
void finish() {
	
	if((p_step!="over")&&(sizeof(p_gift))) {
		string *lst;
		lst=keys(p_gift); 
		foreach(string k in lst) {
			CHAR_D->set_char(k,"gold",CHAR_D->get_char(k,"gold")+p_gift[k]);
		}
	}
	this_object()->simple_action("$N�뿪�ˡ�\n");	
	this_object()->query_room()->delete_exit("litang");
	this_object()->remove();
}
void chaois() {
	string msg;
	msg=chaois[random(sizeof(chaois))];
	this_object()->simple_action(msg);
}

void check() {
	object o_boy,o_girl;
	o_boy=find_body(p_boy);
	o_girl=find_body(p_girl);
	p_life++;
	remove_call_out("check");
	call_out("check",5+random(5));

	if(!objectp(o_boy)) {
		if((time()-LAST_LOGIN_D->query_last(p_boy)[0])>600) {
			this_object()->simple_action(
			"$N��ֵص������ɹٲ����ˣ����������ǰ첻���ˣ�������ȥ�ɡ�\n");
			finish();
			return;
		}
	}
	if(!objectp(o_girl)) {
		if((time()-LAST_LOGIN_D->query_last(p_girl)[0])>600) {
			this_object()->simple_action(
			"$N��ֵص��������Ӳ����ˣ����������ǰ첻���ˣ�������ȥ�ɡ�\n");
			finish();
			return;
		}
	}
	switch(p_step) {
		case "begin":
			environment(this_object())->add_exit("litang" , MARRY_GATE);
			p_step="normal";
	tell(users(),"%^H_RED%^��������ٸ���������"+p_boyname+"��"+p_girlname+
        "�Ļ����Ҫ��ʼ�ˣ���ҿ�����ѽ��\n");
			return;
		case "normal":
			chaois();
			return;
		default :
			return;
	}


}
int set_boygirl(string boy,string girl) {
	p_boy=boy,p_girl=girl;
	p_boyname=CHAR_D->get_char(p_boy,"name");
	p_girlname=CHAR_D->get_char(p_girl,"name");
	p_area=CHAR_D->get_char(p_boy,"area");
	p_step="begin";
	p_life=1;
	remove_call_out("check");
	call_out("check",3);
	return 1;
}
void announce_gold(int p_amt,string name) {
	tell(users(),"%^H_RED%^��������ٸ���������Ϊ"+p_boyname+"��"+p_girlname+
        "�Ļ���"+name+"�������"+chinese_number(p_amt)+"����\n");
}
void answer_guanli(object me,object who,string amt) {
	int p_amt;
	int p_mymoney;
	int p_sal;
	string p_id;
	object fr;
	me->clear_answer();	
	p_amt=to_int(amt);
	who->targetted_action("$N��$T������"+chinese_number(p_amt)+"���ƽ�������°ɡ�\n",me);

        if(p_amt>200) {
                me->targetted_action("$N����$T��������һ�������⡣���⡣����ô�ҵ���$R����������׼��һ�����ɡ�\n",who);
                return;
        }
	if(p_amt<=0) {
		me->targetted_action("$N��$T��Ц����$R��Ҫ����Ц����\n",who);
		return;
	}
	p_mymoney=who->query_all_con_money();
	if(p_mymoney<=(p_amt*10000)) {
		me->targetted_action("$N��$T��Ц����$R����û����ô��Ǯ�\n",who);
		return;
	}
	p_id=who->query_primary_id();
	p_sal=CHAR_D->get_char(p_id,"salary");
	if(CHAR_D->get_char(p_id,"ranknation")==R_KING) p_sal=200;
	if(p_sal==0) p_sal=1;
	if(p_amt<p_sal) {
		me->targetted_action("$N��$TЦ�������Ǯ��ô����˼�ó��֣���$R�����ĸ߹�\n"+
			"����ҲҪ�ó�"+chinese_number(p_sal)+"����������\n",who);
		who->responda("shame");
		return;
	}
	who->set_all_con_money(p_mymoney-p_amt*10000);
/*	if(random(2))
		CHAR_D->set_char(p_girl,"gold",CHAR_D->get_char(p_girl,"gold")+p_amt);
	else
		CHAR_D->set_char(p_boy,"gold",CHAR_D->get_char(p_boy,"gold")+p_amt);
*/
	call_out("announce_gold",6,p_amt,who->short());
	p_gift[p_id]=p_amt;
	DELAY_D->delay_simple_action(who,"$N����"+chinese_number(p_amt)+"�����ӡ�\n",2);
	DELAY_D->delay_targetted_action(me,who,"$N�����񣬼����˶�$T����$R����ȥ�ɡ�\n",4);
//          fr = new("/wiz/group/firework.c");
          fr = new("/sgdomain/obj/other/firework.c");
	fr->move(who);
	DELAY_D->delay_targetted_action(me,who,"$NЦ�Ŷ�˵��������ֻ�����ȥ������ɡ�\n",6);
}
mixed ask_guanli(object who) {
	string p_id;
	p_id=who->query_primary_id();
	if(p_id==p_boy) 
		return "$N��$TЦ�������ɹٿ�ʲô��Ц�������Ͽ��ȥ��С���������ˡ�\n";
	if(p_id==p_girl) 
		return "$N��$TЦ���������ӿ�ʲô��Ц�������Ͽ��ȥ��\n";
	if(p_gift[p_id])
		return "$N��$TЦ����$m$R�Ѿ��͹������ˣ����ؿ���������ȥ����ɡ�\n";

	this_object()->targetted_action("$N��$T�����Ϲ���л��\n",who);
	tell(who,"\n������Ͷ�������ã�%^RED%^answer <����> to li guan%^RESET%^���ش�\n");
	this_object()->set_answer(p_id, (:answer_guanli:) );
	return 1;
}

void special_answer(object who, string matt)
{
	string p_id;
	mixed ret;
	p_id=who->query_primary_id();
        switch(matt)
        {
                case "xinren" :
			this_object()->targetted_action(
				"$N��$T���صص���$R��֪�������˴���������"+
				p_boyname+"��"+p_girlname+"ѽ��\n",who);
			return; 

                case "guanli" :
			ret=ask_guanli(who);
			if(stringp(ret)) {
				this_object()->targetted_action(ret,who);
				return;
			}

			return;
        }
}

int query_clean_up() {
	return 1; // if p_life<200 can't clean up
}
