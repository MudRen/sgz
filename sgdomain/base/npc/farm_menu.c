//farm_menu.c this is used to give order to leader of a base 
// command by fire on Jan 2000

#include <menu.h>
#include <mudlib.h>
#include <verb.h>
#include <ppl.h>

#define LOG_FILE "/sgdomain/base/base.log"

inherit MENUS;
inherit M_ACCESS;
inherit M_GRAMMAR;
inherit M_GLOB;
MENU toplevel;
MENU_ITEM quit_item;
MENU_ITEM seperator;
MENU_ITEM space;

protected object master,slave;
protected int poped;
protected string p_id,p_area,f_id;
protected string p_roomname,p_basename,p_headname;
protected string p_rumor="";

int log_me(string msg) {
	unguarded(1, (: write_file, LOG_FILE, msg :));
	return 1;
}

void set_rumor(string msg) {
	p_rumor=msg;
}
void do_nothing() {
        poped=0;
        modal_pop();

    call_out("quit_menu_application",2);

        if(objectp(slave)&&objectp(master)) {
                master->responda("nothing");
                slave->responda("doubt");
        }
}

object get_master() {
        return SGBASE(p_area,f_id);
}
void real_quit()
{
        if(poped&&(objectp(master)))
                modal_pop();
        remove_call_out("quit_menu_application");

        if(objectp(slave))
              slave->set_busy(0);
		if(sizeof(p_rumor)>0) 
		CHANNEL_D->deliver_tell("rumor","system",p_rumor);

		destruct(this_object());

}

void quit_menu_application()
{
        if(objectp(master)) {
                if(poped)
                        modal_pop();
                poped=0;
                if(objectp(slave))
                master->targetted_action(
                        "$N��$T��������û���ˣ������°ɡ�\n",slave);
                DELAY_D->delay_simple_action(slave,
                        "$Nһ�Ϲ������ǣ�Ȼ���˵�һ�ߣ�\n",2);
        }
        call_out("real_quit",4);
}

void do_query() {
        poped=0;
        modal_pop();

    call_out("quit_menu_application",5);

        if(objectp(slave)&&objectp(master)) {
            master->targetted_action("$N��$T�������������ô������\n",slave);
            DELAY_D->delay_targetted_action(slave,master,
                        "$N��$T����"+
						get_master()->stat_me_total(),2);
        }
}

