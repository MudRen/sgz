// pigroom.c ����
// Written by Xiang Tu <tu@uwalpha.uwinnipeg.ca>

#include "/wiz/suicide/pig.h"
#include <ansi.h>


//inherit F_CLEAN_UP;
inherit INDOOR_ROOM;

string 	*seat = ({ "north", "west", "south", "east" });
mapping chinese_seat = ([ 
	"north": "����",
	"west" : "����",
	"south": "�ϱ�",
	"east" : "����",
]);

int pig_stage;
int round_no, roundcard_count;
string *round_order = allocate(4);
int bid_flag;
string bidcard_str = "";
object server;
string claimer;
mapping	pl = allocate_mapping(4),
 	cards = allocate_mapping(4),
	card_count = allocate_mapping(4),
	roundcards = allocate_mapping(4),
	picks = allocate_mapping(4),
	pick_count = allocate_mapping(4),
	passed = allocate_mapping(4),
	agreed = allocate_mapping(4),
	hscore = allocate_mapping(4),
	tscore = allocate_mapping(4);
	
string	dealer;
int	*allow_playbid = allocate(4);
int 	*oldcards = allocate(52), 
	*newcards = allocate(52);

int pl_count();
void pig_init();
void deal_init();
void bid_init();
void after_bid();
void round_init(string w);
void after_round();
void play_init();
void after_claim();
void after_play();
void after_round();
void after_winner(string rw);
void after_hand();
void auto_play();

string refresh_str(string dir);
string picks_str();
string table_str(string dir);
string scoreboard_str();

void reset()	// set this room to no_reset
{}

int pl_count()
{
	int i, r;
	for (i = r = 0; i < 4; i++)
		if (objectp(pl[seat[i]]))
			r++;
		else
			map_delete(pl, seat[i]);
	return r;
}
void pig_init()
{
	int i;
	pig_stage = PIG_INITTING;
	for (i = 0; i < 4; i++) {
		tscore[seat[i]] = hscore[seat[i]] = 0;
		cards[seat[i]] = allocate(13);
		picks[seat[i]] = allocate(16);
	}
	for (i = 0; i < 52; i++)
		oldcards[i] = i;
}
void deal_init()
{
	pig_stage = PIG_DEALING;
	tell_environment(server, scoreboard_str());
	tell_environment(server,"������ deal ��\n");
}
void bid_init()
{
	int i;
	pig_stage = PIG_BIDDING;
	bidcard_str = "";
	bid_flag = 0;
	for (i = 0; i < 4; i++) {
		allow_playbid[i] = 1;
		passed[seat[i]] = 0;
	}
}

void play_init()
{
	int i, j;
	pig_stage = PIG_PLAYING;
	round_no = 1;
	for (i = 0; i < 4; i++) {
		pick_count[seat[i]] = 0;
		card_count[seat[i]] = 13;
		for (j = 0; j < 16; j++)
			picks[seat[i]][j] = 53;
		claimer = "";
		agreed[seat[i]] = 0;
	}
	round_init(dealer);
}
void round_init(string rw)
{
	int i;
	for (i = 0; i < 4; i++) 
		roundcards[seat[i]] = -1;
	roundcard_count = 0;
	round_order = PIG_D->order_turn(rw);
	if (pig_stage == PIG_PLAYING)
		tell(pl[rw], refresh_str(rw) + "�����ֵ�����ƣ�\n");
}
	
/*void init()
{
	add_action("do_sit", "sit");
	add_action("do_leave", "leave");
	add_action("do_deal", "deal");
	add_action("do_bid", "bid");
	add_action("do_bid", "sell");
	add_action("do_pass", "pass");
	add_action("do_play", "play");
	add_action("do_refresh", "refresh");
	add_action("do_skip", "skip");
	add_action("do_claim", "claim");
}*/

string picks_str()
{
	int i;
string r= "",t="";
        for (i = 0; i < 4; i++) {
		t = "";
		if (objectp(pl[seat[i]]))
                	t = pl[seat[i]]->query("name");
		else 
			t = chinese_seat[seat[i]];
		r += t;
        }
	return r;
}

string refresh_str(string dir)
{
//	if (dir != "north" && dir != "west" && dir != "south" && dir != "east")
		return PIG_D->refresh(cards[dir], 0, card_count[dir] - 1);
//	return "";
}
	

