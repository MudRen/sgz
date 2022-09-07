// name.c used for random npc
#include <ppl.h>

private string *surname =({"��","Ǯ","��","��","��","��","֣","��","��","��","��",
"��","��","��","��","��","��","����","ŷ��","˾��","ȫ","��",
"��","��","��","��","��","ʷ","��","��","��","����","�¶�",
"��","��","��","��","κ","��","��","��","��","��","ë","��",
"��","��","��","��","��","��","��","��","��","ɳ","��","é",
"��","��","��","�ĺ�","ʯ","½","³","��","��","��","��","��",
"��","��","��","̫ʷ","��",});

private string *cgname=({"��","˫","��","��","��","��","��","��","��","��",
"��","��","ʫ","��","�","��","��","��","Ө","��","Ӣ","��",
"��","��","�"});

private string *fmgname=({"ѩ","��","��","˫","��","��","��","��","ܽ","��",
"��","��","��","��","��","��","��","��","��","��","��","��",
"��","�"});

private string *mgname=({"��","»","��","ϲ","��","��","��","ǧ","��","��",
"��","��","��","��","Ǩ","��","��","��","��","��","��","��",
"��","��","ͨ","��","¹","��","��","��","��","��","��",
"��","��","ѷ","��","��","ǫ","��","��","��","��","��","��",
"��","��","��","��","��","��"});

string get_surname() {
	return surname[random(sizeof(surname))];
}
int get_gender(int typ) {
	switch(typ) {
	case YOUNGWOMAN:
	case MIDWOMAN:
	case OLDWOMAN:
		return 2;
	default: return 1;
	}
}
int get_age(int typ) {
	switch(typ) {
	case YOUNGWOMAN:
	case YOUNGMAN:
		return 10+random(10);
	case MIDWOMAN:
	case MIDMAN:
		return 20 + random(20);
	default: return 40+random(20);
	}
}
int get_rongmao(int typ) {
	return 10+random(20);
}

string get_given_name(int typ) {
	string *tmp;
	string nam;
	switch(typ) {
		case YOUNGWOMAN:
			tmp=cgname+fmgname;
			nam=tmp[random(sizeof(tmp))];
			switch(random(3)) {
				case 0:  return nam+nam;
				case 1: return "С"+nam;
				default: return nam+"��";
			}
		case MIDWOMAN:
			tmp=cgname+fmgname;
			nam=tmp[random(sizeof(tmp))];
			return nam;
		case OLDWOMAN:
			tmp=cgname+fmgname;
			nam=tmp[random(sizeof(tmp))];
			switch(random(3)) {
				case 0:  return nam+"��";
				case 1: return nam+"��̫";
				default: return nam;
			}
		case YOUNGMAN:
			tmp=cgname+mgname;
			nam=tmp[random(sizeof(tmp))];
			switch(random(3)) {
				case 1: return "С"+nam;
				default: return nam;
			}
		case MIDMAN:
		case OLDMAN:
			tmp=cgname+mgname;
			nam=tmp[random(sizeof(tmp))];
			return nam;

	}
}
string get_id(int typ) {
	switch(typ) {
		case YOUNGWOMAN: return "girl";
		case YOUNGMAN : return "youngman";
		case MIDWOMAN : return "woman";
		case MIDMAN : return "man";
		case OLDWOMAN : return "oldwoman";
		case OLDMAN : return "oldman";
	}
	return "unknown";
}
string get_desc (int typ) {
	switch(typ) {
		case YOUNGWOMAN: return "С����";
		case YOUNGMAN : return "������";
		case MIDWOMAN : return "����Ů��";
		case MIDMAN : return "��������";
		case OLDWOMAN : return "�ϸ���";
		case OLDMAN : return "����";
	}
	return "unknown";
}
string get_dress(int typ) {
	/*switch(typ) {
		case YOUNGWOMAN: return "ladydress";
		case YOUNGMAN : return "buyi";
		case MIDWOMAN : return "biyuzan";
		case MIDMAN : return "changpao";
		case OLDWOMAN : return "xpao";
		case OLDMAN : return "ypiao";
	}
	return "unknown";*///Ŀǰֻ¼�˲��£����Ժ���ӡ�
	return "buyi";
}


int get_salary(int typ) {
	switch(typ) {
		case YOUNGWOMAN: return 40;
		case YOUNGMAN : return 15;
		case MIDWOMAN : return 30;
		case MIDMAN : return 30;
		case OLDWOMAN : return 20;
		case OLDMAN : return 20;
	}
	return 30;
}

