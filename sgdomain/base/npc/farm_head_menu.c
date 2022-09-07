//farm_head_menu.c
#define LOG_FILE "/sgdomain/base/base.log"

inherit __DIR__+"farm_menu";
protected string p_workername;
protected string r_id;

int log_me(string msg) {
	unguarded(1, (: write_file, LOG_FILE, msg :));
	return 1;
}

void do_query() {
	poped=0;
   	modal_pop();

    call_out("quit_menu_application",5);

	if(objectp(slave)&&objectp(master)) {
	    master->targetted_action("$N��$T�������������ô������\n",slave);
	    DELAY_D->delay_targetted_action(slave,master,
			"$N��$T����"+get_master()->stat_me(r_id),2);
		DELAY_D->delay_simple_action(master,
			"$N����ġ�Ŷ����һ�����ƺ�������ʲô���ֺ���û����\n",3);
	}
}

void do_addworker() {
	string p_ld=master->query_primary_id();
	mixed ret;
	string job_id="getppl";
	poped=0;
   	modal_pop();
	
    call_out("quit_menu_application",5);

	if(objectp(slave)&&objectp(master)) 
	{
	    master->targetted_action("$N��$T�������"+p_roomname+
			"��"+p_workername+"��������������Ҫ������һЩ"+p_workername+
			"��\n",slave);
//Modified by Listen on Aug 20th,2001
//A rank checker is added in case of get fake ppl to destory the farm
//Level to do getppl is setted at >= level 3
	    if((CHAR_D->get_char(p_id,"level")<3) && (!wizardp(p_id)))
	    {
		DELAY_D->delay_targetted_action(slave,master,
			"$N��$T����$R�Ĺ�ְ�ȼ�������������"+JOB_D->query_job(job_id,"name")
			+"�Ĺ�����\n",2);
		DELAY_D->delay_simple_action(master,
			"$N����ġ�Ŷ����һ�����ƺ�������ʲô���ֺ���û����\n",3);
		return;
	    }
//End of modification
	    ret=get_master()->can_have_more_ppl( r_id);
	    if(stringp(ret)) {
		DELAY_D->delay_targetted_action(slave,master,
			"$N��$T����"+ret,2);
		DELAY_D->delay_simple_action(master,
			"$N����ġ�Ŷ����һ�����ƺ�������ʲô���ֺ���û����\n",3);
		return;
	    } else if ( master->query_job(job_id,"count_lasttimes") > 
            JOB_D->query_job(job_id,"count_lasttimes")){
		DELAY_D->delay_targetted_action(slave,master,
			"$N��$T����$R��������"+JOB_D->query_job(job_id,"name")+
			"�Ѿ�������ˣ�Ӧ����Ϣһ���ˡ�\n",2);
		DELAY_D->delay_simple_action(master,
			"$N����ġ�Ŷ����һ�����ƺ�������ʲô���ֺ���û����\n",3);
		return;
	    } else {
		master->resign_job(job_id);
		master->add_job(job_id);
		master->set_job(job_id,"p_area",p_area);
		master->set_job(job_id,"f_id",f_id);
		master->set_job(job_id,"r_id",r_id);
		DELAY_D->delay_targetted_action(slave,master,"$N��$T����$R֮����������\n"+
			"�Ǿ��鷳$R��ȥ��һЩ"+p_workername+"�ɡ�\n���巽����ϸ�� help getppl\n",2);
		DELAY_D->delay_simple_action(master,
			"$N����ġ�Ŷ����һ�����ƺ�������ʲô���ֺ���û����\n",3);
		return;
	    }
	}

}


