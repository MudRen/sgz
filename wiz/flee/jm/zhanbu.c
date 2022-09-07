// 占卜
#include <mudlib.h>
#include <daemons.h>
#include <ansi.h>
void show_result(object ob);
int p_id, e_id;
int p_skill;
string p_name, where;
void main(object ob)
{
	int i;
	object env;
	
	env = environment( ob );
	p_id=TROOP_D->get_char_troop(this_body()->query_id()[0]);
	p_name=this_body()->query_id()[0];
	
	if(!(CHAR_D->get_char(p_name,"skills")))
       	{       write("你不会占卜之术。\n");
                return;
       	}
	
        if(!((p_skill=CHAR_D->get_char(p_name,"skills")["zhanbu"])>40))
	{	write("你占卜之术等级太低。\n");
		return;
	}
	if( !p_id){
                write("只有身在军中才能使用占卜之术。\n");
                return;
        };	
	// In the furture, We have to consider theplayer's ablility
	// add the exp of this jimou, reduce mp, etc.
	where = TROOP_D->get_troop_area(p_id);
	ob->simple_action(SG_SKILL_D->query_use("zhanbu"));
	ob->start_busy(10, "你正忙于使用占卜之术。");

	call_out("show_result", 5+random(5), ob);
}
void show_result(object ob)
{	
	int mora,rm, i;
	int kill, *troops;
	int damage;
	int sm, sm1;
	
	kill = p_skill/10;
	kill = random(kill);
	troops= TROOP_D->list_troops();
	troops= filter_array(troops,(:(TROOP_D->get_troop_area($1)==where)
	:) );
	
	if (kill >10) kill=10;
	ob->stop_busy();
	if( kill==7 )
	{	if (random(2) >= 1)
		{ob->simple_action(SG_SKILL_D->query_succ("zhanbu"));
		rm=this_body()->query_sg_rongmao();
        rm+=random(1)+1;
        rm=bmin(30,rm);
        this_body()->set_sg_rongmao(rm);
	WARAI_D->war_inf(TROOP_D->get_troops(p_id,"task_id"),
TROOP_D->find_troop(p_id)->query_id()[1]+"使用占卜之术，使"+
CHAR_D->get_char(p_name,"name")+
"增加容貌至"+chinese_number(rm)+"点。","b");
		}
		else 
		{ ob->simple_action(SG_SKILL_D->query_succ("zhanbu"));
                rm=this_body()->query_sg_rongmao();
        rm+=random(-1)-1;
        rm=bmin(30,rm);
        this_body()->set_sg_rongmao(rm);
        WARAI_D->war_inf(TROOP_D->get_troops(p_id,"task_id"),
TROOP_D->find_troop(p_id)->query_id()[1]+"使用占卜之术，使"+
CHAR_D->get_char(p_name,"name")+
"减低容貌至"+chinese_number(rm)+"点。","b");	
	}
} 
	if (kill ==4)
		{
		ob->simple_action(SG_SKILL_D->query_succ("zhanbu"));
	e_id= troops[random(sizeof(troops))];
	damage= kill * p_skill*30 /20 ;
	WARAI_D->war_inf(TROOP_D->get_troops(p_id,"task_id"),
TROOP_D->find_troop(p_id)->query_id()[1]+"使用占卜之术，招来天火烧杀"+
TROOP_D->find_troop(e_id)->query_id()[1]+chinese_number(damage)+
"人。","b");
	WARAI_D->kill_troop(e_id,damage);
	WARAI_D->clear_empty_troop(({e_id}));
		}
	if (kill == 6|| kill == 9)
	{	ob->simple_action(SG_SKILL_D->query_succ("zhanbu"));
        e_id= troops[random(sizeof(troops))];
        damage= 10+ random(10);
	kill = kill * 6;
"/daemons/condition_d.c"->apply_condition(e_id,"confuse",kill,damage);
        WARAI_D->war_inf(TROOP_D->get_troops(p_id,"task_id"),
TROOP_D->find_troop(p_id)->query_id()[1]+"使用占卜之术，招来天雷使"+
TROOP_D->find_troop(e_id)->query_id()[1]+"陷入混乱。","b");
	}
	     if (kill == 0 || kill == 1||kill == 5)
		{
		ob->simple_action(SG_SKILL_D->query_fail("zhanbu"));		
		kill = (kill+10)*3;
		damage= 10+ random(10);
"/daemons/condition_d.c"->apply_condition(p_id,"confuse",kill,damage);	
		WARAI_D->war_inf(TROOP_D->get_troops(p_id,"task_id"),
TROOP_D->find_troop(p_id)->query_id()[1]+"使用占卜之术失败，陷入混乱。","b");
	
		}
	if (kill == 8)
		{ob->simple_action(SG_SKILL_D->query_succ("zhanbu"));
		sm = this_body()->query_shouming();
		if (random(2) >= 1)
		{ sm1 = random(1) +1;
		  sm= sm + sm1;
		  this_body()->set_shouming(sm);
	WARAI_D->war_inf(TROOP_D->get_troops(p_id,"task_id"),
TROOP_D->find_troop(p_id)->query_id()[1]+"使用占卜之术，受天神祝福，增加"+
CHAR_D->get_char(p_name,"name")+
"寿命"+chinese_number(sm1)+"年。","b");
		}
		else {
		sm1 = random(-1) -1;
                  sm= sm + sm1;
		sm1 = 0-sm1;
                  this_body()->set_shouming(sm);
        WARAI_D->war_inf(TROOP_D->get_troops(p_id,"task_id"),
TROOP_D->find_troop(p_id)->query_id()[1]+"使用占卜之术，受恶魔诅咒，减少"+
CHAR_D->get_char(p_name,"name")+
"寿命"+chinese_number(sm1)+"年。","b");
	}
	}	

	if (kill == 10)
	{
	ob->simple_action(SG_SKILL_D->query_succ("zhanbu"));
        for (i=0;i<4;i++){
	e_id= troops[random(sizeof(troops))];
        damage= kill * p_skill*70 /20 ;
	WARAI_D->war_inf(TROOP_D->get_troops(p_id,"task_id"),
TROOP_D->find_troop(p_id)->query_id()[1]+"使用占卜之术，招来天龙击杀"+
TROOP_D->find_troop(e_id)->query_id()[1]+chinese_number(damage)+
"人。","b");
        WARAI_D->kill_troop(e_id,damage);
        WARAI_D->clear_empty_troop(({e_id}));
	}
	}
	if (kill == 3){
	ob->simple_action(SG_SKILL_D->query_succ("zhanbu"));
		e_id=troops[random(sizeof(troops))];	
		damage= kill * p_skill/10 ;
	if (random(2) >0){	
	TROOP_D->add_morale(e_id,damage);
	WARAI_D->war_inf(TROOP_D->get_troops(p_id,"task_id"),
TROOP_D->find_troop(p_id)->query_id()[1]+"使用占卜之术，招来天鹰使"+
TROOP_D->find_troop(e_id)->query_id()[1]+
"士气上升。","b");		
	   	}
	else	{
	damage = 0 - damage;
	WARAI_D->war_inf(TROOP_D->get_troops(p_id,"task_id"),
TROOP_D->find_troop(p_id)->query_id()[1]+"使用占卜之术，招来天鹫使"+
TROOP_D->find_troop(e_id)->query_id()[1]+
"士气下降。","b");
		}	
	}
	if (kill == 2)
        {ob->simple_action(SG_SKILL_D->query_succ("zhanbu"));
                e_id=troops[random(sizeof(troops))];
                damage= kill * p_skill/10 ;
		kill= kill *24;
"/daemons/condition_d.c"->apply_condition(e_id,"poison",kill,damage);
WARAI_D->war_inf(TROOP_D->get_troops(p_id,"task_id"),
TROOP_D->find_troop(p_id)->query_id()[1]+"使用占卜之术，招来天蛇使"+
TROOP_D->find_troop(e_id)->query_id()[1]+
"中毒。","b");

        }



return;
}
