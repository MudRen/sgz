// well_bottom.c 井底 by benben

inherit OBJ;
void setup() {
    set_id("bottom", "井底");
    set_in_room_desc("井底\n");
    set_long("井底的枯枝有些腐烂了，发出难闻的气味，你几乎被熏昏过去。\n");
    set_objects( ([
        "/wiz/benben/obj/box.c" : 1,
      ]) );
    set_up_destination("well.c");
}                                  