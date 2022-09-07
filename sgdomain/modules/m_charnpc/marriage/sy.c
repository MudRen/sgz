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
    "һȺС���ڷ��������ţ����ţ�Ҫ��ϲ�ǣ�$N��˵���꣬�꣬������\n",
    "����С���ﲻ��һ��͵͵����ʲô�������죬�ԳԵ�Ц�š�\n",
    "һ�˸ߺ�������Ц�ˣ����˺��ô�Ц��\n",
    "�ܶ��˼������⣬�뿴��������\n",
    "������һ�߹٣������˺���һͨ��վ��һ�ߡ�\n",
    "һ���ʷ������ܽ�������$N�����ֹ���Щʲô��$N������ͷ���ã��á�\n",
    "���ⱬ������ž�������ͣ���������һ����\n",
    "$N����ֱ�����������������ȥ��\n",
    "$N�������ı��Ͳ�ͣ�ص�ͷ���⡣\n",
    "$N�Լ������Ȼ�Ʋ�ͣ�طԸ���ʲô��\n",

});


private mixed handle_blocks( string dir )
{
        string p_id;
	if(dir!="enter") return 0;
	p_id=this_body()->query_primary_id();
	if(p_id==p_boy) {
		this_object()->targetted_action(
		"$N��$T�������ɹ٣�̫�Լ��ˣ���û������ؾ��������ѽ��\n\n"+
		"���˹�����Ц��\n",this_body());
		return 0;
	}
	if(p_id==p_girl) {
		this_object()->targetted_action(
		"$N��$T���������ӣ�̫�Լ��ˣ���û������ؾ��������ѽ��\n\n"+
		"���˹�����Ц��\n",this_body());
		return 0;
	}
        return ::handle_blocks(dir);    
}

void setup()
{
    set_name("si yi", "˾��");
    set_gender(1);
    set_in_room_desc("\n���ڹ���һ�����ģ�\n
%^H_RED%^               ��        �� 
          ����������������������
               ��        ��
           ��������������������
             ������    ������
             ��  ��    ��  ��
             ������    ������
              ����      ����
           ��������������������
             ������    ������
             ��  ��    ��  ��
             ������    ������%^RESET%^\n"+
"\n�м�վ��һ�����ų��۵Ļ���%^H_RED%^˾��%^RESET%^(si yi)\n");

    add_ask_str("xinren","$N��$TС������˭���ѽ����ô�ų���\n");
    add_question("xinren","xinren" );

    add_ask_str("start","$N��$TС�������ǲ��ǿ��Կ�ʼ�ˡ�\n");
    add_question("start","start" );

    call_out("check",10);
    add_block("enter");

    set_block_action( "$N��$Tһ���ֵ�סȥ·�������������˵Ķ�����$R�������ڡ�\n");
}

string long() {
	return
"һ�����ų��۵Ļ���%^H_RED%^˾��%^RESET%^������ָ���������̡�\n";
}


