#include <mudlib.h>

inherit OBJ;
inherit M_GETTABLE;

void setup()
{
        set_id("grass", "���");
	set_unit("��");
        return;
}
int is_food()
{
	return 1;
}
