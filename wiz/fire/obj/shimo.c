// shimo.c ʯĥ
inherit OBJ;
void setup()
{
  set_unit("��");
  set_id("shimo","ʯĥ", "miller");
  set_long("һ��ũ������ĥ��ĥ���ʯĥ������ȥ��������ʯĥûʲô��ͬ��
��������ϸ�۲죬�㷢���ƺ�����Ų���������裩��\n\n");
   set_in_room_desc("һ��ũ������ĥ��ĥ���ʯĥ��(shimo)\n\n");
}
int press(string s)
{
  if((s=="shimo")||(s=="ʯĥ")||(s=="miller"))
  { environment(this_object())->open_cave();
        return 1;
}
        else
                return 0;
}
