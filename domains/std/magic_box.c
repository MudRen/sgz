// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */


inherit INF_SUPPLY;

void setup() {
    set_id("box", "����");
    set_adj("ħ��");
    set_long("ħ�����������ݽߣ�");
    set_max_capacity(VERY_LARGE);
    set_objects( ([
        "/domains/std/objects/platemail" : -1,
        "/domains/std/objects/sword" : -1
      ]) );
}