string table_str(string dir)	// what's going on in table ?
{
	int i;
	mapping rseat = ([]);
	string r = "", z = "";

	if (pig_stage == PIG_PLAYING && pl_count() == 4) { // if in playing mode
		if (dir != "north" && dir != "west" && dir != "south" 
			&& dir != "east")
			rseat = PIG_D->order_turn("north");
		else
			rseat = PIG_D->order_turn(dir);
//		r = "���������ڼ��ҵĹ��ţ���\n";
	
		if (roundcard_count < 4)
			r = sprintf("�����ǵ�%s�֣�����%s���ơ�\n", 
			chinese_number(round_no), 
			pl[round_order[roundcard_count]]->query_chinese_name()+"("+
			pl[round_order[roundcard_count]]->query_primary_id()+")");
		if (bidcard_str != "")
			r += "���˵��ƣ�" + bidcard_str + "\n\n";
		else
			r += "û�������ơ�\n";
		r = sprintf("%s%24s��%s��\n", r, "", pl[rseat[2]]->query_primary_id());	// writes north name
		r = sprintf("%s%26s%s\n", r, "", 
			PIG_D->card_str(roundcards[rseat[2]]));
		r = sprintf("%s%4s%16s%6s%6s%6s%s\n", r, "", "��" + 
			pl[rseat[3]]->query_primary_id() + "��", 
			PIG_D->card_str(roundcards[rseat[3]]), "", 
			PIG_D->card_str(roundcards[rseat[1]]), "��" +
			pl[rseat[1]]->query_primary_id() + "��");
		r = sprintf("%s%26s%s\n", r, "",
			PIG_D->card_str(roundcards[rseat[0]]));
		r = sprintf("%s%24s��%s��\n", r, "", pl[rseat[0]]->query_primary_id());
		if (card_count[dir] > 0)
			r += refresh_str(dir);
		r += picks_str();
	}
	else {
	        r = "����һ��ר�����ڹ�����ķ�����\n\n";
               	if (bidcard_str != "")
                        r += "���˵��ƣ�" + bidcard_str + "\n\n";
                else
                        r += "û�������ơ�\n";
		for (i = 0; i < 4; i++) 
			if (objectp(pl[seat[i]])) {
				if (pl[seat[i]] == server) z = "@"; else z = "";
				r = sprintf("%s%s�������������ǣ�%s(%s)%s��\n", r,
				chinese_seat[seat[i]], pl[seat[i]]->query_chinese_name(),
				pl[seat[i]]->query_primary_id(), z);
			}
			else
				r = sprintf("%s%4s�������ǿյġ���������棬������ sit %-5s ����ȥ��\n",
				r, chinese_seat[seat[i]], seat[i]);
	}
	return r;
}

string scoreboard_str()
{
	int i;
	string r;
	r = "����ɼ���(Scoreboard)\n����������������������������������\n���������������������̷֡������ܷ�\n����������������������������������\n";
	for (i = 0; i < 4; i++)
		if (objectp(pl[seat[i]]))
			r = sprintf("%s%-14s%10d%10d\n", r,
			(string)pl[seat[i]]->query_primary_id(),
			(int)hscore[seat[i]], (int)tscore[seat[i]]);
	return r + "����������������������������������\n";
}

void score_reset()
{
	int i;
	for (i = 0; i < 4; i++)
		tscore[seat[i]] = 0;
}

mixed do_skip(string arg)
{
	if (!this_body()->query("pigging_seat"))
		return "��û���ڹ���\n";
	if (this_body() != server)
		return "ֻ���������������⸱�ƣ�\n";
	if (pig_stage < PIG_BIDDING)
		return "�ƶ�û�У���ʲô��\n";
	server->simple_action("����$N���������⸱�ƣ���\n");
	if (pl_count() == 4)
		deal_init();
	return 1;
}

void after_claim()
{
	int i, j, k;
	for (i = 0; i < roundcard_count; i++) 
		if (PIG_D->is_special(roundcards[i]))
			picks[claimer][pick_count[claimer]++] = roundcards[j];
	for (i = 0; i < 4; i++)
		for (j = 0; j < card_count[seat[i]]; j++)
			if (PIG_D->is_special(cards[seat[i]][j]))
				picks[claimer][pick_count[claimer]++] = cards[seat[i]][j];
	after_hand();
}

