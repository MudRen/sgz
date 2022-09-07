//wiz.c by fire on July 5 1999
private mapping m_act=
([ 
  "long" : "������������lookʱ��",
  "toosoon" : "���߲����ڶ�ʱ������gini�ظ�ĳ�����顣",
  "ask" : "�ٻ�giniʱ��gini�����",
  "name" : "gini�����֡�",
  "title" : "�ڷ����е�������",
  "go" : "gini�ӱ𴦻ص�������ߡ�",
  "disappear" : 
    "�����뿪��ʱ���Զ���ʧ����giniΪ�����simple_act,\n"+
     "������act���������������Ķ��岻ͬ��",
  "come" : "��gini�ӱ�ķ���������",
  "random" : "gini���������",
  "birth" : "gini���������������ʱ��",
  "return" : "��gini��ʧ��",
  "call_old_player" : "��gini������Ұ�����",
  "nooldplyer" : "�Ҳ������֡�",
  "call" : "�ٻ�gini",
  "noneed" : "��ҵȼ�̫�ߣ�gini��Ը�������",
  "magic" : "gini ʩ����",
  "readhint" : "gini ����ʾ hint",
  "do" :  "��giniִ��ָ�",
  "know" : "�ٻ�gini�Ļش�",
  "busy" : "gini����ִ��һ�����񣬲��ܽ�����һ������",

  "lamp_id" : "�ٻ�gini�����id",
  "lamp_long" : "�ٻ�gini�����������",
  "lamp_unit" : "�ٻ�gini����ĵ�λ��",
  "lamp_name" : "�ٻ�gini��������ơ�",
  "gender" : "gini���Ա�1 �У�2 Ů",
]) ;

string *get_n_act() {
	return keys(m_act);
}

mixed do_gini_check(string typ) {
	string *r_keys,*n_keys;
	string ret,*ks;
	mixed acts;
	acts=GINI_D->get_msg(typ);
	if(!mapp(acts)) return acts;
	r_keys=keys(acts);
	n_keys=keys(m_act);
	ret="gini ���ͣ�"+typ+"\n";
	ret="---------------------------------------------------\n";
	if(!sizeof(r_keys)) ret+= "��û�ж����κζ�����\n";
	else
	foreach(string k in r_keys) {
		ret+="�ؼ��֣�%^H_GREEN%^"+k+"%^RESET%^";
		ret+="  ���ͣ�%^H_RED%^"+m_act[k]+"%^RESET%^\n";
		ks=acts[k];
		if(!sizeof(ks)) {
			ret+="   ��û�ж��塣\n";
			continue; 
		}
		foreach(string s in ks) {
			if(s[<1]!='\n') s+="\n";
			ret+="   "+s;
		}
	}
	n_keys-=r_keys;
	if(sizeof(n_keys)) {
		ret+="%^H_RED%^�������¶���û�ж��塣%^H_RED%^\n";
		ret+=
		"----------------------------------------------\n";
		foreach(string k in n_keys) {
			ret+="�ؼ��֣�%^H_GREEN%^"+k+"%^RESET%^";
			ret+="  ���ͣ�%^H_RED%^"+m_act[k]+"%^RESET%^\n";
			ret+="  ���ӣ�"+GINI_D->get_msg("gini",k);
			if(ret[<1]!='\n') ret+="\n";
		}
	}
	return ret;
}

string act_rule() {
	string ret;
	ret=
"gini�����淶���ͣ�
һ��gini�Ķ������������֣���һ������%^H_RED%^����ĸ��˵����
%^RESET%^�ڶ�������%^H_RED%^����Ķ���%^RESET%^��˵�����������¹淶��
1 %^H_BLUE%^GE%^RESET%^��gini��emote��
   ���磺%^H_GREEN%^GEhi%^RESET%^  ��gini��%^RED%^��ɫ���鳤Ҿ���أ���������С����ɫ�������������ˣ�%^RESET%^
2 %^H_BLUE%^GM%^RESET%^��gini��������emote��
   ���磺%^H_GREEN%^GMhi%^RESET%^  ��gini��%^RED%^��ɫ�������Ƶغ�����˸��к���%^RESET%^
3 %^H_BLUE%^GA%^RESET%^��gini(������)������
   ���磺%^H_GREEN%^GA$N������$T��ͷ%^RESET%^  ��gini��%^RED%^��ɫ�������������ͷ%^RESET%^
   ���磺%^H_GREEN%^GA$N������ͷ%^RESET%^  ��gini��%^RED%^��ɫ����������ͷ%^RESET%^
4 %^H_BLUE%^ME%^RESET%^��������emote
   ���磺%^H_GREEN%^MEhehe%^RESET%^  �����%^RED%^�㡸�ٺٺ٣��������ؼ�Ц�˼�����%^RESET%^
5 %^H_BLUE%^MG%^RESET%^�����˶�gini��emote
   ���磺%^H_GREEN%^MGpat%^RESET%^  �����%^RED%^���������������ɫ�����ͷ��%^RESET%^\n";
ret+=
"6 %^H_BLUE%^MA%^RESET%^������(��gini)������
   ���磺%^H_GREEN%^MA$N��$T��һ����ס�ڡ�%^RESET%^  �����%^RED%^�����ɫ�����һ����ס�ڡ�%^RESET%^
7 %^H_BLUE%^GS%^RESET%^��gini ˵��
   ���磺%^H_GREEN%^MS��ǰ����ɽ. . .%^RESET%^  ��gini��%^RED%^��ɫ����˵������ǰ����ɽ. . .%^RESET%^
8 %^H_BLUE%^GT%^RESET%^��gini tell ����
   ���磺%^H_GREEN%^GThi%^RESET%^  ��gini��%^RED%^��ɫ����(fire gini)�����㣺hi%^RESET%^
9 ���ȱʡ����ΪMA : ���˶�gini��emote
   ���磺%^H_GREEN%^$N��$T��һ����ס�ڡ�%^RESET%^  �����%^RED%^�����ɫ�����һ����ס�ڡ�%^RESET%^\n";
return ret;
}