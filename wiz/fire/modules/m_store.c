// m_store.c  by fire on Dec 12 1997  
#include <mudlib.h>
#include <move.h>
void load_from_string( mixed value, int recurse );  //??
varargs string save_to_string(int recursep);   //?
private string *stored_items = ({}); // state name cost ids name ? enough?
void add_object(string ob_name) 
{
    object ob;
    string item_state;
    string item_name;
    string name_of_file;
    string *object_ids;
    int object_value;
    string ob_value;            
        ob=new(ob_name);
        object_value = ob->query_absolutevalue();
        ob_value=ob->query_chinesevalue();
        item_state = save_to_string(1);
        item_name = ob->short();
        object_ids = ob->query_id();
        object_ids += ({ ob->short() });
        stored_items += ({ ({ item_state }) + ({ item_name }) + 
        ({ob_value }) + ({object_ids }) +({ob_name}) });
        destruct(ob);
}
mixed query_items()
{
        int i;
        int m;
        int j;
        string *stored_items_ids;
        string *items_available = ({});
        i = sizeof(stored_items);
        if(!i)
        {
                return "����Ļ���û����\n";
        }
        else
        {
                while(i--)
                {
                        items_available += ({ ({ stored_items[i][1] }) +({stored_items[i][2] }) + ({stored_items[i][4]}) });
                }
                j = sizeof(items_available);
                write("��������������Ʒ�� \n
--------------------------------------------------------\n");
printf("          ��������             ��Ǯ\n");
                for( m=0; m < j; m++)
                {
                        printf("%20s          %s", items_available[m][0],items_available[m][1]);
                }
                return 
"--------------------------------------------------------\n��������Ҫ��ʲô\n";
        }
}
mixed list()
{
        string retstr;
        retstr= query_items();
        write(retstr);
        return 1;
}
void buy_sth(string item, int number)
{
    int i;
    int j = 0;
    int m = 0;
    int p_buyersmoney;
    int p_itemvalue;
    string *for_sale_ids;
    object ob;
    string *ob_filename;
    i = sizeof(stored_items);
    p_buyersmoney=this_body()->query_all_con_money();
    if (!number)
    {
        number = 1;
    }
    if (i)
    {
	while (i--)
        {
            for_sale_ids = ({ stored_items[i][3] });
            if(member_array(item, for_sale_ids[0]) != -1)
            {
                j += 1;
                if (j == number)
                {
		    ob_filename=({ stored_items[i][4] });
		    ob=new(ob_filename[0]);
		    p_itemvalue=ob->query_absolutevalue();
		    if( p_buyersmoney < p_itemvalue )
		    {
			write("Ǯû����ѽ��\n");
		        destruct(ob);
			return;
		    }
		    else
		    {	
	                    if((ob->move(this_body())) == MOVE_OK)
			    {		
                    		this_body()->simple_action("$N�ڴ�������һ"+
                                        ob->query_unit()+ob->short()+"��\n"); 
				this_body()->set_all_con_money(p_buyersmoney - p_itemvalue);
		                return;
			     }
			    else
			    {
				write("����û���ò����ˡ�\n");
			        destruct(ob);
				return;
			    }
		     }
			
                }
            }
        }
	write("��Ҫ�Ķ����������û�С�\n");
	return;
    }
    write("�����û�����ء�\n");
}
mixed buy(string item, int number)
{
	buy_sth(item,number);
	return 1;
}	