mixed do_claim(string arg)
{
	int i;
	object me = this_body();
	if (!me->query("pigging_seat"))
		return "��û���ڹ���\n";
	if (pl_count() != 4)
		return "����������û������\n";
	if (pig_stage != PIG_PLAYING)
		return "�����ʲô��\n";
	if (claimer == me->query("pigging_seat"))
		return "һ�ξ͹��ˣ�\n";
	if (!arg) {
		if (claimer != "")
			return "claim yes|no ��\n";
		agreed[claimer = me->query("pigging_seat")] = 1;
		write("�㷢��ȫ�յ�Ҫ�󣡵ȴ���������\n");
		for (i = 0; i < 4; i++)
			if (seat[i] != claimer)
				tell(pl[seat[i]], query_primary_id() + 
					"��Ϊ�����е��ƶ��Ǵ���ˣ�\n" +
					refresh_str(me->query("pigging_seat")) +
					"���� claim yes ͨ�������� claim no �����\n");
		return 1;
	}
	if (arg == "yes") {
		if (claimer == "")
			return "û������ȫ�գ�\n";
		if (!agreed[me->query("pigging_seat")]) {
			agreed[me->query("pigging_seat")] = 1;
			me->targetted_action("$Nͬ��$t���ƶ��Ǵ���ˣ�\n", pl[claimer]);
			for (i = 0; i < 4; i++)
				if (agreed[seat[i]] != 1)
					return 1;
			pl[claimer]->simple_action("$N��Ҫ��ͨ���ˣ���\n");
			after_claim();
			return 1;
		}
	}
	if (arg == "no") {
		if (claimer == "")
			return "û������ȫ�գ�\n";
		me->targetted_action("$N�����$t��Ҫ�󣡣�\n�������ƣ�\n", pl[claimer]);
		claimer = "";
		for (i = 0; i < 4; i++)
			agreed[seat[i]] = 0;
		return 1;
	}
	else
		return "claim ʲô��\n";
}
	

mixed do_sit(string arg)
{
	object me = this_body();

	if (!arg || (arg != "north" && arg != "west" && arg != "south" && arg != "east"))
		return "�����������\n";

	if (server == me)
		return "�������ܻ���λ��\n";

	map_delete(pl, (string)me->query("pigging_seat"));
		
	if (!objectp(pl[arg])) {
		if (!pl_count()) {
			pig_init();
			server = me;
			write("��������������\n");
			round_order = PIG_D->order_turn(dealer = arg);
		}
		pl[arg] = me;
		me->set("pigging_seat", arg);
		me->simple_action("$N������" + chinese_seat[arg] + "��λ�ӡ�\n");
		if (pl_count() == 3)
			me->simple_action("��������ȱһ������ֻ����Ҫһ����ҾͿ��Կ����ˣ�\n");
		if (pl_count() == 4) {
			me->simple_action("�ã��˴����ˣ�\n");
			deal_init();
		}
		return 1;
	}
	else
		return "���λ�����Ѿ������ˣ�\n";
}

mixed do_leave(string arg)
{
	int i;
	object me = this_body();

	if (!me->query("pigging_seat"))
		return "������û���ڹ���\n";
	else if (server == me) {
		me->simple_action("����$N�����ٹ���ȥ�ˣ�\n");
		server = 0;
		for (i = 0; i < 4; i++) 
			if (objectp(pl[seat[i]])) {
				pl[seat[i]]->simple_action("$Nվ��������\n");
				pl[seat[i]]->delete("pigging_seat");
				map_delete(pl, seat[i]);
			}
		pig_stage = PIG_INITTING;
		return 1;
	}
	else {
		map_delete(pl, (string)me->query("pigging_seat"));
		me->delete("pigging_seat");
		me->simple_action("$N�����ٹ��ˣ�վ��������\n");
		return 1;
	}
}

void do_assign_cards()	// assign cards to players
{
	int i, j, k = 0;

	for (i = 0; i < 13; i++)
		for (j = 0; j < 4; j++) 
			cards[seat[j]][i] = newcards[k++];
	for (i = 0; i < 4; i++) {
		cards[seat[i]] = sort_array(cards[seat[i]], 1);
		tell(pl[seat[i]], PIG_D->refresh(cards[seat[i]], 0, 12));
		card_count[seat[i]] = 13;
	}
}

mixed do_deal(string arg)
{
	int i, j, k;
	object me = this_body();
	if (me != server)
		return "�㲻��������\n";
	if (pig_stage != PIG_DEALING || pl_count() != 4)
		return "���ڲ��ܷ��ƣ�\n";
	PIG_D->shuffle(oldcards, newcards, 2);

	for (i = 0; i < 13; i++)
		for (j = 0; j < 4; j++) 
			cards[seat[j]][i] = newcards[k++];
	for (i = 0; i < 4; i++) {
		cards[seat[i]] = sort_array(cards[seat[i]], 1);
		tell(pl[seat[i]], "��õ�����Ϊ��\n" +
			PIG_D->refresh(cards[seat[i]], 0, 12));
		card_count[seat[i]] = 13;
        }
	tell_environment(this_body(), "�������ˣ���˭Ҫ���Ƶ�û�У�\n");
	tell_environment(this_body(), "������������ƣ���һ�� pass ��\n");
	bid_init();
	return 1;
}

