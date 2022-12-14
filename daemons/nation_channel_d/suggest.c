// suggest.c
// this is used for national suggestion system

inherit __DIR__"nationtax.c";
inherit __DIR__"tran.c";
inherit __DIR__"surrender.c";
inherit __DIR__"friend.c";

static private mapping m_suggest=([]);

private mapping leg_suggest = ([
	"tran" : 	"调配部队和物资。
格式：na $tran <起始地> <目的地> <兵种或物资或金> <数量>
例如：na $tran changan huayin footman 1000\n",

	"nationtax" : 	"调整地区国家税率，提出者：当地太守或国家官员。
格式：na $nationtax [area_id] <税率>\n",

	"surrender" : "举国投降。格式：na $surrender <国家id>\n",
	"check" : 	"查阅当前建议情况。\n",

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
	msg="好，既然大多数人无异议，建议通过。来人，传令："+
		m_suggest[n_id]["str"]+"。";
	CHANNEL_D->deliver_tell("rumor","system",
		COUNTRY_D->get_country(n_id,"name")+m_suggest[n_id]["str"]+"。");  
	if( !function_exists("do_"+m_suggest[n_id]["topic"], this_object()) )
		SGSYS(m_suggest[n_id]["topic"]+".c has no excuting function!");
	else call_other(this_object(),"do_"+m_suggest[n_id]["topic"], n_id);

	m_suggest[n_id]=([]);
}
void discuss_fail(string n_id) {
	string msg;
	msg="看来关于"+m_suggest[n_id]["str"]+"的问题今天讨论不出结果，这个问题回头再说了。";
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
		return "现在没有什么建议值得表决。\n"; 
	}
	if( !arrayp(m_suggest[n_id]["whole_group"]) )
		return "现在没有什么建议值得表决。\n"; 
	if( member_array(p_id,m_suggest[n_id]["whole_group"])==-1 ) 
		return "讨论的东西与你无关。\n";
	if( member_array(p_id,m_suggest[n_id]["rest_group"])==-1 )
		return "你已经表过态了。\n";

	who = m_suggest[n_id]["who"];

	switch( vot ) {
		case "agree" :
			emt = ag_set[random(sizeof(ag_set))];
			spk = "我支持"+m_suggest[n_id]["str"]+"。";
			m_suggest[n_id]["rest_group"]-=({p_id});
			m_suggest[n_id]["agree_group"]+=({p_id});
			break;
		case "disagree" :
			emt = ds_set[random(sizeof(ds_set))];
			spk = "我反对"+m_suggest[n_id]["str"]+"。";
			m_suggest[n_id]["rest_group"]-=({p_id});
			m_suggest[n_id]["disagree_group"]+=({p_id});
			break;
		case "neutral" :
			emt = nu_set[random(sizeof(nu_set))];
			spk = "我对"+m_suggest[n_id]["str"]+"没有意见。";
			m_suggest[n_id]["rest_group"]-=({p_id});
			m_suggest[n_id]["neutral_group"]+=({p_id});
			break;
		default :
			return "请明确表达你的意见。\n";		
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
	if( p_id==n_id ) deliever_tell(n_id,n_id,"让我想一想。") ;
	else deliever_tell(n_id,n_id,"请"+CHAR_D->get_char(p_id,"name")+"谈谈意见。") ;
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

	if( !mapp(m_suggest[n_id]) ) return "目前没有任何建议。\n";
	if( (!m_suggest[n_id]["status"])||(m_suggest[n_id]["status"]=="over") )
		return "目前没有任何建议。\n";
	ret ="目前讨论主题："+m_suggest[n_id]["str"]+"\n";
	ret+="提议者："+CHAR_D->get_char(m_suggest[n_id]["who"],"name")+"。\n";
	ret+="会议人数："+chinese_number(sizeof(m_suggest[n_id]["whole_group"]))+"。\n";
	ret+="支持点："+chinese_number(query_group_value(m_suggest[n_id]["agree_group"]));
	ret+="   反对点："+chinese_number(query_group_value(m_suggest[n_id]["disagree_group"]));
	ret+="   中立点："+chinese_number(query_group_value(m_suggest[n_id]["neutral_group"]));
	ret+="   未表态点："+chinese_number(query_group_value(m_suggest[n_id]["rest_group"]));
	ret+="。\n";
	ret+="讨论轮数："+chinese_number(m_suggest[n_id]["round"])+"。\n";
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
	ret="你的建议系统无法理解。\n";
	ret+="目前可以理解的建议有：\n";
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
		deliever_tell(p_id, n_id,"诸位爱卿，朕以为"+m_suggest[n_id]["reason"]+
		"，"+"当可"+m_suggest[n_id]["str"]+"，"+
		"诸位爱卿意下如何。");
	else
		deliever_tell(p_id, n_id,"吾王万岁万万岁，臣以为"+m_suggest[n_id]["reason"]+
		"，"+"当可"+m_suggest[n_id]["str"]+"，"+
		"陛下与各位同僚意下如何。");
}
mixed deliever_suggest(string p_id,string n_id,string msg) {
	string *paras;
	mixed ret;

	if( !mapp(m_suggest[n_id]) ) m_suggest[n_id]=([]);
	if( msg=="check" ) return check_suggest(n_id);
	if( stringp(m_suggest[n_id]["status"])&&(m_suggest[n_id]["status"]!="over"))
		return "目前正在讨论上一项建议。\n";

	if(!sizeof(msg)) return msg="---";
	paras=explode(msg," ");

	if( !function_exists("do_check_can_"+paras[0], this_object()) ){
        	if( (AREA_D->get_area(CHAR_D->get_char(p_id,"area"),"leader")!=p_id)&&(!CHAR_D->get_char(p_id,"ranknation")) )
                	return "只有国家官员和地区太守才能提出国家建议。\n";
	} else if( stringp(ret=call_other(this_object(),"do_check_can_"+paras[0], p_id)) ) 
		return ret;
	if( !function_exists("do_check_"+paras[0]+"_para", this_object()) )
		return no_legal_suggest();
	if( stringp(ret=call_other(this_object(),"do_check_"+paras[0]+"_para", paras, p_id)) )
		return ret;
}
