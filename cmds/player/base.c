// base.c for players by fire on 30/Jan/2000

#include <mudlib.h>
#define BASE_SERVER "/sgdomain/base/base_server/"
inherit CMD;

private void main(string arg)
{
	string p_area;
    array bases;
	string f_name;
	object ob;
	p_area=this_body()->query_room()->get_area();

	if(!AREA_D->area_exist(p_area)) {
		write("���ﲻ������������\n");
		return;
	}

	f_name=file_name(this_body()->query_room());
	if(f_name!=(AREA_D->get_area(p_area,"path")+AREA_D->get_area(p_area,"go"))) {
		write("ֻ�дӳ��ſڲ��ܽ����������ء�\n");
		return;
	}
	bases=AREA_D->get_area(p_area,"base");
	if(!sizeof(bases)) {
		write("������û���κ��������ء�\n");
		return;
	}
	if(sizeof(bases)>1) {
		if(member_array(arg,bases)==-1) {
			write("��Ҫ�����ĸ���������ѽ��\n");
			foreach(string b in bases) {
				write(BASE_D->get_base(b,"name")+"("+b+") " );
			}
			write("\n");
			write("�� base <id> �����ص���������ء�\n");
			return;
		}
	}
	else arg=bases[0];

	this_body()->simple_action("$N��"+BASE_D->get_base(arg,"name")+
		"ȥ�ˡ�\n");

     ob = load_object(BASE_SERVER+p_area+"/"+arg+"/enter");
	 if(objectp(ob)) {
			this_body()->move(ob);
	        this_body()->do_game_command("look");
			this_body()->other_action("$N������"+BASE_D->get_base(arg,"name"));
	 }
     return;
}

