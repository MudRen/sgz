// help.c by fire on Aug 3 1998
// this is for the help of cmd
#include <mudlib.h>
void start(string arg)
{
        string p_cmdfile;
        string p_helpfile;
        string help_info;
        if(sizeof(arg)==0)
                arg="help";
        p_cmdfile=PCMD+arg+".c";
        if(file_size(p_cmdfile)==-1)
        {
                write("û������ָ��� cmd list �����������\n");
                return;
        }
        p_helpfile=PHELP+"command/"+arg;
        if(arg=="help")
            p_helpfile=PHELP+"cmds/"+"sep_cmds";
        if(file_size(p_helpfile)==-1)
        {
                write("��Ǹ������ָ��İ�����δ��ɡ�\n");
                return;
        }
        help_info=read_file(p_helpfile);
	if(arg=="nick")
	        more(help_info,0,0,NO_ANSI);
	else		
	        more(help_info);
}
