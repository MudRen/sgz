// modified by fire on Jan 3 1998
// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */
inherit VERB_OB;
mixed can_follow_liv(object who)  
{
         return 1;
}
mixed can_follow()
{
	return 1;
}         
void do_follow()
{
         if( this_body()->query("leader") ) 
         {
             this_body()->delete("leader"); 
             this_body()->simple_action("$N���ڷ�������Ŀ�ꡣ\n");
             return;
         } 
         else 
         {
             write("�����ڲ�û�и����κ��ˡ�\n");
             return;
         }
}
void do_follow_liv(object ob)
{
  
      if( ob == this_body() )
      {       
            write("�����Լ���\n");
            return;
      }
      this_body()->set("leader",ob);
      this_body()->targetted_action("$N������ʼ����$Tһ���ж���\n",ob);
      return; 
}
array query_verb_info() {
    return ({ ({ "LIV","" }) });
}
