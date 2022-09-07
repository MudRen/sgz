// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

inherit CMD;

// Rust/Belboz
private void main( mixed *arg)
{

    object      start_place, end_place;
    object      target;
    string      target_name;

    target = arg[0];
    start_place = environment( target );
    target_name = target->query_name();
    end_place = environment( this_body());
    if( start_place == end_place )
    {
        if( this_body()->query_name() == target_name )
        {
            out( "�㲻���ٻ����Լ���\n");
            return;
        }
        out( target_name + "�������\n" );
        return;
    }
    target->move( end_place );
    if( environment( target ) == start_place )
    {
        out( "Trans:  �ƶ�ʧ��\n" );
        return;
    }
    if( ! target_name )
        target_name = target->short();

    /* Be careful here or it will be impossible to trans someone with no env() */
    if (!(target->query_link() && interactive(target->query_link()) && target_name == "Someone") && start_place)
        tell_from_inside( start_place , sprintf( "��������һֻ�ְ�%sץ���ˡ�\n",
            target_name ) );
    outf( "���%s�ٻ�������\n", target_name );
    tell( target, "�㱻һ��紵����ĳ���ط���\n" );

    if( !( target->query_link() && interactive(target->query_link()) &&
        target_name == "Someone" ) )
    {
        tell_environment( target, sprintf("%s������һ����С�\n",
            target_name ), 0, ({ target, this_body() }) );
    }

    return;
}

