// written by fire 
/* Do not remove the headers from this file! see /USAGE for more info. */


inherit __DIR__+"free";

string get_type() {
	return "dcs";
}
string get_type_name() {
	return "%^YELLOW%^���ʦ%^RESET%^";
}
void extra_init() {
	add_ask_str("order","$N��$T����һ�ۣ������Ƕ��Ӷ��ˡ�\n");
	add_question("order","order" );
}
void special_answer(object who, string matt)
{
	string p_id;
	object rom;
	p_id=who->query_primary_id();
	rom=environment(this_object());
        switch(matt)
        {
                case "order" :
			if(p_id==master||p_id==CHAR_D->get_char(master,"mar")) {
				is_busy=1;
				if(rom->get_type()!="kitchen") {
				        this_object()->targetted_action(
						"$N��$T��ͷ����$RҪ���ţ��ҵ���ȥ����׼����\n",who);
					new(__DIR__+"free_menu")->start_menu(who,this_object());
					return;

				}
				if(rom->get_status()<50) {
				        this_object()->targetted_action(
						"$N̾�������������������ò�����������������\n",who);
					new(__DIR__+"free_menu")->start_menu(who,this_object());
					return;
				}
			        this_object()->targetted_action(
				"$N��ͷ����$R���˰ɣ�Ҫ�õ�ʲô��\n",who);
				new(__DIR__+"dcs_menu")->start_menu(who,this_object());
				return;
			}
		        this_object()->targetted_action(
				"$N����$Tһ�ۡ�\n",who);
				return;
        }
}
