// 假传命令
#include <mudlib.h>
#include <daemons.h>
#include <ansi.h>
void show_result(object ob, string who, int p_skill, int p_id, int e_id);

string e_name, p_name;
string p_pid;
void main(object ob, string who)
{
	int p_skill, p_id, e_id;
	int x,y,x2,y2;
	object env;
	string where;
	string chars;	

	env = environment( ob );
	p_id=TROOP_D->get_char_troop(this_body()->query_primary_id());
	p_pid = this_body()->query_primary_id();
	e_id=TROOP_D->get_char_troop(who);
	e_name=CHAR_D->get_char(who,"name");
	p_name=CHAR_D->get_char(ob->query_primary_id(),"name");
	where = TROOP_D->get_troop_area(p_id);
	if(!(p_skill=CHAR_D->get_char(ob->query_primary_id(),"skills")["fakeorder"]))
        {       write("你不会假传命令之计。\n");
                return;}
	if( !p_id){
                write("只有身在军中才能假传命令。\n");
                return;
        }	
	// In the furture, We have to consider theplayer's ablility
	// add the exp of this jimou, reduce mp, etc.
	if ( !e_id || TROOP_D->get_troop_area(e_id)!=where)
		{ write("对方不在此战场上。\n");
			return;
		}
	
	if (TROOP_D->get_troop_side(e_id) ==TROOP_D->get_troop_side(p_id))
                {write ("不可向己方部队施用此计。\n");
                        return;
                }
   chars=TROOP_D->get_troops(e_id,"chars");
   foreach(string c in chars)
   {
      if(CHAR_D->get_char(c,"status")==STATUS_ONLINE)
       {     write ("不可向人控部队使用假传命令。\n");
	return;
	}
   }
	x =TROOP_D->get_troop_position(p_id)[0];
	y = TROOP_D->get_troop_position(p_id)[1];

	x2 = TROOP_D->get_troop_position(e_id)[0];
                y2 = TROOP_D->get_troop_position(e_id)[1];

                if( (x-x2)*(x-x2)+(y-y2)*(y-y2) > 9 ){
			write("你离敌人太远无法施计。\n");
			return;}
                // In future, we have to consider effects of the
                // ablility of general, zhenxing, dixing, etc.
                // Now the damage depends only on the No of bowman
	ob->simple_action(SG_SKILL_D->query_use("fakeorder"));
	ob->start_busy(10, "你正忙于假传命令呢。");
	load_object("/daemons/cast_d.c")->reg_player(ob->query_primary_id(),"fakeorder");
	ob->award_exp(ob->query_sk_level("sk_zhimou")/2+random(20), "fakeorder");
	call_out("show_result", 5+random(5), ob, who,p_skill, p_id, e_id);
}
void show_result(object ob, string who, int p_skill, int p_id, int e_id)
{	
	int kill,kill1,mora,mora1;
        int e_skill;
        int rate, damage, p_num, e_num;

        if (!(CHAR_D->get_char(who,"skills")))
        e_skill=0;
        else {
        e_skill=CHAR_D->get_char(who,"skills")["fakeorder"];}
	if (!objectp(who))
        e_skill= CHAR_D->get_char(who,"skills")["sk_zhimou"];
        kill =random(p_skill);
        kill1 =random(e_skill);
        kill = kill*2 - kill1 *1.8;
        ob->stop_busy();	
	if(kill>50)
{		mora = random (-10) -10;
		mora1 = random (6) +2;
		tell(deep_inventory(TROOP_D->find_troop(p_id)),
                "计策完全成功，敌人陷入迷惑中。\n",
                        MSG_INDENT);
		ob->simple_action(SG_SKILL_D->query_succ("fakeorder"));
	} 
	else
	{     if(kill>15)
		{
		mora = random (-5) - 5;
		mora1 = random (3) + 1;
	tell(deep_inventory(TROOP_D->find_troop(p_id)),
                "计策大成功，敌方迷惑。\n",
                        MSG_INDENT);	
	ob->simple_action(SG_SKILL_D->query_succ("fakeorder"));
		}
	      else 
		{
		mora = random(8) + 3;
		mora1 = random(-8) - 3;
		ob->simple_action(SG_SKILL_D->query_fail("fakeorder"));
		tell(deep_inventory(TROOP_D->find_troop(p_id)),
                "计策失败，我军蒙受损失。\n",
                        MSG_INDENT);
	  	damage= 100 + random (100);
        	WARAI_D->kill_troop(p_id,damage);
		WARAI_D->war_inf(TROOP_D->get_troops(p_id,"task_id"),
TROOP_D->find_troop(p_id)->query_id()[1]+"使用假传命令失败，被敌人乘机歼
灭"+chinese_number(damage)+"人。","b");
		WARAI_D->clear_empty_troop(({p_id}));
		
		}
	}
	TROOP_D->add_morale(p_id,mora1);
	TROOP_D->add_morale(e_id,mora);
	if (kill >15)
	{	damage = 1;
		kill = random(20)+(kill /10) * 3;
	"/daemons/condition_d.c"->apply_condition(e_id,"fake",kill,damage);
	TROOP_D->set_troops(e_id,"fake",p_pid);
	 WARAI_D->war_inf(TROOP_D->get_troops(p_id,"task_id"),
TROOP_D->find_troop(p_id)->query_id()[1]+"使用假传命令，令"+
TROOP_D->find_troop(e_id)->query_id()[1]+"陷入迷惑之中。","b");
	}
	return;
}
