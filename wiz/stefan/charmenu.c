//char menu for managering character database
//created by flee@lima on 3 Aug 1998

#include <menu.h>
#include <mudlib.h>
inherit CMD;
inherit MENUS;
inherit M_GRAMMAR;
inherit M_GLOB;

MENU toplevel;

MENU_ITEM quit_item;
MENU_ITEM seperator;

void do_list(string str);
void do_find(string str);
void do_del(string str);
void do_edit(string str);
void do_add(string str);

void done_delete(string arg, string str);
void done_edit(string char, string input);

string *okid = ({ "stefan", "fire", "yue", "group", "yuner", "flee" });

int check_id(string str)
{
	int i;
	for(i = 0; i < sizeof( okid ); i++)if( str == okid[i] )return 1;
	return 0;
}

mixed check_ok( mixed str)
{
	if( !str || str == "" || str == 0)return "δ֪";
	else return str;
}

int comfirm_char(string *list, string arg)
{
	int i;
	for(i = 0; i < sizeof( list ); i++){
		if( list[i] == arg )return 1;
	};
	return 0;
}

void create() 
{
	set_privilege(1);
	
	toplevel = new_menu("\n" + mud_name() + "��ɫ����˵�");
	quit_item = new_menu_item("�˳�", (:quit_menu_application:), "q");
	seperator = new_seperator("\n������������������������������������������������������������������\n");

	add_menu_item(toplevel, seperator);
	add_menu_item(toplevel, new_menu_item("�г���ɫ(List)",
                        (: get_input_then_call, (: do_list :),
                        "���ĸ���ĸ��ͷ��(enter �������е�): ":), "l"));
        add_menu_item(toplevel, new_menu_item("Ѱ��һ����ɫ(Find)",
                        (: get_input_then_call, (: do_find :),
                        "����Ҫ��ѯ�Ľ�ɫ�� :" :), "f"));
	add_menu_item(toplevel, new_menu_item("����һ����ɫ(Add)",
			(: get_input_then_call, (: do_add :),
                        "����Ҫ���ӵĽ�ɫ�� :" :), "a"));
        add_menu_item(toplevel, new_menu_item("ɾ��һ����ɫ(Delete)",
                        (: get_input_then_call, (: do_del :),
                        "����Ҫɾ���Ľ�ɫ�� :" :), "d"));
        add_menu_item(toplevel, new_menu_item("�޸�һ����ɫ(Edit)",
                        (: get_input_then_call, (: do_edit :),
                        "����Ҫ�޸ĵĽ�ɫ�� :" :), "e") );
        add_menu_item(toplevel, quit_item);
        add_menu_item(toplevel, seperator);
        set_menu_prompt (toplevel, "����ָ��[adeflq]: ");
}
void start_menu()
{
        init_menu_application( toplevel );
}
void do_list(string str)
{
	int count, i;
	string out;
	string *list;
	
	i = 0;
	out = "";
	list = sort_array(CHAR_D->list_chars(), 1);

	if ( !str || str == "" )str = "*";
        else if ( !has_magic(str) )str = str + "*";
        str = "^"+translate(str)+"$";
        list = regexp(list, str);

	if( !list ){
		printf("û���� '%s' ��Ӧ�Ľ�ɫ��\n", str);
		prompt_then_return();
	};
        for(count = 0; count < sizeof(list); count++){
                i++;
                out = out + sprintf("%-15s", list[count]);
                if( i == 4 ){
                        i = 0;
                        out = out + "\n";
                }
        };
	out = out + sprintf("\n���鵽��%d����ɫ��\n", count);
        printf(out + "\n");

        prompt_then_return();
}
void do_find(string str)
{
	string *list;
	mapping temp;
	int per;

	list = sort_array(CHAR_D->list_chars(), 1);        

	if( !str ){
                printf("��Ҫ�����Ǹ���ɫ��\n");
		return;
        };
	if( !comfirm_char(list, str) ){
		printf("%s�����ɫ�������ڡ�\n", str);
		return;
	};
	
	temp = CHAR_D->get_char(str, "gift");
	per = temp["rongmao"];
	temp = CHAR_D->get_char(str, "skills");

	printf("\n\n");
	printf("��ɫ����: %-10s, ����: %-10s, ��: %s \n", 
		str, 
		check_ok( CHAR_D->get_char(str, "name")), 
		check_ok( CHAR_D->get_char(str, "zi")));
	printf("�Ա�:     %-10s, ����: %d\n", 
		(CHAR_D->get_char(str, "gender")==1 ? "��" :"Ů"),
		CHAR_D->get_char(str, "age"));
	printf("����:     %-10d, ��ı: %-10d, ����: %-10d, ��ò: %d\n",
		temp["sk_wuli"],
		temp["sk_zhimou"],
		temp["sk_meili"],
		per );
	printf("����:     %-10s \n", 
		CHAR_D->get_char(str, "reputationstr") );
	printf("���ڵ�:   %-10s, ������: %s\n", 
		check_ok( AREA_D->get_area(CHAR_D->get_char(str, "area"), "name")),
		check_ok( COUNTRY_D->get_country(CHAR_D->get_char(str, "nation"), "name")));
	printf("��͢��ְ: %-10s, �ط���: %s\n", 
		check_ok( OFFICER_D->query_rank_name(CHAR_D->get_char(str, "ranknation"))),
		check_ok( OFFICER_D->query_rank_name(CHAR_D->get_char(str, "ranklocal"))));
	printf("�ҳ�:     %-10d, ٺ»: %d\n", 
		CHAR_D->get_char(str,"loyalty"),		
		CHAR_D->get_char(str,"salary"),);	
	printf("\n");

	prompt_then_return();
}
void do_add(string str)
{
	string str1, str2;
	string *list;

	if( !str ){
		printf("������Ҫ��ӵĽ�ɫӢ������\n");
		return;
	};
	if( !wizardp( this_body()->query_userid() ) ){
                printf("����������ʦ������æ�ɡ�\n");
                return;
	};
	if( !check_id( this_body()->query_userid() ) ){
		printf("please ask Fire or Stefan for this permission.\n");
		return;
	};
	if( sscanf(str, "%s %s", str1, str2 ) != 2){
		printf("������֮��Ҫ�пո�\n");
		return;
	};
	
        list = sort_array(CHAR_D->list_chars(), 1);
	if( comfirm_char(list, str) ){
		printf("%s�Ѿ����ڣ�\n", str);
		printf("Ҫɾ���˽�ɫ����( d )ѡ�Ҫ�༭�˽�ɫ����( e )ѡ�\n");
		return;
	};

	if( CHAR_D->add_char( str ) )printf("%s��ӳɹ�.\n", str);
	else printf("%s���ʧ��.\n", str);

	prompt_then_return();
}
void do_del(string str)
{
	string *list;


        if( !str ){
                printf("������Ҫɾ���Ľ�ɫӢ������\n");
                prompt_then_return();
        };
        if( !wizardp( this_body()->query_userid() ) ){
                printf("����������ʦ������æ�ɡ�\n");
                prompt_then_return();
        };
        if( !check_id( this_body()->query_userid() ) ){
                printf("please ask Fire or Stefan for this permission.\n");
                prompt_then_return();
        };

        list = sort_array(CHAR_D->list_chars(), 1);
	if( !comfirm_char(list, str) ){
                printf("%s�������ڣ�\n", str);
                return;
        };

	do_find( str );

	get_input_then_call( (: done_delete , str :), "��ȷ����(yes or no)>" ); 
	return;
}
void done_delete(string arg, string str)
{

	if( str == "yes" || str == "YES"){
		if( CHAR_D->remove_char( arg ) )printf("%sɾ���ɹ�! \n", str);
		else printf("%sɾ��ʧ��!\n", str);
		return;
	} else if( str == "no" || str == "NO" ){
		printf("canceled\n");
	} else printf("invalid choice, prossess terminated.\n");

}
void do_edit(string str)
{
        string *list;


        if( !str ){
                printf("������Ҫɾ���Ľ�ɫӢ������\n");
                prompt_then_return();
        };
        if( !wizardp( this_body()->query_userid() ) ){
                printf("����������ʦ������æ�ɡ�\n");
                prompt_then_return();
        };
        if( !check_id( this_body()->query_userid() ) ){
                printf("please ask Fire or Stefan for this permission.\n");
                prompt_then_return();
        };

        list = sort_array(CHAR_D->list_chars(), 1);
        if( !comfirm_char(list, str) ){
                printf("%s�������ڣ�\n", str);
                return;
        };

	do_find( str );
	printf("����: name          , ��: zi,\n"); 
	printf("�Ա�: gender(1 Ϊ��,0 ΪŮ), ����: age\n");
	printf("����: wuli          , ��ı: zhimou    , ����: meili     , ��ò: rongmao\n");
	printf("����: reputationstr\n");
	printf("���ڵ�: area        , ������: nation\n");
	printf("��͢��ְ: ranknation, �ط���: ranklocal\n");
	printf("�ҳ�: loyalty       , ٺ»: salary\n"); 

	get_input_then_call( (: done_edit , str :), "����Ҫ�༭����Ŀ������ֵ>"); 
}
void done_edit(string char, string input)
{
	string parameter;
	mixed value;
	if( sscanf( input, "%s %s", parameter, value) != 2 ){
		printf("��ʽ����Ŀ  ��Ŀ��ֵ\n");
		return;
	};
	if( restore_variable( value ) != 0 )value = restore_variable( value );
        if( value == "0" )value = 0;
	if( CHAR_D->set_char(char, parameter , value) )printf("�ı�ɹ���\n");
	else printf("�ı�ʧ�ܣ�\n");
}	

private void main(string args) 
{
    start_menu();
}

