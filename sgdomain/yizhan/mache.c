#include <mudlib.h>

inherit BASE_ROOM;

string *desc = ({
	"�����������бޣ�ߺ���ţ�������������\n",
	"�����������Ȼ��֪������龰��\n",
	"���λ����ƣ�ͣͣ���ߣ���֪����á�����\n",
	"�㲻�ͷ������������ţ���Ҫ�߶�ã�\n",
	"���������Ļ��˼��±��ӡ�\n",
	"·��û��һ�����ˣ���Խ��Խ���ˡ�\n",	
});
void right_place(object ob, string dest);

void setup()
{
	set_light(50);
	set_brief("����");
	set_long("һ������������������ǰ���š�\n");	
}
void destruct_itself(object ob, int time, string dest)
{
//       if(environment(ob)!=this_object())
//                     destruct( this_object() );  // added by fire
	remove_call_out("destruct_itself");
	time = time - 4;
	if( time < 4 )call_out("right_place", time, ob, dest);
	else {
//		printf( desc[random(sizeof(desc))] );
		tell_from_outside(this_object(),desc[random(sizeof(desc))]);
		call_out("destruct_itself", 4, ob, time, dest);
	};
	return;
}
void right_place(object ob, string dest)
{
	string path, name;
	object env;
	object *obs;
	int i;
	path = AREA_D->get_area(dest, "path");
        name = AREA_D->get_area(dest, "go");
        if(!name) name=AREA_D->get_area(dest,"fly");
	env = load_object( path + name);
	this_object()->move( env );
//	ob->move( env );
	tell_environment( this_object(), "һ�����������ƶ�������\n");
	tell_from_inside (this_object(),
        sprintf("������ͣ�������������ƿ����ŵ���%s�ѵ������³���\n",
		AREA_D->get_area(dest,"name")));
	obs=all_inventory(this_object());
	if(sizeof(obs)) {
		for(i=0;i<sizeof(obs);++i) {
			if(obs[i]->is_living()) {
				obs[i]->move(env);
				obs[i]->simple_action("$N����������������\n");
			}
		}
	}
//        ob->simple_action("$N����������������\n");
	tell_environment(this_object(),"����һ��Ƥ�ޣ�������λ���ؼ���\n��һ�����������ʧ�����쳾��֮���ˡ�\n");
    destruct( this_object() );
	return;
}
