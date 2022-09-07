//gini_d.c by fire on June 22 1999
private mapping msg=
([
   "gini" : ([
"birth" : ({
"ͻȻð��һ��%^BLUE%^����%^RESET%^�������У�һ��$T�ݸ�$Nһյ��ƣ�˵����\n������ı����񣬵�����Ҫ��ʱ��ֻҪ���� gini �Ҿͻ�����㡣\n",
}),
"call" : ({
"$N�ӻ����ͳ�һյ��������ƣ������Ӳ��˲�. . . . \nһ��%^BLUE%^����%^RESET%^�ӵ���ð���������ػ���һ����ɫ��־��顣\n",
}),
"come" : ({
"$Nһ����ƣ�$T��æ��Զ��Ʈ����\n",
}),
"go" : ({
"$T��æ��Զ��Ʈ������$N�������ϵ���һ�¡�\n",
}),

"ask" : ({
"$T��$N���˸�������$R�кηԸ���\n",
}),
"disappear" : ({
"$N����һ��%^BLUE%^����%^BLUE^%����������ʧ�ˡ�\n",
}),
"return" : ({
"$N�������ҡ��ҡ��$T����һ�����̣���ص��С�\n",
}),
"readhint" : ({
"$Tҡ��һ�䣬��������ģ�����ֱֳ��飬һ�������ض�$N���\n",
}),

]), // end of gini

]);


private array hints=({
"��ʿʤ�����䣻��ʿʤ�����ǣ���ʿʤ���ڵ¡�\n",
"������ͬ������MUD��ֻ��ͷ���������������������ͨ�챾�죬Ҳ�ѳɴ�ҵ��\n",
"���ж��ݺ����£���һ���ܾ������£����Ǵ�ã�\n�������ܵ�֮�������Ը�֮��Ҳ������һ����\n",
"ǧ���׵ã�һ����Ѱ���ҵ�һ������ȫ�ţ����Ĺ����Ĵ󽫣������������ѡ�\n",
"���˹�֮�����������в���ʧҲ��\n",
"��ʼ������࣬����н���������¾��տ�ͼҲ��\n",
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
           return "��ֻʲô������\n";
    }
}
string get_long(string char) {
    switch (char) {
        case "gini":
           return "һ��%^BLUE%^��ɫ����%^RESET%^��Ʈ�ڿ��У����ϵ����Ź�����\n";
        default :
           return "��ֻʲô������\n";
    }
}
string get_name(string char) {
    switch (char) {
        case "gini":
           return "��ɫ����";
        default :
           return "��ֻʲô������\n";
    }
}


string get_lamp_id(string my_type) {
    switch (my_type) {
        case "gini":
           return "lamp";
        default :
           return "��ֻʲô������\n";
    }
}
string get_lamp_name(string my_type) {
    switch (my_type) {
        case "gini":
           return "���������";
        default :
           return "��ֻʲô������\n";
    }
}

string get_lamp_unit(string my_type) {
    switch (my_type) {
        case "gini":
           return "յ";
        default :
           return "��ֻʲô������\n";
    }
}

string get_lamp_long(string my_type) {
    switch (my_type) {
        case "gini":
           return "һյ����ħ���İ�������Ҫʹ�þ����룺gini\n";
        default :
           return "��ֻʲô������\n";
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
	if(CHAR_D->char_exist(p_id)) {
		o=CHAR_D->find_char(p_id);
		if(!objectp(o)){CHAR_D->remove_char(p_id); return; }
		o->my_come();
	}
	else {
		CHAR_D->add_char(p_id);
		CHAR_D->set_char(p_id,"name",get_name(g_type));
		CHAR_D->set_char(p_id,"is_tmp",1);
		CHAR_D->set_char(p_id,"body","gini");
		CHAR_D->set_char(p_id,"master",oo->query_primary_id());
		CHAR_D->set_char(p_id,"type",g_type);
		CHAR_D->put_char(p_id,file_name(oo->query_room()));
		o=CHAR_D->find_char(p_id);
		o->my_birth();
	}
}
void check_gini() {
    object *os,lmp;
    call_out("check_gini",30);
    os=users()->query_body();
    if(sizeof(os)) {
        foreach(object o in os) {
	   if(objectp(o)) {
               lmp=present("gini lamp",o);
               if(!objectp(lmp)) gini_birth(o);
           }
        }
    }
}
void create() {
   check_gini();
}