// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

inherit CORPSE;

void create()
{
    ::create("̽����");
}

void setup()
{
    set_proper_name(0);
    set_adj("̽���ߵ�");
    set_objects(([ 
      "/domains/std/objects/pac_sword" : 1,
      "/domains/std/objects/platemail" : 1,
      "/domains/std/objects/lantern" : 1,
      "/domains/std/objects/backpack" : 1,
    ]));
}
