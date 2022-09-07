// written by yuner and fire 
/* Do not remove the headers from this file! see /USAGE for more info. */
inherit M_CHAR;
inherit LIVING;
inherit M_SMARTMOVE;
#define MARRY_GATE "/sgdomain/area/marriage/marry_gate"
#define PICPATH "/sgdomain/modules/m_charnpc/marriage/huajiao/"
string p_boy,p_girl;
string p_boyname,p_girlname;
string p_area;
string p_step;
int p_life;
static string *desc=({
        "�������Ľ����⿴ȥ��ȴʲôҲ���������\n",
        "�������������ӣ�һƬ����Ʈ�������ա�\n",
        "���ӻ����Ƶ����ߣ������Ҳ�������ڶ���\n",
        "�������ƿ���첼ͷ��һ������͵͵�������⿴��\n",
        "ϲ�����������Ž������ϡ��������ߺ�������\n",
        "����ڿ��Ұɡ������������������ﷺ��һ�����ۡ�\n",     
});
static string *chaois=({
    "һȺС�����Ż������ţ����ţ�Ҫ��ϲ�ǡ�\n",
    "�����ֵ�С�ŵΣ��Σ��գ��յĺò����֡�\n",
    "һ�˸ߺ�������Ц�ˣ����˺��ô�Ц��\n",
    "��������ž������������������һ����\n",
});
private string* pics=({});
void load_pic() {
	string *fs;
	string p;
	fs=get_dir(PICPATH+"*.pic");
	foreach(string f in fs) {
		p=read_file(PICPATH+f);
		pics+=({p});
	}
}
string show_pic(){
	return "\n�ĸ��η�̧��һ������\n"+
pics[random(sizeof(pics))]+
"һȺ�����ִ�����򣬺ò����֡�\n"+
"һ�������ܸɵĽη�ͷ(jiaofu tou)\n"; 

}
void setup()
{
    set_name("jiaofu tou", "�η�ͷ");
    set_gender(1);
    load_pic();
    set_in_room_desc((: show_pic :));

/*     set_in_room_desc("\n�ĸ��η�̧��һ������\n\n"+
"%^RED%^          __________________
          {|   ________   |}
          {|  [~~~~~~~~]  |}
          {|  [$$$$$$$$]  |}
          {|  [$$$$$$$$]  |}
  ==================================%^RESET%^\n\n"+
"һȺ�����ִ�����򣬺ò����֡�\n"+
"һ�������ܸɵĽη�ͷ(jiaofu tou)\n"); */
   set_max_capacity(VERY_LARGE*2) ;
    add_ask_str("xinren","$N��$TС������˭���ѽ����ô�ų���\n");
    add_question("xinren","xinren" );
	call_out("check",10);

}
void finish() {
	object *os;
	remove_call_out("check");
	this_object()->simple_action(
	"�ڽη�ʹ�����һ���ɢ��ȫ�뿪�ˡ�\n");
	os=this_object()->all_inventory();
	if(sizeof(os)) {
		foreach(object o in os) 
			o->move(environment(this_object()));
	}
	this_object()->remove();
}
void chaois() {
	string msg;
	msg=chaois[random(sizeof(chaois))];
	this_object()->simple_action(msg);
}
void go_boy_city() {
	string p_area;
	p_area=CHAR_D->get_char(p_boy,"area");

	this_object()->simple_action(
		"$N��������������ţ����ɹ�"+p_boyname+
		"��ס"+AREA_D->get_area(p_area,"name")+
		"�����ɹ�ֻҪһָʾ�������ϳ����ˡ�\n");
	this_object()->responda("tell "+p_boy+" ׼�����˾ͣ�%^RED%^ask jiaofu tou about qijiao%^RESET%^��\n");
	
}
void catch_girl() {
	object o_girl,o_boy;
	o_girl=find_body(p_girl);
	if(!objectp(o_girl)) return ; // impossible
	if(o_girl->query_room()!=this_object()->query_room()) {
		this_object()->simple_action(
		"$N��ֵص������������ģ�˭����������"+p_girlname+"�ˣ�������ȥ���ҡ�\n");
		return;
	}
	this_object()->targetted_action("$Nһָ$T���������������ǣ�����Ͻ�����������ˡ�\n",o_girl);
	o_girl->simple_action("������һӵ���ϣ���$N��ס��ͷ������һ��첼��һ�����������\n");
	o_girl->move(this_object());
	p_step="go_boy_city";	
	o_boy=find_body(p_boy);
	if(!objectp(o_boy)) return ; // impossible

   	o_boy->set_asklist("qijiao","target","jiaofu tou");
   	o_boy->set_asklist("qijiao","filename",file_name(this_object()));
   	o_boy->set_asklist("qijiao","funname","ask_qijiao");

}
void check() {
	object o_boy,o_girl;
	o_boy=find_body(p_boy);
	o_girl=find_body(p_girl);
	p_life++;
	remove_call_out("check");
	call_out("check",5+random(5));

	if(!objectp(o_boy)) {
		this_object()->simple_action(
		"$N��ֵص������ɹٲ����ˣ����������ǰ첻���ˣ�����ȥ�ɡ�\n");
		finish();
		return ;
	}
	if(!objectp(o_girl)) {
		this_object()->simple_action(
		"$N��ֵص��������Ӳ����ˣ����������ǰ첻���ˣ�����ȥ�ɡ�\n");
		finish();
		return;
	}
	switch (p_step) {
		case "catchgirl": 
			catch_girl();
			break;
		case "go_boy_city":
			go_boy_city();
			break;
		case "move_to_dongfang":
			chaois();
			break;

		default :
		this_object()->simple_action(
		"$N��ֵص���������Ҳ��֪���ø�ʲô�����������ǰ첻���ˣ�����ȥ�ɡ�\n");
		finish();

	}
}
int set_boygirl(string boy,string girl) {
	p_boy=boy,p_girl=girl;
	p_boyname=CHAR_D->get_char(p_boy,"name");
	p_girlname=CHAR_D->get_char(p_girl,"name");
	p_area=CHAR_D->get_char(p_boy,"area");
	p_step="catchgirl";
	p_life=1;
	remove_call_out("check");
	call_out("check",3);
	return 1;
}
string long() {
	return
"һ�������ܸɵĽη�ͷ�������������쵼��һֻ���׶��顣\n";
}

