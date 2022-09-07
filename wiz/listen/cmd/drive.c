#include <mudlib.h>
inherit CMD;
#define K 0.3
static private array disp=
({
	"�����ڳ�����е����������ܵķ羰��\n",
	"������%^H_CYAN%^�ܳ�%^RESET%^�У�ת˲��Խ����һ����ɽ��\n",
	"��·��һ��С���У��������������������⡣\n",
	"���ȻƳ��һ����Ů������һ㶣������������\n�����%^H_CYAN%^�ܳ�%^RESET%^���̰���˦Զ�ˡ�\n",
	"����һƬ�ںڵ�ɭ�֣���ĳ�ͷǿ�⾪��һƬƬ����\n",
	"��ֻ����������ĺ�������ɽ���лص���\n",
	"Զ���������ӣ��ƺ������˳�û��\n",
	"��ͻȻ�˵����İ���%^H_CYAN%^�ܳ�%^RESET%^�ں������мӿ����ٶȡ�\nת˲�䣬���������ԶԶ������������\n",
	"һ��ը�ף������������, ���ڳ���Ҳ������ɳɳ������\n",
	"��ԶԶ���ƺ�������ս����˺ɱ����\n",
});
private void main(string arg)
{
	object me=this_body();
	object env,eenv;
	string h_type;
	mixed rid;
	int dist,t;
	string star,d_name;
	int speed, endurance;
	env=environment(me);
	if(!env->is_horse()){
		write("ֻ�����ڳ��в���ʹ��������\n");
		return;
	}
	h_type=env->query_primary_id();
	speed=OBJ_D->get_obj(h_type,"sp");
	endurance=OBJ_D->get_obj(h_type,"en");
	if(!speed) speed=10;
	if(!endurance) endurance=10;
	if(!arg)arg="";
	if(!AREA_D->area_exist(arg)){
		write("û���������������cmd help go �鿴������\n"+
			"�� info a list ���ĵ����б���\n");
		return;
	}
	eenv=me->query_room();
	star=eenv->get_area();
	dist=AREA_D->get_distance(star,arg);
	if(dist==0){
		write("�����ھ������������\n");
		return;
	}
	if(dist==-1)dist=10;
	if(dist>endurance) {
		write("���"+env->short()+"һ���ܲ�����ôԶ����ĳ���û�͵ġ�\n");
		return;
	}
	t=to_int(dist*speed*K)+5;
	d_name=AREA_D->get_area(arg,"name");
	this_body()->simple_action(
		"$Nһ�����ţ�"+env->short()+"�����㳯Զ�����۶�ȥ������\n");

	rid=env->get_riders();
	foreach(object o in rid)
		o->start_busy(t,"�����ڱ���ר�Ŀ�����\n");
	env->move(new(VOID_ROOM));
	call_out("random_disp",random(5)+3,({env,arg}));
	call_out("get_target",t,({env,arg}));
	return;

}
void get_target(mixed par)
{
	object o,env,envv;
	string tar,room;
	mixed rid;
	remove_call_out("random_disp");
	tar=par[1];
	if(AREA_D->get_area(tar,"go"))
        
	room=AREA_D->get_area(tar,"path")+
                AREA_D->get_area(tar,"go");
	else
        room=AREA_D->get_area(tar,"path")+
                AREA_D->get_area(tar,"fly");
	env=par[0];
	if(!objectp(env)) return;
	envv=environment(env);
		if(envv->is_voidroom())
		{
			o=load_object(room);
			tell_from_outside(o,sprintf(
				"һ��������һ��%sͻȻ�����������ǰ��\n",env->query_chinese_id()));

			env->move(o);
			tell_from_outside(env,"Ŀ�ĵص��ˡ�\n");
			destruct(envv);
		}
	rid=env->get_riders();
	if(sizeof(rid))
	foreach(object p in rid)
	{
		
		p->start_busy(0);
		p->responda("look");
	}

}
void random_disp(mixed par){
	call_out("random_disp",4+random(6),par);
	if(objectp(par[0]))
		tell_environment(par[0],disp[random(sizeof(disp))]);
}