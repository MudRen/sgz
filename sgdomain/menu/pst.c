// post as a menu
#include <mudlib.h>
#include <setbit.h>
#include <classes.h>
#include <edit.h>
inherit M_INPUT;
inherit M_COMPLETE;
inherit M_GRAMMAR;
inherit CLASS_NEWSMSG;
inherit CMD;
string ngroup;
nomask void wrap_post(string * text)
{
    int i = sizeof(text);
    while ( i-- )
    {
        /* only wrap really long lines */
        if ( sizeof(text[i]) > 78 )
        {
            /* wrap to different widths, based on the text */
            int width=78;
            if ( sizeof(text[i]) > width )
                text[i] = wrap(text[i], width);
        }
    }
}
private nomask void receive_post_text(string subject, string * text)
{
    int id;
    if ( !text )
    {
        write("�������ԡ�\n");
	destruct(this_object());
        return;
    }
    wrap_post(text);
    id = NEWS_D->post(ngroup, subject, implode(text, "\n") + "\n");
    write("���Խ�����\n");
    destruct(this_object());
}
private void receive_post_subject(string subject)
{
    if(subject==".")
    {   write("�������ԡ�\n");
	destruct(this_object());
	return;
    }
    if(!subject)
	subject="";
    if ( subject == "" )
    {
	subject="�����⡣";
    }
    new(EDIT_OB, EDIT_TEXT, 0, (: receive_post_text, subject :));
}
mixed can_i_post() {
      if(wizardp(this_body())) return 1; // wizard can post anywhere
//      ngroup=(this_body()->query_room())->query_board();
      if(ngroup=="caolu") return 1; // any one can post in there
      if(ngroup=="newbie") return 
          "�������ְ����壬ֻ����ʦ�ſ����ڴ����ԡ�\n";
      if(ngroup=="war") return 
          "����ս�����԰壬ֻ��ս��ſ����ڴ����ԡ�\n";
      if(ngroup=="marriage") return 
          "���ǻ������԰壬ֻ�а���ſ����ڴ����ԡ�\n";
      if(ngroup=="ranks") return 
          "�����������԰壬ֻ��ͳ���߲ſ����ڴ����ԡ�\n";
      if(ngroup=="progress") return 
          "������ʦ���԰壬ֻ����ʦ�ſ����ڴ����ԡ�\n";
      if(ngroup[0..6]=="nation.") {
	 string p_id,p_nation;
         p_id=this_body()->query_id()[0];
         p_nation=ngroup[7..<1];
         if(p_nation!=CHAR_D->get_char(p_id,"nation"))
             return "ֻ�б�����Ա�����ڴ����ԡ�\n";
      }
      return 1;
          
}
void do_post()
{
        mixed ret;
	object o;
	o=present("news board",this_body()->query_room());
	if (!objectp(o))
        {
              printf("���û�ط���������ѽ��\n");
	      destruct(this_object());
              return;
        }
	ngroup=o->query_group();
        ret=can_i_post();
        if(stringp(ret)) {
            write(ret);
 	   destruct(this_object());
            return;
        }
        write("�������������⣬ . ��ʾ������\n");
	write("�������⣺");
        modal_simple((: receive_post_subject :));
}
int clean_up() {
	destruct(this_object());
}
