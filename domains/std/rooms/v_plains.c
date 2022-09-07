// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

/*
** v_plains.c -- example use of a virtual object server to create plains
**
** Format for the object is:
**
**      /domains/std/rooms/v_plains/x/y
**
** The data for the plains is pulled from v_plains.data.  It is an array
** of description-id values (in the first N non-comment lines).  Comments
** are lines beginning with #.  After the description array are lists of
** rooms for the boundaries of the plains.  They are in north, east,
** south, west order; one line per grid spot.
**
** Deathblade, 960101: created
*/

inherit GRID_SERVER;

#define DATA_FILE       __DIR__ "v_plains.data"

static private string * my_descriptions = ({
    "һ����ȵķ����Ƭƽԭ�ϵ�Сɽ���ϴ�����",
    "��ص�Ұ�ݺ�Ұ�ȴ���ǰֱ���������һ�ߡ�",
    "����������ƣ����ȵ�����ֱ����£����Ҳ�������ˡ�",
    "һ��������СϪ������������",
});

void create()
{
ZBUG("in set up");
    use_data_file(DATA_FILE);
    set_brief("ƽԭ");
    set_descriptions(my_descriptions);
}
