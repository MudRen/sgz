// Cast.c for jimou
// By flee@sgz October 24 1999
#include <mudlib.h>
#include <daemons.h>

inherit CMD;
inherit M_GRAMMAR;

private void do_abandon(string sk, string ans);

private void main(string arg)
{
	if( !arg||!stringp(arg)||arg=="" )
		write("��Ҫ�������ּ��ܣ�\n");
	else if( arg=="sk_wuli"||arg=="sk_zhimou"||arg=="sk_meili" )
		write("���ܷ�������������\n");
	else if( member_array(arg, SG_SKILL_D->query_skills())==-1 )
		write("�����������ּ��ܣ�\n");
	else if( member_array(arg, this_body()->query_self_skills())==-1 )
		write("�㲢�������ּ��ܣ�\n");
	else 
		
		this_body()->modal_push( (: do_abandon, arg :), 
			"�����Ҫ����"+chinese_number(this_body()->query_sk_level(arg))
			+"����"+SG_SKILL_D->query_name(arg)+"��\n�����˵Ļ�������yes��\n");
	return;
}
private void do_abandon(string sk, string ans)
{
	mapping tmp;

	this_body()->modal_pop();

	if( !ans||!stringp(ans)||ans!="yes" ){
		write("�����������Ҫ���ؿ��ǡ�\n");
		return;
	};

	write("�������"+SG_SKILL_D->query_name(sk)+"��\n");

	this_body()->remove_sg_skill(sk);
	this_body()->save();
	
	tmp = CHAR_D->get_char(this_body()->query_primary_id(), "skills");
	if( !tmp||!mapp(tmp)||!sizeof(tmp) ) return;
	map_delete(tmp, sk);
	CHAR_D->set_char(this_body()->query_primary_id(), "skills", tmp);

	return;
}
