// soil by fire :)
// this is used for the job of ����
#include <mudlib.h>
inherit OBJ;
inherit M_DIGGABLE;
inherit M_INPUT;
string *desc = ({"һƬ���أ�Ӧ�ÿ��Ը�����\n"+
"��������Ҫ�����ݡ�(dig soil with chu tou)\n",
"�����Ѿ���͸�ˣ�������Ҫ��Щˮ��(turn mu tong)\n",
"���ؿ���ȥ�ܷ��ֵ����ӣ�����ׯ������һ���кõ��ճɡ�\n",});
int status; // 0-20 weed 21-40 need water 41- good
int touch;
void setup()
{
        set_id("soil", "һƬ����");
	add_id("tu di");
        set_in_room_desc("һƬ����(soil)");
        status = 0;
        touch=0;
        call_out("decay", 10);
      set_clean_up(1);
}
int query_status()
{
  return status;
}
string long()
{
   if(status<21)
     return desc[0];
   if(status<41)
     return desc[1];
   return desc[2];
}
void decay()
{
     call_out("decay",30);
     touch=touch-1;
     if(touch<0)
        touch=0;
     if(touch)
        return;
     status=status-2;
     if(status<0)
       status=0;
     tell_environment(this_object(),"��ʱ�����˴������ؿ�ʼ�����ˡ�\n");
}
void dig(object o)
{
   if(touch==14)
   {
      write("�ظմ������Ҫ��΢��һ�¡�\n");
      return;
   }
   touch=14;
   if (status<21)
   {
        int m_hp;
        m_hp=this_body()->query_cur_hp();
        if (m_hp<10)
        {  write("��̫���ˣ���Ϣһ����ɡ�\n");
           return;
        }
        m_hp-=5;
        this_body()->set_chr_hp(m_hp);
        status=status+random(10)+2;
        this_body()->simple_action( ({"$N�����ͷ���˳��ݣ���Ƭ�ؿ���ȥ�ö��ˡ�",
"$Nһ��ͷ������ȥ��������һ��ʯͷ�����˫�ַ��顣",
"$Nһ��ͷ������ȥ����С���ҵ����ϣ��۵�$n�໹ֽС�"}) );
   }
   else
      write("�����Ѿ�����Ҫ�����ˡ�\n");
}
int is_digable()
{
	return 1;
}
int water()
{
   if(touch==14)
   {
      write("�ظմ������Ҫ��΢��һ�¡�\n");
      return 0;
   }
   touch=14;
   status=status+random(10)+2;
        this_body()->simple_action( ({"$N����һͰˮ�����ؿ�������������ࡣ",
"$NһͰˮ�ó�ȥ��û�뵽�����Լ�һ���ࡣ"}) );
    if(status>40) {
        if(this_body()->query_job("digsoil","beg_time"))
        {
           this_body()->set_job("digsoil","status","done");
                write("���Ѿ�����ˣ���ȥ��Ǯ�ɡ�\n");
        }
    }   
   return 1;
}
void set_status(int i)
{
   status=i;
}
int query_clean_up() {
   return 1;
}
