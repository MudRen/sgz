#include <security.h>
inherit M_ACCESS;
private string *wj_area=({"qinchuan", "yunnan", "lingling", "xinye", "luling",
"poyang", "jinyang", "qinghe", "kuaiji", "beihai" });

private mapping pl_leader=([]);
private mapping ct_list=([]);

private mapping cl_caption=([]);

private string *chars;

void test_one() {
	
}

#define PLHOME_PATH(x) sprintf("/data/home/%c/%s.o",x[0],x)

mixed clear_players() {
	string *chs, p;
	return "don't call this function untill yu know what you are doing\n";
	chs=CHAR_D->check_char("type",TYPE_PLAYER);
	foreach(string c in chs) {
		CHAR_D->remove_char(c);
		p = PLHOME_PATH(c);
		if(file_size(p)>0) unguarded(1, (: rm, p :));
	}
	return "done\n";
}
string stat_me() {
	string *ks,*as,k,a;
	string ret;
	int i,sum,j,sum2;
	ret="���������������ֲ���\n";
	ret+="======================================================\n";
	ret+="��ҹ��������е���̫�ص��Σ�Ŀǰ�ķ����ǣ�\n";
	i=0;
	foreach(string aaa in wj_area) {
		i++;
		if(i==6) ret+="\n";
		ret+=AREA_D->get_area(aaa,"name")+"��"+
			CHAR_D->get_char(AREA_D->get_area(aaa,"leader"),"name")+"  ";
	}
	ret+="\n=================================================\n";
	ks=keys(ct_list);
	sum=sizeof(ks);
	ret+="NPC�����׶�Ϊ�������ڵء�\n";
	for(i=0;i<sum;++i) {
		k=ks[i];
		ret+="������"+CHAR_D->get_char(k,"name")+"      ��غ͹�Ա��\n";
		as=keys(ct_list[k]);
		sum2=sizeof(as);
		for(j=0;j<sum2;++j) {
			a=as[j];
			ret+="     "+AREA_D->get_area(a,"name")+"��";
			foreach(string c in ct_list[k][a]) {
				ret+=CHAR_D->get_char(c,"name")+" ";
			}
			ret+="\n";
		}
	}
	return ret;	
}

mixed area_init1() {
	string *as;
	int l;
	string *cl;
	as=AREA_D->list_areas();
	foreach(string a in as) {
		l=AREA_D->get_area(a,"level");
		AREA_D->set_area(a,"safe",l*20+100);  //2001.4.13
		AREA_D->set_area(a,"population",l*30000);//2001.8.21 suicide l*20k-->l*30k
		
	}
	cl=COUNTRY_D->list_countries();
	if(sizeof(cl)) {
		foreach(string cc in cl) 
			{string msg;
			 msg = "%^H_GREEN%^������������"+
			       COUNTRY_D->get_country(cc,"name")+
			       "������ͳһ���º󣬾����˶��ݵĺ�ƽ���������߽��ˡ�\n";
			 tell(users(),msg);
			 HIS(msg);
			COUNTRY_D->remove_country(cc);
			}
	
	}
}

mixed area_init2() {
	string *as;
	int l;
	as=AREA_D->list_areas();
	foreach(string a in as) {
		l=AREA_D->get_area(a,"level");
		AREA_D->set_area(a,"gold",l*l*200*9*3); //suicide l*100-->l*l*200*9*3 2001.8.21
		AREA_D->set_area(a,"st",0);
		AREA_D->set_area(a,"food",l*3000);
		
	}
}

mixed area_init3() {
	string *as;
	int l;
	as=AREA_D->list_areas();
	foreach(string a in as) {
		l=AREA_D->get_area(a,"level");
		AREA_D->set_area(a,"troop",0);
		if (l>3)
		    AREA_D->set_area(a,"troop",(["footman":l*l*500]));//2001.4.13
		else
		    AREA_D->set_area(a,"troop",(["footman":l*300]));//2001.4.13
		AREA_D->set_area(a,"morale",180);//2001.4.13
		AREA_D->set_area(a,"train",180);//2001.4.13
		
	}
}

