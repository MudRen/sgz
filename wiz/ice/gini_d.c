//gini_d.c by fire on June 22 1999
//Modilied by suicide on Aug 29 2000
inherit M_ACCESS;

inherit __DIR__+"gini_d/wiz";
#define SAVE_FILE "/data/daemons/gini"

private mapping msg;

private array hints;

private array faqs;

void save_data()
{
       unguarded(1, (: save_object, SAVE_FILE :));
}
void create()
{
    unguarded(1, (: restore_object, SAVE_FILE, 1 :));
    return;
}

mixed get_hint(int i) {
    if(!i)
	return hints[random(sizeof(hints))];
    if(i==-1)
	return hints;
    if(i>sizeof(hints)) return "�ܹ���"+sizeof(hints)+"����ʾ��\n";
    if(i<0) i=1;
        return hints[i-1];
       
}
mixed add_hint(string str) {
	hints-=({str});
	hints+=({str});
	save_data();
	return hints;
}
string remove_hint(int i) {
	string str;
	str=hints[i];
	hints-=({str});
	save_data();
	return str;
}

/*mixed add_faq(string question,function f) 
{       
	faqs-=({question});
	faqs+=({question});
	save_data();
	return faqs;    
}*/




mixed get_msg(string char,string typ,int n) {
    array tmp;
    if(!mapp(msg[char])){SGSYS("no gini type of "+char); return "û��������gini��\n"; }
    if(!sizeof(typ))
       return msg[char];
    tmp=msg[char][typ];
    if(!arrayp(tmp)) { SGSYS("no gini act of "+typ+" for gini "+char);
          return "û�������Ķ�����\n"; }
    if(!sizeof(tmp)) { SGSYS("no gini act of "+typ+" for gini "+char);
        return "$N��֪������ʲô�á�\n"; }
    if(!n)
       return tmp[random(sizeof(tmp))];
    if(n==-1) return tmp;
    return tmp[n-1];
}

mixed add_msg(string gin,string typ,string str) {
	if(!mapp(msg[gin])) return "no gini type of "+ gin+"\n";
	if(!arrayp(msg[gin][typ])) return "no act type of "+typ+"\n";
	msg[gin][typ]-=({str});
	msg[gin][typ]+=({str});
	save_data();
	return msg[gin][typ];
}

mixed rm_msg(string gin,string typ,int i) {
	string str;
	if(!mapp(msg[gin])) return "no gini type of "+ gin+"\n";
	if(!arrayp(msg[gin][typ])) return "no act type of "+typ+"\n";
	str=msg[gin][typ][i-1];
	msg[gin][typ]-=({str});
	save_data();
	return msg[gin][typ];
}

mixed add_typ(string gin,string typ) {
	if(!mapp(msg[gin])) return "no gini type of "+ gin+"\n";
	if(!arrayp(msg[gin][typ])) {
		msg[gin][typ]=({});
		save_data();
		 return "ok\n";
	}
	return "such type already exist\n";
}
mixed add_new_gini(string gin) {
	string *ks;
	if(!sizeof(gin)) return "�Ƿ�gini���͡�\n";
	if(mapp(msg[gin])) return "����gini�����Ѿ������ˡ�\n";
	msg[gin]=([]);
	ks=get_n_act();
	foreach(string k in ks) {
		msg[gin][k]=({});
	}
	save_data();
	return "��gini�������ӳɹ���\n";
}
void gini_birth(object oo) {
        string p_id,g_type;
        object o;
        g_type=oo->get_gini();
        if(!sizeof(g_type)){
           g_type="gini";
           oo->set_gini(g_type);
        }

        p_id=oo->query_primary_id();
        //p_id+=" gini";
        p_id+=" ";
        p_id+=g_type;
        //SUBUG(p_id);
        CHAR_D->add_char(p_id);
        CHAR_D->set_char(p_id,"name",get_msg(g_type,"name",0));
        CHAR_D->set_char(p_id,"is_tmp",1);
        CHAR_D->set_char(p_id,"body","gini");
        CHAR_D->set_char(p_id,"master",oo->query_primary_id());
        CHAR_D->set_char(p_id,"g_type",g_type);
        CHAR_D->set_char(p_id,"type",0);
	CHAR_D->set_char(p_id,"gender",to_int(get_msg(g_type,"gender",0)));
        CHAR_D->put_char(p_id,file_name(oo->query_room()));
        o=CHAR_D->find_char(p_id);
        o->my_birth();
}
void play_get_gini(string p)
{
    object o=find_body(p);
    object os;
    if(!objectp(o)) return;
    os=present("gini lamp",o);
    if(objectp(os)) return;
    gini_birth(o);
}
void play_enter(string p) {
     call_out("play_get_gini",10,p);
}



