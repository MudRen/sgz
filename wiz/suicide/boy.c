// boy.c the body of 问路小男孩

inherit PMODULES+"m_charnpc";

private string my_leader="";
private string my_target;
private mapping my_require=([]);

static string *my_desire=({"mantou"});
//static string *my_desire=({"mantou","niurou","liji","liyu","doufu","kaoya"});

void my_select(string str);
void input_name(string str);
void input_xianren(string str);
void answer_somebody(object who);
void prepare_answer();
void my_select(string str);
void no_answer();
void fail_answer();
void succ_answer();

void setup()
{  
        call_out("my_heart",5);
        add_question("somebody","somebody"); 
        add_ask_str("somebody","$N对$T招了招手：$c，过来，$C向你打听个人，好不好。\n");       
        add_question("xianren","xianren");
        add_ask_str("xianren","$N向$T问到：“不知最近有没有听说什么仙人的消息？\n");     
}
void extra_init()
{
        add_id("boy");
}
string long()
{  
        return "一个调皮的小男孩，浑身脏兮兮，不过看起来非常机灵。\n";
}
void do_my_speak()
{  
        switch(random(5)){  
                case 0:
                        this_object()->simple_action("$N说道：这儿我最熟，没有我不认识的人。\n");
                        break;
                case 1:
                        this_object()->simple_action("$N道：谁能给我块糖吃。\n");
                        break;
                case 2:
                        this_object()->responda("xixi");
                        break;
                case 3:
                        this_object()->responda("kick");
                        break;
                default: 
                this_object()->responda("say 谁要找人找不道，问我准没错。\n");
                break;
        }
}

