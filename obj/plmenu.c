// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

/*      
**      Player menu by John Viega (rust@virginia.edu) 5-Jul-95
**      For the Lima mudlib.
**
**      Still want to have:
**      o channel menu
**     o more reporter commands
**      o what's new or something like that.
**      o take args at line, ie, b yes for biff or somesuch
**     o disable newbie options
*/

#include <menu.h>
#include <mudlib.h>
#include <playerflags.h>
#include <commands.h>
//### for now
#include <security.h>

inherit MENUS;
//### for now
inherit M_ACCESS;

MENU toplevel;
// submenus of the toplevel (main) menu
MENU soulmenu;
MENU reportmenu;
MENU remotemenu;
MENU personalmenu;
// submenus of personalmenu
MENU biffmenu;  
MENU snoopablemenu; 
// Wizard stuff
MENU wizmenu;
MENU testmenu;


MENU_ITEM quit_item;    
MENU_ITEM goto_main_menu_item;
MENU_ITEM main_seperator;

// right now, we're just going to call the help command.
//private MENU helpmenu;


private mapping dispatch = ([ "n" : "news", "w" : "who", 
                              "b" : "bug", "t" : "typo", "i" : "idea",
                              "?" : "help", "l" : "mudlist" ]);


private nomask void simple_cmd(string cmd)
{
    call_other(CMD_DIR_PLAYER "/" + dispatch[cmd], "player_menu_entry");
}


void
start_mail()
{
    this_body()->query_mailer()->begin_mail();
}

void handle_finger(string person)
{
    CMD_OB_FINGER->player_menu_entry(person);
    prompt_then_return();
}

void test_soul(string s)
{
    CMD_OB_SEMOTE->player_menu_entry(s);
    prompt_then_return();
}

void find_soul(string s)
{
    if(!s) {
        write("Invalid.\n");    
        return;
    }

    CMD_OB_EMOTEAPROPOS->player_menu_entry(s);
}

void show_souls(string s)
{
    CMD_OB_FEELINGS->player_menu_entry(s);
}

 
void show_adverbs(string s)
{
/*  write(
"Remember: You can get any of these adverbs by typing part of the adverb \n"
"then *, if the part you type is unique.  Eg, kick rust ene* would give you:\n"
"kick rust energetically, but kick rust en* won't because it also\n"
"matches endearingly and enthusiastically.\n");
*/
  write(
  "��ס��������ü�д��ƴдһ�����ʣ���������ǰ���ֽ���������һ�� * ��\n"
  "ǰ������Ҫ��Ψһȷ��һ�����ʡ����磺kick rust ene* ���ɣ�\n"
  "kick rust energetically���� kick rust en* ���ᣬ��Ϊ en* ͬʱ����Ӧ\n"
  "�� endearingly �� enthusiastically��\n");
  CMD_OB_ADVERBS->player_menu_entry(s);
}


void change_email(string s)
{
  this_user()->set_email(s);
  //write("Email info changed.\n");
    write("�����ʼ���Ϣ�����ˡ�\n");
}

void change_url(string s)
{
  this_user()->set_url(s);
  //write("Home page address changed.\n");
    write("�����ҳ��Ϣ�����ˡ�\n");
}

void
change_title(string s)
{

//  if(strsrch(s,"$N") == -1)
//    s = "$N " + s;
  this_body()->set_title(s);
  
  //write("Title changed.\n");
  write("�ƺŸ����ˡ�\n");
}
 
void
query_personal_info()
{
  printf(
/*         "Your title is: %s\n"
         "Your provided e-mail address is: %s\n"
         "Your provided WWW home page is: %s\n"
         "You %sget notified when new mail arrives.\n" 
         "Wizards %s snoop you.\n",
*/
         "��ĳƺ��ǣ�%s\n"
         "���ṩ�ĵ����ʼ�(e-mail)��ַ�ǣ�%s\n"
         "���ṩ�������ҳ(homepage)�ǣ�%s\n"
         "%s���������ʼ�ʱ�����㡣\n"
         "��ʦ%s�����㡣\n",
         this_body()->query_title(),
         this_user()->query_email(),
         this_user()->query_url(),
         this_body()->test_flag(F_BIFF) ? "" : "��",
         this_body()->test_flag(F_SNOOPABLE) ? "�ܹ�" : "���ܹ�"
         );

  prompt_then_return();
}

void
prompt_change_title()
{
  get_input_then_call ((: change_title :), //"Change title to what? "
                                           "�ĸ�ʲô�ƺ��أ�" );
}

void
prompt_change_email()
{
  get_input_then_call ((: change_email :), //"Change e-mail to what? "
                                           "�ѵ����ʼ���ַ(e-mail)�ĳ�ʲô��");
}

void 
prompt_change_url()
{
  get_input_then_call ((: change_url :), //"Change your WWW homepage address to what? "
                                         "�������ҳ��ַ(homepage)�ĳ�ʲô��");
}


