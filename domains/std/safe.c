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

inherit CONTAINER;
inherit M_OPENABLE;
inherit M_GETTABLE;
inherit M_LOCKABLE;

void setup()
{
    set_adj("�޴��");
    set_id("safe", "���չ�");

    set_in_room_desc( "\n����������һ���޴�ı��չ�(safe)��");

    set_gettable("���չ�̫���ˣ���᲻����\n");
    set_locked("skeleton");
    set_closed(1);
    set_long("����һ���޴�ı��չ�");
    set_max_capacity(LARGE);
    set_strength_vs_magic(0);
    set_objects (( [ "/domains/std/example_scroll.c" : 1 ] ));
}

