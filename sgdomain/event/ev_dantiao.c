//����

#include <mudlib.h>
#include <daemons.h>

string* p_input;
string* e_input;
object fighter1,fighter2;
string p_name,e_name,p_id,e_id;
int p_power,e_power;
int p_defen,e_defen;
int counter=0;

void input_way(string arg);
void input_way2(string arg);
int p_it,e_it;
int p_hp,e_hp;
void wait_result(int h);
int show_result(int p_ids,int e_ids,int k);

void main(string p_id,string e_id)
{	
	int i;

	p_name = CHAR_D->get_char(p_id,"name");
	e_name = CHAR_D->get_char(e_id,"name");
	p_it = TROOP_D->get_char_troop(p_id);
	e_it = TROOP_D->get_char_troop(e_id);
	fighter1 = find_user(p_id);
        fighter2 = find_user(e_id);
p_power=FIGHT_D->get_pure_att_pow(fighter1->query_body())+FIGHT_D->get_add_att_pow(fighter1->query_body());
e_power=FIGHT_D->get_pure_att_pow(fighter2->query_body())+FIGHT_D->get_add_att_pow(fighter2->query_body());
p_defen=FIGHT_D->get_pure_def_pow(fighter1->query_body())+FIGHT_D->get_add_def_pow(fighter1->query_body());	
e_defen=FIGHT_D->get_pure_def_pow(fighter2->query_body())+FIGHT_D->get_add_def_pow(fighter2->query_body());	

	WARAI_D->war_inf(TROOP_D->get_troops(p_it,"task_id"),
p_name+"��"+e_name+"��ʼ������","b");
	i = 1;
	p_hp=fighter1->query_body()->query_cur_hp();
	e_hp=fighter2->query_body()->query_cur_hp();	
		call_out ("wait_result",5,i);
		
return;
}


 		
void input_way(string arg)
{
	int num,i;

	if (!arg) {write("����ѡ������������ж������");
	return;}
	p_input = explode(arg,",");
	num = sizeof(p_input);
	if (num != 5)
	{write(
"����ѡ������������ж������(��ѡ��au,am,ad,du,dm,dd��
������au,dd,ad,ad,dd)��");
	return;}
	for (i=0;i<5;i++)
	{ 
		if (p_input[i]!="au" && p_input[i]!="am" 
		&& p_input[i]!="ad" && p_input[i]!="du" &&p_input[i]!="dm"
		&& p_input[i]!="dd")

       {	write( 
"����ѡ������������ж������(��ѡ��au,am,ad,du,dm,dd��
������au,dd,ad,ad,dd)��");
	return; 
	}
	}
        counter++;
	fighter1->modal_pop();
}

void input_way2(string arg)
{
        int num,i;
	
        if (!arg) {write("����ѡ������������ж������");
        return;}
	e_input = explode(arg,",");
        num = sizeof(e_input);
        if (num != 5)
        {write(
"����ѡ������������ж������(��ѡ��au,am,ad,du,dm,dd��
������au,dd,ad,ad,dd)��");
	return;
	}
        for (i=0;i<5;i++)
        {
                if (e_input[i]!="au" && e_input[i]!="am"
                && e_input[i]!="ad" && e_input[i]!="du" &&e_input[i]!="dm"
		&& e_input[i]!="dd")
	
        {write(
"����ѡ������������ж������(��ѡ��au,am,ad,du,dm,dd��
������au,dd,ad,ad,dd)��");
	return;
        }}
	counter =4;
        fighter2->modal_pop();
}

