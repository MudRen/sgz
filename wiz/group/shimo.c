// shimo.c 石磨 re-design by row
// for makedoufu

#include <ansi.h>
#include <mudlib.h>
inherit "/std/modules/m_pushable.c";
inherit OBJ;
inherit M_INPUT;

string *desc = ({"一个石磨，平常农家就用它来磨面(push shimo)，你可以看见里面装了些黄豆。\n",
"石磨里的黄豆发出「吱吱嘎嘎」的声音，已经被磨成了碎粒(push shimo)。\n",
"黄豆在石磨均匀的转动下，「沙沙」地被磨成了细粉(push shimo)。\n",
"一个石磨，平常农家就用它来磨面(push shimo)。\n"});

int status; // 0-30
int push;
int isfill; //put soy bean in shimo
string short();

void setup()
{
	set_unit("个");
	set_id("shimo","石磨", "miller");
//	set_long("一个农家用来磨米磨面的石磨，看上去和其它的石磨没什么不同。\n
//需要磨面的时侯，转动（ｐｕｓｈ）它就可以了。\n\n");
	set_in_room_desc("一个农家用来磨米磨面的石磨(shimo)。\n");
	status=0;
	push=0;
	isfill=0;
}
string long()
{
	if(isfill==1&&status<11)
	return desc[0];
	if(isfill==1&&status<21)
	return desc[1];
	if(isfill==1&&status<40)
	return desc[2];
	return desc[3];
}
int query_isfill()
{
	return isfill;
}
int push()
{
	int m_hp;
	int x;
	x=this_object()->query_isfill();
	printf("the isfill para is "+x+"\n");
	if(this_body()->query_job("makedoufu","beg_time")==0)
	{
	this_body()->simple_action(
	"$N屏住呼吸，使劲向石磨推去，可手一滑，摔了一个大马趴。\n");
	return 1;
	}
	if(isfill!=1)
	{
	write("石磨里什么都没有，推它只是白费力气。\n");
	return 2;
	}
	if (status<31)
	{
	m_hp=this_body()->query_cur_hp();
	if (m_hp<10)
	{
	write("你太累了，休息一会儿吧。\n");
	return 3;
	}
	m_hp-=5;
	this_body()->set_cur_hp(m_hp);
	status=status+random(2);
	this_body()->start_busy(2,"你正忙着推磨呢。\n");
	this_body()->simple_action( ({
	"$N用力握住石磨上的木柄，缓缓推去，只听「吱吱嘎嘎」的声音，石磨转动了起来。\n\n",
	"$N前腿曲，后腿直，腰板一挺，「嘿」地呼出一口气，石磨转动了！\n\n",
	"$N使劲地推着石磨，在石磨地碾动下，原来颗粒饱满、滚圆的黄豆粉粉碎，漏在了石槽里。\n\n",
	"$N使出吃奶的劲推着磨，一边腾出手来将黄豆聚拢，塞入石磨顶上的小洞里。\n\n"}) );
	}
	return 4;
}
int is_pushable()
{
	return 1;
}
int query_clean_up()
{
	return 1;
}
void set_isfill()
{
	isfill=1;
}
