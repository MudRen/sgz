// by fire on aug 1999
inherit M_CHAR;
inherit LIVING;
inherit M_BLOCKEXITS;
#define MARRY_GATE "/sgdomain/area/marriage/marry_gate"
string p_boy,p_girl;
string p_boyname,p_girlname;
string p_area;
string p_step;
private mapping p_gift=([]);
int p_life;
static string *chaois=({
    "一群小孩在房子里跑着，跳着，要着喜糖。\n",
    "一帮乐师的唢呐「滴滴哒哒」的吹得好不热闹。\n",
    "一人高喊，新娘笑了，众人哄堂大笑。\n",
    "很多人挤在门口，想看个究竟。\n",
    "又来了一队送礼的，各种喜礼都用大红纸包着。\n",
    "一个帐房先生手里拿着算盘，劈里啪啦地计算着礼金的数量，高兴得嘴都合不拢。\n",
    "爆竹「乒乒乓乓」地响个不停，好象比过年还热闹。\n",
    "$N点头哈腰，对进出贵宾不断行礼致敬。\n",
    "$N对新来的宾客道：有什么礼物就交给我吧。\n",

});
mixed get_gift() {
	return p_gift;
}
int get_gift_amount() {
	int ret=1;
	int *val;
	int sum,i;
	val=values(p_gift);
	sum=sizeof(val);
	for(i=0;i<sum;++i)
		ret+=val[i];
	return ret;
}

private mixed handle_blocks( string dir )
{
        string p_id;
	if(dir!="litang") return 0;
	p_id=this_body()->query_primary_id();
	if(p_id==p_boy) {
		this_object()->targetted_action(
		"$N对$T鞠躬道：新郎官还不快进去。\n",this_body());
		return 0;
	}
	if(p_id==p_girl) {
		this_object()->targetted_action(
		"$N对$T鞠躬道：新娘子，里面请。\n",this_body());
		return 0;
	}
	if(p_id=="jiaofu tou") {
		this_object()->targetted_action(
		"$N道：花轿来了，快让开，快让开。\n",this_body());
		return 0;
	}
	if(p_gift[p_id]) {
		this_object()->targetted_action(
		"$N对$T鞠躬道：$m$R，里面请。\n",this_body());
		return 0;
	}
/*	if((!CHAR_D->char_exist(p_id))&&(objectp(find_body(p_id)))) { 
		this_object()->targetted_action(
		"$N对$T鞠躬道：$m$R，里面请。\n",this_body());
		return 0;
	} */
        return ::handle_blocks(dir);    
}

void setup()
{
    set_name("li guan", "礼官");
    set_gender(1);
    set_in_room_desc("\n一个身着绸袍的迎宾%^H_RED%^礼官%^RESET%^(li guan)\n");

    add_ask_str("xinren","$N对$T小声道：谁结婚呀，这么排场。\n");
    add_question("xinren","xinren" );

    add_ask_str("guanli","$N对$T一拱手道：$s特来观礼，现备有微薄礼金，请笑纳。\n");
    add_question("guanli","guanli" );

    call_out("check",10);
    add_block("litang");

    set_block_action( "$N对$T一鞠躬道：请$R先登记完贺礼再入内观礼吧。\n");
}

string long() {
	return
"一个身着绸袍的迎宾%^H_RED%^礼官%^RESET%^，正在忙着收礼接客。\n";
}

void set_step(string s) {
	p_step=s;
	return;
}
void finish() {
	
	if((p_step!="over")&&(sizeof(p_gift))) {
		string *lst;
		lst=keys(p_gift); 
		foreach(string k in lst) {
			CHAR_D->set_char(k,"gold",CHAR_D->get_char(k,"gold")+p_gift[k]);
		}
	}
	this_object()->simple_action("$N离开了。\n");	
	this_object()->query_room()->delete_exit("litang");
	this_object()->remove();
}
void chaois() {
	string msg;
	msg=chaois[random(sizeof(chaois))];
	this_object()->simple_action(msg);
}

