// Updated by stefan on 10 Jan 1997
// Updated by stefan on 8 Feb 1998
/* Do not remove the headers from this file! see /USAGE for more info. */

#include <mudlib.h>

inherit CMD;


private void main( mixed *arg, mapping f)
{
    object      target;
    mixed       output;
    string      flag;

    target = arg[0];
    if( f["i"] )
        output = implode(({sprintf("%s �ĺ����б�",file_name(target))})+
sort_array(
          map_array( functions( target ), (: sprintf("%-34s: %-34s",
                (function_exists($1, $(target)) ?
                  function_exists($1, $(target)) :
                "*STATIC*"), $1 ) :)), 1), "\n");
    else if( f["f"] )
        output =
        sprintf("%sֱ�ӻ��Ӽ̳����µ�����\n    %s\n", file_name(target),
                implode(deep_inherit_list(target), "\n    "));
    else
        output =
        sprintf("%s�ĺ����б�\n%-79#s\n",
          file_name(target), implode(sort_array(functions(target), 1),
"\n"));

            out(output);
        }