string get_arrival_msg()
{
  return "�������ֵ����׶��鿪�˹�����\n";
}
string get_departure_msg()
{
  return "�������ֵ����׶�����$o���˹�ȥ��\n";

}

string *get_player_message(string message, mixed arg) {
    string mess;
    if ( message == "leave" )
      {
    mess = get_departure_msg();
      }
    else if ( message == "enter" )
      {
    mess = get_arrival_msg();
      }
    return action( ({ this_object() }), mess, arg);
}

void do_looking(int forced_look)
{
	string msg;
	msg="���ڻ������������һ��Ҳ��������ֻ������һ����Ц���ͳ�������\n";
	msg+=desc[random(sizeof(desc))];
	write(msg);
}

void answer_move(object me,object o_boy,string dir) {
	string fn;
	this_object()->simple_action("$NЦ�����ã��ã����Ǿ���%^RED%^"+dir+"%^RESET%^�����ߡ�\n");
	this_object()->clear_answer();	
	this_object()->responda("go "+dir);
	fn=file_name(environment(this_object()));
	if(fn==MARRY_GATE) {
		object o_girl;
		this_object()->simple_action("$N�����е������ˣ�\n");
		o_girl=find_body(p_girl);
		o_girl->move(load_object(MARRY_GATE));
		o_girl->simple_action("$N�����˲�������˻��Ρ�\n");
		tell(users(),"%^H_RED%^�����񡿽η�ͷ�������Ѿ��͵���"+
		p_boyname+"��"+p_girlname+"�Ļ����Ҫ��ʼ�ˣ���Ҷ�����ѽ��\n");
		finish();
	}
}
void ask_move(object o_boy) {
       o_boy->targetted_action("$N��$TС������ʱ�������ˣ����ǿ��߰ɡ�\n",this_object());
        this_object()->simple_action("$N�����˵������������������ɹٵȲ����ˣ�����һ����ô�Ц��\n");
	this_object()->targetted_action("$N��$T��������Ҫ���Ǹ�������ѽ��\n",o_boy);
	this_object()->set_answer(p_boy, (:answer_move:) );
	return;
}
void ask_qijiao(object who) {
	object rom,gate;
	who->clear_asklist("qijiao");

       who->targetted_action("$N��$TС������׼�����ˣ������ɡ�\n",this_object());

	this_object()->simple_action("$N�ߺ�����Ρ�\n"+
	"�ڽη��ڴ����ֵĹ������У��ƺƵ�������"+
	AREA_D->get_area(p_area,"name")+"��ȥ��\n");

	gate=load_object(AREA_D->get_area(p_area,"path")+
		AREA_D->get_area(p_area,"go"));
	CHAR_D->appear("jiaofu tou",p_area,AREA_D->get_area(p_area,"go"),
		"$N����һֻ���׶�����һ��������У��ƺƵ����ؿ��˹�����\n");

	this_object()->move(gate);

	p_step="move_to_dongfang";
	
   	who->set_asklist("move","target","jiaofu tou");
   	who->set_asklist("move","filename",file_name(this_object()));
   	who->set_asklist("move","funname","ask_move");
	rom=load_object("/a/"+p_area+"/"+AREA_D->get_area(p_area,"meeting"));
	rom->add_exit("litang" , MARRY_GATE);
	rom=load_object(MARRY_GATE);
	rom->add_exit("out","/a/"+p_area+"/"+AREA_D->get_area(p_area,"meeting"));

	CHAR_D->add_char("li guan");
	CHAR_D->set_char("li guan","body","marriage/lg");
	CHAR_D->set_char("li guan","is_tmp",1);
	CHAR_D->appear("li guan",p_area,"meeting","$N���²��������˹�����\n");
	CHAR_D->find_char("li guan")->set_boygirl(p_boy,p_girl);
	CHAR_D->remove_char_d("li guan");

	CHAR_D->add_char("si yi");
	CHAR_D->set_char("si yi","body","marriage/sy");
	CHAR_D->set_char("si yi","is_tmp",1);
	CHAR_D->put_char("si yi","/sgdomain/area/marriage/marry_tang");
	CHAR_D->find_char("si yi")->set_boygirl(p_boy,p_girl);
	CHAR_D->remove_char_d("si yi");

}
void special_answer(object who, string matt)
{
	string p_id;
	p_id=who->query_primary_id();
        switch(matt)
        {
                case "xinren" :
			this_object()->targetted_action(
				"$N��$T���صص���$R��֪�������˴���������"+
				p_boyname+"��"+p_girlname+"ѽ��\n",who);
			return; 

        }
}

int query_light() {
	return 1;
}
int query_clean_up() {
	return (p_life<200); // if p_life<200 can't clean up
}
