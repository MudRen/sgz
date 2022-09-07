//created by flee@lima on 27 July 1998
//modified by flee@lima on 29 July 1998, adding feelings...cmds 

#include <ansi.h>
#include <menu.h>
#include <mudlib.h>

inherit MENUS;
inherit M_ACCESS;
inherit M_GLOB;
inherit M_GRAMMAR;

MENU toplevel;

MENU_ITEM quit_item;
MENU_ITEM seperator;

void do_list(string str);
void do_find(string which);
void do_del(string str);
void do_edit(string str);
void do_help();

void create()
{
	set_privilege(2);

	toplevel = new_menu("\n" + mud_name() + "��ж��ʱ༭��");

	quit_item = new_menu_item("�˳�", (:quit_menu_application:), "q");
	seperator = new_seperator("\n������������������������������������������������������������������\n");

	add_menu_item(toplevel, seperator);
	add_menu_item(toplevel, new_menu_item("�г���ж���(List)",
			(: get_input_then_call, (: do_list :),
			"���ĸ���ĸ��ͷ��(enter �������е�): ":), "l"));
	add_menu_item(toplevel, new_menu_item("Ѱ��һ����ж���(Find)",
			(: get_input_then_call, (: do_find :),
			"����Ҫ��ѯ�ĵ��� :" :), "f"));
	add_menu_item(toplevel, new_menu_item("ɾ��һ����ж���(Delete)",
			(: get_input_then_call, (: do_del :),
                        "����Ҫɾ���ĵ��� :" :), "d"));
	add_menu_item(toplevel, new_menu_item("�޸�һ����ж���(Edit)",
			(: get_input_then_call, (: do_edit :),
			"����Ҫ�޸ĵĵ��� :" :), "e") );
	add_menu_item(toplevel, new_menu_item("��ʾ�����ļ�(Help)",
			(: do_help :), "h") );
	add_menu_item(toplevel, quit_item);
	add_menu_item(toplevel, seperator);
	set_menu_prompt (toplevel, "����ָ��[defhlq]: ");
}
void start_menu()
{
	init_menu_application( toplevel );
}
//feelings commands, it will find and list semotes from Soul.o 
//dir /cmds/player/semote.c
private void do_list(string arg)
{
	string *list;
	string *long;
	string str;
	int count, i;

	str = "";
	i = 0;

	list = sort_array(SOUL_D->list_emotes(), 1);
	count = sizeof(list);
	
	if ( !arg || arg == "" )arg = "*";
	else if ( !has_magic(arg) )arg = arg + "*";

	arg = "^"+translate(arg)+"$";
	list = regexp(list, arg);
    
	if ( !list ){
        	printf("û���� '%s' ��Ӧ����дʻ㡣\n", arg);
        	return;
    	}

	for(count = 0; count < sizeof(list); count++){
		i++;
		str = str + sprintf("%-15s", list[count]);
		if( i == 4 ){
			i = 0;
			str = str + "\n";
		}
	};
	printf(str + "\n");

	prompt_then_return();	
}
//command semote.c, which can give the details of a semote
//dir is /cmd/player/semote.c
private void do_find(string which)
{
	mapping data;
	mixed * info;

	if( !which ){
	        printf("��Ҫָ��һ����ж��ʡ�\n");
        	return;
	}

	data = SOUL_D->query_emote(which);
    	if( !data ){
        	printf("û�������ж��ʡ�\n");
        	return;
	}
	
	if ( data[""] ){
        	info = SOUL_D->get_soul(which, "", ({ }));
        	printf("%s :\n��ῴ����%s���˻ῴ����%s\n",
               		which, info[1][0], info[1][1]);
	}
	if ( data["LIV"] ){
        	info = SOUL_D->get_soul(which, "LIV", ({ this_object() }));
        	printf("%s somebody:\n��ῴ����%sĿ��ῴ����%s���˻ῴ����%s\n",
               		which, info[1][0], info[1][1], info[1][2]);
    	}
	if ( data["STR"] ){
        	info = SOUL_D->get_soul(which, "STR", ({ "slowly" }));
        	printf("%s slowly :\n��ῴ����%s���˻ῴ����%s\n",
               		which, info[1][0], info[1][1]);
    	}
    	if ( data["LIV STR"] ){
	        info = SOUL_D->get_soul(which, "LIV STR", ({ this_object(), "slowly" }));
        	printf("%s somebody slowly :\n��ῴ����%sĿ��ῴ����%s���˻ῴ����%s\n",
               		which, info[1][0], info[1][1], info[1][2]);
    	}

	prompt_then_return();
}
//rmemote command, use to delete a emote from soul.o
//dir /cmds/wiz/rmemote.c
private void do_del(string str)
{
	string rule;
	if( !wizardp( this_body()->query_userid() ) ){
		printf("����������ʦ������æ�ɡ�\n");
		return;
	};
	if( !str ){
		printf("��Ҫɾ����һ��emote��\n");
		return;
	};

	sscanf(str, "%s %s", str, rule);
	if (SOUL_D->remove_emote(str, rule))printf("ɾ���ɹ���\n");
	else printf("ɾ��ʧ�ܡ�\n");

	prompt_then_return();
}
void do_help()
{
	printf("\n%10s��ж��ʱ༭��\n", mud_name());
	printf("\n\n��������˵�ʹ�á�\n");
	if( wizardp( this_body()->query_userid() ) ){
		printf("\n��ж����������˵��\n");
		printf("	1)$N  �Լ���һ��ƺ���\n");
		printf("	2)$T  Ŀ���һ��ƺ���\n");
		printf("	3)$n  �Լ��Ĵ��ơ�\n");
		printf("	4)$M  �Լ������֡�\n");
		printf("	5)$s  �Լ���ǫ�ơ�\n");
		printf("	6)$S  �Լ����Գơ�\n");
		printf("	7)$R  Ŀ��ľ��ơ�\n");
		printf("	8)$r  Ŀ�����ơ�\n");
	};
	prompt_then_return();
}
void do_edit(string str)
{
	int i;
	mapping data;
	string verb, rule, content;

	if( !wizardp( this_body()->query_userid() ) ){
                printf("����������ʦ������æ�ɡ�\n");
                return;
        };

	printf("��ʽ������,����,����\n");
	sscanf(str, "%s,%s,%s", verb, content, rule);
	if( !verb || !content ){
		printf("�Ƿ��ĸ�ʽ��\n");
		return;
	};

	if( !rule )rule = "";
	if( rule != "" && rule != "LIV" && rule != "STR" && rule != "LIV STR"){
		printf("�Ƿ��Ķ��󣬺Ϸ��Ķ���Ϊ \"\", LIV, STR, LIV STR\n");
		return;
	}
	
	if(SOUL_D->add_emote(verb, rule, content))printf("�޸ĳɹ���\n");
	else printf("�޸�ʧ�ܡ�\n");
	
	prompt_then_return();
}