void do_addroom() {
        string p_ld;
        mixed ret;
        string job_id="buildbase";
        poped=0;
        modal_pop();

    call_out("quit_menu_application",5);

        if(objectp(slave)&&objectp(master)) {
            master->targetted_action("$N��$T������������ѽ���ҿ�����Ҫ�ٶ࿪��һƬ"+
		p_roomname+"��\n",slave);
                if(CHAR_D->get_char(p_id,"level")>2) {
                        ret=get_master()->can_have_more_room();
                        if(stringp(ret)) {
                                DELAY_D->delay_targetted_action(slave,master,
                                        "$N��$T����"+ret+"\n",2);
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
                                p_ld=get_master()->get_leader();
                                master->set_asklist("buildbase","target",p_ld);
                                master->set_asklist("buildbase","filename",PJOB+"buildbase/buildbase")
;
                                master->set_asklist("buildbase","funname","ask_buildbase");

                                master->resign_job(job_id);
                                master->add_job("buildbase");
                                master->set_job("buildbase","status","begin");
                                master->set_job("buildbase","area",p_area);
                                master->set_job("buildbase","f_id",f_id);
                                master->set_job("buildbase","memo","����"+CHAR_D->get_char(p_ld,"name")+"ͬ��");

                                DELAY_D->delay_targetted_action(slave,master,
                                        "$N��$T�����޽���"+p_roomname+"�Ǵ����飬$R�������󵽱�"+
                                        p_basename+"�ܼ�"+CHAR_D->get_char(p_ld,"name")+
                                        "��ͬ��ſ��ԣ���ȥֱ���������ˡ�\n",2);
                                DELAY_D->delay_simple_action(master,
                                        "$N����ġ�Ŷ����һ�����ƺ�������ʲô���ֺ���û����\n",3);
                                return;
                        }
                }
                else {
                                DELAY_D->delay_targetted_action(slave,master,
                                        "$N��$T����$Rְλ���ߣ��������£�����Ҳ��������ѽ��\n",2);
                                DELAY_D->delay_simple_action(master,
                                        "$N����ġ�Ŷ����һ�����ƺ�������ʲô���ֺ���û����\n",3);

                }
        }

}
void do_gethead() {
        string p_ld;
        mixed ret;
        string job_id="gethead";
        poped=0;
        modal_pop();

    call_out("quit_menu_application",5);

        if(objectp(slave)&&objectp(master)) {
            master->targetted_action("$N��$T�����������"+p_basename+
                        "��Щ"+p_roomname+"��û��"+p_headname+"�����ǻ���Ҫ��ӶһЩ"
                        +p_headname+"��\n",slave);
                ret=get_master()->no_head_room();
                if(!stringp(ret)) {
                        DELAY_D->delay_targetted_action(slave,master,
                                "$N��$T����$R����˰ɣ����������Ѿ����ˡ�\n",2);
                        DELAY_D->delay_simple_action(master,
                                "$N����ġ�Ŷ����һ�����ƺ�������ʲô���ֺ���û����\n",3);
                        return;
                } else if ( (master->query_job(job_id,"beg_time")>0) &&(
         (time()-master->query_job(job_id,"beg_time"))<300)){
                        DELAY_D->delay_targetted_action(slave,master,
                                "$N��$T����$R��û��ȥ��"+master->query_job(job_id,"memo")+"ѽ��\n",2);
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
                        string m_area,m_id,m_name,m_zhou;
                        object o_guy;
                        m_area=AREA_D->pick_area();
                        m_zhou=AREA_D->get_area(m_area,"zhou");
                        o_guy="/sgdomain/event/ev_guy"->create_ppl(m_area);
                        m_id=o_guy->query_primary_id();
                        m_name=o_guy->query_name();
                        master->set_asklist(job_id,"target",m_id);
                        master->set_asklist(job_id,"filename",PJOB+job_id+"/"+job_id);
                        master->set_asklist(job_id,"funname","ask_"+job_id);

                        master->resign_job(job_id);
                        master->add_job(job_id);
                        master->set_job(job_id,"status","begin");
                        master->set_job(job_id,"area",p_area);
                        master->set_job(job_id,"f_id",f_id);
                        master->set_job(job_id,"memo",m_zhou+m_name);

                        DELAY_D->delay_targetted_action(slave,master,"$N��$T����$R֮����������\n"+
                                DIRECTION_D->cdir(ret)+
                                "��"+p_basename+"��û��"+p_headname+"����˵"+m_zhou+
                                "�и���"+m_name+"������ʵ���ܸɡ�\n"+
                                "$R����ȥ����������\n",2);
                        DELAY_D->delay_simple_action(master,
                                "$N����ġ�Ŷ����һ�����ƺ�������ʲô���ֺ���û����\n",3);
                        return;
                }
        }
}

mixed can_fire_head(string r_id) {
	int pplnum;
	mixed head;
	head=get_master()->get_room(r_id);
	if(!mapp(head))
		return r_id+"����û��"+p_roomname+"�ɡ�";
	head=get_master()->get_room(r_id,"head");
	if(!mapp(head))
		return DIRECTION_D->cdir(r_id)+"�����"+p_roomname+"��û��"+p_headname+"�ɡ�";

	if(CHAR_D->get_char(p_id,"level")<3)
		return "$Rְλ���ߣ��������£�����Ҳ��������ѽ��";
	return 1;
	
}


