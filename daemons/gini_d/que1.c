//que1.c by fire on June 22 1999
private mapping msg=
([
   "gini" : ([
"call_old_player" : ({
"$Nһָ$T����ι����ƣ������Ҹ�������ָ��ָ�㡣\n",
}),
"busy" : ({
"$T��$N�������ˣ�����һ������û����ء�\n",
}),
"noneed" : ({
"$T��$N�������ˣ����С�£������Ұ���Ҳ���԰쵽ѽ��\n",
}),
"toosoon" : ({
"$T��$N�������ˣ���ʩ���˷�����������û�ָ�ѽ��\n",
}),
"nooldplyer" : ({ 
"$T�ͳ���Զ����������һͨ�������ˣ����ʵĸ����Ҳ���ѽ��\n",
}),
"magic" : ({
"$T�ͳ�һ��ˮ���򣬿��л�����һЩ�����������ˮ������ɫԽ��Խ�ͻȻð��һ�����⡣\n",
}),
"birth" : ({
"ͻȻð��һ��%^BLUE%^����%^RESET%^�������У�һ��$T�ݸ�$Nһյ��ƣ�˵����\n������ı����񣬵�����Ҫ��ʱ��ֻҪ���� gini �Ҿͻ�����㡣\n���㲻��Ҫ���ˣ����� gini return���Ҿͻ���ʧ��\n",
}),
"call" : ({
"$N�ӻ����ͳ�һյ��������ƣ������Ӳ��˲�. . . . \nһ��%^BLUE%^����%^RESET%^�ӵ���ð���������ػ���һ����ɫ��־��顣\n",
"GTbow",
}),
"come" : ({
"$Nһ����ƣ�$T��æ��Զ��Ʈ����\n",
"GS���ˣ��кηԸ���",
"$T��$N���˸�������$R�кηԸ���\n",
}),
"go" : ({
"$T��æ��Զ��Ʈ������$N�������ϵ���һ�¡�\n",
"GS������������",
}),

"ask" : ({
"$N��$T����gini���㶼�ܸ�ʲô�أ�\n",
"$N��$T����gini�����ҿ�����ı��°ɡ�\n",
}),
"disappear" : ({
"$N����һ��%^BLUE%^����%^RESET%^����������ʧ�ˡ�\n",
}),
"return" : ({
"$N�������ҡ��ҡ��$T����һ�����̣���ص��С�\n",
}),
"readhint" : ({
"$Tҡ��һ�䣬��������ģ�����ֱֳ��飬һ�������ض�$N���\n",
}),
"do" : ({
"$N��$Tʹ�˸���ɫ��\n",
"$N��$T�����ֹ���Щʲô��\n",
"$N�������µؿ���$Tһ�ۡ�\n",
}),
"know" : ({
"$T�����ҵı��¿ɴ��ˡ�\n",
"GS�ҵ�����Ϸ�ɶ��ˡ�",
}),
"random" : ({
"GEface","GMack","GS�ܾúܾ���ǰ����һ�����������꣬�������־ͽУ����� . �� . �� . �� . . . .��",
"GMbow",
"GT���ˣ��㻹����","MEhehe","MGpat","MA$N��һ������ס�ڡ�\n",
"$TͻȻ���һ��ħ���ſ���һ�ڰ�$N������ȥ��\n",
}),

]), // end of gini

]);


private array hints=({
"��ʿʤ�����䣻��ʿʤ�����ǣ���ʿʤ���ڵ¡�\n",
"������ͬ������MUD��ֻ��ͷ���������������������ͨ�챾�죬Ҳ�ѳɴ�ҵ��\n",
"���ж��ݺ����£��������ܾ������£����Ǵ�ã�\n���ܵ��������Ը�֮��Ҳ������һ����\n",
"ǧ���׵ã�һ�������ҵ�һ������˫ȫ�����Ĺ����Ĵ󽫣������������ѡ�\n",
"���˹�֮�����������ۣ��า�ۣ��������в���ʧҲ��\n",
"��ʼ������࣬����н�����������տ�ͼҲ��\n",
"����������ƶ�������ƣ��������ɷ�Ҳ��\n",
});
string get_hint() {
    return hints[random(sizeof(hints))];
}
string get_msg(string char,string typ) {
    array tmp;
    if(!mapp(msg[char])) return "$N��֪������ʲô�á�\n";
    tmp=msg[char][typ];
    if(!arrayp(tmp)) return "$N��֪������ʲô�á�\n";
    return tmp[random(sizeof(tmp))];
}
string get_title(string char){
    switch (char) {
        case "gini":
           return "%^BLUE%^��ɫ����%^RESET%^(gini)";
        default :
           return "��֪����ʲô������\n";
    }
}
string get_long(string char) {
    switch (char) {
        case "gini":
           return "һ��%^BLUE%^��ɫ����%^RESET%^��Ʈ�ڿ��У����ϵ����Ź�����\n";
        default :
           return "��֪����ʲô������\n";
    }
}
string get_name(string char) {
    switch (char) {
        case "gini":
           return "��ɫ����";
        default :
           return "��֪����ʲô������\n";
    }
}


