// gravidity.c

#include <condition.h>
#include <ansi.h>

#define NO_HOME 0
#define NO_BEDROOM 1
#define NO_JSP 2  //接生婆
#define NO_SHINV 3 //侍女
#define NO_INBED 4

int check_home(object me){
	object o_h,o_p_h;
	string id,parter_id;
	mapping home,parter_home;
	id=me->query_primary_id();
	parter_id=CHAR_D->get_char(id,"mar");
	home=CHAR_D->get_char(id,"h");
	parter_home=CHAR_D->get_char(parter_id,"h");
	if(!mapp(home)&&!mapp(parter_home)) return NO_HOME;
	o_h=SGHOME(id);
	o_p_h=SGHOME(parter_id);
	if(!sizeof(o_h->check_room("t","bedroom"))){
		if(!sizeof(o_p_h->check_room("t","bedroom"))) return NO_BEDROOM;
	}
	if(!sizeof(o_h->check_npc("pos","jsp"))){
		if(!sizeof(o_p_h->check_npc("pos","jsp"))) return NO_JSP;
	}
	if(!sizeof(o_h->check_npc("pos","sn"))){
		if(!sizeof(o_p_h->check_npc("pos","sn"))) return NO_SHINV;
	}
	if(!environment(me)->is_bed()) return NO_INBED;
	return 1;
}

int new_offspring_xuhao(object h1,object h2) {
	mapping npcs;
	string id;
	int i,j,k;
	i=1;k=0;
	id="npc "+i;
	npcs=h1->get_npc();
	while (mapp(npcs[id])) {
		j=to_int(npcs[id]["xuhao"]);
		while(j){
			if(j>k) k=j;
		}
		i++;
		id="npc "+i;
	}
	npcs=h2->get_npc();
	while (mapp(npcs[id])) {
		j=to_int(npcs[id]["xuhao"]);
		while(j){
			if(j>k) k=j;
		}
		i++;
		id="npc "+i;
	}
	return k+1;
}

int do_birth(string id,string parter_id,object o1,object o2){
	object o;
	int i;
	mapping ret;
	string msg,npc_id,room;	
	
	if(!sizeof(o1->check_npc("pos","jsp"))) {
		tell_user(id,HIR"你觉得肚中一阵疼痛，你流产了！\n"NOR);
		return 0;
	//	me->start_busy(30+random(30),"你难过极了，什么都不想干！\n");
	//	me->delete_gravidity();
	//	return;
	}

	o=load_object("/sgdomain/home/npc/base_offspring.c");
	ret=([]);
	i=new_offspring_xuhao(o,o2);
	ret["rongmao"]=random(21)+10;
	ret["father"]=parter_id;
	ret["mother"]=id;
	ret["gender"]=random(2)+1;
	ret["birthtime"]=time();
	ret["pos"]="offspring";
	ret["room"]="bedroom";
	ret["growth"]=0;
	ret["id"]=parter_id+" "+ id + (i);
	ret["xuhao"]=(i);
	if(ret["gender"]==1) msg="儿子"; else msg="女儿";
	ret["pre_name"]=CHAR_D->get_char(parter_id,"name")+"和"+CHAR_D->get_char(id,"name")+"的"+msg;
	o->set_info(ret);
	npc_id=o1->add_npc(o);
	o1->set_npc(npc_id,"npc_id",npc_id);
	o1->update_npc(npc_id);
	tell_user(id,HIR"只见接生婆一阵手忙脚乱，你顺利生下一个"+msg+"。\n"NOR);
	return 1;
}

void dele_grav(object me){
	me->delete_gravidity();
}

void childvirth(object me){
	object o_h,o_p_h;
	string id,parter_id,room_owner;
	id=me->query_primary_id();
	parter_id=CHAR_D->get_char(id,"mar");
	o_h=SGHOME(id);
	o_p_h=SGHOME(parter_id);
	switch (check_home(me)){
		case NO_HOME :
		case NO_BEDROOM :
		case NO_JSP :
		case NO_SHINV :
		case NO_INBED :
			tell(me,HIR"你觉得肚中一阵疼痛，你流产了！\n"NOR);
			me->start_busy(30+random(30),"你难过极了，什么都不想干！\n");
			me->delete_gravidity();
			break;
		default : 
			call_out("dele_grav",30,me);
			room_owner=(environment(environment(me)))->get_owner();
			if(room_owner==id){
				if(do_birth(id,parter_id,o_h,o_p_h)) return;
			}else if(room_owner=parter_id){	
				if(do_birth(id,parter_id,o_p_h,o_p_h)) return;
			}
			tell(me,HIR"你觉得肚中一阵疼痛，你流产了！\n"NOR);
			me->start_busy(30+random(30),"你难过极了，什么都不想干！\n");
			me->delete_gravidity();
			return;
	}
}

int update_condition(object me, int duration)
{
	if( !duration ) {
	//	me->delete_gravidity();
		childvirth(me);
	//	NEWS_D->system_post("marriage",p_boyname+"与"+p_girlname+"正式成婚",message,  "%^YELLOW%^乔国老%^RESET%^");

		return 0;
	}
    switch (duration%168)
    {
        case 7 :
        case 6 :
        case 5 :
	        if(random(4)==1)//一天一次胎动
 		        tell(me,HIG"你觉得肚子中好象有个生命在蠕动！\n"NOR);
            break;
        case 4:
        case 3:
	        if(random(4)==1)//一天一次胎动
		        tell(me,HIM"你觉得肚子中一动，好象有个小生命踢了你一下！\n"NOR);
            break;
        case 2:
	        if(random(4)==1)//一天一次胎动
		        tell(me,HIY"你觉得肚子中的小生命又开始剧烈运动起来！\n"NOR);
            break;
        case 1:
	        if(random(4)==1)//一天一次胎动
		        tell(me,HIR"你觉得就快要临盆了！\n"NOR);
            break;

        default : 
            break;
    }
    me->apply_condition("gravidity", duration - 1);
	return CND_CONTINUE;
}
