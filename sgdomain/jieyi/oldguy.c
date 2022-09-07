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
		ret+="��"+CHAR_D->get_char(id2,"name")+"��"+CHAR_D->get_char(id3,"name");
	else
		ret+="��"+CHAR_D->get_char(id2,"name");
	return ret;
}
void setup()
{
    set_name("old guy", "����");
    set_gender(1);
    set_proper_name("������");
    set_in_room_desc("��%^H_YELLOW%^�¸�����  ƽԭһ��%^RESET%^��%^H_CYAN%^����%^RESET%^(old guy)\n");
    add_id("guy");
    set_age(80);
    add_block("south");
    set_block_action( "$N����һ����Ц��������$R�𼱣���ʽ���Ͼ�Ҫ��ʼ�ˡ�\n");

    add_ask_str("jieyi",
	"$N����$Tһ��ȭ�������ҵ��������֮�壬��$R������ʽ����֪����\n");
    add_question("jieyi","jieyi" );
       names = ([ ]);
}
string long() {
        return
	"һ����ʮ��������ߣ�𩷢���գ�����ƮƮ�����˾���֮����Ȼ������\n";
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
		"$N����������$T��ͷ��Ц�������ǻ�̫С��������ȴ��»��ǳ���Щ�ٿ��ǰɡ�\n";

        if(sizeof(CHAR_D->get_char(p_id,"jy"))==2) 
                return "$N��$Tҡҡͷ����������̫�ģ���ʧȥӦ�е������ˣ��ǲ��ǣ�\n";
	if(sizeof(names))
		return "$N��$TЦ������Ǹ���Ϸ���Ҫ�²���$R���Ժ�������\n";

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
                this_object()->targetted_action("$N��$TЦ�����ã��ã�$R׼����˭�����أ�\n",who);
                this_object()->set_answer(p_id, (:ask_parter:) );
                tell_user(p_id,"��%^H_RED%^answer <����ID> to old guy%^RESET%^���ش�\n");
                tell_user(p_id,"���������ˣ�����%^H_RED%^answer <����ID>,<����ID> to old guy%^RESET%^���ش�\n");
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
		return "$N�����������������ID��\n";
        if(num>2)
        	return "$N�����Բ��𣬽��������������Լ����ֻ�������ˡ�\n";
        id1=ids[0];
        if(num==2) id2=ids[1];
	if(p_id==id1||p_id==id2||id1==id2)
	return "$Nŭ�����㿪ʲô��Ц����\n";
        if(!CHAR_D->char_exist(id1))
		return "$N��ֵؿ���$Tһ�ۣ�����"+id1+"�����������\n";
        if(stringp(id2)&&!CHAR_D->char_exist(id2))
		return "$N��ֵؿ���$Tһ�ۣ�����"+id2+"�����������\n";
        id1_name=CHAR_D->get_char(id1,"name");
        id2_name=CHAR_D->get_char(id2,"name");

        if(CHAR_D->get_char(id1,"type")!=TYPE_PLAYER)
		return "$N��$Tҡͷ����"+id1_name+"�Ƿ������ӣ����ò������¡�\n";
        if(stringp(id2)&&CHAR_D->get_char(id2,"type")!=TYPE_PLAYER)
		return "$N��$Tҡͷ����"+id2_name+"�Ƿ������ӣ����ò������¡�\n";
        if((CHAR_D->get_char(id1,"gender"))!=(CHAR_D->get_char(p_id,"gender")))
		return "$N��$TЦЦ������"+id1_name+"����ȼ�Ϊ���ԣ�Ϊ�β�ȥ���ǹ��ϣ�\n";
        if(stringp(id2)&&(CHAR_D->get_char(id2,"gender"))!=
		(CHAR_D->get_char(p_id,"gender")))
		return "$N��$TЦЦ������"+id2_name+"����ȼ�Ϊ���ԣ�Ϊ�β�ȥ���ǹ��ϣ�\n";
                
        if(CHAR_D->get_char(id1,"age")<16)
		return "$N��$TЦ����"+id1_name+"��ͻ�С���ٵ�һ���ذɡ�\n";
        if(stringp(id2)&&CHAR_D->get_char(id2,"age")<16)
		return "$N��$TЦ����"+id2_name+"��ͻ�С���ٵ�һ���ذɡ�\n";
        if(sizeof(CHAR_D->get_char(id1,"jy")))
                return "$N��$Tҡͷ����"+id1_name+"�Ѿ�������ˡ�\n";
        if(stringp(id2)&&sizeof(CHAR_D->get_char(id2,"jy")))
                return "$N��$Tҡͷ����"+id2_name+"�Ѿ�������ˡ�\n";
        o_t=CHAR_D->find_char(id1);
        o_p=CHAR_D->find_char(id2);
        if(!objectp(o_t))
                return "$N�ɻ�ض�$T����"+id1_name+"û����һ������\n";
        if(o_t->query_room()!=this_object()->query_room())
                return "$N�ɻ�ض�$T����"+id1_name+"û����һ������\n";
        if(stringp(id2)&&!objectp(o_p))
                return "$N�ɻ�ض�$T����"+id2_name+"û����һ������\n";
        if(stringp(id2)&&o_p->query_room()!=this_object()->query_room())
                return "$N�ɻ�ض�$T����"+id2_name+"û����һ������\n";
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
        me->targetted_action("$N��$T����$R�Դ�Ƭ�̣��Ϸ�������$o�������\n",who,o_t);

        me->targetted_action("$N��$T΢Ц����$RԸ��$o������\n",o_t,who);

        tell_user(ans,"��Ը��ͣ�%^H_RED%^answer yes to old guy%^RESET%^��\n");
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
                me->targetted_action("$N��$T̾��һ����������û�취�����ǻ�ȥ���Ǻ��������ɡ�\n",who);
		clear_names();
                return; 
        }
        me->responda("great");
	if(stringp(id2)&&(id2!=tar->query_primary_id())) {
		o_t=CHAR_D->find_char(id2);
	        me->targetted_action("$N��$T����$R�Դ�Ƭ�̣��Ϸ�������$o�������\n",who,o_t);
	        me->targetted_action("$N��$T΢Ц����$RԸ��$o������\n",o_t,who);
	        tell_user(id2,"��Ը��ͣ�%^H_RED%^answer yes to old guy%^RESET%^��\n");
	        me->set_answer(id2, (:answer_agree:) );
		return;
	}
	if(!objectp(incense1)||!objectp(xiaodao1)||!objectp(haiwan1)||
	!objectp(incense2)||!objectp(xiaodao2)||!objectp(haiwan2)){
	me->simple_action("$N�����ۻ��׵ĺ��룬ҡҡͷ��Ц�����ţ���Ӧ�Ǵ�Ӧ�ˣ��ɼ�����Ʒû��ȫ����ʽ�޷����а���\n");
	return;
	}
	if(stringp(id2)){
	incense3=present("incense",usr3);
	haiwan3=present("haiwan",usr3);
	xiaodao3=present("xiaodao",usr3);
	if(!objectp(incense3)||!objectp(xiaodao3)||!objectp(haiwan3)){
	me->simple_action("$N�����ۻ��׵ĺ��룬ҡҡͷ��Ц�����ţ���Ӧ�Ǵ�Ӧ�ˣ��ɼ�����Ʒû��ȫ����ʽ�޷����а���\n");
	return;
	}
	}
	tell(users(),"%^H_MAGENTA%^�����塿%^H_YELLOW%^�¸����ص�%^RESET%^%^H_CYAN%^����%^RESET%^%^H_MAGENTA%^��"+
		find_names()+"Ը����壬��ʽ������ʼ����ӭ��λǰ������%^RESET%^\n");
	this_object()->simple_action("$N�ֺǺǵص����Ϸ�ûʲô���͵ģ��͸�������һ������Ʒ�ɡ�\n");
	this_object()->simple_action("$Nת��˳�һֻ���ӣ�������%^RED%^��¯%^RESET%^��ǰ�档\n");
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
{this_object()->targetted_action("$Nָ��ָ$T������$R��������\n",this_body());
this_object()->targetted_action("$Tһ˼�����ԣ�����������ɡ�\n",this_body());}
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
	str="�ֵ�";
	}
	else{
	str="���";
	}
	tell(users(),"%^H_MAGENTA%^�����塿%^H_YELLOW%^�¸����ص�%^RESET%^%^H_CYAN%^����%^RESET%^%^H_MAGENTA%^��"+
		find_names()+"�Ľ�����ʽ���ڿ�ʼ��%^RESET%^\n");
	usr1->start_busy(40,"������ʽ���ڽ����С�");
	usr2->start_busy(40,"������ʽ���ڽ����С�");
	if(stringp(id2)){
	usr3->start_busy(40,"������ʽ���ڽ����С�");
	}
	DELAY_D->delay_simple_action(this_object(),"%^H_MAGENTA%^�����塿��%^RESET%^$N������һ������ɫ������ʽ��ʽ��ʼ��\n\n",1);
	DELAY_D->delay_simple_action(this_object(),"%^H_MAGENTA%^�����塿��%^RESET%^$N��������%^H_RED%^����%^RESET%^��\n\n",3);
	DELAY_D->delay_simple_action(usr1,"$N��æ�����д��ŵ�%^CYAN%^��%^RESET%^ȡ�˳���������%^RED%^��¯%^RESET%^�ϵ�ȼ���ٲ���¯�ڡ�\n",4);
	DELAY_D->delay_simple_action(usr2,"$NҲ��æ�����д��ŵ�%^CYAN%^��%^RESET%^ȡ�˳���������%^RED%^��¯%^RESET%^�ϵ�ȼ���ٲ���¯�ڡ�\n",5);
	if(stringp(id2)){
	DELAY_D->delay_simple_action(usr3,"$N�������Ҳ�����д��ŵ�%^CYAN%^��%^RESET%^ȡ�˳���������%^RED%^��¯%^RESET%^�ϵ�ȼ���ٲ���¯�ڡ�\n",6);
	}
	DELAY_D->delay_simple_action(this_object(),"\n%^CYAN%^��ʱ�����г����˵��������̼�������%^RESET%^\n\n",8);
	DELAY_D->delay_simple_action(this_object(),"%^H_MAGENTA%^�����塿��%^RESET%^$N�������Լ����������ִ�������%^H_RED%^�Ѫ%^RESET%^��\n\n",10);
	DELAY_D->delay_simple_action(usr1,"$N֣�ص�ȡ��һ��%^MAGENTA%^��%^RESET%^С������С���ϴ���һ�£���%^H_RED%^Ѫ%^RESET%^��\n"+
	"������׼���õ�ʢ��Ů����Ĵ����\n",11);
	DELAY_D->delay_simple_action(usr2,"$NҲ֣�ص�ȡ��һ��%^MAGENTA%^��%^RESET%^С������С���ϴ���һ�£���%^H_RED%^Ѫ%^RESET%^��\n"+
	"������׼���õ�ʢ��Ů����Ĵ����\n",12);
	if(stringp(id2)){
	DELAY_D->delay_simple_action(usr3,"$N��״��Ҳ����ȡ��һ��%^MAGENTA%^��%^RESET%^С������С���ϴ���һ�£���%^H_RED%^Ѫ%^RESET%^��\n"+
	"������׼���õ�ʢ��Ů����Ĵ����\n",13);
	}
	DELAY_D->delay_simple_action(this_object(),"\n%^CYAN%^Χ�۵���������ط�����֮̾����%^RESET%^\n\n",15);
	DELAY_D->delay_simple_action(this_object(),"%^H_MAGENTA%^�����塿��%^RESET%^$N΢΢һЦ������%^H_RED%^���죡%^RESET%^\n\n",17);
	DELAY_D->delay_simple_action(this_object(),find_names()+"���������𣬹��������س���ݼ���\n\n",18);
	DELAY_D->delay_simple_action(this_object(),"%^H_MAGENTA%^�����塿��%^RESET%^$N�ֵ���%^H_RED%^���%^RESET%^��\n\n",20);
	DELAY_D->delay_simple_action(this_object(),find_names()+"�������̵�ϥ��أ�ׯ�صء������ؽ������еľ���һ��\n"+
	"����%^RED%^��¯%^RESET%^ǰ�����С�\n\n",22);
	DELAY_D->delay_simple_action(this_object(),"%^H_MAGENTA%^�����塿��%^RESET%^$N������һ�����������ص���%^H_RED%^����%^RESET%^��\n\n",24);
	DELAY_D->delay_simple_action(this_object(),find_names()+"����һЦ���ٰݶ�˵�ĵ���\n\n"+
	"%^H_CYAN%^����"+find_names()+""+chinese_number(num)+"�ˣ�\n"+
      "  ��Ȼ���գ��Ƚ�Ϊ"+str+"����ͬ��Э����������\n"+
      "  Σ���ϱ����ң��°�����������ͬ��ͬ��ͬ��\n"+
      "  ����ֻԸͬ��ͬ��ͬ���������������ʵ����\n"+
      "  �ģ��������������˹�¾����%^RESET%^\n\n",26);
	DELAY_D->delay_simple_action(this_object(),"�ıϣ�"+chinese_number(num)+"����ͷ�����µ�%^H_RED%^Ѫ%^RESET%^��һ��������\n\n",28);
	DELAY_D->delay_simple_action(this_object(),"%^CYAN%^Χ�����˽Ա����Ըж�����Ȼ�е����ã�%^RESET%^\n\n",30);
	if(stringp(id2)){
	DELAY_D->delay_simple_action(this_object(),"$N���Ż��׵ĺ��ӣ�������ͷ��΢Ц�����ܺã����һ����"+p_name+"Ϊ����"+id1_name+"��\n"+
	"֮��"+id2_name+"Ϊ�ף��Ӵ�����Ҫ�����మ��ͬ����������\n\n",32);
	}
	else{
	DELAY_D->delay_simple_action(this_object(),"$N���Ż��׵ĺ��ӣ�������ͷ��΢Ц�����ܺã����һ����"+p_name+"Ϊ����"+id1_name+"Ϊ\n"+
	"�ף��Ӵ�����Ҫ�����మ��ͬ����������\n\n",32);
	}
	DELAY_D->delay_simple_action(this_object(),find_names()+""+chinese_number(num)+"����æ�ݵ�����л���ɳ�ȫ��\n\n",33);
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
	str="�����ֵ�";
	}
	else{
	str="�������";
	}
	tell(users(),"%^H_MAGENTA%^�����塿%^H_YELLOW%^�¸����ص�%^RESET%^%^H_CYAN%^����%^RESET%^%^H_MAGENTA%^����ʽ������"+
		find_names()+"�Ӵ�Ϊ"+str+"��Я�ֹ���������%^RESET%^\n");
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
