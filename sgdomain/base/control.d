// control.c for base system
#include <security.h>
#include <base.h>
#include <ppl.h>
#define SGBASEPRODUCTLEVEL 150
#define SAVE_PATHA "/data/base/"
#define NPC_SERVERA "/sgdomain/base/npc_server/"

inherit "/sgdomain/home/control";

mixed valid_room_exist_check() ;

protected int p_level;
protected string f_id; 

protected string p_leader;
int have_enough_src(string r_id,int real);
int set_level(int l) {
	if(l>4) l=4;
	if(l<1) l=1;
	p_level=l;
	save_data();
	return p_level;
}
int get_level() {
	return set_level(p_level);
}

mixed set_leader(string p) {
	string nam;
	if(!CHAR_D->char_exist(p))
		return p+"���ǽ�ɫ��";
	nam=CHAR_D->get_char(p,"name");
	if(CHAR_D->get_char(p,"type")!=TYPE_NPC)
		return nam+"����������ʷʵ���";
	if(CHAR_D->get_char(p,"area")!=p_area)
		return nam+"û��"+AREA_D->get_area(p_area,"name")+"���ӡ�";
	if(CHAR_D->get_char(p,"ranklocal")==0)
		return nam+"���ǵط���Ա��";
	if(AREA_D->get_area(p_area,"leader")==p)
		return "�ط����첻����ֱ���쵼�������ء�";
	p_leader=p;
	CHAR_D->set_char(p,"baseleader",f_id);
	this_object()->update_room("enter");

	return 1;
}
string get_defleader() {
	string *ids;
	string lead=AREA_D->get_area(p_area,"leader");
	string other_fid;
	ids=CHAR_D->check_char_area("type",TYPE_NPC,p_area);
	if(!sizeof(ids)) return "";
	foreach(string id in ids) {
		if(id==lead) continue;
		if(!CHAR_D->get_char(id,"ranklocal")) continue;
		other_fid=CHAR_D->get_char(id,"baseleader");
		if(stringp(other_fid)) {
			object oo=SGBASE(p_area,other_fid);
			if(objectp(oo)&&(oo->get_raw_leader()==id))
				continue;
		}
		set_leader(id);
		return id;
	}
	return "";

}

int valid_leader(string p) {
	if(!sizeof(p_leader)) return 0;
	if(!CHAR_D->char_exist(p_leader)) return 0;
	if(CHAR_D->get_char(p,"type")!=TYPE_NPC) return 0;
	if(CHAR_D->get_char(p,"area")!=p_area) return 0;
	if(CHAR_D->get_char(p,"ranklocal")==0) return 0;
	if(AREA_D->get_area(p_area,"leader")==p) return 0;
	if(CHAR_D->get_char(p,"baseleader")!=f_id) return 0;
	return 1;
}
string get_raw_leader() {
	if(valid_leader(p_leader)) return p_leader;
	return "";
}
string get_leader() {
	if(valid_leader(p_leader)) return p_leader;
	return get_defleader();
}
mixed get_base(string what){
	mixed ret;
	switch (what) {
	case "pplnum":
		ret=0;
		foreach(string r, mixed bs in rooms) 
			ret+=bs["pplnum"];
		return ret;
	case "name":
		return p_area+"_"+f_id;
	}
}
//================================= npc part ================================
mixed find_npc(string id) {
	return find_object(NPC_SERVERA+p_area+"/"+f_id+"/"+id);
}
mixed load_npc(string id) {
	return load_object(NPC_SERVERA+p_area+"/"+f_id+"/"+id);
}

//================================ room part ================================

mixed load_room(string r_id) {
        return load_object("/sgdomain/base/base_server/"+p_area+"/"+f_id+"/"+r_id);

}

mixed update_room(string r_id) {
	object v,*os,o;
	o=load_room(r_id);
	os=all_inventory(o);
	v=load_object(VOID_ROOM);
	if(sizeof(os)) {
		foreach(object oo in os) {
			if(!oo->base_npc())
				oo->move(v);
		}
	}
	destruct(o);
	o=load_room(r_id);
	if(sizeof(os)) {
		foreach(object oo in os) {
			if(objectp(oo))
				oo->move(o);
		}
	}
	return o;
}

