// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

inherit OUTDOOR_ROOM;

void obj_arrived(object ob) {
    if (ob->get_size() >= VERY_LARGE) 
      {
     if(!ob->is_living())
        receive_inside_msg(ob->short() + "落入水中，水花四溅。\n");
        return;
      }
    receive_inside_msg(ob->short() + "沉入水中，很快，在翻腾的浪花中消失了踪影。\n");
    destruct(ob);
}

void setup()
{
    string m = "这里的山壁过于陡峭，你无法攀登。\n";
    string o = "你会被淹死的！\n";

  set_brief("外洞");
  set_area ("pirate");
  set_long("你正站在及膝深的水里，不远处看起来象是个小山洞。"
           "海浪猛烈地冲击着山壁。要想保持平衡都十分困难。沿岸的山壁"
           "旁留出了些许空地，形成一道狭长沙滩。");
  set_exits( ([
               "in" : "../caves/grotto.c",
               "north" : "../caves/grotto.c",
               "east" : "rocky_beach.c",
               "west" : "sandy_beach.c",
               "northeast" :  m,
               "northwest" :  m,
               "south" : o,
               "southeast" : o,
               "southwest" : o,
               ]) );

  add_item( "surf", "water",  "海浪", "海水",
           ([
             "adjs": "fierce",
             "look": "浪头很大，你只有尽力保证不被冲走。",
             "wade": "你正在水中呢。",
             "swim": "你会被淹死的！",
             ]));

  add_item( "cave", "tiny cave", "小山洞", "山洞", 
                "从这个角度，你看不到多少。");

  add_item( "ocean", "海", "海洋", ([
           "look" :  "你尽力想看清海的另一头是什么，但这是白费力。"
                     "你好象看到远处有什么东西，可是相隔太远，会不会"
                     "是艘船呢？",
           "wade":   "你正在水中呢。",
           "swim":   "你会被淹死的！",
             ]));

  add_item( "mountains", "steep mountains", "山壁",
            ([
              "climb" : m,
              "look" : m,
             ]));

  add_item( "sand", "beach" , "沙滩", "这道沙滩是东西向的。" );

  set_hidden_exits("northeast","northwest","south","southeast","southwest", 
                   "in");

  add_hook("object_arrived", (: obj_arrived :));
}


void do_enter(string s)
{
  if(s == "cave")
    this_body()->do_game_command("in");
  else
    write(this_body()->nonsense());
}


mixed direct_enter_obj()
{
  return 1;
}
