// nick.c 
// by fire on Sep 4, 1998
// used for player char to risign a position
inherit M_ANSI;

void start(string arg)
{
	int ret;
	if (colour_strlen(arg) > 20) {
            write("ͷ��̫���ˣ���һ����������İɡ�\n");
	    return;
	}
	if (arg == 0 || arg == "") {
	    this_body()->set_title(0);
            write("ͷ��ȡ���ɹ���\n");
	}  
        else {
            this_body()->set_title(arg);
            write("�ƺ����óɹ���\n");
        }
}
