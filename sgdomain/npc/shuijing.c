// written by yuner and fire 
// modified by suicide at Aug 31 2000
/* Do not remove the headers from this file! see /USAGE for more info. */
#include <mudlib.h>
#include <sanguo.h>
#include <localtime.h>
inherit LIVING;
inherit M_ACTIONS;
inherit M_TRIGGERS;
inherit CHINESE_DA;
inherit M_GREETER;
private *name_list=({ });

//! ������ʲô���ӣ���Ҫ��Ҫ����
int check_date( object who );

//! ����ڵ�����
void gift_nationalday( object who );

string *query_channel_list() {
    return ({ "plyr_gossip" });
}

void greet(object o)
{
write("\n%^CYAN%^ˮ������Ц��ӯӯ�߹������Ͱ���˵����\n��ӭ���������ͣ�����ǵ�һ����һ��Ҫ��������ָ��Ŷ(look board)����\n"+
      "������ʲô����Ҫ�Ұ����Ļ���������(ask shuijing about all)��\n");
if (CHAR_D->char_exist(o->query_primary_id())) return;
else 
write("%^CYAN%^���������է�����ҿ�����ֻС�����������·����Ҫ�Ļ���(ask shuijing about pet)��\n");
    
}



void do_greet(object o) 
{
call_out("greet",1,o);
}


void learn_sj(object who)
{
  int p_res;
  string p_st;
  p_res=LEARNCHECK_D->check_can_learn_skills("jbsj",20);
  switch(p_res)
  {
	case TOO_TIRED:
this_object()->targetted_action("$N��$TЦ��������̫���ˣ���Ϣ�������ѧ%^H_GREEN%^ˮ��֮��%^RESET%^�ɡ���\n",who);
		return;
   	case LESS_LITERATE:
                        this_object()->targetted_action("$N��$T���������ѧ������������Щ�����������׵ġ�\n",this_body());
			return;
	case TOO_EASY:
this_object()->targetted_action("$N��$TЦ���������������������%^H_GREEN%^ˮ��֮��%^RESET%^�ء���\n",who);
		return;
	case LESS_EXP:
		this_object()->targetted_action("$N��$TЦ���������鲻����ֻ������Ҳ�̲�����ѽ����\n",who);
		return;
	case CAN_LEARN:
        this_object()->targetted_action("$N��$T�����%^H_GREEN%^ˮ��֮��%^RESET%^���÷���\n",who);
  		p_st=SG_SKILL_D->query_get("jbsj");
  		who->simple_action(p_st);
  		return;
	default :
		write("��֪Ϊʲô�������㣬������ʦ�ɡ�\n");
  }
  return;
}

