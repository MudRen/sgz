// ʩ��
#include <mudlib.h>
#include <daemons.h>
#include <ansi.h>
void show_result(object ob, string who, int p_skill, int p_id, int e_id);

string e_name, p_name;

void main(object ob, string who)
{
        int p_skill, p_id, e_id;
	int x,y,x2,y2;
	object env;
	string where;
	
	env = environment( ob );
	p_id=TROOP_D->get_char_troop(this_body()->query_primary_id());
	e_id=TROOP_D->get_char_troop(who);
	e_name=CHAR_D->get_char(who,"name");
	p_name=CHAR_D->get_char(ob->query_primary_id(),"name");
	where = TROOP_D->get_troop_area(p_id);
	if(!(p_skill=CHAR_D->get_char(ob->query_primary_id(),"skills")["shidu"]))
        {       write("�㲻��ʩ��֮�ơ�\n");
                return;}
	if( !p_id){
                write("ֻ�����ھ��в���ʩ����\n");
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
p_skill=CHAR_D->get_char(ob->query_primary_id(),"skills")["shidu"];
	x =TROOP_D->get_troop_position(p_id)[0];
	y = TROOP_D->get_troop_position(p_id)[1];

	x2 = TROOP_D->get_troop_position(e_id)[0];
                y2 = TROOP_D->get_troop_position(e_id)[1];

                if( (x-x2)*(x-x2)+(y-y2)*(y-y2) > 9 ){
			write("�������̫Զ�޷�ʩ�ơ�\n");
			return;}
                tell(deep_inventory(TROOP_D->find_troop(e_id)),
	"ʿ��һ��������ԭ����"+p_name+"����Ĳ���ʹ��ʩ��֮�ơ�\n",
                        MSG_INDENT);
                // In future, we have to consider effects of the
                // ablility of general, zhenxing, dixing, etc.
                // Now the damage depends only on the No of bowman
	ob->simple_action(SG_SKILL_D->query_use("shidu"));
	ob->start_busy(10, "����æ��ʩ���ء�");
	load_object("/daemons/cast_d.c")->reg_player(ob->query_primary_id(), "shidu");	
	ob->award_exp(ob->query_sk_level("sk_zhimou")/2+random(20) ,"shidu");
	call_out("show_result", 5+random(5), ob, who, p_skill, p_id, e_id);
}
void show_result(object ob, string who, int p_skill, int p_id, int e_id)
{	
	int kill,kill1,mora,mora1;
        int e_skill;
        int rate, damage, p_num, e_num;

        if (!(CHAR_D->get_char(who,"skills")))
        e_skill=0;
        else {
e_skill = CHAR_D->get_skill(who,"shidu");}
if(!objectp(find_user(who)))
e_skill = CHAR_D->get_skill(who,"sk_zhimou");
	if(CHAR_D->get_skill(who,"chenzhuo"))
e_skill = e_skill + 1.5*CHAR_D->get_skill(who,"chenzhuo");

	kill = p_skill*2 - e_skill *1.2;
        kill =random(kill);
        ob->stop_busy();	
	if(kill>50)
	{	tell(deep_inventory(TROOP_D->find_troop(e_id)),
                "ʿ���׷׵��£���Ȼ���˺���Ķ���\n",
                        MSG_INDENT);
		mora = random (-20) -10;
		mora1 = random (6) +2;
		tell(deep_inventory(TROOP_D->find_troop(p_id)),
                "�Ʋ���ȫ�ɹ����������˺���Ķ���\n",
                        MSG_INDENT);
		ob->simple_action(SG_SKILL_D->query_succ("shidu"));
	} 
	else
	{     if(kill>20)
		{
	tell(deep_inventory(TROOP_D->find_troop(e_id)),
        	"ʿ����ɫ���࣬��Ȼ���˶���\n",
                        MSG_INDENT);	
		mora = random (-10) - 5;
		mora1 = random (3) + 1;
	tell(deep_inventory(TROOP_D->find_troop(p_id)),
                "�Ʋߴ�ɹ����з����˶���\n",
                        MSG_INDENT);	
	ob->simple_action(SG_SKILL_D->query_succ("shidu"));
		}
	      else if( kill>5)
		{
		tell(deep_inventory(TROOP_D->find_troop(e_id)),
        	"ʿ�����в��ʣ�Ӧ�������˶���\n",
                        MSG_INDENT);
		mora = random(-5) - 1;
		mora1 = 1;
		tell(deep_inventory(TROOP_D->find_troop(p_id)),
                "�Ʋ߳ɹ����������˶���\n",
                        MSG_INDENT);
	ob->simple_action(SG_SKILL_D->query_succ("shidu"));
		}	
	      else 
		{
		tell(deep_inventory(TROOP_D->find_troop(e_id)),
        	"ʿ���ɹ��ƽ����ʩ����\n",
                        MSG_INDENT);
		mora = random(8) + 3;
		mora1 = random(-8) - 3;
		ob->simple_action(SG_SKILL_D->query_fail("shidu"));
		tell(deep_inventory(TROOP_D->find_troop(p_id)),
                "�Ʋ�ʧ�ܣ��Ҿ�������ʧ��\n",
                        MSG_INDENT);
	  	damage= 100 + random (100);
        	WARAI_D->kill_troop(p_id,damage);
		WARAI_D->war_inf(TROOP_D->get_troops(p_id,"task_id"),
TROOP_D->find_troop(p_id)->query_id()[1]+"ʹ��ʩ��֮��ʧ�ܣ������˳˻���
��"+chinese_number(damage)+"�ˡ�","b");
		WARAI_D->clear_empty_troop(({p_id}));
		
		}
	}
	TROOP_D->add_morale(p_id,mora1);
	TROOP_D->add_morale(e_id,mora);
	if (kill >5)
{       damage = p_skill - e_skill*0.75+20 + random(10);
		if(damage<1) damage=1;
kill = (kill/1.7)*6;
"/daemons/condition_d.c"->apply_condition(e_id,"poison",kill,damage);
 WARAI_D->war_inf(TROOP_D->get_troops(p_id,"task_id"),
TROOP_D->find_troop(p_id)->query_id()[1]+"ʹ��ʩ��֮�ƣ���"+
TROOP_D->find_troop(e_id)->query_id()[1]+"�����ж�֮�С�","b");
	}
	return;
}
