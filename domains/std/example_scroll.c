// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

//*************************************************************/
//*      an example object for lima bean
//*  
//*      zifnab@lima_bean
//*
//*********************************************************************

#include <mudlib.h>
#include <size.h>

inherit OBJ;
 
inherit M_GETTABLE;
inherit M_LOCKABLE;
inherit M_READABLE;

void setup()
{
    set_id("scroll", "����");
    set_in_room_desc("һ������ľ��ᡣ");
    set_gettable(1);
    set_long("����һ���ƾɵľ��ᣬ������Ƕ�Ľ��ּ�����ʶ��\n");
    set_text("ף����򿪱������ȡ��������ᣬ��������Ľ��ͣ�\n");
    set_size(VERY_SMALL);
}
