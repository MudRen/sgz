//**********************************************// write by benben 29/12/97 benben.c С����#include <mudlib.h>inherit LIVING;inherit M_ACTIONS;inherit M_TRIGGERS;void setup() {    set_name("ben ben", "С����");    add_id("ben ben","ben","С����");    set_gender(2);    set_proper_name("С����");    set_in_room_desc("�������С����(Ben ben)");    set_long("С������æ����ͷ�󺹣���������ء�һ̧ͷ�����㣺\n"+"�������Ÿ���������æ������Щ�ó������üһ��\n\n");	add_question("food","food");}void special_answer(object who, string matt){	switch(matt)	{		case "food" :			this_object()->simple_action("С�����˸߲��ҵ�˵���������������͡�����ȫϯ�����������ǳ�����OKȥ����\n");			return;	}
    set_actions( 2, ({
        "say ������ƭ����",
            "say �ҿ�û�������㡣",
            "say �һ��Ǹ��󻵵���",
            "say ��",
            "say С��������û��������������ȥ�ˡ�",
            "say ����������Խ��Խ��������ôȫ������ѽ��",
            "say ����ôû���·������Ҽң�",
            "say û�����ˣ������ȥ��һƿ�ɣ�",
            "say ",
            "heng",
            "grin"
            }) );
     add_pattern("%sͻȻ������һ�������С�",function(){
        if ($1=="С����")
        {
                respond("jump");
        }
        if ($1=="�һ�")
        {
                respond("kick fire");
                respond("heng fire");
        }
        else
        {
                respond("smile");
                respond("welcome");
        }
        });

    add_pattern("%sһ���ߵ���%s��",function(){ 
	respond("kick $1");
   	respond("chat *slogan $1");
} );
}