// wroten by emperor

inherit __DIR__+"free";

string get_type() {
	return "sn";
}
string get_type_name() {
	return "%^H_GREEN%^侍女%^RESET%^";
}
void extra_init() {
	add_ask_str("order","$N对$T是了个眼色。\n");
	add_question("order","order" );
}

void special_answer(object who, string matt)
{
	string p_id;
	p_id=who->query_primary_id();
        switch(matt)
        {
                case "order" :
			if(p_id==master||p_id=CHAR_D->get_char(master,"mar")) {
			        this_object()->targetted_action(
				"$N忙上前鞠躬道：$R有何吩咐？\n",who);
				is_busy=1;
				new(__DIR__+"sn_menu")->start_menu(who,this_object());
				return;
			}
		        this_object()->targetted_action(
				"$N瞪了$T一眼。\n",who);
				return;
        }
}

