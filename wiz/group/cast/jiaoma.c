// ����
#include <mudlib.h>
#include <daemons.h>
#include <ansi.h>
void show_result(object ob, string who);
int p_id, p_skill;
int e_id;
string e_name, p_name;
void main(object ob, string who)
{
	int x,y,x2,y2;
	object env;
	string where;
	
	env = environment( ob );
	p_id=TROOP_D->get_char_troop(this_body()->query_primary_id());
	e_id=TROOP_D->get_char_troop(who);
	e_name=CHAR_D->get_char(who,"name");
	p_name=CHAR_D->get_char(ob->query_primary_id(),"name");
	where = TROOP_D->get_troop_area(p_id);
	if(!(CHAR_D->get_char(ob->query_primary_id(),"skills")))
        {       write("�㲻�����֮�ơ�\n");
                return;
	}
	if(!p_skill=CHAR_D->get_char(ob->query_primary_id(),"skills")["jiaoma"])
        {       write("�㲻�����֮�ơ�\n");
                return;
	}
	if( !p_id){
                write("ֻ�����ھ��в��ܽ���з�ʿ����\n");
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

                if( (x-x2)*(x-x2)+(y-y2)*(y-y2) > 9 ){
			write("�������̫Զ�޷�ʩ�ơ�\n");
			return;}
                tell(deep_inventory(TROOP_D->find_troop(e_id)),
	"ʿ��һ��������ԭ����"+p_name+"����Ĳ���ʹ��ǣ��֮�ơ�\n",
                        MSG_INDENT);
                // In future, we have to consider effects of the
                // ablility of general, zhenxing, dixing, etc.
                // Now the damage depends only on the No of bowman
	ob->simple_action(SG_SKILL_D->query_use("jiaoma"));
	ob->start_busy(10, "����æ��ǣ�Ƶз�ʿ���ء�");
	
	call_out("show_result", 5+random(5), ob, who);
}
void show_result(object ob, string who)
{	
	int mora, mora1=0;
        int kill;
        int damage;

        kill = p_skill*2/3;
        kill = random(kill);
        ob->stop_busy();
        if( kill>50)
        {
                ob->simple_action(SG_SKILL_D->query_succ("jiaoma"));
                mora = random (-20) -10;
        }
        else
        {     if(kill>15)
                {
                ob->simple_action(SG_SKILL_D->query_succ("jiaoma"));
                mora = random (-10) - 5;
                }
              else
	{	mora = random(8) + 3;
		mora1 = random(-8) - 3;
		ob->simple_action(SG_SKILL_D->query_fail("jiaoma"));
		}
	}
	
	TROOP_D->add_morale(p_id,mora1);
	TROOP_D->add_morale(e_id,mora);
	mora = 0 - mora;
	 WARAI_D->war_inf(TROOP_D->get_troops(p_id,"task_id"),
TROOP_D->find_troop(p_id)->query_id()[1]+"ʹ�ý���֮��ʹ"+
TROOP_D->find_troop(e_id,)->query_id()[1]+"����ʿ��"+chinese_number(mora)+
"�㡣","b");
	return;
}