void init_rooms() {
	rooms=([]);
	rooms["enter"]=([]);

	rooms["enter"]["e"]= ([
		"out" : AREA_D->get_area(p_area,"path")+
			AREA_D->get_area(p_area,"go"), 
		]);

	rooms["enter"]["t"] = "enter" ;

	npcs=([]);
	p_level=1;
	save_data();
}

int get_base_pplnum() {
	string *ks=get_room("list","");
	int ret=0;
	if(!sizeof(ks)) return ret;
	foreach (string k in ks) {
		ret+=get_room(k,"pplnum");
	}
	return ret;
}
mixed can_have_more_ppl(string r_id) {
	int lv=get_level();
	int curnum=get_room(r_id,"pplnum");
	int maxnum=lv*BASEPPLNUM;
	int areapopulation,totalpplnum,maxtotppl;

	if(curnum>=maxnum) 
		return BASE_D->get_base(f_id,"name")+
			"�ȼ��������޷�������"+BASE_D->get_base(f_id,"workername")+"�������ˡ�";
	areapopulation=AREA_D->get_area(p_area,"population");
	totalpplnum=get_base_pplnum();
	maxtotppl=MAXPPLNUMRATE*areapopulation;
	if(totalpplnum>=maxtotppl) {
		return "�����˿ڲ��㣬�޷�������"+BASE_D->get_base(f_id,"workername")+"�������ˡ�";
	}
	p_id=get_leader();
	if(!CHAR_D->char_exist(p_id)) 
		return "û���ܼ࣬�޷�������"+BASE_D->get_base(f_id,"workername")+"�������ˡ�";
	if(!mapp(get_room(r_id,"head"))) 
		return "û��"+BASE_D->get_base(f_id,"headname")+"���޷�������"+
			BASE_D->get_base(f_id,"workername")+"�������ˡ�";
	return 1;
}
mixed add_ppl(string r_id,int num) {
	mixed ret;
	int curnum;
	ret=can_have_more_ppl(r_id);
	if(stringp(ret))
		return ret;
	curnum=get_room(r_id,"pplnum");
	curnum+=num; // this number may more than max value, but
				// that is ok
	set_room(r_id,"pplnum",curnum);
	return curnum;
}

mixed can_have_more_room() {
	int lv=get_level();
	int goldneed;
	int rms=get_room("size","")-1;
	string p_id;
	if((lv*2)<=rms) 
		return BASE_D->get_base(f_id,"name")+
			"�ȼ��������޷��������µ�"+BASE_D->get_base(f_id,"roomname")+"�ˡ�";
	goldneed=BASE_D->get_base(f_id,"gold")/2;
	if(AREA_D->get_area(p_area,"gold")<goldneed)
		return "�����������ѣ��޷������µ�"+BASE_D->get_base(f_id,"roomname")+"�ˡ�";
	p_id=get_leader();
	if(!CHAR_D->char_exist(p_id)) 
		return "û���ܼ࣬�޷������µ�"+BASE_D->get_base(f_id,"roomname")+"�ˡ�";
	return 1;
}

mixed no_head_room() {
	string *rs=get_room("list","");
	foreach(string r in rs) {
		if(r=="enter") continue;
		if(!mapp(get_room(r,"head")))
			return r;
	}
	return 0;
}
mixed init_head(string r_id) {
	mixed head=get_room(r_id,"head");
	int si,pi,wi;
	if(!mapp(head)) return 0;
	switch (head["typ"]) {
	case YOUNGWOMAN:
		si=4; pi=7; wi=7;
		break;
	case YOUNGMAN:
		si=6; pi=3; wi=8;
		break;
	case MIDWOMAN:
		si=7; pi=10; wi=5;
		break;
	case MIDMAN:
		si=10; pi=5; wi=7;
		break;
	case OLDWOMAN:
		si=5; pi=8; wi=4;
		break;
	case OLDMAN:
		si=7; pi=6; wi=6;
		break;
	}
	head["ps"]=si*5+random(si)*5+random(si/2)*5;
	head["pp"]=pi*5+random(pi)*5+random(pi/2)*5;
	head["pw"]=wi*5+random(wi)*5+random(wi/2)*5;
	rooms[r_id]["head"]=head;
	save_data();
}
mixed add_head(object tar) {
	mapping info;
	string r;
	r=no_head_room();
	if(!stringp(r)) return "all room has head.\n";
	info=tar->get_info();
	if(!mapp(info)) return "no information of this head\n";
	info["time"]=time();

	set_room(r,"head",info);
	init_head(r);
	update_room(r);
	return 1;	
}

