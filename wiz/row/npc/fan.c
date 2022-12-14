// fan.c 大扇子 by row
// for makedoufu

#include <ansi.h>
#include <mudlib.h>
inherit "/wiz/row/npc/m_waveable.c";
inherit OBJ;
inherit M_INPUT;

void setup()
{
	set_unit("面");
	set_id("fan","大扇子");
	set_long("这是一面大扇子，柄上拴着根绳子吊在磨房的大梁上，从扇面上\n烟熏火燎的痕迹可以看得出，它是用来煽火的(wave fan)。\n");
	set_in_room_desc("一面大扇子(fan)，柄上拴着根绳子吊在磨房的大梁上。");
}
int wave()
{
	object guozi,room;
	int status,isfill,islu;
	int m_hp;
	room = environment(this_body());
	guozi = present("guozi",room);
	if(this_body()->query_job("makedoufu","beg_time")==0)
	{
	this_body()->simple_action(
	"$N抓着扇子使劲扇，可除了弄出点儿风来，什么事也没有发生。\n");
	return 1;
	}
	if(!objectp(guozi))
	{
	write("你打算用扇子来干嘛？\n");
	return 1;
	}
	isfill=guozi->query_isfill();
	islu=guozi->query_islu();
	status=guozi->query_status();
	if(islu==1)
	{
	write("锅子里的%^B_WHITE%^%^H_YELLOW%^豆浆%^RESET%^已经点过卤了，用不着再煮了。\n");
	return 1;
	}
	if(isfill==0)
	{
	write("锅子里是空的，火也没有点着，你扇什么扇呀？\n");
	return 2;
	}
	if(status>34)
	{
	write("锅子里的%^B_WHITE%^%^H_YELLOW%^豆浆%^RESET%^已经煮好了，接下来应该点卤(turn cruet)。\n");
	return 1;
	}
	if(status<35)
	{
	m_hp=this_body()->query_cur_hp();
	if (m_hp<10)
	{
	write("你太累了，休息一会儿吧。\n");
	return 3;
	}
	m_hp-=5;
	this_body()->set_cur_hp(m_hp);
	guozi->do_wave();
	this_body()->start_busy(2,"你正忙着煽火呢。\n");
	this_body()->simple_action( ({
	"$N举起扇子，用力挥去，只见火星四射，火苗往上蹿了一下。\n\n",
	"$N「呼呼」地挥着扇子，灶头里的火渐渐旺了起来。\n\n",
	"$N用力扇了一下，灶头里喷出的黑烟将$N弄了个「灰头土脸」。\n\n",
	"$N举着扇子使劲地扇着，火苗发出的热气逼人，似乎有点受不了。\n\n"}) );
	return 1;
	}
	write("锅子里的%^B_WHITE%^%^H_YELLOW%^豆浆%^RESET%^已经煮好了，接下来应该点卤(turn cruet)。\n");
	guozi=present("guozi",room)->do_clear();
	return 1;
}
int query_clean_up()
{
	return 1;
}
