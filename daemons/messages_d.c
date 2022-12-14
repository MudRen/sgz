// messages_d.c modified by fire on March 7 1998
// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */
// This really be dynamic, with managing commands, but for now ...
//###TODO: make an interface to this crap.  Put it in a file.
//###combat-torch also needs serious help.
#define ES2SKILL(x) "/kungfu/skill/"+x+".c"

static array parts=({"前额","左颊","右颊","左肩","右肩","胸口",
			 "左臂","右臂","小腹","腰间","左腿","右腿",});
static mapping bat_mess =([]);

static mapping messages = 
([

  "living-default" :
  ([
    "leave": "$n朝$o离开了。\n", 
    "mleave": "$n的身影在一阵烟雾中渐渐隐去。\n",
    "enter": "$n走了过来。\n", //"$n $venter.\n",
    "menter": "$n突然出现在一阵烟雾中。\n", 
    "invis": "$n从你的视野中突然消失了。\n", 
    "vis": "$n突然出现在你面前，又似乎在这里很久了。\n", 
    "home": "$n回家去了。\n", 
    "clone": "$n伸手凌空一指，变出了$o。\n", 
    "destruct": "$n袍袖一挥，$o被化成一股黑烟，吹散开去。\n", 
    ]),
  "player-death" : ({
      "这时，传来消息说：$n去世了。",
      "非常不幸，$n仙逝了。",
  }),
"combat-msg" :
  ([ "praise" :
    ({ "$n不禁赞道：$m果名将也！\n",
       "$n点点头道：$r$m，没想到还真有两手。\n" }),
    "angry" :
    ({ "$n怒道：$m，看我不取下你的狗头！\n",
       "$n怒目圆睁，恨不得一口把$T给生吞下去。\n" }),
     "other" :
    ({ "$n大声道：来、来、来，你我再战三百合。\n",
	"$n凛然道：为国效力，就算战死疆场也无怨言。\n",
	"$n道：$r休走，明年的今日便是你的祭日！\n"
        }),
    ]),
  "nonsense" : ({
      "这个... 今天天气真好啊...\n",
      "您别开玩笑了... \n",
      "好主意... 真是好主意...\n",
      "您别没事找事儿做... 省省吧...\n",
  }),
  "discarded" : ({
      "有人把%s丢在地上了。",
      "好象有人把%s留在这儿了。",
      "%s被弃置在地上。",
      "%s就放在你的身边。",
      "%s放在地上，没有人注意。",
  }),
  ]);
mixed get_messages(string type) {
    return messages[type];
}
mixed get_detail_messages(string type,string subtype) {
	if (!messages[type]) return ({"少一条信息 for "+type+"。\n"});
	if (!messages[type][subtype]) ({"少一条信息 for "+type+"and"+subtype+"。\n"});
    return messages[type][subtype];
}

mixed get_info(mixed inp) {
	if(!sizeof(inp)) return "";
	return inp[random(sizeof(inp))];
}
string part_tran(string inp) {
	string pat=get_info(parts);
	return replace_string(inp,"xx",pat);
}
mixed get_fight_message(string type,string subtype,int level) {
	string ret,old_type;
        //modify by suicide in 20011230 for add extra special kungfu.
        string mapped_skill=previous_object()->query_skill_mapped(type);
        old_type=type;
        if (mapped_skill) type=mapped_skill;
        if(!bat_mess[type]) 
           if (mapped_skill)  //如果有高级enable的武功
              if (file_size(ES2SKILL(mapped_skill))>0)
                    bat_mess[type]=load_object(ES2SKILL(mapped_skill))->bat_message();
        else
           return "don't have the type of "+type+" yet\n";
        //end
	if(!bat_mess[type][level]) 
	{
		if(level<0) return "don't have the type of "+type+" yet\n";
			return get_fight_message(old_type,subtype,level-1);
	}
	switch(subtype) {
/*	case "hit":
	case "miss":
		ret=get_info(bat_mess[type][level]["attack"])+"\n"
			+get_info(bat_mess[type][level][subtype])+"\n";
		break;
*/
        case "wait": 
	default :
		if(!bat_mess[type][level][subtype])
			//return sprintf("don't have type is %s sub type is %s level is %d\n",type,subtype,level);
			ret = get_info(bat_mess[old_type][0][subtype])+"\n";
		else
			ret=get_info(bat_mess[type][level][subtype])+"\n";
//	        printf("old_type=%s subtype=%s \n info = %O\n",old_type,subtype,ret);
		break;
	}
	return part_tran(ret);
}

void create()
{
bat_mess["unarmed"]=(__DIR__+"messages_d/unarmed")->bat_message();
bat_mess["sword"]=(__DIR__+"messages_d/sword")->bat_message();
bat_mess["blade"]=(__DIR__+"messages_d/blade")->bat_message();
bat_mess["spear"]=(__DIR__+"messages_d/spear")->bat_message();
bat_mess["ji"]=(__DIR__+"messages_d/ji")->bat_message();
bat_mess["hammer"]=(__DIR__+"messages_d/hammer")->bat_message();
bat_mess["axe"]=(__DIR__+"messages_d/axe")->bat_message();

}
