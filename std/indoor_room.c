// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

inherit BASE_ROOM;

int is_indoors()
{
    return 1;
}

void mudlib_setup()
{
    ::mudlib_setup();
    add_id("room");
    add_chinese_id("�շ���");
	set("no_fight","���ڱ���̫�������ˣ�Ҫ��������ȥ�ɡ�\n");
}
