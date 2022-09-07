// written by yuner , fire and row
/* Do not remove the headers from this file! see /USAGE for more info. */
inherit M_CHAR;
inherit LIVING;

mixed ask_jiehun(object who);
mixed ask_lihun(object who);
mixed ask_parterner(string t_id);
mixed check();
void answer_agree1(object me,object tar,string ans);
void divorce();
void answer_agree(object me,object girl,string ans);
void answer_parter(object me, object who,string ans);
void special_answer(object who, string matt);

void setup()
{
    set_name("qiao guolao", "�ǹ���");
    set_gender(1);
    set_proper_name("����ү");
    set_in_room_desc("�⿤�¸�����%^H_GREEN%^�ǹ���%^RESET%^(qiao guolao)");
    add_id("qiao");
    set_age(70);

    add_ask_str("jiehun","$N���Ĵյ�$T���ߵ�����������һ�����󣬲�֪������\n$Nһʱ˵�����ڣ��ߵ�����ͨ�졣\n");
    add_question("jiehun","jiehun" );
	add_ask_str("lihun","$N����ͷ��$T������������������顣\n");
	add_question("lihun","lihun");
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
mixed ask_lihun(object who) {
	string p_id=who->query_primary_id();
	int p_gender;
	int p_age;

	p_gender=who->query_gender();
	if(p_gender!=1) return "$N��$T��ͷ���Ŵ�����һ�䣬����ҡͷ����֪ʲô�ط����Ծ���\n";

	if(!CHAR_D->get_char(p_id,"mar")) 
		return "$N��$T���ߡ���һ��������˲��ɣ�����û��������飿\n";
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
		return "$N��$TЦ����"+t_name+"û������Ҫ���������������¿ɲ���������\n";
	if(o_t->query_room()!=this_object()->query_room())	
		return "$N��$TЦ����"+t_name+"û������Ҫ���������������¿ɲ���������\n";
	return 1;
}
mixed check()
{
	object o_t;
	string p_id=this_body()->query_primary_id();
	string t_id,t_name;
	t_id=CHAR_D->get_char(p_id,"mar");
	this_object()->clear_answer();
	if(!CHAR_D->char_exist(t_id)){
	this_object()->targetted_action("$N���ͷ����$T����ԭ����İ��²�����������Ȳ�Ը�ؽڣ��Ϸ������˳ˮ����ɡ�\n",this_body());
	CHAR_D->set_char(p_id,"ever_mar",1);
	call_out("divorce",3);
	return 1;}
	t_name=CHAR_D->get_char(t_id,"name");
	if(CHAR_D->get_char(t_id,"type")!=TYPE_PLAYER){
	this_object()->targetted_action("$N��ֵؿ���$T��"+t_name+"���Ƿ������ˣ�������Ե����Ե���øϿ�ն�ϡ�\n",this_body());
	call_out("divorce",3);
	return 1;}
	o_t=CHAR_D->find_char(t_id);
	if(!objectp(o_t)){
	this_object()->targetted_action("$N��$Tҡͷ����"+t_name+"û������Ҫ�������ʣ����¿ɲ�ͬ��Ϸ��\n",this_body());
	return 1;}
	if(o_t->query_room()!=this_object()->query_room()){
	this_object()->targetted_action("$N��$Tҡͷ����"+t_name+"û������Ҫ�������ʣ����¿ɲ�ͬ��Ϸ��\n",this_body());
	return 1;}
	this_object()->targetted_action("$N��$T����$R�Ȳ�Ҫ�ż�����������$o�������\n",this_body(),o_t);
	this_object()->targetted_action("$N��$T����$RԸ���$o�����Լ��\n",o_t,this_body());
	tell_user(t_id,"Ը��ͣ�%^RED%^answer yes to qiao%^RESET%^��\n");
	CHAR_D->set_char(t_id,"pre_div",p_id);
	this_object()->set_answer(t_id, (:answer_agree1:) );
}
void answer_agree1(object me,object tar,string ans) {
	string p1,p2;
	object tar1;
	me->clear_answer();
	p1=tar->query_primary_id();
	p2=CHAR_D->get_char(p1,"pre_div");
	CHAR_D->set_char(p1,"pre_div",0);
	tar1=CHAR_D->find_char(p2);
	if(ans!="yes") {
		me->responda("sigh "+p2);
		me->targetted_action("$N��$T�����Է���ͬ�⣬���ǻ�ȥ�������������ɡ�\n",tar1);
		return; 
	}
	me->responda("hmm");
	me->targetted_action("$N��$T��$o�����ðɣ���Ȼ˫���ĸ���Ը���Ϸ�Ҳ���ٶ�˵�ˡ�\n",tar1,tar);
	CHAR_D->set_char(p1,"mar");
	CHAR_D->set_char(p1,"ever_mar",1);
	CHAR_D->set_char(p2,"mar");
	CHAR_D->set_char(p2,"ever_mar",1);
	tell(users(),"%^H_MAGENTA%^����Ե��%^H_GREEN%^�ǹ���%^H_YELLOW%^��"+CHAR_D->get_char(p2,"name")+"��Ը��"+
	CHAR_D->get_char(p1,"name")+"�����Լ���Ӵ˶��˳�·�ˣ������Ƿ����ˡ�\n");
	return;
}
void divorce()
{
	string p_id=this_body()->query_primary_id();
	CHAR_D->set_char(p_id,"mar");
	tell(users(),"%^H_MAGENTA%^����Ե��%^H_GREEN%^�ǹ���%^H_YELLOW%^���������£���һ�����须���˵á��Ϸ������������"+CHAR_D->get_char(p_id,"name")+"��������\n");
	return;
}	
void answer_agree(object me,object girl,string ans) {
	string p_boy,p_girl;
	object boy;
	me->clear_answer();
	p_girl=girl->query_primary_id();
	p_boy=CHAR_D->get_char(p_girl,"pre_mar");
	CHAR_D->set_char(p_girl,"pre_mar",0);
	boy=CHAR_D->find_char(p_boy);
	if(ans!="yes") {
		me->responda("poor "+p_boy);
		me->targetted_action("$N��$T�������ж�־���ķ������ɷ�λ����ޡ���ȥŬ������һ����Ư���ġ�\n",boy);
		return; 
	}
	me->responda("great");
	if(CHAR_D->get_char(p_girl,"ever_mar")||CHAR_D->get_char(p_boy,"ever_mar"))
	{
	me->simple_action("$N����Ц�ݵص���������������ٻ飬���Ϸ򿴣��Ͳ��ش�ٴ���˰ɡ�\n");
	boy->responda("ok");
	girl->responda("ok");
	CHAR_D->set_char(p_girl,"mar",p_boy);
	CHAR_D->set_char(p_boy,"mar",p_girl);
	tell(users(),"%^H_MAGENTA%^����Ե��%^H_GREEN%^�ǹ���%^H_RED%^��"+CHAR_D->get_char(p_boy,"name")+"��"+
	CHAR_D->get_char(p_girl,"name")+"����ǰ�ӣ�Ը�ɰ���֮�ã�ף�����Ҹ���%^RESET%^\n");
	return;
	}
	me->targetted_action("$N��$T��$o�����úã���λ��ȥ׼����������һ�����̰��ó��ס�\n"+
		"$n�ֲ������δ��ʽ�ɻ�֮ǰ�ɲ�����������\n",boy,girl);
	CHAR_D->set_char(p_girl,"pri_mar",p_boy);
	CHAR_D->set_char(p_boy,"pri_mar",p_girl);
	tell(users(),"%^H_MAGENTA%^����Ե��%^H_GREEN%^�ǹ���%^H_RED%^��"+CHAR_D->get_char(p_boy,"name")+"Ը��"+
	CHAR_D->get_char(p_girl,"name")+"�ɰ���֮�ã�ף�������ճɻ顣%^RESET%^\n");
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
			case "lihun":
			ret=ask_lihun(who);
			if(stringp(ret)){
				this_object()->targetted_action(ret,who);
				return;
			}
			this_object()->targetted_action(
			"$N����$Tһ�ۣ�����Ŷ��Ҫ��飬���Ϸ��顣\n$N����ȡ��һ��%^H_MAGENTA%^��Ե��%^RESET%^�鿴��������\n",who);
			call_out("check",2);
			return;
        }
}