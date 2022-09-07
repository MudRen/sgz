// ���
#include <mudlib.h>
#include <daemons.h>
#include <ansi.h>
#define WARINFO "/sgdomain/cmd/warinfo.c"

int p_id,p_skill;
string p_name;
string get_conds(int t);

void main(object ob)
{
	int i, x, y, x2, y2, id, *troops;
	int size;
	string disp;
	string where;
	object env;
	object o;
   string p_name,b_id;
   string tmp;
   string c_id,c_name;
   int b_num;

	env = environment(ob);
	p_id = TROOP_D->get_char_troop(this_body()->query_primary_id());
	p_name=this_body()->query_id()[0];
        if(!(CHAR_D->get_char(p_name,"skills")))
        {       write("�㲻�����֮�ơ�\n");
                return;
	}
	if(!p_skill=CHAR_D->get_char(p_name,"skills")["scout"])
        {       write("�㲻�����֮�ơ�\n");
                return;
        }
	if( !p_id){
		write("ֻ�����ھ��в���ʹ����졣\n");
		return;
	};

	ob->simple_action(SG_SKILL_D->query_use("scout"));
	size = p_skill/10;
	
	troops = TROOP_D->list_troops();
	troops = troops - ({ p_id });
	if( !sizeof(troops) )
	return;
	disp=
"�������㲿�ӷ�Բ"+chinese_number(size)+"֮�ڵĲ��������\n";
disp+=
"���ӡ�������������     �������� ������������ ����    λ�á�״̬\n";
disp+=
"����������������������������������������������������������������������\n"
;
	where = TROOP_D->get_troop_area(p_id);
	
	x = TROOP_D->get_troop_position(p_id)[0];
	y = TROOP_D->get_troop_position(p_id)[1];

	for( i = 0; i < sizeof(troops); i++ ){
		id = troops[i];
		x2 = TROOP_D->get_troop_position(id)[0];
		y2 = TROOP_D->get_troop_position(id)[1];

		if( TROOP_D->get_troop_area(id) != where )continue;
		if( (x-x2)*(x-x2)+(y-y2)*(y-y2) > (size * size) )continue;
		o = TROOP_D->find_troop(id);
		p_name = TROOP_D->get_troops(id,"name");
		b_id=o->query_id()[0];
   c_id=TROOP_D->get_troops(id,"chars")[0];
   c_name=CHAR_D->get_char(c_id,"name");
   b_num=TROOP_D->get_troops(id,"total_num");
   tmp=sprintf("%-18s%-9s%-8s %-8d%-7d%-9s%-6s%s\n"
    ,p_name,b_id,c_name,
    sizeof(TROOP_D->get_troops(id,"chars")),
    b_num,WARINFO->get_btype(id),WARINFO->get_pos(id),
    get_conds(id));
    disp+=tmp;
	};
	more(disp);
	return;
}

string get_conds(int t)
{
	mapping conds;
	string* cond;
	string conditions;
	int i;
	conditions = "";
	conds = TROOP_D->get_troops(t, "conds");
	if (!sizeof(conds))return "����";
	cond = keys(conds);
	for (i=0; i< sizeof(cond);i++)
	{
	if (cond[i]=="hide")
	conditions +=" ���� ";
	if (cond[i]=="poison")
	conditions +=" �ж� ";
	if (cond[i]=="confuse")
	conditions +=" ���� ";	
	}
	return conditions;
}	