void do_remove_room() {
        string my_area;
	string room;
	string *rooms;
	int i;
	object o_room;
        my_area=environment(this_object())->get_area();
	rooms=AREA(my_area)->get_room("list");
	if(!sizeof(rooms)) return;

	for(i=0;i<5;++i) {
		room=rooms[random(sizeof(rooms))];
		o_room=find_object(AREA_D->get_area(my_area,"path")+room);
		if(!objectp(o_room)) continue;
//		os=all_inventory(o_room);
//		if(sizeof(os)<2) {
			o_room->clean_up();
//		}
	}
}
void my_charaction()
{  
    int act;
    if( sizeof(my_leader) ){  
                object o=present(my_leader,environment(this_object()));
                if(objectp(o)) return;
                else my_leader="";
        }
        act=random(7);
        switch(act){  
                case 0:
                case 1:
                case 2:
                        do_my_speak();
			break;
                case 3:
                case 4:
                case 5:
			do_my_semote();
			break;
                default:
                        do_my_moving();
			break;
        }
	call_out("do_remove_room",0);
	call_out("do_remove_room",5);
	
}
string assign_desire() {
	string *lst,*mak;
	string typ;
	int val;
	if(random(2)) 
		lst=OBJ_D->check_obj("type","food");
	else
		lst=OBJ_D->check_obj("type","drink");
	typ=lst[random(sizeof(lst))];
	mak=OBJ_D->get_obj_maker(typ);
	if(!sizeof(mak)) return "mantou"; // no place to get it
	val=OBJ_D->get_obj(typ,"value");
	if(val>1500) return "mantou"; // too expensive 20 silver
	return "mantou";
//	return typ;
}
void answer_xianren(object who)
{
        string p_id=who->query_id()[0];
        object o;
        if(present(my_leader,environment(this_object())))
        {
                this_object()->targetted_action("$N对$T道：我正忙着能。\n",who);
                return;
        }
        my_leader=p_id;

        this_object()->targetted_action("$N对$T道：$m要找谁呀。\n",who);
        o=find_user(my_leader);
        if(!objectp(o)) {no_answer(); return;}
        tell_user(my_leader,"请输入要找角色的ID\n");
 tell_user(my_leader,"华陀(hua tuo)，于吉(yu ji)，许邵(xu zijiang)，左慈(zuo ci)，包打听(bao dating)，南华老仙(nanhua laoxian)\n");
        o->modal_push((: input_xianren :),"你打算找谁。");
        call_out("no_answer",60);

}
void answer_somebody(object who)
{
        string p_id=who->query_id()[0];
        object o;
        if(present(my_leader,environment(this_object())))
        {
                this_object()->targetted_action("$N对$T道：我正忙着能。\n",who);
                return;
        }
        my_leader=p_id;
        this_object()->targetted_action("$N对$T道：$m要找谁呀。\n",who);
        o=find_user(my_leader);
        if(!objectp(o)) {no_answer(); return;}
        tell_user(my_leader,"请输入要找角色的ID\n");
        o->modal_push((: input_name :),"你打算找谁。");
        call_out("no_answer",60);

}
void input_xianren(string str)
{       
        object o;
        if(!CHAR_D->char_exist(str))
        {
                write("没有这个角色。\n");
                no_answer();
                return;
        }
        o=find_user(my_leader);
        if(!objectp(o)) {no_answer();return;}
        o->modal_pop();
        my_target=str;
        this_body()->simple_action(
                "$N道：我想找"+CHAR_D->get_char(my_target,"name")+"。\n");

        this_object()->responda("consider");
        call_out("prepare_answer",1);
}
void input_name(string str)
{
        object o;
        if(!CHAR_D->char_exist(str))
        {
                write("没有这个角色。\n");
                no_answer();
                return;
        }
        o=find_user(my_leader);
        if(!objectp(o)) {no_answer();return;}
        o->modal_pop();
        my_target=str;
        this_body()->simple_action(
                "$N道：我想找"+CHAR_D->get_char(my_target,"name")+"。\n");

        this_object()->responda("consider");
        call_out("prepare_answer",1);
}
void prepare_answer()
{
        object o;
        string my_area;

        my_area=environment(this_object())->get_area();
if( my_target!="hua tuo"&&my_target!="xu zijiang"&&my_target!="bao dating"&&my_target!="zuo ci"&&my_target!="yu ji"&&my_target!="nanhua laoxian" ){
            if(CHAR_D->get_char(my_target,"area")!=my_area){
       
         if(CHAR_D->get_char(my_target,"my_area")!=my_area)
                        this_object()->simple_action("$N摇摇头道："+CHAR_D->get_char(my_target,"name")+"？没听说过。大概不住在这个地区吧。\n");
                else
                        this_object()->simple_action("这里有那么多"+CHAR_D->get_char(my_target,"name")+"，我怎么知道你要找哪个。\n");
                DELAY_D->delay_simple_action(this_body(),"$N失望地叹了口气。\n",1);
                remove_call_out("no_answer");
                my_leader=""; 
                return;
           }
        }
        if(!my_require) my_require=([]);
        if(!my_require[my_target])
                my_require[my_target]=assign_desire();


        this_object()->simple_action("$N道："+CHAR_D->get_char(my_target,"name")+"嘛，我知道在哪儿，不过你要给我一份"+
		OBJ_D->get_obj(my_require[my_target],"name")+"("+my_require[my_target]+")。我才告诉你。\n");
//        destruct(o);
        
        o=find_user(my_leader);
        if(!objectp(o)){
                no_answer(); 
                return;
        }
        tell_user(my_leader, "请输入对策：1 ：给钱，2 ：给糖， 3：答应要求， 0 ：放弃\n");
        o->modal_push((: my_select :), "请输入对策：1 ：给钱，2 ：给糖，3：答应要求， 0 ：放弃\n");
}
void my_select(string str)
{
        object o=find_user(my_leader);
        if(!objectp(o)){no_answer();return;}
        if((str!="0")&&(str!="1")&&(str!="2")&&(str!="3"))
                return;
        o->modal_pop();
        remove_call_out("no_answer");
        switch(str)
        {
        case "1":  // give money
                this_body()->targetted_action(
                        "$N拍拍$T的头说，你要的东西我没有，给你一两金子，你自己看着去买吧。\n",
        this_object());
         if(this_body()->query_all_con_money()<10000)
         {
            DELAY_D->delay_simple_action(this_object(),
                                "$N道：你哪有钱，骗人。\n",1);
                        call_out("fail_answer",2);
         }
         else
         {  this_body()->set_all_con_money( 
                                this_body()->query_all_con_money() -10000);
            DELAY_D->delay_simple_action(this_object(),
                                "$N高兴地跳了起来。\n",1);
            DELAY_D->delay_targetted_action(this_body(),this_object(),
                                "$N给$T一两金子。\n",2);
                        call_out("succ_answer",3);
         }
         break;
        case "2":
                this_body()->targetted_action(
                      "$N拍拍$T的头说，你要的东西我没有，给你一块糖，你看好不好。\n",
         this_object());
        {
                        
                        o=present("candy",this_body());
                        if(!objectp(o))
                        {
                                DELAY_D->delay_simple_action(this_object(),
                                        "$N道：你哪有糖，骗人。\n",1);
                                call_out("fail_answer",2);
                        }
                        else
                        {   string c_id=o->query_chinese_id();
                                destruct(o);
                                DELAY_D->delay_simple_action(this_object(),
                                "$N高兴地跳了起来。\n",1);
                   DELAY_D->delay_targetted_action(this_body(),this_object(),
                                "$N给$T一块"+c_id+"。\n",2);
                                call_out("succ_answer",3);
                        }
         }
         break;
        case "3":
                this_body()->targetted_action(
                        "$N拍拍$T的头说：好吧，就答应你的条件吧。\n",this_object());
        {
                        o=present(my_require[my_target],this_body());
                        if(!objectp(o))
                        {
                                DELAY_D->delay_simple_action(this_object(),
                                        "$N道：你哪有我想要的，骗人。\n",1);
                                call_out("fail_answer",2);
                        }
                        else
                        {   string c_id=o->query_chinese_id();
                                destruct(o);
                                DELAY_D->delay_simple_action(this_object(),
                                "$N高兴地跳了起来。\n",1);
                   DELAY_D->delay_targetted_action(this_body(),this_object(),
                                "$N给$T一份"+c_id+"。\n",2);
                                call_out("succ_answer",3);
                        }
         }
         break;
        default:
                this_body()->targetted_action("$N对$T道：算了，不问你了。\n",
   this_object());
                call_out("fail_answer",1);
                break;
        }
}
void succ_answer()
{
    object o,env;
        map_delete( my_require, my_target);
        my_leader="";

        o=CHAR_D->find_char(my_target);

        if(!objectp(o))
        {
                CHAR_D->appear(my_target,CHAR_D->get_char(my_target,"area"));
	        o=CHAR_D->find_char(my_target);
        }
        if(!objectp(o))
        {
                SGSYS("CAN'T FIND "+my_target);
                this_object()->simple_action
           ("$N皱了皱眉头，奇怪，我怎么又想不起他在哪儿了。\n");
                return;
        }
        env=o->query_room();
        if(!objectp(env))
        {
                SGSYS("CAN'T FIND "+my_target+"'s ROOM");
                this_object()->simple_action
        ("$N皱了皱眉头，奇怪，我怎么又想不起他在哪儿了。\n");
                return;
        }
        this_object()->responda("say "+CHAR_D->get_char(my_target,"name")+
                "现在正在"+
                AREA_D->get_area(env->get_area(),"name")+"的"+
                env->short()+"。\n");
        return;
}
void fail_answer()
{
        this_object()->simple_action("$N哼道：小气鬼。\n");
        this_object()->responda("kick "+my_leader);
        my_leader="";
        return;
}

void special_answer(object who, string matt)
{
  switch(matt)
  {
      case "somebody" :
         answer_somebody(who);
	 return;
      case "xianren" :
         answer_xianren(who);
       return;
  }
}
void no_answer()
{
        object o;
        remove_call_out("no_answer");
        this_object()->simpl_action("$N不耐烦地道：怎么这么罗嗦呀，不干了，不干了。\n");
        o=find_user(my_leader);
        if(objectp(o))
                o->modal_pop();
        my_leader="";
}
int is_busy()
{
        if(find_body(my_leader)) return 1;
        return 0;
}
// so will not be clean_up
int query_clean_up() {
	return 1;
}
