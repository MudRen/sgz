// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

#include <mudlib.h>
inherit CMD;

void main( mixed width )
{
    width = to_int(width);
    if( !intp( width ))
    {
        out( "��Ļ���һ��Ҫ���һ��������\n");
        return;
    }
    if( !width )
    {
        out( "��Ŀǰ����Ļ����ǣ�" + this_user()->query_screen_width() + "��\n" );
        return;
    }
    if( width < 20 )
    {
        out( "��Ļ�������Ǵ��� 20 ��\n");
        return;
    }
    this_user()->set_screen_width( width );
    out( "�����Ļ����趨��\n");
}