int show_result(int p_ids, int e_ids,int k)
{
	string i1,i2;
	int c1,c2;
	int j;
	int damage,hp;

	WARAI_D->war_inf(TROOP_D->get_troops(p_it,"task_id"),
p_name+"��"+e_name+"������"+chinese_number(k)+"�غϿ�ʼ��","b");
for( j=0;j<5;j++)
{	
	i1 = p_input[j];		
	if (i1 == "au") c1 = 1;
	if (i1 == "am") c1 = 2;
	if (i1 == "ad") c1 = 3;
	if (i1 == "du") c1 = 8;
	if (i1 == "dm") c1 = 7;
	if (i1 == "dd") c1 = 6;
	i2 = e_input[j];
	if (i2 == "au") c2 = 1;
        if (i2 == "am") c2 = 2;
        if (i2 == "ad") c2 = 3;
        if (i2 == "du") c2 = 8;
        if (i2 == "dm") c2 = 7;
        if (i2 == "dd") c2 = 6;

tell_user("group",sprintf("%d%d%s%s",c1,c2,p_input[j],e_input[j]));
	if ((c1+c2) == 9)
	{
	  if (c1<c2)
	WARAI_D->war_inf(TROOP_D->get_troops(p_ids,"task_id"),
p_name+"����"+e_name+"һ�е��Ǳ���ס�ˡ�","b");			
	if (c1>c2)
	WARAI_D->war_inf(TROOP_D->get_troops(p_ids,"task_id"),
e_name+"����"+p_name+"һ�е��Ǳ���ס�ˡ�","b");	
	}
	
	else {
	if ((c1+c2)>=12)
	WARAI_D->war_inf(TROOP_D->get_troops(p_ids,"task_id"),
p_name+"��"+e_name+"����һ�У��������ˡ�","b");
	
	if ((c1+c2)>6 && (c1+c2)<12)
	{
	if (c1<c2 )
	{	WARAI_D->war_inf(TROOP_D->get_troops(p_ids,"task_id"),
p_name+"����"+e_name+"һ�У�"+e_name+"��ʱȴ���˸��ա�","b");
		
	    damage = p_power - e_defen;
	    if (damage <=0) damage = 1+random(2);
		e_hp= e_hp - damage;
		if (e_hp<0) e_hp =0;
		fighter2->query_body()->set_cur_hp(hp);
		
		WARAI_D->war_inf(TROOP_D->get_troops(p_ids,"task_id"),
e_name+"��Ѫ"+chinese_number(damage)+"�㡣","b");
			
		if (e_hp == 0)
		{WARAI_D->war_inf(TROOP_D->get_troops(p_ids,"task_id"),
p_name+"��������"+e_name+"��","b");
		fighter1->query_body()->set_cur_hp(p_hp);
                fighter2->query_body()->set_cur_hp(e_hp);
			return 1;
		}
		}
	else 
        {       WARAI_D->war_inf(TROOP_D->get_troops(p_ids,"task_id"),
e_name+"����"+p_name+"һ�У�"+p_name+"��ʱȴ���˸��ա�","b");

            damage = e_power - p_defen;
            if (damage <=0) damage = 1+random(2);
                p_hp = p_hp - damage;
                if (p_hp<0) p_hp =0;

                WARAI_D->war_inf(TROOP_D->get_troops(p_ids,"task_id"),
p_name+"��Ѫ"+chinese_number(damage)+"�㡣","b");

                if (p_hp == 0)
                {WARAI_D->war_inf(TROOP_D->get_troops(p_ids,"task_id"),
e_name+"��������"+p_name+"��","b");
                fighter1->query_body()->set_cur_hp(p_hp);
		fighter2->query_body()->set_cur_hp(e_hp);	        
		return 1;
                }
	
	}	
	}
	if ((c1+c2) <= 6)
	{ 
	WARAI_D->war_inf(TROOP_D->get_troops(p_ids,"task_id"),
p_name+"��"+e_name+"�㹥һ�У��������ˡ�","b");
	damage = p_power;
            if (damage <=0) damage = 1+random(2);
		e_hp = e_hp - damage;
                if (e_hp<0) e_hp =0;

                WARAI_D->war_inf(TROOP_D->get_troops(p_ids,"task_id"),
e_name+"��Ѫ"+chinese_number(damage)+"�㡣","b");	

	damage = e_power;
            if (damage <=0) damage = 1+random(2);
		p_hp = p_hp - damage; 
               if (p_hp<0) p_hp =0;

                WARAI_D->war_inf(TROOP_D->get_troops(p_ids,"task_id"),
p_name+"��Ѫ"+chinese_number(damage)+"�㡣","b");
 
	    if (p_hp== 0 && e_hp== 0)
	{	WARAI_D->war_inf(TROOP_D->get_troops(p_ids,"task_id"),
p_name+"��"+e_name+"���ܾ��ˣ�ɱ��ƽ�֡�","b");
		fighter1->query_body()->set_cur_hp(p_hp);
                fighter2->query_body()->set_cur_hp(e_hp);
		return 1;
	}	
	else 
	{
		if (p_hp == 0)
                {WARAI_D->war_inf(TROOP_D->get_troops(p_ids,"task_id"),
e_name+"��������"+p_name+"��","b");
                fighter1->query_body()->set_cur_hp(p_hp);
                fighter2->query_body()->set_cur_hp(e_hp);        
		return 1;
                }	
		if (e_hp == 0)
                {WARAI_D->war_inf(TROOP_D->get_troops(p_ids,"task_id"),
p_name+"��������"+e_name+"��","b");
		fighter1->query_body()->set_cur_hp(p_hp);
                fighter2->query_body()->set_cur_hp(e_hp);
                        return 1;
                }
	}
	}

}
}
return 0;
}

void wait_result(int h)
{
	remove_call_out("wait_result");
	if (counter == 0)
        {counter ++;
	set_this_player(fighter1);
	fighter1->modal_push((:
	input_way:),"��������ĵ�"+chinese_number(h)+"�غ�ѡ��");
	}
	if (counter == 2)
	{	counter++;
		set_this_player(fighter2);	
           fighter2->modal_push((:
        input_way2:),"��������ĵ�"+chinese_number(h)+"�غ�ѡ��");
	}
	if ( counter==4)
	{if (show_result(p_it,e_it,h))
		return;
		h++;
		counter =0;
	if (h==6)
	{	WARAI_D->war_inf(TROOP_D->get_troops(p_it,"task_id"),
p_name+"��"+e_name+"�ѷ��ѽ⣬ɱ��ƽ�֡�","b");
		return;
	}
	}
	call_out("wait_result",3,h);	
	
}
