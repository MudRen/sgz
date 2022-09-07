// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

/*
** horse.c
**
** Example of a mount.
**
** 951220, Rust: Created.
*/

inherit VEHICLE;
inherit M_MOUNTABLE;

void setup()
{
    set_relations("on");
    set_adj("��");
    set_id("horse", "��");
    set_unit("ƥ");
    set_long("�ţ��򣮣�����ƥ��̫����!!!");
    set_preposition("on");
    set_max_capacity(VERY_LARGE*2);
    // So people will see: Sitting on the horse you see Rust...
    set_primary_verb("sitting");
//    set_in_room_desc("������һƥ����");
    set_get_on_msg("$N���������˳���\n");
    set_get_off_msg("$N����ӳ���������������\n");

// We could opt for simple messages, and uncomment these
// 2 lines, but we can also go for more complex msgs (see below).
//    set_arrival_msg("$Nһ�����ε����˹�����\n");
//    set_departure_msg("$N�뿪�ˡ�\n");
}


string get_arrival_msg()
{
  string riders;

  if(!(riders = get_riders_as_string()))
    return 0;

  return short() + "����" + riders +"�뿪�ˡ�\n";
}

string get_departure_msg()
{
  string riders;

  if(!(riders = get_riders_as_string()))
    return 0;

  return riders + "����" + a_short() + "�����ˡ�\n";
}
