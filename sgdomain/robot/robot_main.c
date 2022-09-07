// robot_test
// robot.c
#define MAX_TIME 180
inherit M_ACCESS;
string answer="";
void robot_test(object usr,function f,mixed p);

void no_answer(object usr,function f,mixed p)
{
   object o;
    string p_id;
 if(!objectp(usr)) return;
    o=usr->query_body();
    if(!objectp(o)) return;
     p_id=o->query_id()[0];
    tell_user(p_id,"��ʱ���\n");
   o->set("test_time",0);
   if(!random(10)) o->set_robot(1);
   find_user(p_id)->modal_pop();
   evaluate(f,usr,p);
   destruct(this_object());
}
void input_answer(object usr,function f,mixed p,string right_answer,string str)
{   object o;
    if(!objectp(o=usr->query_body())) {remove_call_out("no_answer") ;return;}
    if(str==right_answer)
    {   o->set("test_time",0);
        //added by suicide in 2001.6.8
        //for every job have a robot test 
        //there is 50% chance to inc 1 lit.
    	if (random(2)||(o->query_literate()<30))
            usr->query_body()->set_robot(0);
        else
            usr->query_body()->reset_robot();
        find_user(usr->query_body()->query_id()[0])->modal_pop();
        remove_call_out("no_answer");
        evaluate(f,usr,p);
	destruct(this_object());
        return;
    }
    if((str=="1")||(str=="2")||(str=="3")||(str=="4"))
    {   o->set("test_time",0);
        usr->query_body()->set_robot(1);
        find_user(usr->query_body()->query_id()[0])->modal_pop();
        remove_call_out("no_answer");
        evaluate(f,usr,p);
   	destruct(this_object());

        return;
    }
    if (str=="n") 
        {int tmp = usr->query_body()->query("test_time");//test_time����ʱ����
         if (tmp ) 
            {
            write("���Ѿ�������ѡ��һ�������ˣ������ε�������Ȼ����Ϊ�ѣ���ѡ��c������\n");
            write("��ش�1,2,3,4��c\n");
            return;
         }
         else
           {
            usr->query_body()->set("test_time",1);
            find_user(usr->query_body()->query_id()[0])->modal_pop();
            remove_call_out("no_answer");
            robot_test(usr,f,p);
           }
         return;
         }
    if (str=="c")
       {int tmp=o->query_perm("robot_cancel");
       if (tmp<3)
          {
          if (!o->query_perm("cancel_time"))
              o->set_perm("cancel_time",time());
          o->set("test_time",0);
          o->set_perm("robot_cancel",tmp+1);
          find_user(usr->query_body()->query_id()[0])->modal_pop();
	  remove_call_out("no_answer");
	  printf("���������λ����˲���,����%d�η����Ļ���!\n",2-tmp);
          return;
        }
       else
          {
          if ((time()-o->query_perm("cancel_time"))>1440*12)
             {
             tmp=0;
             o->set("test_time",0);
             o->set_perm("cancel_time",time());
             o->set_perm("robot_cancel",0);
             find_user(usr->query_body()->query_id()[0])->modal_pop();
  	     remove_call_out("no_answer");
	     printf("���������λ����˲���,����%d�η����Ļ���!\n",2-tmp);
             return;
        } 
          else
            {
            write("���������ش����������Ļ����Ѿ�ȫ��������,���ܷ����ش�\n");
            write("��ش�1,2,3��4\n");
            return;
            }
        
        }
        return;
       }     
    write("��ش�1,2,3,4��n\n");
}
void robot_test(object usr,function f,mixed p)
{
   string right_answer;
   object o_id;
   int is_robot,robot_test,robot_times;
   if(!objectp(usr->query_body())) return;
   o_id=usr->query_body();
   is_robot=o_id->query_robot();
   robot_test=o_id->query_robot_test(); // how many times tested
   robot_times=o_id->query_robot_times(); // how many times as robot 
   //remed by suicide in 2001.6.8 for give a test after every job!
   /*if((!is_robot)&&(robot_test>4)&&((robot_times*5)<robot_test)&&random(2))
   {       
   	   string p_id=o_id->query_id()[0];
	   o_id->set("test_time",0);
	   tell_user(p_id,"�������¼���ã�������ܲ��ԡ�\n");
       evaluate(f,usr,p);
	   destruct(this_object());
	   return;
   }*/  
   call_out("no_answer",MAX_TIME,usr,f,p);
   
/*
   if(usr->query_body()->query_literate()>=30) {
	switch(random(6)) {
	  	default:
	          right_answer=(__DIR__+"area")->test(usr->query_body()->query_id()[0]);
		  break;

	}
   }

   else if(usr->query_body()->query_literate()>20) {
	switch(random(4)) {
		case 0 :
	          right_answer=(__DIR__+"zi")->test(usr->query_body()->query_id()[0]);
		  break;
		case 1:
	          right_answer=(__DIR__+"queitem")->test(usr->query_body()->query_id()[0]);
		  break;
		default:
	          right_answer=(__DIR__+"area")->test(usr->query_body()->query_id()[0]);
		  break;

	}
   }
   else {
	switch(random(2)) {
		case 0:
	          right_answer=(__DIR__+"queitem")->test(usr->query_body()->query_id()[0]);
		  break;
		default:
	          right_answer=(__DIR__+"area")->test(usr->query_body()->query_id()[0]);
		  break;
	}
   }
*/
	switch(random(8)) {
		case 0..1 :
	          right_answer=(__DIR__+"zi")->test(usr->query_body()->query_id()[0]);
		  break;
		case 2..8:          //ԭ����2..6����Ϊ������û�и��꣬��ʱ���ε�����robot
	          right_answer=(__DIR__+"queitem")->test(usr->query_body()->query_id()[0]);
		  break;
		default:
	          right_answer=(__DIR__+"area")->test(usr->query_body()->query_id()[0]);
		  break;

	}

   set_this_player(find_user(usr->query_body()->query_id()[0]));

   find_user(usr->query_body()->query_id()[0])->
     modal_push((: input_answer,usr,f,p,right_answer :),
        "��������ȷ��(1,2,3,4 or n)��");
   return;
}
void create() {
    set_privilege(1);
}
