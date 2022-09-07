// Ma fu for transport
// By flee@sgz, created at 23 NOV 1998
// Modified by flee on 26 NOV, take distance into consideration
#include <mudlib.h>

#define MACHE __DIR__"mache.c"
#define VOID "/obj/void.c"
#define __TIME__ 15
#define K 0.3
#define __COST__ 100

inherit LIVING;

void setup()
{
//	object jia;
//	object jia1;
	int i;
	string *dest;

	set_name("ma fu", "���");
	set_in_room_desc("һλ����������(ma fu)");
	set_long("���̧ͷ������һ�ۣ�Ҫ���Ķ�ȥ�����Һ��ˡ�\nask ma fu about destination\n");
	set_gender(1);
	set_age(25);
	set_sg_rongmao(15);
//	jia=new("/sgdomain/obj/cloth/torso/buyi.c");
//	jia->move(this_object());
//	jia->do_wear();
//	jia1=new("sgdomain/area/cities/luoyang/obj/maxie.c");
//	jia1->move(this_object());
//	jia1->do_wear();
	
	dest = AREA_D->list_areas();
	for( i = 0; i < sizeof(dest); i++){
		add_question(dest[i], "dest");
		add_ask_str(dest[i], "$N��$T���������������ҵ�" + 
			AREA_D->get_area(dest[i], "name") + "��\n");
	};		
	add_question("destination", "destination");
	add_ask_str("destination", "$N��$T���������������ҵ��Ķ�����\n");
}
string long() {
	return "һ�����ƿ��������\n";
}
mixed special_answer(object ob, string dest)
{
	int i, count, tmp;
	int time, cost;
	string out;
	string *dests;
	string *path;
	string from;
	object env, mache;

	dests = AREA_D->list_areas();
        env = environment( ob );
        while( env && !inherits(BASE_ROOM, env) )env = environment( env );
        from = base_name( env );
        from = replace_string( from, "/", " ");
        path = explode( from, " ");
        from = path[sizeof(path)-2];
	if( dest == "destination" ){
		this_object()->responda("ah");
		this_object()->simple_action("$N����������ȥ��Щ�ط���\n");		
		count = 0;
		tmp = 1;
		out = "\n";
		for( i = 0; i < sizeof(dests); i++){
			if( dests[i] == from )continue;
			out = out + sprintf("%-2d)%-6s - %-10s - %-14s", tmp,
				AREA_D->get_area(dests[i], "name"), dests[i],
				chinese_number(AREA_D->get_distance(from,dests[i])) + "������");
			count++;
			tmp++;
			if( count == 2 ){
				count = 0;
				out = out + "\n";
			};
		};
		printf("%s\n\n", out);
	} else {
		if( from == dest ){
			printf("����ɻ����%s�������ھ���%sѽ��\n",
				ob->query_name(), AREA_D->get_area(from,"name"));
			return;
		};
		cost = AREA_D->get_distance( from, dest ) * __COST__;
		time = AREA_D->get_distance( from, dest ) * __TIME__ * K +5;
		if( ob->query_all_con_money() < cost ){
			this_object()->simple_action("$N����һ������⵰��һ��ȥ��\n");
			return;
		};
		ob->set_all_con_money( ob->query_all_con_money() - cost );
		mache = new( MACHE );
		printf("�㸶������%s�����ӡ�\n", chinese_number(cost/100));
		this_object()->simple_action("$N���˻��֣�һ���󳵻����Ŀ��˹�����");
		ob->simple_action("$Nһ��������˳��");
		ob->move( mache );
		this_object()->simple_action("$N��������һ��Ƥ�ޣ����������뿪�ˡ�");
		mache->move( VOID );
		mache->destruct_itself(ob, time, dest);	
	};
	return;
}
		
