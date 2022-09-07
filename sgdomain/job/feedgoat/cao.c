#include <mudlib.h>

inherit OBJ;
inherit M_GETTABLE;

void setup()
{
        set_id("grass", "Çà²Ý");
	set_unit("À¦");
        return;
}
int is_food()
{
	return 1;
}