mixed area_init4() {
	string *as;
	int l;
	as=AREA_D->list_areas();
	foreach(string a in as) {
		l=AREA_D->get_area(a,"level");
		AREA_D->set_area(a,"taxlocal",30);
		AREA_D->set_area(a,"taxnation",10);

		AREA_D->set_area(a,"bussiness",50);
		AREA_D->set_area(a,"business",50);
		AREA_D->set_area(a,"industry",50);
		AREA_D->set_area(a,"agriculture",50);
		AREA_D->set_area(a,"importance",0);
		AREA_D->set_area(a,"bl",0);
		AREA_D->set_area(a,"base",0);
		
	}
}
mixed get_player_leader() {
/*	string ld;

	foreach(string a in wj_area) {
		ld=AREA_D->get_area(a,"leader");
		if(!CHAR_D->char_exist(ld)) {
			tell(users(),"%^H_GREEN%^������������"+AREA_D->get_area(a,"name")+
				"û��̫�ء�����������ֹ��\n");
			error("stop");
			pl_leader[a]=ld;
		}
		tell_user("fire",a+":"+ld+" ");
		
	}
*/


	pl_leader=([
	"qinchuan":"group",
	"yunnan":"rulin",
	 "lingling":"ywl",
	 "xinye":"yangjian",
	"luling":"rickal",
	"poyang":"locker",
	"jinyang":"noise",
	"qinghe":"flag",
	"kuaiji":"chw",
	"beihai":"liuxiong", ]);

}

//2001.4.19 modified
void init_char1() {
	string *as;
	int l;
	as=AREA_D->list_areas();
	l =sizeof(as);
	foreach(string c in chars) {
		CHAR_D->set_char(c,"nc",0);
		CHAR_D->set_char(c,"lc",0);
		CHAR_D->set_char(c,"lo",0);
		CHAR_D->set_char(c,"nation",0);
		CHAR_D->set_char(c,"ranklocal",0);
		CHAR_D->set_char(c,"ranknation",0);
//		CHAR_D->set_char(c,"localcontribution",0);
		CHAR_D->set_char(c,"ps",0);
		CHAR_D->set_char(c,"grant",0); //ɾ����ʱ̫����Ϣ
		CHAR_D->set_char(c,"hon",0);
		//2001.4.19
		CHAR_D->set_char(c,"area",as[random(l)]);
                /*if (CHAR_D->get_char(c,"type")==TYPE_NPC)
                   {CHAR_D->set_char(c,"nation",nation);
                    CHAR_D->set_char(c,"ranklocal",1000);
                    printf("%s %s\n",c,nation);
                   }
                */		    
	}

}


void build_npc_country(string k) {
	string *as,ctp;
	as=keys(ct_list[k]);
	foreach(string a in as) {
		if(member_array(k,ct_list[k][a])!=-1) {
			ctp=a; break;
		}
	}
	CHAR_D->set_char(k,"area",ctp);
	COUNTRY_D->add_country(k,ctp);
	foreach(string a in as) {
		AREA_D->set_area(a,"nation",k);
		foreach(string c in CHAR_D->check_char("area",a))
		{
		if(c==k) continue;
		if (CHAR_D->get_char(c,"type")==TYPE_NPC)
		   if (random(20)!=10)
		    {mapping skills=CHAR_D->get_char(c,"skills");
		     CHAR_D->set_char(c,"nation",k);
		     CHAR_D->set_char(c,"ranklocal",R_SG);
               	     CHAR_D->set_char(c,"loyalty",80+random(20));
               	     if ((skills["sk_wuli"]+skills["sk_zhimou"]+skills["sk_meili"])>=200) 
               	        if (skills["sk_wuli"]>80) 
               	           CHAR_D->set_char(c,"ranknation",20+random(3));
               	        else
               	           CHAR_D->set_char(c,"ranknation",130+random(3));

               	         
		    }
		   else
		     printf("%s %s\n",c,a);
		}
		foreach(string c in ct_list[k][a]) {
			mapping skills=CHAR_D->get_char(c,"skills");
			if (!skills) continue;
			if(c==k) continue;
			(EV_POSITION)->give_position(c,R_SG,a);
               	        if ((skills["sk_wuli"]+skills["sk_zhimou"]+skills["sk_meili"])>=200) 
               	        if (skills["sk_wuli"]>80) 
               	           CHAR_D->set_char(c,"ranknation",20+random(3));
               	        else
               	           CHAR_D->set_char(c,"ranknation",130+random(3));


			CHAR_D->set_char(c,"loyalty",90+random(10));
		}
		//remed by suicide in 2001.8.21 for 2 place init population.
		//now only one place init population
		//AREA_D->set_area(a,"population",
		//	AREA_D->get_area(a,"population")*20);
		//AREA_D->set_area(a,"safe",80);
                if (!AREA_D->get_area(a,"leader")) //��û��̫�صĳ���
                AREA_D->auto_head(a);           //�Զ���ѡNPC̫��

	}

}
void build_npc_country_all() {
	string *ks;
	ks=keys(ct_list);
	foreach(string k in ks){
		call_out("build_npc_country",random(20)+10,k);
	}
}
void find_npc(string a) {
	int t=0;
	string c;
	while(t<2) {
		c=chars[random(sizeof(chars))];
		if(CHAR_D->get_char(c,"is_tmp")) continue;
		if(CHAR_D->get_char(c,"type")==TYPE_PLAYER) continue;
		if(CHAR_D->get_char(c,"ranklocal")) continue;
		(EV_POSITION)->give_position(c,R_SG,a);
		t++;
	}
}
void build_char_country(string k,string a) {
	CHAR_D->set_char(k,"area",a);
	COUNTRY_D->add_country(k,a);
	call_out("find_npc",25,a);
}

