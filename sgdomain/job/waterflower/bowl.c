#include <mudlib.h>
#define HUA "/sgdomain/job/waterflower/hua.c"
#define JOBID "waterflower"
#define S_ROOM "/a/luoyang/ly_dhl.c"
inherit OBJ;
inherit M_GETTABLE;

private int bowl_status;
private int seed_in;

void status();
int query_clean_up();

void setup()
{
	set_id("bowl", "����");
	set_in_room_desc("һ������(bowl)");	
	bowl_status = 0;
      set_gettable(0);
	status();
	return;
}
string long()
{
	if( bowl_status < 3 )
		return "һ��ոշ����˻��ѵĻ��裬������������ˮ��";
else if (bowl_status <7)
		return "һ�����裬���̵Ļ����ڷ��в�����";
else if (bowl_status< 14)
		return "һ�����裬��׳�Ļ�������̫����չ��˫�ۡ�";
	else return "�����Ļ����ߴ��Ŀ���֦ͷ����Ҫ�����ˣ�";
}

void status()
{
	remove_call_out("status");
	if( bowl_status <= 0 ) return;
	bowl_status = bowl_status - random(2) - 1;
	if (bowl_status < 5)
	tell_environment( this_object(), "��������ȱˮ��������ͷ��\n");
	call_out("status", 30 );
	return;
}

int set_status()
{	object player, hua, jiang, room;
	int skill, exp;
 	
	player = this_body();
bowl_status = bowl_status  + 1 - random(1) + random(1);
if (bowl_status >= 20)
{
tell_user(this_body()->query_id()[0],
"�����ˣ����ȥ���ϵĺ�ˮ������ι����������ˣ�\n");
	skill = player->query_sk_level("sk_meili");
        exp = player->query_sk_exp("sk_meili");
        if( skill < 51 )
	player->set_sg_skill("sk_meili", skill, exp + random(10) + 40 );
	hua = new(HUA);        
        hua->move(environment(player));
	player->finish_job(JOBID);
	room=load_object(S_ROOM);
        jiang=present("hua jiang", room );
	jiang->employ();
	destruct(this_object());		
	}
}
mixed direct_turn_obj()
{
	return 1;
}

int turn()
{
	int i, hp;
	object player, hua,bottle;
	object *obs;
	object room,jiang;
	string name;

	room=load_object(S_ROOM);
        jiang=present("hua jiang", room );
        name = jiang->call_name();
	
	player = this_body();
	
	hp = player->query_cur_hp();
        if(this_body()->query_primary_id()!=name)
        {
        all_inventory(this_body());
        bottle=present("bottle",this_body());
        this_body()->simple_action(
        "$N����ˮ���뽽��������æ���ҵģ�ˮ����һ�أ�ˮ��Ҳˤ���ˡ�\n");
	destruct(bottle);
        return 1;
	}
if (hp <25) {
                printf("���Ѿ�̫���ˣ���������Ϣһ���ٸɰɡ�\n");
                return 1;
        }; 
player->set_cur_hp( hp - 8 -random (7) );
	obs = all_inventory( player );
	for( i = 0; i < sizeof( obs ); i++){
		if( obs[i]->can_turn()&& obs[i]->set_water(0) ){
			obs[i]->set_water(1);
			player->simple_action("$N����ˮ������ˮ����\n");
			set_status();
			return 1;	
		};
	};
	printf("��Ҫ��ʲô����ˮ�أ�\n");
	return 1;
}			
int query_clean_up() {
        return 1;
}
