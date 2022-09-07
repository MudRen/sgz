// ai_d.c by fire on June 21, 1998
// this is the centure of the game's IA
// which will contral most the events
// and some behaveor of npcs
#include <ansi.h>
#include <mudlib.h>
#include <daemons.h>
#define DAY_LENGTH 240
#define LOCAL_INCOME 100
#define LEADER_APPEAR 200
#define LEADER_DISAPPEAR 201
#define RAND_APPEAR 202
#define RAND_DISAPPEAR 203
#define NPC_COUNTRY 300
#define BASE_WORK 301
#define GETTOP 302
#define AUTOCONSUME 303
#define M_LOCAL_INCOME "�����á�"+HIG+"���õ����ӵ��ˣ��ٱ����˸߲��ҵ�������ȥ�ˡ�"+NOR+"\n"
#define M_HARVEST "���ջ�"+HIG+"�ջ�ļ��ڵ��ˣ������һƬ��æ�ľ���"+NOR+"\n"
void event_creater();
static private int p_month,p_day,p_hour,p_year;
void launch(int p_what);
void create()
{

        // nothing here yet
        call_out("event_creater",random(EVENT_RAND)+EVENT_BASE);
        return;
}
void start()
{
        array p_date;
        p_date=DAY_D->query_date();
        p_hour=p_date[0];
        p_day=p_date[1];
        p_month=p_date[2];
        p_year=p_date[3];
        if((p_day==10)&&(p_hour==1)) // the noon in 10th of every month
        {
                call_out((: launch :),DAY_LENGTH/3,LOCAL_INCOME);
        }
        if(((p_day==3)||(p_day==7))&&(p_hour==1)) // the day for development
                COUNTRY_D->adjust_product_level();
        if((p_day==1)&&(p_hour==1))
                COUNTRY_D->adjust_safe_level();
        if((p_day==5)&&(p_hour==1)&&(p_month%2))
                COUNTRY_D->adjust_military_level();
        if((p_day==9)&&(p_hour==1))
                (EV_ADJPOPULATION)->adjust_population();
        if((p_day==2)&&(p_hour==1))
        {
                AREA_D->area_check();
                CHAR_D->char_check();
        }
        if(((p_month==3)||(p_month==9))&&(p_day==5)&&(p_hour==1))
		"/sgdomain/event/ev_bwdh"->check_bwdh();
// if(((p_month==3)||(p_month==6)||(p_month==9)||(p_month==12))&&(p_day==1)&&(p_hour==2))
//  "/sgdomain/event/ev_fate"->start();


        if((p_month==1)&&(p_day==1)&&(p_hour==1))
             (EV_ADDLOYALTY)->addloyalty();
        if((p_day==1)&&(p_hour==2))
             (EV_ADDREPUTATION)->addreputation();
                if(p_hour==3)
                {
                        call_out((:launch:),DAY_LENGTH/6,LEADER_DISAPPEAR);
                        call_out((:launch:),DAY_LENGTH*5/6,LEADER_APPEAR);
                }

        CHAR_D->save_data();
        AREA_D->save_data();
        COUNTRY_D->save_data();
       call_out((:launch:),DAY_LENGTH/3,RAND_APPEAR);
       call_out((:launch:),DAY_LENGTH*2/3,RAND_DISAPPEAR);
	//if(p_hour==3)  
	//   call_out((: launch :),DAY_LENGTH/5,NPC_COUNTRY);
	// Remed by suicide in 2000.08.07 for not select guoshi automaticlly
	
	if (p_hour==4)      
	   "/daemons/npcai_d"->act();      //call npcai_d
	 
	if(p_hour==4)
		call_out((: launch :) ,DAY_LENGTH/5,BASE_WORK);
	if((p_hour==2)&&(p_day==2)&&(p_month==1)&&((p_year%10)==0))
		call_out(( : launch :), DAY_LENGTH/4,GETTOP);

	if((p_hour==3)&&(p_day==3)&&(p_month==1))
		call_out(( : launch :), DAY_LENGTH/4,AUTOCONSUME);
 

}
void launch(int p_what)
{
        switch(p_what)
        {
		case BASE_WORK:
			("/sgdomain/event/ev_basework")->base_work();
			return;
	case NPC_COUNTRY:
		("/sgdomain/event/ev_npccountry")->act();
		return;
        case LOCAL_INCOME:
                (EV_LINCOME)->local_income();
                tell(users(),M_LOCAL_INCOME);

// now nation income just has gold from local_income;
//                AREA_D->nation_income();
//                COUNTRY_D->country_pay_whole();
//                (EV_AREAPAY)->area_pay_whole();
// called from ev_lincome
               (PEVENT+"ev_myarmyadjust")->myarmy_adjust();
                if(p_month==9)
                        tell(users(),M_HARVEST);
                return;
        case LEADER_APPEAR:
              (EV_LDAPP)->leader_appear();
                return;
        case LEADER_DISAPPEAR:
                (EV_LDDISAPP)->leader_disappear();
                return;
       case RAND_APPEAR:
           ("/sgdomain/event/ev_guy")->aut_appear();
         return;
      case RAND_DISAPPEAR:
        ("/sgdomain/event/ev_randdisapp")->ran_disappear();
          ("/sgdomain/event/ev_randapp")->ran_appear();
		return;
      case GETTOP:
          ("/sgdomain/event/ev_gettop")->start();
		  return;
      case AUTOCONSUME:
          ("/sgdomain/event/ev_autoconsume")->auto_consume();
		  return;
        default:
                return;
     }
}
void event_creater()
{
        int p_event;
        call_out("event_creater",random(EVENT_RAND)+EVENT_BASE);
        p_event=random(30);
        switch(p_event)
        {
	case 0..2 :
//        case EVENT_NPCCHAR_MOVE:
		"/sgdomain/event/ev_npc_move"->npc_move(CHAR_D->pick_char());
                break;
//        case EVENT_NPCCHAR_LOCALPOSITION:
	case 3..5 :
		(EV_POSITION)->npc_aut_localposition(CHAR_D->pick_char());
                break;
	case 6:
		(EV_LEAVE)->retire();
		break;
	case 7..9:
                (EV_LEAVE)->addleave();
                break;
        case 10..15:
                (EV_DONATE)->auto_donate(CHAR_D->pick_char());
                break;
        case 16:
                (EV_WAR)->auto_war();
                break;
        case 17:
                (EV_MERCHANT)->auto_business();
                break;
        case 18:
                ("/sgdomain/event/ev_xianren.c")->aut_appear();
                break;
         case 19:
            MUSEUM_D->auto_active_npc();
            break;
        default:
                (EV_LEAVE)->auto_leave(CHAR_D->pick_char());
                break;
        }
}
void remove()
{
   remove_call_out("event_creater");
}
int clean_up() {
   return 0; // means never_again
}

