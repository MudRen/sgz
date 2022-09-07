// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

inherit OBJ;
inherit M_CLIMBABLE;

mixed direct_get_obj( object ob ) {
        return "#��������(climb)��\n";
}

varargs static void setup_messages(string id, mixed up_dest, mixed down_dest,
                                   string chinese_name) {
        add_id(id);
        if (chinese_name) {
            add_chinese_id(chinese_name);
            chinese_name += "(" + id + ")";
        }
        else chinese_name = id;
        if (up_dest) {
            if (down_dest) {
                set_long( chinese_name + "ͨ�����·���\n");
                set_in_room_desc("������" + chinese_name + "��ͨ�����·���\n");
            } else {
                set_long( chinese_name + "ͨ���Ϸ���\n");
                set_in_room_desc("������" + chinese_name + "��ͨ���Ϸ���\n");
            }
        } else {
            set_long( chinese_name + "ͨ���·���\n");
            set_in_room_desc("������" + chinese_name + "��ͨ���·���\n");
        }
}

// Separated from create() so that objects can overload this separately
void more_create(mixed up_dest, mixed down_dest, int attached) {
    setup_messages("stairs", up_dest, down_dest, "¥��");
}

void create( mixed up_dest, mixed down_dest, int attached )
{
    ::create();
    more_create( up_dest, down_dest, attached );
    if( attached )
        set_flag( ATTACHED );
    set_up_destination(up_dest);
    set_down_destination(down_dest);
}
