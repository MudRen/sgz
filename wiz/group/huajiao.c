#include <mudlib.h>

inherit BASE_ROOM;

string *desc = ({
	"�������Ľ����⿴ȥ��ȴʲôҲ���������\n",
	"�������������ӣ�һƬ����Ʈ�������ա�\n",
	"���ӻ����Ƶ����ߣ������Ҳ�������ڶ���\n",
	"�������ƿ���첼ͷ��һ������͵͵�������⿴��\n",
	"ϲ�����������Ž������ϡ��������ߺ�������\n",
	"����ڿ��Ұɡ������������������ﷺ��һ�����ۡ�\n",	
});
void right_place(object ob, string dest);

void setup()
{
	set_light(50);
	set_brief("������");
	set_long("�����ӵĻ����ӣ������ĺò�ϲ������\n");	
}
void destruct_itself(object ob, string boy)
{
//       if(environment(ob)!=this_object())
//                     destruct( this_object() );  // added by fire
	string roomb, roomd;
	object envi;
	
	remove_call_out("destruct_itself");
	roomb = CHAR_D->get_char(boy,"room");
	envi = load_object( roomb );		
	roomd = "/a/"+CHAR_D->get_char(boy,"area")+"xitang";
	if(roomb == roomd )call_out("right_place", ob, envi);
	else {
//		printf( desc[random(sizeof(desc))] );
		tell_from_outside(this_object(),desc[random(sizeof(desc))]);
		call_out("destruct_itself", 4, ob, boy);
	};
	return;
}
void right_place(object ob, object env)
{
	object *obs;
	int i;
	this_object()->move( env );
//	ob->move( env );
	tell_environment( this_object(),"һ��ϲ������Ľη��ӵ��һ����컨�����˹�����\n");
	tell_from_inside (this_object(),
	sprintf("��������ͣ��������ý���ƿ�����Ц��˵�������ˣ������\n"));
	obs=all_inventory(this_object());
	if(sizeof(obs)) {
		for(i=0;i<sizeof(obs);++i) {
			if(obs[i]->is_living()) {
				obs[i]->move(env);
		obs[i]->simple_action("$N��ý�Ų������˻��Ρ�\n");
			}
		}
	}
//        ob->simple_action("$N����������������\n");
	tell_environment(this_object(),"����һ��Ƥ�ޣ�������λ���ؼ���\n��һ�����������ʧ�����쳾��֮���ˡ�\n");
    destruct( this_object() );
	return;
}
