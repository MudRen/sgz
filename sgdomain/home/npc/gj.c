// written by fire 
/* Do not remove the headers from this file! see /USAGE for more info. */


inherit __DIR__+"free";

string get_type() {
	return "gj";
}
string get_type_name() {
	return "%^H_GREEN%^�ܼ�%^RESET%^";
}
void extra_init() {
	add_ask_str("order","$N��$Tʹ�˸���ɫ��\n");
	add_question("order","order" );
}
void special_answer(object who, string matt)
{
	string p_id;
	p_id=who->query_primary_id();
        switch(matt)
        {
                case "order" :
			if(p_id==master||p_id==CHAR_D->get_char(master,"mar")) {
			        this_object()->targetted_action(
				"$Næ��ǰ�Ϲ�����$R�кηԸ���\n",who);
				is_busy=1;
				new(__DIR__+"gj_menu")->start_menu(who,this_object());
				return;
			}
		        this_object()->targetted_action(
				"$N����$Tһ�ۡ�\n",who);
				return;
        }
}