void check() {
	object o_boy,o_girl;
	o_boy=find_body(p_boy);
	o_girl=find_body(p_girl);
	p_life++;
	remove_call_out("check");
	call_out("check",5+random(5));

	if(!objectp(o_boy)) {
		if((time()-LAST_LOGIN_D->query_last(p_boy)[0])>600) {
			this_object()->simple_action(
			"$N奇怪地道：新郎官不见了，看来婚礼是办不成了，大伙儿回去吧。\n");
			finish();
			return;
		}
	}
	if(!objectp(o_girl)) {
		if((time()-LAST_LOGIN_D->query_last(p_girl)[0])>600) {
			this_object()->simple_action(
			"$N奇怪地道：新娘子不见了，看来婚礼是办不成了，大伙儿回去吧。\n");
			finish();
			return;
		}
	}
	switch(p_step) {
		case "begin":
			environment(this_object())->add_exit("litang" , MARRY_GATE);
			p_step="normal";
	tell(users(),"%^H_RED%^【婚礼】礼官高声喊道："+p_boyname+"和"+p_girlname+
        "的婚礼就要开始了，大家快来看呀。\n");
			return;
		case "normal":
			chaois();
			return;
		default :
			return;
	}


}
int set_boygirl(string boy,string girl) {
	p_boy=boy,p_girl=girl;
	p_boyname=CHAR_D->get_char(p_boy,"name");
	p_girlname=CHAR_D->get_char(p_girl,"name");
	p_area=CHAR_D->get_char(p_boy,"area");
	p_step="begin";
	p_life=1;
	remove_call_out("check");
	call_out("check",3);
	return 1;
}
void announce_gold(int p_amt,string name) {
	tell(users(),"%^H_RED%^【婚礼】礼官高声宣道：为"+p_boyname+"和"+p_girlname+
        "的婚礼"+name+"奉送礼金"+chinese_number(p_amt)+"两。\n");
}
void answer_guanli(object me,object who,string amt) {
	int p_amt;
	int p_mymoney;
	int p_sal;
	string p_id;
	object fr;
	me->clear_answer();	
	p_amt=to_int(amt);
	who->targetted_action("$N对$T道：这"+chinese_number(p_amt)+"两黄金就请收下吧。\n",me);

        if(p_amt>200) {
                me->targetted_action("$N对着$T「啊」了一声道：这。。这。。怎么敢当，$R还是另外再准备一份礼金吧。\n",who);
                return;
        }
	if(p_amt<=0) {
		me->targetted_action("$N对$T陪笑道：$R不要开玩笑啦。\n",who);
		return;
	}
	p_mymoney=who->query_all_con_money();
	if(p_mymoney<=(p_amt*10000)) {
		me->targetted_action("$N对$T陪笑道：$R身上没有那么多钱嘛。\n",who);
		return;
	}
	p_id=who->query_primary_id();
	p_sal=CHAR_D->get_char(p_id,"salary");
	if(CHAR_D->get_char(p_id,"ranknation")==R_KING) p_sal=200;
	if(p_sal==0) p_sal=1;
	if(p_amt<p_sal) {
		me->targetted_action("$N对$T笑道：这点钱怎么好意思拿出手，向$R这样的高官\n"+
			"最少也要拿出"+chinese_number(p_sal)+"两金子啦。\n",who);
		who->responda("shame");
		return;
	}
	who->set_all_con_money(p_mymoney-p_amt*10000);
/*	if(random(2))
		CHAR_D->set_char(p_girl,"gold",CHAR_D->get_char(p_girl,"gold")+p_amt);
	else
		CHAR_D->set_char(p_boy,"gold",CHAR_D->get_char(p_boy,"gold")+p_amt);
*/
	call_out("announce_gold",6,p_amt,who->short());
	p_gift[p_id]=p_amt;
	DELAY_D->delay_simple_action(who,"$N献上"+chinese_number(p_amt)+"两金子。\n",2);
	DELAY_D->delay_targetted_action(me,who,"$N收完礼，记完账对$T道：$R请快进去吧。\n",4);
//          fr = new("/wiz/group/firework.c");
          fr = new("/sgdomain/obj/other/firework.c");
	fr->move(who);
	DELAY_D->delay_targetted_action(me,who,"$N笑着对说：这里有只焰火，拿去点着玩吧。\n",6);
}
mixed ask_guanli(object who) {
	string p_id;
	p_id=who->query_primary_id();
	if(p_id==p_boy) 
		return "$N对$T笑道：新郎官开什么玩笑，还不赶快进去。小心新娘跑了。\n";
	if(p_id==p_girl) 
		return "$N对$T笑道：新娘子开什么玩笑，还不赶快进去。\n";
	if(p_gift[p_id])
		return "$N对$T笑道：$m$R已经送过彩礼了，不必客气，请快进去观礼吧。\n";

	this_object()->targetted_action("$N对$T连连鞠躬道谢。\n",who);
	tell(who,"\n你打算送多少礼金，用：%^RED%^answer <数量> to li guan%^RESET%^。回答。\n");
	this_object()->set_answer(p_id, (:answer_guanli:) );
	return 1;
}

void special_answer(object who, string matt)
{
	string p_id;
	mixed ret;
	p_id=who->query_primary_id();
        switch(matt)
        {
                case "xinren" :
			this_object()->targetted_action(
				"$N对$T神秘地道：$R不知：新人乃大名鼎鼎的"+
				p_boyname+"和"+p_girlname+"呀。\n",who);
			return; 

                case "guanli" :
			ret=ask_guanli(who);
			if(stringp(ret)) {
				this_object()->targetted_action(ret,who);
				return;
			}

			return;
        }
}

int query_clean_up() {
	return 1; // if p_life<200 can't clean up
}
