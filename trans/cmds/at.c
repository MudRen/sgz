// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

#include <mudlib.h>
inherit CMD;

#define USAGE "�÷���at <����> <����>\n" //"Usage: at <living> <command>\n"

private void main( mixed *arg ) {
    string where;
    object start, targ;

    start = environment(this_body());
    targ = environment(arg[0]);
    if(!targ){
        //out("Your target has no environment.\n");
        out("���Ŀ��û�л�����\n");
        return;
    }
    this_body()->move( targ );
    this_user()->force_me(implode(arg[1], " "));
    if(start)
      this_body()->move( start );
}
