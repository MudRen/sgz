// thief.c the body of thief
inherit PMODULES+"m_charnpc";
private int escape_times;
private int catched;
private string p_leader;
void escape_forever();
void set_leader(string p_id)
{
	p_leader=p_id;
	return;
}

void setup()
{  
	escape_times=0;
	catched=0;
	call_out("my_heart",0);
}
void extra_init()
{
	add_id("thief");
}
string long()
{  
   return "һ���ƻ���С͵�����ڶ����������������ܲ���ʵ��\n";
}
int escape()
{
	int test=0;
	string p_id;
	object env,tar;
   string *obvious_exits;
   int random_exit,i;
	env=environment(this_object());
	obvious_exits=env->query_exit_directions();
   
	p_id=this_object()->query_id()[0];
    i = sizeof(obvious_exits);
    if(!i) {return 0;}
    random_exit = random(i);
	tar=load_object(env->query_exit_value(obvious_exits[random_exit]));
	while((!tar)||(test<5))
	{
		test++;
	    random_exit = random(i);
		tar=load_object(env->query_exit_value(obvious_exits[random_exit]));
	}

   switch(random(5)){
   case 0:
 	 this_object()->responda("say ��ץס�ң�û�š�\n");
	 break;
   case 1:
 	 this_object()->responda("hehe");
	 break;
   case 2:
	   this_object()->responda("escape");
	   break;
   case 3:
	   this_object()->responda("face");
	   break;
   default:
	   this_object()->responda("say ��ʮ���ƣ���Ϊ�ϡ�\n");
   }
	if(objectp(tar))
	{
		this_object()->simple_action("$N��"+tar->short()+"��ȥ��\n");
		this_object()->move(tar);
		this_object()->simple_action("$N��"+env->short()+"���˹�����\n");
		CHAR_D->set_char(p_id,"room",file_name(tar));
	}
}
// others can catch this thief
int can_catch(){
	return 1;
}

int be_catch(string p_officer)
{
	object o;
	int l;
	o=find_body(p_leader);
	if(!objectp(o))
		return 0;
	l=o->query_sk_level("sk_wuli");
	if((random(100)+15)>l)
	{
		escape();
		return 0;
	}
	else
	{
		catched=1;
		o->set_job("patrol","get_thief",1);
		o->responda("hit thief");
		o->targetted_action(
			"$N��ȭ��$T���ڵأ��ȵ������ˣ�����������ȥ��\n",this_object());
		this_object()->responda("beg");
		this_object()->simple_action("����ʿ��������$N������ȥ��\n");
		CHAR_D->remove_char(this_object()->query_id()[0]);
	}
}

void escape_forever()
{
	object o_leader;
	this_object()->simple_action(
		"$N����һ��ǽͷ�������ˡ�\n");
	o_leader=find_body(p_leader);
	if(objectp(o_leader))
		o_leader->set_job("patrol","get_thief",-1); // escaped
	CHAR_D->remove_char(this_object()->query_id()[0]);

}
void my_heart()
{
        string p_id;
	remove_call_out("my_heart");

	escape_times++;
	if(!catched)
	{
		if(escape_times>30)
		{
			if(random(30)==3)
			{
				escape_forever();
				return;
			}
		}
		escape();
	}
        p_id=this_object()->query_id()[0];
        if(!CHAR_D->char_exist(p_id)) 
          remove();
        else
          call_out("my_heart",random(3));
 
}
