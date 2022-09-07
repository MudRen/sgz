#include <mudlib.h>

inherit M_CHAR;
inherit LIVING;

string *first = ({ "��","Ǯ","��","��","��","��","֣","��","��","��",
	"��","��" });
string *words = ({ "˳","��","��","��","��","��","��","��","־","��",
    	"Т","��","��","��","��","��","��","ʢ","ʤ","��","��","��","ͬ","��",
    	"��","��","��","¡","��","��","��","��","��" });

string *rnd_id = ({"ra","ma","ta","pu","gu","du","so","po","lo","phi","tri"});
string *rnd_id_tail = ({"ng","gh","ss","h","le","d","ck","m","tte"});

mapping msg = (["����":({"$N��������˯���ˡ�\n",
			"$N���������Ŀ�������\n",
			"$Nһ�������Ŀ�������\n",
			"$NŬ���Ŀ���������һ��ĺ���\n",
			"$Nƴ�����ƵĿ����������৵ĵ��ڵ��ϡ�\n"}),
		"����":({"$N���ڵ�˯���ˡ�\n",
			"$N�������������ŵء�\n",
			"$Nһ�����������ŵء��\n",
			"$NŬ�������أ�����һ��ĺ���\n",
			"$Nƴ�����Ƶ����ء�\n",}),
		"���":({"$N���ڵ�˯���ˡ�\n",
                        "$N���������Ĺ���š�\n",
                        "$Nһ�������Ĺ���š�\n",
                        "$NŬ���Ĺ�ȣ�����һ��ĺ���\n",
                        "$Nƴ�����ƵĹ�ȡ�\n",}),
	]);
mapping work = (["����":"str", "����":"exp", "���":"int", ]);

void setup()
{
	string name, id;
	
	name = first[random(sizeof(first))];
    	name += words[random(sizeof(words))];
    	if( random(10) > 2 ) name += words[random(sizeof(words))];

    	id = rnd_id[random(sizeof(rnd_id))];
    	if( random(10) > 4 ) id += rnd_id[random(sizeof(rnd_id))];
    	id += rnd_id_tail[random(sizeof(rnd_id_tail))];

	set_name(id, name);
	add_id("worker");
	set_in_room_desc(name+"("+id+")");
	set_long(name+"("+id+")");
	set_gender(1);
	set_age(20+random(20));

	set("str", random(5)+5);
	set("int", random(5)+5);
	set("exp", random(5)+5);
	set("eff", random(5)+5);
	set("wrk", 0 );
	set("job", "none");

	call_out("do_work", 10);
}
void do_work()
{
	int eff;

	eff = query("eff") - 5;
	eff = random(2) + eff;
	if( eff < 0 )eff = 0;
	if( eff > 4 )eff = 4;

	if( !this_object()->query("job") || this_object()->query("job") == "none" ){
		this_object()->simple_action("$N�������µķ�����\n");
	} else {
		this_object()->simple_action(msg[query("job")][eff]);
		set("wrk", query("wrk")+query("eff")*query(work[query("job")]));
	};
	call_out("do_work", 10 + random(5) );
	return;
}
