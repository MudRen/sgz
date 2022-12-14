// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

// Rust.  This one is for simple items there mainly for ornamentation.

inherit BASE_OBJ;
inherit __DIR__"object/vsupport.c";

private static mapping msgs = ([]);

varargs void create(mapping long, string array ids, object dest)
{
    if (!clonep()) return;
    ::create();

    set_attached(1);
    msgs = long;
    if(mapp(msgs))
      {
if(msgs["look"])
      set_long(msgs["look"][<1] == '\n' ? msgs["look"] :
           msgs["look"]+"\n");
    if(msgs["adjs"])
      {
        arrayp(msgs["adjs"]) ? add_adj(msgs["adjs"]...) :
          add_adj(msgs["adjs"]);
        map_delete(msgs, "adjs");
      }
      }
    else
      {
    if(arrayp(ids) && sizeof(ids))
      set_long(//"You see nothing special about the "+ids[0]+".");
               "你并不觉得"+ids[0]+"有任何特殊的地方。");
      }
    if(arrayp(ids))
      set_id(ids...);

    parse_refresh();
    if(!objectp(dest))
      move_object(previous_object());
    else
      move_object(dest);
}


mixed direct_verb_rule(string verb, string rule, mixed args)
{
  string s = msgs[verb];
  if(s)
    return s[<1] == '\n' ? s : s+"\n";
}

/*
mixed get()
{
  string s;

  s = msgs["get"];
  if(s)
    return s + "\n";
}

int direct_get_obj()
{
  return 1;
}
*/
