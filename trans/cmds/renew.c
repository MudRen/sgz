/* Do not remove the headers from this file! see /USAGE for more info. */

#include <commands.h>

inherit CMD;

private void main(mixed *arg) {
    object ob, env;
    string file;
    string data;
    
    ob = arg[0];
    file = base_name(ob);
    sscanf(file, "%s.c", file);
    if (file_size(file+".c")<0) {
        outf("renew: 文件 " + file + ".c 不存在 (或者是一个目录)。\n");
        return 0;
    }
    env = environment(ob);
    data = ob->save_to_string(1);
    ob->remove();
    outf("更新 " + file + ".c ...\n");
    if (CMD_OB_UPDATE->do_update(file + ".c", 3) < time())
        out(file + ": 无需更新。\n");
    ob = new(file);
    ob->load_from_string(data, 1);
    ob->move(env);
}