// this is the main part to ask a gini to do sth
// gini is the first sub, the player is the second
// GE gini emote GM gini to master semote
// ME master emote MG master to gini semote
// GS gini say GT gini tell
void gini_act(string p_id,string typ) {
	string g_id,g_typ,act;
	object o_gini,o_ply;
	string p_t;
	//g_id=p_id+" gini";
	g_id=p_id+" "+this_body()->get_gini();
	o_gini=CHAR_D->find_char(g_id);
	o_ply=find_body(p_id);
	if(!objectp(o_gini)) return;
	if(!objectp(o_ply)) return;
	g_typ=CHAR_D->get_char(g_id,"g_type");
	act=get_msg(g_typ, typ,0);
	p_t=act[0..1];
	switch(p_t) {
	case "GE" :  // gini emote
		o_gini->responda(act[2..<1]);
		return ;  // self semote
	case "GM" :  // gini emote to master
		o_gini->responda(act[2..<1]+" "+p_id); // to his master
		return ;
	case "GA" :  // master act
		if(act[<1]!='\n') act+="\n";
		o_gini->targetted_action(act[2..<1],o_ply);
		return ;
	case "ME" :  // master emote
		o_ply->responda(act[2..<1]);
		return ;  // self semote
	case "MG" :  // master emote to gini
		o_ply->responda(act[2..<1]+" "+g_id);
		return ;  // self semote
	case "MA" :  // master act
		if(act[<1]!='\n') act+="\n";
		o_ply->targetted_action(act[2..<1],o_gini);
		return ;
	case "GS" :  // gini say
		o_gini->responda("say "+act[2..<1]);
		return ;
	case "GT" : // gini tell
		o_gini->responda("tell "+p_id+" "+act[2..<1]);
		return ;
	default :
		if(act[<1]!='\n') act+="\n";
		//act = "this is a \ntest\n";
		//tell_user("suicide",sprintf("[%O]\n",act));
		
		o_ply->targetted_action(act,o_gini);
		return ;
	}
}
int gini_exist(string g) {
	return (mapp(msg[g]));
}
string gini_list() {
	string ret="����      ����\n";
	string *gs;
	gs=keys(msg);
	foreach(string g in gs) {
		ret+=g;
		ret+="      "+get_msg(g,"name",0);
		ret+="\n";
	}
	return ret;
}
string what_can_do() {
return "
%^H_BLUE%^gini              %^RESET%^          �ٻ��ҵĵ�����
%^H_BLUE%^gini do%^H_RED%^ some thing%^RESET%^          ������һЩ�¡�
%^H_BLUE%^gini return       %^RESET%^          �Ҿͻ��Ȳ�������
%^H_BLUE%^gini faq%^H_RED%^  thing%^RESET%^             ����ѯ���й�����İ�����
%^H_BLUE%^gini old          %^RESET%^          �Ҿͻ��Ҹ������������㡣
%^H_BLUE%^gini wiz          %^RESET%^          ��ʦָ���
%^H_BLUE%^gini help         %^RESET%^          giniָ���ʹ�÷�����顣

���磺%^H_CYAN%^gini do hi %^RESET%^             �Ҿͻ�Ϲ���
���磺%^H_CYAN%^gini faq Ǯ %^RESET%^            ����ѯ���й�Ǯ������
";
}
string wiz_can_do() {
return 
"
-------------------JINI ����ָ��---------------------------------
%^H_BLUE%^gini add %^H_RED%^some thing%^RESET%^�� �����µ�gini���͡�
%^H_BLUE%^gini list         %^RESET%^    ���������б�
%^H_BLUE%^gini change%^H_RED%^ type  %^RESET%^    ������������
---------------------��������------------------------------------
%^H_BLUE%^gini check%^RESET%^��            gini�����鿴��
%^H_BLUE%^gini addact%^RESET%^��           ���Ӷ�����
%^H_BLUE%^gini rmact%^RESET%^��            ɾ��������
%^H_BLUE%^gini actrule%^RESET%^��          �������͡�
---------------------��ʾ����------------------------------------
%^H_BLUE%^gini hintlist%^RESET%^��         �б���ʾ����
%^H_BLUE%^gini addhint%^RESET%^��          ������ʾ��
%^H_BLUE%^gini rmhint%^RESET%^��           ɾ����ʾ��
---------------------�������------------------------------------
%^H_BLUE%^gini qlist%^RESET%^��            �б����⼯��
%^H_BLUE%^gini addq%^RESET%^��             �������⡣
%^H_BLUE%^gini rmq%^RESET%^��              ɾ�����⡣

";
}