void do_orderworker() {
    string p_ld;
    mixed ret;
    string job_id="basejob";
    poped=0;
    modal_pop();

	call_out("sp_quit_menu_application",5);

    if(objectp(slave)&&objectp(master)) {
        master->targetted_action("$N��$T��������������Ŭ�����$S������ָ��һ�¡�\n",slave);
		if ( master->query_job(job_id,"count_lasttimes") > 
			JOB_D->query_job(job_id,"count_lasttimes")){
            DELAY_D->delay_targetted_action(slave,master,
                    "$N��$T����$R��������"+JOB_D->query_job(job_id,"name")+
                    "�Ѿ�������ˣ�Ӧ����Ϣһ���ˡ�\n",2);
            DELAY_D->delay_simple_action(master,
                    "$N����ġ�Ŷ����һ�����ƺ�������ʲô���ֺ���û����\n",3);
            return;
        } else {
            master->resign_job(job_id);
            master->add_job(job_id);
            master->set_job(job_id,"status","begin");
            master->set_job(job_id,"score",0);
            master->set_job("buildbase","memo","ָ��"+AREA_D->get_area(p_area,"name")+p_workername);

            DELAY_D->delay_targetted_action(slave,master,
                    "$N��$Tһ����æ�Ϲ�����$R����ָ�ӣ�������̫�ò����ˡ�\n"+
					"һ�߰��Ե������$r�����ǳԱ��˳ŵġ�\n",2);
            DELAY_D->delay_targetted_action(master,slave,
                    "$N��$T����һ�۵�����˵ʲô��\n",3);
            DELAY_D->delay_simple_action(slave,
                    "$N��æ��Ц����û˵ʲô��û˵ʲô��С�����ȥ���ˡ�\n",4);
			{
				object job=new(__DIR__+"basejob");
				job->init(master,slave);
			}
            return;
        }
    }
}
void do_dealworker() {
	do_nothing();
}



void create( )
{
    set_privilege(1);
}


mixed can_sub_worker(int val) {
	int pplnum;
	if(val<10) 
		return "һ�����ٲü�ʮ����";

	pplnum=get_master()->get_room(r_id,"pplnum");
	if(val>pplnum)
		return "��"+p_roomname+"û����ô��"+p_workername+"��";

	if(CHAR_D->get_char(p_id,"level")<3)
		return "$Rְλ���ߣ��������£�����Ҳ��������ѽ��";
	return 1;
	
}

void do_subworker(int val) {
	int pplnum,gold;
	mixed ret;
	poped=0;
   	modal_pop();
    call_out("quit_menu_application",5);

    master->targetted_action("$N��$T�����ҿ�����"+p_workername+"��ʣ��Ӧ�òü�"+val+"��"
			"��\n",slave);
	val=to_int(val);
	ret=can_sub_worker(val);
	if(stringp(ret)) {
		DELAY_D->delay_targetted_action(slave,master,
			"$N��$T����"+ret+"\n",2);
		DELAY_D->delay_simple_action(master,
			"$N����ġ�Ŷ����һ�����ƺ�������ʲô���ֺ���û����\n",3);
		return;
	}
	pplnum=get_master()->get_room(r_id,"pplnum");
	pplnum-=val;
	get_master()->set_room(r_id,"pplnum",pplnum);

	DELAY_D->delay_targetted_action(slave,master,
		"$N��$T������Щ"+p_workername+"�����µġ�\n",2);
	DELAY_D->delay_targetted_action(master,slave,
		"$N��$T����������ÿ��һ�����ӵ�ǲɢ�ѡ�\n",3);
	DELAY_D->delay_targetted_action(slave,master,
		"$N��$T����$R���ģ�$s���ȥ�졣\n",4);
	DELAY_D->delay_simple_action(master,
		"$N����ص��˵�ͷ��\n",5);

	gold=AREA_D->get_area(p_area,"gold");
	gold-=val;
	AREA_D->set_area(p_area,"gold",gold);
	set_rumor(AREA_D->get_area(p_area,"name")+"�����һ��"+p_workername+"��");
	log_me(AREA_D->get_area(p_area,"name")+"�����һ��"+p_workername+"��");
	return;

}



mixed can_sub_stuff(string stf,int val) {
	string stfname,prod,prodname;
	mapping consume;
	mapping src;
	if(!BASE_D->stuff_exist(stf))
		return "û��"+stf+"�������ʡ�";
	stfname=BASE_D->get_stuff(stf,"name");
	if(val<=0) 
		return "Ҫ���ٶ���"+stfname+"��";

	src=get_master()->get_room(r_id,"src");
	if(!mapp(src)) src=([]);
	
	if(src[stf]["num"]<val) return "����û����ô��"+stfname+"��";//suicide 2000.02.26

	if(CHAR_D->get_char(p_id,"level")<3)
		return "$Rְλ���ߣ��������£�����Ҳ��������ѽ��";
	return 1;
	
}

