// mutong.c ��ľͰ by row
// for makedoufu

#include <ansi.h>
#include <mudlib.h>
inherit OBJ;
inherit M_INPUT;

void set_status();
void do_cold();
int query_status();
int query_isfill();
void set_isfill();
void finish_job();
void empty_it();

string *desc = ({
"����һֻ��ľͰ���ǹط���������ȴ%^B_WHITE%^%^H_YELLOW%^����%^RESET%^�ġ�\n",
"����һֻ��ľͰ����������������ʢ�ŵȴ���ȴ��%^B_WHITE%^%^H_YELLOW%^����%^RESET%^��\n",
"����һֻ��ľͰ��ԭ�ȵ��±��%^B_WHITE%^%^H_YELLOW%^����%^RESET%^�Ѿ���ȫ��ȴ�ˣ�%^B_WHITE%^%^H_GREEN%^��䶹��%^RESET%^�����ˣ�\n"});
int status;
int isfill; // there is doujiang in

void setup()
{
	set_unit("ֻ");
	set_id("mutong","��ľͰ");
	set_in_room_desc("һֻ��ľͰ(mutong)������ĥ���ĵ��ϣ���������ʢ������");
	status=0;
	isfill=0;
}
string long()
{
	if(isfill==0)
	return desc[0];
	if(isfill==1&&status==0)
	return desc[1];
	return desc[2];
}
void set_status()
{
	status=0;
}
int query_status()
{
	return status;
}
int query_clean_up()
{
	return 1;
}
void set_isfill()
{
	isfill=1;
}
int query_isfill()
{
	return isfill;
}
void empty_it()
{
	isfill=0;
}
void do_cold()
{
	call_out("finish_job",180);
	return;
}
void finish_job()
{
	if(isfill==1&&status==0)
	{
	status=1;
	tell_environment(this_object(),"ľͰ����±��%^B_WHITE%^%^H_YELLOW%^����%^RESET%^��ȫ��ȴ�ˣ�%^B_WHITE%^%^H_GREEN%^��䶹��%^RESET%^�Ѿ������ˣ�\n");
	return;
	}
	tell_environment(this_object(),"��֪��Ϊʲô���У�������ʦ�ɡ�\n");
	return;
}