void remove_room(string r)
{
     map_delete(rooms,r);
     save_data();
     update_room("enter");
}

mixed add_new_room() {
	string *valid_dir=({"east","west","north","south","southeast","southwest","northeast","northwest"});

	string *curdir=keys(get_room("enter","e"));

	string ext,opext,r_id;
	string dis;
	int gold;
	valid_dir-=curdir;

	if(!sizeof(valid_dir)) {
		SGSYS("Can't add new room, no more valid exits\n");
		return;
	}
	ext=valid_dir[random(sizeof(valid_dir))];
	opext=DIRECTION_D->oppdir(ext);

	r_id=ext;
	rooms[r_id]=([]);
	rooms[r_id]["t"]="room";
	rooms[r_id]["e"]=([]);
	
	rooms[r_id]["e"][opext]="enter";
	rooms[r_id]["pro"]=BASE_D->get_base(f_id,"defproduct");
	rooms["enter"]["e"][ext]=r_id;
	dis=AREA_D->get_area(p_area,"name")+"�ֽ������µ�"+BASE_D->get_base(f_id,"roomname");
	gold=AREA_D->get_area(p_area,"gold");
	gold-=BASE_D->get_base(f_id,"gold")/2;
	AREA_D->set_area(p_area,"gold",gold);
	CHANNEL_D->deliver_tell("rumor","system",dis);

	save_data();
	update_room("enter");
	return r_id;
}
void set_power(string r_id,int v) {
	if(!mapp(rooms[r_id])) return;
	rooms[r_id]["power"]=v;
	save_data();
	return ;
}
void check_status(string r_id) {
	string leader;
	if(!mapp(rooms[r_id])) return ;
	leader=get_leader();
	if(leader=="") {
		set_room(r_id,"status",S_NOLEADER);
		set_power(r_id,0);
		return ;
	}
	if(!mapp(rooms[r_id]["head"])) {
		set_room(r_id,"status",S_NOHEAD);
		set_power(r_id,0);
		return ;
	}
	if(!rooms[r_id]["pplnum"]) {
		set_room(r_id,"status",S_NOPPL);
		set_power(r_id,0);
		return ;
	}
	set_room(r_id,"status",S_NORMAL);
}
void calculate_power(string r_id) {
	int pplnum;
	int safe,ind,agr,bus;
	int pow;
	int si,sa,sb,ss,sp,sw,ps,pp,pw;
	int lzg,lbf; // �ι������ͱ�������
	int spr;
	string leader;
	mixed bs,head;
	if(!mapp(rooms[r_id])) return ;
	check_status(r_id);
	if((rooms[r_id]["status"]!=S_NORMAL)&&(rooms[r_id]["status"]!=S_NOSOURCESTUFF)) return;
	
	pplnum=rooms[r_id]["pplnum"];
	pow=pplnum;
	
	pow*=SGBASEPRODUCTLEVEL;
	pow/=100;
	safe=AREA_D->get_area(p_area,"safe");
	pow*=(100+safe); pow/=300;

	ind=AREA_D->get_area(p_area,"industry");
	agr=AREA_D->get_area(p_area,"agriculture");
	bus=AREA_D->get_area(p_area,"business");

	bs=BASE_D->get_base(f_id,"");
	si=bs["si"]; sa=bs["sa"]; sb=bs["sb"];
	ss=bs["ss"]; sp=bs["sp"]; sw=bs["sw"];
	pow*=(si*ind+sa*agr+sb*bus+1000); pow/=3000;
	
	leader=get_leader();
	lzg=CHAR_D->get_skill(leader,"sk_meili");
	lbf=CHAR_D->get_skill(leader,"sk_zhimou");
	pow*=(lzg+lbf); pow/=200;

	head=rooms[r_id]["head"];
	ps=head["ps"]; pp=head["pp"]; pw=head["pw"];
	if(ps==0) { 
		init_head(r_id);
		head=rooms[r_id]["head"];
		ps=head["ps"]; pp=head["pp"]; pw=head["pw"];
	}

	pow*=(ss*ps+sp*pp+sw*pw); pow/=1000;

	spr=rooms[r_id]["spr"];
	if(spr>100) spr=100;
	if(spr<0) spr=0;
	rooms[r_id]["spr"]=spr;
	pow*=spr; pow/=100;
	set_power(r_id,pow);
}
int get_power(string r_id) {
	int power;
	if(!mapp(rooms[r_id])) return 0;
	calculate_power(r_id);
	return rooms[r_id]["power"];
}
string get_room_statusstr(string r_id) {
	int st=get_room(r_id,"status");
	switch (st) {
	case S_NOLEADER:
		return "û���ܼࡣ";
	case S_NOHEAD:
		return "û��"+BASE_D->get_base(f_id,"headname");
	case S_NOPPL:
		return "û��"+BASE_D->get_base(f_id,"workername");
	case S_NOSOURCESTUFF:
		return "ԭ�ϲ���";
	case S_NORMAL:
		return "��������";
	default :
		return "��ֵ�δ֪״̬"+st;
	}
}

