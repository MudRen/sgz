#include <ansi.h>

mixed get_suggest(string n_id,string what);
mixed set_suggest(string n_id, string what, mixed val);
void discuss_suggest(string n_id);
void announce_suggest(string n_id);
void add_suggest(string n_id,string topic,mixed para,string who,string *areas);

mixed do_check_can_friend(string who)
{
	if( !wizardp(this_body()) )
		return "for test only!\n";
        if( !mapp(COUNTRY_D->get_country(who)) )
                return "ֻ�й�������Ȩ�������\n";
        else return 1;
}
mixed do_check_friend_para(string *para, string who)
{
	int time;
	string cc;
	
	if( sizeof(para)!=3||!stringp(cc=para[1])||!stringp(para[2]) ) 
		return "����ĸ�ʽ��\n";
	time = to_int(para[2]);
	if( !mapp(COUNTRY_D->get_country(cc)) )
		return "û��������ң�\n";
	if( cc == who )
		return "����������Լ����˰ɣ�";
	if( COUNTRY_D->is_friend(who, cc) )
		return "�����Ѿ������ѹ�ϵ�ˣ�\n";
	if( time<=0 )
		return "����ʱ�䲻�����Ǹ����ɣ�\n";
	if( time>15 )
		return "�����Լ��ʮ���졣";

	set_suggest(who, "str", "��"+COUNTRY_D->get_country(cc,"name")+"�������");
        set_suggest(who,"reason","�����Ǵ�ɹ���ͳһ�Ľݾ�");

	add_suggest(who,"friend", ({cc, time}), who, ({ }));

	announce_suggest(who);
        call_out("discuss_suggest",2,who);
        return 1;
}	
void do_friend(string n_id)
{
	int time;
	string his, cc;
	
	cc = get_suggest(n_id, "para")[0];
	time = get_suggest(n_id, "para")[1];
	his = HIC+COUNTRY_D->get_country(n_id,"name")+"��"
		+COUNTRY_D->get_country(cc,"name")+"��ȥ��һ�����"+
		chinese_number(time)+"���Э���飡\n\n"+NOR;
	tell(users(), his );

	if( mapp(get_suggest(cc,0))&&sizeof(get_suggest(cc,0)) ){
		his = COUNTRY_D->get_country(cc,"name")+"�������۾������£����˵��±������ˣ�\n";
		tell(users(), his );
		return;
	}
	add_suggest(cc,"answer_friend", ({n_id, time}), 0, ({ }));
	set_suggest(cc, "str", "ͬ"+COUNTRY_D->get_country(n_id,"name")+"����"+chinese_number(time)+"��");
	set_suggest(cc,"reason",COUNTRY_D->get_country(n_id,"name")+"���ҹ�����˽��˵�����");
	announce_suggest(cc);
        call_out("discuss_suggest",2,cc);

        return;
}
void do_answer_friend(string n_id)
{
	int time;
	string cc, his;
	mapping ff;

	cc = get_suggest(n_id, "para")[0];
        time = get_suggest(n_id, "para")[1];
	his = COUNTRY_D->get_country(n_id,"name")+"��"+COUNTRY_D->get_country(cc,"name")+
		"����˽���"+chinese_number(time)+"���Э�飡";
	tell(users(), HIR+his+NOR);

	ff = COUNTRY_D->get_country(n_id,"friends");
	if( !mapp(ff)||!sizeof(ff) ) ff = ([ ]);
	ff[cc] = time()+time*86400;
	COUNTRY_D->set_country(n_id,"friends", ff);

	return;
}
