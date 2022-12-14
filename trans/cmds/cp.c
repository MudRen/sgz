// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

// Simple cp, no -r yet.
#include <mudlib.h>
inherit CMD;

private void copy_one(string src, string dst, int force)
{
    string contents;

    if ( is_file(dst) && !force )
    {
        outf(//"%s already exists.  Copy failed.\n", 
             "%s 早已存在，拷贝失败。\n", dst);
    }
    else if ( !(contents = read_file(src)) )
    {
        outf(//"Could not read %s.  Copy failed.\n"
             "无法读取文件 %s，拷贝失败。\n", src);
    }
    else if ( !write_file(dst, contents, 1) )
    {
        outf(//"%s could not be written to.  Copy failed.\n"
             "%s 不能被写，拷贝失败。\n", dst);
    }
    else
    {
        outf(//"%s copied to %s.\n"
             "%s 拷贝到 %s。\n", src, dst);
    }
}

private void main(mixed argv, mapping flags)
{
    string src;
    string dst;
  
    if(sizeof(argv[0]) > 1 && !is_directory(argv[1]))
    {
        //outf("cp: files dir not files file\n");
        outf("用法：cp <文件群> <目录> 而不是 cp <文件群> <文件>\n");
        return;
    }
    if(sizeof(argv[0]) > 1)
    {
        if(argv[1][<1] != '/')
            argv[1] += "/";

        foreach(src in argv[0])
            {
                dst = argv[1] + split_path(src)[1];
                copy_one(src, dst, flags["f"]);
            }
    }
    else 
    {
        dst = argv[1];
        src = argv[0][0];

        if(is_directory(dst))
        {
            if(dst[<1] != '/')
                dst += "/";
            dst += depath(src);
        }

        copy_one(src, dst, flags["f"]);
    }
}