string get_room_problemstr(string r_id) {
	int st=get_room(r_id,"problem");
	switch (st) {

	case P_ASKWINE:
		return BASE_D->get_base(f_id,"workername")+"��Ҫ�Ⱦơ�";
	case P_ASKMEAT:
		return BASE_D->get_base(f_id,"workername")+"��Ҫ���⡣";
	case P_ASKRAISE:
		return BASE_D->get_base(f_id,"headname")+"Ҫ��Ӷ��";
	case P_NORMAL:
		return "һ������";
	default :
		return "��ֵ�δ֪����"+st;
	}
}
mixed get_room(string r_id,string para) {
	if(!para) para="";
	switch(para) {
	case "power" :
		return get_power(r_id);
	case "problemstr":
		return get_room_problemstr(r_id);
	case "statusstr":
		return get_room_statusstr(r_id);
	default :
		return ::get_room(r_id,para);
//		return "/stdomain/home/control"::get_room(r_id,para);
	}
}

string stat_me(string r_id) {
	string ret="";
	string roomname,workername,headname;
	mapping consume,src;
	mapping c=rooms[r_id],head;
	int pow;
	roomname=BASE_D->get_base(f_id,"roomname");
	workername=BASE_D->get_base(f_id,"workername");
	headname=BASE_D->get_base(f_id,"headname");
	if(!mapp(c)) return "û�����"+roomname+"\n";
	ret+="���ͣ�"+roomname+"\n";
	ret+=workername+"������"+c["pplnum"]+" �ɾ���"+c["spr"]+"\n";
	head=c["head"]; 
	if(!mapp(head))
		ret+="Ŀǰû��"+headname+"\n";
	else {
		ret+=headname+"��"+head["sname"]+head["gname"];
		ret+=" ������"+head["ps"]+" ������"+head["pp"]+" �ǻۣ�"+head["pw"]+"\n";
	}
	if(!stringp(c["pro"])) 
		c["pro"]=BASE_D->get_base(f_id,"defproduct");
	pow=get_room(r_id,"power");
	ret+="��������"+pow+" ���������ۣ�"+c["work"]+"\n";
	ret+="��Ʒ��"+BASE_D->get_stuff(c["pro"],"name")+" ÿ"+
		BASE_D->get_stuff(c["pro"],"quantity")+
		BASE_D->get_stuff(c["pro"],"unit")+"��Ҫ��������"+
		BASE_D->get_stuff(c["pro"],"work")+" ";
	consume=BASE_D->get_stuff(c["pro"],"consume");
	if(sizeof(consume)) {
		ret+="��Ҫԭ�ϣ�";
		foreach(string con, int vol in consume) {
			ret+=""+vol+BASE_D->get_stuff(con,"unit")+
				BASE_D->get_stuff(con,"name")+" ";
		}
	}
	ret+="\n";
	src=c["src"];
	if(sizeof(src)) {
		ret+="Ŀǰ���ԭ�ϣ�";
		foreach(string con, int vol in src) {
			ret+=""+vol+BASE_D->get_stuff(con,"unit")+
				BASE_D->get_stuff(con,"name")+" ";
		}
		ret+="\n";
	}

	if(c["status"]==S_NORMAL) {
		if(!have_enough_src(r_id,0)) {
			set_room(r_id,"status",S_NOSOURCESTUFF);
		}
	}

	ret+="Ŀǰ״����"+get_room_statusstr(r_id)+"\n";
	ret+="Ŀǰ���⣺"+get_room_problemstr(r_id)+"\n";

	ret+="�����²�����"+pow*10*BASE_D->get_stuff(c["pro"],"quantity")/BASE_D->get_stuff(c["pro"],"work")+
		BASE_D->get_stuff(c["pro"],"unit")+
		BASE_D->get_stuff(c["pro"],"name")+"\n";
	ret+="�����������"+pow*10*12*BASE_D->get_stuff(c["pro"],"quantity")/BASE_D->get_stuff(c["pro"],"work")+
		BASE_D->get_stuff(c["pro"],"unit")+
		BASE_D->get_stuff(c["pro"],"name")+"\n";
	return ret;
}
int get_room_product_estimate(string r_id) {
	string stf=get_room(r_id,"pro");
	int pow,qut,work;
	if(!BASE_D->stuff_exist(stf)) return 0;
	pow=get_power(r_id);
	if(!pow) return 0;
	qut=BASE_D->get_stuff(stf,"quantity");
	work=BASE_D->get_stuff(stf,"work");
	return (pow*qut*10)/work;
}
mapping get_base_product_estimate() {
	mapping ret=([]);
	string *rds,stf;
	int val;
	rds=get_room("list","");
	if(!sizeof(rds)) return ([]);
	foreach(string r in rds) {
		if(r=="enter") continue;
		stf=get_room(r,"pro");
		val=get_room_product_estimate(r);
		ret[stf]+=val;
	}
	return ret;
}

