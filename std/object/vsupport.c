// modified by fire on March 5, 1998
// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

#include <mudlib.h>
#include <hooks.h>

varargs mixed call_hooks(string, int, mixed);

//:FUNCTION check_permission
//check_permission(what) calls who->allow(what) in our owner, if one exists.
//Used by many of the verb routines to keep players from fiddling with things
//in other player's/monster's inventories.
mixed check_permission(string what) {
    object who = owner(this_object());

    if (!who || who->allow(what))
        return 1;
    return "��������������������̫����ò�˰ɣ�\n";//"#Rather impolite to do that without asking, don't you think?\n";
}

//:FUNCTION direct_get_obj
//Do some checks for the parser when we are the OBJ of the "get OBJ" rule
mixed direct_get_obj(object ob)
{
    object who = owner(ob);

    if(objectp(who))
    if(who->is_corpse())
        return 1;
    if ( environment() == this_body() )
        return "#����������ϣ�\n"; //"#You already have it!\n";
    if ( who && who != this_body() && !wizardp(this_body()) )
        return "#��ϧ�㲻�Ǹ�ְҵ����..:)\n"; //"#Too bad you're not a skilled pickpocket.\n";
    if ( this_object() == this_body() )
        return "����Լ�Ҫ�����أ�\n"; //"#You make an advance on yourself.\n";

    //:HOOK prevent_get
    //A yes/no/error hook called by direct_get_obj() if the standard conditions
    //succeed

    return call_hooks("prevent_get", HOOK_YES_NO_ERROR);
}

//:FUNCTION need_to_have
//Do some sanity checks for verbs that auto-take objects, or only allow
//you to use objects you are carrying.
//Most of the work is done in try_to_acquire.
mixed need_to_have() {
    mixed res = direct_get_obj(this_object());

    if (res == "#����������ϣ�\n")
        return 1;
    return res;
}

//:FUNCTION direct_look_at_obj
//Always allow "look at OBJ" to succeed by default.
mixed direct_look_at_obj(object ob) {
    return 1;
}

//:FUNCTION direct_look_at_obj
//Always allow "look OBJ" to succeed by default.  This is actually used to
//support "examine OBJ".
mixed direct_look_obj(object ob) {
    return 1;
}

//:FUNCTION direct_look_at_obj
//Always allow "look for OBJ" to succeed by default.
mixed direct_look_for_obj(object ob) {
    return 1;
}

//:FUNCTION direct_smell_obj
//Handle parser checks for "smell OBJ" rule.
mixed direct_smell_obj(object ob)
{
    return check_permission("smell");
}

//:FUNCTION direct_give_obj_to_liv
//Handle parser checks for "give OBJ to LIV" rule, where we are the object
//being given.
mixed direct_give_obj_to_liv()
{
    return need_to_have();
}

//:FUNCTION direct_eat_obj
//Handle parser checks for "eat OBJ" rule.
mixed direct_eat_obj(object ob) {
    return "����" + this_object()->short() + 
           "����ͬ������������\n";
}

//### shouldn't these to only be in coins?
mixed direct_give_wrd_str_to_liv()
{
    return 1;
}

//### This DEFINATELY shouldn't be here.  Should be in living.c
mixed indirect_give_wrd_str_to_liv()
{
    return 1;
}

mixed direct_look_str_obj(string prep, object ob) {
    return //"There is nothing " + prep + " " + this_object()->short() + ".\n";
           "û�ж�����"+ prep_calc(prep, this_object()->short())+"��\n";
}

//:FUNCTION direct_put_obj_wrd_obj
//Handle parser checks for "put OBJ WRD OBJ"     
mixed direct_put_obj_wrd_obj(object ob1, object ob2) {
    return check_permission("put");
}

//:FUNCTION direct_get_obs
//Handle parser checks for "get OBS"
mixed direct_get_obs(object ob)
{
    if ( environment() == this_body() || 
      (environment() && environment()->is_living()) ||
      this_object() == this_body() )
        return 0;

    //:HOOK prevent_get
    //A yes/no/error hook called by direct_get_obj() if the standard conditions
    //succeed

    return call_hooks("prevent_get", HOOK_YES_NO_ERROR);
}

//:FUNCTION direct_get_obj_from_obj
//Handle parser checks for "get OBJ from OBJ"
mixed direct_get_obj_from_obj(object ob1, object ob2) {
    return direct_get_obj(ob1);
}

//:FUNCTION direct_get_obj_out_of_obj
//Handle parser checks for "get OBJ out of OBJ"
mixed direct_get_obj_out_of_obj(object ob1, object ob2) {
    return direct_get_obj(ob1);
}

//:FUNCTION direct_get_obj_with_obj
//Handle parser checks for "get OBJ with OBJ"
mixed direct_get_obj_with_obj(object ob1, object ob2) {
    return direct_get_obj(ob1);
}

//:FUNCTION direct_sell_obj_to_liv
//Handle parser checks for "sell OBJ to LIV"
mixed direct_sell_obj_to_liv(object ob, object liv, mixed foo) {
    return need_to_have();
}

//:FUNCTION direct_buy_obj_from_liv
//Handle parser checks for "buy OBJ from LIV"
mixed direct_buy_obj_from_liv(object ob, object liv) {
    if (owner(ob) != liv)
        return liv->query_possessive() + "û�����ֶ�������\n"; //"doesn't have that!\n";
    return 1;
}

//:FUNCTION direct_drop_obj
//Handle parser checks for "drop OBJ" 
mixed direct_drop_obj(object ob)
{
    if ( environment() != this_body() )
        return "#��û���ⶫ����\n"; //"#You don't have it!\n";

    //:HOOK prevent_drop
    //A yes/no/error hook called by direct_drop_obj() if the standard conditions
    //succeed

    return call_hooks("prevent_drop", HOOK_YES_NO_ERROR);
}

//:FUNCTION direct_flip_obj
//Handle parser checks for "flip OBJ"
mixed direct_flip_obj(object ob) {
    //:HOOK direct_flip
    //A yes/no/error hook called by direct_flip_obj(); if no hooks exists, the
    //useless message will be used.

    return call_hooks("direct_flip", HOOK_YES_NO_ERROR,
      M_PARSING->useless("�Ҷ�" + ob->short()));
}

//:FUNCTION direct_throw_obj
//Handle parser checks for "throw OBJ"
mixed direct_throw_obj(object ob1, object ob2)
{
    return need_to_have();
}

//:FUNCTION direct_throw_obj_at_obj
//Handle parser checks for "throw OBJ at OBJ"
mixed direct_throw_obj_at_obj(object ob1, object ob2)
{
    return need_to_have();
}

//:FUNCTION indirect_throw_obj_at_obj
//Handle parser checks for "throw OBJ at OBJ"
mixed indirect_throw_obj_at_obj(object ob1, object ob2)
{
    return 1;
}

