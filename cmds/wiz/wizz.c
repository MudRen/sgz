// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */
// product du Belboz/Rust
#include <mudlib.h>
#include <move.h>
inherit CMD;
string* MSGS;
create()
{
    MSGS =      ({
    "��ü���۰�������ƾ���",
    "�ƽ���ʿ",
    "������ս��ֱ����",
    "�����������ͻ��",
    "һ������ɫ��˹��˹�γ�",
    "���ֻ��������һ����",
    "�ƶ����������һ����",
    "�һ�Ļ���",
    "̩̹��˺�",
    "�˼����ĵ�����Ŀ��",
    "������г�",
    "�����Ѳ��",
    "����һ�����",
    "��������Ƭ",
    "������������Ƿɵ�",
   
  });
}
private void main( string arg )
{
    object      start_room;
    string      name;
    start_room = environment( this_body() );
    name        = this_body()->query_name();
    if( WIZ_ROOM == file_name(start_room))
    {
        this_body()->simple_action("$N�е��е�ͷ��Ŀѣ��");
        return;
    }
    if(!arg)
        arg = MSGS[random(sizeof(MSGS))];
    if( this_body()->move( WIZ_ROOM ) != MOVE_OK)
    {
      out( "��ѹ��û��Ү��\n" );
        return;
    }
    this_body()->force_look();
    outf("�㱻%s�ͻص���ʦ������\n", arg );
    if( name == "Someone" )
        return;
    tell_from_inside( start_room, sprintf( "%s��%s�����ˣ�\n",
        name, arg ) );
    tell_environment( this_body(),
      sprintf( "%s��%s���˻�����\n", name, arg ), 0, ({this_body()}) );
    return;
}
