// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

//  Yaynu@Lima Bean
#include <mudlib.h>
inherit CMD;
inherit M_ANSI;
 
private void main(string arg) {
object forwho;   
if(!arg){
    if(i_use_ansi())  out("Ansi ɫ����"+
        ansi("%^BOLD%^%^MAGENTA%^�򿪵ġ�%^RESET%^%^WHITE%^")+"\n");
    else out("Ansi ɫ���ǹرյġ�\n");
    return;
        }     
    if(!forwho)
      forwho = this_user();
    if(arg != "on" && arg != "off"){
        out("�÷�: ansi <on/off>.\n");
        return;}
    if(arg == "on") {
        this_body()->query_shell_ob()->set_variable( "ansi" , 1);      
        out("�� ansi ɫ�ʡ�\n");
     this_user()->update_translations();
        return;}
        this_body()->query_shell_ob()->unset_variable( "ansi"); 
     this_user()->update_translations();
        out("�ر� ansi ɫ�ʡ�\n");
        return;
}                                    
 

