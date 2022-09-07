// written by  fire
// m_charanswer.c
/* for common for chars */
#include <mudlib.h>
#include <daemons.h>
void add_question(string p,string p2);
void char_answer_setup()
{
/*	string p_id,p_area;
	p_id=this_object()->query_id()[0];
	p_area=CHAR_D->get_char(p_id,"area");
	if(!p_area) return;

	if(AREA_D->get_area(p_area,"leader")==p_id) // local leader
	{ */
		add_question("settle","settle" );
		add_question("position","position");		
		add_question("localmeeting","localmeeting");
		add_question("job","job");
		
//	}
    add_question("zgxy","zgxy");
    add_question("wxxy","wxxy");
    add_question("bfxy","bfxy");
    add_question("guoshi","guoshi");
}
void char_special_answer(object who, string matt)
{
    switch(matt)
    {
        case "settle" :
			(EV_SETTLE)->ask_settle(who,this_object());
            return;
		case "position":
			(EV_POSITION)->ask_position(who,this_object());
			return;
		case "localmeeting":
			(EV_LOCALMEETING)->ask_localmeeting(who,this_object());
			return;
		case "job":
			(EV_JOB)->ask_job(who,this_object());
			return;
		case "wxxy" :
		case "bfxy" :
		case "zgxy" :
			(EV_LEARNSKILLS)->ask_skills(who,this_object(),matt);
			return;
	 	case "guoshi":
	 	        ("/sgdomain/event/ev_guoshi.c")->ask_guoshi(who,this_object());
	 	        return;
    }
}
void special_answer(object who,string matt)
{
    if(!(CHAR_D->char_exist(this_object()->query_id()[0]))) {
	this_object()->targetted_action("$N��$T˵�����Բ����Ҳ�֪����\n",who);
	return;
    }
    char_special_answer( who, matt);
}
