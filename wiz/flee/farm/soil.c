#include <mudlib.h>
#define FARMER __DIR__"farmer.c"

inherit OBJ;
inherit M_INPUT;

void setup()
{
        set_id("soil", "һƬ����");
        add_id("tu di");
        set_in_room_desc("һƬ���ֵ�����(soil)");
}
string query_stat(int i)
{
	if( i<6 ) return "���ӿ�ʼ��ѿ�ˡ�\n";
	else if( i<12 ) return "���̵�ׯ�������������š�\n";
	else if( i<18 ) return "ׯ�ڿ�ʼ�����ˣ�һƬ�������ٵľ���\n";
	else return "��Ƶ�ׯ�����ڷ���ҡ�������յļ��ڵ��ˡ�\n";
}
string long()
{
	object ob;
	mapping job;

	ob = this_body();
	job = ob->query_job("do_farm", "");
	if( !job||!mapp(job)||job["beg_time"]<=0 )
		return "һƬ�����͵�ׯ�ڣ������������š�\n";
	else if( !job["job"]||job["job"]=="" )
		return query_stat(job["time"])+"���һ�����ã�����ׯ��һ�����и����ճɡ�\n";
	else return query_stat(job["time"])+"Ȼ��"+load_object(FARMER)->get_quest(job["job"]);

}
