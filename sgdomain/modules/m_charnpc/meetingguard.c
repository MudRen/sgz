// by fire on june 2000
inherit M_CHAR;
inherit LIVING;
inherit M_BLOCKEXITS;
string p_area,p_nation,p_dir,p_room;
int task_id;
static string *chaois=({
    "һȺС���ڷ��������ţ����ţ�Ҫ��ϲ�ǡ�\n",
    "һ����ʦ�����š��ε����ա��Ĵ��úò����֡�\n",
    "һ�˸ߺ�������Ц�ˣ����˺��ô�Ц��\n",
    "�ܶ��˼����ſڣ��뿴��������\n",
    "������һ������ģ�����ϲ���ô��ֽ���š�\n",
    "һ���ʷ����������������̣�����ž���ؼ������������������˵��춼�ϲ�£��\n",
    "����ƹƹ���ҡ��������ͣ������ȹ��껹���֡�\n",
    "$N��ͷ�������Խ���������������¾���\n",
    "$N�������ı��͵�����ʲô����ͽ����Ұɡ�\n",

});

private mixed handle_blocks( string dir )
{
        string p_id;

		if(dir!=p_dir) return 0;
	p_id=this_body()->query_primary_id();
	if(CHAR_D->get_char(p_id,"nation")==p_nation) {
		this_object()->targetted_action(
		"$N��$T�Ϲ�����$m$R�������롣\n",this_body());
		return 0;
	}
        return ::handle_blocks(dir);    
}

void setup()
{
    set_name("guard", "����");
	add_id("meeting guard");
    set_gender(1);
    set_in_room_desc("\nһ��ȫ����װ��%^H_RED%^����%^RESET%^(guard)\n");

    call_out("check",5);

    set_block_action( "$N��Ǻॡ�һ���γ��ֵ���ָ��$T�����ȵ�����$r������ǰ����̽���顣\n");
}

string long() {
	return
"һ��ȫ����װ��%^H_RED%^����%^RESET%^\n";
}

void finish() {
	remove_call_out("check");	
	this_object()->simple_action("$N�뿪�ˡ�\n");	
	this_object()->remove();
}
void chaois() {
	string msg;
	msg=chaois[random(sizeof(chaois))];
	this_object()->simple_action(msg);
}

void check() {
	remove_call_out("check");
	call_out("check",5+random(5));
	if(!mapp(TASK_D->get_task(task_id))) {
		finish();
		return;
	}
//	chaois();
}
int set_position(string area,int task,string room,string dir) {
	string meetroom;
	p_area=area;
	p_nation=AREA_D->get_area(p_area,"nation");
	p_room=room;
	p_dir=dir;
	task_id=task;

    add_block(p_dir);
	
	remove_call_out("check");
	call_out("check",3);
	return 1;
}
int is_meetingguard() {
	return 1;
}
int query_clean_up() {
	return 1; // if p_life<200 can't clean up
}

