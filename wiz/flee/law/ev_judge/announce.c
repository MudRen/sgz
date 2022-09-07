#include <ansi.h>

static string *title = ({"ة��","̫ξ","��˾��","̫����","̫����",
                                "������","͢ξ��","��ξ��","������","˾ũ��" });

void announce_elect_result(string *ss, int turn);
void call_for_meeting(string *ss);
void announce_process(int tt);
void announce_start();
void call_for_ministers(string *ss);
void announce_end();
void announce_nojudge(string k);
void announce_who_win(string k);
void announce_who_lose(string k);
void announce_end_meeting();
void call_for_judge();

void announce_elect_result(string *ss, int turn)
{    
    string str  = "%^H_YELLOW%^��������͢��%^H_RED%^����%^H_CYAN%^���У�\n";
    string *msg = ({ 	"%^H_RED%^����%^H_CYAN%^���У�������������꣬����һ����������¡�%^RESET%^\n",
			"%^H_CYAN%^���׵ۣ��%^RESET%^\n",
			"%^H_RED%^����%^H_CYAN%^���У��ǡ�%^RESET%^\n",
			"%^H_RED%^����%^H_CYAN%^���У�Т��ʵۣ��������񣬻ʵ۳��ã������������������٣�����\n                      ��㡣������ɥ���衣����������Ϊ����ң��������٣�Ӧ��\n                      ˳�ˣ���ο����֮����%^RESET%^\n",
			"%^H_CYAN%^���׵��ߵ�����ͨ�죬�޲����Ҹ��ط����ȥ��%^RESET%^\n",
			"%^H_CYAN%^���׵ۣ��ƣ���˹��˱㽵һگ�����˴�Ϊ�����ա�%^RESET%^\n",
			"%^H_CYAN%^Ƭ�̺󡣡���%^RESET%^\n\n",
			"%^H_RED%^����%^H_CYAN%^���У�������ˣ��ʵ�گԻ������˳Ӧ��������������Ϊ�Źɣ�����\n"+"                      ���⣺%^RESET%^\n\n", });
    if ( !turn||!intp(turn) ) turn = 0;
    if ( turn>=sizeof(msg) ) {
          foreach ( string s in ss ) {
              str +=    HIC+"                      ��  "+HIG+
			COUNTRY_D->get_country(CHAR_D->get_char(s, "nation"), "name")+
			AREA_D->get_area(CHAR_D->get_char(s, "area"),"name")+
			OFFICER_D->get_officer(CHAR_D->get_char(s, "ranklocal"),"name")+"��"+ 
			CHENGHU_D->query_char_jun(s)+"��"+NOR+
			CHAR_D->get_char(s, "name")+HIC+"��  "+HIY+
			title[CHAR_D->get_char(s,"rankroyal")]+HIC+"һְ��"+NOR+"\n";
          }
	tell( users(), str+"%^RESET%^\n");
    } else {
    	tell( users(), "%^H_YELLOW%^��������͢��"+msg[turn] );
	turn ++;
	remove_call_out("announce_elect_result");
        call_out("announce_elect_result", 2, ss, turn);
    }
    return;
}
void call_for_meeting(string *ss)
{
    int i;
    string str  = "%^H_YELLOW%^��������͢��%^H_RED%^����%^H_CYAN%^���У�������ˣ��ʵ�گԻ: ��\n                      ";
    foreach ( string s in ss ) {
	str += HIW+title[CHAR_D->get_char(s,"rankroyal")]+NOR+CHAR_D->get_char(s,"name")+"��";
        i++;
        if ( i == 3 ) {
     	    i = 0;
	    str += "\n                      ";
	}
    }
    tell(users(), str[0..sizeof(str)-2]+"����������" );
}
