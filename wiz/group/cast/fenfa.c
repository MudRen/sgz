// �ܷ�
#include <mudlib.h>
#include <daemons.h>
#include <ansi.h>

int p_id,p_skill;
string p_name;

void main(object ob)
{
	int i, x, y, x2, y2, id, kill, kills,*troops,xtmp,ytmp,cn;
	string where, s_type;
	mapping solider,enemy;
	object env;

	env = environment(ob);
	p_id = TROOP_D->get_char_troop(this_body()->query_primary_id());
	p_name=this_body()->query_id()[0];
        if(!(CHAR_D->get_char(p_name,"skills")))
        {       write("�㲻��ܷ�֮�ơ�\n");
                return;
	}
	if(!p_skill=CHAR_D->get_char(p_name,"skills")["fenfa"])
        {       write("�㲻��ܷ�֮�ơ�\n");
                return;
        }
	if( !p_id){
		write("ֻ�����ھ��в���ʹ�÷ܷ���\n");
		return;
	};
	solider = TROOP_D->get_troops(p_id, "soldier");
	s_type= keys(solider)[random(sizeof(keys(solider)))];	
	if( solider[s_type]["energy"] < 20 ){
		write("ʿ���ж������㣬����ʹ�÷ܷ���\n");
		return;
	};


	troops = TROOP_D->list_troops();
	troops = troops - ({ p_id });
	if( !sizeof(troops) )return;
	where = TROOP_D->get_troop_area(p_id);
	if(sizeof(troops) < 2)
	{	write("��û�б���Χ�ɡ�\n");
		return;
	}
	cn =0;
	xtmp = -1;
	ytmp= -1;
	x = TROOP_D->get_troop_position(p_id)[0];
        y = TROOP_D->get_troop_position(p_id)[1];
	for( i = 0; i < sizeof(troops); i++ ){
                id = troops[i];
                x2 = TROOP_D->get_troop_position(id)[0];
                y2 = TROOP_D->get_troop_position(id)[1];

                if( TROOP_D->get_troop_area(id) != where )continue;
                if( (x-x2)*(x-x2)+(y-y2)*(y-y2) > 1 ||
TROOP_D->get_troop_side(id)==TROOP_D->get_troop_side(p_id))continue;
//		tell_user("group",id+"\n");
		if(xtmp== -1 || ytmp == -1)	
		{ xtmp = x2;
		 ytmp = y2;
		cn =1;
		}
		else {if (xtmp != x2 || ytmp!= y2)
		cn++;
		}
		}
//	tell_user("group","cn is "+chinese_number(cn));	
	if(cn<2)	
	 {       write("��û�б���Χ�ɡ�\n");
                return;
        }		
	
	solider[s_type]["energy"] = 0;
        TROOP_D->set_troops(p_id, "solider", solider);
        ob->simple_action(SG_SKILL_D->query_use("fenfa"));
		
	x = TROOP_D->get_troop_position(p_id)[0];
	y = TROOP_D->get_troop_position(p_id)[1];
	load_object("/daemons/cast_d.c")->reg_player(p_name, "fenfa");
        ob->award_exp(ob->query_sk_level("sk_zhimou")/2+random(20) ,"fenfa");
	
	for( i = 0; i < sizeof(troops); i++ ){
		id = troops[i];
		x2 = TROOP_D->get_troop_position(id)[0];
		y2 = TROOP_D->get_troop_position(id)[1];

		if( TROOP_D->get_troop_area(id) != where )continue;
		if( (x-x2)*(x-x2)+(y-y2)*(y-y2) > 1 || TROOP_D->get_troop_side(id) ==TROOP_D->get_troop_side(p_id))continue;
		tell(deep_inventory(TROOP_D->find_troop(id)),
			"����Χ�ĵ�����������˹�����\n",
			MSG_INDENT);		
		tell(deep_inventory(TROOP_D->find_troop(p_id)),
                        "���µ�ʿ������һ֧�о��У�\n",
                        MSG_INDENT);
		kill = p_skill*p_skill*p_skill*100/(1400*50);
		if(kill<200)
		kill = random(50) + 150;
		kills = 200*2500/(p_skill*p_skill);
		enemy = TROOP_D->get_troops(id, "soldier");
		s_type= keys(enemy)[random(sizeof(keys(enemy)))];
		WARAI_D->kill_troop(id,kill);
		WARAI_D->kill_troop(p_id,kills);
		WARAI_D->clear_empty_troop(({id}));
	};
	WARAI_D->war_inf(TROOP_D->get_troops(p_id,"task_id"),
TROOP_D->find_troop(p_id)->query_id()[1]+"ʹ�÷ܷ�֮�ƣ�ɱ��"+
chinese_number(kill)+"�ˡ�","b");
	return;
}
