// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

/*
** openable.c (M_OPENABLE)
**
** This object provides base open/close capabilities for an OBJ
**
**
//### doc forthcoming...
*/

#include <mudlib.h>
#include <hooks.h>

mixed call_hooks(string, int);

/*
** From OBJ::description
*/
void set_in_room_desc(string arg);
string short();
varargs void add_adj();
varargs void remove_adj();

private int closed;
private string open_msg =  "$N打开$o。";//"$N $vopen a $o.";
private string close_msg = "$N关上$o。";//"$N $vclose a $o.";
private string open_desc;
private string closed_desc;

void hook_state(string, string, int);
void add_hook(string, function);
void resync_visibility();

int openable() { return 1; }

int query_closed() { return closed; }

void set_closed(int x) { 
  string* adjs;
  
  closed = x; 
  hook_state("extra_short", "open", !closed);
  hook_state("extra_short", "closed", closed);
  
  remove_adj("closed", "open");
  if (closed)
      add_adj("closed");
  else
      add_adj("open");

  if (open_desc && !x) 
      set_in_room_desc(open_desc);
  if (closed_desc && x)
      set_in_room_desc(closed_desc);
  
  /* our inventory visibility probably just changed. */
  resync_visibility();
}


void set_open_desc( string desc )
{
  open_desc = desc;
  if (!query_closed()) set_in_room_desc(desc);
}

void set_closed_desc( string desc )
{
  closed_desc = desc;
  if (query_closed()) set_in_room_desc(desc);
}

string query_closed_desc() { return closed_desc; }

string query_open_desc() { return open_desc; }

void set_open_msg(string new_msg)
{
    open_msg = new_msg;
}

void set_close_msg(string new_msg)
{
    close_msg = new_msg;
}

int open_with(object with)
{
    string ex;

    if (!query_closed())
    {
        write(//"It is already open.\n"
              "它已经打开了。\n");
        return 1;
    }

//:HOOK prevent_open
//A yes/no/error hook which can prevent an object from being opened.

    ex = call_hooks("prevent_open", HOOK_YES_NO_ERROR);
    if (!ex) ex = short() + "好象打不开。\n";
    if (stringp(ex)) {
        write(ex);
        return 1;
    }
    
    this_body()->simple_action(open_msg, this_object());
    set_closed(0);
    if (ex = inv_list(all_inventory())) {
        write("在里面你发现了：\n"+ex);
    }
//:HOOK open
//called when an object is opened.  The return value is ignored.
    call_hooks("open", HOOK_IGNORE);

    return 1;
}

mixed close() {
    mixed tmp;
    if (query_closed()) {
        write("它已经关上了。\n");
        return 1;
    }
//:HOOK prevent_close
//A yes/no/error hook that can prevent an object from being closed
    tmp = call_hooks("prevent_close", HOOK_YES_NO_ERROR);
    if (!tmp) tmp = short() + "好象关不上。\n";//"doesn't seem to want to close.\n";
    if (stringp(tmp)) return tmp;
    
    this_body()->simple_action(close_msg, this_object());
//:HOOK close
//called when an object is closed.  The return value is ignored.
    call_hooks("close", HOOK_IGNORE);

    set_closed(1);    
    return 1;
}

int is_open()
{
  return !query_closed();
}

/* Verb interaction */
mixed direct_open_obj(object ob) {
    if (!query_closed())
      return "它已经打开了。\n";//"It is already open.\n";
    return 1;
}

mixed direct_close_obj(object ob) {
    if (query_closed())
        return "它已经关上了。\n";//"It is already closed.\n";
    return 1;
}


string extra_long_stuff()
{
    return short() + "是" + (query_closed() ? "关着的" : "开着的") + "。\n";
}


// You should do this, or call set_closed() when you create an openable,
// so that the proper adjective gets initialized.
void internal_setup() {

    set_closed(1);
    
    add_hook("extra_long", (: extra_long_stuff :));
    add_hook("prevent_look_in", (: closed ? "它是关着的。\n" : (mixed)1 :));
}