void 
set_biff(string s)
{
  if(s == "y")
    {
      this_body()->set_flag(F_BIFF);    
      //write("Mail notification is now on.\n");
      write("�ʼ���ʾ���ڴ򿪡�\n");

    }
  else
    {
      this_body()->clear_flag(F_BIFF);  
      //write("Mail notification is now off.\n");
      write("�ʼ���ʾ���ڹرա�\n");
    }
  goto_previous_menu();
} 

 
void
set_ansi(string s)
{
  if(s && s=="on")
  {
  this_body()->query_shell_ob()->set_variable( "ansi" , 1);
  //write("Ansi is now on.\n");
    write("ɫ�ʿ�����\n");
  } else {
  this_body()->query_shell_ob()->unset_variable( "ansi");
  //write("Ansi is off.\n");
  write("ɫ�ʹرա�\n");
}
}
      
   
void
set_snoopable(string s)
{
  if(s == "n")
    {
      this_body()->clear_flag(F_SNOOPABLE);
      write(//"You now can not be snooped (except by admins)\n"
            "���ڿ�ʼ����������û���˿��Լ����㡣\n");
    }
  else
    {
      this_body()->set_flag(F_SNOOPABLE);
      write(//"Any wizard can now snoop you.\n"
            "���ڿ�ʼ���κ���ʦ�����Լ����㡣\n");
    }
  goto_previous_menu();
}

void finish_who(string mudname)
{
    CMD_OB_FINGER->player_menu_entry("@" + mudname);
    printf(//"%s queried.  It's up to that mud to reply to you.\n",
           "�� %s ��ѯ���Ѿ��ͳ��������᲻�����ش�\n", mudname);
    prompt_then_return();
}

void
remote_who()
{
  //write("Which mud do you want to query?\n");
  write("��Ҫ���ĸ� MUD ѯ�ʣ�\n");
  complete_choice(0, IMUD_D->query_mudnames(), (: finish_who :));
}

#if 0 /* mudinfo is a wiz command */
void finish_mudinfo(string mudname)
{
    do_cmd( "mudinfo " + mudname );

    printf("%s queried.  It's up to that mud to reply to you.\n"
           "�� %s ��ѯ���Ѿ��ͳ��������᲻�����ش�\n", mudname);
}
 
void remote_muds()
{
    do_cmd( "mudlist" );
}
void remote_mudinfo()
{
   //write("Which mud do you want to query?\n");
   write("��Ҫ���ĸ� MUD ѯ�ʣ�\n");
   complete_choice(0, IMUD_D->query_mudnames(), (: finish_mudinfo :));
}
#endif /* 0 */

