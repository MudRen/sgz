// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

#include <mudlib.h>
#include <daemons.h>

inherit CMD;

private void main(string str) {
    mixed data;
    mixed *m;
    int i;

    if (!str) {
        out("用法：showemote verb\n");
        return;
    }
    data = SOUL_D->query_emote(str);
    if (!data) {
        out("没有这个 emote.\n");
        return;
    }
    m = keys(data);
    for (i=0; i<sizeof(m); i++) {
        if (stringp(data[m[i]])) {
            outf("%O -> %s\n", m[i], data[m[i]]);
        } else {
            outf("%O -> %s\n", m[i], implode(data[m[i]], "\n\t-> "));
        }
    }
}