string get_lamp_id(string my_type) {
    switch (my_type) {
        case "gini":
           return "lamp";
        default :
           return "��֪����ʲô������\n";
    }
}
string get_lamp_name(string my_type) {
    switch (my_type) {
        case "gini":
           return "���������";
        default :
           return "��֪����ʲô������\n";
    }
}
string get_lamp_unit(string my_type) {
    switch (my_type) {
        case "gini":
           return "յ";
        default :
           return "��֪����ʲô������\n";
    }
}

string get_lamp_long(string my_type) {
    switch (my_type) {
        case "gini":
           return "һյ����ħ���İ�������ƣ�Ҫʹ�þ����룺gini\n";
        default :
           return "��֪����ʲô������\n";
    }
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
        p_id+=" gini";

        CHAR_D->add_char(p_id);
        CHAR_D->set_char(p_id,"name",get_name(g_type));
        CHAR_D->set_char(p_id,"is_tmp",1);
        CHAR_D->set_char(p_id,"body","gini");
        CHAR_D->set_char(p_id,"master",oo->query_primary_id());
        CHAR_D->set_char(p_id,"g_type",g_type);
        CHAR_D->set_char(p_id,"type",0);
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

void check_gini() {
/*    object *os,lmp;
    call_out("check_gini",30);
    os=users()->query_body();
    if(sizeof(os)) {
        foreach(object o in os) {
           if(objectp(o)) {
               lmp=present("gini lamp",o);
               if(!objectp(lmp)) gini_birth(o);
           }
        }
    } */
}
void create() {
   check_gini();
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
	g_id=p_id+" gini";
	o_gini=CHAR_D->find_char(g_id);
	o_ply=find_body(p_id);
	if(!objectp(o_gini)) return;
	if(!objectp(o_ply)) return;
	g_typ=CHAR_D->get_char(g_id,"g_type");
	act=get_msg(g_typ, typ);
	p_t=act[0..1];
	switch(p_t) {
	case "GE" :  // gini emote
		o_gini->responda(act[2..<1]);
		return ;  // self semote
	case "GM" :  // gini emote to master
		o_gini->responda(act[2..<1]+" "+p_id); // to his master
		return ;
	case "GA" :  // master act
		o_gini->targetted_action(act[2..<1],o_ply);
		return ;

	case "ME" :  // master emote
		o_ply->responda(act[2..<1]);
		return ;  // self semote
	case "MG" :  // master emote to gini
		o_ply->responda(act[2..<1]+" "+g_id);
		return ;  // self semote
	case "MA" :  // master act
		o_ply->targetted_action(act[2..<1],o_gini);
		return ;
	case "GS" :  // gini say
		o_gini->responda("say "+act[2..<1]);
		return ;
	case "GT" : // gini tell
		o_gini->responda("tell "+p_id+" "+act[2..<1]);
		return ;
	default :
		o_ply->targetted_action(act,o_gini);
		return ;
	}
}
string what_can_do() {
return 
"%^H_BLUE%^gini%^RESET%^��               �ٻ��ҵĵ�����
%^H_BLUE%^gini do %^H_RED%^some thing%^RESET%^�� ������һЩ�¡�
  ���磺%^H_GREEN%^gini do hi %^RESET%^  �Ҿͻ�Ϲ���
%^H_BLUE%^gini return%^RESET%^��        �Ҿͻ��Ȳ�������
%^H_BLUE%^gini old%^RESET%^��           �Ҿͻ��Ҹ������������㡣

";
}