void finish() {
	this_object()->simple_action("$N�뿪�ˡ�\n");	
	this_object()->remove();
}
void chaois() {
	string msg;
	msg=chaois[random(sizeof(chaois))];
	this_object()->simple_action(msg);
}
void jh_ring() {
	object o_girl,o_boy,*os;
	object o_girlring,o_boyring;

	o_girl=find_body(p_girl);
	if(!o_girl) return;

	o_boy=find_body(p_boy);
	if(!o_boy) return;

	os=all_inventory(o_girl);
	os=filter_array(os,(:$1->ob_state()=="hands":));
	if(!sizeof(os))
		return ;
	o_girlring=os[0];

	os=all_inventory(o_boy);
	os=filter_array(os,(:$1->ob_state()=="hands":));
	if(!sizeof(os))
		return ;
	o_boyring=os[0];

	o_girlring->do_remove();
	o_boyring->do_remove();

	o_girlring->move(o_boy);
	o_boyring->move(o_girl);

	o_boy->targetted_action("$N�������$o����$T��\n",o_girl,o_boyring);
	o_girl->targetted_action("$N�������$o����$T��\n",o_boy,o_girlring);

	o_girlring->do_wear();
	o_boyring->do_wear();
	return; 
}
void big_gift() {
	object *os,o_boy,o_girl;
	object o_l;
	string msg;
	msg="���׵����մ��ã���"+p_boyname+"��"+p_girlname+"�����вμӻ�����˴���ף����\n";
	tell(users(),"%^H_RED%^������"+msg);
	os=all_inventory(this_object()->query_room());
	os=filter_array(os,(:$1->query_link():));
	if(sizeof(os)) {
		foreach(object o in os) {
			o_l=new("/sgdomain/obj/other/shoyu");
			tell(o,"��õ�һ"+o_l->short()+"\n");
			o_l->move(o);
		}
	}

	o_girl=find_body(p_girl);
	if(objectp(o_girl)) {
		o_l=new("/sgdomain/area/emp/dan/yyd");
		tell(o_girl,"��õ�һ"+o_l->short()+"\n");
		o_l->move(o_girl);
		
	}

	o_boy=find_body(p_boy);
	if(objectp(o_boy) ) {
		o_l=new("/sgdomain/area/emp/dan/csd");
		tell(o_boy,"��õ�һ"+o_l->short()+"\n");
		o_l->move(o_boy);
		
	}
	this_object()->simple_action("���˶��õ��˺��׵۵������Ҷ��ܸ��ˡ�\n");
}
string get_message() {
	string ret="";
	string g_area;
	object o_lg;
	ret+="���ɣ�%^H_RED%^"+p_boyname+"%^RESET%^("+p_boy+") ���䣺"
		+chinese_number(CHAR_D->get_char(p_boy,"age"))+"\n";
	ret+="  �Ҿӣ�"+AREA_D->get_area(p_area,"name");
	ret+=" ���ң�"+COUNTRY_D->get_country(AREA_D->get_area(p_area,"nation"),"name")+"\n";
	ret+="  ���ҹ�ְ��"+OFFICER_D->query_rank_name(CHAR_D->get_char(p_boy,"ranknation"));
	ret+=" �ط���ְ��"+OFFICER_D->query_rank_name(CHAR_D->get_char(p_boy,"ranklocal"))+"\n";

	g_area=CHAR_D->get_char(p_girl,"area");
	ret+="���%^H_GREEN%^"+p_girlname+"%^RESET%^("+p_girl+") ���䣺"
		+chinese_number(CHAR_D->get_char(p_girl,"age"))+"\n";
	ret+="  �Ҿӣ�"+AREA_D->get_area(g_area,"name");
	ret+=" ���ң�"+COUNTRY_D->get_country(AREA_D->get_area(g_area,"nation"),"name")+"\n";
	ret+="  ���ҹ�ְ��"+OFFICER_D->query_rank_name(CHAR_D->get_char(p_girl,"ranknation"));
	ret+=" �ط���ְ��"+OFFICER_D->query_rank_name(CHAR_D->get_char(p_girl,"ranklocal"))+"\n";
	
	ret+="ʱ�䣺"+DAY_D->query_chinese_day()+ "��Ԫ"+CHINESE_D->chinese_time(time())+"\n";

	o_lg=CHAR_D->find_char("li guan");
	if(objectp(o_lg)) {
		mapping p_gift;
		string p_id;
		int p_mnt;
		p_gift=o_lg->get_gift();
		ret+="��������    ��        ��    ��\n";
		if(sizeof(p_gift)) {
			foreach(p_id, p_mnt in p_gift) {
				ret+=sprintf("      %-12s      �ƽ�%s��\n",
				FINGER_D->get_chinese_id(p_id)+"("+p_id+")",chinese_number(p_mnt));
			}
		}
	}
	return ret;
}
void the_end() {
	object o;
	object *os;

	string message;
	os=all_inventory(this_object()->query_room());
	os=filter_array(os,(:$1->query_link():));
        os->stop_busy();

	message=get_message();
	NEWS_D->system_post("marriage",p_boyname+"��"+p_girlname+"��ʽ�ɻ�",
  	message,  "%^YELLOW%^�ǹ���%^RESET%^");

	o=CHAR_D->find_char("li guan");
	if(objectp(o)) {
		o->set_step("over");
		o->finish();
	}


	finish();

}
void check() {
	string msg;
	object o_boy,o_girl,me;
	o_boy=find_body(p_boy);
	o_girl=find_body(p_girl);
	p_life++;
	remove_call_out("check");
	call_out("check",6+random(7));
	if(!stringp(p_boy)) return;
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
	me=this_object();
	switch(p_step) {
		case "begin":
			msg="˾�Ǹ���������"+p_boyname+"��"+p_girlname+
			        "�Ļ�����ʽ��ʼ�ˣ����������¹���\n";
			tell(users(),"%^H_RED%^������"+msg);
			me->simple_action(msg);
			DELAY_D->delay_simple_action(me,"�������ϰ�����������Ҷ����е�ע���Ż���Ľ��̡�\n",2);
			p_step="btd";
			return;

		case "btd":
			msg="˾�Ǹ���������һ����ء�\n";
			tell(users(),"%^H_RED%^������"+msg);
			me->simple_action(msg);
			DELAY_D->delay_targetted_action(o_boy,o_girl,"$N��$T����ظ����°ݡ�\n",2);
			p_step="bgt";
			return;

		case "bgt":
			msg="˾�Ǹ������������ݸ��á�\n";
			tell(users(),"%^H_RED%^������"+msg);
			me->simple_action(msg);
			DELAY_D->delay_targetted_action(o_boy,o_girl,"$N��$T�Ը�ĸǰ�������°ݡ�\n",2);
			p_step="db";
			return;

		case "db":
			msg="˾�Ǹ������������޶԰ݡ�\n";
			tell(users(),"%^H_RED%^������"+msg);
			me->simple_action(msg);
			DELAY_D->delay_targetted_action(o_boy,o_girl,"$N��$T����棬�໥�ݵ���\n",2);
			p_step="jh";
			return;

		case "jh":
			msg="˾�Ǹ�����������������ָ��\n";
			tell(users(),"%^H_RED%^������"+msg);
			me->simple_action(msg);
			call_out("jh_ring",2);
			p_step="jf";
			return;


		case "jf":
			msg="˾�Ǹ������������ɽ����ѡ�\n";
			tell(users(),"%^H_RED%^������"+msg);
			me->simple_action(msg);
			DELAY_D->delay_simple_action(o_boy,"$N�����������ϻƽ�һ������\n",2);
			p_step="gift";
			return;

		case "gift":
			msg="˾�Ǹ������������ռα���Ʒ��\n";
			tell(users(),"%^H_RED%^������"+msg);
			me->simple_action(msg);
			{	
				object o_lg;
				int amt=1;
				o_lg=CHAR_D->find_char("li guan");
				if(objectp(o_lg)) {
					amt=o_lg->get_gift_amount();
				}
				CHAR_D->set_char(p_girl,"gold",
					CHAR_D->get_char(p_girl,"gold")+amt);
				DELAY_D->delay_simple_action(o_girl,
					"$N�����������»ƽ�"+chinese_number(amt)+"����\n",2);
			}
			p_step="biggift";
			return;

		case "biggift":
			msg="˾�Ǹ������������ܺ��׵�ף����\n";
			tell(users(),"%^H_RED%^������"+msg);
			me->simple_action(msg);
			call_out("big_gift",2);

			p_step="result";
			return;


		case "result":
			msg="˾�Ǹ���������"+p_boyname+"��"+p_girlname+"��ʽ��Ϊ���ޡ�\n";
			tell(users(),"%^H_RED%^������"+msg);
			me->simple_action(msg);
                        DELAY_D->delay_targetted_action(o_boy,o_girl,"$N��$T������ӵ����һ��
��������������������һ��������������һ������
$T������ৡ���һ�º��ˣ��ߴ��ص�����ͷ�����������$N�Ļ��
$N�ֲ������˵��������գ�����$T�����������������ȥ��
$T���ߵر������۾������ߴ����������ϲ�������ˡ�
���˿�ʼ������ʱ��һ����������������������
\n",2);
			CHAR_D->set_char(p_girl,"mar",p_boy);
			CHAR_D->set_char(p_boy,"mar",p_girl);
			CHAR_D->set_char(p_girl,"pri_mar",0);
			CHAR_D->set_char(p_boy,"pri_mar",0);

			p_step="end";
			return;

		case "end":
			msg="˾�Ǹ���������"+p_boyname+"��"+p_girlname+"���񵽴˽�����\n";
			tell(users(),"%^H_RED%^������"+msg);
			me->simple_action(msg);
			call_out("the_end",2);

			p_step="";
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
	p_step="normal";
	p_life=1;
	remove_call_out("check");
	call_out("check",3);
	return 1;
}
mixed ask_start(object o_boy) {
	string p_id=o_boy->query_primary_id();
	object o_girl;
	int p_money;
	object o_boyring,o_girlring,*os;
	string p_boyring,p_girlring;
	int p_allplayer,p_hereplayer,p_requireplayer;
	mapping wear;

	if(p_step!="normal")
		return "$N��$T�����꣬�Ѿ���ʼ�ˣ�С�ĵ㡣\n";
	if(p_id!=p_boy)
		return "$N��$T�������ɹٻ�û���ż�������ʲô����\n";
	o_girl=find_body(p_girl);
	if(o_girl->query_room()!=this_object()->query_room())
		return "$N��$T���������ӻ�û���������˭���ѽ��\n";
	p_money=o_boy->query_all_con_money();
	if(p_money<1000000) 
		return "$N��$T����$Rһ�������ӵĽ����ѻ�û��׼���ðɣ�û�з��ӿɲ��ܽ�顣\n";

	os=all_inventory(o_girl);
	if(!sizeof(os)) 
		return "$N����üͷ����������ô�������Ӿ������ˡ�\n";
	os=filter_array(os,(:$1->ob_state()=="hands":));
	if(!sizeof(os))
		return "$N����üͷ����������ô��û�д�����ָ��\n";
	o_girlring=os[0];
	p_girlring=o_girlring->query_primary_id();

	os=all_inventory(o_boy);
	os=filter_array(os,(:$1->ob_state()=="hands":));
	if(!sizeof(os))
		return "$N����üͷ�����ɹ���ô��û�д�����ָ��\n";
	o_boyring=os[0];
	p_boyring=o_boyring->query_primary_id();

	os=all_inventory(this_object()->query_room());
	os=filter_array(os,(:$1->query_link():));
	
	p_hereplayer=sizeof(os)-2;
	p_allplayer=sizeof(users())-2;

	p_requireplayer=bmin(10,p_allplayer/3);
	if(p_hereplayer<p_requireplayer) 
		return "$N��$T����Ŀǰ����"+chinese_number(p_allplayer)+
			"λ����������ߣ�����ֻ����"+chinese_number(p_hereplayer)+
			"λ�α����������ﻹ��Ҫ��ȥ��"+chinese_number(p_requireplayer-p_hereplayer)+
			"λ�α�����ڡ�\n";
	o_boy->set_all_con_money(p_money-1000000);


	wear=CHAR_D->get_char(p_boy,"wear");
	if(!mapp(wear))	wear=([]);
	wear["hands"]=p_girlring;
	o_girlring->set_owner(p_boy);
	CHAR_D->set_char(p_boy,"wear",wear);

	wear=CHAR_D->get_char(p_girl,"wear");
	if(!mapp(wear))	wear=([]);
	wear["hands"]=p_boyring;
	o_boyring->set_owner(p_girl);
	CHAR_D->set_char(p_girl,"wear",wear);

	os->start_busy(600,"�������ڽ��У��뱣�ְ�����\n");
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
		case "start":
			ret=ask_start(who);
			if(stringp(ret)) {
				this_object()->targetted_action(ret,who);
				return;
			}
			p_step="begin";
        }
}

int query_clean_up() {
	return 1; // if p_life<200 can't clean up
}
