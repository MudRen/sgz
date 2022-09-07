// Updated by fire on April 05, 1998
// Updated by tset on 03 Mar 1998
// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */
 
inherit CONTAINER;
string the_name;
object link;
 
int is_living() {
    return 1;
}
 
string in_room_desc() 
{
    return query_in_room_desc();
}
    
mixed ob_state()
{
    return the_name;
}
     
object query_link() 
{
    return link;
}
void mudlib_setup(string name, string long, object l)
{
    ::mudlib_setup(); 
    link = l;
    if ( !name ) {
        name = "����";
    }
    the_name = name;
    set_long(long || the_name + "��ʬ�壬��������֮����");
    set_id("corpse", "ʬ��");
    set_unit("��");
    set_proper_name(the_name + "��ʬ��");
    set_in_room_desc(the_name + "��ʬ��(corpse)");
    set_max_capacity(VERY_LARGE);
    set_size(VERY_LARGE);
    set_preposition("on");
    if( clonep(this_object()) ) call_out("decay", 120, 1);
}
 
string introduce_contents()
{
    return "��"+query_chinese_id()+"���㿴����\n";
}   
mixed indirect_get_obj_from_obj(object ob1,object ob2)
{
  return 1;
}    
void decay(int phase)
{
    switch(phase) {
        case 1:
          tell_environment(this_object(),
                the_name+"��ʬ�忪ʼ�����ˣ�����һ�����ŵĶ����\n" );
          set_id("corpse", "���õ�ʬ��");
          set_long(
"���ʬ����Ȼ�Ѿ�����������һ��ʱ���ˣ���ɢ����һ�ɸ�ʬ��ζ����\n");
          set_in_room_desc("һ�߸��õ�ʬ�塣\n");
          call_out("decay", 120, phase + 1);
          break;
       case 2:
          tell_environment(this_object(),
                query_chinese_id()+"���紵Ǭ�ˣ����һ�ߺ��ǡ�\n" );
          set_id("skeleton", "һ�߿�Ǭ�ĺ���");
          set_long("�⸱�����Ѿ���������ܾ��ˡ�\n");
          set_in_room_desc("һ�߿�Ǭ�ĺ��ǡ�\n");
          call_out("decay", 60, phase + 1);
          break;
       case 3:
          tell_environment(this_object(),
                "һ��紵������"+query_chinese_id()+"���ɹǻҴ�ɢ�ˡ�\n" );
          if( environment() ) {
              object *inv;
              int i;
    
              inv = all_inventory(this_object());
              for(i=0; i<sizeof(inv); i++)
                   inv[i]->move(environment());
          }
          destruct(this_object());
          break;
    }
}
mixed is_corpse()
{
	return 1;
}
