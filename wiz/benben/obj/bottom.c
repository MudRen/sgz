// well_bottom.c 井底 by benben

inherit OBJ;
inherit M_CLIMBABLE;
void setup() {
    set_id("bottom", "井底");
    set_in_room_desc("井底\n");
    set_long("井底的枯枝有些腐烂了，发出难闻的气味，你几乎被熏昏过去。\n");
    set_up_destination("well.c");
}                                  