void done_substuff(string stf, int val) {
	int area_have;
	string stfname;
	mixed ret;
	mapping src;
	poped=0;
   	modal_pop();
    call_out("quit_menu_application",5);

	stfname=BASE_D->get_stuff(stf,"name");
	if(!stringp(stfname)) stfname=stf; 
	else stfname=BASE_D->get_stuff(stf,"unit")+stfname;

    master->targetted_action("$N��$T�����ҿ�����ԭ�Ϲ�ʣ��Ӧ���ٵ���"+val +stfname+
			"��\n",slave);
	val=to_int(val);
	ret=can_sub_stuff(stf,val);
	if(stringp(ret)) {
		DELAY_D->delay_targetted_action(slave,master,
			"$N��$T����"+ret+"\n",2);
		DELAY_D->delay_simple_action(master,
			"$N����ġ�Ŷ����һ�����ƺ�������ʲô���ֺ���û����\n",3);
		return;
	}
	area_have=AREA_D->get_area(p_area,stf);
        //modified by suicide in 2000.02.20 for keep the price of the src
	//to calculate the cost of product

	//AREA_D->set_area(p_area,stf,area_have+val);
	src=get_master()->get_room(r_id,"src");
	if(!mapp(src)) src=([]);
	if(!mapp(src[stf])) src[stf]=([]);
	src[stf]["num"]-=val;
	AREA_D->add_area_st(p_area,stf,val,src[stf]["price"]);
	get_master()->set_room(r_id,"src",src);

	DELAY_D->delay_targetted_action(slave,master,
		"$N��$T����$R���ģ�$s���ȥ�졣\n",2);
	DELAY_D->delay_simple_action(master,
		"$N����ص��˵�ͷ��\n",3);
	return;
}

