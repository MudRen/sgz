// the body of merchant
inherit PMODULES+"m_charnpc";
inherit __DIR__+"guy/guy_thought";
inherit __DIR__+"guy/guy_final";
private int life=600; //fake guy exist for 10 minutes

void clear_catch(string p_id) {
    CHAR_D->set_char(p_id,"catch_time",0);
    CHAR_D->set_char(p_id,"catch_file",0);
    CHAR_D->set_char(p_id,"catch_function",0);
    CHAR_D->set_char(p_id,"catch_para",0);

}

void setup()
{  
	//call_out("my_heart",5);
	add_question("recruit","recruit");
	add_question("followme","followme");
	add_question("getppl","getppl");
	add_ask_str("followme","$N����Ⱥ$T�������֣�С�����ǣ��ڼ����߶�û��˼��\n"+
		"����ȥ�ɣ��г��кȻ�����ɱ�˷Ż𣬶�����ѽ��\n");
	add_ask_str("recruit","$N����Ⱥ$T�������֣�С�����ǣ��ڼ����߶�û��˼��\n"+
		"����ȥ�ɵ����ɣ��г��кȻ�����ɱ�˷Ż𣬶�����ѽ��\n");
	add_ask_str("getppl","$N����Ⱥ$T�������֣�С�����ǣ�������������$S�������к��¸ɡ�\n");
	call_out("my_heart",20);
}
string long()
{
  string p_id=this_object()->query_id()[1];
   return "һȺ"+p_id+
      "������һ������ʲô��\n";
}
string query_title(string p_id,string c_id)
{  return "һȺ"+c_id+ "("+p_id+")";
}
void do_my_dispear()
{
	string p_id;
	object o;
	p_id=query_pure_leader(); // use query_pure_leader to avoid dead loop
	if(stringp(p_id)) {
		clear_catch(p_id);		
		o=find_user(p_id);
		if(objectp(o))
			o->modal_pop();
	}
	this_object()->simple_action
     ("һ$N����ʱ���磬��Ҷ���ȥ�ɡ�\n");
   this_object()->simple_action
     ("��$Nһɢ��ȥ�ˡ�\n");
   remove();
}
void do_my_speak()
{  switch(random(5))
   {  case 0:
        this_object()->simple_action
          ("$N��֪������ʲô��ͻȻ��Ц������\n");
       break;
     case 1:
        this_object()->simple_action
          ("һ��$N�������ǵ�����׬Ǯ��\n");
        this_object()->simple_action
          ("���˵�ͷ���ǡ�\n");
       break;
     case 2:
        this_object()->simple_action
          ("һ��$N������˵������ٶ�����ԡ�\n");
        this_object()->simple_action
          ("��һ$N������ɵ�ˣ�ǰ�����Ҽ��˼����ϱ�����������Ƥ����ͷ��\n");
       break;
     case 3:
        this_object()->simple_action
          ("һ��$N������ʵ�ڼҴ���Ҳ��������������ȥ���̡�\n");
        this_object()->simple_action
          ("��$N���п�������������\n");
       break;
     default: 
        this_object()->simple_action
          ("һ��$N��������ʥ�ϻ�ӹ���鳼��������ɽ����ѽ��\n");
        this_object()->simple_action
          ("��һ$N�����С���㣬��Ҫ������\n");
       break;
    }
}
void my_charaction()
{  int act;
   string p_id=query_leader();
   if(sizeof(p_id))
         return;
   act=random(5);
   switch(act)
   {    case 0:
//          if(random(100)==0)
//             do_my_dispear();
     
      case 1:
      	  return;
      case 2:
          do_my_speak();
          return;         
      case 3:
      	   return;
      default:
          do_my_moving();
   }
}
void my_heart()
{
	int tick = 20 + random(10);
	remove_call_out("my_heart");
	//printf("my heart is going on %d! life left %d\n",tick,life);
	if (this_object()->query("is_fake"))
	{
		life-=tick;
		if (life>0 || this_object()->query("is_locked")==1)
		{
		   my_charaction();
		   call_out("my_heart",20+random(10));
		}
		else
		{
		   if (stringp(this_object()->query("master")))
			tell_user(this_object()->query("master"),"%^H_RED%^���ɸ봫�顿�ܱ���"+
				"�᷽����ѱ�����ʶ�ƣ�ȫ��ɱ����ʡ�%^RESET%^ \n");
		   do_my_dispear();
		}
	}
	else
	{			
		my_charaction();
		call_out("my_heart",20+random(10));
	}
		
}
void answer_followme(object who)
{
   mixed ret;
   string p_id=who->query_id()[0];

   write("%^H_RED%^�Բ���,���ױ��Ĺ�����ʱ���ر��ˣ�%^RESET%^\n");
   return;

   who->start_busy(2,"������˵���أ�\n");
   this_object()->set("is_locked",1);
   ret=can_ask_for_join(p_id);
   if(ret!=1)
   {
     this_object()->targetted_action(ret,who);
	 check_leader();
     return;
   }
   set_act("followme");
   call_out("my_respond",1);
   
}
void answer_recruit(object who)
{
   mixed ret;
   string p_id=who->query_id()[0];
   who->start_busy(2,"������˵���أ�\n");
   this_object()->set("is_locked",1);
   ret=can_ask_for_recruit(p_id);
   if(ret!=1)
   {
     this_object()->targetted_action(ret,who);
	 check_leader();
     return;
   }
   set_act("recruit");
   call_out("my_respond",1);
}

void answer_getppl(object who)
{
   mixed ret;
   string p_area,f_id,r_id;
   string p_id=who->query_id()[0];
   who->start_busy(2,"������˵���أ�\n");
   this_object()->set("is_locked",1);
   ret=can_ask_for_getppl(p_id);
   if(ret!=1)
   {
     this_object()->targetted_action(ret,who);
	 check_leader();
     return;
   }
   set_act("getppl");
   p_area=who->query_job("getppl","p_area");
   f_id=who->query_job("getppl","f_id");
   r_id=who->query_job("getppl","r_id");
   this_object()->targetted_action("$N��$T����ʲô���¡�\n",who);
   who->targetted_action("$N����"+AREA_D->get_area(p_area,"name")+
	   "��"+BASE_D->get_base(f_id,"name")+ "Ҫ��һ��"+
	   BASE_D->get_base(f_id,"workername")+"������ȥ�ɣ���Ȼ���кô���\n",this_object());

   call_out("my_respond",1);

}

void special_answer(object who, string matt)
{
  switch(matt)
  {
      case "followme" :
         answer_followme(who);
       return;
      case "recruit" :
         answer_recruit(who);
		 return;
      case "getppl" :
         answer_getppl(who);
	  return;
  }
}
int is_guy() {
	return 1;
}
// will not be clean_up
int query_clean_up() {
	return 1;
}
