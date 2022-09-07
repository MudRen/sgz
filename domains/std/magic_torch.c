// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

inherit TORCH;
inherit M_VALUABLE;

void setup() {
    set_adj("魔法");
    set_id("torch", "木棍");
    set_long( (: "一根细长的木头，似乎有某种活力。\n" + (query_is_lit() ? "它上面燃烧着奇异的蓝色火焰。\n" : "") :) );
    set_light_msgs("当$N把$O点着的时候，一股蓝色的火苗烧了起来。\n", "当$n把$o点燃的时候，发出蓝色的火光。\n");
    set_source( (: $1->can_light_the_magic_torch() ? (mixed)1 : "火焰的颜色似乎不对...\n" :) );
    set_fuel(-1); // never runs out
set_value(15);
}
