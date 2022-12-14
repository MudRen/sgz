// cmd.c
// by fire on 3 August 1998
// this is used to give most command by ppl
#include <mudlib.h>
#include <daemons.h>
inherit CMD;
inherit M_GLOB;
private void main(string arg)
{
   string p_cmd,p_arg="";
   mixed condition;
   int hp;
   if(!arg)
	   p_cmd="help";
   else
	   if(sscanf(arg,"%s %s",p_cmd,p_arg)!=2)
	   {
		   p_cmd=arg;
		   p_arg="";
	   }
   if(!stringp(p_arg))
	   p_arg="";
	condition=this_body()->check_condition();
	if(stringp(condition)) {
		write(condition);
		return;
	}
   if(p_cmd=="list")
   {
		string *list;
		int i=0;
                list=get_dir(PCMD+"*.c");
		list=sort_array(list,1);
		printf("目前可以使用的命令有：");
		while(i<sizeof(list))
		{
			if((i%5)==0)
				printf("\n");
			printf("%-15s",list[i][0..<3]);
			i++;
		}
		printf("\n");
		printf("共有命令%d条．\n",sizeof(list));
		return;
   }
   p_cmd=PCMD+p_cmd;
   p_cmd=p_cmd+".c";
   if(file_size(p_cmd)==-1)
   {
		write("没有这条指令，用 cmd list 查找所有命令．\n");
		return;
   }
   if(!p_cmd->no_need_hp())
   {

	   hp=this_body()->query_cur_hp();
	   if(hp<5)
	   {
		   write("你体力不足，无力思考下达命令。\n");
		   return;
	   }
	   this_body()->set_cur_hp(hp-2);
   }
   p_cmd->start(p_arg);
}
