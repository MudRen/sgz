// maker.c
// this is the menu to 
#include <menu.h>
#include <commands.h>
#include <security.h>   /* ### for now */
#include <edit.h>

inherit M_GLOB;
inherit MENUS;
inherit M_ACCESS;       /* ### for now */

MENU toplevel;

// submenus of the toplevel (build) menu

// sub menus of the roommenu
MENU editmenu;
MENU objmenu;
MENU actmenu;

MENU_ITEM N_QUIT;
MENU_ITEM main_seperator;

private string p_id,p_name,p_long;
private string p_room;
private array p_act,p_obj;
private int p_gender,p_age;
private int is_new; // 1 is a new maker, 0 is a old maker
void do_new( string str) {
    string p_surname,p_givenname;
    int p_namepart;
    int p_tmp;
	if(!str) str="";
	if(CHAR_D->char_exist(str)){
		write ("�ý�ɫ�Ѿ����ڡ�\n");
        prompt_then_return();
		return;
	}
    p_namepart=sscanf(str,"%s %s",p_surname,p_givenname);

    if(p_namepart!=2){
		write ("ID�����������ֹ��ɡ�\n");
        prompt_then_return();
		return;

	}
	p_id=str;
	p_room=file_name(environment(this_body()));
	p_act=({});
	p_obj=({});
	p_name="�¹���";
	p_gender=1;
	p_age=random(40)+15;
	p_long=0;
	is_new=1;
	goto_menu(editmenu);
}
void do_edit(string str) {
	if(!str) str="";
	if(!CHAR_D->get_char(str,"is_maker")){
		write ("�����ڸù�����\n");
        prompt_then_return();
		return;
	}
	else{
		p_id=str;
		p_room=CHAR_D->get_char(p_id,"shd_room");
		p_act=CHAR_D->get_char(p_id,"m_act");
		p_name=CHAR_D->get_char(p_id,"name");
		p_long=CHAR_D->get_char(p_id,"long");
		p_gender=CHAR_D->get_char(p_id,"gender");
		p_obj=CHAR_D->get_char(p_id,"goods");
		p_age=CHAR_D->get_char(p_id,"age");
		is_new=0;
		goto_menu(editmenu);
	}
}
void add_name(string str){
	if((!str)||(str=="")) return;
	p_name=str;
	write("���֣�"+str+"\n");
}
void add_gender(string str){
	if((!str)||(str=="")) return;
	p_gender=to_int(str);
	if(p_gender!=2) p_gender=1;
	write("�Ա�"+((p_gender==1)? "��" : "Ů")+"\n");
}
void add_age(string str){
	if((!str)||(str=="")) return;
	p_age=to_int(str);
	write("���䣺"+p_age+"\n");
}
void add_long(string str){
	if((!str)||(str=="")) return;
	p_long=str;
	write("��ò��"+str+"\n");
}

void add_room(string str){
	object o;
	if((!str)||(str=="")) return;
	if(str=="here") str=file_name(environment(this_body()));
	o=load_object(str);
	if(!objectp(o)) {
		write ("�����ڸ÷��䡣\n");
        prompt_then_return();
		return;
	}
	p_room=str;
	write("���䣺"+str+"\n");
}

void add_save(string str){
	mixed tmp;
	if((!str)||(str=="")) str="y";
	if((str[0]!='y')) {
		return;
	}
	if(is_new) {
		tmp=CHAR_D->add_char(p_id);
		tell_user("fire",p_id);
		write(tmp);
	}
	CHAR_D->set_char(p_id,"name",p_name);
	CHAR_D->set_char(p_id,"age",p_age);
	CHAR_D->set_char(p_id,"long",p_long);
	CHAR_D->set_char(p_id,"m_act",p_act);
	CHAR_D->set_char(p_id,"goods",p_obj);
	CHAR_D->set_char(p_id,"gender",p_gender);
	CHAR_D->set_char(p_id,"shd_room",p_room);
	CHAR_D->set_char(p_id,"room",p_room);
	CHAR_D->set_char(p_id,"is_maker",1);
	CHAR_D->set_char(p_id,"is_tmp",1);
	CHAR_D->set_char(p_id,"body","maker");
	write("����������ϡ�\n");
	goto_menu(toplevel);
}

void add_unsave(string str){
	if((!str)||(str=="")) str="N";
	if((str[0]=='y')) {
		goto_menu(toplevel);
		return;
	}
	return;
}