void setup()
{
    set_name("shuijing xiansheng", "ˮ������");
    set_gender(1);
    set_proper_name("ˮ������");
    set_in_room_desc("\n%^H_YELLOW%^ˮ������%^RESET%^(shuijing xiansheng)");
    add_id("shuijing");
    add_id("sx");
    add_id("xiansheng");
    set_age(70);
    set_long("     
      һ����ʮ��������ߣ��ɷ���ǣ�
����˸˸�� ���۳������ǻ۵Ĺ�â��
Ҫ����ʲô�����ģ����������������� ");
	add_question("name","name" );
	add_question("here","here");
	add_question("news","news");
	add_question("rumors","rumors");
	add_question("help","help");
	add_question("money","money");
	add_question("shouming","shouming");
	add_question("jbsj","jbsj");
//        add_question("luoyang","luoyang");
	add_question("newyear","newyear");
	add_question("pet","pet");
	add_question("valentine","valentine");

// edc 
//	add_question("compensation", "compensation");
////

// xiaobai: ������(ͨ��)
	add_question( "gift", "gift" );
//// xiaobai

    add_pattern("%s���˹�����", (: "say " + $1 + "���������ӭ���������ͣ�
�ȶ���(read)���ɣ�" :) );
    add_pattern("%s����LIMA��", (: "say " + $1 + "���������ӭ���������ͣ�
�ȶ���(read)���ɣ�" :) ); 
        init_greet();
}

// ������ʲô���ӣ���Ҫ��Ҫ����������һ��Ϊ10��
int check_date( object who )
{
    string p_id;
	mixed *local;
	int nRet = 0;
	int bSpecial = 0;  // �ǲ����ر������ 

    // ����Ƿ񶨾ӽ�ɫ��ֻ�ж��ӽ�ɫ��������
    p_id=who->query_primary_id();
    if( CHAR_D->char_exist(p_id) )
    {
   		this_object()->targetted_action("$N��$TЦ����"+
            "�Ƕ����˵Ľ�ɫѽ���ã��á�����\n",who);
        
    }
    else
    {
		this_object()->targetted_action("$N��$TЦ����"+
            "ֻ�ж��ӵ���Ҳ������$R��û�ж��ӣ�����ȥ���Ӱɡ�\n",who);
        return 0;
    }

    local = localtime( time() );    
    // �����
    if ( ( local[LT_MON] == 9 ) && ( local[LT_MDAY] > 0 && local[LT_MDAY] < 11 ) )
    {
        bSpecial = 1;
        
        if( CHAR_D->get_char( p_id, "nationalday_year" ) < local[LT_YEAR] )
        {
            nRet = 1;
            
            // ��¼�������������
            CHAR_D->set_char( p_id, "nationalday_year", local[LT_YEAR] );
            
            // ������
            gift_nationalday( who );
        }
        else
        {
             this_object()->targetted_action("$N��$TЦ����"+
                 "$R�Ĺ��������������Ѿ�����ˣ�ǧ��Ҫ̫̰�İ���\n",who);
        }
               
    }
    
    if ( !bSpecial )
    {
        this_object()->targetted_action("$N����$Tһ�ۣ�����"+
            "��Ե�޹ʵģ���ʲô���\n",who);

    }
        
    return nRet;

}  // end check_date

//! ����ڵ�����
void gift_nationalday( object who )
{
    string p_id;
    int num,offset;
    object ob;
    
    p_id=who->query_primary_id();
                
    this_object()->targetted_action("$N��$TЦ����"+
        "����ڼ������Ҷ��ø߸����ˣ������˵���Ҷ��������Ȼ��$Rһ�ݡ�\n",who);
  	num =  2000 + random( 3000 );
    CHAR_D->add_honor_point( p_id, num );
    
    who->simple_action("$N�õ���"+chinese_number(num)+
    	"���������㡣\n");
    num=100;
    MONEY_D->add_poket_money( who, num*10000 );
    who->simple_action("$N�õ���"+chinese_number(num)+
    	"���ƽ�\n");
    ob=new("/sgdomain/obj/other/shoyu");
    ob->move(who);
    who->simple_action("$N�õ��˺����ױ�������\n");
    who->responda("jump shuijing");
	ob=new( "/sgdomain/obj/other/firework" );
	ob->move( who );
	who->simple_action("$N�õ���һö�̻���\n");
    this_object()->targetted_action("$N��$TЦ����"+
        "�á�light firework�������̻���\n",who);
    this_object()->targetted_action("$N��$TЦ����"+
        "����ѽڣ�������Բ��\n",who);
    ob = OBJ_D->clone_obj( "mooncake" );
	ob->move( who );
	who->simple_action("$N�õ���һ���ִ���Բ���±���\n");
    who->responda("mobai shuijing");

}  // end gift_nationalday

void newyear_gift(object who) {
	string p_id;
	int num,offset;
	object ob;
	mixed *local;
// this_object()->targetted_action("$N��$TЦ����"+
//"��������ˣ�����������ˡ�\n",who);
//return;
	p_id=who->query_primary_id();
	if(!CHAR_D->char_exist(p_id)) {
			this_object()->targetted_action("$N��$TЦ����"+
"ֻ�ж��ӵ���Ҳ�����������$R��û�ж��ӣ�����ȥ���Ӱɡ�\n",who);
 			return;
	}
/*	if(CHAR_D->get_char(p_id,"hon")>=50) {
			this_object()->targetted_action("$N��$TЦ����"+
"$R���������Ѿ�����ˡ�\n",who);
 			return;
	}
*/
        local = localtime(time());
        
        if (local[LT_MON]!=0)
        {
         this_object()->targetted_action("$N��$TЦ����"+
         "$R����һ���������Ѿ����ˣ����ǵ�����ɡ�\n",who);
         return;
        }
        if(CHAR_D->get_char(p_id,"new_year")>=local[LT_YEAR])
        {
         this_object()->targetted_action("$N��$TЦ����"+
         "$R���������Ѿ�����ˣ�ǧ��Ҫ̫̰�İ���\n",who);
         return;
        }
        
        
	this_object()->targetted_action("$N��$TЦ����"+
        "���굽�ˣ�����˵�ˣ������˵���Ҷ��к������Ȼ��$Rһ�ݡ�\n",who);
        
       	num=2688;
	CHAR_D->add_honor_point(p_id,num);
	who->simple_action("$N�õ���"+chinese_number(num)+
		"���������㡣\n");
	num=50;
	MONEY_D->add_poket_money(who,num*10000);
	who->simple_action("$N�õ���"+chinese_number(num)+
		"���ƽ�\n");
	ob=new("/sgdomain/obj/other/shoyu");
	ob->move(who);
	who->simple_action("$N�õ��˺����ױ�������\n");
	CHAR_D->set_char(p_id,"new_year",local[LT_YEAR]);
	who->responda("jump shuijing");
	
}

void valentine_gift(object who)
{
	string p_id;
	int num,offset;
	object ob;
	mixed *local;
// this_object()->targetted_action("$N��$TЦ����"+
//"��������ˣ�����������ˡ�\n",who);
//return;
	p_id=who->query_primary_id();
	if(!CHAR_D->char_exist(p_id)) {
			this_object()->targetted_action("$N��$TЦ����"+
"ֻ�ж��ӵ���Ҳ������˽����$R��û�ж��ӣ�����ȥ���Ӱɡ�\n",who);
 			return;
	}
/*	if(CHAR_D->get_char(p_id,"hon")>=50) {
			this_object()->targetted_action("$N��$TЦ����"+
"$R���������Ѿ�����ˡ�\n",who);
 			return;
	}
*/
        local = localtime(time());
        
        if ((local[LT_MON]!=1) || (local[LT_MDAY]!=14))
        {
         this_object()->targetted_action("$N��$TЦ����"+
         "$R����һ�������˽��Ѿ����ˣ����ǵ�����ɡ�\n",who);
         return;
        }
        if(CHAR_D->get_char(p_id,"love_year")>=local[LT_YEAR])
        {
         this_object()->targetted_action("$N��$TЦ����"+
         "$R�����˽������Ѿ�����ˣ�ǧ��Ҫ̫̰�İ���\n",who);
         return;
        }
        
        
	this_object()->targetted_action("$N��$TЦ����"+
        "���굽�ˣ�����˵�ˣ������˵���Ҷ������˽������Ȼ��$Rһ�ݡ�\n",who);
        CHAR_D->set_char(p_id,"love_year",local[LT_YEAR]);
       	num=2688;
	CHAR_D->add_honor_point(p_id,num);
	who->simple_action("$N�õ���"+chinese_number(num)+
		"���������㡣\n");
	num=50;
	MONEY_D->add_poket_money(who,num*10000);
	who->simple_action("$N�õ���"+chinese_number(num)+
		"���ƽ�\n");
	ob=new("/sgdomain/obj/other/shoyu");
	ob->move(who);
	who->simple_action("$N�õ��˺����ױ�������\n");
	CHAR_D->set_char(p_id,"new_year",local[LT_YEAR]);
	who->responda("jump shuijing");
	ob=new("/wiz/chun/rose");
	ob->move(who);
	who->simple_action("$N�õ���һ֦���޻���õ�壬�Ͽ�ȥ�͸����İ����˰ɡ�\n");
	who->responda("jump shuijing");
	who->set_gini("lin");
	who->simple_action("$N���������ô��į������һ��Ѿ�߰ɣ�������ô�ٻ��������Լ������ɡ�\n");
	who->responda("mobai shuijing");

}

// һ�дӼ�, copy/paste from valentine_gift(), deadline: 09/2001
// edc
void compensation_honour(object who) {
	string p_id;
	int num,offset;
	object ob;
	mixed *local;
	int old_hon, age;

	p_id=who->query_primary_id();
	if(!CHAR_D->char_exist(p_id)) {
		this_object()->targetted_action("$N��$TЦ����"+
		"ֻ�ж��ӵ���Ҳ��в�����$R��û�ж��ӣ�����ȥ���Ӱɡ�\n",who);
 			return;
	}

        local = localtime(time());
        
        if ( (local[LT_MON]>8) ||
        	( ( local[LT_MON] == 8 ) && ( local[LT_MDAY] >= 10) )
        	|| (local[LT_YEAR]>2001) )
        {
         this_object()->targetted_action("$N��Ȧ���ض�$T˵����"+
         	"$R����һ�������������Ѿ�������ϣ��ÿ���Ŷ~\n",who);
         return;
        }
        
        // isComensate: 1   ���� 07/2001 restart ����ʧ 10K honour
        // �Ժ��������������, ���԰����ֵ�ó���������
        if(CHAR_D->get_char(p_id,"isCompensate") == 1)
        {
         this_object()->targetted_action("$N��$TЦ����"+
         	"$R�Ĳ��������Ѿ�����ˣ�ǧ��Ҫ̫̰�İ���\n",who);
         return;
        }
        
        
	this_object()->targetted_action("$N��$T���˵�ͷ����"+
        	"���������㣬��Ȼ��$Rһ�ݡ�\n",who);
        CHAR_D->set_char(p_id,"isCompensate",1);
       	
        old_hon=CHAR_D->get_char(p_id,"hon");
	age = CHAR_D->get_char(p_id, "age"); // different age, different honour back
	if (( age > 14) && (age < 16))
		num = 5000;
	else if ( age <= 14 )
		num = 1000;
	else
		num = 10000;
        CHAR_D->set_char(p_id,"hon",old_hon+num);

	who->simple_action("$N�õ���"+chinese_number(num)+
		"���������㡣\n");
	who->responda("great shuijing");

}
////

void special_answer(object who, string matt)
{
	int p_money;
	string p_id;
	object ob;
	string s_tmp;
	switch(matt)
	{
// edc
		case "compensation" :
			compensation_honour(who);
			return;
////
		case "newyear" :
			newyear_gift(who);
 			return;
                case "valentine" :
			valentine_gift(who);
 			return;
		case "name" :
			this_object()->targetted_action("$N��$TЦ����"+
"�����ҵ������ҵ���������һɽҰ��������ʲô���մ���ѽ����\n",who);
 			return;
 		case "here" :
			this_object()->simple_action(
"$N˵��������������ʱ������֪������Щʲô��(help,money,shouming)");
			return;
		case "help" :
			this_object()->simple_action("$N΢΢һЦ��\n");
			this_object()->simple_action("$N˵������������Ұɣ����ҿ��ʶ��ˡ���\n"+
"Ҫ���˽��������磬���ȶ�������(news)��\n");
			return;
		case "news" :
			this_object()->targetted_action("$N��$TЦ����"+
"��������������С�ֵ��Ļ���־�����ɳ�һ����ҵ��\n",who);
			return;
		case "rumors" :
			this_object()->targetted_action("$N��$TС��˵����"+
"��˵����������Ϸ������������������ʦ������Ȥ�Ļ��п�ȥ�����ɡ�\n",who);
			return;
			
		case "money" :
			this_object()->targetted_action(
"$N��$t�ź���˵�������������ҵ���ȫ�������ˣ�$cҪ�ǲ������ɵ�����\n"+
"�Ŵ󻧼ҿ����ܲ����ҵ��ɸɣ���������(help digsoil)�鿴��\n",who);
                        return;
			p_money=who->query_amt_money("bank");
			p_money=p_money+who->query_all_con_money();
			if (p_money>50000)
			{
				this_object()->targetted_action(
"$N��$t˵������С�ֵܼ����ķᣬֻ�¿������������Ǯ�ɡ���\n",who);
				return;
			}
			p_id=this_body()->query_userid();
			if(member_array(p_id, name_list) != -1)
			{
				this_object()->targetted_action(
"$N��$t�ź���˵�������������ҵ���ȫ��С�ֵ��ˣ��� . . .��\n",who);
				return;
			}
			name_list+=({ p_id });
			ob=new(M_GOLD);
			ob->set_m_num(3);
			ob->move(who);
			this_object()->targetted_action(
"$N��$t˵��������������֮����Ҳ����Ե����㱡��������С�ֵ���ɰ�ҵ��\n",who);
			this_object()->targetted_action("$N��$tһЩ�ƽ�\n",who);
			return;
		case "shouming" :
			p_money=who->query_shouming();
			s_tmp=chinese_number(p_money);
			this_object()->simple_action("$N��ָ������\n");
			this_object()->targetted_action(
"$N��$tС��˵������$R���и�֮�ˣ���������"+s_tmp+"�ꡣ��\n",who);
			return;
		case "jbsj" : // ����ˮ��
			learn_sj(who);
			return ;
		case "gift" : // xiaobai: ����
			check_date(who);  // ��һ�½���ʲô���ӣ��ͺ��ʵ�����
			return ;
		case "pet" :
		        who->set_gini("dog");
		        if (present("gini lamp",who)) 
		        {
		        this_object()->other_action("$N����˵�������͸����С���ǲ��ǲ���������Ҫ������һ�������ϵ�����(gini)���ͻ�ص�����ߵġ�\n",who);
                        return;
                        }
		           	
		        GINI_D->gini_birth(who);
			this_object()->other_action("$N����˵������ֻ�Ϸ��İ���С�����͸����ˣ�Ҫ�ǲ�����ô��������������(gini help)�쿴��\n",who);
			return;
//                case "luoyang" :
//                        this_object()->simple_action("$NЦ�����������˸��Σ���������Ի��\n
//        �ȹ���ѣ�������ȼ���ҵ�ʯĥ��������֮��
//        �µ��ܶ����õ����飬ϰ����������Ҫʮ����
//        �ݼ��ܷ�����ؾ�������ȥ�������޳�ɷ�Ҳ����\n");
//                        return;
	}
}
