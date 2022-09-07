#include <mudlib.h>
#include <ansi.h>
#include <armor.h>
#include <command.h>
#define NULL_VALUE 0
inherit CLOTH;
inherit F_SAVE;
inherit F_AUTOLOAD;
inherit F_DAMAGE;
// inherit F_CLEAN_UP;

mapping default_dirs = ([
	"north":		"��",
	"south":		"��",
	"east":			"��",
	"west":			"��",
	"northup":		"����",
	"southup":		"�ϱ�",
	"eastup":		"����",
	"westup":		"����",
	"northdown":	"����",
	"southdown":	"�ϱ�",
	"eastdown":		"����",
	"westdown":		"����",
	"northeast":	"����",
	"northwest":	"����",
	"southeast":	"����",
	"southwest":	"����",
	"up":			"��",
	"down":			"��",
	"enter":		"��",
	"out":			"��",
]);


string inputstr,verb;

void create()
{
	seteuid(getuid());
	set("long",@LONG
                    �ɻ���Ҷ��
                (bug fixed verison)
������������������������������������������������������
�� ������ ��      �� ��       �� Note & description ��
������������������������������������������������������
��fill    ��fill <id>         �������ָ�ĳ�˵ľ���  ��
��nofill  ��nofill <id>       ������ĳ�˵ľ���      ��
��yao     ��yao<genre><value> ��ֻҪ������һ��Ǯ�Ϳɡ�
��        ��                  ���Ա�����Ҫ��������Ǯ��
������������������������������������������������������
��whereis ��whereis or<id>    ���г����������˵�λ�á�
��pk      ��pk<ob> with <id>  ����ĳ��ɱĳ��        ��
��chuqiao ��chuqiao <id>      ���Ž�ɱĳ��          ��
��xing    ��xing <id>         ����ĳ������          ��
��yun     ��yun  <id>         ����ĳ���ε�          ��
��qshs    ��qshs <id>         ����������(�ָ�ԭ�书)��
��feng    ��feng <id>         ���ⶳĳ��            ��
��jiefeng ��jiefeng <id>      �����ĳ��            ��
��gan     ��gan <id>          ����ĳ�����ߣ�        ��
��superdie��superdie          ������������������������
��quanjia ��quanjia <id>      ����ĳ�˲��ٴ�ܣ�    ��
��jizhu   ��jizhu<id>with<id> ��pk id with id       ��
��ban     ��ban <id> <msg>    ��װ��ĳ��˵������    ��
��move    ��move <id> <dir>   ���ƶ�ĳ��            ��
������������������������������������������������������
LONG
	);
	set("unit","��");
	set("no_get",1);
	set("material", "cloth");
	set("armor_prop/armor", 30000);
	set("light",1);
	set_weight(-10000000);
	setup();
}

void init()
{
	seteuid(geteuid());
	set_name(HIY "�ɻ���Ҷ��" NOR, ({ "jia", "ander" }));
	add_action("do_change","change");
	add_action("full","fill");
	add_action("hun","nofill");
	add_action("wave","yao");
	add_action("whereis", "whereis");
	add_action("pk_mob", "pk");
	add_action("do_wakeup", "xing");
	add_action("do_hun","hun");
	add_action("do_die","chuqiao");
	add_action("do_reincarnate","qshs");
	add_action("do_disable_player","feng");
	add_action("do_enable_player","jiefeng");
	add_action("super_die","superdie");
	add_action("do_gan","gan");
	add_action("do_halt","quanjia");
	add_action("do_killer","jizhu");
	add_action("do_ban","ban");
	add_action("do_move","move");
	this_player()->set_temp("heat",1);
}

int do_change(string arg)
{
	object fd;
	object me = this_player();
	string gender;
	if(!arg) return notify_fail ("usage: change <id>\n");
	if(!objectp(fd = present(arg, environment(me))))
		return notify_fail("����û������ˡ�\n");
	if(!fd->is_character() || fd->is_corpse())
		return notify_fail("�����һ�㣬�ǲ����ǻ��\n");
	gender = fd->query("gender");
	if (arg) {
		switch(gender)
		{
			case "Ů��":
				fd->set("gender","����");
				break;
			case "����":
				fd->set("gender","Ů��");
				break;
			case "����":
				switch(random(3))
				{
					case 1:
						fd->set("gender","Ů��");
						break;
					case 2:
						fd->set("gender","����");
						break;
					case 3:
						break;
				}
		}
		message("shout", HIC "�����ԡ���" + HIG + "��˵" + me->query("name") + "�ɹ��Ķ�"
		 + fd->query("name") + "������һ�α���������\n" NOR,users());
		fd->save();
		write(HIC"��������ˣ�\n"NOR);
		return 1;
	}
}

