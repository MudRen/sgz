// written by row May. 1999 
/* Do not remove the headers from this file! see /USAGE for more info. */
#include <mudlib.h>
#include <sanguo.h>
#include <ansi.h>

inherit LIVING;
inherit M_ACTIONS;
inherit M_TRIGGERS;
inherit CHINESE_DA;
inherit M_BLOCKEXITS;

string *query_channel_list() {
    	return ({ "plyr_gossip" });
}
void add_out()
{
   	string *exits;
   	string p_area;
   	object room;

   	room = environment(this_object());
   	if( !objectp(room) ){ 
		SGSYS("I have no room !!!"); 
		return;
	}
   	exits = room->query_exit_directions(1);
   	if( member_array("out",exits)!=-1 ) return; // out is here
  	p_area = room->get_area();
   	room->add_exit("out",AREA_D->get_area(p_area,"path") +
     		AREA_D->get_area(p_area,"fly"));
}
private mixed handle_blocks( string dir )
{
    	string p_area,p_fly;
    	object room;
    	string p_id;
    	room = environment(this_object());
    	if(!objectp(room)){
		SGSYS("I don't know where am i. "); 
		return;
	}
    	p_area = room->get_area();
	p_fly  = AREA_D->get_area(p_area,"path")+AREA_D->get_area(p_area,"fly");
    	p_id   = this_body()->query_id()[0];
	if( wizardp(this_body()) ){
		return 0;
	}
	if( (CHAR_D->get_char(p_id,"in_prison")) == 0 ) return 0;
    	return ::handle_blocks(dir);	
}
void setup()
{
    	set_name("yu zu", "����");
    	set_gender(1);
    	set_proper_name("����");
    	set_in_room_desc(""HIB"����"NOR"(yu zu)");
    	set_age(35);
	set_sg_rongmao(15);
    	set_long("����ר�Ÿ��𿴹ܼ����ģ��������������Ļ��������ʹ�����\n(ask yu zu about out)\n");
	add_question("here","here");
	add_question("out","out");
	add_ask_str("out","$N�����Ͱ͵���$T������ʲôʱ��ſ��Գ�ȥѽ��\n");
        call_out("add_out",random(10)+1);
    	add_block("out");
    	set_block_action( "$Nһ�ƽ�$T���˸����򣺸�ʲô������Խ��ѽ�����ȥ�ȵ��ʹ��ҡ�\n");
}
void special_answer(object who, string matt)
{
	string p_id;
	int be_caught,last_login,min,sec,in_prison,time;

	p_id=this_body()->query_id()[0];
	last_login=LAST_LOGIN_D->query_last(p_id)[0];
	be_caught=CHAR_D->get_char(p_id,"be_caught");
	in_prison=(CHAR_D->get_char(p_id,"in_prison"))*60;
	time=time();
	switch(matt)
	{
		case "here" :
			this_object()->simple_action("$N��Цһ������������Ǽ�����ϲ����ϲ���ͳ����ɡ�\n",who);
 			return;
		case "out" :
			if ((CHAR_D->get_char(p_id,"in_prison"))==0){
				this_object()->targetted_action("$N���ͷ��ص���$m���㲻�����������Գ�ȥ��������������ҵ��ۡ�\n",who);
				return;
			}
			if( (last_login>be_caught) ){
				if( time<(last_login+in_prison) ){
					min=(in_prison+last_login-time)/60;
					sec=in_prison+last_login-time-(min*60);
					this_object()->targetted_action("$N��Ц����$m����ʲô�����㻹������"+chinese_number(min)+"��"+chinese_number(sec)+"����Σ���ʵ���Űɣ�\n", who);
					return;
				}
				this_object()->targetted_action("$N���ͷ������$m����������������Գ�ȥ�ˡ�\n",who);
				CHAR_D->set_char(p_id,"in_prison",0);
				CHAR_D->set_char(p_id,"be_caught",0);
				CHAR_D->set_char(p_id,"caught_area",0);
				return;
			} else {
				if( time<(be_caught+in_prison) ){
					min=(in_prison+be_caught-time)/60;
					sec=in_prison+be_caught-time-(min*60);
					this_object()->targetted_action("$N��Ц����$m����ʲô�����㻹������"+chinese_number(min)+"��"+chinese_number(sec)+"����Σ���ʵ���Űɣ�\n", who);
					return;
				}
				this_object()->targetted_action("$N���ͷ������$m����������������Գ�ȥ�ˡ�\n",who);
				CHAR_D->set_char(p_id,"in_prison",0);
				CHAR_D->set_char(p_id,"be_caught",0);
				CHAR_D->set_char(p_id,"caught_area",0);
				return;
			}
 	}
}
