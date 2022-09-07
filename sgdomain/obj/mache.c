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
	remove_call_out("destruct_itself");
	time = time - 4;
	if( time < 4 )call_out("right_place", time, ob, dest);
	else {
		printf( desc[random(sizeof(desc))] );
		call_out("destruct_itself", 4, ob, time, dest);
	};
	return;
}
void right_place(object ob, string dest)
{
	string path, name;
	object env;

	path = AREA_D->get_area(dest, "path");
	name = AREA_D->get_area(dest, "fly");
	env = load_object( path + name);
	this_object()->move( env );
	tell_environment( env, "һ�����������ƶ�������\n");
	ob->move( env );
        printf("������ͣ�������������ƿ����ŵ���%s�ѵ������³���\n",AREA_D->get_area(dest,"name"));
        ob->simple_action("$N����������������\n");
        write("����һ��Ƥ�ޣ�������λ$R���ؼ���\n��һ�����������ʧ�����쳾��֮���ˡ�");
        destruct( this_object() );
	return;
}
