// attck.c
// by Suicide on Aug 22 2000
#include <verb.h>
inherit VERB_OB;
mixed direct_attack_str(string str) {
	return 1;
}
mixed do_attack_str(string str)
{
	object o, env;
    	mixed ret;
    	string *where;
	o=ENV_LIV(str);
	if(!objectp(o)) return;
	if(o==this_body()) {
		write("�Լ����Լ���Ц����\n");
		return;
	}
	where = explode(file_name(this_body()->query_room()),"/");
	if ((AREA_D->get_area(where[1],"meeting")==where[2])||
	    (AREA_D->get_area(where[1],"flying")==where[2]))
	   {
	   write("����Ǿ����صأ�������򶷲��������������ΰ���\n");
	   return;
	}
	env = o->query_room();
	if((o->query_job("patrol","beg_time"))&&
        (o->query_job("patrol","status")!="done")&&
        (o->query_job("patrol","area")==env->get_area())){
                write("�Է����ڴ���ִ��Ѳ������˫ȭ�ѵ����֣����Ƕ�Զ���!\n");
                return;
        }
	ret=FIGHT_D->can_fight(this_body(),o);
}

array query_verb_info()
{
     return ({ ({"STR" }) });
}
