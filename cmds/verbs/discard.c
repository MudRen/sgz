/*
** discard.c by fire on Jan 15
**
*/
#include <mudlib.h>
#include <setbit.h>
#include <classes.h>
#include <edit.h>
inherit M_INPUT;
inherit M_COMPLETE;
inherit M_GRAMMAR;
inherit CLASS_NEWSMSG;
inherit VERB_OB;
string ngroup;
int p_id=0;

private nomask int filter_removed(int elem) {
    class news_msg msg = NEWS_D->get_message(ngroup, elem);
    
    if (!msg || !msg->body)
        return 0;
    return 1;
}
private nomask void receive_remove_verify(string str)
{
    if ( str[0] != 'y' && str[0] != 'Y' )
    {
        write("����ɾ����\n");
        return;
    }
    NEWS_D->remove_post(ngroup, p_id);
    write ("ɾ����ϡ�\n");
}
void do_discard_str(string st)
{
    class news_msg msg;
    int id;
    int array ids;
    object o;

//        ngroup=environment(this_body())->query_board();
//  write("this my discard.c\n");
	o=present("news board",this_body()->query_room());

	if (!objectp(o))
        {
              printf("���û�����Կ�ɾ��ѽ��\n");
              return;
        }
	ngroup=o->query_group();
        if (sscanf(st, "%d", id) != 1)
        {
		write( "��Ҫɾ���ڼ������ԣ�\n");
		return;
	}
	ids = sort_array(filter_array(NEWS_D->get_messages(ngroup),(: filter_removed :)), 1);
        if (id <= 0 || id > sizeof(ids))
        {
            printf("���԰���û���������ԡ�\n");
	    return;
	}
	p_id=ids[id-1];
	msg=NEWS_D->get_message(ngroup, p_id);
 if(msg->userid != this_user()->query_userid() &&
 !(ngroup[0..5]=="nation" && ngroup[7..]==this_user()->query_userid())
           //above added by suicide for emperor to delete the useless title
           //in their own country board 2000/03/19
          )
        {
    	    write("��ֻ��ɾ���Լ�д�����ԡ�\n");
            return;
        }
if ( (msg->userid!=this_user()->query_userid()) && ngroup[0..5]=="nation" && ngroup[7..]==this_user()->query_userid() )
           if ( (time()-msg->time)<86400)
              {
    	        write("������Ի�û��һ���ʱ�ޣ�����ʱ�޷�ɾ����\n");
                return;
              }

	NEWS_D->remove_post(ngroup, p_id);
    	write ("ɾ����ϡ�\n");

//        printf( "ȷ��ɾ����[yn] > ");
//        modal_simple((: receive_remove_verify :));
}
array query_verb_info()
{
    return ({ ({ "STR" }) });
}
