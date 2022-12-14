#include <mudlib.h>
#include <ansi.h>

#define GOAT "/sgdomain/job/feedgoat/goat.c"

inherit LIVING;

void ask_pay(object player);
void ask_job(object player);

void setup()
{
	set_name("yang guan", "羊倌");
	set_in_room_desc("「"+HIY+"小放羊"+NOR+"」"+"羊倌(yang guan)");
	set_long("羊倌对你嘻嘻的笑了几声，\n"+
       		"要工作就ask yang guan about job。\n"+
       		"要钱就ask yang guan about pay。\n");
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
		this_object()->simple_action("$N暗笑道：真是个白痴,嘿嘿。\n");
        	this_object()->targetted_action(
         		"$N对$T道：$R真是又能干，又聪明，这是奖你张大票子。\n",usr);
        	this_object()->targetted_action("$N给$T一张百圆纸钱。甛n",usr);
        	usr->simple_action("$N高兴地连称：好！好！谢谢赏赐。\n");
        	ob = new("/sgdomain/obj/money/fmoney.c");
        	ob->move(usr);
    	} else {
        	CHAR_D->set_char( usr->query_id()[0], "reputation",
			CHAR_D->get_char(usr->query_id()[0], "reputation")+1 );
        	tell_user(usr->query_id()[0], "你的声望提高了。\n");
        	this_object()->simple_action("$N说到：不错，不错．\n");
        	this_object()->targetted_action("$N给$T二十两银子。\n",usr);
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
            		"$N对$T道：没干活就想拿钱呀。\n",usr);
       	 	return;
    	};
    	this_object()->targetted_action(
      		"$N对$T说道：活儿干得不错，但我还要给你一道题,看你聪明不聪明。\n",usr);
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
         		"$N对$T对满脸堆笑道：$m$R折杀$s也，此乃下人的活，怎敢劳动$R。\n",usr);
       		return;
    	};
	if( usr->query_job("feedgoat", "beg_time") > 0	){
		this_object()->targetted_action( 
			"$N奇怪的打量了$T几眼，您不正在做这件事吗？\n",
usr);
		return;
	};
   	if( usr->query_job("feedgoat","count_lasttimes") > 
    		JOB_D->query_job("feedgoat","count_lasttimes") ){
     		this_object()->targetted_action(
          		"$N对$T道：你今天干的活够多的了，该休息休息了。\n",usr);
        	return;
    	};

    	usr->resign_job("feedgoat");
    	usr->add_job("feedgoat");
	goat = new( GOAT );
	goat->set_owner( usr );
	goat->move( environment(usr) );
	this_object()->simple_action("$N牵了一只小羊出来。\n");
	goat->responda("follow " + usr->query_id()[0]);
    	this_object()->targetted_action(
		"$N对$T道：那么，要好好照顾它噢。\n", usr);
}
