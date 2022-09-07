//char menu for managering character database
//created by flee@lima on 3 Aug 1998

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
    add_menu_item(toplevel, new_menu_item("�г���������(List)",
      (: get_input_then_call, (: do_list :),
           "���ĸ���ĸ��ͷ��(enter �������е�): ":), "l"));
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
void do_list(string str)
{
    mixed top=SGHELP_D->query_topics();
    string *list;
    int count, i;
    string out;
        
    i = 0;
    out = "";
    list = sort_array(keys(top), 1);
    if ( !str || str == "" )str = "*";
    else if ( !has_magic(str) )str = str + "*";
    str = "^"+translate(str)+"$";
    list = regexp(list, str);
    if( !list ){
         printf("û���� '%s' ��Ӧ�İ������⡣\n", str);
         return;
    };
    count=sizeof(list);
    out="����ID         �������            ��  ���� ���������\n";
    for(i=0; i<count; ++i)
    {
       out = out + 
       sprintf("%-15s%-20s%2s    %d      %d\n", list[i],
          top[list[i]]["t"],((top[list[i]]["is_parent"]==1 ) ? "��" : "��"),
          sizeof(top[list[i]]["parent"]),sizeof(top[list[i]]["related"]));
    }
    out = out + sprintf("\n���鵽��%d���������⡣\n", count);
        more(out + "\n");
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
