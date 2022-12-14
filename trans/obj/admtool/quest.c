// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

/*
** news.c -- News administration
**
** 951124, Rust: created
*/

#include <mudlib.h>


void std_handler(string str);
varargs void modal_simple(function input_func, int secure);
varargs void modal_func(function input_func, mixed prompt_func, int secure);
void receive_quest_input(string);

#define PROMPT_QUEST     "(AdmTool:quest)   [lLarmq?] > "

private nomask void write_quest_menu()
{
/*
    write("Administration Tool: quest administration\n"
          "\n"
          "    l        - list all places to get points\n"
          "    L        - list all quests\n"
          "    a <name> - add quest points for a goal\n"
          "    r <name> - remove quest points for a goal\n"
          "\n"
          "    m        - main menu\n"
          "    q        - quit\n"
          "    ?        - help\n"
          "\n"
          );
*/
    write("管理工具：QUEST 管理\n"
          "\n"
          "    l        - 列出所有拿分点\n"
          "    L        - 列出所有 QUESTs\n"
          "    a <名称> - 为目标增加拿分点\n"
          "    r <名称> - 为目标删除拿分点\n"
          "\n"
          "    m        - 主选单\n"
          "    q        - 退出\n"
          "    ?        - 帮助\n"
          "\n"  
          );        
}

private nomask void list_quests()
{
    more(QUEST_D->quest_dump());
}


string new_quest_name;
int value;
string master_file;

private nomask void get_milestone(string s)
{
  if(!stringp(s) || !strlen(s))
    {
      s = 0;
    }
  QUEST_D->add_quest(new_quest_name, value, master_file, s);

  printf("Quest %s 增加了。\n", new_quest_name);
  modal_func((: receive_quest_input :), PROMPT_QUEST);
}

private nomask void get_master(string master)
{
  if(!is_file(master_file=evaluate_path(master)) &&
     !is_file(master_file+".c"))
    {
      //write("That file doesn't exist.\n");
      write("这个文件不存在。\n");
      return;
    }
  modal_func((:get_milestone:), //"If this is a quest endpoint, give a one line description of the quest for \nplayers, or else hit enter (and nothing else!):  "
                                "如过这是一个 quest 的终点，请给出一行 quest 的描述，否则回车：\n");
             
}


private nomask void get_value(string pts_as_string)
{
  value = to_int(pts_as_string);
  printf(//"Quest %s' value is set at %d points.\n"
         "Quest %s 的值设为 %d 分。\n", new_quest_name, value);
  modal_func((:get_master:), //"What file can dole out these points? "
                             "哪个文件给出这些分呢？");
}

private nomask void add_quest(string name)
{
  if(!stringp(name) || !strlen(name))
    {
      //write("Not a valid quest name.\n");
      write("非法 quest 的名字。\n");
      return;
    }
  if(QUEST_D->quest_exists(name))
    {
      //write("That quest already exists.\n");
      write("这个 quest 早就存在了。\n");
      return;
    }
  new_quest_name = name;
  modal_func((:get_value:), //"How many points is this quest item worth? "
                            "这个 quest 值多少分呢？");
  
}


private nomask void remove_quest(string name)
{
  if(!QUEST_D->delete_quest(name))
    {
      //write("No such quest.\n");
      write("没有这个 quest。\n");
      return;
    }
  else
    {
      //write("Deleted.\n");
      write("删除了。\n");
    }
}


private nomask void receive_quest_input(string str)
{
    string name;

    sscanf(str, "%s %s", str, name);

    switch ( str )
    {
    case "l":
        list_quests();
        break;

    case "L":
        more(QUEST_D->dump_final_goals());
        break;

    case "a":
        if(!name)
          {
            write("a <quest name>\n");
            return;
          }
        add_quest(name);
        break;

    case "r":
        if(!name)
          {
            write("r <quest name>\n");
            return;
          }
        remove_quest(name);
        break;

    case "?":
        write_quest_menu();
        break;

    default:
        std_handler(str);
        break;
    }
}

static nomask void begin_quest_menu()
{
    modal_func((: receive_quest_input :), PROMPT_QUEST);
    write_quest_menu();
}