void build_char_country_all() {
	foreach(string a in wj_area){
		call_out("build_char_country",random(20),pl_leader[a],a);
	}
}

void build_random_country(string a) {
	string *nbs,nb;
	nbs=AREA_D->get_area(a,"neighbor");
	nb=nbs[0];
	AREA_D->set_area(a,"nation",AREA_D->get_area(nb,"nation"));
	//call_out("find_npc",25,a); 
	//2001.4.19
	foreach(string c in CHAR_D->check_char("area",a))
		{
		if (CHAR_D->get_char(c,"type")==TYPE_NPC)
		   if (random(20)!=10)
		    {CHAR_D->set_char(c,"nation",AREA_D->get_area(nb,"nation"));
		     CHAR_D->set_char(c,"ranklocal",R_SG);
            	     CHAR_D->set_char(c,"loyalty",80+random(20));

		    }
		   else
		     printf("%s %s\n",c,a);
		}
        if (!AREA_D->get_area(a,"leader")) //��û��̫�صĳ���
                AREA_D->auto_head(a);           //�Զ���ѡNPC̫��

	
}

void build_random_country_all() {
	foreach(string a in wj_area){
		call_out("build_random_country",random(20)+25,a);
	}
}


void restart() {
//	write("���ڲ�Ҫ��������\n");
//	return;
	tell(users(),"%^H_GREEN%^������������������ʼ����������\n");
	area_init1();
	tell(users(),"%^H_GREEN%^�����������������˿ڣ�������ʼ����ϡ�\n");
	area_init2();
	tell(users(),"%^H_GREEN%^�����������������ƽ����ݳ�ʼ����ϡ�\n");
	area_init3();
	tell(users(),"%^H_GREEN%^�������������������ӣ�ʿ����ѵ����ʼ����ϡ�\n");
	area_init4();
	tell(users(),"%^H_GREEN%^��������������������ũ���̣�˰���ص㣬���أ���������ʼ����ϡ�\n");


//	no player countries this time
//	get_player_leader();
//	tell(users(),"%^H_GREEN%^��������������ҹ���ѡ����ϡ�\n");


	chars=CHAR_D->list_chars();
	chars = filter_array(chars,(: !CHAR_D->get_char($1,"is_tmp"):));//2001.4.19
	init_char1();
	tell(users(),"%^H_GREEN%^��������������ɫ�������ף����ҹ��ף��ҳϣ�ְ�������ϡ�\n");

//	build_char_country_all();  // no player countries

	build_npc_country_all();
	build_random_country_all();
	DAY_D->add_generation();

}
mixed char_test() {
	string *ks,*as,*bs;
	string *chars;
	chars=({});
	ks=keys(ct_list);
	foreach(string a in ks) {
		as=keys(ct_list[a]);
		foreach(string aa in as) {
			bs=ct_list[a][aa];
			foreach(string aaa in bs) {
				if(member_array(aaa,chars)!=-1)
					return "char " + aaa + " used already\n";
				if(!CHAR_D->char_exist(aaa)) return "char "+aaa+" not exist\n";
				chars+=({aaa});
			}
		}
	}
	return sizeof(chars);

}
mixed area_test() {
	string *a_area=({});
	string *ks,*ars;
	foreach(string a in wj_area) {
		if(member_array(a,a_area)!=-1)
			return "area " + a + " used already\n";
		if(!AREA_D->area_exist(a)) return "area "+a+" not exist\n";
		a_area+=({a});
	}
	ks=keys(ct_list);
	foreach(string k in ks) {
		ars=keys(ct_list[k]);
		foreach ( string a in ars) {
			if(member_array( a , a_area)!=-1)
				return "area "+a+" used already\n";
			if(!AREA_D->area_exist(a)) return "area "+a+" not exist\n";
			a_area+=({a});
		}
	}
	ars=AREA_D->list_areas()-a_area;
	if(sizeof(ars))
		return ars[0]+" not assign to any place\n";
	return 1;
	
}

