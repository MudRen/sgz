// written by fire 
/* Do not remove the headers from this file! see /USAGE for more info. */


inherit __DIR__+"free";

string get_type() {
	return "zfxs";
}
string get_type_name() {
	return "%^H_RED%^�ʷ�����%^RESET%^";
}
void extra_init() {
	add_ask_str("order","$N��$T���˵�ͷ��$SҪ�����Ŀ��\n");
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

				if(rom->get_type()!="zhangfang") {
				        this_object()->targetted_action(
						"$Nһģ���ӵ�������Ҫȥ�ʷ����С�\n",who);
					new(__DIR__+"free_menu")->start_menu(who,this_object());

					return;

				}
				if(rom->get_status()<50) {
				        this_object()->targetted_action(
						"$Nһģ���ӵ����ʷ��������ò������ʸ���û���ǡ�\n",who);
					new(__DIR__+"free_menu")->start_menu(who,this_object());

					return;
				}
			        this_object()->targetted_action(
				"$N����һ���ʱ���$R���Ŀ��\n",who);
				new(__DIR__+"zfxs_menu")->start_menu(who,this_object());
				return;
			}
		        this_object()->targetted_action(
				"$N����$Tһ�ۡ�\n",who);
				return;
        }
}
