// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

// The specification is: tail file *
// We will recieve: ({ array of file names })

#include <mudlib.h>
inherit CMD;

void tail(string file, int n)
{
  out(implode(explode(read_file(file),"\n")[0..(n-1)],"\n"));
}

private void main( mixed *arg, mapping flags, string stdin ) {
  int i;
  int n = 10;
  if(flags["n"]) n = (to_int(flags["n"]) || 10);
  if(stdin)
    {
      out(implode(explode(stdin,"\n")[0..(n-1)],"\n"));
      return;
    }
  for (i=0; i<sizeof(arg[0]); i++) {
    tail(arg[0][i],n);
  }
}

int help() {
  //printf("Usage: tail [file]\n"
  //  "Description: display the last lines of a file\n");
  printf("用法：head <文件名>\n"
         "说明：显示文件前几行。\n" );
  return 1;
}
