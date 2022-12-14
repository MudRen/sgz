// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

// specification is: spew file str*
// we will recieve: ({ string, ({ args }) })
// This is pretty much something you can do w/ <

#include <mudlib.h>

inherit CMD;

// Quick hack by Rust 12-12-93
private void main(mixed* arg) {
    string buf;
    string* lines;
    string name;
    int loop;
    int i;
    int startln, numlines;
    string pipe;
    string file;
    string rest;

    file = arg[0];
    rest = implode(arg[1]," ");
    sscanf(rest, "%s %d %d", rest, startln, numlines);
    if(!buf = (numlines ? read_file(file, startln, numlines) :
        read_file(file, startln))){
        //write("Couldn't find your file.\n");
        write("找不到你的文件。\n");
        return;
    }
    pipe = "say";
    lines = explode(buf, "\n");
    i = sizeof(lines);
    for(loop = 0; loop<i; loop++){
        this_user()->force_me(pipe+" "+lines[loop]);
    }
    return;
}

int help(){

/*    write("Usage: spew <file> [startline] [# lines] [| command]\n"
      "dumps contents of the file to the screen as a say from the user.\n"
      "if pipe is used, dumps to the command specified.  Ie, \n"
      "spew /cmds/xtra/_spew | wiz\n"
      "would send the contents of this file over the wiz line.\n"
      "\n");
*/
      write("用法：spew <文件> [起始行号] [行数] [| <命令>]\n"
            "说明：把文件中的内容显示到屏幕上，作为使用者说(say)的话。\n"
            "      如果使用 pipe，就把文件中的每行作为 pipe 命令的参数。\n");
}
