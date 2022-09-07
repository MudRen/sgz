inherit OUTDOOR_ROOM;
inherit __DIR__+"base";
string get_long();
void base_init() {
	object o_h=get_master();
	object o_leader;
	string p_id=o_h->get_leader();
	set_brief(AREA_D->get_area(p_area,"name")+BASE_D->get_base(f_id,"name"));
	set_long(get_long());
	set_area(p_area);
	if(CHAR_D->char_exist(p_id)) {
		o_leader=new(PBASE+"npc/leader",p_area,f_id);
		if(objectp(o_leader))
			o_leader->move(this_object());
	}

}
string get_long() {
	object oh;
	string ret=get_base_room_long();
	string ext;
	int level;
/*	oh=get_master();
	level=oh->get_level();
	switch(level) {
	case 1:
		ext= "  ����һ���½���ũ������Χ��û�п�����������ء�\n\n";
		break;
	case 2:
		ext= "  һ��СС��ũ������Χ�м�Ƭũ�\n\n";
		break;
	case 3:
		ext= "  һ����ũ������Χ�����������Ұ��\n\n";
		break;
	default:
		ext="һ���޴��ޱȵ�ũ����������ȥ����Χ�����һ���޼̡�\n\n";
	}
	return ret+"\n"+ext;
*/
	if(!sizeof(ret)) ret=" \n";
	return ret;
}