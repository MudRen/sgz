/* ting.c
** Coded by 苑璧@三国志
** Code generated with RoomMaker v0.9.1 coded by Onyx@RedDragon
** Do not remove this header.
*/


inherit ROOM;
inherit STORE;

static string * nogo = ({
"$N茫然地在亭子中转了几圈，头都快晕了。",
"$N呆呆地看着远方，愣愣地出神。",
"$N迎着亭外的凉风，浑身打了个激灵。",
"$N刚刚迈步准备出去，忽然听到风铃乱响，不觉又踌躇起来。",
"$N一转身，觉得有人在注意行径，顿时停住脚步打量四周。",
"小道上到处都是树叶，$N不禁心中一紧：还是不去的好。",
"$N似乎听到远出响起雷声，还是待在这儿吧。",
"$N一出亭子，就被一种沉沉的阴翳压得喘不过气来，只好回转。",
});
   
string * going = ({ "轻快","慢慢","小心谨慎","迅速","匆匆","安闲", });

int sound() {
    write("风声、铃声、树叶声，你还隐隐约约地听到鸟叫声。\n");
    return 1;
}

int do_go_road() {
    object r;
    if( !wizardp(this_body()) ) {
        this_body()->simple_action(nogo[random(sizeof(nogo))]+"\n");
	return 1;
    }
    r = load_object(query_exits()[query_exit_directions(1)[random(sizeof(query_exit_directions(1)))]]);
    this_body()->simple_action("$N"+going[random(sizeof(going))]+
        "地走向一条小路，身影渐渐远去．．．\n");
    this_body()->move(r);
    tell_environment(this_body(), sprintf("%s走了过来。\n",
	this_body()->short()), 0, ({ this_body() }) );
    this_body()->force_look();
    return 1;
}

void setup(){
    set_light(1);
    set_brief("%^B_RED%^%^ORANGE%^香枫亭%^RESET%^%^ROOM_EXIT%^");
    set_long("
一个小小的亭子座落在枫林之中。四周树木参天，几条蜿蜒小道通向
密林深处。亭子中有一张桌子，四周放了些椅子。四根亭柱上各贴了
一句诗。亭外树叶被风吹得飒飒作响，一个风铃儿时不时地高高低低
叮当叮当几声。
\n"
);
    add_item("table", "桌子",
        ([ "look" : "一个红木大八仙桌。
桌上放了好几个精致的杯子。
中间的小碟子上还摆了些点心。"
        ]));
    add_item("chair", "椅子", "seat",
        ([ "look" : "几张镂花红木椅子。",
	   "sit"  : "你坐上一张红木椅子。",
	]));
    add_item("poem", "诗", "亭柱", "duilian",
        ([ "look" : "
        %^TELL%^月%^RESET%^挂%^NEWBIE_CHANNEL%^半%^RESET%^边%^WEATHER_CHANNEL%^天%^RESET%^，
        %^ANNOUNCE_CHANNEL%^嫦%^WIZ_CHANNEL%^娥%^RESET%^伴%^ERRORS_CHANNEL%^子%^RESET%^眠。
        %^CONF_CHANNEL%^酉%^RESET%^时天下%^RUMOR_CHANNEL%^雨%^RESET%^，
        %^MORE%^读%^RESET%^书不必%^GOSSIP_CHANNEL%^言%^RESET%^。
\n",
	]));
    add_item("bell", "风铃", "ling",
	([ "look" : "一只风铃挂在亭子的东南角上。",
	   "listen" : "风铃在风中摇荡，发出阵阵清脆地铃声。",
           "move" : "你摇动风铃，一阵叮呤咣啷的声音过了好一会儿才歇下去。\n",
	   "ring" : "只听风铃叮叮当当，好像编钟奏乐一样。",
	]));
    set_exits( ([
        "caolu" : "/sgdomain/area/guan/huayin/vhall.c",
        "road" : "/domains/std/wizroom.c",
	"zatan" : "/wiz/tset/chatroom.c",
        "changan" : "/sgdomain/area/cities/changan/ca_center.c",
        "luoyang" : "/sgdomain/area/cities/luoyang/ly_zsyz.c",
	"chencang" : "/sgdomain/area/guan/chencang/cc_dk.c",
	"jieting" : "/sgdomain/area/guan/jieting/jt_zsyz.c",
	"tianshui" : "/sgdomain/area/town/tianshui/ts_yz.c",
	"mianchi" : "/sgdomain/area/guan/mianchi/mc_yst.c",
	"qinchuan" : "/sgdomain/area/town/qinchuan/qc_bm.c",
        "huayin" : "/sgdomain/area/guan/huayin/vcenter.c",
	"didao" : "/sgdomain/area/guan/didao/dd_dk1.c",
        "anding" : "/sgdomain/area/town/anding/ad_yst.c",
	"hangu" : "/sgdomain/area/guan/hangu/hg_dl1.c",
	"hongnong" : "/sgdomain/area/town/hongnong/hn_cz.c",
	"tongguan" : "/sgdomain/area/guan/tongguan/tg_dl.c",
	"jingyang" : "/sgdomain/area/town/jingyang/jy_yst.c",
//        "bowangpo" : "/sgdomain/area/guan/bowangpo/bwp_sz",
//        "baima" : "/sgdomain/area/guan/baima/bm_sj",
//        "beiping" : "/sgdomain/area/town/beiping/bp_yst",
//        "bailangshan" : "/sgdomain/area/guan/bailangshan/bls_sj",
    ]) );
    set_hidden_exits("changan", "luoyang", "chencang", "jieting",
		     "tianshui", "mianchi", "qinchuan", "huayin",
			"jingyang",
//                        "bowangpo", "baima", "beiping", "bailangshan",
		     "didao", "anding", "hangu", "hongnong", "tongguan");
    set_enter_msg("ting", "只见一片枫叶在风中缓缓飘落，化作$N。\n");
/*
    set_objects( ([
    M_BOARD : ({ 1, "%^B_YELLOW%^%^H_RED%^香叶集%^RESET%^%^NEWS_CHANNEL%^", "wiz.tips" })
    ]) );
*/
}

string query_board() {
    return "wiz.tips";
}
