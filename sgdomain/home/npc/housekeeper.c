// written by fire 
/* Do not remove the headers from this file! see /USAGE for more info. */

inherit M_CHAR;
inherit LIVING;
private string master,master_name;
private is_busy;
void setup(string p_id)
{
	master=p_id;
	master_name=CHAR_D->get_char(p_id,"name");
	set_name(p_id+" dgj","��ܼ�");
	set_gender(1);
    	set_proper_name("��ܼ�");
    	set_in_room_desc(master_name+"�ҵ�%^H_GREEN%^��ܼ�%^RESET%^("+p_id+ " dgj)");
	add_id("dgj");
	set_age(45);

	add_ask_str("order","$N�ع�ͷ����$Tһ�ۡ�\n");
	add_question("order","order" );
	is_busy=0;
}

string long() {
	return master_name+"�ҵ�%^H_GREEN%^��ܼ�%^RESET%^("+master+ " dgj)";
}

void special_answer(object who, string matt)
{
	string p_id;
	p_id=who->query_primary_id();
        switch(matt)
        {
                case "order" :
			if(p_id==master) {
			        this_object()->targetted_action(
				"$Næ��ǰ�Ϲ�����$R�кηԸ���\n",who);
				return;
			}
		        this_object()->targetted_action(
				"$N����$Tһ�ۡ�\n",who);
				return;
        }
}