mixed do_refresh(string arg)
{
	object me = this_body();
	if (!me->query("pigging_seat"))
		return "��û���ڹ���\n";
	if (pig_stage < PIG_BIDDING || 
		card_count[me->query("pigging_seat")] < 1)
		return "������û���ƣ�\n";
	tell(pl[(string)me->query("pigging_seat")], 
		"����������Щ�ƣ�\n" + refresh_str(me->query("pigging_seat")));
	return 1;
}

mixed do_bid(string arg)
{
	object me = this_body();
	int c, b;
	string ts;

	if (!me->query("pigging_seat"))
		return "��û���ڹ���\n";
	if (pig_stage != PIG_BIDDING)
		return "���ڲ������Ƶ�ʱ��\n";
	if (!arg)
		return "������ʲô��\n";
	if ((c = PIG_D->is_validcard(arg)) == -1 ||
		!PIG_D->has_card(cards[me->query("pigging_seat")], 0, 12, c))
		return "������û�������ƣ�\n";
	if (!(b = PIG_D->is_validbid(c)))
		return "�����Ʋ��ܱ�����\n";
	if (bid_flag & b)
		return "�������Ѿ��������ˣ�\n";
	bid_flag |= b;
	switch (b) {
	case BID_SPIG :
		allow_playbid[0] = 0; break;
	case BID_HACE :
		allow_playbid[1] = 0; break;
	case BID_DSHEEP :
		allow_playbid[2] = 0; break;
	case BID_CTRANS :
		allow_playbid[3] = 0; break;
	}
	me->simple_action("$N˵��������" + PIG_D->card_str(c) + "��\n");
	ts = "";
	if (bidcard_str != "") ts = "��";
	bidcard_str = PIG_D->card_str(c) + "��" + me->query("name") + "��" +
		ts + bidcard_str;

	return 1;
}

mixed do_pass(string arg)
{
	object me = this_body();
	int i;

	if (!me->query("pigging_seat"))
		return "��û���ڹ���\n";
	if (pig_stage != PIG_BIDDING)
		return "�����ʲô��\n";
	if (passed[me->query("pigging_seat")] == 1)
		return "���Ѿ�ͣ���ˣ�\n";
	passed[me->query("pigging_seat")] = 1;
	me->simple_action("$N˵������ͣ����\n");
	for (i = 0; i < 4; i++) 
		if ((int)passed[seat[i]] == 0)
			return 1;

	for (i = 0; i < 4; i++)
		passed[seat[i]] = 0;
	tell_environment(server, "ȫ��ͣ������������\n");
	tell_environment(server, "�����" + pl[dealer]->query_chinese_name()+"("+pl[dealer]->query_primary_id() + ")�ȳ���\n");

	play_init();
	return 1;
}

void after_play()
{
	int i;
	roundcard_count++;
	for (i = 0; i < 4; i++) 
		if (card_count[seat[i]] > 0)
			tell(pl[seat[i]], table_str(seat[i])); 
	if (roundcard_count > 3)
		after_round();
}
	
void after_winner(string rw)
{
	int i;
	pl[rw]->simple_action("$N��" + PIG_D->card_str(roundcards[rw]) + "���\n");
	for (i = 0; i < 4; i++)
                if (PIG_D->is_special(roundcards[seat[i]])) {
                        picks[rw][pick_count[rw]++] = 
                                roundcards[seat[i]];
                        if (roundcards[seat[i]] == SPIG) {
				pl[rw]->simple_action("$N�õ�����ͷ����\n");
                                dealer = rw;
			}
                }
        picks[rw] = sort_array(picks[rw], 1);
}

void after_round()
{
	int i;
	string rw;

	allow_playbid[SUIT(roundcards[round_order[0]])] = 1;
	after_winner(rw = PIG_D->card_cmp4(roundcards, SUIT(roundcards[round_order[0]])));
	round_init(rw);
	
	if (round_no++ == 12) 
		auto_play();  // starts auto_play
}
void auto_play()
{
	int i;
	for (i = 0; i < 4; i++)
		roundcards[seat[i]] = cards[seat[i]][0];
	roundcard_count = 4;
        for (i = 0; i < 4; i++) {
		card_count[seat[i]] = 0;
		tell(pl[seat[i]], table_str(seat[i])); 
	}
	after_winner(PIG_D->card_cmp4(roundcards, SUIT(roundcards[round_order[0]])));
	after_hand();
}

