// belong.c 
// by Suicide on July 20, 2001
// used for one dummy claim which id he is belongs.

inherit M_INPUT;

mixed is_valid_owner(string owner_id)
{object owner;
 if (!owner=find_body(owner_id))
    return "Ϊ�˰�ȫ�������趨�ĸ�IDӵ���߱������ߣ�\n";
 if (wizardp(owner))
    return "�����趨�ĸ�IDӵ���߲�������ʦ��\n";
 return 1;
}

void confirm_do(object dummy,string owner,string arg)
{
if (arg=="Y"||arg=="y")
   {
   dummy->set_owner(owner);
   write("%^CYAN%^�㽫����ID<"+dummy->query_userid()+">�ƽ������<"+owner+">%^RESET%^\n");
   modal_pop();
   return;
   }
else
   {
   if (arg=="N"||arg=="n")
      {
      write("%^CYAN%^����������ؿ��ǿ���!%^RESET%^\n");
      modal_pop();
      return;
	}
   else
      {
      modal_pop();
      modal_push((: confirm_do, dummy,owner:), 
      "%^CYAN%^��ȷ��Ҫ������ID<"+dummy->query_userid()+">�ƽ������<"+owner+">��?������Y/N?%^RESET%^\n");
      } 
   }


}

void start(string arg)
{string dummy_id,other_owner_id;
 mixed ret;
 if (!arg||arg=="")
    {printf("���ID��ӵ������%s\n",this_user()->query_owner());
     return;}
 if (sscanf(arg, "%s to %s", dummy_id,other_owner_id)==2)
    {object dummy;
     if (!dummy=find_user(dummy_id))
       {write("���д���ID�ƽ�������ID�������ߣ�\n");
        return;}
     if (dummy->query_owner()!=this_user()->query_userid())
       {write("�㲻�Ǹô���ID��ӵ���ߣ��޷��ƽ�������ˣ�\n");
        return;}
     ret = is_valid_owner(other_owner_id);
     if (stringp(ret))
        write(ret);
     else
        {
         modal_push((: confirm_do, dummy,other_owner_id:), 
        "%^CYAN%^��ȷ��Ҫ������ID<"+dummy_id+">�ƽ������<"+other_owner_id+">��?������Y/N?%^RESET%^");

         //dummy->set_owner(other_owner_id);
         //write("%^CYAN%^�㽫����ID<"+dummy_id+">�ƽ������<"+other_owner_id+">%^RESET%^\n");
        }
   }
 else
    {
     if (this_user()->query_owner()!="")
       {
        write("ֻ�и�ID��ӵ����ͨ������ %^CYAN%^cmd belong <����ID> to <�ƽ�ID>%^RESET%^����ת��ӵ���ߣ�\n");
        return;
       }
     if (wizardp(this_body()))
       {
        write("��ʦID�����趨ӵ���ߣ�\n");
        return;
       }
       
     ret = is_valid_owner(arg);
     if (stringp(ret))
        write(ret);
     else
        {
         modal_push((: confirm_do, this_user(),arg:), 
        "%^CYAN%^��ȷ��Ҫ���Լ���������ID��ʼ�趨Ϊ<"+arg+">��?������Y/N?%^RESET%^");

         //this_user()->set_owner(arg);
         //write("%^CYAN%^�㽫�Լ���������ID��ʼ�趨Ϊ"+arg+"%^RESET%^\n");
        }
    }

}