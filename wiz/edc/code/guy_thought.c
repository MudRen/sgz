// buy_thought.c by fire on Dec 1998
void select_way();
void  select_num();
static private string *sug=({
"$N����Щ$T����ս��ʱ�ڣ���Ҷ�����ƶ����һ�����Ӵ�Ҿͷ���ȥ�Ⱦưɡ�",
"$N����Щ$T�������ǲ�֪������򲻵�֮�£�������׼û��",
"$N����Щ$T�������ǲ�֪�ҵ��ǻ����һ����ɲ⣬���ҵ����£����ް���֮��",
"$N����Щ$T�������ǲ�֪�ҵ�������һ���������д󽫷緶�����ǿ��ǲ��ǣ�",
"$N����Щ$T�����ҵĻƽ����������壬���Ǹ���ȥ�ɡ�",
"$N����Щ$T�������ǲ�֪�ҵ�������������˵һ�仰��û�˸�˵�����֣������ң��ٺ١�",
"$N����Щ$T����������Щ��֪�ô��ĵ����ٲ�������������ȫץ������",
"$N����Щ$T�������ǲ�����ֻҪһ���̣�Ǯ�Ͷ����Ҳ�����塣",
"$N����Щ$T��������֪������һ���µгǣ���������Ҫ�����ж��١�",
"$N����Щ$T�������Ӻ����ɷ��Ե�������������һ����ҵ������",
"$N���������ض���Щ$T������������������ʵ����ȱ��ѽ��",
"$N����Щ$T����ֻҪ�����ң��������꣬�����Ǹ߹ٺ�»���Դ����",
"$N�����ض���Щ$T������������Щ����ʵ���Ƕ�ţ���٣����˷��ҵ�ʱ�䡣",});
private string p_leader="";
private object o_leader;
private int status=0;
private mixed suggest=({});
void do_my_dispear();
string query_pure_leader() {
	return p_leader;  // do no check
}
int check_leader() {
	object o;
	if(!sizeof(p_leader)) return 0;
	o=find_body(p_leader);
	if(!objectp(o)) {do_my_dispear(); return 0;}
	if(o!=o_leader) {do_my_dispear(); return 0;}
	if((o->query_room())!=(this_object()->query_room()))
		{do_my_dispear(); return 0;}
	return 1;
}
string query_leader()
{  
	check_leader();
	return p_leader;
}
void set_leader(string p)
{
   p_leader=p;
   o_leader=find_body(p);
}
void judge_select(int p_select)
{
    object bdy=find_body(p_leader);

	if(!check_leader())
		return;
    switch(p_select)
    {    case 1:
         if(bdy->query_all_con_money()<10000)
         {
            this_object()->simple_action("$N������������Ǯ��ƭ�ˣ�\n");
            status-=2;
         }
         else
         {  bdy->set_all_con_money( bdy->query_all_con_money() -10000 );
            this_object()->simple_action("��$N�����˵�����������\n");
            status+=2;
         }
         break;
       case 13:
           this_object()->targetted_action
             ("$N��$T�����翴���㲻�Ǹ��ö�����\n",bdy);
         status=0;
         break;
       default:
         if(random(2)==1)
         {
            this_object()->simple_action(
                  "$N���������۷�ֱ����ˮ�����˳�����\n");
// edc  08/04/2001  add more possiblity for recruiting
/*            status+=2;*/
		status += random(2)+2;
////
         }
         else{
            status-=random(2)+1;
            this_object()->simple_action(
               "$N��Ȼ���ţ��������꣬�꣬��ţ����ţ��\n");
          } 
    }      
    call_out("my_respond",1);
}
void input_way(string str)
{   int p_select=to_int(str);
    object usr=find_user(p_leader);   
    object bdy=find_body(p_leader);
	if(!check_leader())
		return;
    if(!objectp(usr)) return;
    if(!objectp(bdy)) return;
    if((p_select<1)||(p_select>13)) return;
    remove_call_out("no_answer_way");
    if(member_array(p_select,suggest)!=-1)
    {  tell_user(p_leader,"���ַ����ù��ˣ��û�һ�С�\n");
       call_out("no_answer_way",30);
       return;
    }
    usr->modal_pop();
    bdy->targetted_action(sug[p_select-1]+"\n",this_object());
    call_out("judge_select",1,p_select);
    suggest+=({p_select});
}
void no_answer_way()
{ input_way("13");
}
void select_way()
{
   object usr=find_user(p_leader);
   if(!objectp(usr)) return;
   tell_user(p_leader,"���ǿ���������ȥ�����������ʲô�취˵�����ǡ�\n"+
"��������������������������������������������������������������������\n"+
" 1 ��Ǯ  2 �Կ��¸�  3 �Կ����  4 �Կ�����  5 �Կ�Ƹ�  6 �Կ�ְλ\n"+
" 7 ����  8 �Ƹ��ջ�  9 ��Ů�ջ� 10 ��ҵ�ջ� 11 ������� 12 ��ְ�ջ�\n"+
"13 ����\n"+
"��������������������������������������������������������������������\n");
   call_out("no_answer_way",30);
   usr->modal_push((: input_way :),
        "���������˵������(1--13)��");
}