void add_obj(string str) {
	mixed name;
	if(!str) str="";
	name=OBJ_D->get_obj(str,"name");
	if(!name) {
		write ("����Ʒ�����ڡ�\n");
        prompt_then_return();
		return;
	}
	if(!p_obj) p_obj=({});
	p_obj-=({str});
	p_obj+=({str});
	write("������Ʒ��"+name+"\n");
}

void del_obj(string str) {
	mixed name;
	if(!str) str="";
	name=OBJ_D->get_obj(str,"name");
	if(!name) {
		write ("����Ʒ�����ڡ�\n");
        prompt_then_return();
		return;
	}
	if(!p_obj) p_obj=({});
	p_obj-=({str});
	write("ȥ����Ʒ��"+name+"\n");
}

void list_obj() {
	if(!p_obj) p_obj=({});
	if(!sizeof(p_obj)) {
		write ("��û���κ���Ʒ��\n");
        prompt_then_return();
		return;
	}
	write("����������Ʒ��\n");
	foreach(string p in p_obj){
		write(OBJ_D->get_obj(p,"name"));
		write("("+p+")\n");

	}
    prompt_then_return();
	return;
}
void list_act() {
	int i,s;
	if(!p_act) p_act=({});
	if(!sizeof(p_act)) {
		write ("��û���κ����С�\n");
        prompt_then_return();
		return;
	}
	write("�����������У�\n");
	s=sizeof(p_act);
	for(i=0;i<s;++i) {
		printf("[%2d] %s\n",i+1,p_act[i]);
	}
    prompt_then_return();
	return;
}

void del_act(string str) {
	int i,sum;
	string s;
	i=to_int(str);
	if(!p_act) p_act=({});
	sum=sizeof(p_act);
	if((i<1)||(i>sum)) {
		write ("��û�������С�\n");
        prompt_then_return();
		return;
	}
	s=p_act[i-1];
	p_act-=({s});
	write("ȥ�����У�"+s+"\n");
}

void add_act(string str) {
	if(!str) str="";
	if(sizeof(str)<8) {
		write ("������̫�̡�\n");
        prompt_then_return();
		return;
	}
	if(!p_act) p_act=({});
	p_act-=({str});
	p_act+=({str});
	write("�������У�"+str+"\n");
}
void init_actionmenu() {
	add_menu_item(actmenu,main_seperator);
	add_menu_item(actmenu,new_menu_item("��������(a)",
		(: get_input_then_call, (: add_act :),
		"�����¼�������� : " :),  "a"));
	add_menu_item(actmenu,new_menu_item("ɾ������(d)",
		(: get_input_then_call, (: del_act :),
		"ɾ���ڼ������� : " :),  "d"));
	add_menu_item(actmenu,new_menu_item("�г�����(l)",
		(: list_act :),"l"));
	add_menu_item(actmenu, new_menu_item("�����ϼ�(r)",
		editmenu,"r"));
	add_menu_item(objmenu,main_seperator);
}
void init_objmenu() {
	add_menu_item(objmenu,main_seperator);
	add_menu_item(objmenu,new_menu_item("������Ʒ(a)",
		(: get_input_then_call, (: add_obj :),
		"�����¼�����ƷID  : " :),  "a"));
	add_menu_item(objmenu,new_menu_item("ɾ����Ʒ(d)",
		(: get_input_then_call, (: del_obj :),
		"������ȥ����ƷID  : " :),  "d"));
	add_menu_item(objmenu,new_menu_item("�г���Ʒ(l)",
		(: list_obj :),"l"));
	add_menu_item(objmenu, new_menu_item("�����ϼ�(r)",
		editmenu,"r"));
	add_menu_item(objmenu,main_seperator);

}

