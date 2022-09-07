// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

// Written by Rust.
#include <mudlib.h>

inherit OBJ;
inherit M_READABLE;
inherit M_GETTABLE;


void setup(string text)
{
    if(!strlen(text))
    {
	text = "*** Recorder heard nothing but silence.\n";
    }
  
    set_id("transcript", "�ʼǱ�");
    set_unit("��");
    set_gettable(1);
    set_in_room_desc("���Ϸ���һ���ʼǱ���");
    set_long("��������Щ�Ի��ļ�¼��\n");
    set_text(text);
}