int whereis(string arg)
{
	object where, fd;
	object *ob;
	string msg;
	int i;
	if (arg!= NULL_VALUE) {
		fd = LOGIN_D->find_body(arg);
		if (!fd) return notify_fail("��Ҷ˵�����������Ϻ���û�����ѽ����\n");
	}
	if (arg) {
		where = environment(find_player(arg));
		if (!where) return notify_fail ("��������Ʈ��䡣\n");
		msg = where->query ("short")+" - "+file_name(where)+"\n";
		msg += where->query("long");
	} else {

	ob = users();
	msg = "";
	for(i=0; i<sizeof(ob); i++) {
		where = environment(ob[i]);
		if (!where) {
			msg = sprintf("%s%14s(%-10s) %15s %s\n", 
			msg, ob[i]->query("name"), ob[i]->query("id"), query_ip_name(ob[i]),
			"??????????");
		} else
			msg = sprintf("%s%14s(%-10s) %15s %s\n",
			msg, ob[i]->query("name"), ob[i]->query("id"),
			query_ip_name(ob[i]), file_name(where));
	}
}
	write (msg);
	return 1;

}

int full(string arg)
{
	int max;
	object me = this_player();
	object fd;

	if(!arg) return notify_fail ("usage: fill <id>\n");
	if(!objectp(fd = present(arg, environment(me))))
		return notify_fail("����û������ˡ�\n");
	if(!fd->is_character() || fd->is_corpse())
		return notify_fail("�����һ�㣬�ǲ����ǻ��\n");

	max = fd->query("max_gin");
	fd->set("eff_gin",max);
	fd->set("gin",max);
	max = fd->query("max_kee");
	fd->set("eff_kee",max);
	fd->set("kee",max);
	max = fd->query("max_sen");
	fd->set("eff_sen",max);
	fd->set("sen",max);
	max = fd->max_food_capacity();
	fd->set("food",max);
	max = fd->max_water_capacity();
	fd->set("water",max);
	max = fd->query("max_jing");
	fd->set("eff_jing",max);
	fd->set("jing",max);
	max = fd->query("max_qi");
	fd->set("eff_qi",max);
	fd->set("qi",max);
	max = fd->query("max_shen");
	fd->set("eff_shen",max);
	fd->set("shen",max);
	max = fd->max_food_capacity();
	fd->set("food",max);
	max = fd->max_water_capacity();
	fd->set("water",max);
	fd->clear_condition();

	message_vision( sprintf("$N������մ󺰣���Զ������\n"), this_player());
	
	return 1;
}

int hun(string arg)
{
	int min;
	object me = this_player(); 
	object fd;

	if(!arg) return notify_fail ("usage: nofill <id>\n");
	if(!objectp(fd = present(arg, environment(me))))
		return notify_fail("����û������ˡ�\n");
	if(!fd->is_character() || fd->is_corpse())
		return notify_fail("�����һ�㣬�ǲ����ǻ��\n");

	min = fd->query("min_gin");
	fd->set("eff_gin",min);
	fd->set("gin",min);
	min = fd->query("min_kee");
	fd->set("eff_kee",min);
	fd->set("kee",min);
	min = fd->query("min_sen");
	fd->set("eff_sen",min);
	fd->set("sen",min);
	min = fd->min_food_capacity();
	fd->set("food",min);
	min = fd->min_water_capacity();
	fd->set("water",min);
	min = fd->query("min_jing");
	fd->set("eff_jing",min);
	fd->set("jing",min);
	min = fd->query("min_qi");
	fd->set("eff_qi",min);
	fd->set("qi",min);
	min = fd->query("min_shen");
	fd->set("eff_shen",min);
	fd->set("shen",min);
	min = fd->min_food_capacity();
	fd->set("food",min);
	min = fd->min_water_capacity();
	fd->set("water",min);
	message_vision( sprintf("$N��������һ�������˹�ȥ����ʱ������ȫ��û����...\n"),
	this_player());

	return 1;
}

