// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

#include <mudlib.h>
#include <daemons.h>

inherit CMD;

nomask private void main(string str) {
    if (!str) {
        out("�÷���targetemote verb\n");
        return;
    }
    SOUL_D->add_emote(str, "", "$N"+str+"��", 0);
    SOUL_D->add_emote(str, "STR", "$N"+str+"$o.", 0);
    SOUL_D->add_emote(str, "OBJ", "$N"+"��$o"+str+"��", 0);
    SOUL_D->add_emote(str, "LIV", "$N"+"��$t"+str+"��", 0);
    out("Added.\n");
}
