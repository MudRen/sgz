// written by fire 
/* Do not remove the headers from this file! see /USAGE for more info. */


inherit __DIR__+"free";

string get_type() {
	return "sc";
}
string get_type_name() {
	return "%^H_GREEN%^���%^RESET%^";
}
void extra_init() {
	add_ask_str("order","$N��$T�������֡�\n");
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
			if(p_id==master) {
				is_busy=1;

			        this_object()->targetted_action(
				"$N��ǰһ���Ϲ�����$s�ڴˣ�$R��Ը���\n",who);
				new(__DIR__+"sc_menu")->start_menu(who,this_object());
				return;
			}
		        this_object()->targetted_action(
				"$N����$Tһ�ۡ�\n",who);
				return;
        }
}
