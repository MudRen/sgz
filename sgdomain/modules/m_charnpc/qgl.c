// written by yuner and fire 
/* Do not remove the headers from this file! see /USAGE for more info. */
inherit M_CHAR;
inherit LIVING;
void setup()
{
    set_name("qiao guolao", "�ǹ���");
    set_gender(1);
    set_proper_name("����ү");
    set_in_room_desc("�⿤�¸�����%^H_GREEN%^�ǹ���%^RESET%^(qiao guolao)");
    add_id("qiao");
    set_age(70);

    add_ask_str("jiehun","$N���Ĵյ�$T���ߵ�����������һ�����󣬲�֪..һʱ˵�����ڣ��ߵ�����ͨ�졣\n");
    add_question("jiehun","jiehun" );

}
string long() {
	return
"һ����ʮ��������ߣ��׷�ͯ�ԣ�����Ц�ݡ�\n";
}
mixed ask_jiehun(object who) {
	string p_id=who->query_primary_id();
	int p_gender;
	int p_age;

	p_gender=who->query_gender();
	if(p_gender==2) return "$N��$T̾��һ������Ů�˼�Ҳ�������������飬��������\n";
	if(p_gender!=1) return "$N��$T��ͷ���Ŵ�����һ�䣬����ҡͷ����֪ʲô�ط����Ծ���\n";

	p_age=who->query_age();
	if(p_age<16) return "$N����������$T��ͷ��˵������ôС��ѧ�����������ǳ��������ɡ�\n";

	if(CHAR_D->get_char(p_id,"reputation")<10000) 
		return "$N��$T�������ж���ҵΪ�أ�$R������ȥ�ɾ�һ����ҵ����Щ�������źóɼ�ҵ��\n";
	if(CHAR_D->get_char(p_id,"mar")) 
		return "$N��$T���ߡ���һ�������ػ飿�Ŷ�û�У����ʾ�ץ������\n";
	return 1;
}
mixed ask_parterner(string t_id) {
	object o_t;
	string t_name;
	if(!CHAR_D->char_exist(t_id))
		return "$N��$T��ֵص���"+t_id+"������ôû��˵����\n";
	t_name=CHAR_D->get_char(t_id,"name");
	if(CHAR_D->get_char(t_id,"type")!=TYPE_PLAYER)
		return "$N��$T��Ц����"+t_name+"���Ƿ������ˣ������������¡�\n";
	if(CHAR_D->get_char(t_id,"gender")!=2)
		return "$N��$T��Ц�������"+t_name+"���������ֵ��ǰɣ����ָ���ץ������\n";
	if(CHAR_D->get_char(t_id,"age")<15)
		return "$N��$TЦ����"+t_name+"̫С�ˣ���Ҳ������ô�Լ�ѽ��\n";

	if(CHAR_D->get_char(t_id,"mar")) 
		return "$N��$TЦ����"+t_name+"�����ż��ˣ���������\n";

	o_t=CHAR_D->find_char(t_id);
	if(!objectp(o_t))
		return "$N��$TЦ����"+t_name+"û������Ҫ���������������¿ɲ�������\n";
	if(o_t->query_room()!=this_object()->query_room())	
		return "$N��$TЦ����"+t_name+"û������Ҫ���������������¿ɲ�������\n";

	return 1;

}
void answer_agree(object me,object girl,string ans) {
	string p_boy,p_girl;
	object boy;
	p_girl=girl->query_primary_id();
	p_boy=CHAR_D->get_char(p_girl,"pre_mar");
	CHAR_D->set_char(p_girl,"pre_mar",0);
	boy=CHAR_D->find_char(p_boy);
	if(ans!="yes") {
		me->responda("poor "+p_boy);
		me->targetted_action("$N��$T�������ж�־���ķ������ɷ�λ����ޡ�\n",boy);
		return; 
	}
	me->responda("great");
	me->targetted_action("$N��$T��$o�����úã���λ��ȥ׼����������һ�����̰��ó��ס�\n"+
		"$n�ֲ������δ��ʽ�ɻ�֮ǰ�ɲ����������\n",boy,girl);
	CHAR_D->set_char(p_girl,"pri_mar",p_boy);
	CHAR_D->set_char(p_boy,"pri_mar",p_girl);
	return;
}
void answer_parter(object me, object who,string ans) {
	mixed ret;
	object o_t;
	string p_id;
	p_id=who->query_primary_id();
	me->clear_answer();
	ret=ask_parterner(ans);
	if(stringp(ret)) {
		me->targetted_action(ret,who);
		return;
	}
	o_t=CHAR_D->find_char(ans);
	me->targetted_action("$N��$T����$R�Ȳ�Ҫ�ż�������������$o�������\n",who,o_t);
	me->targetted_action("$N��$T΢Ц����$RԸ��޸�$o��\n",o_t,who);
	tell_user(ans,"Ը��ͣ�%^RED%^answer yes to qiao%^RESET%^��\n");
	CHAR_D->set_char(ans,"pre_mar",p_id);
	me->set_answer(ans, (:answer_agree:) );

}
void special_answer(object who, string matt)
{
	mixed ret;
	string p_id;
	p_id=who->query_primary_id();
        switch(matt)
        {
                case "jiehun" :
			ret=ask_jiehun(who);
			if(stringp(ret)) {
				this_object()->targetted_action(ret,who);
				return;
			}
		        this_object()->targetted_action(
				"$N��$TЦ��������ŤŤ��������������ѽ��������˭�ˣ�\n",who);
			this_object()->set_answer(p_id, (:answer_parter:) );
			tell_user(p_id,"��%^RED%^answer <����ID> to qiao%^RESET%^���ش�\n");
                        return;
        }
}
