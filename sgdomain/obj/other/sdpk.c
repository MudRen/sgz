// sdpk.c ɿ������
inherit OBJ;
inherit M_GETTABLE;
string m_area;
string m_roomname;
int m_life;
void setup()
{   
    set_id("bugao", "%^YELLOW%^����%^RESET%^");
    set_size(VERY_SMALL);
    set_gettable(1);
    set_in_room_desc("ǽ������һ��%^YELLOW%^����%^RESET%^��\n");   
}
string long() {
	if(!AREA_D->area_exist(m_area)) {
		remove();
		return "";
	}
	return "һ��ɿ��"+AREA_D->get_area(m_area,"name")+
          "����Ĳ��档\n";
}
void set_area(string area) {
	m_area=area;
}
void set_roomname(string r) {
	m_roomname=r;
}
mixed query_can_drop() {
	object rom;
	rom=this_body()->query_room();
	if(!AREA_D->area_exist(m_area)) {
		remove();
		return 0;
	}
	if(rom->get_area()!=m_area) 
		return "���Ų���Ҫ����"+AREA_D->get_area(m_area,"name")+"��\n";
	if(rom->short()!=m_roomname) 
		return "���Ų���Ҫ����"+m_roomname+"��\n";
	return 1;
}
void my_life() {
	object env;
	int safe;
	if(random(m_life)>2) {
		remove();
		return;
	}
	m_life++;
	env=environment(this_object());
	if((env->short()!=m_roomname)||(env->get_area()!=m_area)) {
		remove();
		return;
	}
	call_out("my_life",random(60)+60);
	safe=AREA_D->get_area(m_area,"safe");
	switch(random(4)) {
		case 0:
			CHANNEL_D->deliver_tell("rumor","system", 
			AREA_D->get_area(m_area,"name")+"����ɿ���Բ��棬���Ҿ���û��Ӱ�졣");
			return;

		case 1:
			safe++; 
			AREA_D->set_area(m_area,"safe",safe);
			CHANNEL_D->deliver_tell("rumor","system", AREA_D->get_area(m_area,"name")+
			"����ɿ���Բ��棬����������ı�����ذ�������ˣ�");
			return;
		case 2:
			safe-=2; safe=bmax(0,safe);
			AREA_D->set_area(m_area,"safe",safe);
			CHANNEL_D->deliver_tell("rumor","system", 
  AREA_D->get_area(m_area,"name")+"����ɿ���Բ��棬�������۷׷ף����ذ����½��ˡ�");
			return;

		default :
			safe--; safe=bmax(0,safe);
			AREA_D->set_area(m_area,"safe",safe);
			CHANNEL_D->deliver_tell("rumor","system", 
AREA_D->get_area(m_area,"name")+"����ɿ���Բ��棬�������۷׷ף����ذ����½��ˡ�");
			return;
	}
}
mixed drop() {
	string m_id;
	string nat;
	int loy;

       this_body()->other_action(
		"$N��������û�ˣ��������شӻ����ͳ��Ų��棬����ǽ�ϡ�\n");
	this_object()->move(this_body()->query_room());
	m_life=0;
        call_out("my_life",5);
	this_body()->start_busy(20,"��������æ���ء�\n");
//	call_out("drop_bugao",20);
	this_body()->set_job("bugao","status","done");
	m_id=this_body()->query_primary_id();

	nat=AREA_D->get_area(m_area,"nation");

	loy=CHAR_D->get_char_loyalty(m_id,nat);
	loy--; loy=bmax(1,loy);
	CHAR_D->set_char_loyalty(m_id,nat,loy);


        CHAR_D->set_char(m_id,"catch_time",time()+30);
        CHAR_D->set_char(m_id,"catch_file",PJOB+"bugao/bugao");
        CHAR_D->set_char(m_id,"catch_function","bugao_catch");
        CHAR_D->set_char(m_id,"catch_para",this_object());
        CHAR_D->set_char(m_id,"catch_area",m_area);

	CHANNEL_D->deliver_tell("rumor","system", 
		this_body()->query_chinese_id()+"��"+AREA_D->get_area(m_area,"name")+"����ɿ���Բ��档");
       return "��Ѳ�������ǽ�ϡ�\n";
}

/*void disapp() {
	remove();
}*/
mixed get() {
	string nat,id;
	nat=AREA_D->get_area(m_area,"nation"); 
	id=this_body()->query_primary_id();
	if(CHAR_D->get_char(id,"nation")!=nat)
		return "�������£������ٹܡ�\n";
	this_body()->simple_action(
		"$Nһ�ѽ������ǽ��˺�����������һ�š�\n");
	CHAR_D->set_char(id,"loyalty",CHAR_D->get_char(id,"loyalty")+1);
	remove();
//	call_out("disapp",1);
	return "����ҳ�����ˡ�\n";
}
/*void drop_bugao()
{
	this_object()->move(this_body()->query_room());
	this_body()->set_job("bugao","status","done");
	return;
}*/
