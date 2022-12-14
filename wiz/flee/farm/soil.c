#include <mudlib.h>
#define FARMER __DIR__"farmer.c"

inherit OBJ;
inherit M_INPUT;

void setup()
{
        set_id("soil", "一片土地");
        add_id("tu di");
        set_in_room_desc("一片肥沃的土地(soil)");
}
string query_stat(int i)
{
	if( i<6 ) return "种子开始萌芽了。\n";
	else if( i<12 ) return "碧绿的庄稼苗愉快的生长着。\n";
	else if( i<18 ) return "庄稼开始抽穗了，一片欣欣向荣的景象。\n";
	else return "金黄的庄稼正在风中摇动，丰收的季节到了。\n";
}
string long()
{
	object ob;
	mapping job;

	ob = this_body();
	job = ob->query_job("do_farm", "");
	if( !job||!mapp(job)||job["beg_time"]<=0 )
		return "一片绿油油的庄稼，健康的生长着。\n";
	else if( !job["job"]||job["job"]=="" )
		return query_stat(job["time"])+"情况一切良好，您的庄稼一定会有个好收成。\n";
	else return query_stat(job["time"])+"然而"+load_object(FARMER)->get_quest(job["job"]);

}