mixed can_ask_for_getppl(string p_id)
{  
	object o_leader;
	int p_level;
   string p_area=this_object()->query_room()->get_area();
   if(AREA_D->get_area(p_area,"safe")<20 && !this_object()->query("is_fake"))
       return "$Nһ����������Ŀ�ⶢ��$T��һ�桸�ٺٺ١��ؼ�Ц����\n$T�ŵ�ת����ܡ�\n";
   if(AREA_D->get_area(p_area,"population")<500 && !this_object()->query("is_fake"))
       return "��$N��$T���������������׼ٻ���ƭ���ǣ������Ķ���ȥ��\n";

	if(sizeof(query_pure_leader()))
   {   if(p_leader==p_id)
          return "$N��$T�������ǲ�����������\n";
          return "$N��$T����ȥȥȥ��û��������æ����\n";       
   }
   if(!CHAR_D->get_char(p_id,"nation"))
          return "$N��$T������Ҫ���ģ�һ��ȥ��\n";

//	set_leader(p_id);
//   o_leader=find_body(p_leader);
//   if((o_leader->query_job("getppl","beg_time"))==0) 
//	  return "һ��$N��$T����$r����ʲô���£���������\n";
//to solve the getppl problem
   if ((find_body(p_id)->query_job("getppl","beg_time"))==0)
	   return "һ��$N��$T����$r����ʲô���£���������\n";
   set_leader(p_id);
   o_leader=find_body(p_leader);
	
   suggest=({});
   p_level=CHAR_D->get_skill(p_id,"sk_meili");
   p_level/=10;
//modified by listen for fake guy
	if (this_object()->query("is_fake"))
		status=12; // must success
	else
		status=random(p_level)+1;
   {
	string p_nation;
	int loy;
	p_nation=AREA_D->get_area(p_area,"nation");

	if( p_nation != CHAR_D->get_char(p_id,"nation") ) {
	        CHAR_D->set_char(p_id,"catch_time",time()+600);
	        CHAR_D->set_char(p_id,"catch_file",PJOB+"fanpeople/fanpeople");
	        CHAR_D->set_char(p_id,"catch_function","recruit_catch");
	        CHAR_D->set_char(p_id,"catch_para",this_object());
	        CHAR_D->set_char(p_id,"catch_area",p_area);
		
		loy=CHAR_D->get_char_loyalty(p_id,p_nation);
		loy--; loy=bmax(1,loy);
		CHAR_D->set_char_loyalty(p_id,p_nation,loy);
	}
   }
   return 1;
}

