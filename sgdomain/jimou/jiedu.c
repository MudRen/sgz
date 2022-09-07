// �ⶾ
#include <mudlib.h>
#include <daemons.h>
#include <ansi.h>
void show_result(object ob, string who, int p_skill,int p_id,int e_id);

string e_name, p_name;

void main(object ob, string who)
{
        int p_id, e_id, p_skill;
	int x,y,x2,y2;
	object env;
	string where;
	
	env = environment( ob );
	p_id=TROOP_D->get_char_troop(this_body()->query_primary_id());
	e_id=TROOP_D->get_char_troop(who);
	e_name=CHAR_D->get_char(who,"name");
	p_name=CHAR_D->get_char(ob->query_primary_id(),"name");
	where = TROOP_D->get_troop_area(p_id);
	if(!(p_skill=CHAR_D->get_char(ob->query_primary_id(),"skills")["jiedu"]))
        {       write("�㲻��ⶾ֮�ơ�\n");
                return;}
	if( !p_id){
                write("ֻ�����ھ��в��ܽⶾ��\n");
                return;
        }	
	if ( !e_id || TROOP_D->get_troop_area(e_id)!=where)
		{ write("�Է����ڴ�ս���ϡ�\n");
			return;
		}
	if (!TROOP_D->get_troops(e_id,"conds"))
		{write("�Է�δ�ж���\n");
			return;
		}
	else if(!TROOP_D->get_troops(e_id,"conds")["poison"])
		 {write("�Է�δ�ж���\n");
                        return;
                }
	if (TROOP_D->get_troop_side(e_id) !=TROOP_D->get_troop_side(p_id))
                {write ("������з�����ʩ�ô˼ơ�\n");
                        return;
                }
	x =TROOP_D->get_troop_position(p_id)[0];
	y = TROOP_D->get_troop_position(p_id)[1];

	x2 = TROOP_D->get_troop_position(e_id)[0];
                y2 = TROOP_D->get_troop_position(e_id)[1];

                if( (x-x2)*(x-x2)+(y-y2)*(y-y2) > 9 ){
			write("����Է�̫Զ�޷�ʩ�ơ�\n");
			return;}
                tell(deep_inventory(TROOP_D->find_troop(e_id)),
	"ʿ�������׶���ԭ����"+p_name+"����Ĳ���ʹ�ýⶾ֮�ơ�\n",
                        MSG_INDENT);
	ob->simple_action(SG_SKILL_D->query_use("jiedu"));
	ob->start_busy(10, "����æ�ڽⶾ�ء�");
	load_object("/daemons/cast_d.c")->reg_player(ob->query_primary_id(), "jiedu");	
        ob->award_exp(ob->query_sk_level("sk_zhimou")/2+random(20) ,"jiedu");
	call_out("show_result", 5+random(5), ob, who, p_skill, p_id, e_id);
}
void show_result(object ob, string who,int p_skill,int p_id,int e_id)
{	
	int kill,kill1,mora,mora1;
        int e_skill;
        int rate, damage, p_num, e_num;

        e_skill=TROOP_D->get_troops(e_id,"conds")["poison"]["duration"];
	e_skill= e_skill/6;
	p_skill = p_skill * 3;
        kill =random(p_skill);
        kill1 =random(e_skill);
        kill = kill*2 - kill1 *1.8;
        ob->stop_busy();	
	if(kill>25)
	{	tell(deep_inventory(TROOP_D->find_troop(e_id)),
                "ʿ�������׶���������ȫ��ȥ��\n",
                        MSG_INDENT);
		mora = random (10) +10;
		mora1 = random (6) +2;
		tell(deep_inventory(TROOP_D->find_troop(p_id)),
                "�Ʋ���ȫ�ɹ���������ȫ��ȥ��\n",
                        MSG_INDENT);
		ob->simple_action(SG_SKILL_D->query_succ("jiedu"));
		map_delete(TROOP_D->get_troops(e_id, "conds"),"poison");	
WARAI_D->war_inf(TROOP_D->get_troops(p_id,"task_id"),
TROOP_D->find_troop(p_id)->query_id()[1]+"ʹ�ýⶾ֮�ƣ���"+
TROOP_D->find_troop(e_id)->query_id()[1]+"����ж�״̬��","b");
	} 
	else
	{	tell(deep_inventory(TROOP_D->find_troop(e_id)),     
        	"�ⶾʧ�ܡ�\n",
                        MSG_INDENT);
		tell(deep_inventory(TROOP_D->find_troop(p_id)),
		"�ⶾʧ�ܡ�\n",
                        MSG_INDENT);
		mora = random(-8) - 3;
		mora1 = random(-8) - 3;
		ob->simple_action(SG_SKILL_D->query_fail("jiedu"));
		tell(deep_inventory(TROOP_D->find_troop(p_id)),
                "�Ʋ�ʧ�ܣ��Ҿ�������ʧ��\n",
                        MSG_INDENT);
	  	damage= 10 + random (50);
        	WARAI_D->kill_troop(p_id,damage);
		WARAI_D->war_inf(TROOP_D->get_troops(p_id,"task_id"),
TROOP_D->find_troop(p_id)->query_id()[1]+"ʹ�ýⶾ֮��ʧ�ܣ������˳˻���
��"+chinese_number(damage)+"�ˡ�","b");
		WARAI_D->clear_empty_troop(({p_id}));
		
		}
	
	TROOP_D->add_morale(p_id,mora1);
	TROOP_D->add_morale(e_id,mora);
	return;
}