void create() {
string *npcs = MUSEUM_D->get_char("list");
int l = sizeof(npcs);

ct_list["ma teng"]=([ "xiliang" : ({"ma teng", "ma chao", "pang de", "ma tie" }),
		"didao" : ({ "ma dai", "ma xiu"})
	    ]);
ct_list["han sui"]=([ "longxi" : ({"han sui", "zhang heng", "yang qiu" }),
		"tianshui" : ({ "liang xing", "cheng yi" }),
		"jieting" : ({ "cheng yin" }),
		"qishan" : ({ "ma wan"}),
	    ]);
ct_list["dong zhuo"]=([ "changan" : ({"dong zhuo","li su", "li ru", "dong cheng", 
				"zhang liao"}),
		"anding" : ({"zhu juan"}),
		"chencang" : ({ "song xian", }),
		"xianyang" : ({ "lv bu", "chen gong" }),
		"jingyang" : ({ "wei xu" }),
		"huayin" : ({ "guo si" }),
		"tongguan" : ({ "hou cheng"}),
		"wuzhangyuan" :({"gao shun" }),
		"wuguan" : ({ "fan chou"}),
		"hangu" : ({"zhang ji",}),
		"hongnong" : ({ "hua xiong", "wang yun"}),
		"mianchi" : ({"zhong you"}),
//2001.4.19		"luoyang" : ({"lu zhi", "huangfu song", "yang biao"}),
		"huguan" : ({"zhang xiu"}),
		"hulaoguan" : ({"xu rong"}),
	]);
ct_list["he jin"]=([
		"taiyuan" : ({"he jin", "pan feng", "han fu" }),
		"shangdang" : ({ "xin pi" }),
		"yanmenguan" : ({"xin ping"}),
	]);
ct_list["zhang lu"]=([
		"hanzhong" : ({"zhang lu", "yan pu", "yang song"}),
		"xiabian" : ({ "zhang wei"}),
		"yangpingguan" : ({ "zhang yin"}),
	]);
ct_list["liu zhang"]=([
	"chengdu" : ({"liu zhang", "zhang song" , "deng xian", "li hui", "xu jing" }),
	"dingjunshan" : ({ "zhang ren",}),
	"jiange" : ({"lei tong"}),
	"zitong": ({"wu lan", "zou jing"}),
	"fucheng" : ({ "huang quan"}),
	"mianzhuguan" : ({ "fei shi"}),
	"jianning" : ({ "wu yi", "dong he"}),
	"jiangzhou": ({"yang huai",}),
	"yongan" : ({"yan yan", "liu ba"}),
	]);
ct_list["liu biao"]=([
	"xiangyang" : ({"liu biao", "liu cong", "kuai liang", "zhang yun", "huo jun" }),
	"shangyong" : ({ "cao mao", "kuai yue" }),
	"chanxi" : ({ "wen pin", "fu yi" }),
	"changbanpo" : ({ "gan ning", "su fei"}),
	"jiangxia" : ({ "liu qi", "huang zu"}),
	]);
ct_list["liu bei"]=([
	"jiangling" : ({"liu bei", "zhuge liang", "wei yan", "liu feng", "yi ji"}),
	"yiling" : ({"zhang fei", "zhang bao"}),
	"gongan" : ({ "huang zhong", "yin mo"}),
	"huarong" : ({"guan yu", "xu shu", "wang fu"}),
	"wuling" : ({"zhao yun", "ma liang", "jian yong"}),
	]);
ct_list["liu du"]=([
	"changsha" : ({"liu du", "xing daorong", "liu xian"}),
	"guiyang" : ({"pan rui"}),
	"guilin" : ({"gong zhi"}),
	"nanhai" : ({ "bao long"}),
	"chibi" : ({ "zhao fan"}),
	]);
ct_list["yuan shu"]=([
	"wan" : ({"yuan shu", "ji ling", "lei bo"}),
	"runan" : ({"yuan yin",}),
	"bowangpo" : ({"lv fan"}),
	]);
ct_list["sun jian"]=([
	"chaisang" : ({"sun jian", "zhou yu", "zhu zhi", "zhang zhao", "lu ji"}),
	"yuzhang" : ({"sun quan", "huang gai"}),
	"xisaishan" : ({ "lv meng", "han dang"}),
	"danyang" : ({"sun jing", "sun yu"}),
	"lujiang" : ({"sun ce", "li yi"}),
	"ruxukou": ({"lu xun", "ling cao"}),
	]);
ct_list["liu you"]=([
	"shouchun" : ({"liu you", "chen heng", "chen wu"}),
	"hefei": ({"yan xing"}),
	"huaiyin" : ({"ze rong"}),
//2001.4.19	"jianye" : ({"taishi ci"}),
	"wujun" : ({"zhang ying"}),
	]);
ct_list["cao cao"]=([
	"xuchang" : ({"cao cao", "guo jia", "xun you", "xun yu", "dian wei", 
		"cao ren", "xiahou en", "man chong" }),
	"qiao" : ({ "yu jin", "liu ye" }),
	"dingtao" : ({"cao ang", "che zhou"}),
	"puyang" : ({"xu huang", "chen jiao"}),
	"baima" : ({"cao hong", "cao chun"}),
	"ye": ({"xiahou chun", "cheng yu"}),
	"chenliu" : ({"xiahou yuan", "chen qun"}),
	"guandu" : ({"li dian", "le jin"}),
	]);
ct_list["yuan shao"]=([
	"nanpi" : ({"yuan shao", "yan liang", "wen chou", "zhang he", "chunyu qiong", "ju shou"}),
	"daixian" : ({ "guo tu"}),
	"jicheng" : ({"yuan tan", "tian feng"}),
	"yijing" : ({"chen zhen"}),
	"jieqiao" : ({ "gao lan"}),
	"pingyuan" : ({"yuan shang", "feng ji"}),
	"jinan" : ({"yuan xu", "chen lin"}),
	"bohai" : ({"shen pei"}),
	]);
ct_list["tao qian"]=([
	"xuzhou" : ({"tao qian", "chen gui", "chen deng", "sun gan"}),
	"xiaopei" : ({"zang ba"}),
	"xiapi" : ({"cao bao"}),
	"guangling" : ({"mi fang"}),
	"langya" : ({"mi zhu"}),
	]);

ct_list["gongsun zan"]=([
	"beiping" : ({"gongsun zan", "gongsun gong", "yan gang"}),
	"bailangshan" : ({"gongsun yue"}),
	"xiangping" : ({"gongsun du"}),
	]);
	
//2001.4.19
ct_list["cdd npc"]=([
        "luoyang" : ({"liguang npc","cdd npc","noise npc","sabah npc"}),
        ]);
ct_list[npcs[0]+" npc"]=([
        "jianye" : ({}),
        ]);
for (int i=0;i<l;i++)
    ct_list[npcs[0]+" npc"]["jianye"]+=({npcs[i]+" npc"});

}