//============================== system part ======================================
void get_save_file() {
	p_savefile=SAVE_PATHA+get_base("name");
}
void save_data()
{
	if(!sizeof(p_savefile)) return;
       unguarded(1, (: save_object, p_savefile :));
}
void restore_data() {
    if(!sizeof(p_savefile)) return;
      unguarded(1, (: restore_object, p_savefile, 1 :));
}

void create(string a_id,string fd) {
	array bases;
	if(!clonep(this_object())) return;
	set_privilege(1);

	call_out("check_me",300);
	p_area=a_id;
	f_id=fd;
	
	get_save_file();
	restore_data();	

	p_area=a_id;
	f_id=fd;
	get_save_file();

	bases=AREA_D->get_area(p_area,"base");

	if(!arrayp(bases)) {
		destruct(this_object());
		return;
	}
	if(!sizeof(rooms)) init_rooms();
	scan_npc();
       valid_room_exist_check();
	save_data();
}
int need_clean() {
	string *rs;
	string tmp=get_base("name");
	rs=users()->query_body()->query_room()->get_base();
	if(member_array(tmp,rs)==-1) return 1; // no user in room
	return 0;
}
void clean_me() {
	string *rs;
	object o_r;
	rs=keys(rooms);
	foreach(string r in rs) {
		o_r=find_object(FROOMA(p_area,f_id,r));
		if(objectp(o_r))
			destruct(o_r);
	}
	remove_call_out("check_me");
	destruct(this_object());
}

void check_me() {
	remove_call_out("check_me");
	call_out("check_me",300);
	if(need_clean())
		clean_me();	
}

int is_base_control() {
	return 1;
}
string get_area() {
	return p_area;
}
string get_f_id() {
	return f_id;
}

