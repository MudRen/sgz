// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

/*
** workroom.c
**
** This is used for wizards' temporary workrooms.  This is NOT a template
** for a permanent workroom.  Copy one from an existing wizard or figure
** out how to write one :-)
**
** Deathblade thinks this was written by Beek; certainly commented by DB
*/

#include <mudlib.h>

#include <ansi.h>
inherit ROOM;

void set_owner(string str)
{
    set_long("%^B_RED%^��ط�Խ��Խ���ģ�Խ��Խ���Ծ�... �����Ķ������أ�"+NOR+"\n\n");
    set_light(1);
}
