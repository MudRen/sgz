#include <mudlib.h>
#include <sanguo.h>

inherit OBJ;
inherit M_GETTABLE;
inherit M_VALUE;

void setup() {
    	set_unit("÷Í");
    	set_id("yao cao","“©≤›");
	add_id("yaocao");
	set_gettable(1);
	set_value(1000+random(500));
set_size(2);
}
int is_grass()
{
	return 1;
}
