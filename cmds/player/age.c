// age.c by fire on Dec 30 1997
#include <mudlib.h>
#include <sanguo.h>
inherit CHINESE_DA;
inherit CMD;
void main() {
	int p_day, p_month, p_year;
	p_year=this_body()->query_age();
	p_month=this_body()->query_ag_month();
	p_day=this_body()->query_ag_day();
	printf("���׼ȷ������%s����%s����%s�졣\n",
		chinese_number(p_year),
		chinese_number(p_month),
		chinese_number(p_day));
	return;
}
