//��ڧ
#include <mudlib.h>
#include <daemons.h>
#include <ansi.h>
void show_result(object ob, string who);
int p_id;
int e_id,r_id;
int t_id=0;
int p_skill;
string e_name, p_name, t_name;
void main(object ob, string who)
{
	int i,x,y,x2,y2,x3,y3, *troops;
	object env;
	string where;
	
	env = environment( ob );
	p_id=TROOP_D->get_char_troop(this_body()->query_primary_id());
	e_id=TROOP_D->get_char_troop(who);
	e_name=CHAR_D->get_char(who,"name");
	p_name=CHAR_D->get_char(ob->query_primary_id(),"name");
	where = TROOP_D->get_troop_area(p_id);
if(!(p_skill=CHAR_D->get_char(ob->query_primary_id(),"skills")["neihong"]))
	{	write("�㲻����ڧ֮�ơ�\n");
		return;}
	if( !p_id){
                write("ֻ�����ھ��в���ʹ����ڧ֮�ơ�\n");
                return;
        }	
	// In the furture, We have to consider theplayer's ablility
	// add the exp of this jimou, reduce mp, etc.
	if ( !e_id || TROOP_D->get_troop_area(e_id)!=where)
		{ write("�Է����ڴ�ս���ϡ�\n");
			return;
		}
	if (TROOP_D->get_troop_side(e_id) ==TROOP_D->get_troop_side(p_id))
                {write ("�����򼺷�����ʩ�ô˼ơ�\n");
                        return;
                }	
	x =TROOP_D->get_troop_position(p_id)[0];
	y = TROOP_D->get_troop_position(p_id)[1];

	x2 = TROOP_D->get_troop_position(e_id)[0];
                y2 = TROOP_D->get_troop_position(e_id)[1];
	
                if( (x-x2)*(x-x2)+(y-y2)*(y-y2) > 4 ){
			write("�������̫Զ�޷�ʩ�ơ�\n");
			return;}
		troops = TROOP_D->list_troops();
        troops = troops - ({ p_id }) - ({ e_id});
        if( !sizeof(troops) )
	{ write ("���������ӿɹ���ڧ��\n");
	return;}
	for( i = 0; i < sizeof(troops); i++ ){
                r_id = troops[i];
	if(TROOP_D->get_troop_side(r_id)!=TROOP_D->get_troop_side(p_id))	
	{	x3= TROOP_D->get_troop_position(r_id)[0];
		y3=TROOP_D->get_troop_position(r_id)[1];
		if ((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2)<1)
		t_id=r_id;
		}
		}
	if (!t_id)
	{	write("���������ӿɹ���ڧ��\n");
		return;
	}

                tell(deep_inventory(TROOP_D->find_troop(e_id)),
	"һ�������У��������������е���Ϯ����\n",
                        MSG_INDENT);
		tell(deep_inventory(TROOP_D->find_troop(t_id)),
        "һ�������У��������������е���Ϯ����\n",
                        MSG_INDENT);
                // In future, we have to consider effects of the
                // ablility of general, zhenxing, dixing, etc.
                // Now the damage depends only on the No of bowman
	ob->simple_action(SG_SKILL_D->query_use("neihong"));
	ob->start_busy(10, "����æ��ʩ���ء�\n");
	
	call_out("show_result", 10+random(5), ob, who);
}
void show_result(object ob, string who)
{	
	int kill,kill1,mora,mora1;
	int e_skill;
	int damage, t_num, e_num, p_num;
	int task_id;
	float rate;
	
	if (!(CHAR_D->get_char(who,"skills")))
	e_skill=0;
	else {
	e_skill=CHAR_D->get_char(who,"skills")["neihong"];}
	if (!objectp(who))
        e_skill= CHAR_D->get_char(who,"skills")["sk_zhimou"];
	kill =random(p_skill);
	kill1 =random(e_skill);
	kill = kill*2 - kill1 *1.8;
	ob->stop_busy();
	if( kill>50)
	{	tell(deep_inventory(TROOP_D->find_troop(e_id)),
                "�������������壡�壡��\n",
                        MSG_INDENT);
		tell(deep_inventory(TROOP_D->find_troop(t_id)),
                "�������������壡�壡��\n",
                        MSG_INDENT);
		mora = random (-20) -10;
		mora1 = random (6) +2;
		rate = 2;
		ob->simple_action(SG_SKILL_D->query_succ("neihong"));
		} 
	else
	{     if(kill>20)
		{
	tell(deep_inventory(TROOP_D->find_troop(e_id)),
        	"��е������жӣ�С�ĵ���͵Ϯ����\n",
                        MSG_INDENT);	
	tell(deep_inventory(TROOP_D->find_troop(t_id)),
                "��е������жӣ�С�ĵ���͵Ϯ����\n",
                        MSG_INDENT);
		mora = random (-10) - 5;
		mora1 = random (3) + 1;
		rate = 1.1;
		ob->simple_action(SG_SKILL_D->query_succ("neihong"));
		}
	      else if( kill>5)
		{
		tell(deep_inventory(TROOP_D->find_troop(e_id)),
        	"����ɵ�˵������С���жӣ��������˾��ģ���\n",
                        MSG_INDENT);
		tell(deep_inventory(TROOP_D->find_troop(t_id)),
                "����ɵ�˵������С���жӣ��������˾��ģ���\n",
                        MSG_INDENT);
		mora = random(-5) - 1;
		mora1 = 1;
		rate = 0.4;
		ob->simple_action(SG_SKILL_D->query_succ("neihong"));
		}	
	      else 
		{
		tell(deep_inventory(TROOP_D->find_troop(e_id)),
        	"�����г����˵���������ţ�������ڧ֮�ƣ���\n",
                        MSG_INDENT);
		tell(deep_inventory(TROOP_D->find_troop(t_id)),
                "�����г����˵���������ţ�������ڧ֮�ƣ���\n",
                        MSG_INDENT);
		mora = random(8) + 3;
		mora1 = random(-8) - 3;
		rate = 0;
		ob->simple_action(SG_SKILL_D->query_fail("neihong"));
		}
	}
	p_num=TROOP_D->get_soldier_total_number(p_id);
	e_num=TROOP_D->get_soldier_total_number(e_id);
	t_num = TROOP_D->get_soldier_total_number(t_id);
	TROOP_D->add_morale(p_id,mora1);
	TROOP_D->add_morale(t_id,mora);
	TROOP_D->add_morale(e_id,mora);
	if (t_num > (e_num*5))
	{damage = rate * kill * 2* t_num / (e_num*2.5);}
	else 
	{if (t_num < e_num)
	damage = rate *kill * t_num * 4/e_num;
	else 
	damage = rate * kill * 2 * t_num / (e_num *1.2); 
	}
	if(damage>0){
            task_id=TROOP_D->get_troops(e_id,"task_id");
            WARAI_D->war_inf(task_id,
              TROOP_D->find_troop(e_id)->query_id()[1]+"����"+p_name+"����ڧ֮�ƣ���"+TROOP_D->find_troop(t_id)->query_id()[1]+"��ս��ʧ"+chinese_number(damage)+"�ˡ�","b");
	 WARAI_D->kill_troop(e_id,damage);
         WARAI_D->kill_troop(t_id,damage);	        
	 WARAI_D->clear_empty_troop(({t_id}));
	 WARAI_D->clear_empty_troop(({e_id}));
         }	
	else {
	damage = (t_num + e_num)*100/p_num;
	task_id=TROOP_D->get_troops(e_id,"task_id");
	WARAI_D->war_inf(task_id,
	TROOP_D->find_troop(p_id)->query_id()[1]+"ʹ����ڧ֮��ʧ�ܣ������˳˻�����"+chinese_number(damage)+"�ˡ�","b");
	WARAI_D->kill_troop(p_id,damage);
         WARAI_D->clear_empty_troop(({p_id}));	
	}
return;
}