void do_substuff(string stf) {
	get_input_then_call
     ((: done_substuff, stf:), "���ٶ��٣�");
}
mixed can_add_stuff(string stf,int val) {
	string stfname,prod,prodname;
	mapping consume;
	mapping src;
	int areahave;
	if(!BASE_D->stuff_exist(stf))
		return "û��"+stf+"�������ʡ�";
	stfname=BASE_D->get_stuff(stf,"name");
	if(val<=0) 
		return "Ҫ���Ӷ���"+stfname+"��";
	prod=get_master()->get_product(r_id);
	prodname=BASE_D->get_stuff(prod,"name");
	consume=BASE_D->get_stuff(prod,"consume");
	if(!sizeof(consume))
		return "����"+prodname+"����Ҫ�κ��������ʡ�";
	if(!consume[stf])
		return "����"+prodname+"����Ҫ"+stfname+"��";
	areahave=AREA_D->get_area(p_area,stf);
	if(areahave<val)
		return "������û����ô���"+stfname+"������";
	if(CHAR_D->get_char(p_id,"level")<2)
		return "$Rְλ���ߣ��������£�����Ҳ��������ѽ��";

	return 1;
	
}
void done_addstuff(string stf, int val) {
	int area_have;
	string stfname;
	mixed ret;
	mapping src;
	poped=0;
   	modal_pop();
    call_out("quit_menu_application",5);

	stfname=BASE_D->get_stuff(stf,"name");
	if(!stringp(stfname)) stfname=stf; 
	else stfname=BASE_D->get_stuff(stf,"unit")+stfname;

    master->targetted_action("$N��$T�����ҿ�����ԭ�ϲ��㣬Ӧ���ٵ���"+val +stfname+
			"��\n",slave);
	val=to_int(val);
	ret=can_add_stuff(stf,val);
	if(stringp(ret)) {
		DELAY_D->delay_targetted_action(slave,master,
			"$N��$T����"+ret+"\n",2);
		DELAY_D->delay_simple_action(master,
			"$N����ġ�Ŷ����һ�����ƺ�������ʲô���ֺ���û����\n",3);
		return;
	}
	area_have=AREA_D->get_area(p_area,stf);
	//modified by suicide in 2000.02.20 for keep the price of the src
	//to calculate the cost of product
	AREA_D->add_area_st(p_area,stf,-val,0);
	//AREA_D->set_area(p_area,stf,area_have-val);
	src=get_master()->get_room(r_id,"src");
	if(!mapp(src)) src=([]);
	if(!mapp(src[stf])) src[stf]=([]);
	src[stf]["num"]+=val;
	src[stf]["price"]=AREA_D->get_area_st_price(p_area,stf);
	get_master()->set_room(r_id,"src",src);

	DELAY_D->delay_targetted_action(slave,master,
		"$N��$T����$R���ģ�$s���ȥ�졣\n",2);
	DELAY_D->delay_simple_action(master,
		"$N����ص��˵�ͷ��\n",3);
	return;

	
}
void do_addstuff (string stf) {
	get_input_then_call
     ((: done_addstuff, stf:), "���Ӷ��٣�");
}
mixed can_changestuff (string stf) {
	string stfname;
	string curstf;
	int lv,mylv;
	if(!BASE_D->stuff_exist(stf))
		return "û����˵��"+stf+"���ֶ���������ʲô����ѽ��";
	stfname=BASE_D->get_stuff(stf,"name");
	lv=BASE_D->get_product_level(f_id,stf);
	if(lv==0) return p_basename+"��������"+stfname+"��";
	mylv=get_master()->get_level();
	curstf=get_master()->get_room(r_id,"pro");
	if(curstf==stf) return "Ŀǰ��"+p_roomname+"�Ĳ�Ʒ����"+stfname+"�";
	if(mylv<lv)
		return "��"+p_basename+"�ȼ�̫�ͣ��޷�����"+stfname;
	if(CHAR_D->get_char(p_id,"level")<2)
		return "$Rְλ���ߣ��������£�����Ҳ��������ѽ��";
	return 1;

}
void do_changestuff (string stf) {
	string stfname;
	mixed ret;
	poped=0;
   	modal_pop();
    call_out("quit_menu_application",6);

	stfname=BASE_D->get_stuff(stf,"name");
	if(!stringp(stfname)) stfname=stf; 

    master->targetted_action("$N��$T�����ҽ��鱾"+p_roomname+"������"+stfname+"��\n",slave);
	ret=can_changestuff(stf);

	if(stringp(ret)) {
		DELAY_D->delay_targetted_action(slave,master,
			"$N��$T����"+ret+"\n",2);
		DELAY_D->delay_simple_action(master,
			"$N����ġ�Ŷ����һ�����ƺ�������ʲô���ֺ���û����\n",3);
		return;
	}
	get_master()->set_room(r_id,"pro",stf);
	get_master()->set_room(r_id,"work",0);

	DELAY_D->delay_targetted_action(slave,master,
		"$N��$T������������ǰ���۵������������ˡ�\n",2);
	DELAY_D->delay_targetted_action(master,slave,
		"$N��$T����û�а취������"+stfname+"����Ҫ��\n",3);
	
	DELAY_D->delay_targetted_action(slave,master,
		"$N��$T����$R���ģ�$s���ȥ�졣\n",4);
	DELAY_D->delay_simple_action(master,
		"$N����ص��˵�ͷ��\n",5);
	set_rumor(AREA_D->get_area(p_area,"name")+p_basename+"��ʼ����"+stfname+"��");

	return;

}
void init_base_menu() {
    toplevel = new_menu("\n�����к͹�ɣ�");
    quit_item = new_menu_item("����", (:quit_menu_application:), "q");
    seperator = new_seperator
    ("----------------------------------------------------------------------");
    space = new_seperator
    ("                                                                      ");

    add_menu_item(toplevel, seperator);
    add_menu_item(toplevel, space);
    add_menu_item(toplevel, new_menu_item("ѯ�����",	(: do_query :) ,"1"));
    add_menu_item(toplevel, new_menu_item("����"+p_workername,	(: do_addworker :) ,"2"));

    add_menu_item(toplevel, new_menu_item("�ü�"+p_workername,	(: get_input_then_call,
		(: do_subworker :) ,"�ü�����"+p_workername :), "3"));

	add_menu_item(toplevel, new_menu_item("ָ��"+p_workername,	(: do_orderworker :)  ,"4"));

    add_menu_item(toplevel, new_menu_item("��������",	(: do_dealworker :)  ,"5"));

    add_menu_item(toplevel, new_menu_item("����ԭ��",	(: get_input_then_call,
		(: do_addstuff :) ,"���Ӻ���ԭ�ϣ�" :), "6"));

    add_menu_item(toplevel, new_menu_item("����ԭ��",	(: get_input_then_call,
		(: do_substuff :) ,"���ٺ���ԭ�ϣ�" :), "7"));

    add_menu_item(toplevel, new_menu_item("�ı��Ʒ",	(: get_input_then_call,
		(: do_changestuff :) ,"��Ϊ���ֲ�Ʒ��" :), "8"));
    
	add_menu_item(toplevel, quit_item);
    add_menu_item(toplevel, space);
    set_menu_prompt (toplevel, "����ָ��[1234568q]: ");

}
void start_head_menu (object m, object s, string a, string f, string r) {
	r_id=r;
	p_workername=BASE_D->get_base(f,"workername");
	start_menu(m,s,a,f);

//	init_base_menu();

}
