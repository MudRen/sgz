#include <mudlib.h>
#include <ansi.h>

#define GOAT "/sgdomain/job/feedgoat/goat.c"

inherit LIVING;

void ask_pay(object player);
void ask_job(object player);

void setup()
{
	set_name("yang guan", "����");
	set_in_room_desc("��"+HIY+"С����"+NOR+"��"+"����(yang guan)");
	set_long("���Ķ���������Ц�˼�����\n"+
       		"Ҫ������ask yang guan about job��\n"+
       		"ҪǮ��ask yang guan about pay��\n");
   	set_gender(1);
   	set_age( 10+random(10) );
   	set_sg_rongmao(-1);
   	add_question("job", "job");
   	add_question("pay","pay");
}
mixed special_answer(object ob, string str)
{
	object player;

	player = this_body();

	if( str == "job" )ask_job( player );
        else if( str == "pay" )ask_pay( player );

	return;
}
void award(object usr)
{
    	object ob;

    	if( usr->query_robot() ){   
		this_object()->simple_action("$N��Ц�������Ǹ��׳�,�ٺ١�\n");
        	this_object()->targetted_action(
         		"$N��$T����$R�������ܸɣ��ִ��������ǽ����Ŵ�Ʊ�ӡ�\n",usr);
        	this_object()->targetted_action("$N��$Tһ�Ű�ԲֽǮ���\n",usr);
        	usr->simple_action("$N���˵����ƣ��ã��ã�лл�ʹ͡�\n");
        	ob = new("/sgdomain/obj/money/fmoney.c");
        	ob->move(usr);
    	} else {
        	CHAR_D->set_char( usr->query_id()[0], "reputation",
			CHAR_D->get_char(usr->query_id()[0], "reputation")+1 );
        	tell_user(usr->query_id()[0], "�����������ˡ�\n");
        	this_object()->simple_action("$N˵������������\n");
        	this_object()->targetted_action("$N��$T��ʮ�����ӡ�\n",usr);
        	ob=new(M_SILVER);
        	ob->set_m_num(20);
        	ob->move(usr);
    	}
	return;
}
void ask_pay(object usr)
{
	string name;
    	name = usr->query_id()[0];

    	if( !usr->query_job("feedgoat", "end") ){
        	this_object()->targetted_action(
            		"$N��$T����û�ɻ������Ǯѽ��\n",usr);
       	 	return;
    	};
    	this_object()->targetted_action(
      		"$N��$T˵��������ɵò������һ�Ҫ����һ����,���������������\n",usr);
    	usr->finish_job("feedgoat");
	usr->set_job("feedgoat", "end", 0);	
	ROBOT->robot_test( usr, (:award:) );
	return;
}
void ask_job(object usr)
{
    	string name;
	object goat;

    	name = usr->query_id()[0];
    	if( CHAR_D->get_char(name, "nation") ){
       		this_object()->targetted_action(
         		"$N��$T��������Ц����$m$R��ɱ$sҲ���������˵Ļ�����Ͷ�$R��\n",usr);
       		return;
    	};
	if( usr->query_job("feedgoat", "beg_time") > 0	){
		this_object()->targetted_action( 
			"$N��ֵĴ�����$T���ۣ������������������\n",
usr);
		return;
	};
   	if( usr->query_job("feedgoat","count_lasttimes") > 
    		JOB_D->query_job("feedgoat","count_lasttimes") ){
     		this_object()->targetted_action(
          		"$N��$T���������ɵĻ����ˣ�����Ϣ��Ϣ�ˡ�\n",usr);
        	return;
    	};

    	usr->resign_job("feedgoat");
    	usr->add_job("feedgoat");
	goat = new( GOAT );
	goat->set_owner( usr );
	goat->move( environment(usr) );
	this_object()->simple_action("$Nǣ��һֻС�������\n");
	goat->responda("follow " + usr->query_id()[0]);
    	this_object()->targetted_action(
		"$N��$T������ô��Ҫ�ú��չ����ޡ�\n", usr);
}
