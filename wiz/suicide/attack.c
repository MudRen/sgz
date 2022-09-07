// fight.c
// by fire on April 2 1999
#include <verb.h>
inherit VERB_OB;
mixed direct_attack_str(string str) {
	return 1;
}
mixed do_attack_str(string str)
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
		write("这儿不是打架的地方。\n");
		return;
	}
	if(!objectp(o)) return;
	if(o==this_body()) {
		write("自己打自己？笑话。\n");
		return;
	}
	ret=FIGHT_D->can_fight(this_body(),o);
}

array query_verb_info()
{
     return ({ ({"STR" }) });
}
