// outdoor by fire
#include <hooks.h>
inherit DOOR;
string do_desc();

void later_set_up(string p_id,string dir) {
	tell_user("fire","dir is "+dir+"\n");
	setup_door(p_id,dir);
}
void setup(string p_id,string dir) {
	
	set_id("door", "����");

	setup_door(p_id,dir);

//	call_out("later_set_up",1,p_id,dir);
	set_locked("locked",p_id);

	set_in_room_desc((: do_desc :));
}
string do_desc() {
	if(stringp(query_locked()))
		return "���ű����������š�";
  	if (query_closed())
		return "���Ž����š�";
	return "���ų����š�";
}
mixed direct_lock_obj_with_obj(){
	if(stringp(query_locked()))
		return "�����Ѿ������ˡ�\n";
	if(!query_closed())
		return "��Ҫ�ȹ��ϲ�������\n";
	return 1;
}

mixed direct_unlock_obj_with_obj(object ob_d, object ob_k) {
	if(!stringp(query_locked()))
		return "����û����ѽ��\n";
	return 1;
}