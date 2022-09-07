// fight.c
// by fire on April 2 1999
#include <verb.h>
inherit VERB_OB;
mixed direct_fight_str(string str) {
	return 1;
}
mixed do_fight_str(string str)
{
	object o, env;
    	mixed ret;
	o=ENV_LIV(str);
	env = this_body()->query_room();
	ret=env->query("no_fight");

	if( stringp(ret)){
		write(ret); return;
	}
	if(ret==1) {
		write("������Ǳ���ĵط���\n");
		return;
	}
	if(!objectp(o)) return;
	if(o==this_body()) {
		write("�Լ����Լ���Ц����\n");
		return;
	}
	if (objectp(o->query_link())){
	    string a_id,b_id;
	    a_id=this_body()->query_primary_id();
            b_id=o->query_primary_id();
	    if(FIGHT_D->get_fight_peer(b_id)!=a_id) {
	      FIGHT_D->set_fight_peer(a_id,b_id);
	      tell(o,this_body()->query_chinese_id()+
		  "�������䡣�����ͬ�⣬�������룺\n%^RED%^     fight "+a_id+"%^RESET%^\n");
	      write( "��Ϊ"+o->query_chinese_id()+"��������ң�Ҫ���䣬����ȶԷ�ͬ����С�\n");
		return;
			                             }
		}
	ret=FIGHT_D->can_fight(this_body(),o);
}

array query_verb_info()
{
     return ({ ({"STR" }) });
}