int set_spr(string r_id,int v) {
	if(v<0) v=0;
	if(v>100) v=100;
	rooms[r_id]["spr"]=v;
	save_data();
	return v;
}
int room_working(string r_id) {
	int power,work;
	int tmp;
	if(r_id=="enter") return 0;
	power=get_room(r_id,"power");

	if(random(5)==0) {// case 1 /5 it is about 18 points / 24 hours
		tmp=rooms[r_id]["spr"]; 
		if(random(tmp)>15)
			tmp--;
		else
			tmp++;
		rooms[r_id]["spr"]=tmp;
	}

	if(have_enough_src(r_id,1)!=1) {
		return 0;
	}
	work=get_room(r_id,"work");
	if(power>0) {
		rooms[r_id]["work"]=work+power;
	}
	return power+work;

}
int base_working() {
	string *rs;
	rs=keys(rooms);
	foreach(string r_id in rs) {
		room_working(r_id);
	}
	save_data();
	return 1;
}
string get_product(string r_id) {
	string pdt=get_room(r_id,"pro");
	if(!BASE_D->stuff_exist(pdt)) 
		return BASE_D->get_base(f_id,"defproduct");
	return pdt;
}
int room_harvest(string r_id) {
	int work,quantity,qwork;
	string pdt;
	int share,val;

	if(r_id=="enter") return 0;
	work=get_room(r_id,"work");
	if(work==0) return;
	pdt=rooms[r_id]["pro"];
	if(!stringp(pdt)) {
		pdt=BASE_D->get_base(f_id,"defproduct");
	}

	quantity=BASE_D->get_stuff(pdt,"quantity");
	qwork=BASE_D->get_stuff(pdt,"work");

	share=work/qwork;
	work-=(share*qwork);
	share*=quantity;
	val=AREA_D->get_area(p_area,pdt);
	val+=share;
	AREA_D->set_area(p_area,pdt,val);

	rooms[r_id]["work"]=work;
	return val;
}


int base_harvest() {
	string *rs;
	rs=keys(rooms);
	foreach(string r_id in rs) {
		room_harvest(r_id);
	}
	save_data();
	return 1;
}

int get_head_gold_consume() {
	int silver=0;
	int gold;
	foreach(string r,mapping b in rooms) {
		if(mapp(b["head"])) 
			silver+=b["head"]["salary"];
	}
	gold=silver/100;
	if((gold*100)<silver) gold++;
	return gold;

}
int get_ppl_gold_consume() {
	int pplnum=get_base("pplnum");
	return pplnum/20;
}

int get_ppl_food_consume() {
	int pplnum=get_base("pplnum");
	if(f_id=="farm") return 0; // ũ����������ʳ
	return pplnum/2;
}

