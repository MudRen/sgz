// by fire on Jan 9 1998 barrel.c
#include <ansi.h>
inherit OBJ;
inherit M_GETTABLE;
int isfill;
string short();
void setup() {
    set_adj("С�ɵ�");
    set_id("shui hu", "ˮ��","bottle");
    set_unit("��");
    set_in_room_desc("һֻ�����õ�ˮ��(shui hu)��");
    isfill=0;
}
string long()
{
    if(isfill)
    {
       return "һֻ�����õ�ˮ��(shui hu)��\n"+
        "����װ����ˮ��\n";
    }
    return "һֻ�����õ�ˮ��(shui hu)��\n";
}
mixed direct_fill_obj()
{
   return 1;
}
void fill_with(object with)
{
   string s_obj;
   if(isfill)
   {
      printf("%s�Ѿ����ˡ�\n",short());
      return;
   }
   isfill=1;
   this_body()->simple_action("$N��"+short()+"װ����ˮ��\n");
}
int can_turn()
{
        return 1;
}
int set_water(int water)
{
	if( water == 0 )return isfill;
	else {
		isfill = 0;
		return isfill;
	}
}
