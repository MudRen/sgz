// messages_d.c modified by fire on March 7 1998
// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */
// This really be dynamic, with managing commands, but for now ...
//###TODO: make an interface to this crap.  Put it in a file.
//###combat-torch also needs serious help.
#define ES2SKILL(x) "/kungfu/skill/"+x+".c"

static array parts=({"ǰ��","���","�Ҽ�","���","�Ҽ�","�ؿ�",
			 "���","�ұ�","С��","����","����","����",});
static mapping bat_mess =([]);

static mapping messages = 
([

  "living-default" :
  ([
    "leave": "$n��$o�뿪�ˡ�\n", 
    "mleave": "$n����Ӱ��һ�������н�����ȥ��\n",
    "enter": "$n���˹�����\n", //"$n $venter.\n",
    "menter": "$nͻȻ������һ�������С�\n", 
    "invis": "$n�������Ұ��ͻȻ��ʧ�ˡ�\n", 
    "vis": "$nͻȻ����������ǰ�����ƺ�������ܾ��ˡ�\n", 
    "home": "$n�ؼ�ȥ�ˡ�\n", 
    "clone": "$n�������һָ�������$o��\n", 
    "destruct": "$n����һ�ӣ�$o������һ�ɺ��̣���ɢ��ȥ��\n", 
    ]),
  "player-death" : ({
      "��ʱ��������Ϣ˵��$nȥ���ˡ�",
      "�ǳ����ң�$n�����ˡ�",
  }),
"combat-msg" :
  ([ "praise" :
    ({ "$n�����޵���$m������Ҳ��\n",
       "$n���ͷ����$r$m��û�뵽���������֡�\n" }),
    "angry" :
    ({ "$nŭ����$m�����Ҳ�ȡ����Ĺ�ͷ��\n",
       "$nŭĿԲ�����޲���һ�ڰ�$T��������ȥ��\n" }),
     "other" :
    ({ "$n��������������������������ս���ٺϡ�\n",
	"$n��Ȼ����Ϊ��Ч��������ս������Ҳ��Թ�ԡ�\n",
	"$n����$r���ߣ�����Ľ��ձ�����ļ��գ�\n"
        }),
    ]),
  "nonsense" : ({
      "���... ����������ð�...\n",
      "������Ц��... \n",
      "������... ���Ǻ�����...\n",
      "����û�����¶���... ʡʡ��...\n",
  }),
  "discarded" : ({
      "���˰�%s���ڵ����ˡ�",
      "�������˰�%s��������ˡ�",
      "%s�������ڵ��ϡ�",
      "%s�ͷ��������ߡ�",
      "%s���ڵ��ϣ�û����ע�⡣",
  }),
  ]);
mixed get_messages(string type) {
    return messages[type];
}
mixed get_detail_messages(string type,string subtype) {
	if (!messages[type]) return ({"��һ����Ϣ for "+type+"��\n"});
	if (!messages[type][subtype]) ({"��һ����Ϣ for "+type+"and"+subtype+"��\n"});
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
           if (mapped_skill)  //����и߼�enable���书
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