mixed get_base_src_consume(string r_id) {
	mixed ret,con;
	int pow,powconsume,v1;
	string prd;
	prd=get_product(r_id);
	con=BASE_D->get_stuff(prd,"consume");
	if(!mapp(con)) return 0;
	powconsume=BASE_D->get_stuff(prd,"work");
	pow=get_power(r_id);
	ret=([]);
	foreach(string s,int v in con) {
		v1=v*pow/powconsume;
		if((v1*powconsume)<(v*pow)) v1++;
		ret[s]=v1;
	}
	return ret;
}
int have_enough_src(string r_id,int real) { // real will consume
	mixed consume,c;						// other just query
	int pow,powconsume,v1;
	string prd;
	consume=get_base_src_consume(r_id);
	if(!mapp(consume)) return 1; // dont' need resource
	c=rooms[r_id]["src"];

	if(!mapp(c)) return 0; // no resoruce at all
	foreach(string s, int v in consume) {
		if(consume[s]>c[s]) return 0;
		if(real==1)
			c[s]-=consume[s];
	}
	if(real) {
		rooms[r_id]["src"]=c;
		save_data();
	}
	return 1;

}
int get_base_gold_consume() {
	int goldneed;
	int level;
	goldneed=BASE_D->get_base(f_id,"gold");
	level=get_level();
	while(level>1) {
		goldneed*=2;
		level--;
	}
	goldneed*=(sizeof(rooms)+2);
	goldneed/=100;
	return goldneed;
}
int get_gold_consume() {
	return get_base_gold_consume()+
		get_ppl_gold_consume()+
		get_head_gold_consume();
}
void base_consume() {
	string *rs;
	string dis;
	string r;
	int p_gold=AREA_D->get_area(p_area,"gold");
	int p_goldneed=get_base_gold_consume();
	int level,p_food,p_foodneed;
	rs=keys(rooms);
	rs-=({"enter"});
	level=get_level();

	if(p_gold<p_goldneed) {
		AREA_D->set_area(p_area,"gold",0);
		level--;
		if(level==0) {
			array bs;
			bs=AREA_D->get_area(p_area,"base");
			bs-=({f_id});
			AREA_D->set_area(p_area,"base",bs);
			dis=AREA_D->get_area(p_area,"name")+"�ʽ���"+
				AREA_D->get_area(p_area,"name")+"��"+
				BASE_D->get_base(f_id,"name")+"�����ˡ�";
			CHANNEL_D->deliver_tell("rumor","system",dis);
			return;		
		}
		while(sizeof(rs)>level*2) {
			r=rs[random(sizeof(rs))];
			map_delete(rooms,r);
                        rs=keys(rooms);
		}
		foreach (r in rs) {
			rooms[r]["head"]=0;
			rooms[r]["pplnum"]=0;
		}

		dis=AREA_D->get_area(p_area,"name")+"�ʽ���"+
			AREA_D->get_area(p_area,"name")+"��"+
			BASE_D->get_base(f_id,"name")+"�����ˡ�";
		CHANNEL_D->deliver_tell("rumor","system",dis);
		set_level(level);
		save_data();	
		return;		
	}
	p_gold-=p_goldneed;
	p_goldneed=get_head_gold_consume()+get_ppl_gold_consume();
	if(p_gold<p_goldneed) {
		AREA_D->set_area(p_area,"gold",0);
		foreach ( r in rs) {
			rooms[r]["pplnum"]=rooms[r]["pplnum"]/2;
		}
		dis=AREA_D->get_area(p_area,"name")+"�ʽ���"+
			AREA_D->get_area(p_area,"name")+"��"+
			BASE_D->get_base(f_id,"workername")+"�����ˡ�";
		CHANNEL_D->deliver_tell("rumor","system",dis);
		save_data();	
		return;		
	}
	p_gold-=p_goldneed;
	AREA_D->set_area(p_area,"gold",p_gold);

	p_food=AREA_D->get_area(p_area,"food");
	p_foodneed=get_ppl_food_consume();
	if(p_food<p_foodneed) {
		AREA_D->set_area(p_area,"food",0);
		foreach ( r in rs) {
			rooms[r]["pplnum"]=rooms[r]["pplnum"]/2;
		}
		dis=AREA_D->get_area(p_area,"name")+"��ʳ����"+
			AREA_D->get_area(p_area,"name")+"��"+
			BASE_D->get_base(f_id,"workername")+"�����ˡ�";
		CHANNEL_D->deliver_tell("rumor","system",dis);
		save_data();	
		return;		
	}
	AREA_D->set_area(p_area,"food",p_food-p_foodneed);
}


string stat_me_total() {
	string ret;
	string *rds;
	int tppl=0,tpow=0,trms=0,thds=0;
	int tgoldc=0,tfoodc=0;
	ret="��"+BASE_D->get_base(f_id,"name")+"��������£�\n";
	ret+="�ȼ���"+get_level()+" �ܼࣺ"+CHAR_D->get_char(get_leader(),"name")+"\n";
	rds=get_room("list","");
	tgoldc=get_gold_consume();
	tfoodc=get_ppl_food_consume();
	tppl=get_base("pplnum");
	foreach(string r in rds) {
		if(r=="enter") continue;
		trms++;
		if(mapp(rooms[r]["head"])) thds++;
		tpow+=get_power(r);
	}
	ret+=BASE_D->get_base(f_id,"roomname")+"����"+trms+" "+
		BASE_D->get_base(f_id,"headname")+"����"+thds+"\n";
	ret+=BASE_D->get_base(f_id,"workername")+"����"+tppl+
		" ����������"+tpow+"\n";
	ret+="�½������ģ�"+tgoldc+" ���������ģ�"+tfoodc+"\n��";
	return ret;
}

mixed valid_room_exist_check() {
	mapping x=get_room("enter","e");
if(!sizeof(x)) return 2;
	foreach(string ee,string eo in x) {
		if(ee=="out") {
			string tmp1;
			tmp1="/a/"+p_area+"/"+AREA_D->get_area(p_area,"go");
			if(tmp1!=x[ee]) {
				x[ee]=tmp1;
				set_room("enter","e",x);
			}
			continue;
		}
		if(!mapp(get_room(ee,""))) {
			map_delete(x,ee);
			set_room("enter","e",x);
			
		}
	}
	return 1;
}


