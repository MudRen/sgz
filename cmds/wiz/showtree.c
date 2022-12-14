// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

// Quick hack by Beek

#include <mudlib.h>

inherit CMD;

varargs string print_tree(string file, string func, int indent) {
    object ob;
    string result;
    int found;
    
    if( !file )
    {
        return "你要指定一个文件。\n";
    }
    
    ob = find_object( file );
    if (file[0] != '/')
        file = "/" + file;
    
    if (!ob) {
        return repeat_string("  ", indent) + "找不到文件: " + file + "\n";
    }
    result = repeat_string("  ", indent) + file + ":\n";
    if (func && (function_exists(func, ob) + ".c") == file) {
    result += repeat_string("  ", indent) + "  [defined]\n";
        found = 1;
    } else if (!func)
        found = 1;

    indent++;
    foreach (file in inherit_list(ob)) {
        string str = print_tree(file, func, indent);
        if (str != "") {
            result += str;
            found = 1;
        }
    }   
    return (found ? result : "");
}

// [str] cfile
private void main(mixed *arg) {
    string file, func;

    if (arg[1]) {
        file = arg[1];
        func = arg[0];
        out("追踪函数 " + func + " 的定义，文件：" + file + "\n");
    } else {
        file = arg[0];
        func = 0;
    }

    out(print_tree(file, func));
}