void do_firehead(string r_id) {
	mapping head;
	string r_headname,c_rid;
	mixed ret;
	poped=0;
   	modal_pop();
    call_out("quit_menu_application",7);
	c_rid=DIRECTION_D->cdir(r_id);
	if(sizeof(c_rid)==0) c_rid=r_id;
    master->targetted_action("$N��$T�����ҿ�"+c_rid+"�����"+p_headname+"���²������������ˡ�\n",slave);
	ret=can_fire_head(r_id);
	if(stringp(ret)) {
		DELAY_D->delay_targetted_action(slave,master,
			"$N��$T����"+ret+"\n",2);
		DELAY_D->delay_simple_action(master,
			"$N����ġ�Ŷ����һ�����ƺ�������ʲô���ֺ���û����\n",3);
		return;
	}
	head=get_master()->get_room(r_id,"head");
	r_headname=head["sname"]+head["gname"];
	get_master()->set_room(r_id,"head",0);

	DELAY_D->delay_targetted_action(slave,master,
		"$N��$T����$R��Ȼ������$sҲ��Ϊ"+c_rid+
		p_roomname+"��"+p_headname+r_headname+
		"�Ǹ�ֻ�Է����ɻ���ˡ�ֻ�ǽ����"+p_headname+"��"+
		p_roomname+"�ͻ�ͣ����\n",2);
	DELAY_D->delay_targetted_action(master,slave,
		"$N��$T�������õ��ģ����Ǻܿ�ͻ������ˡ�\n",3);
	DELAY_D->delay_targetted_action(slave,master,
		"$N��Ŷ����һ����$T����$R���ģ�$s���ȥ�졣\n",4);
	DELAY_D->delay_simple_action(master,
		"$N����ص��˵�ͷ��\n",5);
	DELAY_D->delay_simple_action(master,
		p_headname+r_headname+"������ˡ�\n",6);
	get_master()->update_room(r_id);

	set_rumor(AREA_D->get_area(p_area,"name")+"�����"+p_headname+r_headname+"��");
	log_me(AREA_D->get_area(p_area,"name")+"�����"+p_headname+r_headname+"��");
	return;
}
void do_destroyroom() {
        do_nothing();

}

void create( )
{
    set_privilege(1);
}

void init_base_menu() {
    toplevel = new_menu("\n�����к͹�ɣ�");
    quit_item = new_menu_item("����", (:quit_menu_application:), "q");
    seperator = new_seperator
    ("----------------------------------------------------------------------");
    space = new_seperator
    ("                                                                     ");

    add_menu_item(toplevel, seperator);
    add_menu_item(toplevel, space);
    add_menu_item(toplevel, new_menu_item("ѯ�����",   (: do_query :),"1"));
    add_menu_item(toplevel, new_menu_item("����"+p_roomname,   (: do_addroom :),"2"));

    add_menu_item(toplevel, new_menu_item("��ļ"+p_headname,   (: do_gethead :),"3"));
    add_menu_item(toplevel, new_menu_item("���"+p_headname,   (: get_input_then_call,
                (: do_firehead :) ,"����ĸ�"+p_roomname+"��"+p_headname+"��" :) ,"4"));


    add_menu_item(toplevel, new_menu_item("����"+p_roomname,   (: get_input_then_call,
                (: do_destroyroom :) ,"�����ĸ�"+p_roomname+"��" :) ,"0"));



    add_menu_item(toplevel, quit_item);
    add_menu_item(toplevel, space);
    set_menu_prompt (toplevel, "����ָ��[12340q]: ");

}

void start_menu(object m, object s,string a, string f)
{
        master=m;
        slave=s;
        p_id=master->query_primary_id();
        p_area=a;
        f_id=f;
        p_roomname=BASE_D->get_base(f_id,"roomname");
        p_basename=BASE_D->get_base(f_id,"name");
        p_headname=BASE_D->get_base(f_id,"headname");
	init_base_menu();

        poped=1;
        init_menu_application( toplevel );
        call_out("quit_menu_application",50);
}

void sp_quit_menu_application()
{
        remove_call_out("quit_menu_application");
		destruct(this_object());
}

