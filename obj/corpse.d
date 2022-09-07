// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

inherit CONTAINER;

string the_name;
object link;

int is_living() {
    return 1;
}

string in_room_desc() {
    return query_in_room_desc();
}

mixed ob_state()
{
    return the_name;
}

object query_link() {
    return link;
}

void mudlib_setup(string name, string long, object l)
{
    ::mudlib_setup();

    link = l;
    if ( !name )
        return;

    the_name = name;
    set_long(long || the_name + "��ʬ�壬��������֮����");
 
    set_id("corpse", "ʬ��");
    set_unit("��");
    set_proper_name(the_name + "��ʬ��");//"' corpse");
    set_in_room_desc(the_name + "��ʬ�徲�������ڵ��ϡ�");//" is lying here slumped on the ground.");
    set_max_capacity(VERY_LARGE);
    set_size(VERY_LARGE);
    set_preposition("on");
}

string introduce_contents()
{
    return "��"+short()+"���㿴����\n";//"On " + short() + " you see:\n";
}    
mixed indirect_get_obj_from_obj()
{
  return 1;
}
