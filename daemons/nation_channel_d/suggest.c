// suggest.c
// this is used for national suggestion system

inherit __DIR__"nationtax.c";
inherit __DIR__"tran.c";
inherit __DIR__"surrender.c";
inherit __DIR__"friend.c";

static private mapping m_suggest=([]);

private mapping leg_suggest = ([
	"tran" : 	"���䲿�Ӻ����ʡ�
��ʽ��na $tran <��ʼ��> <Ŀ�ĵ�> <���ֻ����ʻ��> <����>
���磺na $tran changan huayin footman 1000\n",

	"nationtax" : 	"������������˰�ʣ�����ߣ�����̫�ػ���ҹ�Ա��
��ʽ��na $nationtax [area_id] <˰��>\n",

	"surrender" : "�ٹ�Ͷ������ʽ��na $surrender <����id>\n",
	"check" : 	"���ĵ�ǰ���������\n",

]);

void deliever_tell(string p_id,string n_id,string msg);
mixed deliever_semote(string p_id,string n_id,string msg);
void deliever_emote(string p_id,string n_id,string msg);

int query_group_value(string *g)
{
	int p_ret=0;
	if( !sizeof(g) ) return 0;
	foreach(string p_id in g) p_ret+=CHAR_D->get_char(p_id,"level");
        return p_ret;
}
void discuss_succ(string n_id) {
	string msg;
	msg="�ã���Ȼ������������飬����ͨ�������ˣ����"+
		m_suggest[n_id]["str"]+"��";
	CHANNEL_D->deliver_tell("rumor","system",
		COUNTRY_D->get_country(n_id,"name")+m_suggest[n_id]["str"]+"��");  
	if( !function_exists("do_"+m_suggest[n_id]["topic"], this_object()) )
		SGSYS(m_suggest[n_id]["topic"]+".c has no excuting function!");
	else call_other(this_object(),"do_"+m_suggest[n_id]["topic"], n_id);

	m_suggest[n_id]=([]);
}
void discuss_fail(string n_id) {
	string msg;
	msg="��������"+m_suggest[n_id]["str"]+"������������۲����������������ͷ��˵�ˡ�";
	deliever_tell(n_id,n_id,msg);
	m_suggest[n_id]=([]);
}
mixed deliever_vote(string p_id, string n_id,string vot) {
	string who;
	string *ag_set=({"agree ","support ","agree","uadme ","great",
		"great ","admire "});
	string *ds_set=({"disagree","disagree ","ack ","no","ack"});
	string *nu_set=({"nosay","pure","wake","fool","nothing"});
	string emt;
	string spk;

	if( !mapp(m_suggest[n_id]) ){ 
		m_suggest[n_id]=([]);
		return "����û��ʲô����ֵ�ñ����\n"; 
	}
	if( !arrayp(m_suggest[n_id]["whole_group"]) )
		return "����û��ʲô����ֵ�ñ����\n"; 
	if( member_array(p_id,m_suggest[n_id]["whole_group"])==-1 ) 
		return "���۵Ķ��������޹ء�\n";
	if( member_array(p_id,m_suggest[n_id]["rest_group"])==-1 )
		return "���Ѿ����̬�ˡ�\n";

	who = m_suggest[n_id]["who"];

	switch( vot ) {
		case "agree" :
			emt = ag_set[random(sizeof(ag_set))];
			spk = "��֧��"+m_suggest[n_id]["str"]+"��";
			m_suggest[n_id]["rest_group"]-=({p_id});
			m_suggest[n_id]["agree_group"]+=({p_id});
			break;
		case "disagree" :
			emt = ds_set[random(sizeof(ds_set))];
			spk = "�ҷ���"+m_suggest[n_id]["str"]+"��";
			m_suggest[n_id]["rest_group"]-=({p_id});
			m_suggest[n_id]["disagree_group"]+=({p_id});
			break;
		case "neutral" :
			emt = nu_set[random(sizeof(nu_set))];
			spk = "�Ҷ�"+m_suggest[n_id]["str"]+"û�������";
			m_suggest[n_id]["rest_group"]-=({p_id});
			m_suggest[n_id]["neutral_group"]+=({p_id});
			break;
		default :
			return "����ȷ�����������\n";		
	}
	if(emt[<1]==' ') emt+=who;
	deliever_tell( p_id, n_id,spk );
	return 1;	
}
void npc_char_consider(string n_id, string p_id) {
	if( !function_exists("npc_char_consider_"+m_suggest[n_id]["topic"],this_object()) ){
		switch(random(3)){
			case 0:	deliever_vote( p_id, n_id,"agree");
				return;
			case 1:	deliever_vote( p_id, n_id,"disagree");
				return;
			case 2:	deliever_vote( p_id, n_id,"neutral");
				return;
		}
	} else 
		call_other(this_object(),"npc_char_consider_"+m_suggest[n_id]["topic"], n_id, p_id);
}
void char_consider(string n_id,string p_id) {
	if( p_id==n_id ) deliever_tell(n_id,n_id,"������һ�롣") ;
	else deliever_tell(n_id,n_id,"��"+CHAR_D->get_char(p_id,"name")+"̸̸�����") ;
	if( !objectp(find_body(p_id)) ) npc_char_consider(n_id,p_id);
}
void discuss_consider(string n_id){
	string *rest;
	rest = m_suggest[n_id]["rest_group"];
	if( !sizeof(rest) ) { SGSYS("should not no ppl left"); }
	foreach(string s in rest) {
		if(!objectp(find_body(s))) {
			char_consider(n_id,s);
			return;
		}
	}
	char_consider(n_id,rest[random(sizeof(rest))]);
}
void discuss_suggest(string n_id) {
	int a_p,d_p,n_p,r_p;
	int min_round, ret;

	if( !mapp(m_suggest[n_id]) ) return ;
	if((!m_suggest[n_id]["status"])||(m_suggest[n_id]["status"]=="over")) {
		m_suggest[n_id]=([]);
		return;
	}

	a_p=query_group_value(m_suggest[n_id]["agree_group"]);
	d_p=query_group_value(m_suggest[n_id]["disagree_group"]);
	n_p=query_group_value(m_suggest[n_id]["neutral_group"]);
	r_p=query_group_value(m_suggest[n_id]["rest_group"]);
	min_round=sizeof(m_suggest[n_id]["whole_group"])+3;

	if( function_exists("check_succ_"+m_suggest[n_id]["topic"]) ){
		ret = call_other(this_object(),"check_succ_"+m_suggest[n_id]["topic"], a_p, d_p, r_p );
		if( ret==1 ) { discuss_succ(n_id); return; }
		if( ret==2 ) { discuss_fail(n_id); return; }
	} else {
		if(a_p>(d_p+r_p))  { discuss_succ(n_id); return; }
		if(d_p>=(a_p+r_p)) { discuss_fail(n_id); return; }
	}
	if(m_suggest[n_id]["round"]>min_round) {
		discuss_fail(n_id); 
		return;
	}

	m_suggest[n_id]["round"]++;
	call_out("discuss_suggest",random(10)+10,n_id);

	discuss_consider(n_id);
}
string check_suggest(string n_id){
	string ret;

	if( !mapp(m_suggest[n_id]) ) return "Ŀǰû���κν��顣\n";
	if( (!m_suggest[n_id]["status"])||(m_suggest[n_id]["status"]=="over") )
		return "Ŀǰû���κν��顣\n";
	ret ="Ŀǰ�������⣺"+m_suggest[n_id]["str"]+"\n";
	ret+="�����ߣ�"+CHAR_D->get_char(m_suggest[n_id]["who"],"name")+"��\n";
	ret+="����������"+chinese_number(sizeof(m_suggest[n_id]["whole_group"]))+"��\n";
	ret+="֧�ֵ㣺"+chinese_number(query_group_value(m_suggest[n_id]["agree_group"]));
	ret+="   ���Ե㣺"+chinese_number(query_group_value(m_suggest[n_id]["disagree_group"]));
	ret+="   �����㣺"+chinese_number(query_group_value(m_suggest[n_id]["neutral_group"]));
	ret+="   δ��̬�㣺"+chinese_number(query_group_value(m_suggest[n_id]["rest_group"]));
	ret+="��\n";
	ret+="����������"+chinese_number(m_suggest[n_id]["round"])+"��\n";
	return ret;
}
mixed get_suggest(string n_id,string what) {
	if(!n_id) return m_suggest;
	if(!what) return m_suggest[n_id];
	return m_suggest[n_id][what];
}
mixed set_suggest (string n_id,string what,mixed val) {
	if(!m_suggest[n_id]) return n_id+" don't have suggest now\n";
	m_suggest[n_id][what]=val;
	return m_suggest[n_id];
}
string no_legal_suggest() {
	string ret;
	ret="��Ľ���ϵͳ�޷���⡣\n";
	ret+="Ŀǰ�������Ľ����У�\n";
	ret+=implode(keys(leg_suggest),"  ");
	return ret+"\n";
}
void add_suggest(string n_id,string topic,mixed para, string who, string *areas )
{
	string *ids,id,*npcs;
	
	ids=CHAR_D->check_char("nation",n_id);
	ids=filter_array(ids,(: CHAR_D->get_char($1,"ranknation") :));
	if(sizeof(areas)) {
		foreach(string s in areas) {
			id=AREA_D->get_area(s,"leader");
			ids-=({id});
			ids+=({id});
		}
	}
	if(sizeof(ids)>12) {
		npcs=filter_array(ids,(: !objectp(find_body($1)) :));
		ids-=npcs;
		while(sizeof(ids)<12) {
			ids+=({npcs[0]});
			npcs-=({npcs[0]});
		}
	}
	if( !m_suggest[n_id] ) m_suggest[n_id]=([]);
	m_suggest[n_id]["status"]="give";	// status of meeting
	m_suggest[n_id]["who"]=who;		// who give the suggestion
	m_suggest[n_id]["topic"]=topic;		// topic
	m_suggest[n_id]["para"]=para;		// parameters
	m_suggest[n_id]["agree_group"]=({who}); // those who agree
	m_suggest[n_id]["disagree_group"]=({}); // those who against
	m_suggest[n_id]["neutral_group"]=({});  // those who have no idea
	m_suggest[n_id]["rest_group"]=ids-({who}); // those who haven't give suggest
	m_suggest[n_id]["whole_group"]=ids;	// all officers and taishous 
	m_suggest[n_id]["round"]=0;		// turns
}
void announce_suggest(string n_id) {
	string p_id;
	p_id=m_suggest[n_id]["who"];
	if(p_id==n_id) // this king
		deliever_tell(p_id, n_id,"��λ���䣬����Ϊ"+m_suggest[n_id]["reason"]+
		"��"+"����"+m_suggest[n_id]["str"]+"��"+
		"��λ����������Ρ�");
	else
		deliever_tell(p_id, n_id,"�������������꣬����Ϊ"+m_suggest[n_id]["reason"]+
		"��"+"����"+m_suggest[n_id]["str"]+"��"+
		"�������λͬ��������Ρ�");
}
mixed deliever_suggest(string p_id,string n_id,string msg) {
	string *paras;
	mixed ret;

	if( !mapp(m_suggest[n_id]) ) m_suggest[n_id]=([]);
	if( msg=="check" ) return check_suggest(n_id);
	if( stringp(m_suggest[n_id]["status"])&&(m_suggest[n_id]["status"]!="over"))
		return "Ŀǰ����������һ��顣\n";

	if(!sizeof(msg)) return msg="---";
	paras=explode(msg," ");

	if( !function_exists("do_check_can_"+paras[0], this_object()) ){
        	if( (AREA_D->get_area(CHAR_D->get_char(p_id,"area"),"leader")!=p_id)&&(!CHAR_D->get_char(p_id,"ranknation")) )
                	return "ֻ�й��ҹ�Ա�͵���̫�ز���������ҽ��顣\n";
	} else if( stringp(ret=call_other(this_object(),"do_check_can_"+paras[0], p_id)) ) 
		return ret;
	if( !function_exists("do_check_"+paras[0]+"_para", this_object()) )
		return no_legal_suggest();
	if( stringp(ret=call_other(this_object(),"do_check_"+paras[0]+"_para", paras, p_id)) )
		return ret;
}
