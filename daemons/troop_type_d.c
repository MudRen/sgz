// troop_type_d.c by fire on August 3, 1999
#include <mudlib.h>
#define SAVE_FILE "/data/daemons/troop_type_d"
inherit M_ACCESS;
private mapping tps=([]);
static string *lst;

void clear_tps() {
	lst=keys(tps);

}

void save_data()
{
	unguarded(1, (: save_object, SAVE_FILE, 1 :));
	return;
}
void create()
{
        unguarded(1, (: restore_object, SAVE_FILE, 1 :));
	clear_tps();
        return;
}

mixed get_troop_type(mixed tit,string par) {
	if(tit=="list") return lst;
	if(!tit) return tps;
	if(!mapp(tps[tit])) return 0;
	if(!par) return tps[tit];
	return tps[tit][par];
}
mixed init_off() {
	string path="/wiz/group/troops/";
	string *fs,t_id;
	object o;
//	return "disable now\n";
	fs=get_dir(path+"*.c"); 
	foreach(string f in fs) {
		o=load_object(path+f);
		if(!objectp(o)) continue;
		t_id=f[0..<3];
		tps[t_id]=([]);
		tps[t_id]["name"]=o->query_name();
		tps[t_id]["type"]=o->query_type();
		tps[t_id]["recruit"]=o->query_recruit();
		tps[t_id]["cost"]=o->query_cost();
		tps[t_id]["update"]=o->do_upgrade();
		tps[t_id]["forbiden"]=o->query_forbiden();
		tps[t_id]["city"]=o->get_city();

		tps[t_id]["energy_cost"]=([]);
		tps[t_id]["energy_cost"]["��"]=o->query_energy_cost("��",0,0);
		tps[t_id]["energy_cost"]["��"]=o->query_energy_cost("��",0,0);
		tps[t_id]["energy_cost"]["��"]=o->query_energy_cost("��",0,0);
		tps[t_id]["energy_cost"]["��"]=o->query_energy_cost("��",0,0);
		tps[t_id]["energy_cost"]["��"]=o->query_energy_cost("��",0,0);
		tps[t_id]["energy_cost"]["other"]=o->query_energy_cost("other",0,0);

		tps[t_id]["energy_recover"]=([]);
		tps[t_id]["energy_recover"]["��"]=o->query_energy_recover("��",0,0);
		tps[t_id]["energy_recover"]["��"]=o->query_energy_recover("��",0,0);
		tps[t_id]["energy_recover"]["��"]=o->query_energy_recover("��",0,0);
		tps[t_id]["energy_recover"]["��"]=o->query_energy_recover("��",0,0);
		tps[t_id]["energy_recover"]["��"]=o->query_energy_recover("��",0,0);
		tps[t_id]["energy_recover"]["other"]=o->query_energy_recover("other",0,0);

		tps[t_id]["arrow_defence"]=o->query_arrow_defence();
		tps[t_id]["special_defence"]=o->query_special_defence();
		tps[t_id]["special_attack"]=o->query_special_attack();
		tps[t_id]["attack"]=o->query_attack();
	}
	save_data();

}
string list_troop() {
	int i,sum,ts;
	string ret;
	sum=sizeof(lst);
	ret=
"����ID       ��������   ����ID       ��������   ����ID       ��������   \n";
	ret+= 
"------------------------------------------------------------------------\n";
	ts=1;
	for(i=0;i<sum;++i,ts++) {
		ret+=sprintf("%-13s%-11s",lst[i],
		tps[lst[i]]["name"]);
		if(ts>=3) {
			ret+="\n";ts=0;
		}
	}
	return ret;

}

