// boy.c the body of ��·С�к�
// last modified by xiaobai, Sep. 14, 2001

// #define _DEBUG_ID   "xiaobai"

inherit PMODULES+"m_charnpc";

private string my_leader="";
private string* strBadIdArr = ({});  // ��¼������ id
private string my_target;
private mapping my_require=([]);
private int m_nCntInput = 0;  /*!< counter for input */

static string *my_desire=({"mantou"});
//static string *my_desire=({"mantou","niurou","liji","liyu","doufu","kaoya"});

void my_select(string str);
void input_name(string str);
void input_xianren(string str);
void answer_somebody(object who);
void prepare_answer();
void my_select(string str);
void no_answer();

//! �жϺ�ĳ�˵Ľ�̸���� no_answer ����
void abort();

void fail_answer();
void succ_answer();

// xiaobai:
//! mark down this id
void mark_id( string par_str );
//! remove the id from the list, the id can ask boy again
void recover_id( string par_str );
//! prompt the selection input request
void request_selection();

void setup()
{  
        call_out("my_heart",5);
        add_question("somebody","somebody"); 
        add_ask_str("somebody","$N��$T�������֣�$c��������$C����������ˣ��ò��á�\n");       
        add_question("xianren","xianren");
        add_ask_str("xianren","$N��$T�ʵ�������֪�����û����˵ʲô���˵���Ϣ��\n");     
}
void extra_init()
{
        add_id("boy");
}
string long()
{  
        return "һ����Ƥ��С�к������������⣬�����������ǳ����顣\n";
}
void do_my_speak()
{  
        switch(random(5)){  
                case 0:
                        this_object()->simple_action("$N˵������������죬û���Ҳ���ʶ���ˡ�\n");
                        break;
                case 1:
                        this_object()->simple_action("$N����˭�ܸ��ҿ��ǳԡ�\n");
                        break;
                case 2:
                        this_object()->responda("xixi");
                        break;
                case 3:
                        this_object()->responda("kick");
                        break;
                default: 
                this_object()->responda("say ˭Ҫ�����Ҳ���������׼û����\n");
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
    if( sizeof(my_leader) )
    {  
        object o = present( my_leader, environment( this_object() ) );
        if( objectp(o) )
            return;
        else my_leader="";
     }

    act=random(7);

    switch(act)
    {  
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

string assign_desire()
{
	/*string *lst,*mak;
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
	if(val>1500) return "mantou"; // too expensive 20 silver*/ //������һ�ɸ���ͷ�������Ժ�������
	return "mantou";
//	return typ;
}
void answer_xianren(object who)
{
        string p_id = who->query_id()[0];
        object o;  // �� boy ��̸���˵� obj

        if ( my_leader != "" )
        // ���˺� boy ��̸����û�н���
        {
            o = present( my_leader, environment( this_object() ) );

            if( objectp( o ) )
            {
                this_object()->targetted_action("$N��$T��������æ���ء�\n",who);
                return;
            }
            else
            // xiaobai: 10-22-2001, �Ǹ��˲�����ǰ��ȡ�������Ľ�̸
            {
                abort();
            }
        }

        if( member_array( p_id, strBadIdArr ) != -1 )
        {
            this_object()->targetted_action("$N��$T������ողŷ����ң����һ���������\n",who);
            return;
        }

        my_leader = p_id;

        this_object()->targetted_action("$N��$T����$mҪ��˭ѽ��\n",who);
        o = find_user( my_leader );
        if(!objectp(o))
        {
            no_answer();
            return;
        }
        
        tell_user(my_leader,"������Ҫ�ҽ�ɫ��ID\n");
        
        tell_user(my_leader,"����(hua tuo)���ڼ�(yu ji)������(xu zijiang)�����(zuo ci)��������(bao dating)���ϻ�����(nanhua laoxian)\n");
        
        o->modal_push((: input_xianren :),"�������˭��");
        
        // xiaobai: ԭ��ʱ��Ϊ60
        call_out( "no_answer", 30 + random(10) );
}

void answer_somebody(object who)
{
        string p_id=who->query_id()[0];
        object o;  // �� boy ��̸���˵� obj
        
        if ( my_leader != "" )
        // ���˺� boy ��̸����û�н���
        {
            o = present( my_leader, environment( this_object() ) );

            if( objectp( o ) )
            {
                this_object()->targetted_action("$N��$T��������æ���ء�\n",who);
                return;
            }
            else
            // xiaobai: 10-22-2001, �Ǹ��˲�����ǰ��ȡ�������Ľ�̸
            {
                abort();
            }
        }
        
        if( member_array( p_id, strBadIdArr ) != -1 )
        {
            this_object()->targetted_action("$N��$T������ողŷ����ң����һ���������\n",who);
            return;
        }
#ifdef _DEBUG_ID
    TELL_BUG( _DEBUG_ID, p_id );
#endif  // _DEBUG_ID

        my_leader=p_id;

        this_object()->targetted_action("$N��$T����$mҪ��˭ѽ��\n",who);

        o = find_user(my_leader);
        if(!objectp(o)) {no_answer(); return;}
        tell_user(my_leader,"������Ҫ�ҽ�ɫ��ID\n");
        o->modal_push((: input_name :),"�������˭��");
        
        // xiaobai: ԭ��ʱ��Ϊ60
        call_out("no_answer", 30 + random(10) );

}
void input_xianren(string str)
{       
        object o;
        if(!CHAR_D->char_exist(str))
        {
                write("û�������ɫ��\n");
                no_answer();
                return;
        }
        o=find_user(my_leader);
        if(!objectp(o)) {no_answer();return;}
        o->modal_pop();
        my_target=str;
        this_body()->simple_action(
                "$N����������"+CHAR_D->get_char(my_target,"name")+"��\n");

        this_object()->responda("consider");
        call_out("prepare_answer",1);
}
void input_name(string str)
{
        object o;
        if(!CHAR_D->char_exist(str))
        {
                write("û�������ɫ��\n");
                no_answer();
                return;
        }
        o=find_user(my_leader);
        if(!objectp(o)) {no_answer();return;}
        o->modal_pop();
        my_target=str;
        this_body()->simple_action(
                "$N����������"+CHAR_D->get_char(my_target,"name")+"��\n");

        this_object()->responda("consider");
                
        call_out("prepare_answer",1);
}
void prepare_answer()
{
    string my_area;

    my_area=environment(this_object())->get_area();
	tell_user("huaer",sprintf("����boy.c / prepare_answer()��, my_area = %s\n",my_area));
    if( my_target!="hua tuo"&&my_target!="xu zijiang"&&my_target!="bao dating"&&my_target!="zuo ci"&&my_target!="yu ji"&&my_target!="nanhua laoxian" ){
    if(CHAR_D->get_char(my_target,"area")!=my_area){
       
         if(CHAR_D->get_char(my_target,"my_area")!=my_area)
                        this_object()->simple_action("$Nҡҡͷ����"+CHAR_D->get_char(my_target,"name")+"��û��˵������Ų�ס����������ɡ�\n");
                else
                        this_object()->simple_action("��������ô��"+CHAR_D->get_char(my_target,"name")+"������ô֪����Ҫ���ĸ���\n");
                DELAY_D->delay_simple_action(this_body(),"$Nʧ����̾�˿�����\n",1);
                remove_call_out("no_answer");

                // xiaobai: ��ס��� id  20 ��
                mark_id( my_leader );

                my_leader=""; 

                return;
           }
	if(objectp(find_body(my_target))) { // this is a player
             this_object()->simple_action("��֪��"+CHAR_D->get_char(my_target,"name")+"���Ķ������ǲ�������㡣\n");

                remove_call_out("no_answer");
                
                // xiaobai: ��ס��� id  20 ��
                mark_id( my_leader );
                
                my_leader="";
		return;
	}

        }
        if(!my_require) my_require=([]);
        if(!my_require[my_target])
                my_require[my_target]=assign_desire();


        this_object()->simple_action("$N����"+CHAR_D->get_char(my_target,"name")+"���֪�����Ķ���������Ҫ����һ��"+
		OBJ_D->get_obj(my_require[my_target],"name")+"("+my_require[my_target]+")���ҲŸ����㡣\n");
//        destruct(o);

       // xiaobai: reset the counter of input
       m_nCntInput = 0;
         
       request_selection();        
}

//! prompt the selection input request
void request_selection()
{
    object o = find_user( my_leader );
    
    m_nCntInput ++;
    
    if( !objectp(o) || m_nCntInput > 3 )
    {
            no_answer(); 
            return;
    }
    
    tell_user(my_leader, "������Բߣ�1 ����Ǯ��2 �����ǣ� 3����ӦҪ�� 0 ������\n");
    
    o->modal_push((: my_select :), "������Բߣ�1 ����Ǯ��2 �����ǣ�3����ӦҪ�� 0 ������\n");
        
}  // end quest_selection

void my_select(string str)
{
        object o=find_user(my_leader);
        if(!objectp(o)){no_answer();return;}
        if((str!="0")&&(str!="1")&&(str!="2")&&(str!="3"))
                return;
        o->modal_pop();
        switch(str)
        {
        case "1":  // give money
                this_body()->targetted_action(
                        "$N����$T��ͷ˵����Ҫ�Ķ�����û�У�����һ�����ӣ����Լ�����ȥ��ɡ�\n",
        this_object());
         if(this_body()->query_all_con_money()<10000)
         {
            DELAY_D->delay_simple_action(this_object(),
                                "$N����������Ǯ��ƭ�ˡ�\n",1);
                        call_out("fail_answer",2);
         }
         else
         {  this_body()->set_all_con_money( 
                                this_body()->query_all_con_money() -10000);
            DELAY_D->delay_simple_action(this_object(),
                                "$N���˵�����������\n",1);
            DELAY_D->delay_targetted_action(this_body(),this_object(),
                                "$N��$Tһ�����ӡ�\n",2);
                        call_out("succ_answer",3);
         }
         break;
        case "2":
                this_body()->targetted_action(
                      "$N����$T��ͷ˵����Ҫ�Ķ�����û�У�����һ���ǣ��㿴�ò��á�\n",
         this_object());
        {
                        
                        o=present("candy",this_body());
                        if(!objectp(o))
                        {
                                DELAY_D->delay_simple_action(this_object(),
                                        "$N�����������ǣ�ƭ�ˡ�\n",1);
                                call_out("fail_answer",2);
                        }
                        else
                        {   string c_id=o->query_chinese_id();
                                destruct(o);
                                DELAY_D->delay_simple_action(this_object(),
                                "$N���˵�����������\n",1);
                   DELAY_D->delay_targetted_action(this_body(),this_object(),
                                "$N��$Tһ��"+c_id+"��\n",2);
                                call_out("succ_answer",3);
                        }
         }
         break;
        case "3":
                this_body()->targetted_action(
                        "$N����$T��ͷ˵���ðɣ��ʹ�Ӧ��������ɡ�\n",this_object());
        {
                        o=present(my_require[my_target],this_body());
                        if(!objectp(o))
                        {
                                DELAY_D->delay_simple_action(this_object(),
                                        "$N��������������Ҫ�ģ�ƭ�ˡ�\n",1);
                                call_out("fail_answer",2);
                        }
                        else
                        {   string c_id=o->query_chinese_id();
                                destruct(o);
                                DELAY_D->delay_simple_action(this_object(),
                                "$N���˵�����������\n",1);
                   DELAY_D->delay_targetted_action(this_body(),this_object(),
                                "$N��$Tһ��"+c_id+"��\n",2);
                                call_out("succ_answer",3);
                        }
         }
         break;
        default:
                this_body()->targetted_action("$N��$T�������ˣ��������ˡ�\n",
                   this_object());
                // xiaobai:
                call_out("no_answer",1);
                break;
        }
}
void succ_answer()
{
        object o,env;
        map_delete( my_require, my_target);

        remove_call_out("no_answer");

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
           ("$N������üͷ����֣�����ô���벻�������Ķ��ˡ�\n");
                return;
        }
        env=o->query_room();
        if(!objectp(env))
        {
                SGSYS("CAN'T FIND "+my_target+"'s ROOM");
                this_object()->simple_action
        ("$N������üͷ����֣�����ô���벻�������Ķ��ˡ�\n");
                return;
        }
        this_object()->responda("say "+CHAR_D->get_char(my_target,"name")+
                "��������"+
                AREA_D->get_area(env->get_area(),"name")+"��"+
                env->short()+"��\n");

        // xiaobai: ��ס��� id  20 ��
        mark_id( my_leader );
        my_leader="";

        return;
}

void fail_answer()
{
    this_object()->simple_action("$N�ߵ���С������\n");
    this_object()->responda("kick "+my_leader);

    // xiaobai: let the user select other thing
    request_selection();
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
        this_object()->simple_action("$N���ͷ��ص����ú�������ˣ���һ���������\n");
        o=find_user(my_leader);
        if(objectp(o))
                o->modal_pop();
        // xiaobai: ��ס��� id  20 ��
        mark_id( my_leader );

        my_leader="";
}

//! �жϺ�ĳ�˵Ľ�̸���� no_answer ����
void abort()
{
        object o;
        remove_call_out("no_answer");
        this_object()->simple_action( "$N������������ղź���˵�����˲�֪��������ȥ�ˡ�" );
        o=find_user(my_leader);
        if(objectp(o))
                o->modal_pop();
        // xiaobai: ��ס��� id  20 ��
        mark_id( my_leader );

        my_leader="";

}  // end abort

// xiaobai:
void mark_id( string par_str )
{
    if ( ( par_str != "" ) && ( member_array( par_str, strBadIdArr ) == -1 ) )
    {
        strBadIdArr += ({par_str});
        call_out( (: recover_id :), 20, par_str );
    }
        
}  // end mark_id

void recover_id( string par_str )
{
    if ( ( par_str != "" ) && ( member_array( par_str, strBadIdArr ) != -1 ) )
    {
        strBadIdArr -= ({par_str});
    }
    
}  // recover_id

int is_busy()
{
        if(find_body(my_leader)) return 1;
        return 0;
}
// so will not be clean_up
int query_clean_up() {
	return 1;
}