int wave (string arg)
{
	string kind;
	int amount;
	object n_money;

	if( !arg || sscanf(arg, "%d %s", amount, kind)!=2 )
		return notify_fail("usage: yao <����Ǯ> <Ǯ������>\n
		ע�������ȱ���������Ǯ��\n");

	n_money = present(kind + "_money", this_player());
	if( !n_money && file_size("/clone/money/" + kind + ".c") < 0 )
		return notify_fail("��Ҷ˵�������û�У�ҡ��ƨѽ��\n");
	if( amount < 1 )
		return notify_fail("�Ǻǣ�����û�С�\n");

	if( !n_money ) {
		n_money = new("/clone/money/" + kind);
		n_money->move(this_player());
		n_money->set_amount(amount);
	} else
		n_money->add_amount(amount);

	message_vision( sprintf(HIY "$Nʹ�����ͱ��˵Ŀڴ���ͻȻ�Ӵ������ͳ�%s%s%s��\n" NOR,
		chinese_number(amount), n_money->query("base_unit"), n_money->query("name")),
		this_player());
	return 1;
}

int pk_mob(string str)
{
	object ob1,ob2;
	string st1,st2;
	object me = this_player();

	if (!str || str=="") return notify_fail ("����ү˵��������˭ PK ˭��\n");
	if (sscanf( str,"%s with %s",st1,st2)!=2 )
		return notify_fail ("pk <ob1> with <ob2>\n");

	if (!ob1=present(st1,environment(me)))
		return notify_fail("�Ҳ��� "+st1+" �������.\n");

	if (!ob2=present(st2,environment(me)))
		return notify_fail("�Ҳ��� "+st2+" �������.\n");

	message_vision(HIR ""+ob1->name()+"����"+ob2->name()+"���һ����������������\n" NOR,
		this_player());
	ob1->kill_ob(ob2);
	return 1;
}

int do_wakeup (string arg)
{
	object who;
	object me = this_player();

	if(!arg) return notify_fail ("usage: xing <id>\n");
	if(!objectp(who = present(arg, environment(me))))
		return notify_fail("����û������ˡ�\n");
	if(!who->is_character() || who->is_corpse())
		return notify_fail("�����һ�㣬�ǲ����ǻ��\n");

	who->remove_call_out("revive");
	who->revive();
	who->reincarnate();
	write("Ok.\n");
	return 1;
}

int do_hun (string arg)
{
	object who;
	object me = this_player();
	
	if (!arg) return notify_fail ("usage: hun <id>\n");
	if(!objectp(who = present(arg, environment(me))))
		return notify_fail("����û������ˡ�\n");
	if(!who->is_character() || who->is_corpse())
		return notify_fail("�����һ�㣬�ǲ����ǻ��\n");

	who->remove_call_out("unconcious");
	who->unconcious();
	who->announce();
	write("Ok.\n");
	return 1;
}

int do_die (string arg)
{
	object ob;
	object me=this_player();

	if (!arg) return notify_fail("usage: chuqiao <id>\n");
	if(!objectp(ob = present(arg, environment(me))))
		return notify_fail("����û������ˡ�\n");
	if(!ob->is_character() || ob->is_corpse())
		return notify_fail("�����һ�㣬�ǲ����ǻ��\n");

	message_vision( sprintf(HIY "ֻ��$N���ֶ������һָ����У����������ʡ���\nһ�Ѿ޽��������Ľ�����ɳ���ֱ������...\n" NOR),
		this_player());
	tell_room(environment(ob),"����к�Ȼ������һ�Ѿ޴�ı�����ֱ��վ���Ǳߵ�" + (string)ob->query("name")+"��ȥ��\n" , ob);
	tell_object(ob,"���Ȼ���������һ����������ľ޴󱦽���������..\n������һ��...\n");
	ob->die();
	message_vision( sprintf( HIY "ֻ��$N���ֶ������һָ����У����������ʡ���\nһ�Ѿ޽�������лص���$N���Ľ����\n" NOR),
		this_player());
	write("Ok.\n");
	return 1;
}

int do_reincarnate (string str)
{
	object ob, me;
	
	if (!str) return notify_fail("usage: qshs <id>\n");
	ob = LOGIN_D->find_body(str);
	if (!ob) return notify_fail("���������?\n");
	if (ob->is_ghost())
		tell_object(ob,"�������ȫ������...\n");
	else
		return notify_fail("��...����˺����ǻ�ģ�\n");

	tell_object(ob,"�����ϣ����ǹ�!��Ҫ���㸴��ұ����ϴε�һ�С�\n");
	tell_room(environment(ob),"һ�����ͻȻ��������£�������" + (string)ob->query("name")+"����Χ��\n", ob);
	tell_object(ob,"ͻȻһ����������������𣬡������....��������\n��ʼ���ٲ��ǻ���ˡ�����ͻȻ�е�һ�����...\n");
	ob->reincarnate();
	ob->query_temp("last_damage_from");
	tell_object(ob,"�ܺã����ָ����ˣ�\n");
	write("Ok.\n");
	return 1;
}

int do_disable_player (string str)
{
	object ob;

	if (!str) return notify_fail("usage: feng <id>\n");
	ob = LOGIN_D->find_body(str);
	if (!ob) return notify_fail("���������?\n");

	tell_object(ob,"ͻȻ����۾�һƬģ��...\n");
	ob->set_temp("block_msg/all",1);
	ob->disable_player(HIR "<Ϲ����>" NOR);
	write("Ok.\n");
	return 1;
}

int do_enable_player (string str)
{
	object ob;

	if (!str) return notify_fail("usage: jiefeng <id>\n");
	ob = LOGIN_D->find_body(str);
	if (!ob) return notify_fail("���������?\n");

	tell_object(ob,"�����������˵��������ټ��ټ�ܡ������ָֻ���...\n");
	ob->set_temp("block_msg/all",0);
	ob->enable_player();
	write("Ok.\n");
	return 1;
}

int do_gan (string str)
{
	object ob;

	if (!str) return notify_fail("usage: gan <id>\n");
	ob = LOGIN_D->find_body(str);
	if (!ob) return notify_fail("û�ҵ�����ˡ�\n");

	tell_object(ob,"���ɻ���Ҷ�ס������㣺ʵ�ڲ�����˼����������ȥ��...\n");
	destruct(ob);
	if(ob) write("���޷�������˸��ߡ�\n");
	else write("Ok.\n");
	return 1;
}

void super_die()
{
	CHANNEL_D->do_channel( this_object(),"rumor",
	sprintf(HIY "�������ۿ���" + this_player()->query("name") + "�÷�Ҷ�ı���ɱ�����е��ˡ�" + NOR));
	users()->die();
	write("Ok.\n");
	return 1;
}

int do_halt (string arg)
{
	object ob;
	object me = this_player();

	if (!arg) return notify_fail("usage: quanjia <id>\n");
	if(!objectp(ob = present(arg, environment(me))))
		return notify_fail("����û������ˡ�\n");

	if(!ob->is_fighting())
		return notify_fail("�������ڲ�û�д��С�\n");
	tell_room(environment(ob),HIY "����к�Ȼ�����˷�Ҷ����Ӱ��\n���Ͱ��Ķ�"+
		(string)ob->query("name")+"˵�����������˴������ˣ��ҿ���λ"+RANK_D->query_respect(ob)+"�������˰ɣ���\n" NOR, ob);
	ob->remove_all_killer();
	tell_room(environment(ob),HIC "�ţ�" + (string)ob->query("name")+"˵��������˵�Ķԣ��Ҳ����ٴ��ˡ���\n" NOR, ob);
	tell_room(environment(ob), "..." + (string)ob->query("name")+"�����ܵ����٣����������ˣ�\n", ob);
	return 1;
}

int do_killer(string arg)
{
	object ob1,ob2;
	string st1,st2;
	object me = this_player();

	if (!arg || arg=="") return notify_fail ("��Ҷ˵��������˭��˭���?\n");
	if (sscanf( arg,"%s with %s",st1,st2)!=2 )
		return notify_fail ("jizhu <ob1> with <ob2>\n");
	if(!objectp(ob1 = present(st1, environment(me))))
		return notify_fail("����û������ˡ�\n");
	if(!ob1->is_character() || ob1->is_corpse())
		return notify_fail("�����һ�㣬�ǲ����ǻ��\n");

	if(!objectp(ob2 = present(st2, environment(me))))
		return notify_fail("����û������ˡ�\n");

	ob1->set_temp("looking_for_trouble", 0);
	ob2->set_temp("looking_for_trouble", 0);
	ob1->kill_ob(ob2);
	write(HIC "��Ҷ˵��������������\n" NOR);
	return 1;
}

int do_ban(string arg)
{
	object ob1;
	object me = this_player();
	string st1,st2;

	if (!arg || arg=="") return notify_fail ("��Ҫװ��˭��˵����\n");
	if (sscanf( arg,"%s say %s",st1,st2)!=2 )
		return notify_fail ("ban <id> say <message>\n");
	if(!objectp(ob1 = present(st1, environment(me))))
	return notify_fail("����û������ˡ�\n");
	message("sound", ob1->name() + "˵����" +  st2 + "\n" NOR, environment(ob1), ob1);
	return 1;
}

int do_move(string arg)
{
	object obj;
	object me = this_player();
	object here = environment(me);
	string dir,st1,st2,ch_exit;
	mapping exit;

	if (!arg || arg=="") return notify_fail ("��Ҫ�ƶ�˭��\n");
	if (sscanf(arg, "%s %s", st1, st2)!=2)
		return notify_fail ("usage: move <who> <dir>\n");
	if(!objectp(obj = present(st1, environment(me))))
		return notify_fail("����û������ˡ�\n");
	if( !mapp(exit = here->query("exits")) || undefinedp(exit[st2]) ) {
		return notify_fail("�������û�г�·��\n");
	}
	if(!obj->is_character() || obj->is_corpse())
		return notify_fail("�����һ�㣬�ǲ����ǻ��\n");
	ch_exit = default_dirs[st2];
	message_vision( sprintf("$N���Ժ�������" + ch_exit + "�뿪��\n"), obj);
	obj->move(exit[st2]);
	tell_room(environment(obj), (string)obj->query("name") + "���Ժ��������˹�����\n");
	write("Ok.\n");
	return 1;
}
	
int query_autoload()
{
	if (wizardp(this_player()))
	return 1;
	else return 0;
}
