// by fire on March 1999
#include <mudlib.h>
inherit OBJ;
void hook_state(string, string, int);
//### Huh?  This appears to be unused.
private static string   wearmsg="$N����һ��$o��\n";
private static string   removemsg="$N����$o��\n";
private static int      is_on;
private static string   slot;

private static int m_att_abi=0;
private static int m_def_pow=0;
void set_def_pow(int p_tmp){
	m_def_pow=p_tmp;
}
int query_def_pow(){
	return m_def_pow;
}
void set_att_abi(int p_attack){
	m_att_abi=p_attack;
}
int query_att_abi(){
	return m_att_abi;
}

mixed ob_state() {
    if (!is_on) return 0;
    return slot;
}
/*void remove() {
	if(!slot)
        return 0;
	if(!objectp(environment()))
		return 0;
	if(!(environment()->is_living()))
		return 0;
    environment()->depopulate_body_slot(slot, this_object());
} */
void set_wearmsg( string s ){
  wearmsg = s;
}
string query_wearmsg(){
  return wearmsg;
}
void set_removemsg( string s ){
  removemsg = s;
}
string query_removemsg(){
  return removemsg;
}
void set_slot(string what){
    slot = what;
}
string query_slot(){
    return slot;
}
void set_is_on( int g){
  is_on = g;
  hook_state("extra_short", "������", is_on);
  hook_state("prevent_drop", "��Ҫ�Ȱ�����������\n", is_on);
}
void do_wear()
{
    object who;
    if(!slot)
    {   write("�ⶫ������֪�ô��ġ�\n");
        return;
    }
    who=owner(this_object());
    foreach (object ob2 in all_inventory(who)) 
    { 	if ((slot==ob2->ob_state()))
		{
			write("���Ѿ�������ͬ��װ���ˡ�\n");
			return;
		}
    }	
    environment()->populate_body_slot(slot, this_object());
    set_is_on(1);
    who->simple_action(wearmsg, this_object());
}
void do_remove() {
    if(!slot)
        return 0;
    environment()->depopulate_body_slot(slot, this_object());
    set_is_on(0);
    environment()->simple_action(removemsg, this_object());
}
mixed  direct_wear_obj() {
    object who = owner(this_object());
    if (who != this_body())
        return 0;                                       
    if( is_on )                                         
        return "���������أ�\n";
    return 1;
}
mixed direct_remove_obj() {
    object who = owner(this_object());
    if (who != this_body())
        return 0;                                 
    if (environment() != this_body() || !is_on)
        return "�������û�д�����\n"; 
    return 1;
}
