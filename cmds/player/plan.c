// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

// Command for generating templates for verbs by Rust.  8-95
//  This file is part of the Lima mudlib distribution.  
//  Don't remove this header.  See /USAGE for more info.

#include <mudlib.h>
#include <edit.h>

inherit CMD;

private nomask void set_plan(string * plan)
{
    if( !sizeof( plan ))
    {
        write( "��û�иı���ļƻ���\n");
        return;
    }
    write("���趨�ƻ���ɡ�\n");
    this_body()->set_plan(implode(plan,"\n"));
}

private void main()
{
#ifdef EVERYONE_HAS_A_PLAN

    out("������ļƻ��ɣ�\n");
    new(EDIT_OB, EDIT_TEXT, 0, (: set_plan :));

#else
    out("�Բ���û���������ܡ�\n");
#endif
}
