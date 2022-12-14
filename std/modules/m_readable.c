// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

#include <mudlib.h>

/*
** From OBJ::description
*/
string short();


mapping                 entries;
mapping                 synonyms;
private string          read_text;


void
set_text( string t )
{
  read_text = t;
}

string
read()
{
    this_body()->simple_action(//"$N $vread the $o.\n"
                               "$N读了一会儿$o。", this_object());

    return read_text;
}

string
read_entry( string entry )
{

    entry = entries[entry];
    if(!entry)
      {
        entry = entries[synonyms[entry]];
      }

    if (functionp(entry))
        return evaluate(entry);

    if (stringp(entry) && file_size(entry) > 0)
        return read_file(entry);

    return 0;
}

int
has_entries()
{
  return mapp( entries );
}

/* Parser interaction */
mixed direct_read_obj(object ob) {
    if (!read_text) {
      if (entries)
          return //"It has a number of entries about various topics.\n";
                 "上面有好几项关于不同话题的内容。\n";
      return 0;
    }
    return 1;
}

mixed direct_read_word_obj(string p, object ob) {
    return direct_read_obj(ob);
}

mixed direct_read_str_word_obj(string str, string p, object ob) {
    if (!entries) {
      if (read_text)
          return //"It's fairly short.  Just read it all.\n";
                 "它很短，就读完了吧。\n";
      return "它上面没有字。\n";
    }
    return 1;
}

mixed direct_read_word_str_word_obj(string p1, string str, string p2,
                                  object ob) {
    return direct_read_str_word_obj(str, p2, ob);
}

void set_entries(mapping e)
{
  entries = e;
}

void set_entry_synonyms(mapping s)
{
  synonyms = s;
}








