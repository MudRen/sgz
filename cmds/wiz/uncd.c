/* Do not remove the headers from this file! see /USAGE for more info. */

/* Beek: Nov 2 96 */

inherit CMD;

private void main() {
    object ob = this_body()->query_shell_ob();
    
    ob->swap_pwd();

    outf("µ±Ç°Ä¿Â¼: %s\n", ob->get_variable("pwd") || "NONE");
}