void
create()
{
    set_privilege(1);

  toplevel      = new_menu(mud_name()+"��̶��Ϸѡ��");
  soulmenu      = new_menu("���ѡ��");
  reportmenu    = new_menu("����ѡ��");
  personalmenu  = new_menu("����ѡ��");
  biffmenu      = new_menu("�յ��ʼ�ʱ�Ƿ���ʾ�㣿");
  snoopablemenu = new_menu("����ʦ���Լ�������");
  remotemenu    = new_menu("������̶(MUD)");
  wizmenu       = new_menu("��ʦѡ��");

  // Since we'll use these things more than once, we can just
  // call new_menu_item once, and insert them wherever we want
  // to use them.
  quit_item = new_menu_item("�˳�", (:quit_menu_application:), "q");
  goto_main_menu_item =new_menu_item("�ص���ѡ��", 
                                         toplevel, "m");


  main_seperator = new_seperator("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");


  // Add items to the toplevel (main) menu.  
  add_menu_item (toplevel, main_seperator);
  add_menu_item (toplevel, new_menu_item("�Ķ����� (news)", 
                                         (: simple_cmd :), "n"));
  add_menu_item (toplevel, new_menu_item("�շ��ʼ� (mail)",
                                         (: start_mail :), "m"));
  // The 1 at the end of this next one creates a prompt:
  // "[Hit enter to return to menu] "
  // You can also do this by calling prompt_then_return() from your
  // function.
  add_menu_item (toplevel, new_menu_item("��������˭�������У� (who)", 
                                            (: simple_cmd :), "w", 1));
  add_menu_item (toplevel, new_menu_item("��ѯĳ�˵��� (finger)", 
                                            (: get_input_then_call, 
                                              (: handle_finger :),
                                             "��ѯ˭�ĵ��� ? ":), "f"));
  add_menu_item (toplevel, new_menu_item("���/���� ѡ��", soulmenu, "s"));
  add_menu_item (toplevel, new_menu_item("�㱨����ƴд����������", 
                                         reportmenu, "r"));
  add_menu_item (toplevel, new_menu_item("���Ļ���ʾ����С����",
                                         personalmenu, "i"));
  add_menu_item (toplevel, new_menu_item("����������̶(mud)����Ϣ",
                                         remotemenu, "o"));
  add_menu_item (toplevel, new_menu_item("��ʦ�Ķ���", wizmenu, "*", 0, 
                                         (: wizardp(this_user()) :)));
  add_menu_item (toplevel, quit_item);
  add_menu_item (toplevel, new_menu_item("����", (: simple_cmd :), "?"));

  // Add items to the soul menu.
  add_menu_item (soulmenu, main_seperator);
  add_menu_item (soulmenu, 
                 new_menu_item("�г����ʻ�", (: get_input_then_call,
                                              (: show_souls :),
                                              "���ĸ���ĸ��ͷ��"
                                              "(enter �������е�): ":),
                               "s"));
  add_menu_item (soulmenu, 
                 new_menu_item("�г����ʴʻ�", (: get_input_then_call,
                                              (: show_adverbs :),
                                              "���ĸ���ĸ��ͷ��"
                                              "(enter �������е�): ":),
                               "a"));
  add_menu_item (soulmenu, 
                 new_menu_item("�������", (: get_input_then_call,
                                              (: find_soul :),
                                              "���ҵ����Ҫ�������֣�" :),
                               "f"));

  add_menu_item (soulmenu, 
                 new_menu_item("�������", (: get_input_then_call,
                                      (: test_soul :),
                                      "�������: ":),
                       "t"));

  add_menu_item (soulmenu, quit_item);
  
  add_menu_item (soulmenu, goto_main_menu_item);
                                         
  add_menu_item (reportmenu, main_seperator);
  add_menu_item (reportmenu, new_menu_item("�㱨��̴���", (: simple_cmd :),
                                           "b"));
  add_menu_item (reportmenu, new_menu_item("�㱨ƴд����", (: simple_cmd :),
                                           "t"));
  add_menu_item (reportmenu, new_menu_item("�������뷨", (: simple_cmd :),
                                           "i"));
  add_menu_item (reportmenu, quit_item);
  add_menu_item (reportmenu, goto_main_menu_item);

  add_menu_item (personalmenu, main_seperator);
  add_menu_item (personalmenu, new_menu_item("���ĸ���С����",
                                             (: query_personal_info :), "v"));
  add_menu_item (personalmenu, new_menu_item("�ı�ƺ�", 
                                             (: prompt_change_title :), "t"));
  add_menu_item (personalmenu, new_menu_item("�ı�����ʼ�(e-mail)��ַ",
                                             (: prompt_change_email :), "e"));
  add_menu_item (personalmenu, new_menu_item("�ı������ҳ(homepage)��ַ",
                                             (: prompt_change_url :), "w"));
  add_menu_item (personalmenu, new_menu_item("�趨��ȡ���ʼ���ʾ",
                                             biffmenu, "n"));
  add_menu_item (personalmenu, new_menu_item("�趨�Ƿ񱻼���", snoopablemenu, "s"));
  //  add_menu_item (personalmenu, new_menu_item("Change your supplied real name",
  //                                         (: prompt_change_real_name :), "n"));
add_menu_item(personalmenu, new_menu_item("����ɫ��", (: get_input_then_call, (: set_ansi :), "Ansi 'on' or 'off' ? (default off): ":), "a"));
 
  add_menu_item (personalmenu, quit_item);
  add_menu_item (personalmenu, goto_main_menu_item);

  add_menu_item (biffmenu, main_seperator);
  add_menu_item (biffmenu, new_menu_item("Yes", (: set_biff :), "y"));
  add_menu_item (biffmenu, new_menu_item("No", (: set_biff :), "n"));
  add_menu_item (biffmenu, quit_item);
  add_menu_item (biffmenu, goto_main_menu_item);

  add_menu_item (snoopablemenu, main_seperator);
  add_menu_item (snoopablemenu, new_menu_item("Yes", 
                                              (: set_snoopable :), "y"));
  add_menu_item (snoopablemenu, new_menu_item("No", 
                                              (: set_snoopable :), "n"));
  add_menu_item (snoopablemenu, quit_item);
  add_menu_item (snoopablemenu, goto_main_menu_item);

  add_menu_item (remotemenu, main_seperator);
  add_menu_item (remotemenu, new_menu_item("�г�" + mud_name() + 
                                           "��֪����̶(mud)", 
                (: simple_cmd :), "l", 1 ));
  add_menu_item (remotemenu, new_menu_item("��������˭��������̶(mud)��",
                                           (:remote_who:), "w"));
  add_menu_item (remotemenu, quit_item);
  add_menu_item (remotemenu, goto_main_menu_item);
  add_menu_item (wizmenu, main_seperator);
//  add_menu_item (wizmenu, new_menu_item("Info on another mud",
//                                      (: remote_mudinfo :), "i"));
  add_menu_item (wizmenu, quit_item);
  add_menu_item (wizmenu, goto_main_menu_item);

}


void
start_menu()
{
  init_menu_application(toplevel);
}
