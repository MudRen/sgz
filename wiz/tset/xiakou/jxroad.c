//  jxroad.c
//  ���Ĵ�·
//  created by tset 3/4/98
// last updated by tset 7/18/98

inherit GRID_SERVER;

static private string * my_descriptions = ({
    "\n��·����������ļ������������ˣ�����һƬƬũ����Զ����չ��\n\n",
    "\n��·ƽƽ̹̹�����Կ�������Сɽ���ڵ�ƽ���ϡ�\n\n",
    "\nɽ·�ϵ����Ǵ��СС��ʯ�飬��ʱ����Ұ�޳�û�������С�\n\n",
});

void create()
{
    use_data_file(__DIR__"jxroad.data");
    set_brief("���Ĵ�·");
    set_descriptions(my_descriptions);
}