mixed can_ask_for_join(string p_id)
{  object o;
   int p_level;
   if(sizeof(query_pure_leader()))
   {   if(p_leader==p_id)
          return "$N��$T�������ǲ�����������\n";
          return "$N��$T����ȥȥȥ��û��������æ����\n";       
     }
        if(!CHAR_D->get_char(p_id,"nation"))
                return "$N��$T������Ҫ���ģ�һ��ȥ��\n";
	set_leader(p_id);
   suggest=({});
   p_level=CHAR_D->get_char_level(p_id);
//modified by listen for fake guy
	if (this_object()->query("is_fake"))
		status=12; // must success
	else
	   status=p_level+random(10-p_level);
   return 1;
}
mixed can_ask_for_recruit(string p_id)
{  object o;
   string p_area;
   int p_level;
   p_area=this_object()->query_room()->get_area();
   if(AREA_D->get_area(p_area,"safe")<20 && !this_object()->query("is_fake"))
       return "$Nһ����������Ŀ�ⶢ��$T��һ�桸�ٺٺ١��ؼ�Ц����\n$T�ŵ�ת����ܡ�\n";
   if(AREA_D->get_area(p_area,"population")<500 && !this_object()->query("is_fake"))
       return "$N��$T�������ؾ���������������ٳ����������˾͵ö�����\n";

   if(sizeof(query_pure_leader()))
   {   if(p_leader==p_id)
          return "$N��$T�������ǲ�����������\n";
       return "$N��$T����ȥȥȥ��û��������æ����\n";
   }
        if(!CHAR_D->get_char(p_id,"nation"))
                return "$N��$T������Ҫ���ģ�һ��ȥ��\n";
       if(((PJOB+"recruit/recruit")->get_recruit_left(p_id))<=0)
           return "$N��$T���ɵ�˵��$m$R����û���б��ƻ��ɡ�\n";
       if(sizeof(find_body(p_id)->query_job("recruit","lasttimes"))>50)
           return "$N��$T���ɵ�˵��$m$Rһ��������ô�����\n";

	set_leader(p_id);
   suggest=({});
   p_level=CHAR_D->get_char_level(p_id);
   //modified by listen for fake guy
	if (this_object()->query("is_fake"))
		status=12; // must success
	else
		status=random(p_level)+1;
   {
	string p_nation;
	int loy;
	p_nation=AREA_D->get_area(p_area,"nation");

	if( p_nation != CHAR_D->get_char(p_id,"nation") ) {
	        CHAR_D->set_char(p_id,"catch_time",time()+600);
	        CHAR_D->set_char(p_id,"catch_file",PJOB+"fanpeople/fanpeople");
	        CHAR_D->set_char(p_id,"catch_function","recruit_catch");
	        CHAR_D->set_char(p_id,"catch_para",this_object());
	        CHAR_D->set_char(p_id,"catch_area",p_area);
		
		loy=CHAR_D->get_char_loyalty(p_id,p_nation);
		loy--; loy=bmax(1,loy);
		CHAR_D->set_char_loyalty(p_id,p_nation,loy);
	}
   }
   return 1;
}
void my_respond()
{
   object o;
   if(!sizeof(p_leader)) return;
   o=find_body(p_leader);
   if(!objectp(o)) return;
   if(o->query_room()!=environment(this_object())) return;
   if(status<0) status=0;
   if(status>10) status=10; 
  switch(status)
   {   case 0:
         this_object()->taregetted_action
            ("һ$N��$T�����ҿ�����̸��ȥҲû��ʲô��˼�ˡ�\n");
         do_my_dispear();
         return;    
       case 1:
       case 2:
         this_object()->simple_action(
           "һ$N������һﲻ���š�\n");
         this_object()->simple_action(
           "��һ$N�����ҿ�Ҳ�ǡ�\n");
         break;
       case 3:
       case 4:
         this_object()->simple_action(
           "һ$N����������Щ����\n");
         this_object()->simple_action(
           "��һ$N����������һ�ס�\n");
         break;
       case 5:
       case 6:
         this_object()->simple_action(
           "һ$N��ͷ���˿�������$M�����ò������⣬�����أ�\n");
         this_object()->simple_action(
           "��һ$N��������������\n",o);
         break;
       case 7:
       case 8:
         this_object()->simple_action(
           "��$N�׷׵�ͷ���ǡ�\n");
         break;
       case 9:
         this_object()->simple_action(
           "һ$N������Ҫȥ��������ô����\n");
         this_object()->simple_action(
           "��һ$N������̫�����ٵȵȡ�\n");
         break;
       case 10:
         this_object()->simple_action(
           "��$N���˵������������׷׵�����ȥ����ȥ��\n");
         break;
   }
   if(status==10)
     select_num();
   else
     select_way();    
}
