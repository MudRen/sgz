#include <ansi.h>

mixed get_suggest(string n_id,string what);
mixed set_suggest(string n_id, string what, mixed val);
void discuss_suggest(string n_id);
void announce_suggest(string n_id);
void add_suggest(string n_id,string topic,mixed para,string who,string *areas);

mixed do_check_can_chanrang(string who)
{
	if( !wizardp(this_body()) ) 
		return "for wizard test only!\n";
        if( !mapp(COUNTRY_D->get_country(who)) )
                return "ֻ�й�������Ȩ�������ã�\n";
        else return 1;
}
mixed do_check_chanrang_para(string *para, string who)
{
	string newking;
	object ob;
	mapping tmp;

	if( !arrayp(para)||!sizeof(para)||sizeof(para)!=2 )
		return "����ĸ�ʽ��\n";
	if( !(newking=para[1])||!mapp(CHAR_D->get_char(newking,"")) )
		return "��Ҫ����λ���ø�˭��\n";
	if( !objectp(ob=find_body(newking)) )
		return CHAR_D->get_char(newking,"name")+"���ڲ������ϣ��޷����ø�����\n";
	if( ob->query_literate()<200 )
		return CHAR_D->get_char(newking,"name")+"��ѧ����̫�ͣ��������Ե��������ΰ���\n";
	if( CHAR_D->get_char(newking, "reputation")<50000 )
		return CHAR_D->get_char(newking,"name")+"�������㣬�������Է��ڰ���\n";
	if( CHAR_D->get_char_loyalty(newking,who)!=100 )
		return CHAR_D->get_char(newking,"name")+"�������Ĺ���֮�ˣ����ܰ���δ��Ĵ�ҵ��������\n";
	if( !mapp(tmp=CHAR_D->get_char(newking,"nc"))||tmp[who]<2000 )
		return CHAR_D->get_char(newking,"name")+"��δΪ�ҹ��д��ף����ܵ�������֮λ��\n";
	//Added by suicide for control can't chanrang to npc to avoid punish	
        if (CHAR_D->get_char(newking,"type")==TYPE_NPC)
            return CHAR_D->get_char(newking,"name")+"�Ǹ�NPC��������̫�����˰ɣ�\n";  
        
	set_suggest(who, "str", "�ѹ���֮λ���ø�"+CHAR_D->get_char(newking,"name"));
       	set_suggest(who,"reason","�²����ڣ��Ҿ���������԰֮��");

	add_suggest(who,"chanrang", ({newking}) , who, ({ }));

	announce_suggest(who);
        call_out("discuss_suggest",2,who);
}	
void do_chanrang(string n_id)
{
	string cc, *list, tmp, his, area;
	mapping data;

	cc = get_suggest(n_id,"para")[0];
	his= CHAR_D->get_char(n_id,"name")+"�ѹ���֮λ���ø�"+CHAR_D->get_char(cc,"name")+"��\n";
	area=CHAR_D->get_char(cc,"area");
	tell(users(), HIR+his+NOR);
 
        //Added by suicide for penalty king who chanrang 
        if (COUNTRY_D->get_country(n_id,"level")==1)
          {CHAR_D->set_char(n_id,"reputation",CHAR_D->get_char(n_id,"reputation")/4);
           CHAR_D->set_char(cc,"reputation",CHAR_D->get_char(cc,"reputation")*4);}
        else
          {CHAR_D->set_char(n_id,"reputation",CHAR_D->get_char(n_id,"reputation")/2);
           CHAR_D->set_char(cc,"reputation",CHAR_D->get_char(cc,"reputation")*2);}
        //added end �۹�������λ��3/4����,��Ϊ�ڶ����ͳƵ�ʱ��������,��������4��
        //          һ�������λ��1/2����,��Ϊ�ڶ���ʱ����һ��,��������2��.
        COUNTRY_D->add_country(cc, area);
	list = CHAR_D->check_char("nation", n_id);
	foreach(tmp in list)
		CHAR_D->set_char(tmp, "nation", cc);

	list = AREA_D->check_area("nation",n_id);
	foreach(tmp in list)
		AREA_D->set_area(tmp,"nation", cc);

	data = COUNTRY_D->get_country(n_id,"");
	COUNTRY_D->remove_country(n_id);
	foreach(tmp in keys(data))
		COUNTRY_D->set_country(cc, tmp, data[tmp]);

	CHAR_D->set_char(n_id, "ranknation", 0);
	

	// the old king commits suicide and remove his character.
 
	return;
}