void after_hand()
{
	// doing the scoring here
	int i;
	string collect_all = "";

	for (i = 0; i < 4; i++) {
		hscore[seat[i]] = PIG_D->count_score(picks[seat[i]], bid_flag);
		if (hscore[seat[i]] == 1000)
			collect_all = seat[i];
		pl[seat[i]]->add("pig_played", 1);
		pl[seat[i]]->add("pig_score", hscore[seat[i]]);
	}
	if (collect_all == "")
		for (i = 0; i < 4; i++) {
			tscore[seat[i]] += hscore[seat[i]];
			if (tscore[seat[i]] <= -1000) 
				pl[seat[i]]->add("pig_head", 1);
		}
	else {
		for (i = 0; i < 4; i++)
			if (seat[i] != collect_all) 
				pl[seat[i]]->add("pig_head", 1);
	}
	for (i = 0; i < 4; i++) 
		if (tscore[seat[i]] <= -1000)
			pl[seat[i]]->simple_action("$N��һͷ��\n");
	for (i = 0; i < 4; i++)
		if (tscore[seat[i]] <= -1000) {
			score_reset();
			break;
		}
	deal_init();
}
	
mixed do_play(string arg)
{
	object me = this_body();
	int i, c, sc, nbc = 0, cpos = -1;
	string ms;

	if (!(ms = me->query("pigging_seat")))
		return "��û���ڹ���\n";
	if (pig_stage != PIG_PLAYING)
		return "���ڲ��ǳ��ƽ׶Σ�\n";
	if (ms != round_order[roundcard_count])
		return "��û�ֵ�����ƣ�\n";
	if (!arg || (c = PIG_D->is_validcard(arg)) == -1)
		return "��Ҫ�������ƣ�\n";
	for (i = 0; i < card_count[ms]; i++) 
		if (cards[ms][i] == c) {
			cpos = i; break;
		}
	if (cpos == -1)
		return "������û�������ƣ�\n";

	if (roundcard_count > 0 && (sc = PIG_D->has_suit(cards[ms], 0, 
		card_count[ms] - 1, SUIT(roundcards[round_order[0]]))) > 0 && 
		SUIT(c) != SUIT(roundcards[round_order[0]]))
		return "�㲻�ܳ������ƣ�\n";

	if (roundcard_count == 0 || sc > 1) {
		switch (c) {
		case SPIG :
			if (!allow_playbid[SPADE])
				nbc = 1;
			break;
		case HACE :
			if (!allow_playbid[HEART])
				nbc = 1;
			break;
		case DSHEEP : 
			if (!allow_playbid[DIAMOND])
				nbc = 1;
			break;
		case CTRANS :
			if (!allow_playbid[CLUB])
				nbc = 1;
			break;
		}
		if (nbc)
			return "�������Ʋ����ڵ�һ�ֳ���\n";
	}
	for (i = cpos; i < card_count[ms] - 1; i++)
		cards[ms][i] = cards[ms][i+1];
	cards[ms][13 - round_no] = 53;
	roundcards[ms] = c;
	card_count[ms]--;
	if (roundcard_count > 0 && SUIT(c) != SUIT(roundcards[round_order[0]]))
		me->simple_action("$N����һ��" + PIG_D->card_str(c) + "��\n");
	else
		me->simple_action("$N����һ��" + PIG_D->card_str(c) + "��\n");
	after_play();
	return 1;
}

int is_pigroom()
{return 1;}

void setup(){
    /*set_objects( ([
	"/sgdomain/npc/turfboss" : 1
      ]) );*/
    set_area("wiz_area");
    set_brief("����");
    set_long("����һ���׼�Ĺ���������ʦΪ�����������Ͼʱ������ǲ���ر�������ҹ\n"
"���߲��ݴ������ɵġ����ӵ�������һ�Ű���������Χ�������̫ʦ�Ρ�ǽ����\n��һ����Ϸ����"
"˵����%^CYAN%^help pig_cmds%^RESET%^��\n");
    set_exits( ([
                "east" : "/wiz/suicide/horseroom",
                ]) );
    set_can_meet(1);
}
