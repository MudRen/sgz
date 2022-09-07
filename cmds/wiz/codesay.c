// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

// -Beek

inherit CMD;
inherit M_GRAMMAR;

void create()
{
  ::create();
  no_redirection();
}

private void main(string s) {
    if (!s || s == "") {
        write("�÷���codesay <code>\n");
        return;
    }

    s = replace_string(s, ";", ";\n");
    s = replace_string(s, "{", "{\n");
    s = replace_string(s, "}", "}\n");

    // Indent
    write_file("/tmp/codesay", s, 1);
    ed_start("/tmp/codesay");
    ed_cmd("I");
    ed_cmd("x");
    s = read_file("/tmp/codesay");
    // fix the fact that indentation uses tabs
    s = "\n\t" + replace_string(s, "\n", "\n\t");
    
    this_body()->simple_action("$N˵����$o", punctuate(s));
}
