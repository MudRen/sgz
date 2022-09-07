/* ting.c
** Coded by Է�@����־
** Code generated with RoomMaker v0.9.1 coded by Onyx@RedDragon
** Do not remove this header.
*/


inherit ROOM;
inherit STORE;

static string * nogo = ({
"$NãȻ����ͤ����ת�˼�Ȧ��ͷ�������ˡ�",
"$N�����ؿ���Զ�����㶵س���",
"$Nӭ��ͤ������磬�������˸����顣",
"$N�ո�����׼����ȥ����Ȼ�����������죬�����ֳ��������",
"$Nһת��������������ע���о�����ʱͣס�Ų��������ܡ�",
"С���ϵ���������Ҷ��$N��������һ�������ǲ�ȥ�ĺá�",
"$N�ƺ�����Զ���������������Ǵ�������ɡ�",
"$Nһ��ͤ�ӣ��ͱ�һ�ֳ���������ѹ�ô�����������ֻ�û�ת��",
});
   
string * going = ({ "���","����","С�Ľ���","Ѹ��","�Ҵ�","����", });

int sound() {
    write("��������������Ҷ�����㻹����ԼԼ�������������\n");
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
        "������һ��С·����Ӱ����Զȥ������\n");
    this_body()->move(r);
    tell_environment(this_body(), sprintf("%s���˹�����\n",
	this_body()->short()), 0, ({ this_body() }) );
    this_body()->force_look();
    return 1;
}

void setup(){
    set_light(1);
    set_brief("%^B_RED%^%^ORANGE%^���ͤ%^RESET%^%^ROOM_EXIT%^");
    set_long("
һ��СС��ͤ�������ڷ���֮�С�������ľ���죬��������С��ͨ��
�������ͤ������һ�����ӣ����ܷ���Щ���ӡ��ĸ�ͤ���ϸ�����
һ��ʫ��ͤ����Ҷ���紵�������죬һ�������ʱ��ʱ�ظ߸ߵ͵�
��������������
\n"
);
    add_item("table", "����",
        ([ "look" : "һ����ľ���������
���Ϸ��˺ü������µı��ӡ�
�м��С�����ϻ�����Щ���ġ�"
        ]));
    add_item("chair", "����", "seat",
        ([ "look" : "�����λ���ľ���ӡ�",
	   "sit"  : "������һ�ź�ľ���ӡ�",
	]));
    add_item("poem", "ʫ", "ͤ��", "duilian",
        ([ "look" : "
        %^TELL%^��%^RESET%^��%^NEWBIE_CHANNEL%^��%^RESET%^��%^WEATHER_CHANNEL%^��%^RESET%^��
        %^ANNOUNCE_CHANNEL%^��%^WIZ_CHANNEL%^��%^RESET%^��%^ERRORS_CHANNEL%^��%^RESET%^�ߡ�
        %^CONF_CHANNEL%^��%^RESET%^ʱ����%^RUMOR_CHANNEL%^��%^RESET%^��
        %^MORE%^��%^RESET%^�鲻��%^GOSSIP_CHANNEL%^��%^RESET%^��
\n",
	]));
    add_item("bell", "����", "ling",
	([ "look" : "һֻ�������ͤ�ӵĶ��Ͻ��ϡ�",
	   "listen" : "�����ڷ���ҡ����������������������",
           "move" : "��ҡ�����壬һ������ॵ��������˺�һ�����Ъ��ȥ��\n",
	   "ring" : "ֻ�����嶣�������������������һ����",
	]));
    set_exits( ([
        "caolu" : "/sgdomain/area/guan/huayin/vhall.c",
        "road" : "/domains/std/wizroom.c",
	"zatan" : "/wiz/tset/chatroom.c",
        "changan" : "/sgdomain/area/cities/changan/ca_center.c",
	"luoyang" : "/sgdomain/area/cities/luoyang/ly_yz.c",
	"chencang" : "/sgdomain/area/guan/chencang/cc_dk.c",
	"jieting" : "/sgdomain/area/guan/jieting/jt_xd.c",
	"tianshui" : "/sgdomain/area/town/tianshui/ts_yz.c",
	"mianchi" : "/sgdomain/area/guan/mianchi/mc_lk1.c",
	"qinchuan" : "/sgdomain/area/town/qinchuan/qc_bm.c",
        "huayin" : "/sgdomain/area/guan/huayin/vcenter.c",
	"didao" : "/sgdomain/area/guan/didao/dd_dk1.c",
        "anding" : "/sgdomain/area/town/anding/ad_yst.c",
	"hangu" : "/sgdomain/area/guan/hangu/hg_dl1.c",
	"hongnong" : "/sgdomain/area/town/hongnong/hn_cz.c",
	"tongguan" : "/sgdomain/area/guan/tongguan/tg_dl.c",
	"bowangpo" : "/sgdomain/area/guan/bowangpo/bwp_sz",
    ]) );
    set_hidden_exits("changan", "luoyang", "chencang", "jieting",
		     "tianshui", "mianchi", "qinchuan", "huayin",
			"bowangpo",
		     "didao", "anding", "hangu", "hongnong", "tongguan");
    set_enter_msg("ting", "ֻ��һƬ��Ҷ�ڷ��л���Ʈ�䣬����$N��\n");
/*
    set_objects( ([
    M_BOARD : ({ 1, "%^B_YELLOW%^%^H_RED%^��Ҷ��%^RESET%^%^NEWS_CHANNEL%^", "wiz.tips" })
    ]) );
*/
}

string query_board() {
    return "wiz.tips";
}