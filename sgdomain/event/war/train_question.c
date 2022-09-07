// train_question.c
// by fire on Dec 1998
#include <train.h>
mixed get_train_question()
{
   mixed question;
   question=({
(["mess":"�о�����Ķ��棬Ҫ���г��湥����ʲôָ�",
"ans":({"cmd attack e","cmd attack east"}),
"help":"/help/player/sanguo/command/attack"]),
(["mess":"�о���������棬Ҫ���г��湥����ʲôָ�",
"ans":({"cmd attack s","cmd attack south"}),
"help":"/help/player/sanguo/command/attack"]),
(["mess":"�о���������棬Ҫ���г��湥����ʲôָ�",
"ans":({"cmd attack w","cmd attack west"}),
"help":"/help/player/sanguo/command/attack"]),
(["mess":"�о�����ı��棬Ҫ���г��湥����ʲôָ�",
"ans":({"cmd attack n","cmd attack north"}),
"help":"/help/player/sanguo/command/attack"]),
(["mess":"�о�����Ķ��棬Ҫ���г�湥����ʲôָ�",
"ans":({"cmd horse e","cmd horse east"}),
"help":"/help/player/sanguo/command/horse"]),
(["mess":"�о���������棬Ҫ���г�湥����ʲôָ�",
"ans":({"cmd horse s","cmd horse south"}),
"help":"/help/player/sanguo/command/horse"]),
(["mess":"�о���������棬Ҫ���г�湥����ʲôָ�",
"ans":({"cmd horse w","cmd horse west"}),
"help":"/help/player/sanguo/command/horse"]),
(["mess":"�о�����ı��棬Ҫ���г�湥����ʲôָ�",
"ans":({"cmd horse n","cmd horse north"}),
"help":"/help/player/sanguo/command/horse"]),
(["mess":"�о�����Ķ��棬Ҫ����Χ����ʲôָ�",
"ans":({"cmd siege e","cmd siege east"}),
"help":"/help/player/sanguo/command/siege"]),
(["mess":"�о���������棬Ҫ����Χ����ʲôָ�",
"ans":({"cmd siege s","cmd siege south"}),
"help":"/help/player/sanguo/command/siege"]),
(["mess":"�о���������棬Ҫ����Χ����ʲôָ�",
"ans":({"cmd siege w","cmd siege west"}),
"help":"/help/player/sanguo/command/siege"]),
(["mess":"�о�����ı��棬Ҫ����Χ����ʲôָ�",
"ans":({"cmd siege n","cmd siege north"}),
"help":"/help/player/sanguo/command/siege"]),
// edc 08/04/2001  cancel bowman directly array
/*(["mess":"�о�����Ķ��棬Ҫ���й���������ʲôָ�",
"ans":({"cmd array e","cmd array east"}),
"help":"/help/player/sanguo/command/array"]),
(["mess":"�о���������棬Ҫ���й���������ʲôָ�",
"ans":({"cmd array s","cmd array south"}),
"help":"/help/player/sanguo/command/array"]),
(["mess":"�о���������棬Ҫ���й���������ʲôָ�",
"ans":({"cmd array w","cmd array west"}),
"help":"/help/player/sanguo/command/array"]),
(["mess":"�о�����ı��棬Ҫ���й���������ʲôָ�",
"ans":({"cmd array n","cmd array north"}),
"help":"/help/player/sanguo/command/array"]), */
(["mess":"�о�����Ķ����һ��ط���Ҫ���й���������ʲôָ�",
"ans":({"cmd array e 2","cmd array east 2"}),
"help":"/help/player/sanguo/command/array"]),
(["mess":"�о�����������һ��ط���Ҫ���й���������ʲôָ�",
"ans":({"cmd array s 2","cmd array south 2"}),
"help":"/help/player/sanguo/command/array"]),
(["mess":"�о�����������һ��ط���Ҫ���й���������ʲôָ�",
"ans":({"cmd array w 2","cmd array west 2"}),
"help":"/help/player/sanguo/command/array"]),
(["mess":"�о�����ı����һ��ط���Ҫ���й���������ʲôָ�",
"ans":({"cmd array n 2","cmd array north 2"}),
"help":"/help/player/sanguo/command/array"]),
(["mess":"�о�����Ķ��ϣ�Ҫ���й���������ʲôָ�",
"ans":({"cmd array se","cmd array southeast"}),
"help":"/help/player/sanguo/command/array"]),
(["mess":"�о�����Ķ�����Ҫ���й���������ʲôָ�",
"ans":({"cmd array ne","cmd array northeast"}),
"help":"/help/player/sanguo/command/array"]),
(["mess":"�о���������ϣ�Ҫ���й���������ʲôָ�",
"ans":({"cmd array sw","cmd array southwest"}),
"help":"/help/player/sanguo/command/array"]),
(["mess":"�о������������Ҫ���й���������ʲôָ�",
"ans":({"cmd array nw","cmd array northwest"}),
"help":"/help/player/sanguo/command/array"]),
});
  return question[random(sizeof(question))];
}
void input_answer(string p_leader,int task_id,string ans)
{
   mixed trainpara;
   object o;
   string help_info;
   trainpara=TASK_D->get_task(task_id,"trainpara");
   if (ans=="help")
   {
      help_info=read_file(trainpara["help"]);
      tell_user(p_leader,help_info+"\n");   
      return;
   }
   if(member_array(ans,trainpara["ans"])!=-1)
   {
       trainpara["right"]=1;
       TASK_D->set_task(task_id,"trainpara",trainpara);
       o=find_user(p_leader);
         if(objectp(o)) o->modal_pop();
       tell_user(p_leader,"�ش���ȷ��\n");
       return;
   }
   if(ans!="")
       tell_user(p_leader,"�ش����\n");
}
void show_question(string p_leader,int task_id)
{
   mixed trainpara;
   object o;
   o=find_user(p_leader);
   if(!objectp(o)) return;
   trainpara=TASK_D->get_task(task_id,"trainpara");
   tell_user(p_leader,trainpara["mess"]+"\n");
   o->modal_push((: input_answer,p_leader,task_id :),
        "��help�������Ϣ��");
}
void quit_question(int task_id)
{
   string p_leader;
   object o;
   p_leader=TASK_D->get_task(task_id,"def_leader");
   o=find_user(p_leader);
   if(!objectp(o)) return;
   o->modal_pop();
}