void init_editmenu(){
   add_menu_item(editmenu, main_seperator);
   add_menu_item(editmenu, new_menu_item("�༭��������(m)",
		(: get_input_then_call, (: add_name :),
           "���빤������ : " :),  "m"));
   add_menu_item(editmenu, new_menu_item("�༭�����Ա�(g)",
		(: get_input_then_call, (: add_gender :),
           "���빤���Ա�(��:1 | Ů:2) : " :),  "g"));
   add_menu_item(editmenu, new_menu_item("�༭��������(a)",
		(: get_input_then_call, (: add_age :),
           "���빤������ : " :),  "a"));
   add_menu_item(editmenu, new_menu_item("�༭������ò(l)",
		(: get_input_then_call, (: add_long :),
           "���빤����ò : " :),  "l"));
   add_menu_item(editmenu, new_menu_item("�༭��������(r)",
		(: get_input_then_call, (: add_room :),
           "���빤������ : " :),  "r"));
   add_menu_item(editmenu, new_menu_item("�༭������Ʒ(o)",
		objmenu,  "o"));
   add_menu_item(editmenu, new_menu_item("�༭��������(w)",
		actmenu,  "w"));
   add_menu_item(editmenu, new_menu_item("���̷���(s)",
		(: get_input_then_call, (: add_save :),
           "ȷ�ϴ�����(y/n) : " :),  "s"));
   add_menu_item(editmenu, new_menu_item("�����̷���(u)",
		(: get_input_then_call, (: add_unsave :),
           "ȷ�Ϸ�����(y/n) : " :),  "u"));
   add_menu_item(editmenu, main_seperator);
   return;
}
void do_list(string str){
     string *list;
     string dis="";
     object o_room;
     string p_rom,ara,*objs;
     list=CHAR_D->check_char("is_maker",1);
    if ( !str || str == "" )
        str = "*";
    else 
        str = str + "*";
    str = "^"+translate(str)+"$";
    list = regexp(list, str);    
    
     if(!sizeof(list)) {
         write("û�������Ĺ�����\n");
         prompt_then_return();
         return;
     }
     foreach(string ls in list) {
        p_rom=CHAR_D->get_char(ls,"shd_room");
        o_room=load_object(p_rom);
        if(objectp(o_room)) {
           p_rom=o_room->short();
           ara=o_room->get_area();
           ara=AREA_D->get_area(ara,"name");
        }
        else {
           p_rom="----";
           ara="----";
        }
        if(!stringp(p_rom)) p_rom="----";
        if(!stringp(ara)) ara="----";
        dis+=sprintf("����ID: %s ����������%s �ɶ�: %s ���ڵ���: %s ���ڷ���: %s ",
           ls,CHAR_D->get_char(ls,"name"),
            (CHAR_D->get_char(ls,"just_sell")==1 ? "��" : "��"),
            ara,p_rom);
        objs=CHAR_D->get_char(ls,"goods");
        if(sizeof(objs)) {
           dis+="\n��������";
           foreach(string ob in objs) {
              dis+=sprintf("%s(%s)�ȼ���%dͬ�ˣ�%d\n",
                 OBJ_D->get_obj(ob,"name"),ob,
                 OBJ_D->get_obj(ob,"level"),
                 sizeof(OBJ_D->get_obj_maker(ob)));
           }
        }
        dis+="\n";
    }
    more(dis);
    prompt_then_return();
    return;
}
void do_delete(string str) {
	write("not finish\n");
}
void create() {
    set_privilege(1);
    toplevel = new_menu(mud_name()+"�����༭��");
    editmenu = new_menu("�༭������Ϣ");
    objmenu = new_menu("�༭����������������Ʒ");
    actmenu =  new_menu("�༭����������");

    N_QUIT = new_menu_item("Quit",(:quit_menu_application:),"q");
    main_seperator =  new_seperator("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");

    add_menu_item(toplevel, main_seperator);
    add_menu_item(toplevel, new_menu_item("����һ���¹���(n)", 
		(: get_input_then_call, (: do_new :),
           "����Ҫ�����Ĺ���ID :" :), "n"));
    add_menu_item(toplevel, new_menu_item("�༭һ�����й���(e)",  
		(: get_input_then_call, (: do_edit :),
           "����Ҫ�༭�Ĺ���ID :" :),  "e"));
    add_menu_item(toplevel, new_menu_item("ɾ��һ������(d)", 
		(: get_input_then_call, (: do_delete :),
           "����Ҫɾ���Ĺ���ID :" :), "n"));
    add_menu_item(toplevel, new_menu_item("�б���(l)", 
		(: get_input_then_call, (: do_list :),
           "����Ҫ�б�Ĺ���ID����ĸ :" :), "l"));

    add_menu_item(toplevel, N_QUIT);
    add_menu_item(toplevel, main_seperator);
	init_editmenu();
	init_actionmenu();
	init_objmenu();
    // Add menu items to the roommenu item
}

void start_menu() {
    init_menu_application(toplevel);
}

