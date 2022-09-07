// home.c for players by fire on 1/9/1999

#include <mudlib.h>
#define HOME_SERVER "/sgdomain/home/home_server/"
inherit CMD;

private void main(string arg)
{
    string p_id;
    object ob;
    string *msgs;
    mapping home;

    string p_area;
    if (!arg)
    {
	p_id=this_body()->query_primary_id();
	home=CHAR_D->get_char(p_id,"h");
	if(!mapp(home)) {
		write("�㻹û���ء�\n");
		return;
	}
	if(home["st"]=="building") {
		write("��ļһ�û���á�\n");
		return;
	}
	if(home["st"]=="updating") {
		write("��ļ�����������\n");
		return;
	}

	if(home["st"]=="moving") {
		write("��ļһ�û�ᵽ�ء�\n");
		return;
	}
	if(CHAR_D->get_char(p_id,"task")) {
		write("�������й��������ܻؼҡ�\n");
		return;
	}
	if(CHAR_D->get_char(p_id,"in_prison")){
		write("���������ڷ��̣����ܻؼҡ�\n");
		return;
	}
	p_area=this_body()->query_room()->get_area();
	if(p_area!=home["a"]) {
		write("��ļ���"+AREA_D->get_area(home["a"],"name")+"���������������\n");
		return;
	}

	msgs = this_body()->get_player_message("home");
        if (environment(this_body()))
                this_body()->my_action( "��ؼ�ඡ�\n");
        this_body()->other_action( msgs[1]);

        ob = load_object(HOME_SERVER+p_id+"/front");

        this_body()->move(ob);

        msgs = this_body()->get_player_message("menter");

        tell_environment(this_body(), msgs[1], 0, ({ this_body() }));

//        if ( !(this_body()->test_flag(F_BRIEF)) )
            this_body()->do_game_command("look");
	this_body()->start_busy(2,"����æ�Żؼ��ء�\n");
        return;
    }
    p_id=arg;


    home=CHAR_D->get_char(p_id,"h");
	if(!mapp(home)) {
		write("��Ҫ���ʵ��˻�û���ء�\n");
		return;
	}
	if(home["st"]!="new") {
		write("��Ҫ���ʵ��˵ļ����ڻ����ܰݷá�\n");
		return;
	}
	if(CHAR_D->get_char(this_body()->query_primary_id(),"task")) {
		write("�������й��������ܵ������š�\n");
		return;
	}
	if(CHAR_D->get_char(p_id,"in_prison")){
		write("���������ڷ��̣����ܰݷ����ˡ�\n");
		return;
	}
	p_area=this_body()->query_room()->get_area();
	if(p_area!=home["a"]) {
		write("��Ҫ���ʵ��˵ļ���"+AREA_D->get_area(home["a"],"name")+"���������������\n");
		return;
	}

    this_body()->simple_action("$Nǰ�� " + CHAR_D->get_char(p_id,"name") +
      " �ļ�����������ȥ�ˡ�");

        ob = load_object(HOME_SERVER+p_id+"/front");

        this_body()->move(ob);

    tell_environment(this_body(), this_body()->query_name() +
      "���������� " + CHAR_D->get_char(p_id,"name") + " �һ췹�ˡ�\n",
      0, ({ this_body() }));


//    if(!(this_body()->test_flag(F_BRIEF)))
        this_body()->do_game_command("look");
    this_body()->start_busy(2,"����æ�Ÿ�·�ء�\n");

    return;
}

