// ռ��
#include <mudlib.h>
#include <daemons.h>
#include <ansi.h>
void show_result(object ob, int p_skill, int p_id, int e_id);
string p_name, where, sid;

void main(object ob)
{
	int i, p_skill, p_id, e_id;
	object env;
	
	env = environment( ob );
	p_id=TROOP_D->get_char_troop(this_body()->query_id()[0]);
	p_name=this_body()->query_id()[0];
	p_skill=CHAR_D->get_char(ob->query_primary_id(),"skills")["zhanbu"];
	if(!(CHAR_D->get_char(p_name,"skills")))
       	{       write("�㲻��ռ��֮����\n");
                return;
       	}
	
	if( !p_id){
                write("ֻ�����ھ��в���ʹ��ռ��֮����\n");
                return;
        };	
	// In the furture, We have to consider theplayer's ablility
	// add the exp of this jimou, reduce mp, etc.
	where = TROOP_D->get_troop_area(p_id);
	ob->simple_action(SG_SKILL_D->query_use("zhanbu"));
	ob->start_busy(10, "����æ��ʹ��ռ��֮����");
	load_object("/daemons/cast_d.c")->reg_player(ob->query_primary_id(),"zhanbu");
        ob->award_exp(ob->query_sk_level("sk_zhimou")/2+random(20), "zhanbu");
	call_out("show_result", 5+random(5), ob, p_skill, p_id, e_id);
}
void show_result(object ob, int p_skill, int p_id, int e_id)
{	
	int mora,rm, i;
	int kill, *troops, *temps;
	int damage;
	int sm, sm1;

	kill = p_skill/5;
	kill = random(kill);
	tell_user("group","kill is "+kill+".\n");
	troops= TROOP_D->list_troops();
	troops= filter_array(troops,(:(TROOP_D->get_troop_area($1)==where)
	:) );
	sid = TROOP_D->get_troop_side(p_id);
	temps = filter_array(troops,(:(TROOP_D->get_troop_side($1)!=sid)
        :) );
	if(sizeof(temps)>1)
	{if (random(6)>1)
		troops = temps;
	 else 
	 {if(sizeof(troops) >1)
                troops = troops - ({p_id});}	
	}
	else {
	if(sizeof(troops) >1)
		troops = troops - ({p_id});
	}
	if (kill >20) kill=20;
	ob->stop_busy();
	if( kill==15 )
	{	if (random(2) >= 1)
		{ob->simple_action(SG_SKILL_D->query_succ("zhanbu"));
		rm=this_body()->query_sg_rongmao();
        rm+=random(1)+1;
        rm=bmin(30,rm);
        this_body()->set_sg_rongmao(rm);
	WARAI_D->war_inf(TROOP_D->get_troops(p_id,"task_id"),
TROOP_D->find_troop(p_id)->query_id()[1]+"ʹ��ռ��֮����ʹ"+
CHAR_D->get_char(p_name,"name")+
"������ò��"+chinese_number(rm)+"�㡣","b");
		}
		else 
		{ ob->simple_action(SG_SKILL_D->query_succ("zhanbu"));
                rm=this_body()->query_sg_rongmao();
        rm+=random(-1)-1;
        rm=bmin(30,rm);
        this_body()->set_sg_rongmao(rm);
        WARAI_D->war_inf(TROOP_D->get_troops(p_id,"task_id"),
TROOP_D->find_troop(p_id)->query_id()[1]+"ʹ��ռ��֮����ʹ"+
CHAR_D->get_char(p_name,"name")+
"������ò��"+chinese_number(rm)+"�㡣","b");	
	}
} 
	if (kill == 5 || kill ==7 || kill == 10 || kill == 13)
		{
		ob->simple_action(SG_SKILL_D->query_succ("zhanbu"));
	e_id= troops[random(sizeof(troops))];
	damage= kill * p_skill *3/5 ;
	WARAI_D->war_inf(TROOP_D->get_troops(p_id,"task_id"),
TROOP_D->find_troop(p_id)->query_id()[1]+"ʹ��ռ��֮�������������ɱ"+
TROOP_D->find_troop(e_id)->query_id()[1]+chinese_number(damage)+
"�ˡ�","b");
	WARAI_D->kill_troop(e_id,damage);
	WARAI_D->clear_empty_troop(({e_id}));
		}
	if (kill == 11 || kill ==17 || kill == 9)
	{	ob->simple_action(SG_SKILL_D->query_succ("zhanbu"));
        e_id= troops[random(sizeof(troops))];
        damage= 10+ random(10);
	kill = kill * 3;
"/daemons/condition_d.c"->apply_condition(e_id,"confuse",kill,damage);
        WARAI_D->war_inf(TROOP_D->get_troops(p_id,"task_id"),
TROOP_D->find_troop(p_id)->query_id()[1]+"ʹ��ռ��֮������������ʹ"+
TROOP_D->find_troop(e_id)->query_id()[1]+"������ҡ�","b");
	}
	     if (kill == 0 || kill == 1)
		{
		ob->simple_action(SG_SKILL_D->query_fail("zhanbu"));		
		kill = (kill+10)*3;
		damage= 10+ random(10);
"/daemons/condition_d.c"->apply_condition(p_id,"confuse",kill,damage);	
		WARAI_D->war_inf(TROOP_D->get_troops(p_id,"task_id"),
TROOP_D->find_troop(p_id)->query_id()[1]+"ʹ��ռ��֮��ʧ�ܣ�������ҡ�","b");
	
		}
	
	    if (kill == 12)
                {
                AREA_D->set_area(where, "wind", random(9));
                WARAI_D->war_inf(TROOP_D->get_troops(p_id,"task_id"),
                        TROOP_D->find_troop(p_id)->query_id()[1]+
"ʹ��ռ��֮��ʹ����תΪ"+DAY_D->get_wind_short(AREA_D->get_area(where,"wind"))+"��","b");
		}
	    if (kill == 16)
		{
		AREA_D->set_area(where, "weather", random(7));	
		WARAI_D->war_inf(TROOP_D->get_troops(p_id,"task_id"),
			TROOP_D->find_troop(p_id)->query_id()[1]+
"ʹ��ռ��֮��ʹ����תΪ"+DAY_D->get_weather_short(AREA_D->get_area(where,"weather"))+"��", "b");
		}
	
	if (kill == 14)
		{ob->simple_action(SG_SKILL_D->query_succ("zhanbu"));
		sm = this_body()->query_shouming();
		if (random(2) >= 1)
		{ sm1 = random(1) +1;
		  sm= sm + sm1;
		  this_body()->set_shouming(sm);
	WARAI_D->war_inf(TROOP_D->get_troops(p_id,"task_id"),
TROOP_D->find_troop(p_id)->query_id()[1]+"ʹ��ռ��֮����������ף��������"+
CHAR_D->get_char(p_name,"name")+
"����"+chinese_number(sm1)+"�ꡣ","b");
		}
		else {
		sm1 = random(-1) -1;
                  sm= sm + sm1;
		sm1 = 0-sm1;
                  this_body()->set_shouming(sm);
        WARAI_D->war_inf(TROOP_D->get_troops(p_id,"task_id"),
TROOP_D->find_troop(p_id)->query_id()[1]+"ʹ��ռ��֮�����ܶ�ħ���䣬����"+
CHAR_D->get_char(p_name,"name")+
"����"+chinese_number(sm1)+"�ꡣ","b");
	}
	}	

	if (kill == 20 || kill == 19)
	{
	ob->simple_action(SG_SKILL_D->query_succ("zhanbu"));
        for (i=0;i<4;i++){
	e_id= troops[random(sizeof(troops))];
        damage= kill * p_skill*1.2/2 ;
	WARAI_D->war_inf(TROOP_D->get_troops(p_id,"task_id"),
TROOP_D->find_troop(p_id)->query_id()[1]+"ʹ��ռ��֮��������������ɱ"+
TROOP_D->find_troop(e_id)->query_id()[1]+chinese_number(damage)+
"�ˡ�","b");
        WARAI_D->kill_troop(e_id,damage);
        WARAI_D->clear_empty_troop(({e_id}));
	}
	}
	if (kill == 4 || kill ==2){
	ob->simple_action(SG_SKILL_D->query_succ("zhanbu"));
		e_id=troops[random(sizeof(troops))];	
		damage= kill * p_skill/10 ;
	if (random(2) >0){	
	TROOP_D->add_morale(e_id,damage);
	WARAI_D->war_inf(TROOP_D->get_troops(p_id,"task_id"),
TROOP_D->find_troop(p_id)->query_id()[1]+"ʹ��ռ��֮����������ӥʹ"+
TROOP_D->find_troop(e_id)->query_id()[1]+
"ʿ��������","b");		
	   	}
	else	{
	damage = 0 - damage;
	WARAI_D->war_inf(TROOP_D->get_troops(p_id,"task_id"),
TROOP_D->find_troop(p_id)->query_id()[1]+"ʹ��ռ��֮������������ʹ"+
TROOP_D->find_troop(e_id)->query_id()[1]+
"ʿ���½���","b");
		}	
	}
	if (kill == 3 || kill ==8 || kill == 6)
        {ob->simple_action(SG_SKILL_D->query_succ("zhanbu"));
                e_id=troops[random(sizeof(troops))];
                damage= kill * p_skill/8 ;
		kill= kill *18;
"/daemons/condition_d.c"->apply_condition(e_id,"poison",kill,damage);
WARAI_D->war_inf(TROOP_D->get_troops(p_id,"task_id"),
TROOP_D->find_troop(p_id)->query_id()[1]+"ʹ��ռ��֮������������ʹ"+
TROOP_D->find_troop(e_id)->query_id()[1]+
"�ж���","b");

        }



return;
}