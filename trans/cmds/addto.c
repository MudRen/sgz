// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

// >> makes this command a bit obsolete, so it's not updated to use |

#include <mudlib.h>
inherit CMD;

string *lines;

private void main(mixed * arg) {
    if ( is_file(arg[0]) )
    {
        lines = explode(read_file(arg[0]), "\n");
        //out("Adding to: " + arg[0] + "\nuse '.' when done.\n-------------------------------------------------------\n");
        out("添加在文件末尾："+arg[0]+"\t\t用 '.' 结束编辑。\n-------------------------------------------------------\n");
        out(implode(lines[<10..<1], "\n") + "\n");
    }
    else
    {
        //out("Creating: " + arg[0] + "\nuse '.' when done.\n-------------------------------------------------------\n");
        out("建立文件：" + arg[0] + "\t\t用 '.' 结束编辑。\n-------------------------------------------------------\n");
    }

    new(ADDTO_OB)->addto(arg[0]);
}