string get_stuff_list(mixed ms) {
	string *ls;
	string ret="";
	if(!sizeof(ms)) return "";
	if(mapp(ms)) {
		ls=keys(ms);
		foreach(string l in ls) {
			if(l=="gold") 
				ret+="��";
			else
				ret+=(EV_MERCHANT)->query_goods(l,"name")+"��";
			ret+=ms[l]+" ";
		}
	}
	else {
		foreach(string l in ms) {
			if(l=="gold") 
				ret+="�� ";
			else
				ret+=(EV_MERCHANT)->query_goods(l,"name")+" ";
		}
		
	}
	return ret;

}
string get_area_list(string *ss) {
	string ret="";
	foreach(string s in ss) {
		ret+=AREA_D->get_area(s,"name")+" ";
	}
	return ret;
}
string get_area_con(mixed ss) {
	string ret="";
	string *ls;
	ls=keys(ss);
	foreach(string s in ls) {
		if(s=="other")
			ret+="��ǽ��";
		else
			ret+=s+"��";
		ret+=sprintf("(%2d) ",ss[s]);
	}
	return ret;
}
string get_attack_range(mixed ss) {
	int p_min=1000,p_max=0;
	int mm;
	foreach(mapping s in ss) {
		mm=s["damage"];
		p_min=bmin(p_min,mm);
		p_max=bmax(p_max,mm);
	}
	return "ɱ������"+p_min+" -- "+p_max;
}


string show_troop(string what) {
	string ret;
	string *ls;
	ret=sprintf("ID��%s  ���ƣ�%s  ���ͣ�%s\n", 
		what,tps[what]["name"],tps[what]["type"]);

	if(sizeof(tps[what]["recruit"])) {
		ret+="��ļ��"+get_stuff_list(tps[what]["recruit"])+"\n";
	}
	if(sizeof(tps[what]["cost"])) {
		ret+="���ģ�"+get_stuff_list(tps[what]["cost"])+"\n";
	}
	
	if(sizeof(tps[what]["update"])) {
		ret+=sprintf("������\n");
		ls=keys(tps[what]["update"]); 
		foreach(string l in ls){
			ret+=sprintf("   ���֣�%-10sѵ����%3d װ����%s\n",
			get_troop_type(l,"name"),
			tps[what]["update"][l]["train"],
			get_stuff_list(tps[what]["update"][l]["weapon"]));
		}
	}
	ret+=sprintf("��ֹ���Σ�%s\n",implode(tps[what]["forbiden"]," "));

	if(sizeof(tps[what]["city"])) {
		ret+=sprintf("����ļ������%s\n",get_area_list(tps[what]["city"]));
	}
	ret+=sprintf("�н��������ģ�%s\n",get_area_con(tps[what]["energy_cost"]));
	ret+=sprintf("��Ϣ�����ָ���%s\n",get_area_con(tps[what]["energy_recover"]));

	if(tps[what]["arrow_defence"]) 
		ret+=sprintf("������������%d\n",tps[what]["arrow_defence"]);
	if(sizeof(tps[what]["special_defence"])) {
		ret+=sprintf("�����������");
		ls=keys(tps[what]["special_defence"]); 
		foreach(string l in ls){
			ret+=get_troop_type(l,"name");
			ret+="("+tps[what]["special_defence"][l]+") ";
		}
		ret+="\n";
	}
	if(sizeof(tps[what]["special_attack"]))  {
		ret+=sprintf("���⹥������");
		ls=keys(tps[what]["special_attack"]); 
		foreach(string l in ls){
			ret+=get_troop_type(l,"name");
			ret+="("+tps[what]["special_attack"][l]+") ";
		}
		ret+="\n";
	}
	ret+=get_attack_range(tps[what]["attack"]);
	return ret;	
}
string stat_me(string what) {
	string ret;
	
	if((!what)||(what=="")) what="list";
	switch(what) {
		case "list":
			return list_troop();
		case "all" :
			ret="";
			foreach(string l in lst) {
				ret+=show_troop(l);
				ret+="\n";
			}
			return ret;
		default :
			if(!mapp(tps[what])) 
				return "û�����ֲ��ӡ�\n";
			return show_troop(what);
	}
}


mixed remove_troop_type(string r) {
	mixed tmp;
	if(!mapp(tps[r])) return "no such officer troop type.\n";
	tmp=tps[r];
	map_delete(tps,r);
	save_data();
	clear_tps();
	return tmp;
}
mixed add_troop_type(string r) {
	if(mapp(tps[r])) return "such troop type exist already.\n";
	tps[r]=([]);
	save_data();
	clear_tps();
	return tps[r];
	
}
mixed set_troop_type(string r,string what,mixed val) {
	if(!mapp(tps[r])) return "no such troop type add_officer first.\n";
	tps[r][what]=val;
	save_data();
	clear_tps();
	return tps[r];
}
