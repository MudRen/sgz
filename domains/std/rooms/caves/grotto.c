// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

inherit ROOM;

void setup()
{
  set_area ("pirate");
  set_brief("彩绘岩穴");
  set_long("翻腾的海浪冲击着岩穴的入口，"
           "虽然这里的一些图画被海水冲毁，它们仍旧艳丽异常。"
           "淡淡的光线照入这个岩穴，但你无法分辨出到底是阳光还是月光。"
           "你只是勉强可以辨认出那北面墙内阴暗处的矮洞口。");
  set_exits( ([
               "south" : "../beach/outside_cave.c",
               "out" : "../beach/outside_cave.c",
               "north" : "low_crawl.c"
               ]) );
  set_hidden_exits("south");
  set_default_exit( "这个方向没有出口。\n");

  set_objects( ([
                 "/domains/std/objects/dead_adventurer" : 1,
              "/domains/std/monsters/troll" :1,
                 ]) );

  add_item( "cave", "paint", "paintings", "grotto", "彩绘", "图画",
           "这些图画描绘是死亡的题材，让人不禁心惊肉跳。");

  add_item( "light", "光线", "似乎是从外面照进来的。" );
  add_item( "moonlight", "月光", "你无法肯定它是月光。" );
  add_item( "sunlight",  "阳光", "你无法肯定它是阳光。");
  add_item( "crawl", "low crawl", "矮洞口", "矮洞", "它在北面。" );

  add_item( "waves", "water" , "海浪", "海水",
           ([
             "look" : "只不过是普通海水。",
             "wade" : "那不过是浪费时间。",
             "swim" : "这些水太浅了。",
             ]));
  
}


