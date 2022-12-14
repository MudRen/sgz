// written by row 
/* Do not remove the headers from this file! see /USAGE for more info. */
#include <mudlib.h>
inherit M_CHAR;
inherit LIVING;
inherit M_BLOCKEXITS;
private mapping names;
object usr1,usr2,usr3;

void begin_ceremony();
void end_ceremony();
void answer_parter(object me, object who, string ans);
mixed ask_parter(object me, object who, string ans);
void answer_agree(object me,object girl,string ans);
mixed find_id(int i) {
	string *ids;
	if(!sizeof(names)) return 0;
	ids=keys(names);
	foreach(string id in ids) {
		if(names[id]==i) return id;
	}
	return 0;
}
string find_names() {
	string ret;
	string id1,id2,id3;
	id1=find_id(1);
	id2=find_id(2);
	id3=find_id(3);

	ret=CHAR_D->get_char(id1,"name");
	if(stringp(id3))
		ret+="、"+CHAR_D->get_char(id2,"name")+"和"+CHAR_D->get_char(id3,"name");
	else
		ret+="和"+CHAR_D->get_char(id2,"name");
	return ret;
}
void setup()
{
    set_name("old guy", "老者");
    set_gender(1);
    set_proper_name("老先生");
    set_in_room_desc("『%^H_YELLOW%^德高望重  平原一叟%^RESET%^』%^H_CYAN%^老者%^RESET%^(old guy)\n");
    add_id("guy");
    set_age(80);
    add_block("south");
    set_block_action( "$N袍袖一拂，笑道：哎，$R别急，仪式马上就要开始了。\n");

    add_ask_str("jieyi",
	"$N对着$T一抱拳，道：我等欲结晋兰之义，望$R主持仪式，不知当否？\n");
    add_question("jieyi","jieyi" );
       names = ([ ]);
}
string long() {
        return
	"一个八十开外的老者，皓发红颜，长须飘飘，令人敬仰之情油然而生。\n";
}
void clear_names(){
        names = ([ ]);
	this_object()->clear_answer();
	remove_call_out("clear_names");
}
mixed ask_jieyi(object who) {
        string p_id=who->query_primary_id();
        int p_gender;
        int p_age;

        p_gender=who->query_gender();

        p_age=who->query_age();
        if(p_age<16) return 
		"$N轻轻拍了拍$T的头，笑道：你们还太小，结义这等大事还是长大些再考虑吧。\n";

        if(sizeof(CHAR_D->get_char(p_id,"jy"))==2) 
                return "$N对$T摇摇头，道：凡事太滥，就失去应有的意义了，是不是？\n";
	if(sizeof(names))
		return "$N对$T笑到：抱歉，老夫有要事缠身，$R请稍后再来！\n";

        return 1;
}
void special_answer(object who, string matt)
{
	mixed ret;
        string p_id;
        p_id=who->query_primary_id();

        if( matt=="jieyi" ){
		ret=ask_jieyi(who);
                if( stringp(ret) ) {
			this_object()->targetted_action(ret,who);
			return;
		}
                this_object()->targetted_action("$N对$T笑到：好，好，$R准备和谁结义呢？\n",who);
                this_object()->set_answer(p_id, (:ask_parter:) );
                tell_user(p_id,"用%^H_RED%^answer <对象ID> to old guy%^RESET%^来回答。\n");
                tell_user(p_id,"若是两个人，则用%^H_RED%^answer <对象ID>,<对象ID> to old guy%^RESET%^来回答。\n");
                names = ([p_id:1]);
                call_out("clear_names", 150);
		return;
        } 
	return ::special_answer(who, matt);
}
mixed check_parter(object me,object who,string ans) {
        string *ids;
        object o_t,o_p;
        string p_id=who->query_primary_id();
        string id1,id2;
        string id1_name,id2_name;
        int num;


        ids=explode(ans,",");
        num=sizeof(ids);
        if(num<1)
		return "$N道：请输入结义对象的ID。\n";
        if(num>2)
        	return "$N道：对不起，结义人数加上你自己最多只能有三人。\n";
        id1=ids[0];
        if(num==2) id2=ids[1];
	if(p_id==id1||p_id==id2||id1==id2)
	return "$N怒道：你开什么玩笑？！\n";
        if(!CHAR_D->char_exist(id1))
		return "$N奇怪地看了$T一眼，道："+id1+"，有这个人吗？\n";
        if(stringp(id2)&&!CHAR_D->char_exist(id2))
		return "$N奇怪地看了$T一眼，道："+id2+"，有这个人吗？\n";
        id1_name=CHAR_D->get_char(id1,"name");
        id2_name=CHAR_D->get_char(id2,"name");

        if(CHAR_D->get_char(id1,"type")!=TYPE_PLAYER)
		return "$N对$T摇头道："+id1_name+"非凡夫俗子，不得参与俗事。\n";
        if(stringp(id2)&&CHAR_D->get_char(id2,"type")!=TYPE_PLAYER)
		return "$N对$T摇头道："+id2_name+"非凡夫俗子，不得参与俗事。\n";
        if((CHAR_D->get_char(id1,"gender"))!=(CHAR_D->get_char(p_id,"gender")))
		return "$N对$T笑笑，道："+id1_name+"与你等既为异性，为何不去找乔国老？\n";
        if(stringp(id2)&&(CHAR_D->get_char(id2,"gender"))!=
		(CHAR_D->get_char(p_id,"gender")))
		return "$N对$T笑笑，道："+id2_name+"与你等既为异性，为何不去找乔国老？\n";
                
        if(CHAR_D->get_char(id1,"age")<16)
		return "$N对$T笑道："+id1_name+"年纪还小，再等一二载吧。\n";
        if(stringp(id2)&&CHAR_D->get_char(id2,"age")<16)
		return "$N对$T笑道："+id2_name+"年纪还小，再等一二载吧。\n";
        if(sizeof(CHAR_D->get_char(id1,"jy")))
                return "$N对$T摇头道："+id1_name+"已经结义过了。\n";
        if(stringp(id2)&&sizeof(CHAR_D->get_char(id2,"jy")))
                return "$N对$T摇头道："+id2_name+"已经结义过了。\n";
        o_t=CHAR_D->find_char(id1);
        o_p=CHAR_D->find_char(id2);
        if(!objectp(o_t))
                return "$N疑惑地对$T道："+id1_name+"没和你一起来吗？\n";
        if(o_t->query_room()!=this_object()->query_room())
                return "$N疑惑地对$T道："+id1_name+"没和你一起来吗？\n";
        if(stringp(id2)&&!objectp(o_p))
                return "$N疑惑地对$T道："+id2_name+"没和你一起来吗？\n";
        if(stringp(id2)&&o_p->query_room()!=this_object()->query_room())
                return "$N疑惑地对$T道："+id2_name+"没和你一起来吗？\n";
	names[id1]=2;
	if(stringp(id2))
		names[id2]=3;
        return 1;

}
mixed ask_parter(object me, object who, string ans)
{
	mixed ret=check_parter(me, who,ans);
	string id2;
	this_object()->clear_answer();
	if(stringp(ret)) {
		this_object()->targetted_action(ret,who);
		clear_names();
		return;
	}
	id2=find_id(2);
	answer_parter(me,who,id2);
}
void answer_parter(object me, object who, string ans) {
        object o_t;
        string p_id;
        p_id=who->query_primary_id();

        o_t=CHAR_D->find_char(ans);
        me->targetted_action("$N对$T到：$R稍待片刻，老夫先问问$o的意见。\n",who,o_t);

        me->targetted_action("$N对$T微笑道：$R愿与$o结义吗？\n",o_t,who);

        tell_user(ans,"若愿意就：%^H_RED%^answer yes to old guy%^RESET%^。\n");
        me->set_answer(ans, (:answer_agree:) );
}
void answer_agree(object me,object tar,string ans) {
        string p_id,id1,id2;
        object who,o_t,ob;
	string *objs;
	object incense1,haiwan1,xiaodao1; 
	object incense2,haiwan2,xiaodao2; 
	object incense3,haiwan3,xiaodao3; 
       me->clear_answer();
	objs=({"/sgdomain/jieyi/oxhead.c","/sgdomain/jieyi/sheephead.c","/sgdomain/jieyi/pighead"});
	id1=find_id(2);
	id2=find_id(3);
	p_id=find_id(1);
	usr1=CHAR_D->find_char(p_id);
	usr2=CHAR_D->find_char(id1);
	usr3=CHAR_D->find_char(id2);
	incense1=present("incense",usr1);
	haiwan1=present("haiwan",usr1);
	xiaodao1=present("xiaodao",usr1);
	incense2=present("incense",usr2);
	haiwan2=present("haiwan",usr2);
	xiaodao2=present("xiaodao",usr2);
        CHAR_D->set_char(id1,"pre_jy",0);
        who=CHAR_D->find_char(p_id);

        if(ans!="yes") {
                me->responda("poor "+p_id);
                me->targetted_action("$N对$T叹了一口气，道：没办法，你们回去考虑好了再来吧。\n",who);
		clear_names();
                return; 
        }
        me->responda("great");
	if(stringp(id2)&&(id2!=tar->query_primary_id())) {
		o_t=CHAR_D->find_char(id2);
	        me->targetted_action("$N对$T到：$R稍待片刻，老夫先问问$o的意见。\n",who,o_t);
	        me->targetted_action("$N对$T微笑道：$R愿与$o结义吗？\n",o_t,who);
	        tell_user(id2,"若愿意就：%^H_RED%^answer yes to old guy%^RESET%^。\n");
	        me->set_answer(id2, (:answer_agree:) );
		return;
	}
	if(!objectp(incense1)||!objectp(xiaodao1)||!objectp(haiwan1)||
	!objectp(incense2)||!objectp(xiaodao2)||!objectp(haiwan2)){
	me->simple_action("$N捋了捋花白的胡须，摇摇头，笑道：嗯，答应是答应了，可祭祀用品没带全，仪式无法进行啊。\n");
	return;
	}
	if(stringp(id2)){
	incense3=present("incense",usr3);
	haiwan3=present("haiwan",usr3);
	xiaodao3=present("xiaodao",usr3);
	if(!objectp(incense3)||!objectp(xiaodao3)||!objectp(haiwan3)){
	me->simple_action("$N捋了捋花白的胡须，摇摇头，笑道：嗯，答应是答应了，可祭祀用品没带全，仪式无法进行啊。\n");
	return;
	}
	}
	tell(users(),"%^H_MAGENTA%^【结义】%^H_YELLOW%^德高望重的%^RESET%^%^H_CYAN%^老者%^RESET%^%^H_MAGENTA%^："+
		find_names()+"愿意结义，仪式即将开始！欢迎各位前来观礼。%^RESET%^\n");
	this_object()->simple_action("$N乐呵呵地道：老夫没什么可送的，就给你们添一样祭祀品吧。\n");
	this_object()->simple_action("$N转身端出一只盘子，放在了%^RED%^香炉%^RESET%^的前面。\n");
	ob=new(objs[random(sizeof(objs))]);
	ob->move(this_object()->query_room());
	CHAR_D->set_char(p_id,"pre_jy",1);
	CHAR_D->set_char(id1,"pre_jy",1);
	if(stringp(id2)){
	CHAR_D->set_char(id2,"pre_jy",1);
	}
	call_out("begin_ceremony",10);
	return;
}
private mixed handle_blocks( string dir )
{
    object room;
    string p_id;
    room=environment(this_object());
    if(!objectp(room)) {SGSYS("I don't know where am i. "); return;}
    p_id=this_body()->query_id()[0];
    if(environment(this_body())->is_horse())
{this_object()->targetted_action("$N指了指$T，道：$R请先下马。\n",this_body());
this_object()->targetted_action("$T一思量：对，还是先下马吧。\n",this_body());}
        if( wizardp(this_body()) ){
        return 0;
        }
	if(CHAR_D->get_char(p_id,"pre_jy")==0){
	return 0;
	}
	return ::handle_blocks(dir);
}
void begin_ceremony()
{
	string str;
	int num;
	string id1,id2,p_id;
	string id1_name,id2_name,p_name;
	id1=find_id(2);
	id2=find_id(3);
	p_id=find_id(1);
	usr1=CHAR_D->find_char(p_id);
	usr2=CHAR_D->find_char(id1);
	usr3=CHAR_D->find_char(id2);
	id1_name=CHAR_D->get_char(id1,"name");
	id2_name=CHAR_D->get_char(id2,"name");
	p_name=CHAR_D->get_char(p_id,"name");
	
	if(stringp(id2)){
	num=3;
	}
	else{
	num=2;
	}
	if(CHAR_D->get_char(p_id,"gender")==1){
	str="兄弟";
	}
	else{
	str="姊妹";
	}
	tell(users(),"%^H_MAGENTA%^【结义】%^H_YELLOW%^德高望重的%^RESET%^%^H_CYAN%^老者%^RESET%^%^H_MAGENTA%^："+
		find_names()+"的结义仪式现在开始！%^RESET%^\n");
	usr1->start_busy(40,"结义仪式正在进行中。");
	usr2->start_busy(40,"结义仪式正在进行中。");
	if(stringp(id2)){
	usr3->start_busy(40,"结义仪式正在进行中。");
	}
	DELAY_D->delay_simple_action(this_object(),"%^H_MAGENTA%^【结义】：%^RESET%^$N咳嗽了一声，正色道：仪式正式开始！\n\n",1);
	DELAY_D->delay_simple_action(this_object(),"%^H_MAGENTA%^【结义】：%^RESET%^$N大声道：%^H_RED%^上香%^RESET%^！\n\n",3);
	DELAY_D->delay_simple_action(usr1,"$N急忙将怀中揣着的%^CYAN%^香%^RESET%^取了出来，凑在%^RED%^香炉%^RESET%^上点燃，再插入炉内。\n",4);
	DELAY_D->delay_simple_action(usr2,"$N也急忙将怀中揣着的%^CYAN%^香%^RESET%^取了出来，凑在%^RED%^香炉%^RESET%^上点燃，再插入炉内。\n",5);
	if(stringp(id2)){
	DELAY_D->delay_simple_action(usr3,"$N不甘落后，也将怀中揣着的%^CYAN%^香%^RESET%^取了出来，凑在%^RED%^香炉%^RESET%^上点燃，再插入炉内。\n",6);
	}
	DELAY_D->delay_simple_action(this_object(),"\n%^CYAN%^顿时空气中充满了淡淡的青烟及香气。%^RESET%^\n\n",8);
	DELAY_D->delay_simple_action(this_object(),"%^H_MAGENTA%^【结义】：%^RESET%^$N整了整自己的衣衫后，又大声道：%^H_RED%^歃血%^RESET%^！\n\n",10);
	DELAY_D->delay_simple_action(usr1,"$N郑重地取出一柄%^MAGENTA%^雕花%^RESET%^小刀，在小臂上刺了一下，将%^H_RED%^血%^RESET%^滴\n"+
	"在早已准备好的盛着女儿红的大海碗里。\n",11);
	DELAY_D->delay_simple_action(usr2,"$N也郑重地取出一柄%^MAGENTA%^雕花%^RESET%^小刀，在小臂上刺了一下，将%^H_RED%^血%^RESET%^滴\n"+
	"在早已准备好的盛着女儿红的大海碗里。\n",12);
	if(stringp(id2)){
	DELAY_D->delay_simple_action(usr3,"$N见状，也立刻取出一柄%^MAGENTA%^雕花%^RESET%^小刀，在小臂上刺了一下，将%^H_RED%^血%^RESET%^滴\n"+
	"在早已准备好的盛着女儿红的大海碗里。\n",13);
	}
	DELAY_D->delay_simple_action(this_object(),"\n%^CYAN%^围观的众人轻轻地发出赞叹之声。%^RESET%^\n\n",15);
	DELAY_D->delay_simple_action(this_object(),"%^H_MAGENTA%^【结义】：%^RESET%^$N微微一笑，道：%^H_RED%^祭天！%^RESET%^\n\n",17);
	DELAY_D->delay_simple_action(this_object(),find_names()+"将海碗捧起，恭恭敬敬地朝天拜祭。\n\n",18);
	DELAY_D->delay_simple_action(this_object(),"%^H_MAGENTA%^【结义】：%^RESET%^$N又道：%^H_RED%^祀地%^RESET%^！\n\n",20);
	DELAY_D->delay_simple_action(this_object(),find_names()+"闻言立刻单膝跪地，庄重地、慢慢地将海碗中的酒洒一半\n"+
	"洒在%^RED%^香炉%^RESET%^前的土中。\n\n",22);
	DELAY_D->delay_simple_action(this_object(),"%^H_MAGENTA%^【结义】：%^RESET%^$N深吸了一口气，缓缓地道：%^H_RED%^誓言%^RESET%^！\n\n",24);
	DELAY_D->delay_simple_action(this_object(),find_names()+"相视一笑，再拜而说誓道：\n\n"+
	"%^H_CYAN%^『念"+find_names()+""+chinese_number(num)+"人，\n"+
      "  虽然异姓，既结为"+str+"，则同心协力，救困扶\n"+
      "  危；上报国家，下安黎庶。不求同年同月同日\n"+
      "  生，只愿同年同月同日死。皇天后土，实鉴此\n"+
      "  心，背义忘恩，天人共戮！』%^RESET%^\n\n",26);
	DELAY_D->delay_simple_action(this_object(),"誓毕，"+chinese_number(num)+"人仰头将余下的%^H_RED%^血%^RESET%^酒一饮而尽。\n\n",28);
	DELAY_D->delay_simple_action(this_object(),"%^CYAN%^围观众人皆被誓言感动，哄然叫道：好！%^RESET%^\n\n",30);
	if(stringp(id2)){
	DELAY_D->delay_simple_action(this_object(),"$N捋着花白的胡子，连连点头，微笑道：很好！如此一来，"+p_name+"为长，"+id1_name+"次\n"+
	"之，"+id2_name+"为幼，从此你们要相亲相爱，同进共退啦。\n\n",32);
	}
	else{
	DELAY_D->delay_simple_action(this_object(),"$N捋着花白的胡子，连连点头，微笑道：很好！如此一来，"+p_name+"为长，"+id1_name+"为\n"+
	"幼，从此你们要相亲相爱，同进共退啦。\n\n",32);
	}
	DELAY_D->delay_simple_action(this_object(),find_names()+""+chinese_number(num)+"人连忙拜道：多谢老丈成全！\n\n",33);
	call_out("end_ceremony",36);
	return;
}
void end_ceremony()
{
	string str;
	string id1,id2,p_id;
	object incense1,haiwan1,xiaodao1; 
	object incense2,haiwan2,xiaodao2; 
	object incense3,haiwan3,xiaodao3; 
	id1=find_id(2);
	id2=find_id(3);
	p_id=find_id(1);

	incense1=present("incense",usr1);
	haiwan1=present("haiwan",usr1);
	xiaodao1=present("xiaodao",usr1);
	incense2=present("incense",usr2);
	haiwan2=present("haiwan",usr2);
	xiaodao2=present("xiaodao",usr2);
	if(CHAR_D->get_char(p_id,"gender")==1){
	str="结义兄弟";
	}
	else{
	str="金兰姊妹";
	}
	tell(users(),"%^H_MAGENTA%^【结义】%^H_YELLOW%^德高望重的%^RESET%^%^H_CYAN%^老者%^RESET%^%^H_MAGENTA%^：仪式结束，"+
		find_names()+"从此为"+str+"，携手共闯三国！%^RESET%^\n");
	if(stringp(id2)){
	CHAR_D->set_char(p_id,"jy",([2:id1,3:id2]));
	CHAR_D->set_char(id1,"jy",([1:p_id,3:id2]));
	CHAR_D->set_char(id2,"jy",([1:p_id,2:id1]));
	CHAR_D->set_char(id1,"pre_jy");
	CHAR_D->set_char(p_id,"pre_jy");
	CHAR_D->set_char(id2,"pre_jy");
	}
	else{
	CHAR_D->set_char(p_id,"jy",([2:id1]));
	CHAR_D->set_char(id1,"jy",([1:p_id]));
	CHAR_D->set_char(p_id,"pre_jy");
	CHAR_D->set_char(id1,"pre_jy");
	}
	destruct(incense1);
	destruct(incense2);
	if(stringp(id2)&&present("incense",usr3)){
	incense3=present("incense",usr3);
	destruct(incense3);
	}
	destruct(xiaodao1);
	destruct(xiaodao2);
	if(stringp(id2)&&present("xiaodao",usr3)){
	xiaodao3=present("xiaodao",usr3);
	destruct(xiaodao3);
	}
	destruct(haiwan1);
	destruct(haiwan2);
	if(stringp(id2)&&present("haiwan",usr3)){
	haiwan3=present("haiwan",usr3);
	destruct(haiwan3);
	}
	return;
}
