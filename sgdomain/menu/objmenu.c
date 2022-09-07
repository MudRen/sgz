// to manage D_OBJ system
//by fire on March 22, 1999

#include <menu.h>
#include <mudlib.h>
inherit MENUS;
inherit M_ACCESS;
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


int comfirm_char(string *list, string arg)
{
        int i;
        for(i = 0; i < sizeof( list ); i++){
                if( list[i] == arg )return 1;
        };
        return 0;
}
void done_title(string str,string title)
{
    mixed ret;
    ret=SGHELP_D->set_topic(str,"t",title);
    if(ret) write("�ɹ���\n");
     else write("ʧ�ܡ�\n");
}
void do_title(string str)
{
    get_input_then_call
     ((: done_title, str:), "������⡣");

}
void do_class(string str)
{
    mixed ret;
    ret=SGHELP_D->set_topic(str,"is_parent",1);
    if(ret) write("�ɹ���\n");
     else write("ʧ�ܡ�\n");
}
void do_unclass(string str)
{
    mixed ret;
    ret=SGHELP_D->set_topic(str,"is_parent",0);
     write("�ɹ���\n");
}

void done_subclass(string str,string par)
{
    mixed ret;
    ret=SGHELP_D->sub_parent(str,par);
    write(ret);
}
void do_subclass(string str)
{
    get_input_then_call
     ((: done_subclass, str:), "����һ����ɾ����");
}

void done_addclass(string str,string par)
{
    mixed ret;
    ret=SGHELP_D->add_parent(str,par);
    write(ret);
}
void do_addclass(string str)
{
    get_input_then_call
     ((: done_addclass, str:), "������һ�ࡣ");
}
void do_check()
{
   mixed ret;
   ret=SGHELP_D->find_wrong();
   write(ret);
   prompt_then_return();
}
void create()
{
    set_privilege(1);
    toplevel = new_menu("\n" + mud_name() + "����ϵͳ����˵�");
    quit_item = new_menu_item("�˳�", (:quit_menu_application:), "q");
    seperator = new_seperator
    ("\n������������������������������������������������������������������\n");
    add_menu_item(toplevel, seperator);
    add_menu_item(toplevel, new_menu_item("��Ʒ�б�(List)",
      (: get_input_then_call, (: do_list :),
           "��Ʒ������ࣿ(enter �������е�): ":), "l"));
        add_menu_item(toplevel, new_menu_item("Ѱ��һ����������(Find)",
           (: get_input_then_call, (: do_find :),
           "����Ҫ��ѯ�İ��������� :" :), "f"));
        add_menu_item(toplevel, new_menu_item("�޸��������(Title)",
           (: get_input_then_call, (: do_title :),
             "����Ҫ�޸ı�������� :" :), "t"));
        add_menu_item(toplevel, new_menu_item("��һ����Ϊ��(Class)",
            (: get_input_then_call, (: do_class :),
             "����Ҫ��Ϊ������� :" :), "c"));
        add_menu_item(toplevel, new_menu_item("ȡ��һ��(UnClass)",
            (: get_input_then_call, (: do_unclass :),
             "����Ҫȡ��������� :" :), "u"));

        add_menu_item(toplevel, new_menu_item("��һ�������һ��(AddClass)",
            (: get_input_then_call, (: do_addclass :),
             "����Ҫ���������� :" :), "a"));
        add_menu_item(toplevel, new_menu_item("��һ�����һ����ȡ��(SubClass)",
            (: get_input_then_call, (: do_subclass :),
             "����Ҫ���������� :" :), "s"));

        add_menu_item(toplevel, new_menu_item("���Ҳ���������(cHeck)",
             (: do_check :), "h"));

        add_menu_item(toplevel, quit_item);
        add_menu_item(toplevel, seperator);
        set_menu_prompt (toplevel, "����ָ��[lftcuasq]: ");
}
void start_menu()
{
        init_menu_application( toplevel );
}

void doreal_list(string *ids,string str){
	string *dis; 
	string tmp;
	mixed ob;
	ob=OBJ_D->get_obj();
	dis=explode(str,",");
	if(!sizeof(dis))
		dis=({"name"});

	foreach(string id in ids)
	{
		tmp=sprintf("%-12s ",id);
		foreach(string d in dis){
			if(!ob[id][d])
				tmp+="       0 ";
			else{
				if(intp(ob[id][d]))
					tmp+=sprintf("%8d ",ob[id][d]);
				else
					tmp+=sprintf("%-10s",ob[id][d]);
			}
			if(tmp[<1]==10)
				tmp=tmp[0..<2];
		}
		printf("%s\n",tmp);
	}
}
		


void do_list(string str)
{
	string *ids;
	string dis;
	if((!str)||(str==""))
		ids=OBJ_D->get_obj("list");
	else
	{
		ids=OBJ_D->check_obj("type",str);
		if(!sizeof(ids))
			ids=OBJ_D->check_obj("sub_type",str);
	}
	if(!sizeof(ids)) {
         printf("û�и�����Ʒ��\n", str);
         prompt_then_return();
         return;
    }

    get_input_then_call
     ((: doreal_list, ids:), "��ʾ��Щ��Ϣ��");
}

void do_find(string str)
{
    mapping temp;
    string dis;
    temp = SGHELP_D->get_topic(str);
    if( !temp ){
         printf("û�й��� '%s' �İ������⡣\n", str);
         prompt_then_return();
         return;
    }
    dis=sprintf("����: %s : ���� :%O\n",str,temp["t"]);
    dis+=sprintf("λ�ã� %O\n",temp["p"]);
    dis+=sprintf("�Ƿ���: %O \n",temp["is_parent"]);
    dis+=sprintf("�����ࣺ%O \n",temp["parent"]);
    dis+=sprintf("������⣺%O \n",temp["related"]);
    write(dis);
}
